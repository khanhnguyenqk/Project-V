// generated by Fast Light User Interface Designer (fluid) version 1.0300
#include "stdafx.h"
#include "VideoPlayerUI.h"

VideoPlayerUI::VideoPlayerUI() {
  { int wMainWindow, hMainWindow;
	wMainWindow = 1720;
	hMainWindow = 960;
	mainWindow_ = new Fl_Double_Window(50, 50, wMainWindow, hMainWindow);
	mainWindow_->box(FL_UP_BOX);
	mainWindow_->user_data((void*)(this));

	int gap = 5;
    int xFilePathInput, yFilePathInput, wFilePathInput, hFilePathInput;
	int xOpenFile, yOpenFile, wOpenFile, hOpenFile;
	int hSmlButton, wSmlButton, hMedButton, wMedButton;
	int xViewGroup, yViewGroup, wViewGroup, hViewGroup;
	int xControlGroup, yControlGroup, hControlGroup, wControlGroup;
	int xDrawTools, yDrawTools, wDrawTools, hDrawTools;
	
	
	int xXPan, yXPan, wXPan, hXPan;
	int xYPan, yYPan, wYPan, hYPan;
	int xZoom, yZoom, wZoom, hZoom;
	int xSlider, ySlider, wSlider, hSlider;
	int xVideoWindow, yVideoWindow, wVideoWindow, hVideoWindow;

	hSmlButton = 25; wSmlButton = 60;
	hMedButton = 25; wMedButton = 80;

    {
		hFilePathInput = 35; yFilePathInput = 0; wFilePathInput = (int)(0.6*wMainWindow); xFilePathInput = 70;
		yOpenFile = yFilePathInput + gap; xOpenFile = xFilePathInput + wFilePathInput + gap; 
		hOpenFile = hFilePathInput - 2*gap; 
		wOpenFile = wSmlButton;

		Fl_Group* o = new Fl_Group(0, 0, int(wMainWindow * 0.8), hFilePathInput, "FileInputGroup");
		o->labeltype(FL_NO_LABEL);
		{ filePathInput_ = new Fl_File_Input(xFilePathInput, yFilePathInput, 
									wFilePathInput, hFilePathInput, "File Path");
		}// Fl_File_Input* filePathInput_
		{openFile_ = new Fl_Button(xOpenFile, yOpenFile, wOpenFile, hOpenFile, "Open");} // Fl_Button* stop_
		{defaultSetting_ = new Fl_Button(xOpenFile+wOpenFile+gap,yOpenFile,wMedButton,hOpenFile,"Default");}
		o->end();
    } // Fl_Group* o
    { 
		xViewGroup = 0;	yViewGroup = yFilePathInput + hFilePathInput; 
		wViewGroup = int(wMainWindow * 0.8);	hViewGroup = int(hMainWindow * 0.8);
		hXPan = hSlider = wYPan = wZoom = 35;
		xZoom = xViewGroup; yXPan = yViewGroup;
		yZoom = yViewGroup + hXPan; xXPan = xViewGroup + wZoom;
		xSlider = xViewGroup + wZoom; yYPan = yViewGroup + hXPan;
		ySlider = yViewGroup + hViewGroup - hSlider;
		xYPan = xViewGroup + wViewGroup - wYPan;
		hZoom = hViewGroup - hXPan - hSlider;
		hYPan = hViewGroup - hXPan - hSlider;
		wXPan = wViewGroup - wZoom - wYPan;
		wSlider = wViewGroup - wZoom - wYPan;
		xVideoWindow = xViewGroup + wZoom; yVideoWindow = yViewGroup + hXPan;
		wVideoWindow = wViewGroup - wZoom - wYPan;
		hVideoWindow = hViewGroup - hXPan - hSlider;

		Fl_Group* o = new Fl_Group(xViewGroup, yViewGroup, wViewGroup, hViewGroup, "videoView");
      o->labeltype(FL_NO_LABEL);
      { xPan_ = new Fl_Value_Slider(xXPan, yXPan, wXPan, hXPan, "XPan");
        xPan_->type(5);
        xPan_->box(FL_BORDER_BOX);
		xPan_->labeltype(FL_NO_LABEL);
        xPan_->minimum(-1);
        xPan_->textsize(14);
      } // Fl_Value_Slider* xPan_
      { yPan_ = new Fl_Value_Slider(xYPan, yYPan, wYPan, hYPan, "YPan");
        yPan_->type(4);
        yPan_->box(FL_BORDER_BOX);
		yPan_->labeltype(FL_NO_LABEL);
        yPan_->minimum(-1);
        yPan_->textfont(4);
        yPan_->textsize(14);
      } // Fl_Value_Slider* yPan_
      { zoom_ = new Fl_Value_Slider(xZoom, yZoom, wZoom, hZoom, "Zoom");
        zoom_->type(4);
        zoom_->box(FL_BORDER_BOX);
		zoom_->labeltype(FL_NO_LABEL);
        zoom_->minimum(0.1);
        zoom_->maximum(10);
        zoom_->value(1);
        zoom_->textsize(14);
      } // Fl_Value_Slider* zoom_
      { aoiProcessorWindow = new AoiProcessWindow(xVideoWindow, yVideoWindow, wVideoWindow, hVideoWindow, 
										NULL, "Video Window");
        aoiProcessorWindow->box(FL_NO_BOX);
        aoiProcessorWindow->color(FL_BACKGROUND_COLOR);
        aoiProcessorWindow->selection_color(FL_BACKGROUND_COLOR);
        aoiProcessorWindow->labeltype(FL_NO_LABEL);
        aoiProcessorWindow->labelfont(0);
        aoiProcessorWindow->labelsize(14);
        aoiProcessorWindow->labelcolor(FL_FOREGROUND_COLOR);
        aoiProcessorWindow->align(Fl_Align(FL_ALIGN_CENTER));
        aoiProcessorWindow->when(FL_WHEN_RELEASE);
      } // VideoWindow* aoiProcessorWindow
      { slider_ = new Fl_Slider(xSlider, ySlider, wSlider, hSlider, "Slider");
        slider_->type(3);
        slider_->box(FL_BORDER_BOX);
        slider_->color(FL_SELECTION_COLOR);
        slider_->labeltype(FL_NO_LABEL);
        slider_->maximum(100);
        slider_->value(0);
      } // Fl_Slider* slider_
      o->end();
    } // Fl_Group* o
    { 
		xControlGroup = 0; yControlGroup = hFilePathInput + hViewGroup;
		hControlGroup = hMainWindow - yControlGroup; wControlGroup = int(wMainWindow*0.8);
		Fl_Group* o = new Fl_Group(xControlGroup, yControlGroup, wControlGroup, hControlGroup, "controllerGroup");
      o->labeltype(FL_NO_LABEL);
      { stop_ = new Fl_Button(420, yControlGroup + gap, wSmlButton, hSmlButton, "@square");
      } // Fl_Button* stop_
      { play_ = new Fl_Button(485, yControlGroup + gap, wSmlButton, hSmlButton, "@>|");
      } // Fl_Button* play_
      { halfSpeed_ = new Fl_Button(285, yControlGroup + gap, wSmlButton, hSmlButton, "@<<");
      } // Fl_Button* halfSpeed_
      { doubleSpeed_ = new Fl_Button(615, yControlGroup + gap, wSmlButton, hSmlButton, "@>>");
      } // Fl_Button* doubleSpeed_
      { prevFrame_ = new Fl_Button(355, yControlGroup + gap, wSmlButton, hSmlButton, "@<");
      } // Fl_Button* prevFrame_
      { nextFrame_ = new Fl_Button(550, yControlGroup + gap, wSmlButton, hSmlButton, "@>");
      } // Fl_Button* nextFrame_
	  { videoDetails_ = new Fl_Multiline_Output(100, yControlGroup + 35, 600, hMainWindow - yControlGroup - 35 - gap);
	  videoDetails_->labeltype(FL_NO_LABEL);
	  } // Fl_Multiline_Output* videoDetails_
      o->end();
    } // Fl_Group* o

    {	xDrawTools = xViewGroup + wViewGroup + gap;
		yDrawTools = 20;
		wDrawTools = wMainWindow - xDrawTools;
		hDrawTools = hMainWindow;
		Fl_Group* o = new Fl_Group(xDrawTools, yDrawTools, wDrawTools, hDrawTools, "Drawing tools");
		{ newAOI_ = new Fl_Button(xDrawTools + gap, yDrawTools + gap, 
									wMedButton, hMedButton, "New AOI");
		}
		{ deleteAOI_ = new Fl_Button(xDrawTools+2*gap+wMedButton, yDrawTools+gap, 
									wMedButton, hMedButton, "Del AOI");
		}
		{ prevAOI_ = new Fl_Button(xDrawTools+gap, yDrawTools+2*gap+hMedButton, 
			wMedButton, hMedButton, "Prev AOI");
		}
		{ nextAOI_ = new Fl_Button(xDrawTools+2*gap+wMedButton, yDrawTools+2*gap+hMedButton, 
			wMedButton, hMedButton, "Next AOI");
		}
		{ savePicture_ = new Fl_Button(xDrawTools+gap,yDrawTools+3*gap+2*hMedButton,wMedButton,hMedButton,
			"Save");
		}
		{ useRect_ = new Fl_Button(xDrawTools+2*gap+wMedButton,yDrawTools+3*gap+2*hMedButton,wMedButton,hMedButton,
			"Rectangle");
		}
      o->end();
    } // Fl_Group* o
    mainWindow_->end();
  } // Fl_Double_Window* mainWindow_

  // Extra code
  aoiProcessorWindow->addDependent(slider_);
  aoiProcessorWindow->addDependent(videoDetails_);

  // Tool tips
  stop_->tooltip("Stop");
  play_->tooltip("Play/Pause");
  doubleSpeed_->tooltip("Double Speed");
  halfSpeed_->tooltip("Half Speed");
  nextFrame_->tooltip("Next Frame (Video has to be paused)");
  prevFrame_->tooltip("Previous Frame (Video has to be paused)");
  zoom_->tooltip("Zoom");
  xPan_->tooltip("X pan");
  yPan_->tooltip("Y pan");
  slider_->tooltip("Video slider");

  // Call back
  play_->callback((Fl_Callback*)cb_play);
  stop_->callback((Fl_Callback*)cb_stop);
  doubleSpeed_->callback((Fl_Callback*)cb_doubleSpeed);
  halfSpeed_->callback((Fl_Callback*)cb_halfSpeed);
  nextFrame_->callback((Fl_Callback*)cb_nextFrame);
  prevFrame_->callback((Fl_Callback*)cb_prevFrame);
  zoom_->callback((Fl_Callback*)cb_zoom);
  xPan_->callback((Fl_Callback*)cb_xPan);
  yPan_->callback((Fl_Callback*)cb_yPan);
  slider_->callback((Fl_Callback*)cb_slider);
  openFile_->callback((Fl_Callback*)cb_openFile);
  newAOI_->callback((Fl_Callback*)cb_newAOI);
  deleteAOI_->callback((Fl_Callback*)cb_delAOI);
  nextAOI_->callback((Fl_Callback*)cb_nextAOI);
  prevAOI_->callback((Fl_Callback*)cb_prevAOI);
  defaultSetting_->callback((Fl_Callback*)cb_default);
  savePicture_->callback((Fl_Callback*)cb_save);
  useRect_->callback((Fl_Callback*)cb_useRect);
}

