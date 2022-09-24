#include "Tail.h"


Tail::Tail(float xSpeed, float ySpeed){

  this-> tailList = std::make_shared<TailList>();
  this->xSpeed = xSpeed;
  this->ySpeed = ySpeed;
}

/*
  Tail::Tail(int xPos, int yPos){
  this->xPos = xPos;
  this->yPos = yPos;

  /*
  this->tailSprite = new olc::Sprite("./graphics/ball.png");
  this->tailDecal = new olc::Decal(this->tailSprite);
  this->len = 0;
  std::cout <<"TailCreate " <<std::to_string(len)<< "\n";
  this->hasNext = false;
  }
*/

void Tail::addTailPiece(int xPos, int yPos){

  std::shared_ptr<TailPiece> newPiece = std::make_shared<TailPiece>(xPos, yPos);
  this->tailList->addTailPieceToList(newPiece);
}

void Tail::onUpdate(std::shared_ptr<Player> player){
}

void Tail::drawTail(olc::PixelGameEngine* engine, float xSpeed, float ySpeed, float xPos, float yPos){

  if (TailList::size == 0){
    return;
  }

  std::shared_ptr<TailListNode> tempNode= this-> tailList->getFirst();
  float tempXPos = tempNode->getTailPiece() ->getXPos();
  float tempYPos = tempNode ->getTailPiece() ->getYPos();

    if (tempYPos != yPos){
      tempNode->move(tempXPos, tempYPos+ySpeed);
      engine->DrawStringDecal({10,5}, "compensating x",olc::GREEN, {0.1f, 0.1f} );
    }

    if (tempXPos != xPos){
        engine->DrawStringDecal({10,8}, "compensating y",olc::GREEN, {0.1f, 0.1f} );
      tempNode->move( tempXPos+xSpeed, tempYPos);
    }

  if(std::abs(tempXPos -xPos) >4 || std::abs(tempYPos-yPos) >4){


    tempNode->getTailPiece()-> move(tempXPos+xSpeed, tempYPos+ySpeed);
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
  engine->DrawStringDecal({10,50}, "Tail:"+std::to_string(i),olc::GREEN, {0.1f, 0.1f} );

}
