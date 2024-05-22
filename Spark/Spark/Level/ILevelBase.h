#pragma once

class LevelManager;
class ActorWorld;

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
	virtual void BeginPlay() = 0;

	virtual void Tick(float _dt) = 0;
	virtual void Render() = 0;

	virtual void EndPlay() = 0;

};

