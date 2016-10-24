//Code first fixed time, and then variable update time

#include <stdio.h>

#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/input.h>
#include <ESAT/time.h>
#include <ESAT/math.h>

//Whether the code runs on fixed time steps or variable time steps 
bool g_IA_fixed_step = true;
//Uses SDL or OS time
bool g_use_SDL_time = true;
int g_framerate = 25;

float g_rads = 0.0f;

void Input() {
  if (ESAT::IsSpecialKeyDown(ESAT::kSpecialKey_Right))
    g_framerate += 1;
  else if (ESAT::IsSpecialKeyDown(ESAT::kSpecialKey_Left))
    g_framerate -= 1;
  else
    return;
  
  printf("Running at %dfps\n", g_framerate);
}

void IA(int accumTime) {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			NULL;
		}
	}
}

void Update(double m_iTimeStep) {
	
	g_rads += 0.001f * m_iTimeStep;

	IA(m_iTimeStep);
}

void Draw() {
	

	ESAT::DrawBegin();
	ESAT::DrawClear(0, 0, 0);

	float pathpoints[] = { -1.0f,-1.0f, 1.0f,-1.0f, 1.0f,1.0f, -1.0f,1.0f, -1.0f,-1.0f };
	float out_points[10];
	ESAT::Mat3 scale = ESAT::Mat3Scale(50.0f, 50.0f);
	ESAT::Mat3 translate = ESAT::Mat3Translate(200.0f, 200.0f);
	ESAT::Mat3 rotate = ESAT::Mat3Rotate(g_rads);
	ESAT::Mat3 transform = ESAT::Mat3Multiply(rotate, scale);
	transform = ESAT::Mat3Multiply(translate, transform);


	for (int i = 0; i < 10; i+=2) {
		ESAT::Vec2 vec_in, vec_out;
		vec_in.x = pathpoints[i];
		vec_in.y = pathpoints[i + 1];

		vec_out = ESAT::Mat3TransformVec2(transform, vec_in);

		out_points[i] = vec_out.x;
		out_points[i+1] = vec_out.y;
	}

	ESAT::DrawSetFillColor(255, 255, 255);
	ESAT::DrawSetStrokeColor(255, 255, 255);
	ESAT::DrawSolidPath(out_points, 5, true);

	ESAT::DrawEnd();
	ESAT::WindowFrame();
        for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			NULL;
		}
	}
}





int ESAT::main(int argc, char **argv) {

	ESAT::WindowInit(800, 600);

	ESAT::WindowSetMouseVisibility(true);

	float m_iTimeStep = 1000.0 / g_framerate;

	float CurrentTime = ESAT::Time();
	int dt = 0;



	while (ESAT::WindowIsOpened()) {
          
                float m_iTimeStep = 1000.0 / g_framerate;
                
		Input();

		//accumTime at this point is nearly zero
		float accumTime = ESAT::Time() - CurrentTime;

		while (accumTime >= m_iTimeStep) {
			Update(m_iTimeStep);
			CurrentTime += m_iTimeStep;
			accumTime = ESAT::Time() - CurrentTime;
		}

		Draw();

	}


	return 0;
}