


#ifndef __PLAYER_RESURRECT_H
#define __PLAYER_RESURRECT_H

int resurrect(int percent);

// Von wo darf ein Resurrectt aufgerufen werden
#define RESURRECT_ALLOWED ({\
      "/spellbooks/pal_spells", \
      "/d/astral/lamuerte/brunnen/spellobj/scroll_resurrect",\
      "/d/astral/feyaria/draconia/obj/revive",\
      })
  
#endif
