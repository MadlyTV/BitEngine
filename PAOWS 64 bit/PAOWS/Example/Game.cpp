#include "../src/BitEngine.h"

using namespace BitEngine;
using namespace graphics;
using namespace maths;

class Game : public BitEngine {
private:
	Window* window;
	Layer* layer;
	Sprite* top;
	Sprite* bottom;

	Sprite* player1;
	Sprite* player2;

	maths::Rectangle *ballrec;

	Sprite* Player1win;
	Sprite* Player2win;

	int winner;

	Sprite* ball;
	vec2* ballDirection;
public:
	Game() {

	}

	~Game() {
		delete layer;
	}

	void init() override {
		window = createWindow("ExampelPongGame", 1280, 720);
		layer = new Layer(new BatchRenderer2D(), new Shader("src/shaders/basic.vert", "src/shaders/basic.frag"), maths::mat4::orthographic(-16,16, -9,9, -1,1));

		//WinScreens
		Player1win = new Sprite(-1000, -1000, 9, 3, new Texture("Example/Res/Player1.png"));
		Player2win = new Sprite(-1000, -1000, 9, 3, new Texture("Example/Res/Player2.png"));

		//top
		top = new Sprite(-16, 8.8, 32, 0.2, maths::vec4(1, 1, 1, 1));

		//bottom
		bottom = new Sprite(-16, -9, 32, 0.2, maths::vec4(1, 1, 1, 1));

		//middle
		for (int y = -9; y < 8.8; y += 4) {
			layer->add(new Sprite(-0.4, y, 0.8, 2, maths::vec4(1,1,1,1)));
		}

		//player1
		player1 = new Sprite(-16, -2, 0.4, 4, maths::vec4(1,0,0,1));

		//player2
		player2 = new Sprite(15.6, -2, 0.4, 4, maths::vec4(0, 0, 1, 1));

		//ball
		ball = new Sprite(-0.125, 0, 0.25, 0.25, maths::vec4(0, 1, 0, 1));
		ballrec =  new maths::Rectangle(ball->position.x, ball->position.y, 10, 10);

		ballDirection = new vec2(0.2, 0.18f);

		winner = 0;

		layer->add(top);
		layer->add(bottom);

		layer->add(player1);
		layer->add(player2);

		layer->add(Player1win);
		layer->add(Player2win);

		layer->add(ball);
	}

	void tick() override {
		std::cout << "UPS: " << getUPS() << " FPS: " << getFPS() << std::endl;
	}

	void update() override {

		float speed = 0.25f;

		if (winner == 0) {

			if (window->isKeyPressed(GLFW_KEY_W)) {
				player1->position.y += speed;
			}
			else if (window->isKeyPressed(GLFW_KEY_S)) {
				player1->position.y -= speed;
			}

			if (window->isKeyPressed(GLFW_KEY_UP)) {
				player2->position.y += speed;
			}
			else if (window->isKeyPressed(GLFW_KEY_DOWN)) {
				player2->position.y -= speed;
			}

			if (player1->position.y >= 9 - player1->GetSize().y - top->GetSize().y) {
				player1->position.y = 9 - player1->GetSize().y - top->GetSize().y;
			}

			if (player1->position.y <= -9 + bottom->GetSize().y) {
				player1->position.y = -9 + bottom->GetSize().y;
			}

			if (player2->position.y >= 9 - player2->GetSize().y - top->GetSize().y) {
				player2->position.y = 9 - player2->GetSize().y - top->GetSize().y;
			}

			if (player2->position.y <= -9 + bottom->GetSize().y) {
				player2->position.y = -9 + bottom->GetSize().y;
			}

			if (ball->position.y >= 9-ball->GetSize().y) {
				ballDirection->y *= -1;
			}

			if (ball->position.y <= -9) {
				ballDirection->y *= -1;
			}

			if (ball->position.x >= 16) {
				winner = 1;
			}

			if (ball->position.x <= -16 - ball->GetSize().x) {
				winner = 2;
			}

			if (maths::Rectangle(ball->GetPosition(), ball->GetSize()).Intersects(maths::Rectangle(player2->GetPosition(),player2->GetSize()))) {
				ballDirection->x *= -1;
			}

			if (maths::Rectangle(ball->GetPosition(), ball->GetSize()).Intersects(maths::Rectangle(player1->GetPosition(), player1->GetSize()))) {
				ballDirection->x *= -1;
			}

			ball->position += *ballDirection;
		}
		else if (winner == 1) {
			Player1win->position = vec2(-4.5, -2);

			if (window->isKeyPressed(GLFW_KEY_SPACE)) {
				winner = 0;

				ball->position.x = 0 - ball->GetSize().x/2;

				Player1win->position = vec2(-1000, -1000);
				Player2win->position = vec2(-1000, -1000);
			}
		}
		else if (winner == 2) {
			Player2win->position = vec2(-4.5, -2);

			if (window->isKeyPressed(GLFW_KEY_SPACE)) {
				winner = 0;

				ball->position.x = 0 - ball->GetSize().x / 2;

				Player1win->position = vec2(-1000, -1000);
				Player2win->position = vec2(-1000, -1000);
			}
		}
	}

	void render() override {
		layer->render();
	}
};

int main() {

	Game game;
	game.start();

	return 0;
}