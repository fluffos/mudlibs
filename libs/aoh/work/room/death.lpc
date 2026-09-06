/* Death  (Mateese, 28-Aug-92)
** slighlty updated, Pepel, 8-Jan-95
**
** The final judge itself.
*/

#include <properties.h>   /* for the property names */

inherit "/std/npc";

/*-------------------------------------------------------------------------*/

void create () {

  (::create());

  SetName ("Death");
  AddId ("moot");
  AddId ("scythe");
  AddId ("robe");

  SetShort ("Death, clad in black");

  SetRace ("immortal");

  Set(P_DEFENCES, ({ 50 }) );
  Set(P_HANDS, ({ ({ "right hand", 0, 25 }), ({"left hand", 0, 25 }) }));
}

/*-------------------------------------------------------------------------*/

void init() {
  ::init();
  add_action("take_it", "take");
}

/*-------------------------------------------------------------------------*/

/* hack alert */
nosave private string lastid;
int id(string s) { if (::id(s)) { lastid = s; return 1; } }

varargs string Long (string str) {

  if (lastid == "death" || lastid == "moot")
    return
 "Death seems to have taken Jane Fonda's exercise and diet program much too\n"
"seriously. A clear case of Anorexia Neurosa. Except for a wicked looking\n"
"scythe he's dressed in a black hooded robe that suits him admireably well.\n"
"There's something about his eyes as well, or maybe the lack of eyes, that\n"
"you feel you'd better not investigate too closely.\n";

  if (lastid == "scythe")
    return
"An extremly sharpened scythe. It's so sharp that gusts of wind actually try\n"
"to turn away from the edge rather than be sliced in two by the wicked\n"
"looking blade. It does strange things with light as well as unlucky photons\n"
"split into their sub-components when they hit the blade.\n";

  if (lastid == "robe")
    return
"A black hooded robe with numerous pockets. It doesn't seem to fit you very\n"
"well however. It seems to have been tailored for a very lean customer.\n"
"VERY lean actually...\n";

  return 0;
}

/*-------------------------------------------------------------------------*/

int take_it(string str) {

  if (str == "scythe" || str == "robe") {
    int extra;
    extra = random(90) + 10;
    write (
"You take a firm grip on the " + str + " and try to pull it towards you.\n\n"
"STUPID MORTAL. YOU JUST EARNED " + extra + " EXTRA YEARS IN PURGATORY!\n"
"Death frowns and raps you smartly across your fingers with a bony hand.\n"
          );
    this_player()->SetExplored();
    return 1;
  }
  return 0;
}

/***************************************************************************/
