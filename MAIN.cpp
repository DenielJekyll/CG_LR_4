#include "Hook.h"
using namespace std;

GLint Width = 512, Height = 512;
GLubyte ColorR = 0, ColorG = 0, ColorB = 0;
GLubyte PointSize = 5;

enum keys { Empty, KeyR, KeyG, KeyB, KeyW, KeyA, KeyS, KeyD, KeyU,KeyI };


/* ������� ���������� ������ */
struct type_point
{
	GLint x, y;
	type_point(GLint _x, GLint _y) { x = _x; y = _y; }
};
vector <type_point> Points;

/* ������� ������ �� ����� */
void Display(void)
{
	glClearColor(0.5, 0.5, 0.5, 1); glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(ColorR, ColorG, ColorB);
	glPointSize(PointSize);
	glBegin(GL_POINTS);
	for (int i = 0; i<Points.size(); i++)
		glVertex2i(Points[i].x, Points[i].y);
	glEnd();

	glFinish();
}

/* ������� ��������� �������� ���� */
void Reshape(GLint w, GLint h)
{
	Width = w;    Height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* ������� ��������� ��������� �� ���������� */
void Keyboard(unsigned char key, int x, int y)
{
	int i, n = Points.size();

	/* ��������� RGB-��������� ����� ����� */
	if (key == 'r') ColorR += 5;
	if (key == 'g') ColorG += 5;
	if (key == 'b') ColorB += 5;

	/* ��������� XY-�������� ����� */
	if (key == 'w') for (i = 0; i<n; i++) Points[i].y += 5;
	if (key == 's') for (i = 0; i<n; i++) Points[i].y -= 5;
	if (key == 'a') for (i = 0; i<n; i++) Points[i].x -= 5;
	if (key == 'd') for (i = 0; i<n; i++) Points[i].x += 5;

	/* ��������� ������� ����� */
	if (key == 'u') PointSize++;
	if (key == 'i') PointSize--;

	glutPostRedisplay();

	char v[50]; sprintf(v, "������� ���� ���� �����: R=%.3d G=%.3d B=%.3d", ColorR, ColorG, ColorB);
	glutSetWindowTitle(v);
}

/* ������� ��������� ��������� �� ���� */
void Mouse(int button, int state, int x, int y)
{
	/* ������� ���� ������, �� �� �������� */
	if (state != GLUT_DOWN) return;

	/* ����� ����� �� ������ ����� */
	if (button == GLUT_LEFT_BUTTON)
	{
		type_point p(x, Height - y);
		Points.push_back(p);
	}
	/* �������� ��������� ����� �� ������������ ����� */
	if (button == GLUT_MIDDLE_BUTTON)
	{
		Points.pop_back();
	}

	glutPostRedisplay();
}

void Menu(int pos)
{
	int key = (keys)pos;

	switch (key)
	{
		case KeyR: Keyboard('r', 0, 0); break;
		case KeyG: Keyboard('g', 0, 0); break;
		case KeyB: Keyboard('b', 0, 0); break;
		case KeyW: Keyboard('w', 0, 0); break;
		case KeyS: Keyboard('s', 0, 0); break;
		case KeyA: Keyboard('a', 0, 0); break;
		case KeyD: Keyboard('d', 0, 0); break;
		case KeyU: Keyboard('u', 0, 0); break;
		case KeyI: Keyboard('i', 0, 0); break;

		default:
			int menu_color = glutCreateMenu(Menu);
			glutAddMenuEntry("���������� R", KeyR);
			glutAddMenuEntry("���������� G", KeyG);
			glutAddMenuEntry("���������� B", KeyB);

			int menu_move = glutCreateMenu(Menu);
			glutAddMenuEntry("�����",  KeyW);
			glutAddMenuEntry("����",   KeyS);
			glutAddMenuEntry("B����",  KeyA);
			glutAddMenuEntry("������", KeyD);

			int menu_size = glutCreateMenu(Menu);
			glutAddMenuEntry("���������", KeyU);
			glutAddMenuEntry("���������", KeyI);

			int menu = glutCreateMenu(Menu);
			glutAddSubMenu("����� �����", menu_color);
			glutAddSubMenu("�����������", menu_move);
			glutAddSubMenu("��������� ������� �����", menu_size);

			glutAttachMenu(GLUT_RIGHT_BUTTON);
			Keyboard(Empty,0,0);
	}
}


/* �������� ��������� */
void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("������� ���� ���� �����:");
	Menu(Empty);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);

	glutMainLoop();
}
