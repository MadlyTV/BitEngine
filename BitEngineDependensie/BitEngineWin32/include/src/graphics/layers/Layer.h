#pragma once

#include "bt\common.h"
#include "bt\types.h"

#include "../../events/Event.h"
#include "../../events/IEventListener.h"

#include "bt\app\Window.h"
#include "bt\utils\Timestep.h"

namespace bt { namespace graphics {
	class BT_API Layer : public events::IEventListener {
	protected:
		Window* m_Window;
		bool m_Visible;
	public:
		Layer();
		virtual ~Layer();

		inline bool IsVisible() const { return m_Visible; }
		inline void SetVisible(bool visible) { m_Visible = visible; }

		virtual void Init();
		virtual void OnEvent(events::Event& event);
		virtual void OnTick();
		virtual void OnUpdate(const Timestep& ts);
		virtual void OnUpdateInternal(const Timestep& ts);
		virtual void OnRender();
	protected:
		virtual bool OnResize(uint width, uint height);
	};
} }