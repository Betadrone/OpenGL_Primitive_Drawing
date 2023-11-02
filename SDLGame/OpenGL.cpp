#include "OpenGL.h"

void OpenGL::ClearScreen()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL::CreateBorder()
{
	CreateDotGL();
	CreateLineGL();
	CreateTriangleGL();
}

void OpenGL::CreateDotGL()
{
	//glEnable(GL_POINT_SMOOTH);
	glPointSize(35.0f);
	glBegin(GL_POINTS);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(-0.9f, 0.7f, 1.0f);

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(-0.9f, -0.7f, 1.0f);

		glColor4f(0.1f, 0.3f, 0.7f, 1.0f);
		glVertex3f(0.9f, 0.7f, 1.0f);
		
		glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
		glVertex3f(0.9f, -0.7f, 1.0f);

		glColor4f(0.7f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-0.7f, 0.9f, 1.0f);

		glColor4f(0.2f, 0.4f, 0.3f, 1.0f);
		glVertex3f(0.7f, 0.9f, 1.0f);

		glColor4f(0.5f, 0.2f, 0.3f, 1.0f);
		glVertex3f(-0.7f, -0.9f, 1.0f);

		glColor4f(0.1f, 0.5f, 0.4f, 1.0f);
		glVertex3f(0.7f, -0.9f, 1.0f);
		
	glEnd();
}

void OpenGL::CreateLineGL()
{
	glLineWidth(10.0f);
	glBegin(GL_LINES);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(-0.9f, 0.7f, 1.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(-0.9f, -0.7f, 1.0f);

		glColor4f(0.1f, 0.3f, 0.7f, 1.0f);
		glVertex3f(0.9f, 0.7f, 1.0f);
		glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
		glVertex3f(0.9f, -0.7f, 1.0f);

		glColor4f(0.7f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-0.7f, 0.9f, 1.0f);
		glColor4f(0.2f, 0.4f, 0.3f, 1.0f);
		glVertex3f(0.7f, 0.9f, 1.0f);

		glColor4f(0.5f, 0.2f, 0.3f, 1.0f);
		glVertex3f(-0.7f, -0.9f, 1.0f);
		glColor4f(0.1f, 0.5f, 0.4f, 1.0f);
		glVertex3f(0.7f, -0.9f, 1.0f);
	glEnd();
}

void OpenGL::CreateTriangleGL()
{
	glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 0.7f, 1.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(-0.7f, 1.0f, 1.0f);

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.7f, 1.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(0.7f, 1.0f, 1.0f);

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -0.7f, 1.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(-0.7f, -1.0f, 1.0f);

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -0.7f, 1.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(0.7f, -1.0f, 1.0f);
	glEnd();
}

void OpenGL::CreateArrayPic()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glColorPointer(4, GL_FLOAT, 0, &colors[0]);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void OpenGL::CreateElementArrayPic()
{
	if (EventHandler::events[UP_PRESSED])	
	{
		for (int i = 0; i < indexLen; i++)
		{
			if ((i + 1) % 3 == 2)
			{
				triVert[i] += 0.001f;
			}
		}
	}
	if (EventHandler::events[DOWN_PRESSED])
	{
		for (int i = 0; i < indexLen; i++)
		{
			if ((i + 1) % 3 == 2)
			{
				triVert[i] -= 0.001f;
			}
		}
	}
	if (EventHandler::events[RIGHT_PRESSED])
	{
		for (int i = 0; i < indexLen; i++)
		{
			if ((i + 1) % 3 == 1)
			{
				triVert[i] += 0.001f;
			}
		}
	}
	if (EventHandler::events[LEFT_PRESSED])
	{
		for (int i = 0; i < indexLen; i++)
		{
			if ((i + 1) % 3 == 1)
			{
				triVert[i] -= 0.001f;
			}
		}
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glColorPointer(4, GL_FLOAT, 0, &colors[0]);
	glVertexPointer(3, GL_FLOAT, 0, &triVert[0]);
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, &vertIndex[0]);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void OpenGL::DrawKirby()
{
	//Kirby Drawing
	// body
	glPointSize(300.0f);
	glBegin(GL_POINTS);
	glColor4f(1.0f, 0.753f, 0.796f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();
	// eyes
	glPointSize(25.0f);
	glBegin(GL_POINTS);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex3f(-0.08f, 0.2f, 1.0f);
	glVertex3f(0.08f, 0.2f, 1.0f);
	glEnd();

	glPointSize(25.0f);
	glBegin(GL_POINTS);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-0.08f, 0.14f, 1.0f);
	glVertex3f(0.08f, 0.14f, 1.0f);
	glEnd();

	glPointSize(25.0f);
	glBegin(GL_POINTS);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(-0.08f, 0.082f, 1.0f);
	glVertex3f(0.08f, 0.082f, 1.0f);
	glEnd();
	// cheeks
	glPointSize(25.0f);
	glBegin(GL_POINTS);
	glColor4f(0.906f, 0.329f, 0.502f, 1.0f);
	glVertex3f(-0.113f, -0.025f, 1.0f);
	glVertex3f(-0.14f, -0.025f, 1.0f);
	glVertex3f(-0.17f, -0.025f, 1.0f);

	glVertex3f(0.113f, -0.025f, 1.0f);
	glVertex3f(0.14f, -0.025f, 1.0f);
	glVertex3f(0.17f, -0.025f, 1.0f);
	glEnd();
	// mouth
	glPointSize(25.0f);
	glBegin(GL_POINTS);
	glColor4f(0.0039f, 0.0431f, 0.0745f, 1.0f);
	glVertex3f(-0.035f, -0.1f, 1.0f);
	glVertex3f(0.0f, -0.1f, 1.0f);
	glVertex3f(0.03f, -0.1f, 1.0f);
	glEnd();

	// Feet
	glPointSize(35.0f);
	glBegin(GL_POINTS);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-0.08f, -0.41f, 1.0f);
	glVertex3f(-0.13f, -0.41f, 1.0f);
	glVertex3f(-0.18f, -0.41f, 1.0f);
	glVertex3f(-0.21f, -0.41f, 1.0f);

	glVertex3f(0.08f, -0.41f, 1.0f);
	glVertex3f(0.13f, -0.41f, 1.0f);
	glVertex3f(0.18f, -0.41f, 1.0f);
	glVertex3f(0.21f, -0.41f, 1.0f);
	glEnd();

	// Arms
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.853f, 0.896f, 1.0f);
	glVertex3f(0.213f, 0.14f, 1.0f);
	glVertex3f(0.3f, -0.10f, 1.0f);
	glVertex3f(0.213f, -0.16f, 1.0f);

	glVertex3f(-0.21f, 0.14f, 1.0f);
	glVertex3f(-0.3f, -0.10f, 1.0f);
	glVertex3f(-0.21f, -0.16f, 1.0f);
	glEnd();
}

