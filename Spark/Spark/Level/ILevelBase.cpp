#include "ILevelBase.h"

#include "Spark/Actors/Actor.h"
#include "Spark/Actors/ActorWorld.h"

const char* ILevelBase::Name() const
{
	return m_name;
}

ActorWorld* ILevelBase::GetWorld() const
{
	return m_world;
}

ILevelBase::ILevelBase(const char* _name)
	: m_name{ _name }, m_levelManager{ nullptr }, m_world{ new ActorWorld }, m_config{ nullptr }, m_screen{ nullptr }
{
	const Vec2 pos = Vec2
	{
		static_cast<float>(GetScreenWidth()) * .5f,
		static_cast<float>(GetScreenHeight()) * .5f,
	};

	const Vec2 scale = Vec2::one * 16.f;

	m_world->m_root->UpdateActorTransform(Mat3::CreateTransform(pos, 0, &scale));
}

ILevelBase::~ILevelBase()
{
	m_name = nullptr;
	m_levelManager = nullptr;

	delete m_world;
	m_world = nullptr;
}

Config* ILevelBase::GetConfig() const
{
	return m_config;
}

Screen* ILevelBase::GetScreen() const
{
	return m_screen;
}
