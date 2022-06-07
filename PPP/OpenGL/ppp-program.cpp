using namespace std;
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>

GLint Width = 1080, Height = 1080; //начальные размеры окна

//Функция вырисовки на экране
void Display()
{
	glClearColor(1, 1, 1, 1); // цвет окна 
	glClear(GL_COLOR_BUFFER_BIT); //очистка буфера цвета и буфера глубины 
	glLineWidth(1); // ширина линий кооринатных осей
	glColor3f(0, 0, 0); // цвет координатных осей (черный)
	glBegin(GL_LINES); // ось ОХ, ось OY
	glVertex2f(-50, 0); //Отрисовка осей координат в разные стороны ↓
	glVertex2f(50, 0);
	glVertex2f(0, 50);
	glVertex2f(0, -50);
	glEnd();

	// построение графиков 
	glLineWidth(2);
	glColor3f(1, 0, 0); // цвет графика 1-й функции (красный)
	glBegin(GL_LINE_STRIP); // график 1-й функции
	for (double x = -255; x < -3; x += 0.1) { //промежуток нахождения решения 
		double y = (exp(x + 3)) / (x + 3);
		glVertex2d(x, y);
	}
	for (double x = -3; x < 255; x += 0.1) { //промежуток нахождения решения 
		double y = (exp(x + 3)) / (x + 3);
		glVertex2d(x, y);
	}
	glEnd();
	glBegin(GL_LINE_STRIP); // график 2-й функции
	glColor3f(0, 0, 1); // цвет графика 2-й функции (синий)
	for (double x = -1000; x <= 1000; x += 0.1) { //промежуток нахождения решения 
		double y = cbrtf((x - 1) * (x * x - 2 * x - 2)) + 1;
		glVertex2d(x, y);
	}
	glEnd();
	glFinish();
}

//Функция вызывается при изменении размеров окна
void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;

	// устанавливаем размеры области отображения
	glViewport(0, 0, w, h);

	// отрографическая проекция
	glMatrixMode(GL_PROJECTION); //указание с какой матрицей будем работать, gl_projection - значение по умолчанию, говорит о том, что все последующие команды относятся к проекту
	glLoadIdentity(); // считывает текущую матрицу
	glOrtho(-20, 10, -20, 20, -10, 10); //glOrtho описывает преобразование, которое производит параллельную проекцию. Текущая матрица (см. glMatrixMode) умножается на эту матрицу, и результат заменяет текущую матрицу.
	glMatrixMode(GL_MODELVIEW); //говорит о том, что работы будет теперь просмотром, а не проектом.
	glLoadIdentity(); // считывает текущую матрицу
}

// Функция обработки сообщений с клавиатуры
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'
	if (key == ESCAPE)
		exit(0);
}


// Главный цикл приложения
int main(int argc, char* argv[])
{
	float yi = 0;
	float xi = 0;
	for (float x = -4; x <= -3.0; x += 0.001)
	{
		float y1 = floor((cbrtf((x - 1) * (x * x - 2 * x - 2)) + 1) * 100) / 100;

		float y2 = floor(((exp(x + 3)) / (x + 3)) * 100) / 100;
		if (y1 == y2)
		{

			cout << "Intersection point: " << floor(x * 100) / 100 << " " << y1;
		}

	}


	glutInit(&argc, argv); //Инициализация окна приложения
	glutInitDisplayMode(GLUT_RGB);//Определения режима отображения
	glutInitWindowSize(Width, Height);//Размер окна
	glutCreateWindow("Графики функций");//Название окна
	glutDisplayFunc(Display);//Отрисовка окна
	glutReshapeFunc(Reshape);//Изменения размера под указанное
	glutKeyboardFunc(Keyboard); //Инициализация выхода с помощью "escape"
	glutMainLoop();//Запуск программы

}