//MircroArcade EECS 183 2014 Showcase
//Breaker Breaker

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "stdlib.h"


class Board		
{
public:

  //MODIFIES: the private member variables of Board
  //EFFECTS: initializes paddlePos and level to 0, initializes lives to 3, paddleHeight to 7, paused and ballLeft to true
  Board();

  //MODIFIES: nothing 
  //EFFECTS: returns paddlePos
  int getPaddlePos();

  //MODIFIES: paddlePos 
  //EFFECTS: sets the paddle position to input
  void setPaddlePos(int input);

  //MODIFIES: nothing 
  //EFFECTS: returns lives
  int getLives();

  //MODIFIES: lives 
  //EFFECTS: sets the lives to input
  void setLives(int input);

  //MODIFIES: nothing 
  //EFFECTS: returns level
  int getLevel();

  //MODIFIES: level
  //EFFECTS: sets the level to input
  void setLevel(int input);

  //MODIFIES: nothing 
  //EFFECTS: returns ballRow
  int getBallRow();

  //MODIFIES: ballRow
  //EFFECTS: sets the row of the ball to input
  void setBallRow(int input);

  //MODIFIES: nothing 
  //EFFECTS: returns ballCol
  int getBallCol();

  //MODIFIES: ballCol 
  //EFFECTS: sets the column of the ball to input
  void setBallCol(int input);

  //MODIFIES: nothing 
  //EFFECTS: returns ballLeft
  boolean getBallLeft();

  //MODIFIES: ballLeft 
  //EFFECTS: sets ballLeft to input
  void setBallLeft(boolean input);

  //MODIFIES: nothing 
  //EFFECTS: returns ballRight
  boolean getBallRight();

  //MODIFIES: ballRight 
  //EFFECTS: sets ballRight to input
  void setBallRight(boolean input);

  //MODIFIES: nothing 
  //EFFECTS: returns ballDown
  boolean getBallDown();

  //MODIFIES: ballDown 
  //EFFECTS: sets ballDown to input
  void setBallDown(boolean input);

  //MODIFIES:nothing
  //EFFECTS: returns paddleHeight
  int getPaddleHeight();

  //MODIFIES:paused
  //EFFECTS: sets paused to false
  void resetPause();

  //MODIFIES:paused
  //EFFETCS: sets paused to true
  void setPause();

  //MODIFIES: nothing
  //EFFETCS: returns paused
  boolean getPaused();

  //MODIFIES: strength array, ballRow, ballCol, BallRight, ballDown
  //EFFECTS: first sets up the ball so that it is on top of the paddle
  // on the left pixel with initial direction to the left and up. Next 
  //sets up the board according to which level the game is on.
  void initBoard();

  //EFFECTS:Displays the pixels with strength>0 on the board
  void displayBlocks();

  //MODIFIES: ballRow and ballCol
  //EFFECTS: updates the balls position based on what direction the ball 
  //is traveling. Be careful to not let the ball go off the board!
  void updateBall();

  //MODIFIES: nothing
  //EFFECTS: returns true if the ball goes off the board when the player 
  //fails to hit it with the paddle
  boolean lostBall();

  //MODIFIES:ballDown, ballRight, ballLeft
  //EFFECTS: changes the ball's direction if the ball hits the top or sides of the board
  void hitWall();

  //MODIFIES:ballDown, ballRight, ballLeft
  //EFFECTS:changes the direction of the ball depending on which direction the ball was traveling 
  //when it hits the paddle
  void hitPaddle( );

  //MODIFIES:ballDown, ballRight, ballLeft, strength array
  //EFFECTS:changes the direction of the ball depending on which direction the ball was traveling 
  //when it hits a block. Decrements the strength of the block.
  void hitBlock();

  //MODIFIES: nothing
  //EFFECTS: returns true if all blocks are destroyed, false otherwise 
  boolean levelComplete();

  //MODIFIES:strength array
  //EFFECTS: sets all strengths to 0
  void initStrength();


private:

  int strength[8][16];          //The strengths of blocks on the board
  int paddlePos;		//Leftmost position of the paddle
  int paddleHeight;	        // height of the upper paddle
  int lives;			//Number of lives left
  int level;			//Current level
  int ballRow;			//Row of the ball
  int ballCol;			//Column of the ball
  boolean ballLeft;		//If ballleft == TRUE, ball is moving left
  boolean ballRight;		//If ballRight == TRUE, ball is moving right.  
  boolean ballDown;		//If ballDown == TRUE, ball is moving down.  Otherwise, ball is moving up
  boolean paused;		// Pause after ball loss

};

