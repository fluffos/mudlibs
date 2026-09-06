/* Advent - The Grate -- Mateese, 14-Aug-96
 *
 * This is the grate blocking the entrance to the Cave. It can be unlocked
 * using the keys from r/subtwell. True Spelunkers can pass it anyway :-)
 * It needed to be an own object to add a subdetail to it.
 */

#include <properties.h>
#include <lock.h>
#include <doors.h>
#include "advent.h"

inherit "/obj/door";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public int CheckAction (string method, string verb, string arg) 

/* The grate can't block players which already solved the cave.
 */

{
  if ("block" == method && QueryFlag(F_SOLVED, this_player()))
  {
    write("The bars are indeed immaterial and don't block your way.\n");
    return 0;
  }
  return ::CheckAction(method, verb, arg);
}

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_SHORT, "a steel grate");
  Set(P_LONG,
"It is a streel grate, mounted into rocks.\n"
     );
  AddId(({"grate", "\nadventgrate"}));
  AddAdjective("steel");
  Set(P_DOORCODE, "\nadventgrate");
  Set(P_CHECKDOOR, DACT_CHECK);
  Set(P_WEIGHT, 300000);
  Set(P_KEYCODE, ADV_GRATE_KEYCODE);
  Set(P_LOCKSTATE, LOCK_LOCKED);
  Set(P_PICK_CHANCE, 30);
  Set(P_KEYIDS, ({ "key", "keys" }));
  AddSubDetail( ({ "bar", "bars" }),
"The bars of the grate are tightly spaced and firm.\n"
	      );
}

/*-----------------------------------------------------------------------*/
public string DetailBars()

/* Hint to true Spelunkers that they can pass the grate without
 * unlocking.
 * This description is replicated in r/subtoutgrate.
 */

{
  if (!QueryFlag(F_SOLVED, this_player()))
    return
"The bars of the grate are tightly spaced and firm. A sign has been affixed "
"to them.\n"
    ;
  return
"The bars of the grate are tightly spaced, but look immaterial. "
"A sign has been affixed to them.\n"
  ;
}

/*-----------------------------------------------------------------------*/
public void Aloha (int flag)

/* In r/subtoutgrate, add a sign to the grate.
 */

{
  ::Aloha(flag);

  if (ADVENT("r/subtoutgrate") == to_string(environment(this_object())))
  {
    string msg;
      
    Set(P_LONG,
"It is a streel grate, mounted into rocks. A sign has been affixed "
"to one of the bars.\n"
       );
    AddSubDetail( ({ "bar", "bars" }), #'DetailBars);

    /* The following message is replicated in r/subtoutgrate */
    msg = "\n"
          "    +-----------------------+\n"
          "    |       Warning!        |\n"
          "    | Uncharted Cave ahead. |\n"
          "    |  Enter at own risk.   |\n"
          "    +-----------------------+\n"
          "\n"
          "  Biontic Magics & Excavations\n"
	  "\n"
	  ;

    AddSubDetail("sign", msg);
    AddSubReadMsg("sign", msg);
  }
}

/*************************************************************************/
