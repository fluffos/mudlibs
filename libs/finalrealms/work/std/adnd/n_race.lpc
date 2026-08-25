/* AD&D, 2nd Edition (c) Player Character Race */
#include "ability.h"

string raceObj;                        /* filename of race object */
int height, weight;                    /* in inches and pounds */
int curAge, realAge, maxAge;           /* in game years */

string get_race_obj(void) { return (raceObj); }

int set_race_obj(string filename)
{
  if (!filename || filename == "" || file_size(filename) < 0)
    return 0;
  if (!filename->CheckRaceRqr())
    return 0;
  raceObj = filename;
  raceObj->GetAbilityScoreAdj();
  height = raceObj->GetAvgHt();
  weight = raceObj->GetAvgWt();
  realAge = curAge = raceObj->GetStartingAge();
  maxAge = raceObj->GetMaximumAge();
  raceObj->ActivateRace();
}

int get_height(void) { return (height); }
int get_weight(void) { return (weight); }
void set_height(int ht) { height = ht; }
void set_weight(int wt) { weight = wt; }
int adjust_height(int adj) { return (height += adj); }
int adjust_weight(int adj) { return (weight += adj); }

int get_current_age(void) { return (curAge); }
/*
int get_real_age(void) { return (realAge); }
int get_maximum_age(void) { return (maxAge); }
*/
int adjust_current_age(int adj)
{
  if (curAge + adj > maxAge)
  {
    this_player()->natural_death();
    return (curAge);
  }
  curAge += adj;
  get_physical_effects();
  return (curAge);
}

int adjust_maximum_age(int adj)
{
  if (curAge > maxAge + adj)
  {
    this_player()->natural_death();
    return (curAge);
  }
  return (maxAge += adj);
}

/*  this function should only be called by the process that keeps   */
/*  track of time.  it should be called only once per game year.    */
/*  for example, if the ratio of game time to real time is 6 sec    */
/*  to 1 sec, this function would be called every 60 game days and  */
/*  20 game hours.  This is called regardless of the amount of      */
/*  time that the player has used in that period.  after all, a     */
/*  player character doesn't adventure every single day.            */

void happy_birthday(void)
{
  realAge++;
  get_physical_effects();    /* physical effects can oscillate      */
  get_mental_effects();      /* mental effects depend on real age   */
}

void get_mental_effects(void)
{
  if (realAge > raceObj->GetVenerableAge())
    ChangeAbilityScore(INT, 1), ChangeAbilityScore(WIS, 1);
  if (realAge > raceObj->GetOldAge())
    ChangeAbilityScore(WIS, 1);
  if (realAge > raceObj(INT, 1), ChangeAbilityScore(WIS, 1);
}

void get_physical_effects(void)
{
  nosave int middle = 0, old = 0, venerable = 0;
  object plrChr = this_player();

  if (curAge < raceObj->GetMiddleAge())
  {
    if (middle)
    {
      plrChr->ChangeAbilityScore(STR, 1);
      plrChr->ChangeAbilityScore(CON, 1);
      middle = 0;
    }
    if (old)
    {
      plrChr->ChangeAbilityScore(STR, 2);
      plrChr->ChangeAbilityScore(DEX, 2);
      plrChr->ChangeAbilityScore(CON, 1);
      old = 0;
    }
    if (venerable)
    {
      plrChr->ChangeAbilityScore(STR, 1);
      plrChr->ChangeAbilityScore(DEX, 1);
      plrChr->ChangeAbilityScore(CON, 1);
      venerable = 0;
    }
    return;
  }
  if (!middle)
  {
    plrChr->ChangeAbilityScore(STR, -1);
    plrChr->ChangeAbilityScore(CON, -1);
    middle = 1;
  }
  if (curAge < raceObj->GetOldAge())
    return;
  if (!old)
  {
    plrChr->ChangeAbilityScore(STR, -2);
    plrChr->ChangeAbilityScore(DEX, -2);
    plrChr->ChangeAbilityScore(CON, -1);
    old = 1;
  }
  if (curAge < raceObj->GetVenerableAge())
    return;
  if (!venerable)
  {
    plrChr->ChangeAbilityScore(STR, -1);
    plrChr->ChangeAbilityScore(DEX, -1);
    plrChr->ChangeAbilityScore(CON, -1);
    venerable = 1;
  }
}

