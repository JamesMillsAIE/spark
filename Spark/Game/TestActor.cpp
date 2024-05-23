#include "TestActor.h"

#include "Spark/Utility/Config.h"

TestActor::TestActor()
	:m_speed{ 0 }
{
}

void TestActor::OnBeginPlay()
{
	if(Config* config = GetConfig())
	{
		m_speed = config->GetValue<float>("player", "speed");
	}
}

void TestActor::OnTick(float _dt)
{
	const Vec2 modification =
	{
		static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
		static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W))
	};

	UpdateActorTransform(
		Mat3::CreateTranslation(modification * _dt * m_speed)
	);
}

void TestActor::OnRender()
{
	DrawCircleV(GetActorPosition(), GetActorScale().Magnitude(), RED);
}
