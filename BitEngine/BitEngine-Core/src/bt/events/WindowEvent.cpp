#include "bt\bt.h"
#include "WindowEvent.h"

namespace bt { namespace events {

	ResizeWindowEvent::ResizeWindowEvent(uint width, uint height)
		: Event(ResizeWindowEvent::GetStaticType()), m_Size(maths::tvec2<uint>(width, height))
	{ }

} }