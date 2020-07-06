#pragma once

#include "GameLevel.h"

#include "PowerUp.h"

#include <vector>

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

typedef std::tuple<bool, Direction, glm::vec2> Collision;

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);

// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;

class Game
{
public:
	// game state
	GameState    State;
	bool         Keys[1024];
	bool		 KeysProcessed[1024];
	unsigned int Width, Height;

	unsigned int Lives = 3;

	std::vector<GameLevel> Levels;
	std::vector<PowerUp> PowerUps;
	unsigned int Level;

	// constructor/destructor
	Game(unsigned int width, unsigned int height);
	~Game();
	// initialize game state (load all shaders/textures/levels)
	void Init();

	void ResetLevel();
	void ResetPlayer();

	void SpawnPowerUps(GameObject &block);
	void UpdatePowerUps(float dt);

	// game loop
	void ProcessInput(float dt);
	void Update(float dt);
	void Render();

	// collisions in update
	void DoCollisions();
};
