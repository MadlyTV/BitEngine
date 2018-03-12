# Getting started

In the exampel folder you can se a game.cpp file remove it or just exculde it from the project if you whould like to look thrue it later

Create a new file called ```game.cpp``` in in the exampel folder or a new new folder of youre choosing. Dont forget to open up that file

Now on the top of that file you need to include the BitEngine.h do that with the following line of code

```
#include <BitEngine.h>
```

Now that you have included the BitEngine.h file you have access to the whole game engien.

After this you need to make a new class that inherets from BitEngine inside your game.cpp file

```
class Game : public BitEngine {
	
	Game()
	{
	
	}
	
	~Game()
	{
		
	}
	
	void init() override 
	{
	
	}
	
	void render() override 
	{
	
	}
}
```

Theas 4 functions are manditory that you include in youre class and a short explanation for these functions are
* ```BitEngine()``` is a standard constructor for your game class
* ```~Game()``` is a standard destructor for youre game class, you include it because you need somewhere to delete some resourses in the future
* ```init()``` Runs one in the begining of youre game, you are going to use it to initialise resourses for your game
* ```render()``` Runs as fast as possible and is used for rendering of your sprites

There are 2 more funtions you can add if you need them but thay are not madetory 

```
void tick() override 
{

}
```
adn
```
void update() override 
{

}
```

* ```tick()``` runs once per second
and
* ```update()``` runs 60 times per second and is used for game logic

Outside of youre newly created game class you need to create the standard cpp main function and initialise youre newly created class like so

```
int main()
{
	Game game;
	game.start();
	
	return 0;
}
```

The ```game.start()``` function is from BitEngine that starts all the nesasary functions to run the game

Now that we have done all that we can start to create a window for youre game to run on

Start by creating a Window varibal over youre class constructor like so

```
class Game : public BitEngine {	
private:
	Window* window;
	
	Game()
	{
	
	}
}
```

Okay you have created the varibal but you havent assigned anything to it lets do that by runnig a function from BitEngine like so

```
void init() override 
{
		window = createWindow(NAME, WIDTH, HEIGHT);
}
```

A thing to note about this window is that in norman cases you whould have to delete is in when the aplication is closing but BitEngine is doing that automaticly when the aplication is closing

Okay you need to replace the NAME, WIDTH and HEIGHT arguments with real numbers and text so here is a short explanation about the arguments

* NAME = The name of the window (char)
* WIDTH = The width of the window (int)
* HEIGHT = the height of the window (int)

Now this is the end of the getting started code you have everything you need to create a game file and a window.