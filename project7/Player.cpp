//
//  Player.cpp
//  Pig
//
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll( int amount )
    {
        if (amount == 0) {
            mDie.roll();
            int currentRoll = mDie.getValue();
            if (currentRoll == 1) {
                mScore = 0;
            }
            else {
                mScore = mScore + currentRoll;
            }
        return currentRoll;
    }
        
        else {
            int currentRoll = amount;
            if (currentRoll == 1) {
                mScore = 0;
            }
            else {
                mScore = mScore + currentRoll;
            }
            return currentRoll;
        }
        
    }

    
    //add the current score into the running total since the turn ended
    //       reset the current score to 0 for the next round of play
    //problem is that mScore only holds last roll score, and because this function is only called when the turn is over, the total ends up only being the last die roll instead of the entire total
    void Player::endTurn()
    {
        mTotal = mTotal + mScore;
        mScore = 0;
    }
    
    // return the current total
    int Player::getTotal( ) const
    {
        return( mTotal );
    }
    
    // return the current total
    int  Player::getScore( ) const
    {
        return( mScore );
    }
    

}
