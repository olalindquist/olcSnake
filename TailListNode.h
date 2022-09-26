#pragma once
#include <memory>
#include "TailPiece.h"

class TailPiece;

class TailListNode {

 private:
  std::shared_ptr<TailPiece> tailPiece;
  std::shared_ptr<TailListNode> next;
  bool hasNextNode;

 public:
  TailListNode (std::shared_ptr<TailPiece> tailPiece);
  TailListNode ();
  std::shared_ptr<TailPiece> getTailPiece();
  std::shared_ptr<TailListNode> getNext();
  bool hasNext();
  void setNext(std::shared_ptr<TailListNode> nextNode) ;
  void draw(olc::PixelGameEngine* engine);

};
