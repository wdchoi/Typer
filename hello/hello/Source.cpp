#include <GLFW/glfw3.h>

const int width = 640;
const int height = 480;

//color = (Red, Green, Blue)
float *pixels = new float [width * height * 3];
//float *pixels = (float*)malloc(sizeof(float)*width*height * 3);
void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
		
	}
}
void drawLine2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(j, i, red, green, blue);

	}
}


void draw() {

	int i_center = 20, j_center = 400;
	const int thinkness1 = 10;
	const int thinkness2 = 10;
	for (int k = 0; k < 5; k++) {
		i_center = i_center + 10;
		j_center = j_center + 10;
		for (int j = j_center - thinkness1; j < j_center + thinkness1; j++)
			for (int i = i_center - thinkness2; i < i_center + thinkness2; i++) {
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			}
	}
	drawLine(100, 400, 200, 400, 0.0f, 0.0f, 1.0f);
	drawLine(100, 300, 200, 300, 0.0f, 0.0f, 1.0f);
	drawLine2(300, 100, 400, 100, 0.0f, 0.0f, 1.0f);
	drawLine2(300, 200, 400, 200, 0.0f, 0.0f, 1.0f);



	drawLine(100, 100, 200, 200, 0.0f, 0.0f, 1.0f);
	drawLine(200, 200, 300, 100, 0.0f, 0.0f, 1.0f);
	drawLine(100, 100, 300, 100, 0.0f, 0.0f, 1.0f);
	
	drawLine(300, 320, 350, 350, 0.0f, 0.0f, 1.0f);
	drawLine(350, 350, 400, 320, 0.0f, 0.0f, 1.0f);
	drawLine(300, 320, 320, 260, 0.0f, 0.0f, 1.0f);
	drawLine(320, 260, 380, 260, 0.0f, 0.0f, 1.0f);
	drawLine(380, 260, 400, 320, 0.0f, 0.0f, 1.0f);
}


void drawSQ() {

	const int i_center = 400, j_center = 400;
	const int thinkness = 40;
	
	for (int k = 0; k < 5; k++) {
		
		for (int j = j_center - thinkness; j < j_center + thinkness; j++)
			for (int i = i_center - thinkness; i < i_center + thinkness; i++) {
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			}
	}
	
}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);


		//assign all pixels red color 
		for (int j= 0; j < height; j++)
			for (int i = 0; i < width; i++) {
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}
		draw();
		drawSQ();
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels;
	//free(pixels);
	return 0;
}