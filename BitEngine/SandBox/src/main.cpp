#include <BitEngine.h>

using namespace bt;
using namespace graphics;
using namespace maths;

class Game : public Application
{
public:
	Game()
		: Application("SandBox", {1280,720,false,false}, bt::graphics::API::RenderAPI::OPENGL)
	{ }

	~Game() 
	{ }

	void Init() override {
		Application::Init();
	}
};

int main() {

	Game game;
	game.Start();
	
	return 0;
}