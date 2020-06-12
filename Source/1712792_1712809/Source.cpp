#include "Application.h"

using namespace std;


int main()
{
	cout << "press ENTER to enable auto-mode \n";
	cout << "press RIGHT SHIFT to disable auto-mode \n";
	cout << "press SPACE to start game \n";
	cout << "press A/D to move player 1 paddle \n";
	cout << "press LEFT/RIGHT ARROW to move player 2 paddle \n";

	Application game;
	game.run();
	return 0;
}