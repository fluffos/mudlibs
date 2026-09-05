/*
 * death_mark.c
 */

#include <message.h>

#include "death.h"

inherit "basic/autoload";

private void
start_death()
{
  object my_host;
  if ((!my_host = environment()) && !interactive(my_host))
    return;
  message(({
    ({ M_INDENT,0,M_SAY,"You see a dark shape gathering some mist... "
       "or maybe you're just imagining that..." }),
    ({ M_INDENT,0,M_WRITE,"You can see a dark hooded man standing "
       "beside your corpse. He is wiping the bloody blade of a wicked "
       "looking scythe with slow measured motions. Suddenly he stops "
       "and seems to look straight at you with his empty... no, not "
       "empty but... orbs...\n" }),
    ({ M_WRITE,"Death says: COME WITH ME, MORTAL ONE!\n" }),
    ({ M_WRITE,"He reaches for you and suddenly you find yourself in "
       "another place.\n" })
  }));
  my_host->move_living(0,DEATH_HOME);
}

void
init()
{
  if (environment() != this_player())
    return;
  start_death();
}

status
prevent_move(object from,object to)
{
  if (!clonep() || from)
    return 1;
}