//sets up the LED board with the correct parameters
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

//EFFECTS:turns off all the pixels on the board
void clearBoard();

//REQUIRES:  val is the value of the potentiometer
//MODIFIES: nothing
//EFFECTS: returns the column position of the left pixel of the paddle
int calculatePaddlePosition(int val);


//EFFECTS:displays the number of lives remaining/level number on the board. If it doesn't all fit 
//on the board at once, the text scrolls.
//use text size 1 and delay of 50
void printMessage(int number);

//EFFECTS:displays string text needed(suchs as "LIVES" or "LEVEL") on the board. If it
//doesn't all fit on the board at once, the text scrolls.
//use text size 1 and delay of 50
void printMessage(String message);

//contains data about pin assignments and values
struct Pins
{
  int potPin; 	        //input pin potentiometer
  int val;		//value of the potentiometer
  int button;		//input pin for the button
  int buttonState;      // current state of the button

};

void(* resetFunc) (void) = 0; //declare reset function @ address 0

//EFFECTS:displays "GameOver" on the board and resets the game. This function
//is implemented for you.
void gameOver(){
  printMessage("GameOver");
  delay(3000);
  resetFunc();
}

//DO NOT MODIFY ANY CODE ABOVE THIS LINE. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup()
{
  //set up the board, button, and potentiometer in preparation for the start of the game. All pixels should be off, 
  //strengths should be 0. Display number of lives at beginning of game

  //YOUR CODE GOES HERE

}


void loop()
{  
  //everything needed for the game to play goes here

  //YOUR CODE GOES HERE

  matrix.writeDisplay(); //display all changes made in one iteration of loop
  delay(150); //to slow it down and make it easier to debug. also makes the paddle lag       	
}

//WRITE YOUR FUNCTION IMPLEMENTATIONS BELOW 
Board::Board()
{
  setPaddlePos(0);
  setLevel(0);
  setLives(3);
  paddleHeight = 7;
  setPause();
  setBallLeft(true);
}

int Board::getPaddlePos()
{
  return paddlePos;
}

void Board::setPaddlePos(int input)
{
  paddlePos = input;
}

int Board::getLives()
{
  return lives;
}

void Board::setLives(int input)
{
  lives = input;
}

int Board::getLevel()
{
  return level;
}

void Board::setLevel(int input)
{
  level = input;
}

int Board::getBallRow()
{
  return ballRow;
}
void Board::setBallRow(int input)
{
  ballRow = input;
}

void Board::setBallCol(int input)
{
  ballCol = input;
}

int Board::getBallCol()
{
  return ballCol;
}

boolean Board::getBallLeft()
{
  return ballLeft;
}

void Board::setBallLeft(boolean input)
{
  ballLeft = input;
}

boolean Board::getBallRight()
{
  return ballRight;
}

void Board::setBallRight(boolean input)
{
  ballRight = input;
}

boolean Board::getBallDown()
{
  return ballDown;
}

void Board::setBallDown(boolean input)
{
  ballDown = input;
}

int Board::getPaddleHeight()
{
  return paddleHeight;
}

void Board::resetPause()
{
  paused = false;
}

void Board::setPause()
{
  paused = true;
}

boolean Board::getPaused()
{
  return paused;
}

void Board::initBoard()
{
  setBallRow(0);
  setBallCol(0);
  setBallRight(false);
  setBallDown(false);
  switch (level)
  {
    case 1:
      for(int i = 0; i < 8; i++)
      {
        strength[i][15] = 1;
      }
      break;
    case 2:
      for(int i = 0; i < 8; i++)
      {
        strength[i][15] = 1;
        strength[i][14] = 1;
      }
     break;
    case 3:
      for(int i = 0; i < 8; i++)
      {
         strength[i][15] = 2;
         strength[i][14] = 1;
      }
      break;
    case 4:
     for(int i = 0; i < 8; i++)
     {
        strength[i][15] = 3;
        strength[i][14] = 2;
        strength[i][13] = 1;
     }
     break;
    case 5:
     for(int i = 0; i < 8; i++)
     {
        strength[i][15] = 3;
        strength[i][14] = 0;
        strength[i][13] = 2;
        strength[i][6] = 1;
        strength[i][5] = 1;
     }
     break;
    default:
     for(int i = 0; i < 8; i++)
     {
        strength[i][15] = random(1,5);
        strength[i][14] = random(1,5);
        strength[i][13] = random(1,5);
        strength[i][6] = random(1,4);
        strength[i][5] = random(1,4);
     }
  }
}

