#pragma once

extern bool restart;

bool ValidNumber(const std::string& inputString, const int min, const int max);
bool YesNoQuestion(const std::string& question);
void ResetGame();
void DisplayUI();

