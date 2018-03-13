#pragma once

#include "../src/graphics/layers/layer.h"
#include "../src/graphics/2D/batchrenderer2D.h"

class TileLayer : public BitEngine::graphics::Layer  {
public:
	TileLayer(BitEngine::graphics::Shader* shader);
	~TileLayer();
};