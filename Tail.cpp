#include "Tail.h"

Tail::Tail(float xSpeed, float ySpeed){
  this-> tailList = std::make_shared<TailList>();
  this->xSpeed = xSpeed;
  this->ySpeed = ySpeed;

}

void Tail::addTailPiece(int xPos, int yPos){

  if (TailList::size == 0){
  std::shared_ptr<TailPiece> priorPiece = this->tailList->getLast()->getTailPiece();
  std::shared_ptr<TailPiece> newPiece = std::make_shared<TailPiece>(xPos, yPos, priorPiece);
  this->tailList->addTailPieceToList(newPiece);

  }else{

    std::shared_ptr<TailPiece> priorPiece = this->tailList->getFirst()->getTailPiece();
  std::shared_ptr<TailPiece> newPiece = std::make_shared<TailPiece>(xPos, yPos, priorPiece);
  this->tailList->addTailPieceToList(newPiece);
  }
}

void Tail::drawTail(olc::PixelGameEngine* engine, float playerXspeed, float playerYspeed, float playerXPos, float playerYPos){

  if (TailList::size == 0){
    return;
  }

  float priorXPos = playerXPos;
  float priorYPos = playerYPos;

  std::shared_ptr<TailListNode> priorNode= this-> tailList->getFirst();
  std::shared_ptr<TailPiece> priorPiece= priorNode->getTailPiece();


  if (( (priorXPos - (priorPiece->getXPos())) >= -3 &&
        (priorXPos - (priorPiece->getXPos())) <= 3)
      &&
      ((priorYPos - priorPiece->getYPos()) <=  3 &&
       (priorYPos - priorPiece->getYPos()) >= -3)
      ) {

  }else{
    priorPiece->setCheckpoint(playerXPos, playerYPos);
  }
  priorPiece->update();
  priorPiece->draw(engine);


  int i = 0;
  while (priorNode->hasNext()){
    i++;
    engine->DrawStringDecal({10,5}, "in While "+ std::to_string(i),olc::RED, {0.2f, 0.2f} );

    priorNode = priorNode->getNext();
    priorXPos = priorPiece->getXPos();
    priorYPos = priorPiece->getYPos();
    priorPiece = priorNode->getTailPiece();

  if (( (priorXPos - (priorPiece->getXPos())) >= -3 &&
        (priorXPos - (priorPiece->getXPos())) <= 3)
      &&
      ((priorYPos - priorPiece->getYPos()) <=  3 &&
       (priorYPos - priorPiece->getYPos()) >= -3)
      ) {

  }else{
   priorPiece->setCheckpoint(priorXPos, priorYPos);
  }
  priorPiece->update();
  priorPiece->draw(engine);
  }
  engine->DrawStringDecal({10,50}, "Tail:",olc::GREEN, {0.1f, 0.1f} );
}

/*



  float firstXPos = tempNode->getTailPiece() ->getXPos();
  float firstYPos = tempNode ->getTailPiece() ->getYPos();


  compensate(tempNode, firstXPos, firstYPos, xPos, yPos, xSpeed, ySpeed);



  if(std::abs(firstXPos -xPos) >4 || std::abs(firstYPos-yPos) >4){


    tempNode->getTailPiece()-> move(firstXPos+xSpeed, firstYPos+ySpeed);
  }

  tempNode->getTailPiece()->draw(engine);

  int i = 0;
  /*
    while (tempNode ->hasNext()){

    tempNode = tempNode->getNext();


    tempXPos = tempNode->getTailPiece() ->getXPos();
    tempYPos = tempNode ->getTailPiece() ->getYPos();

    if(std::abs(tempXPos -xPos) >2 || std::abs(tempYPos-yPos) >2){

    tempNode->move(xPos+xSpeed, yPos+ySpeed);
    }
    tempNode->draw(engine);
    xPos =  tempXPos;
    yPos =  tempYPos;
    i++;
    }
  */
