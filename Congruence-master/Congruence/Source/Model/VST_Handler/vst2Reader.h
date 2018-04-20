/*
  ==============================================================================

    vst2Reader.h
    Created: 19 Apr 2018 7:56:09pm
    Author:  Tyler

  ==============================================================================
*/

#pragma once

#include "aeffect.h"
#include "aeffectx.h"
#include "vsfxstore.h"

// C callbacks
extern "C" {
// Main host callback
  VstIntPtr VSTCALLBACK hostCallback(AEffect *effect, VstInt32 opcode,
    VstInt32 index, VstInt32 value, void *ptr, float opt);
}

// Plugin's entry point
typedef AEffect *(*vstPluginFuncPtr)(audioMasterCallback host);
// Plugin's dispatcher function
typedef VstIntPtr (*dispatcherFuncPtr)(AEffect *effect, VstInt32 opCode,
  VstInt32 index, VstInt32 value, void *ptr, float opt);
// Plugin's getParameter() method
typedef float (*getParameterFuncPtr)(AEffect *effect, VstInt32 index);
// Plugin's setParameter() method
typedef void (*setParameterFuncPtr)(AEffect *effect, VstInt32 index, float value);
// Plugin's processEvents() method
typedef VstInt32 (*processEventsFuncPtr)(VstEvents *events);
// Plugin's process() method
typedef void (*processFuncPtr)(AEffect *effect, float **inputs,
  float **outputs, VstInt32 sampleFrames);

class vst2Reader {
    private:
    
    
    public:
     /* */
     AEffect* loadPluginWin();
     AEffect* loadPluginMac();
    
}
