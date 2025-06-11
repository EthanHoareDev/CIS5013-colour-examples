#include "core.h"
#include "MyShapes.h"

void DrawAdditiveRectangles()
{
	// Enable blending and set the blend function to additive
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);  // Additive blending

	// Optional: set smooth shading for better interpolation
	glShadeModel(GL_SMOOTH);

	// First rectangle: Blue
	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2f(250.0f, 300.0f);
	glVertex2f(450.0f, 300.0f);
	glVertex2f(450.0f, 500.0f);
	glVertex2f(250.0f, 500.0f);
	glEnd();

	// Second rectangle: Green, slightly offset to overlap
	glColor3ub(0, 255, 0);
	glBegin(GL_QUADS);
	glVertex2f(400.0f, 300.0f);
	glVertex2f(600.0f, 300.0f);
	glVertex2f(600.0f, 500.0f);
	glVertex2f(400.0f, 500.0f);
	glEnd();

	// Third rectangle: Red, overlapping both
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(325.0f, 450.0f);
	glVertex2f(525.0f, 450.0f);
	glVertex2f(525.0f, 650.0f);
	glVertex2f(325.0f, 650.0f);
	glEnd();

	glDisable(GL_BLEND); // Clean up after
}


void DrawThreeRec(float _X, float _Y, float _width, float _height)
{
	glBegin(GL_QUADS);

	glVertex2d(_X, _Y);
	glVertex2d(_X + _width, _Y);
	glVertex2d(_X + _width, _Y + _height);
	glVertex2d(_X, _Y + _height);


	glEnd();






}
void drawShadedTriangle() {

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(450.0, 450.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(500.0f, 550.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(550.0f, 450.0f);

	glEnd();
}

void drawStarOutline() {

	glBegin(GL_LINE_LOOP);

	glColor3ub(255, 255, 255);
	glVertex2f(0.0, 0.25f);

	glColor3ub(255, 255, 0);
	glVertex2f(0.1f, 0.1f);

	glColor3ub(255, 0, 255);
	glVertex2f(0.25f, 0.08f);

	glColor3ub(255, 0, 0);
	glVertex2f(0.15f, -0.05f);

	glColor3ub(0, 255, 255);
	glVertex2f(0.25f, -0.25f);

	glColor3ub(0, 255, 255);
	glVertex2f(0.0f, -0.125f);

	glColor3ub(231, 170, 25);
	glVertex2f(-0.25f, -0.25f);

	glColor3ub(128, 200, 0);
	glVertex2f(-0.15f, -0.05f);

	glColor3ub(0, 255, 255);
	glVertex2f(-0.25f, 0.08f);

	glColor3ub(200, 90, 221);
	glVertex2f(-0.1f, 0.1f);

	glEnd();
}

void drawStarShaded() {

	glBegin(GL_TRIANGLE_FAN);

	glColor3ub(255, 255, 0);
	glVertex2f(0.0f, 0.0f); // Centre vertex

	glColor3ub(0, 0, 0);
	glVertex2f(0.0, 0.25f); // First boundary vertex
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.25f, 0.08f);
	glVertex2f(0.15f, -0.05f);
	glVertex2f(0.25f, -0.25f);
	glVertex2f(0.0f, -0.125f);
	glVertex2f(-0.25f, -0.25f);
	glVertex2f(-0.15f, -0.05f);
	glVertex2f(-0.25f, 0.08f);
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(0.0, 0.25f); // Repeat of first boundary vertex to close the loop

	glEnd();
}

void drawTank() {

	// Render body
	glBegin(GL_LINE_LOOP);

	glColor3ub(0, 255, 0); // just set colour once as all vertices will keep this unless changed
	glVertex2f(-0.75f, 0.4f);
	glVertex2f(0.75f, 0.4f);
	glVertex2f(0.75f, -0.4f);
	glVertex2f(-0.75f, -0.4f);

	glEnd();

	// Render gun
	glBegin(GL_LINE_LOOP);

	glColor3ub(255, 0, 0); // just set colour once as all vertices will keep this unless changed
	glVertex2f(-0.5f, 0.3f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(-0.5f, -0.3f);

	glEnd();
}


// Draw a semi-circle with smooth shading, with red vertices on the inner edge and yellow vertices on the outer edge.
void drawSemiCircleStudio() {

	glShadeModel(GL_SMOOTH);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.25f, 0.0f);

	glColor3ub(255, 255, 0);
	glVertex2f(-0.75f, 0.0f);

	glColor3ub(0, 255, 0);
	glVertex2f(-0.216506351f, 0.125f);

	glColor3ub(0, 0, 255);
	glVertex2f(-0.649519053f, 0.375f);

	glColor3ub(0, 150, 255);
	glVertex2f(-0.125, 0.216506351f);

	glColor3ub(139, 0, 255);
	glVertex2f(-0.375f, 0.649519053f);

	glColor3ub(139, 0, 255);
	glVertex2f(0.0f, 0.25f);

	glColor3ub(0, 150, 255);
	glVertex2f(0.0f, 0.75f);

	glColor3ub(0, 0, 255);
	glVertex2f(0.125f, 0.216506351f);

	glColor3ub(0, 255, 0);
	glVertex2f(0.375f, 0.649519053f);

	glColor3ub(255, 255, 0);
	glVertex2f(0.216506351f, 0.125f);

	glColor3ub(255, 0, 0);
	glVertex2f(0.649519053f, 0.375f);

	glColor3ub(255, 0, 0);
	glVertex2f(0.25f, 0.0f);

	glColor3ub(255, 255, 0);
	glVertex2f(0.75f, 0.0f);

	glEnd();
}