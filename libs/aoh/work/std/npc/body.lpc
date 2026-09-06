/* std/npc/body
**
**  This are the extended life functions of a npc.
*/

#include <attributes.h>
#include <combat.h>
#include <combattune.h>
#include <living.h>
#include <messages.h>
#include <health.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <driver/object_info.h>

inherit "/std/living/body";

#define THIS this_object()
#define TP   this_player()
#define ENV  environment
#define PREV previous_object()

#define NETDEAD  (THIS && !interactive() && query_once_interactive(THIS))
public void AddHeart(mixed hook);     // std/living/heart
public int QueryLState();             // std/living/description

/*--------------------------------------------------------------------------*/

private int aAlcohol, aFood, aDrink;
private int aDegAlcohol, aDegFood, aDegDrink;
private int aMaxAlcohol, aMaxFood, aMaxDrink;
private int aRateAlcohol;

// These variables accumulate the 1/10-degeneration points
// over the heart_beat()s.

private int accAlc, accFood, accDrink;

/*--------------------------------------------------------------------------*/

public int QueryDegAlcohol() { return aDegAlcohol; }
public int SetDegAlcohol(int i) { return aDegAlcohol = i; }

public int QueryMaxAlcohol() { return aMaxAlcohol; }
public int SetMaxAlcohol(int i) { AddHeart(HEART_BODY); return aMaxAlcohol = i; }

public int QueryAlcohol() { return aAlcohol; }
public int SetAlcohol(int i) {
  int max;
  max = QueryMaxAlcohol();
  AddHeart(HEART_BODY);
  return aAlcohol = i > max ? max : i;
}

public int QueryRateAlcohol() { return aRateAlcohol; }
public int SetRateAlcohol(int i) { return aRateAlcohol = i; }

public int QueryDegDrink() { return aDegDrink; }
public int SetDegDrink(int i) { return aDegDrink = i; }

public int QueryMaxDrink() { return aMaxDrink; }
public int SetMaxDrink(int i) { AddHeart(HEART_BODY); return aMaxDrink = i; }

public int QueryDrink() { return aDrink; }
public int SetDrink(int i) {
  int max;
  max = QueryMaxDrink();
  AddHeart(HEART_BODY);
  return aDrink = i > max ? max : i;
}

public int QueryDegFood() { return aDegFood; }
public int SetDegFood(int i) { return aDegFood = i; }

public int QueryMaxFood() { return aMaxFood; }
public int SetMaxFood(int i) { AddHeart(HEART_BODY); return aMaxFood = i; }

public int QueryFood() { return aFood; }
public int SetFood(int i) {
  int max;
  max = QueryMaxFood();
  AddHeart(HEART_BODY);
  return aFood = i > max ? max : i;
}


/*  QueryFoodMsg stuff, for easier fodder handling */

public string FoodMsg(int food) {
  string str;
  int i;
  switch(food) {
    case 90..101: str = "Totally full!"; break;
    case 75.. 89: str = "Mighty stuffed"; break;
    case 50.. 74: str = "Satisfied"; break;
    case 25.. 49: str = "A bit hungry"; break;
    case 10.. 24: str = "A bit hungry"; break;
    case  0..  9: str = "Hungry"; break;
    default:
      i = QueryFood();
      if (i > -10) str = "Very hungry";
      else if (i > -50) str = "Very hungry";
      else if (i > -250) str = "Mass hungry";
      else if (i > -500) str = "Get food!";
      else str = "get food!";
  }
  return str;
}

public string QueryFoodMsg() {
  return FoodMsg(aFood);
}
// ----------------------------

public string AlcoholMsg(int alcohol) {
  string str;
  switch (alcohol) {
    case 90..101: str = "Totally bombed!"; break;
    case 75.. 89: str = "Happily smashed"; break;
    case 50.. 74: str = "Very drunk"; break;
    case 25.. 49: str = "Drunk"; break;
    case 10.. 24: str = "Light-headed"; break;
    case  5..  9: str = "Slighty drunk"; break;
    case -1..  4: str = "Sober"; break;
    default:  str = "sober";
  }
  return str;
}

