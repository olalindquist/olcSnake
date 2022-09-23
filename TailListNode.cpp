#include "TailListNode.h"


TailListNode::TailListNode(std::shared_ptr<TailPiece> tailPiece){
  this ->tailPiece = tailPiece;
  this ->next = nullptr;
  this->hasNextNode = false;
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
