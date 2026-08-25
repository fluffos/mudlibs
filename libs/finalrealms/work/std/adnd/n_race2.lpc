/* AD&D, 2nd Edition (c) Player Character Races -- Race */
#include "ability.h"

string raceName, subName;
int *asMinRqr, *asMaxRqr, *asAdj;
int mBaseHt, fBaseHt, mBaseWt, fBaseWt;
int startAge, middleAge, oldAge, venerableAge;
mixed htAdj, wtAdj, startAgeAdj, maxAgeAdj;
string *classRqr;
int lightRqr;

void create(void)
{
  raceName = subName = "";
  asMinRqr = ({ 3, 3, 3, 3, 3, 3 });
  asMaxRqr = ({ 18, 18, 18, 18, 18, 18 });
  asAdj = ({ 0, 0, 0, 0, 0, 0 });
  mBaseHt = fBaseHt = mBaseWt = fBaseWt = 0;
  startingAge = middleAge = oldAge = venerableAge = 0;
  htAdj = wtAdj = startAgeAdj = maxAgeAdj = ({ 0, 0 });
  classRstr = ({ "" });
  lightRqr = 0;
}

string GetRaceName(void) { return (raceName); }
string GetSubName(void) { return (subName); }

int CheckRaceRqr(void)
{
  int i, as[NUM_AS];

  this_player()->GetActualScores(as);
  for (i = 0; i < NUM_AS; i++)
    if (as[i] < asMinRqr[i] || as[i] > asMaxRqr[i])
      return 0;
  return 1;
}

int GetAbilityScoreAdj(void)
{
  int i;
  object plrChr = this_player();

  for (i = 0; i < NUM_AS; i++)
    plrChr->ChangeAbilityScore(i, asAdj[i]);
}

int GetAvgHt(void)
{
  object plrChr = this_player();

  if (plrChr->query_male())
    return (mBaseHt + random(htAdj[0]) + htAdj[1]);
  if (plrChr->query_female())
    return (fBaseHt + random(htAdj[0]) + htAdj[1]);
  return 0;
}

int GetAvgWt(void)
{
  object plrChr = this_player();

  if (plrChr->query_male())
    return (mBaseWt + random(wtAdj[0]) + wtAdj[1]);
  if (plrChr->query_female())
    return (fBaseWt + random(wtAdj[0]) + wtAdj[1]);
  return 0;
}

int GetStartingAge(void) {
  return (startingAge + random(startAgeAdj[0]) + startAgeAdj[1]);
}

int GetMaximumAge(void) {
  return (venerableAge + random(maxAgeAdj[0]) + maxAgeAdj[1]);
}

int GetMiddleAge(void) { return (middleAge); }
int GetOldAge(void) { return (oldAge); }
int GetVenerableAge(void) { return (venerableAge); }

int CheckClassRstr(string className) {
  return (member_array(classRstr, className) >= 0);
}

int CheckVision(int light) { return (light >= lightRqr); }

/*  each race must overload this function */
int ActivateRace(void) { }


