#pragma once

#include "Event.h"

namespace bt { namespace events {

	class BT_API IEventListener {
	public:
		virtual void OnEvent(Event& event) = 0;
	};

} }