// Call back methods
void VideoPlayerUI::cb_play_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->switchPlayPause();
}
void VideoPlayerUI::cb_play(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_play_i(obj, v);
}

void VideoPlayerUI::cb_stop_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->stop();
}
void VideoPlayerUI::cb_stop(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_stop_i(obj, v);
}

void VideoPlayerUI::cb_doubleSpeed_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->doubleSpeed();
}
void VideoPlayerUI::cb_doubleSpeed(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_doubleSpeed_i(obj, v);
}

void VideoPlayerUI::cb_halfSpeed_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->halfSpeed();
}
void VideoPlayerUI::cb_halfSpeed(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_halfSpeed_i(obj, v);
}

void VideoPlayerUI::cb_prevFrame_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->pause();
	this->aoiProcessorWindow->showPrevFrame();
}
void VideoPlayerUI::cb_prevFrame(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_prevFrame_i(obj, v);
}

void VideoPlayerUI::cb_nextFrame_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->pause();
	this->aoiProcessorWindow->showNextFrame();
}
void VideoPlayerUI::cb_nextFrame(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_nextFrame_i(obj, v);
}

void VideoPlayerUI::cb_zoom_i(Fl_Value_Slider * o, void * v)
{
	this->aoiProcessorWindow->zoomRatio_=o->value();
	this->aoiProcessorWindow->redraw();
}
void VideoPlayerUI::cb_zoom(Fl_Value_Slider * o, void * v)
{
	((VideoPlayerUI*)(o->parent()->parent()->user_data()))->cb_zoom_i(o,v);	
}

