
/*--------------------------------------------------------------------------
 *  /std/herb.c --  Standard herb
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 *
 *  21-jun-97 [softbyte]  creation
 *  28-jun-97 [tune]      added sorted flag for faster handling,
 *                        changed the big herb text mapping to one string prop
 *  01-feb-98 [tune]      more diddling; added property functions; changed
 *                        SetStandard() a bit; added random values based on
 *                        herb strength;
 */

// TODO: Functions need to be implemented

#include <properties.h>
#include <herbs.h>
#include <classes.h>

inherit "/std/unit";
inherit "/std/food";

nosave int *herb_min;        // array of skills values

mapping herb_skill_data;     // holds all skill data for this herb
int is_sorted = 0;           // flag if skills array is sorted

string pHerbLong, pHerbName;
string pHerbFun, pHerbEatMsg;
int pHerbStrength, pHerbType;


// prototypes
string SetHerbName(string s);
int SetHerbType(int i);
int SetHerbStrength(int i);
string SetHerbFun(string s);
string SetHerbEatMsg(string s);


/** --------------------------------------------------------------- **
 **                       Public Functions                          **
 ** --------------------------------------------------------------- **/


  /** ------------------------------------------------------------
      @function     SetStandard( int type, string name,
                                 int strength, string text )

      @return       int
                    1 on success, 0 on failure

      @description  Use this function to quickly and easily configure
                    an herb. SetStandard() sets the type of herb, its
                    name, its strength, eat message, a random value,
                    and the function to be called when the herb is
                    eaten.


      @param        int type
                    This is the general type of herb. The most common
                    types are listed in /sys/herbs.h. To make a custom
                    herb, use type HERB_CUSTOM. It is stored in
                    P_HERB_TYPE.

                    Types can be:
                    HERB_HEAL_HP
                    HERB_HEAL_SP
                    HERB_HEAL_EP     (TODO)
                    HERB_HEAL_POISON
                    HERB_HURT_HP
                    HERB_HURT_SP
                    HERB_HURT_EP     (TODO)
                    HERB_SATIATE
                    HERB_INTOXICATE  (TODO)
                    HERB_SLEEP       (TODO)
                    HERB_CUSTOM

      @param        string name
                    This is the name of the herb. It is required so
                    that healers who buy and sell the herbs can
                    identify the herb. The value is stored in P_HERB_NAME.

      @param        int strength        [optional]
                    This defines how many points (HP, SP, etc) are
                    added to or removed from the player. If strength
                    is not given, a random number will be selected.
                    The value is stored in P_HERB_STRENGTH.
                    Custom herbs do not necessarily need a strength.


      @param        string text         [optional]
                    This is the message given to the player after they
                    have digested the herb. If none is given, the
                    default message will be used. The value is stored
                    in P_HERB_EAT_MSG.

      ------------------------------------------------------------
*/


public varargs int SetStandard(int type, string name, int strength,
                               string text )
{
  string tmp;

  if (!type || !name)
  {
    raise_error(
      "Usage: \n"
      "   SetStandard(int herb_type, string herb_name, int strength,  "
         "string eat_msg).\n"
      "Minimum required arguments:\n"
      "   herb_type, herb_name \n"
      "Optional Arguments: \n"
      "   strength, eat_msg \n"
    );
    return 0;
  }

  if(!strength)
    strength = random(20) + 1;

  SetHerbType(type);
  SetHerbStrength(strength);
  SetHerbName(name);
  AddId(name);

  switch(type)
  {
    case HERB_HEAL_HP:
      tmp = "The refreshing taste of the @@QueryShort@@ restores your health.\n";
      SetHerbFun("HealHP");
      SetValuePerUnit( (random(20)+10) * strength );
      break;
    case HERB_HEAL_SP:
      tmp = "You feel strange but the @@QueryShort@@ restores your magic energy.\n";
      SetHerbFun("HealSP");
      SetValuePerUnit( (random(15)+15) * strength );
      break;
    case HERB_HEAL_POISON:
      tmp = "The power of the @@QueryShort@@ cleans your blood from poison.\n";
      strength = -strength;
      SetHerbFun("AddPoison");
      SetValuePerUnit( (random(12)+15) * strength );
      break;
    case HERB_HURT_HP:
      tmp = "The bitter taste of the @@QueryShort@@ hurts you.\n";
      SetHerbFun("ReduceHP");
      SetValuePerUnit( (random(5)+8) * strength );
      break;
    case HERB_HURT_SP:
      tmp = "You gasp at the bitter taste of the @@QueryShort@@ and loose magic energy.\n";
      SetHerbFun("ReduceSP");
      SetValuePerUnit( (random(9)+7) * strength );
      break;
    case HERB_HURT_POISON:
      tmp = "The @@QueryShort@@ taste poisonous. You don't feel very well now.\n";
      SetHerbFun("AddPoison");
      SetValuePerUnit( (random(5)+10) * strength );
      break;
    case HERB_SATIATE:
      tmp = "The @@QueryShort@@ let you feel less hungry.\n";
      SetHerbFun("AddFood");
      SetValuePerUnit( (random(7)+8) * strength );
      break;
    default:
      tmp = "That didn't taste too badly.\n";
      SetValuePerUnit( (random(10)+5) * strength );
  }

  if (text && stringp(text))
    SetHerbEatMsg(text);
  else
    SetHerbEatMsg(tmp);

  return 1;
}




