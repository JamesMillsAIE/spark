#include "TestActor.h"

void TestActor::OnTick(float _dt)
{
	const Vec2 modification =
	{
		static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
		static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W))
	};

	UpdateActorTransform(
		Mat3::CreateTranslation(modification * _dt)
	);
}

void TestActor::OnRender()
{
	DrawCircleV(GetActorPosition(), GetActorScale().Magnitude(), RED);
}
