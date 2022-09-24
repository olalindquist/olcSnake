#include "TailListNode.h"

TailListNode::TailListNode (){
  this ->tailPiece = nullptr;
  this->hasNextNode = false;
  this ->next = nullptr;
}

TailListNode::TailListNode(std::shared_ptr<TailPiece> tailPiece){
  this ->tailPiece = tailPiece;
  this ->next = nullptr;
  this->hasNextNode = false;
}

std::shared_ptr<TailPiece> TailListNode::getTailPiece(){
  return this-> tailPiece;

}
void TailListNode::setNext(std::shared_ptr<TailListNode> nextNode){
    this->next = nextNode;
    this->hasNextNode = true;
  }

std::shared_ptr<TailListNode> TailListNode::getNext(){
  if (this->hasNextNode)   {
    return this->next;
  }
  return nullptr;
  }

bool TailListNode::hasNext(){
    return this->hasNextNode;
}
void TailListNode::draw(olc::PixelGameEngine* engine){
  this->tailPiece->draw(engine);
}
void TailListNode::move(float newXpos, float newYPos){
  this->tailPiece->move (newXpos,newYPos);
}