public string QueryAlcoholMsg() {
  return AlcoholMsg(aAlcohol);
}
// -------------------
public string DrinkMsg(int drink) {
  string str;
  int i;
  switch(drink) {
    case 90..101: str = "Totally quenched!"; break;
    case 75.. 89: str = "Soaked"; break;
    case 50.. 74: str = "Sorta soaked"; break;
    case 25.. 49: str = "Half full"; break;
    case 10.. 24: str = "Thirsty"; break;
    case  0..  9: str = "Pretty thirsty"; break;
    default:
      i = QueryDrink();
      if (i > -10) str = "Pretty thirsty";
      else if (i > -50) str = "Very thirsty";
      else if (i > -250) str = "Extremely thirsty";
      else if (i > -500) str = "Parched";
      else str = "parched";
  }
  return str;
}
public string QueryDrinkMsg() {
  return DrinkMsg(aDrink);
}

//---------------------------------------------------------------------------

public int AddAlcohol(int strength)
{
  int alc;
  if ((alc = QueryAlcohol()) > QueryMaxAlcohol() && strength > 0)
    return 0;
  alc += strength;
  SetAlcohol(alc >= 0 ? alc : 0);
  return QueryAlcohol() - (alc-strength);
}

public int AddDrink(int strength)
{
  int drink;
  if ((drink = QueryDrink())+strength > QueryMaxDrink() && strength > 0)
    return 0;
  SetDrink(drink+strength);
  return strength;
}

public int AddFood(int strength)
{
  int food;
  if ((food = QueryFood())+strength > QueryMaxFood() && strength > 0)
    return 0;
  SetFood(food+strength);
  return strength;
}

//---------------------------------------------------------------------------

public int QueryRegHP() {
  int val;
  val = ::QueryRegHP();
  if (QueryFood() < 0 || QueryDrink() < 0)
    val -= QueryRateHP();
  if (QueryAlcohol())
    val += QueryRateAlcohol();
  return val;
}

public int QueryRegSP() {
  int val;
  val = ::QueryRegSP();
  if (QueryFood() < 0 || QueryDrink() < 0)
    val -= QueryRateSP();
  if (QueryAlcohol())
    val += QueryRateAlcohol();
  return val;
}

//---------------------------------------------------------------------------
public void DoDigest()
{
  int val;

  if (!Query(P_NOWIZ) || LSTATE_GHOST == QueryLState())
    return;

#if 0
  if (IS_IMMORTAL(this_object()) || LSTATE_GHOST == QueryLState())
    return;
#endif

  // Reduce Drink.
  val = QueryDrink() - 1;
  accDrink += QueryDegDrink();
  if (accDrink > 100)
  {
    accDrink -= 100;
    SetDrink(val);
    if (val <= -500)
    {
      ReduceHP(1, 10);
      write("You are drying out.\n");
    }
    else if ( val <= 10 && random(100) < 10)
      write("You feel thirsty.\n");
  }

  // Reduce Food.
  val = QueryFood() - 1;
  accFood += QueryDegFood();
  if (accFood > 100)
  {
    accFood -= 100;
    SetFood(val);
    if (val <= -500)
    {
      ReduceHP(1, 10);
      write("You faint.\n");
    }
    else if ( val <= 10 && random(100) < 10)
      write("You feel hungry.\n");
  }
  if (THIS && interactive(THIS))
    AddHeart(HEART_BODY);
}

//---------------------------------------------------------------------------
public int body_heartbeat()
{
  int val, alc, rc;

  rc = ::body_heartbeat();
  if (LSTATE_GHOST == QueryLState())
    rc = 1;
  else
  {
    alc = QueryAlcohol();
    if (alc && (val = random(100)) < 4)
    {
      write( ({"You hiccup.\n", "You stumble.\n", "You feel drunk.\n",
                "You burp.\n"
              })[val]);
      say(capitalize(QueryName()) + ({" hiccups.\n",
                          " seems to fall, but takes a step and recovers.\n",
                          " looks drunk.\n",
                          " burps.\n"})[val]);
    }
    // Degenerate alcohol.
    if (alc > 0)
    {
      val -= 1;
      accAlc += QueryDegAlcohol();
      if (accAlc > 100)
      {
        accAlc -= 100;
        if (val < 1)
        {
          val = 0;
          write("You are sober.\n");
        }
        SetAlcohol(val);
      }
      if (val)
        rc = 1;
    }

    if (THIS && interactive(THIS))
      DoDigest();
  }
  return rc;
}


//---------------------------------------------------------------------------
public varargs void Death(object *killers) {
  if (!({int})THIS->second_life())
    ::Death(killers);
}

public void create()
{
  ::create();
  SetRateAlcohol(ALCOHOL_RATE);
  SetDegAlcohol(ALCOHOL_DEG);
  SetDegDrink(DRINK_DEG);
  SetDegFood(FOOD_DEG);
}

/****************************************************************************/
