#pragma once

#include "../../maths/maths.h"
#include "camera.h"

namespace BitEngine { namespace graphics {

	class OrthographicCamera : public Camera
	{
	private:

	public:
		OrthographicCamera(const maths::mat4& projectionMatrix);
		~OrthographicCamera();

		void Focus() override;
		void Update() override;
		
	};

} }