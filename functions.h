#pragma once

void clearInputBuffer(void);

void suspend();

void printHeader();

void mainMenu();

int inputInt();

int inputIntRange(int, int);

void modeNormal(); 

void modeTroll(); 

void clipboardCopy(const char*); 

void printFooter();