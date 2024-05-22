#pragma once

#include <Spark/Actors/Actor.h>

class TestActor final : public Actor
{
protected:
	void OnTick(float _dt) override;
	void OnRender() override;
};