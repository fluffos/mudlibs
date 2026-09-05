#pragma strong_types

#include <event.h>
#include <message.h>

inherit "/complex/spell";

void create()
{
  ::create();
  set_author	("Mentar");
  set_spell	("Travelling Torch");
  set_art	("fiat");
  set_lore	("ignis");
  set_level	(10);
  set_cost	(30);
  set_delay	(5000);
  set_info	("This spell creates a lit torch out of thin air. Nothing \
more, nothing less.");
}

int init_spell (mapping event)
{
  message (({({ M_WRITE, "You concentrate on the ignis runes and wave ",
		"the fiat gestures." }),
  	     ({ M_SAY, M_PL, M_PL_VERB, "wave", " ", M_PL_POSSESSIVE,
		" hands in the air and", M_PL_VERB, " close", M_PL_POSSESSIVE,
		" eyes." })}));
  return 1;
}

int start_spell (mapping event)
{
  switch(event[E_SUCCESS])
  {
    case -99..-1:       message (({({ M_WRITE, "Nothing happens." })}));
			cancel_event();
			return 0;
    default:		message (({({ "Suddenly, the air between ", M_PL_S,
				" hands begins to glow." })}));
  }
  return 1;
}

int execute_spell (mapping event)
{
object torch;

  message (({({ "A torch appears in ", M_PL_S, " hands." })}));
  torch = clone_object ("/complex/lamp");
  torch->set_fill_level (({"spent", "nearly spent", "half spent",
			 "slightly spent", "brand new"}));
  torch->set_light_levels (({"not lit", "lit"}));
  torch->set_id(({"travelling torch","torch"}));
  torch->set_short("a torch");
  torch->set_long("It looks like an ordinary torch. ");
  torch->set_encumbrance(1500);
  torch->set_value(50);
  torch->set_max_fuel(2500);
  torch->set_fuel(2500);
  switch(transfer(torch, this_player()))
  {
    case 0:	break;
    default:	message (({({ M_THE, torch, " seems to be too heavy for ",
    			M_PL, " to carry. It falls down to the ground." })}));
		move_object (torch, environment(this_player()));
		break;
  }
  torch->lamp_light();
  return 1;
}
