/* Advent - The Fierce Green Dragon -- Mateese, 19-Aug-96
 *
 * The dragon can be found in the Secret Canyon, guarding the Persian Rug.
 * It can be killed with bare hands by answering the question with 'yes'
 * (said or commanded).
 * The state of the answer is stored in the player as 'AdventDragonQuestion':
 *   0: didn't try to kill yet.
 *   1: tried to kill, didn't answer yet.
 *   2: second try to kill, maybe answered no.
 */

#include <config.h>
#include <properties.h>
#include <living.h>
#include <moving.h>
#include "advent.h"

inherit "/std/living";
inherit ADVENT("i/advlib");

#define P_QUESTION "AdventDragonQuestion"

/*-----------------------------------------------------------------------*/
public void create()
{
  if (::create()) /* Don't setup the blueprint */
    return;

  // Description
  SetInitLevel(50);
  Set(P_NAME, "Dragon");
  Set(P_SHORT, "a fierce green dragon");
  Set(P_LONG, "A huge fierce green dragon. Nothing to mess with.\n");
  Set(P_WEIGHT, 300000);
  Set(P_VALUE, 0);
  Set(P_RACE, "dragon");
  Set(P_GENDER, GENDER_NEUTER);
  Set(P_WIMPY, 10);
  Set(P_GO_CHANCE, 0);
  Set(P_MSGIN,   ({ "stomps in", "stomps in" }) );
  Set(P_MSGOUT,  ({ "stomps", "stomps out" }) );
  Set(P_MMSGIN,  ({ "plops in", "is here" }) );
  Set(P_MMSGOUT, ({ "fades away", "left" }) );
  Set(P_HANDS, ({ ({ " tail", 0, 20 })
                , ({ "its mouth", 0, 50 })
               })
     );
  Set(P_KILL_XP, 30000);
  Set(P_SHRUG_MSG, "Hiss!\n");
  Set(P_NOGET, "It nearly takes you instead!\n");
    /* the original killed the player upon this attempt */
  AddDefence(0, 40);
  AddDefence(DT_SLASH, 10);
  AddDefence(DT_BLUDGEON, 10);
  AddDefence(DT_PIERCE, 10);
  AddDefence(DT_FIRE, 20);
  AddDefence(DT_COLD, 10);

  AddId( ({ "dragon", ADV_DRAGON }) );
  AddAdjective( ({"huge", "green", "fierce" }) );
    
  Set(ADV_DRAGON, 1);

  /* Catch the saying of 'yes' or 'no'.
   */
  InitMatch(
       ({ "_catch_yesno" }),  /* Function        */
       ({ "says:"        }),  /* type            */
       ({ 0              })   /* match (0 == "") */
           );
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  this_player()->Set(P_QUESTION, 0);
  add_action("fkill", "kill");
  add_action("fyesno", "yes");
  add_action("fyesno", "no");

  write("A huge green fierce dragon bars your way!\n");
}

/*-----------------------------------------------------------------------*/
public int fkill (string arg)

/* Intercept the 'kill' command to ask the question before.
 */

{
  int question;
    
  if (!arg || -1 == strstr("dragon", arg))
    return 0;

  question = this_player()->Query(P_QUESTION);
  
  /* Player didn't answer the question or answered 'no' before.
   */
  if (question >= 1)
  {
    this_player()->Set(P_QUESTION, 2);
    return 0;
  }
    
  /* Ask the question and wait for the answer. */
  this_player()->Set(P_QUESTION, 1);
  write("With what? With your bare hands?\n");
  return 1;
}

/*-----------------------------------------------------------------------*/
public int GotAnswer (int bYes)
{
  if (1 == this_player()->Query(P_QUESTION))
  {
    this_player()->Set(P_QUESTION, 2);
    if (bYes)
    {
      write(
"Congratulations! You just vanquished a dragon with your bare hands!\n"
"(Unbelievable, isn't it?)\n"
	   );
      show(this_player()->Query(P_NAME)+" killed the dragon!\n");
      if (!QueryFlag(F_DRAGON))
      {
	SetFlag(F_DRAGON);
        this_player()->AddXP(Query(P_KILL_XP)+5000);
        this_player()->SetExplored();
      }
      LeaveCorpse();
      remove();
    }
    else
      write("Not bloody likely.\n");
    return 1;
  }
  return 0;
}

/*-----------------------------------------------------------------------*/
/* The reception of 'yes' and 'no'.
 */

void _catch_yesno (string msg)
{
  int i;
  string *msgs;

  i = member(msg, ':');
  msgs = norm_id(msg[i+1..<2], 1);
  if ("yes" == msgs[0])
    GotAnswer(1);
  if ("no" == msgs[0])
    GotAnswer(0);
}

public int fyesno (string arg)
{
  return GotAnswer("yes" == query_verb());
}

/*-----------------------------------------------------------------------*/
public varargs int allow_enter (int method, mixed extra)

/* Print a message if someone gives us something.
 * The handling is a bit crude, but for sake of compatibility with
 * the original...
 */

{
  if (M_GIVE == method)
  {
    write("The dragon is implacable.\n");
    return 0;
  }
  return ::allow_enter(method, extra);
}

/*************************************************************************/
