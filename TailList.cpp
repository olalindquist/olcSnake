#include "TailList.h"
#include <iostream>

int32_t TailList::size;

int32_t size() {
  return TailList::size;
}

TailList::TailList(){
  TailList::size = 0;
  this->firstNode = std::make_shared<TailListNode>();
  this->lastNode = std::make_shared<TailListNode>();
  this->priorNode = std::make_shared<TailListNode>();
}

void TailList::addTailPieceToList(std::shared_ptr<TailPiece> newPiece){
  std::shared_ptr<TailListNode> newNode = std::make_shared<TailListNode>(newPiece);

  if (TailList::size == 0){
        std::cout <<"ListSize is 0 according to TailList"  << "\n";
    this->firstNode = newNode;
    this->lastNode = this->firstNode;
    TailList::size +=1;
    return;

  }

  if (TailList::size > 0){
        std::cout <<"ListSize is 1 or higher according to TailList"  << "\n";
    this->priorNode = this->lastNode;
    this->lastNode->setNext(newNode);
    this->lastNode = this->lastNode->getNext();
    TailList::size+=1;
  }

}

std::shared_ptr<TailListNode> TailList::getFirst(){
  return this->firstNode;
}

std::shared_ptr<TailListNode> TailList::getLast(){
  return this->lastNode;
}

std::shared_ptr<TailListNode> TailList::getPriorNode(){
  return this->firstNode;
}
