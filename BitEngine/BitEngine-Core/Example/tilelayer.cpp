#include "tilelayer.h"

TileLayer::TileLayer(BitEngine::graphics::Shader* shader)
	: Layer(new BitEngine::graphics::BatchRenderer2D(), shader, BitEngine::maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -10.0f, 10.0f))
{
			
}

TileLayer::~TileLayer() 
{
			
}