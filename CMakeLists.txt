cmake_minimum_required(VERSION 3.24)
project(GoFishWithPhilosophers2)

set(CMAKE_CXX_STANDARD 17)

add_executable(GoFishWithPhilosophers2 main.cpp Card.cpp Card.h Deck.cpp Deck.h RandomNumberGenerator.cpp RandomNumberGenerator.h Player.cpp Player.h Game.cpp Game.h FullyMultiplayerGame.cpp FullyMultiplayerGame.h SingleplayerGame.cpp SingleplayerGame.h)
