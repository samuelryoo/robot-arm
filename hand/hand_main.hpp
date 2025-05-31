#ifndef _HAND_MAIN_HPP
#define _HAND_MAIN_HPP

#include <stdlib.h>

#define RPS_INPUT 2

void setup();

// Hand movement positions
void open_thumb();
void open_fingers();
void close_thumb();
void close_fingers();

extern int thumbPos;
extern int fingersPos;

void rock();
void paper();
void scissors();

void rps();


void loop();

#endif /* _MAIN_HPP */
