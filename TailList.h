#pragma once
#include <memory>
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include "TailListNode.h"

class TailPiece;
class TailListNode;

class TailList {

private:
  std::shared_ptr<TailPiece> tailPiece;
  std::shared_ptr <TailListNode>  firstNode;
  std::shared_ptr <TailListNode>  lastNode;

public:
  static int32_t size;

  TailList();
  bool hasNext();
  std::shared_ptr<TailListNode> getNext();
  std::shared_ptr<TailListNode> getFirst();
  int32_t getSize();
  void addTailPieceToList(std::shared_ptr<TailPiece> newPiece);
  void moveTail();
};
