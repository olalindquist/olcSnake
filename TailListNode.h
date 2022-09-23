#pragma once
#include <memory>

class TailPiece;

class TailListNode {

 private:
  std::shared_ptr<TailPiece> tailPiece;
  std::shared_ptr<TailListNode> next;
  bool hasNextNode;

 public:
  TailListNode (std::shared_ptr<TailPiece> tailPiece);
  std::shared_ptr<TailPiece> getTailPice();

  std::shared_ptr<TailListNode> getNext();

  bool hasNext();

  void setNext(std::shared_ptr<TailListNode> nextNode) ;

};
