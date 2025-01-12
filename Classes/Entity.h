#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"
#include "Box2D.h"
#include <list>

USING_NS_CC;

class Entity
{
public:
	Entity(b2World* world, b2Body* body);
	virtual ~Entity();
	static Entity* makePlanet(b2World* world, float density, Vec2 pos, Sprite* sprite);
	static Entity* makeStar(b2World* world, float density, Vec2 pos, Sprite* sprite);
	void applyForce(Vec2 force);
	void applyImpulse(Vec2 impulse);
	Sprite* getSprite();
	Sprite* updateSprite();
	float getMass();
	Vec2 getPos();
	Vec2 getVel();
	bool castRay(b2RayCastOutput* output, const b2RayCastInput& input);
protected:
	b2Body* body;
private:
	b2World* world;
};

#endif
