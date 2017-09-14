#ifndef PRISONER_H
#define PRISONER_H

#include "Agent.h"
#include "../Pathfinding/astar.h"
#include <cstdlib>

class Prisoner;

//Physic attributes
class PrisonerBody : public AgentBody {
public:
	void update(double accumTime) override;

	int color_[4] = { 0, 0, 0, 200 };
	int size_ = 30;
};


//Psychic attributes. Managers are mind-pure.
class PrisonerMind : public AgentMind {

friend class Prisoner;

public:
	virtual void sense() override;
	virtual void reason() override;
	void update(double accumTime) override;

	bool isAlive();
	bool isActive();

	PrisonerStatus status_;
	double time_end_status_;
	Prisoner* target_;
	Prisoner* owner_;
};


class Prisoner : public Agent {
public:

	Prisoner();
	Prisoner(const Prisoner& orig);
	virtual ~Prisoner();

	void init();
	void update(double accumTime) override;
	void render() override;

	virtual AgentBody* getBody() { return reinterpret_cast<PrisonerBody*>(body_); };
	virtual MOMOS::SpriteHandle getImg() override { return img_; };

	PrisonerMind* mind_;
	PrisonerBody* body_;

	MOMOS::SpriteHandle img_;

	//Crate being carried, if any
	Crate* crate_;

	//Prisoner will rest out of their own working shift
	short working_shift_;
	//The prisoner is moving to a door
	bool door_route_set_ = false;
	int current_target_door_ = 1;
	//The prisoner is moving to the scape base
	bool escape_route_set_ = false;
	float original_speed_;

private:

	
};

#endif /* PRISONER_H */