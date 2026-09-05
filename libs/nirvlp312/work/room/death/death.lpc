/*
 * death.c - Death incarnate
 */

#include <message.h>
#include <skilltree.h>

#include "death.h"

inherit "obj/monster";

void
configure()
{
  monster::configure();
  set_name("Death");
  set_living_name("moot");
  set_id(({ "moot","death" }));
  set_short("Death, clad in black");
  set_long("Death seems to have taken Jane Fonda's exercise and diet program "
           "much too seriously. A clear case of Anorexia Neurosa. Except for "
           "a wicked looking scythe he's dressed in a black hooded robe that "
           "suits him admireably well. There's something about his eyes as "
           "well, or maybe the lack of eyes, that you feel you'd better not "
           "investigate too closely.\n");
  set_items(({ "scythe",
           "An extremely sharpened scythe. It's so sharp that gusts of "
           "wind actually try to turn away from the edge rather than be "
           "sliced in two by the wicked looking blade. It does strange "
           "things with light as well as unlucky photons split into their "
           "sub-components when they hit the blade.\n",
           "robe",
           "A black hooded robe with numerous pockets. It doesn't seem to "
           "fit you very well however. It seems to have been tailored for "
           "a very lean customer. VERY lean actually...\n" }));
  set_race("living");
  set_tongue("common");
  set_skill(S_COMMON, 50);
  set_level(999);
  set_male();
  set_ac(50);
  set_wc(50);
  move_living("X",DEATH_HOME);
}

void
init()
{
  monster::init();
  add_action("my_take","take");
  add_action("my_take","get");
}

status
my_take(string str)
{
  if (str == "scythe" || str == "robe")
  {
    message(({
      ({ M_WRITE,"You take a firm grip on the ",str," and try to pull "
     "it towards you." }),
      ({ M_WRITE,"Death frowns, raps you smartly across your fingers "
     "with a bony hand and says: STUPID MORAL. YOU JUST EARNED ",
     (random(90)+10)," EXTRA YEARS IN PURGATORY!" })
    }));
    return 1;
  }
}

status
prevent_move(mixed from,mixed to)
{
  if (to)
  {
    if (objectp(to))
      to = load_name(to);
    if (to == DEATH_HOME)
      return 0;
  }
  return 1;
}
