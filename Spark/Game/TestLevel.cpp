#include "TestLevel.h"

#include "LevelNames.h"
#include "TestActor.h"
#include "Spark/Actors/ActorWorld.h"

TestLevel::TestLevel()
	: ILevelBase(TEST_LEVEL)
{
}

void TestLevel::BeginPlay()
{
	if (ActorWorld* world = GetWorld())
	{
		world->SpawnWithTransform(
			new TestActor,
			Vec2
			{
				static_cast<float>(GetScreenWidth()) * .5f,
				static_cast<float>(GetScreenHeight()) * .5f,
			},
			0,
			Vec2::one * 50.f
			);
	}
}

void TestLevel::Tick(float _dt)
{
}

void TestLevel::Render()
{
}

void TestLevel::EndPlay()
{
}
