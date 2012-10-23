#include "StdAfx.h"
#include "CaptureTrapezium.h"
#include "CvPoint_Wrapper.h"
#include "Eigen/Dense"
#include "LinearAlgebra.h"

using namespace Eigen;

CaptureTrapezium::CaptureTrapezium(void)
{
	cornerLengthPercentage_ = 0.05;
	pts_[0] = pts_[1] = pts_[2] = pts_[3] = cvPoint2D32f(0.0, 0.0);
}


CaptureTrapezium::~CaptureTrapezium(void)
{
}

void CaptureTrapezium::finishCreating() {
	pts_[0] = cvPoint2D32f(rect_.x, rect_.y);
	pts_[1] = cvPoint2D32f(rect_.x+rect_.width, rect_.y);
	pts_[2] = cvPoint2D32f(rect_.x+rect_.width, rect_.y+rect_.height);
	pts_[3] = cvPoint2D32f(rect_.x, rect_.y+rect_.height);
}

int CaptureTrapezium::actionController(CvPoint mousePointer) {
	if (this->contains(mousePointer)) {
		//double sqrtP = sqrt(cornerPercentage_);
		//CvPoint tl = cvPoint(rect_.x,rect_.y);
		//CvPoint tr = cvPoint(rect_.x+rect_.width,rect_.y);
		//CvPoint sizeVector = cvPoint(rect_.width, rect_.height);
		//CvPoint sizeVectorInvert = cvPoint(-rect_.width, rect_.height);
		////CvPoint center = divVector(addVectors(sizeVector,tl), 2);

		//	CvPoint tl_inner = addVectors(tl, mulVector(sizeVector, sqrtP));
		//if ((mousePointer.x <= tl_inner.x) && (mousePointer.y <= tl_inner.y))
		//	return RESIZE_TL;

		//CvPoint tr_inner = addVectors(tr, mulVector(sizeVectorInvert, sqrtP));
		//if ((mousePointer.x >= tr_inner.x) && (mousePointer.y <= tr_inner.y))
		//	return RESIZE_TR;

		//CvPoint br_inner = addVectors(tl, mulVector(sizeVector, 1 - sqrtP));
		//if ((mousePointer.x >= br_inner.x) && (mousePointer.y >= br_inner.y))
		//	return RESIZE_BR;

		//CvPoint bl_inner = addVectors(tr, mulVector(sizeVectorInvert, 1 - sqrtP));
		//if ((mousePointer.x <= bl_inner.x) && (mousePointer.y >= bl_inner.y))
		//	return RESIZE_BL;
		RowVector2d mouse;
		mouse << mousePointer.x, mousePointer.y;
		RowVector2d pts[4];
		pts[0] << pts_[0].x, pts_[0].y;	pts[1] << pts_[1].x, pts_[1].y;	
		pts[2] << pts_[2].x, pts_[2].y;	pts[3] << pts_[3].x, pts_[3].y;
		RowVector2d diag1, diag2;
		diag1 = pts[2] - pts[0]; diag2 = pts[3] - pts[1];
		double l1, l2;
		l1 = diag1.norm(); l2 = diag2.norm();
		double cornerZone1, cornerZone2;
		cornerZone1 = l1 * cornerLengthPercentage_; cornerZone2 = l2 * cornerLengthPercentage_;
		int ret = -1;
		if ((mouse - pts[0]).norm() <= cornerZone1) {
			ret = P0;
		} else if ((mouse - pts[2]).norm() <= cornerZone1) {
			ret = P2;
		} else if ((mouse - pts[1]).norm() <= cornerZone2) {
			ret = P1;
		} else if ((mouse - pts[3]).norm() <= cornerZone2) {
			ret = P3;
		}
		printf("%d\n", ret);
		if (ret != -1) return ret;
		return MOVE_RECT;
	}
	else
		return -1;
}

void CaptureTrapezium::moveCorner(int drawMethod, CvPoint vector) {
	CvPoint2D32f dest;
	CvPoint2D32f newPoints[4];
	switch (drawMethod) {
	case P0:
		dest = addVectors(pts_[0], vector);
		newPoints[0] = dest; 
		newPoints[1] = pts_[1]; newPoints[2] = pts_[2]; newPoints[3] = pts_[3];
		if (isConvex(newPoints)) {
			pts_[0] = addVectors(pts_[0], vector);
		}
		break;
	case P1:
		dest = addVectors(pts_[1], vector);
		newPoints[1] = dest; 
		newPoints[0] = pts_[0]; newPoints[2] = pts_[2]; newPoints[3] = pts_[3];
		if (isConvex(newPoints)) {
			pts_[1] = addVectors(pts_[1], vector);
		}
		break;
	case P2:
		dest = addVectors(pts_[2], vector);
		newPoints[2] = dest; 
		newPoints[1] = pts_[1]; newPoints[0] = pts_[0]; newPoints[3] = pts_[3];
		if (isConvex(newPoints)) {
			pts_[2] = addVectors(pts_[2], vector);
		}
		break;
	case P3:
		dest = addVectors(pts_[3], vector);
		newPoints[3] = dest; 
		newPoints[1] = pts_[1]; newPoints[2] = pts_[2]; newPoints[0] = pts_[0];
		if (isConvex(newPoints)) {
			pts_[3] = addVectors(pts_[3], vector);
		}
		break;
	default:
		throw "Exception here, change to something meaningful please!";
	}
	fixBoundaryRect();
}

void CaptureTrapezium::fixBoundaryRect() {
	int x1, y1, x2, y2;
	x1 = (int)minFour(pts_[0].x, pts_[1].x, pts_[2].x, pts_[3].x);
	y1 = (int)minFour(pts_[0].y, pts_[1].y, pts_[2].y, pts_[3].y);
	x2 = (int)maxFour(pts_[0].x, pts_[1].x, pts_[2].x, pts_[3].x);
	y2 = (int)maxFour(pts_[0].y, pts_[1].y, pts_[2].y, pts_[3].y);
	rect_.x = x1; rect_.y = y1;
	rect_.width = x2 - x1;
	rect_.height = y2 - y1;
}

void CaptureTrapezium::move(CvPoint vector) {
	rect_.x += vector.x; rect_.y += vector.y;
	pts_[0] = addVectors(pts_[0], vector);
	pts_[1] = addVectors(pts_[1], vector);
	pts_[2] = addVectors(pts_[2], vector);
	pts_[3] = addVectors(pts_[3], vector);
}

double CaptureTrapezium::maxFour(double a, double b, double c, double d) {
	return (a>b&&a>c&&a>d?a:b>c&&b>d?b:c>d?c:d);
}

double CaptureTrapezium::minFour(double a, double b, double c, double d) {
	return (a<b&&a<c&&a<d?a:b<c&&b<d?b:c<d?c:d);
}

CvPoint2D32f CaptureTrapezium::getPoint(int it) {
	return pts_[it];
}

bool CaptureTrapezium::isConvex(CvPoint2D32f pts[4]) {
	return (!areOnSameSide(pts[0], pts[2], pts[1], pts[3])) && 
		(!areOnSameSide(pts[1], pts[3], pts[0], pts[2]));
}