#define _USE_MATH_DEFINES 
#include <cmath>
#include <windows.h>
#include "glut.h"
#include "tracer.h"
#include "helpTracer.h"
#include <vector>
#include <gl\gl.h>
#include <cstdio>

#define kSpeed  0.03f	//�������� ����������� ������

using namespace std;

GLint width, height;	//������ � ������ ����
GLfloat ratio;			//����������� ������ � ������ ����

bool rot = false;			//�������� �������� ������ � ������� ����

bool raytracer_mode = false;	//����� �����������
