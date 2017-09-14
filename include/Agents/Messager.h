/*
* A manager to handle messages between agents.
*/
#ifndef MESSAGER_H
#define MESSAGER_H

#include "Agent.h"


//Psychic attributes. Managers are mind-pure.
class MessagerMind : public AgentMind {

	friend class Messager;

public:
	virtual void sense() override;
	virtual void reason() override;
	void update(double accumTime) override;

	void sendMessage(Message m);
	void receiveMessage(Message m);
	void respondMessage(Message m, bool response);

	Agent* target_;
	//Pathfinder* owner_;
};



class Messager : public Agent {
public:
  
  Messager();
  Messager(const Messager& orig);
  virtual ~Messager();

  void update(double accumTime) override;
  
private:

};

#endif /* MANAGER_H */