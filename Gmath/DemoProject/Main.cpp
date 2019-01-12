#include "raylib.h"
#include "transform2d.h"



int main()
{
	
	
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "DEMO");

	transform2d base;
	base.localPos = { 100, 100 };

	transform2d turret;
	turret.setParent(&base);
	Rectangle baseRec{ base.localPos.xpos, base.localPos.ypos, 100.0f, 150.0f };
	vec2 worldPosT = turret.worldPosition();
	Rectangle turretRec{ worldPosT.xpos, worldPosT.ypos, 50.0f, 75.0f };
	while (!WindowShouldClose())
	{
		BeginDrawing();

		worldPosT = (turret.worldPosition());
		ClearBackground(RAYWHITE);
		if (IsKeyDown(KEY_DOWN))
		{
			base.translate({ 100 * GetFrameTime() , 100 * GetFrameTime() });
		}
		baseRec.x = base.localPos.xpos;
		baseRec.y = base.localPos.ypos;
		turretRec.x = worldPosT.xpos;
		turretRec.y = worldPosT.ypos;


	
		DrawRectanglePro(baseRec, { baseRec.width / 2, baseRec.height / 2 }, base.localRot, BLUE);
		DrawRectanglePro(turretRec, { turretRec.width / 2, turretRec.height / 2 }, turret.localRot, RED);


	

		SetTargetFPS(60);
	

		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}