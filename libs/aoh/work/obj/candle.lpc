/**
 **   A simple candle. Will burn for approx. 1600 secs w/o lag
 **   Feb 1997 [tune]  creation
 **   May 1997 [tune]  fixed msgs 
 **/


#include <properties.h>
#include <lamp.h>
#include <nightday.h>
#include <config.h>

inherit "/std/lamp";

void create()  
{
  ::create();
  SetShort("a candle");
  SetLong("A simple white wax candle.\n");
  
  SetIds( ({ "candle", "light" }) );
  AddAdjective( ({ "wax", "white" }) );
  
  Set(P_BURN_STEP, 400);      // one fuel unit burns 300 secs.
  Set(P_FUELTYPE, PFT_NONE);  // can't refill a candle
  
  SetFuelAmount(4, 4);        // candle burns (400 secs * 4)
  SetValues(10, 0);           // candle is worth 10, wick 0
                              // when burning 1/4 as bright as a torch
  SetBrightness( (ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT))/4 );
  SetWeights(15, 0);          // candle 15g, wick 0g
  
  SetHelpMsg(
   "A candle, when lit, can offer some light - however, not as much "
   "as a lit torch. You can also extinguish it.\n");
  
  SetLMsg( 0, "the candle is already burning");
  SetLMsg( 1, "The candle is already out.\n");
  SetLMsg( 2, "The wick is completely burnt up - the candle won't light anymore.\n");
  SetLMsg( 3, "The candle starts burning.\n");
  SetLMsg( 4, "@@Pl_Name@@ lights @@Pl_Poss@@ candle.\n");
  SetLMsg( 5, "You blow out your candle.\n");
  SetLMsg( 6, "@@Pl_Name@@ blows out @@Pl_Poss@@ candle.\n");
  SetLMsg( 7, "Your candle sputters and goes out as the wick burns up.\n");
  SetLMsg( 8, "@@Pl_Owner@@ candle sputters and goes out.\n");

}

varargs string Short()
{
  string sh;

  sh = ::Short();
  if (QueryBurning())
    sh = "a burning " + strip_a(sh);
  return sh;
}

varargs string QueryLong() 
{
  if (QueryBurning()) 
    return "A simple white wax candle. It is burning.\n";
  return ::QueryLong();
}

int BurnUp()
{
  ::BurnUp();
  switch(Query(P_FUEL))
  {
    case 3:
      show(
       "The candle has burned down a few inches.\n");
      break;
    case 2:
      show(
       "The candle has burned down halfway.\n");
      break;
    case 1:
      show(
       "The candle has burned down to a stub.\n");
      break;
    case 0:
      remove();
      break;
  }
  return 0;
}
