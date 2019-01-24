#include "raylib.h"
#include "transform2d.h"



int main()
{
	
	
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "DEMO");
	SetTargetFPS(60);

	transform2d base;
	base.localPos = { 100, 100 };

	transform2d turret;
	turret.setParent(&base);

	Rectangle baseRec{ base.localPos.xpos, base.localPos.ypos, 100.0f, 150.0f };
	vec2 worldPosT = turret.worldPosition();
	Rectangle turretRec{ worldPosT.xpos, worldPosT.ypos, 50.0f, 75.0f };
	vec2 scale = base.worldScale();

	baseRec.height = baseRec.height * scale.xpos;
	float oHeight = baseRec.height;
	while (!WindowShouldClose())
	{
		BeginDrawing();

		baseRec.x = base.localPos.xpos;
		baseRec.y = base.localPos.ypos;
		turretRec.x = worldPosT.xpos;
		turretRec.y = worldPosT.ypos;
		worldPosT = (turret.worldPosition());

		ClearBackground(RAYWHITE);
		if (IsKeyDown(KEY_DOWN))
		{
			base.translate({ 100 * GetFrameTime() , 100 * GetFrameTime() });
		}
		
		if (IsKeyDown(KEY_RIGHT))
		{
			base.rotate(10);
			turret.localRot = base.localRot;
		}

		if (IsKeyDown(KEY_LEFT))
		{
			turret.rotate(10);
		}

		if (IsKeyPressed(KEY_E))
		{
			scale.xpos += 1;
			baseRec.height = oHeight * scale.xpos;
			std::cout << scale.xpos << std::endl;
		}
		if (IsKeyPressed(KEY_R))
		{
			scale.xpos -= 1;
			baseRec.height = oHeight *scale.xpos;
			std::cout << scale.xpos << std::endl;
		}	
		DrawRectanglePro(baseRec, { baseRec.width / 2, baseRec.height / 2 }, base.localRot, DARKPURPLE);
		DrawRectanglePro(turretRec, { turretRec.width / 2, turretRec.height / 2 }, turret.localRot, GOLD);


	

	

		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}