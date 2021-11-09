#include <iostream>
#include <random>
#include <chrono>
#pragma once

void AI(char ploca[3][3]);

int rng();
bool whoWon(char ploca[3][3], char move);
void clearScreen();
void clearBoard(char ploca[3][3]);
void showBoard(char ploca[3][3]);
