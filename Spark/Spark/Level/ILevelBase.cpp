#include "ILevelBase.h"

#include "Spark/Actors/Actor.h"
#include "Spark/Actors/ActorWorld.h"
#include "Spark/Utility/Config.h"

const char* ILevelBase::Name() const
{
	return m_name;
}

ActorWorld* ILevelBase::GetWorld() const
{
	return m_world;
}

ILevelBase::ILevelBase(const char* _name)
	: m_name{ _name }, m_levelManager{ nullptr }, m_world{ new ActorWorld }, m_config{ nullptr }, m_screen{ nullptr },
	m_isConfigured{ false }
{
	
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

void ILevelBase::Configure(Config* _config, Screen* _screen)
{
	if (m_isConfigured)
		return;

	m_config = _config;
	m_screen = _screen;

	const Vec2 worldOffset = m_config->GetValue<Vec2>("world", "offset");

	const Vec2 pos = Vec2
	{
		static_cast<float>(GetScreenWidth()) * worldOffset.x,
		static_cast<float>(GetScreenHeight()) * worldOffset.y,
	};

	const Vec2 scale = Vec2::one * m_config->GetValue<float>("world", "scale");

	m_world->m_config = _config;
	m_world->m_screen = _screen;
	m_world->m_root->UpdateActorTransform(Mat3::CreateTransform(pos, 0, &scale));

	m_isConfigured = true;
}
