#include "Application.h"



const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application()
	: gWindow(sf::VideoMode(640, 480), "SFML Application")
	, gPlayer1(sf::Vector2f(10, 20), sf::Vector2f(600.f, 0.f))
	, gPlayer2(sf::Vector2f(10, 440), sf::Vector2f(600.f, 0.f))
	, gBall(sf::Vector2f(320, 240), sf::Vector2f(250, -250))
	, autoPlayEnabled(false)
	//add background
{
	srand(time(NULL));
	int randNum1 = rand() % (2 - -1 + 1) + -1;
	int randNum2 = rand() % (2 - -1 + 1) + -1;
	if (randNum1 == 0) randNum1 = -1;
	if (randNum1 == 2) randNum1 = 1;
	if (randNum2 == 0) randNum2 = -1;
	if (randNum2 == 2) randNum2 = 1;
	gBall.velocity = sf::Vector2f(250 * randNum1, 250 * randNum2);//randomize starting velocity
	gWindow.setKeyRepeatEnabled(true);
	gWindow.setVerticalSyncEnabled(true);
}

void Application::run()//start the application and main game loop
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (gWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)//set FPS
		{
			timeSinceLastUpdate -= TimePerFrame;
			processInput();
			update(TimePerFrame);
		}

		render();
	}
}


void Application::processInput()//handle and get input in realtime from user
{
	sf::Event event;

	while (gWindow.pollEvent(event))
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
				gBall.isMoving = true;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
				autoPlayEnabled = true;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
				autoPlayEnabled = false;

			gPlayer1.handleRealTimeInput(sf::Keyboard::Key::A, sf::Keyboard::Key::D);
			gPlayer2.handleRealTimeInput(sf::Keyboard::Key::Left, sf::Keyboard::Key::Right);
			break;
		case sf::Event::KeyReleased:
			gPlayer1.handleRealTimeInput(sf::Keyboard::Key::A, sf::Keyboard::Key::D);
			gPlayer2.handleRealTimeInput(sf::Keyboard::Key::Left, sf::Keyboard::Key::Right);
			break;
		case sf::Event::Closed:
			gWindow.close();
		}
}


void Application::update(const sf::Time& dt)//update current position of every object and its state
{
	if (gBall.avatar.getPosition().y < 10)
	{
		std::cout << "player 1 LOSE";
		_getch();
		exit(0);
	}
	if (gBall.avatar.getPosition().y > 470.0)
	{
		std::cout << "player 2 LOSE";
		_getch();
		exit(0);
	}

	gPlayer1.update(dt);
	gPlayer2.update(dt);


	gBall.update(dt);

	if (autoPlayEnabled)
		autoPlay();


	if (gBall.collisionDetection(gPlayer1) || gBall.collisionDetection(gPlayer2))
	{
		gBall.bouncePaddle();
		gBall.accelerate();
		//paddle accelerate(for high speed gaming) NEEDED
		gPlayer1.velocity.x *= 1.03f;
		gPlayer2.velocity.x *= 1.03f;
	}

}


void Application::render()// draw the play screen
{
	gWindow.clear();

	gWindow.draw(gPlayer1);
	gWindow.draw(gPlayer2);
	gWindow.draw(gBall);

	gWindow.display();
}

void Application::autoPlay()//autoplay mode
{
	gPlayer1.avatar.setPosition(gBall.avatar.getPosition().x - 50, gPlayer1.avatar.getPosition().y);
	gPlayer2.avatar.setPosition(gBall.avatar.getPosition().x - 50, gPlayer2.avatar.getPosition().y);
}