void VideoPlayerUI::cb_xPan_i(Fl_Value_Slider* o, void*) 
{
	this->aoiProcessorWindow->xPanRatio_=o->value();
	this->aoiProcessorWindow->redraw();
}
void VideoPlayerUI::cb_xPan(Fl_Value_Slider* o, void* v) 
{
	((VideoPlayerUI*)(o->parent()->parent()->user_data()))->cb_xPan_i(o,v);
}

void VideoPlayerUI::cb_yPan_i(Fl_Value_Slider* o, void*) 
{
	this->aoiProcessorWindow->yPanRatio_=o->value();
	this->aoiProcessorWindow->redraw();
}
void VideoPlayerUI::cb_yPan(Fl_Value_Slider* o, void* v) 
{
	((VideoPlayerUI*)(o->parent()->parent()->user_data()))->cb_yPan_i(o,v);
}

void VideoPlayerUI::cb_slider_i(Fl_Slider* obj, void* v) {
	this->aoiProcessorWindow->jumpToFrame((int)obj->value());
}
void VideoPlayerUI::cb_slider(Fl_Slider* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_slider_i(obj, v);
}

void VideoPlayerUI::cb_openFile_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->stop();
	this->aoiProcessorWindow->deleteAllTools();
	this->aoiProcessorWindow->initiateVideo(this->filePathInput_->value());
	this->aoiProcessorWindow->play();
}
void VideoPlayerUI::cb_openFile(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_openFile_i(obj, v);
}

