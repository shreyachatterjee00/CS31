//
//  Pig.cpp
//  Pig
//
//

#include "Pig.h"
#include <iostream>

namespace cs31
{
    Pig::Pig()
    {
        
    }
    
    // stringify this Game by stringifying this Game's Board
    std::string Pig::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Pig!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Pig!\n";
            }
        }
        return( s );
    }
    
    // let the human player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the human's turn, set the board's rolled value and update the board's
    // human score accordingly
    int Pig::humanPlay( int amount )
    {
        
        int amountRolled = mHuman.roll(amount);
        mBoard.setRolledValue(amountRolled);
        int score = mHuman.getScore();   //change
        mBoard.setHumanScore(score);
        mBoard.setHumanTurn();
        return amountRolled;
        
        
    }
    
    // inform the human Player that their turn has ended
    // update the board's human total
    void Pig::humanEndTurn()
    {
        mHuman.endTurn();
        mBoard.setHumanTotal( mHuman.getTotal() );
        
        mBoard.setHumanScore(0);    //amending a current function 
        if (isGameOver() == false) {
            mBoard.setComputerTurn();
        }
    }
    
    // let the computer player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.mTotal    int    3
    // once you have a rolled amount, inform the board that it is now
    // the computer's turn, set the board's rolled value and update the board's
    // computer score accordingly
    int Pig::computerPlay( int amount )
    {
        int amountRolled = mComputer.roll(amount);
        mBoard.setRolledValue(amountRolled);
        int score = mComputer.getScore();        //change
        mBoard.setComputerScore(score);
        mBoard.setComputerTurn();
        return amountRolled;
    }
    
    // when keeprolling returns true, the computer will keep rolling
    // this method implements a 60% chance to keep rolling...
    // unless the score plus the existing total >= SCORENECESSARYTOWIN
    bool Pig::computerKeepRolling() const
    {
        bool result( false );
        Die d( 5 );
        d.roll();
        if (d.getValue() >= 3)
        {
            result = true;
        }
        if (mComputer.getScore() + mComputer.getTotal() >= SCORENECESSARYTOWIN)
        {
            // stop...
            result = false;
        }
        return( result );
    }
    
    // inform the computer Player that their turn has ended
    // update the board's computer total
    void Pig::computerEndTurn()
    {
        mComputer.endTurn();
        mBoard.setComputerTotal( mComputer.getTotal() );
        mBoard.setComputerScore(0); //amending a current function
        if (isGameOver() == false) {
            mBoard.setHumanTurn();
        }
    }
    
    // determine the game outcome at this moment
    //first player to 30 wins, which is the value of SCORENECESSARYTOWIN
    Pig::GAMEOUTCOME  Pig::determineGameOutcome( ) const
    {
        if (mBoard.getHumanTotal() >= SCORENECESSARYTOWIN) {
            GAMEOUTCOME result = GAMEOUTCOME::HUMANWONGAME;
            return result;
        }
        else if (mBoard.getComputerTotal() >= SCORENECESSARYTOWIN) {
            GAMEOUTCOME result = GAMEOUTCOME::COMPUTERWONGAME;
            return result;
        }
        else {
            GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
            return result;
        }
    }
    
    //  determine if the game is over
    // if it has, return true and inform the board that the game is over and
    // inform the board that the Human won or the Computer won, accordingly
    bool Pig::isGameOver()
    {
        if (determineGameOutcome() == GAMEOUTCOME::HUMANWONGAME) {
            mBoard.setGameOver(true);
            mBoard.markHumanAsWinner();
            return true;
        }
        
        else if (determineGameOutcome() == GAMEOUTCOME::COMPUTERWONGAME) {
            mBoard.setGameOver(true);
            mBoard.markComputerAsWinner();
            return true;
        }
        
        else {
            return false;
        }
        
    }

}
