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
  }

  /*
  std::shared_ptr<TailPiece> priorPiece = this->tailList->getLast()->getTailPiece();
  std::shared_ptr<TailPiece> newPiece = std::make_shared<TailPiece>(xPos, yPos, priorPiece);
  this->tailList->addTailPieceToList(newPiece);
  */
}

void Tail::onUpdate(std::shared_ptr<Player> player){

}

void Tail::compensate(std::shared_ptr<TailListNode> node,  float priorPieceX, float priorPieceY,float xPos,float yPos, float xSpeed, float ySpeed){
}

void Tail::drawTail(olc::PixelGameEngine* engine, float playerXspeed, float playerYspeed, float playerXPos, float playerYPos){

  if (TailList::size == 0){
    return;
  }

  std::shared_ptr<TailListNode> firstNode= this-> tailList->getFirst();
  std::shared_ptr<TailPiece> firstPiece= firstNode->getTailPiece();


  engine->DrawStringDecal({3,1}, "Xdist"+ std::to_string(playerXPos - (firstPiece->getXPos())), olc::RED, {0.1f, 0.1f} );
  engine->DrawStringDecal({3,2}, "PlayerXpos"+ std::to_string(playerXPos), olc::RED, {0.1f, 0.1f} );
  engine->DrawStringDecal({3,5}, "tailXcheckpointX"+ std::to_string(firstPiece->getCheckpointX()), olc::RED, {0.1f, 0.1f} );


  if (( (playerXPos - (firstPiece->getXPos())) >= -3 &&
        (playerXPos - (firstPiece->getXPos())) <= 3)
      &&
      ((playerYPos - firstPiece->getYPos()) <=  3 &&
       (playerYPos - firstPiece->getYPos()) >= -33)

      ) {
    engine->DrawStringDecal({10,3}, "Less then 4" , olc::RED, {0.1f, 0.1f} );

  }else{
   firstPiece->setCheckpoint(playerXPos, playerYPos,0,0); //TODO

  }
  firstPiece->update();

  firstPiece->draw(engine);
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