void VideoPlayerUI::cb_newAOI_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->setDrawStatus();
}
void VideoPlayerUI::cb_newAOI(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_newAOI_i(obj, v);
}

void VideoPlayerUI::cb_delAOI_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->deleteCurrentTool();
	this->aoiProcessorWindow->cloneAndDrawTools();
}
void VideoPlayerUI::cb_delAOI(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_delAOI_i(obj, v);
}

void VideoPlayerUI::cb_nextAOI_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->nextAOI();
	this->aoiProcessorWindow->cloneAndDrawTools();
}
void VideoPlayerUI::cb_nextAOI(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_nextAOI_i(obj, v);
}

void VideoPlayerUI::cb_prevAOI_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->prevAOI();
	this->aoiProcessorWindow->cloneAndDrawTools();
}
void VideoPlayerUI::cb_prevAOI(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_prevAOI_i(obj, v);
}

void VideoPlayerUI::cb_default_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->setNormalSpeed();
	this->aoiProcessorWindow->xPanRatio_ = 0;
	this->aoiProcessorWindow->yPanRatio_ = 0;
	this->aoiProcessorWindow->zoomRatio_ = 1;
	this->xPan_->value(0);
	this->yPan_->value(0);
	this->zoom_->value(1);
}
void VideoPlayerUI::cb_default(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_default_i(obj, v);
}

void VideoPlayerUI::cb_save_i(Fl_Button* obj, void* v) {
	this->aoiProcessorWindow->saveScreen();
}
void VideoPlayerUI::cb_save(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_save_i(obj, v);
}

void VideoPlayerUI::cb_useRect_i(Fl_Button* obj, void* v) {
	if (this->aoiProcessorWindow->isUsingRectangle()) {
		useRect_->label("Trapezium");
		this->aoiProcessorWindow->useRectangle(false);
	} else {
		useRect_->label("Rectangle");
		this->aoiProcessorWindow->useRectangle(true);
	}
	
}
void VideoPlayerUI::cb_useRect(Fl_Button* obj, void* v) {
	((VideoPlayerUI*)(obj->parent()->parent()->user_data()))->cb_useRect_i(obj, v);
}

// Other methods
void VideoPlayerUI::setFilePath(const char* filePath) {
	this->filePathInput_->value(filePath);
}