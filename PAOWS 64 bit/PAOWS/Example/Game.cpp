#include "../src/BitEngine.h"

using namespace BitEngine;
using namespace graphics;
using namespace maths;

class Game : public BitEngine {
private:
	//the window and the layer varibals
	Window* window;
	Layer* layer;

	//referense for all the sprites
	Sprite* top;
	Sprite* bottom;

	Sprite* player1;
	Sprite* player2;

	Sprite* Player1win;
	Sprite* Player2win;

	Sprite* ball;

	//the direction the ball is moving in;
	vec2* ballDirection;

	//a varibal to check if a player has won and with player won
	int winner;

	//the speed for the players
	float speed = 0.25f;
public:
	Game() {

	}

	~Game() {
		//deletes tha layer vaibal when the game exits to clean up memory
		delete layer;
	}

	void init() override {
		//initializes the whe window
		window = createWindow("ExampelPongGame", 1280, 720);

		//initialises the layer with a BatchRenderer and a standard shader and a orthographic view
		layer = new Layer(new BatchRenderer2D(), new Shader(), maths::mat4::orthographic(-16,16, -9,9, -1,1));

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

		ballDirection = new vec2(0.4, 0.38f);

		winner = 0;

		//adds all the sprites to my layer
		layer->add(top);
		layer->add(bottom);

		layer->add(player1);
		layer->add(player2);

		layer->add(Player1win);
		layer->add(Player2win);

		layer->add(ball);
	}

	void tick() override {
		//spits out the UPS(updated per second) and FPS (frames per second) in the game console
		std::cout << "UPS: " << getUPS() << " FPS: " << getFPS() << std::endl;
	}

	void update() override {
		
		//checks if no player has won then do game logic
		if (winner == 0) {

			//all the player inputs
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

			//updates the collision bounds for all the moving sprites
			ball->UpdateBoundsPosition();
			player1->UpdateBoundsPosition();
			player2->UpdateBoundsPosition();

			//checks if player is over or under the maximum y value it can be and corrects its y value
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

			//if ball hits top or bottom then change direction on the y value
			if (ball->position.y >= 9-ball->GetSize().y) {
				ballDirection->y *= -1;
			}

			if (ball->position.y <= -9) {
				ballDirection->y *= -1;
			}

			//checks if ball hits the players padels then change x direction value
			if (ball->GetBounds().Intersects(player1->GetBounds())) {
				ballDirection->x *= -1;
			}

			if (ball->GetBounds().Intersects(player2->GetBounds())) {
				ballDirection->x *= -1;
			}

			//if ball is to far away on the x value set a player as winner
			if (ball->position.x >= 16) {
				winner = 1;
			}

			if (ball->position.x <= -16 - ball->GetSize().x) {
				winner = 2;
			}

			//update the ball position
			ball->position += *ballDirection;
		}
		else if (winner == 1) {
			//displays player one is winner
			Player1win->position = vec2(-4.5, -2);

			//checks if space is pressed
			if (window->isKeyPressed(GLFW_KEY_SPACE)) {
				// set is so that no one is winner :,(
				winner = 0;
				
				// replases the ball in the center
				ball->position.x = 0 - ball->GetSize().x/2;

				//removes the "player 1 won" sign
				Player1win->position = vec2(-1000, -1000);
				//to be on the safe side removes the "player 2 won sign also"
				Player2win->position = vec2(-1000, -1000);
			}
		}
		else if (winner == 2) {
			//displays player tow is winner
			Player2win->position = vec2(-4.5, -2);

			//checks if space is pressed
			if (window->isKeyPressed(GLFW_KEY_SPACE)) {
				// set is so that no one is winner :,(
				winner = 0;

				// replases the ball in the center
				ball->position.x = 0 - ball->GetSize().x / 2;

				//to be on the safe side removes the "player 1 won sign also"
				Player1win->position = vec2(-1000, -1000);
				//removes the "player 2 won" sign
				Player2win->position = vec2(-1000, -1000);
			}
		}
	}

	void render() override {
		//renders all the layers
		layer->render();
	}
};

//the main function cpp need to start a program
int main() {

	//the game class from above
	Game game;
	//starts the game
	game.start();

	//when everything is done return 0 :)
	return 0;
}