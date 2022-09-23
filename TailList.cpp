#include "TailList.h"

int32_t TailList::size;
TailList::TailList(){
  TailList::size = 0;
}

int32_t size() {
  return TailList::size;
}

void TailList::addTailPieceToList(std::shared_ptr<TailPiece> newPiece){


  std::shared_ptr<TailListNode> newNode = std::make_shared<TailListNode>(newPiece);

  if (TailList::size == 0){
    this->firstNode = newNode;
    this->lastNode = this->firstNode;
    TailList::size +=1;
    return;
  }

  if (TailList::size > 0){
    this->lastNode->setNext(newNode);
    this->lastNode = this->lastNode->getNext();
    TailList::size+=1;
  }
}
