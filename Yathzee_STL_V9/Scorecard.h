#ifndef SCORECARD_H
#define SCORECARD_H
#include<set>
#include<list>
#include<map>

using namespace std;
#include "Player.h"
#include "Dice.h"
class Scorecard {
    //Protected member variables
protected:
    int score, one, two, three, four, five, six;
    int trip, quad, small, large, chance, fHouse;
    int yazy, bonus, total, upper, lower;
public:
    //Default constructor
    Scorecard();
    //Mutator member variables
    void setOne(int o) { one = o; }
    void setTwo(int tw) { two = tw; }
    void setThree(int th) { three = th; }
    void setFour(int fr) { four = fr; }
    void setFive(int fi) { five = fi; }
    void setSix(int sx) { six = sx; }
    void setTrip(int tp) { trip = tp; }
    void setQuad(int qd) { quad = qd; }
    void setFull(int fh) { fHouse = fh; }
    void setSmall(int sm) { small = sm; }
    void setLarge(int lg) { large = lg; }
    void setYazy(int yz) { yazy = yz; }
    void setChan(int ch) { chance = ch; }
    void setBonus(int bn) { bonus = bn; }
    void setScore(int sc) { score = sc; }
    void setTotal(int t) { total = t; }
    void setUpper(int up) { upper = up; }
    void setLower(int lw) { lower = lw; }
    //virtual Accessor function
    virtual int getScore()const { return score; }
    //Accessor function
    int getOne() const { return one; }
    int getTwo()const { return two; }
    int getThree()const { return three; }
    int getFour()const { return four; }
    int getFive()const { return five; }
    int getSix()const { return six; }
    int getTrip()const { return trip; }
    int getQuad()const { return quad; }
    int getFull()const { return fHouse; }
    int getSmall()const { return small; }
    int getLarge()const { return large; }
    int getYazy()const { return yazy; }
    int getChan()const { return chance; }
    int getBon()const { return bonus; }
    int getTotal()const { return total; }
    int getUpper() const { return upper; }
    int getLower() const { return lower; }
};

#endif /* SCORECARD_H */

