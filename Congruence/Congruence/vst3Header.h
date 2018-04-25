/*
==============================================================================

This file is part of the Congruence library.
Copyright (c) 2017 - Tyler Small.

Congruence is an open source library subject to commercial or open-source
licensing.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

CONGRUENCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
DISCLAIMED.

Code in this file is adopted from JUCE, copyright Copyright (c) 2017 - ROLI Ltd.
under fair use defined by GPL v3 (see www.gnu.org/licenses).
https://juce.com/

See license file for details.

==============================================================================
*/
#if _MSC_VER && !__INTEL_COMPILER
#pragma once
#endif

#ifndef VST3HEADER_H
#define VST3HEADER_H

#ifdef _WIN32 || _WIN64
#define _WIN32_WINNT_WIN7                   0x0601 // Windows 7  
#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8  
#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1  
#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10  
#define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10

/*additional include directory needed for Windows.h on your system*/
/*C:\Program Files (x86)\Windows Kits\8.1\*/
#if __has_include("Include/um\Windows.h")
#include <Include/um\Windows.h> //win 8.1
#elif __has_include("10.0.14393.0\um\Windows.h")
#include <10.0.14393.0\um\Windows.h> //win 10
#endif //windows path
#endif //windows

///NEED ANDROID HEADERSSSS

/*additional include directory needed for vstsdk*/
/*C:\...\vstSDK369\VST_SDK\VST3_SDK*/
#include <base/source/fstring.h>
#include <pluginterfaces/base/conststringtable.h>
#include <pluginterfaces/base/funknown.h>
#include <pluginterfaces/base/ipluginbase.h>
#include <pluginterfaces/base/ustring.h>
#include <pluginterfaces/gui/iplugview.h>
#include <pluginterfaces/gui/iplugviewcontentscalesupport.h>
#include <pluginterfaces/vst/ivstattributes.h>
#include <pluginterfaces/vst/ivstaudioprocessor.h>
#include <pluginterfaces/vst/ivstcomponent.h>
#include <pluginterfaces/vst/ivstcontextmenu.h>
#include <pluginterfaces/vst/ivsteditcontroller.h>
#include <pluginterfaces/vst/ivstevents.h>
#include <pluginterfaces/vst/ivsthostapplication.h>
#include <pluginterfaces/vst/ivstmessage.h>
#include <pluginterfaces/vst/ivstmidicontrollers.h>
#include <pluginterfaces/vst/ivstparameterchanges.h>
#include <pluginterfaces/vst/ivstplugview.h>
#include <pluginterfaces/vst/ivstprocesscontext.h>
#include <pluginterfaces/vst/vsttypes.h>
#include <pluginterfaces/vst/ivstunits.h>
#include <pluginterfaces/vst/ivstmidicontrollers.h>
#include <pluginterfaces/vst/ivstchannelcontextinfo.h>
#include <public.sdk/source/common/memorystream.h>
#include <public.sdk/source/vst/vsteditcontroller.h>
#include <public.sdk/source/vst/vstpresetfile.h>

// needed for VST_VERSION
#include <pluginterfaces/vst/vsttypes.h>

#include <base/source/baseiids.cpp>
#include <base/source/fbuffer.cpp>
#include <base/source/fdebug.cpp>
#include <base/source/fobject.cpp>
#include <base/source/fstreamer.cpp>
#include <base/source/fstring.cpp>
#if VST_VERSION >= 0x030608
#include <base/thread/source/flock.cpp>
#include <pluginterfaces/base/coreiids.cpp>
#else
#include <base/source/flock.cpp>
#endif
#include <base/source/updatehandler.cpp>
#include <pluginterfaces/base/conststringtable.cpp>
#include <pluginterfaces/base/funknown.cpp>
#include <pluginterfaces/base/ipluginbase.h>
#include <pluginterfaces/base/ustring.cpp>
#include <pluginterfaces/gui/iplugview.h>
#include <pluginterfaces/gui/iplugviewcontentscalesupport.h>
#include <pluginterfaces/vst/ivstmidicontrollers.h>
#include <pluginterfaces/vst/ivstchannelcontextinfo.h>
#include <public.sdk/source/common/memorystream.cpp>
#include <public.sdk/source/common/pluginview.cpp>
#include <public.sdk/source/vst/vsteditcontroller.cpp>
#include <public.sdk/source/vst/vstbus.cpp>
#include <public.sdk/source/vst/vstinitiids.cpp>
#include <public.sdk/source/vst/vstcomponent.cpp>
#include <public.sdk/source/vst/vstcomponentbase.cpp>
#include <public.sdk/source/vst/vstparameters.cpp>
#include <public.sdk/source/vst/vstpresetfile.cpp>
#include <public.sdk/source/vst/hosting/hostclasses.cpp>

namespace Steinberg
{
	/** Missing IIDs */
	DEF_CLASS_IID(IPluginBase)
		DEF_CLASS_IID(IPlugView)
		DEF_CLASS_IID(IPlugFrame)
#if VST_VERSION < 0x030608
		DEF_CLASS_IID(IBStream)
#endif
		DEF_CLASS_IID(IPluginFactory)
		DEF_CLASS_IID(IPluginFactory2)
		DEF_CLASS_IID(IPluginFactory3)
		DEF_CLASS_IID(IPlugViewContentScaleSupport)
}

//==============================================================================
#undef ASSERT
#undef WARNING
#undef PRINTSYSERROR
#undef DEBUGSTR
#undef DBPRT0
#undef DBPRT1
#undef DBPRT2
#undef DBPRT3
#undef DBPRT4
#undef DBPRT5
#undef min
#undef max
#undef MIN
#undef MAX
#undef calloc
#undef free
#undef malloc
#undef realloc
#undef NEW
#undef NEWVEC
#undef VERIFY
#undef VERIFY_IS
#undef VERIFY_NOT
#undef META_CREATE_FUNC
#undef CLASS_CREATE_FUNC
#undef SINGLE_CREATE_FUNC
#undef _META_CLASS
#undef _META_CLASS_IFACE
#undef _META_CLASS_SINGLE
#undef META_CLASS
#undef META_CLASS_IFACE
#undef META_CLASS_SINGLE
#undef SINGLETON
#undef OBJ_METHODS
#undef QUERY_INTERFACE
#undef LICENCE_UID
#undef BEGIN_FACTORY
#undef DEF_CLASS
#undef DEF_CLASS1
#undef DEF_CLASS2
#undef DEF_CLASS_W
#undef END_FACTORY
#undef void c_decl free(void *_Block)
#undef _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)

#endif /*vst3sdk*/