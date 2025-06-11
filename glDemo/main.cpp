
#include "core.h"
#include "MyShapes.h"

using namespace std;


// global variables
mt19937 engine;
uniform_real_distribution<float> range;
vector<float>xValues;
vector<float>yValues;



// Window size
const unsigned int initWidth = 512;
const unsigned int initHeight = 512;

// Example variables to change when doing keyboard input

// the position of our object
float x = 0.0f;
float y = 0.0f;

// amount we change x, y when keys are pressed
const float movementSpeed = 0.005f;

// flags to track when a movement key is pressed
bool wPressed = false;
bool sPressed = false;
bool aPressed = false;
bool dPressed = false;


// Function prototypes
void renderScene();

// Rendering function prototypes
void drawShadedTriangle();
void drawStarOutline();
void drawStarShaded();
void drawTank();
void drawSemiCircleStudio();
void DrawAdditiveRectangles();
void DrawThreeRec(float _X, float _Y, float _width, float _height);


void resizeWindow(GLFWwindow* window, int width, int height);
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateScene();



int main() {

	//
	// 1. Initialisation
	//
	

	// Initialise glfw and setup window
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);

	GLFWwindow* window = glfwCreateWindow(initWidth, initHeight, "Real-Time Computer Graphics", NULL, NULL);

	// Check window was created successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	

	// Set callback functions to handle different events
	glfwSetFramebufferSizeCallback(window, resizeWindow); // resize window callback
	glfwSetKeyCallback(window, keyboardHandler); // Keyboard input callback


	// Initialise glew
	glewInit();

	
	// Setup window's initial size
	resizeWindow(window, initWidth, initHeight);

	// Initialise scene - geometry and shaders etc
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // setup background colour to be black

	// *** setup viewplane to the appropriate size
	gluOrtho2D(0, 1000, 0, 1000);

	random_device rd;
	engine = mt19937(rd());
	range = uniform_real_distribution<float>(0.0f, 1000.0f);

	xValues = vector<float>(100, 0.0f);
	yValues = vector<float>(100, 0.0f);

	for (int i = 0; i < 100; i++)
	{
		float x = range(engine);
		float y = range(engine);

		xValues[i] = x;
		yValues[i] = y;


	}

	//
	// 2. Main loop
	// 
	
	// Loop while program is not terminated.
	while (!glfwWindowShouldClose(window)) {

		updateScene();
		renderScene();						// Render into the current buffer
		glfwSwapBuffers(window);			// Displays what was just rendered (using double buffering).

		// Poll events (key presses, mouse events)
		// glfwWaitEvents();				// Use this if no animation.
		// glfwWaitEventsTimeout(1.0/60.0);	// Use this to animate at 60 frames/sec (timing is NOT reliable)
		glfwPollEvents();					// Use this version when animating as fast as possible
	}

	glfwTerminate();
	return 0;
}




// renderScene - function to render the current scene


void renderScene()
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPointSize(5.0f);
	glColor3ub(0, 180, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 100; i++)
	{

		glVertex2f(xValues[i], yValues[i]);

		//float x = range(engine);
		//float y = range(engine);

		//glVertex2f(x, y);


	}
	glEnd();



	// Render objects here...
	//drawShadedTriangle();
	//drawStarOutline();
	//drawStarShaded();
	//drawTank();
	//drawSemiCircleStudio();
	//DrawAdditiveRectangles();





}

// Rendering functions




// Draw a semi-circle with smooth shading, with red vertices on the inner edge and yellow vertices on the outer edge.



// Function to call when window resized
void resizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);		// Draw into entire window
}

// Function to call to handle keyboard input
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {

		// check which key was pressed...
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;

			default:
			{
			}
		}
	}
	else if (action == GLFW_RELEASE) {
		// handle key release events
	}
}


// Function called to animate elements in the scene
void updateScene() {
}

