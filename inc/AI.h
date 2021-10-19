#include <iostream>
#include <random>
#include <chrono>
#pragma once

void AI(char ploca[3][3]);

int rng();
bool hasWon(char ploca[3][3]);
bool AIWon(char ploca[3][3]);
void clearScreen();
void clearBoard(char ploca[3][3]);
void showBoard(char ploca[3][3]);
