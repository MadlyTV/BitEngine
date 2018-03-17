#pragma once

//app stuff
#include <bt\app\Application.h>
#include <bt\app\Input.h>
#include <bt\app\Window.h>

//event stuff
#include <bt\events\Event.h>
#include <bt\events\EventDispatcher.h>
#include <bt\events\Events.h>
#include <bt\events\IEventListener.h>
#include <bt\events\KeyEvent.h>
#include <bt\events\MouseEvent.h>
#include <bt\events\WindowEvent.h>

//api
#include <bt\graphics\API\Context.h>
//layer
#include <bt\graphics\layers\Layer.h>
//graphis
#include <bt\graphics\Renderer.h>

//maths stuff
#include <bt\maths\AABB.h>
#include <bt\maths\mat4.h>
#include <bt\maths\maths.h>
#include <bt\maths\maths_func.h>
#include <bt\maths\Rectangle.h>
#include <bt\maths\tvec2.h>
#include <bt\maths\vec2.h>
#include <bt\maths\vec3.h>
#include <bt\maths\vec4.h>

//opengl
//#include <bt\platform\opengl\GLCommon.h>
#include <bt\platform\opengl\GLContext.h>
#include <bt\platform\opengl\GLRenderer.h>


//System
#include <bt\system\Allocator.h>
#include <bt\system\FileSystem.h>
#include <bt\system\Memory.h>
#include <bt\system\MemoryManager.h>
#include <bt\system\System.h>
#include <bt\system\VFS.h>

//utils stuff
#include <bt\utils\Log.h>
#include <bt\utils\time.h>
#include <bt\utils\timer.h>
#include <bt\utils\Timestep.h>

//common suff
//#include <bt\common.h>
#include <bt\String.h>
#include <bt\types.h>