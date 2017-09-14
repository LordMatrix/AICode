#include "../../include/Agents/Messager.h"

Messager::Messager() : Agent() {

  this->body_ = nullptr;
}

Messager::Messager(const Messager& orig) {
}

Messager::~Messager() {
}

void Messager::update(double accumTime) {
	if (true) {
		mind_->update(accumTime);
	}
}

void MessagerMind::sense() {
}

void MessagerMind::reason() {
  //Process message queue
  while (messages_.size() > 0) {
    Message m = messages_.back();
   // switch (m.type) {
     // default:
       //   break;
    //}
    
    messages_.pop_back();
  }
}


void MessagerMind::sendMessage(Message m) {
  //m.receiver->receiveMessage(m);
}

void MessagerMind::receiveMessage(Message m) {
  messages_.push_back(m);
}

void MessagerMind::respondMessage(Message m, bool response) {
 // m.res = (response) ? YES : NO;
  sendMessage(m);
}