void Board::displayBlocks()
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 16; j++)
    {
      if(Board::strength[i][j] >0)
         {
           matrix.drawPixel(i, j, 1);
         }
    }
  }
}



void Board::updateBall()
{
  //handles block collision
  if (Board::strength[ballCol][ballRow + 1] > 0)
  {
    hitBlock();
  }
  
  if ((ballLeft) && !(ballRight))
  {
      if (ballDown)
      {
           if (!(ballCol == 0))
           {
               setBallCol(ballCol - 1);
               setBallRow(ballRow - 1);
              
           }
           else hitWall();         
      }
      setBallCol(ballCol - 1);
      setBallRow(ballRow + 1);
  }
  if (!(ballLeft) && (ballRight))
  {
    if (ballDown)
    {
           if (!(ballCol == 7))
           {
               setBallCol(ballCol + 1);
               setBallRow(ballRow - 1);        
           }
           else hitWall();          
     }
     setBallCol(ballCol + 1);
     setBallRow(ballRow + 1);
   if (!(ballLeft) && !(ballRight))
   {
     setBallRow(ballRow + 1);
   }
 
}
}

boolean Board::lostBall()
{
  if (ballRow < 0)
    {
      return true;
    }
}




void Board::hitWall()
{
  if ((ballLeft == true) && (ballRight == false))
    {
      setBallLeft(false);
      setBallRight(true);
    }
   else if ((ballLeft == false) && (ballRight == true))
    {
      setBallLeft(true);
      setBallRight(false);
    }
   if ((ballLeft == false) && (ballRight == false))
    {
      setBallDown(true);
    }
}

void Board::hitPaddle()
{ 
    if ((ballRow == paddlePos + 1) || ((ballRow == paddleHeight + 1)
        && (ballRow == paddlePos + 1)))
    {
        if ((ballLeft == true) && (ballRight == false))
        //this defines actions for balls coming at the 
        //paddle from the right (moving left)
        {
          if (ballCol == paddlePos + 1)
          {
            setBallDown(false);
            setBallLeft(false);
            setBallRight(true);
          }
          if (ballCol == paddlePos)
          {
            setBallDown(false);
            setBallLeft(false);
            setBallRight(false);
          }
          if (ballCol == paddlePos - 1)
          {
            setBallDown(false);
            setBallLeft(true);
            setBallRight(false);
          }
        }
        if ((ballLeft == false) && (ballRight == true))
        //this defines actions for balls coming at the 
        //paddle from the left (moving right)
        {
          if (ballCol == paddlePos + 1)
          {
            setBallDown(false);
            setBallLeft(false);
            setBallRight(false);
          }
          if (ballCol == paddlePos)
          {
            setBallDown(false);
            setBallLeft(true);
            setBallRight(false);
          }
          if (ballCol == paddlePos + 2)
          {
            setBallDown(false);
            setBallLeft(false);
            setBallRight(true);
          }
        }
    }
}
    
    

void Board::hitBlock()
{
  if((ballCol % 2) == 0)
  {
    strength[ballCol][ballRow + 1] -= 1;
    strength[ballCol + 1][ballRow + 1] -= 1;
  }
  if ((ballCol % 2) == 1)
  {
    strength[ballCol - 1][ballRow+1] -= 1;
    strength[ballCol][ballRow + 1] -= 1;
  }
  Board::hitWall();
  if (ballDown == false)
    {
      setBallDown(true);
    }
   
}

boolean Board::levelComplete()
{
  
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 16; j++)
    {
     if (strength[i][j] != 0)
     {
       return false;
     }
    }
  }
  return true;
}

void Board::initStrength()
{
  for(int i = 0; i < 8; i++)
  { 
    for(int j = 0; j < 16; j++)
    {
      strength[i][j] = 0;
    }
  }
}

void clearBoard()
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 16; j++)
    {
      matrix.drawPixel(i,j,0); //LOOK AT THIS AGAIN
      //FOR THE LOVE OF GOD    
    }   
  }
}

void printMessage(int number)
{
 matrix.Adafruit_GFX::setTextSize(1);
 matrix.Adafruit_GFX::drawChar(0,0,(char)number, 1, 1, 1);
 delay(50);
}

void printMessage(String message)
{
  matrix.Adafruit_GFX::setCursor(0, 0);
  matrix.Adafruit_GFX::setTextColor(1);
  matrix.Adafruit_GFX::setTextSize(1);
  matrix.Adafruit_GFX::setTextWrap(false);
  matrix.Adafruit_GFX::print(message);
}