// ----------------------------------------------------------------------
// Optional you can change the look of the herb when a skilled player
// looks at it which has a skill between minskill and maxskill
// The text is then simply added to the long or plural long description
// depending on the amount of herbs the player has

varargs int	AddHerbInfo(int minskill, string long, string plurallong)
{
  if (!plurallong)
    plurallong = long;
  herb_min += ({minskill});
  //herb_long += ({long});
  //herb_plural += ({plurallong});
  herb_skill_data += ([ minskill: long; plurallong ]);
  return 1;
}

/** --------------------------------------------------------------- **
 **                      Private Functions                          **
 ** --------------------------------------------------------------- **/

// returns the modified long descripton if 'skill' is high enough to
// get it. if pluralflag is set the modified plural long is returned

public string GetHerbInfo(int skill,int pluralflag)
{
  int i, tmp;
  string long;

  long = "";

  if(!is_sorted)
  {
    sort_array(herb_min, #'> /*'*/);
    is_sorted = 1;
  }

  for (i=0; i < sizeof(herb_min); i++)
  {
    if (skill <= herb_min[i])
	{
	    break;
	}
	else
	  tmp = herb_min[i];
  }
  if (pluralflag)
    return herb_skill_data[tmp, 1];
  return herb_skill_data[tmp,0];
}

// ----------------------------------------------------------------------
// If you want completely own herb handling overwrite the NotifyEat
// function but use the standard herb anyways. NotifyEat will be called
// when the player has eaten the herb sucessfully

public void NotifyEat(object player)
{
  string s;       // text output
  int amount;     // strength
  string fun;     // function to call

  amount = Query(P_HERB_STRENGTH);
  s = Query(P_HERB_EAT_MSG);

  if(fun = Query(P_HERB_FUN))
    call_other(player, fun, amount);
  tell_object(player,process_string(s || ""));

  return;
}

// ----------------------------------------------------------------------
//                            Properties
// ----------------------------------------------------------------------

// A special long description for players with herbalism skills.

string SetHerbLong(string text)
{
   return pHerbLong = text;
}

string QueryHerbLong()
{
   return pHerbLong || "";
}

// The type of herb

int SetHerbType(int type)
{
   return pHerbType = type;
}

string QueryHerbType()
{
   return pHerbType || "";
}

string SetHerbName(string name)
{
   return pHerbName = name;
}

string QueryHerbName()
{
   return pHerbName || "";
}

int SetHerbStrength(int strength)
{
   return pHerbStrength = strength;
}

string QueryHerbStrength()
{
   return pHerbStrength || "";
}

string SetHerbFun(string fun)
{
   return pHerbFun = fun;
}

string QueryHerbFun()
{
   return pHerbFun || "";
}

string SetHerbEatMsg(string pEatMsg)
{
   return pHerbEatMsg = pEatMsg;
}

string QueryHerbEatMsg()
{
   return pHerbEatMsg || "";
}

// ----------------------------------------------------------------------
// Modify the long description

varargs string QueryLong()
{
  int skill;

  skill = ({int})this_player()->QueryAttr(SK_HERB);
  return ::QueryLong() + (skill ? QueryHerbLong() : "") + (GetHerbInfo(skill,0) || "");
}

// ----------------------------------------------------------------------
// Modify the plural long description

varargs string QueryPluralLong(string what)
{
  int skill;

  skill = ({int})this_player()->QueryAttr(SK_HERB);
  return ::QueryPluralLong(what) + (skill ? QueryHerbLong() : "") +
         (GetHerbInfo(skill,1) || "");
}

// ----------------------------------------------------------------------
// For debugging

public void QueryHerbData()
{
   printf("herb_skill_data: %O \nherb_min: %O", herb_skill_data, herb_min);
}

// ----------------------------------------------------------------------
// Create

varargs void create()
{
  unit::create();
  food::create();

  // Some food initialisations
  SetFood();        // herbs are food in principle
  SetFoodStuff(1);  // They hardly stuff
  SetFoodHeal(0);   // Possible heal handling is done be ourselves

  // these food messages are simply defaults if no other message is set
  SetFoodMsgs( ({
    "You consume the herb.\n",                 // msg to player
    "@@Pl_Name@@ consumes an herb.\n",         // to seeing environment
    "Someone chews and swallows something.\n"  // non-seeing environment
  }) );

  // our own initialisations
  herb_min = ({});
  herb_skill_data = ([]);

  SetLong("A pleasantly fragrant herb with green leaves.\n");
  SetShort("an herb");
  AddId(C_HERB);
  AddPluralId("herbs");

  SetHerbType(HERB_DEFAULT);              // no special effect
  SetHerbName("unknown");

  SetWeightPerUnit(10);
  SetValuePerUnit(random(20) + 10);
  SetAmount(1);

  Set(P_INFO,     "It's an herb, which could quite possibly be edible.\n");
  Set(P_HELP_MSG, "You can 'eat' this.\n");
}

void init()
{
  ::init();
  food::init();
}
