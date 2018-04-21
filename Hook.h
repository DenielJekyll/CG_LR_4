#define _USE_MATH_DEFINES 
#include <cmath>
#include <windows.h>
#include "glut.h"
#include "tracer.h"
#include "helpTracer.h"
#include <vector>
#include <gl\gl.h>
#include <cstdio>

#define kSpeed  0.03f	//скорость перемещения камеры

using namespace std;

GLint width, height;	//ширина и высота окна
GLfloat ratio;			//соотношение ширины и высоты окна

bool rot = false;			//включить вращение камеры с помощью мыши

bool raytracer_mode = false;	//режим трассировки
