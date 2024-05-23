#pragma once

class LevelManager;
class ActorWorld;
class Config;
class Screen;

class ILevelBase
{
	friend class LevelManager;

public:
	const char* Name() const;

	ActorWorld* GetWorld() const;

protected:
	const char* m_name;

	LevelManager* m_levelManager;
	ActorWorld* m_world;

protected:
	ILevelBase(const char* _name);
	virtual ~ILevelBase();

protected:
	Config* GetConfig() const;
	Screen* GetScreen() const;

protected:
	virtual void BeginPlay() = 0;

	virtual void Tick(float _dt) = 0;
	virtual void Render() = 0;

	virtual void EndPlay() = 0;

private:
	Config* m_config;
	Screen* m_screen;

};

