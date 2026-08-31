
/* defines for the monksoul */

#include "/players/whisky/genesis/sys/break_string.h"

#define BS(x) break_string(x+"\n",68);

#define _tp   this_player()
#define _tpn _tp->query_name()
#define _tpr _tp->query_real_name()
#define _tpp _tp->query_possessive()
#define _tpl _tp->query_level()
#define _tpo _tp->query_pronoun()
#define _tps _tp->query_sp()
#define _tph _tp->query_hp()
#define _tpw _tp->query_wis()
#define _tpd _tp->query_dex()
#define _tpi _tp->query_int()
#define _tpc _tp->query_con()
#define _e   environment
#define _obj "/players/whisky/guild/obj/"
#define _shad "/players/whisky/guild/shadows/"
#define _gm  "/guild/master"

//##m##
#define HEAL _tp->query_wis()*8
#define CURE HEAL/2
#define AID  HEAL/4

#define _spells\
        ({"death","smash","choke","meditate","feet","springleap",\
          "aikido"})

mixed _chk_ghost()
{
      if (_tp->query_ghost())
      {
         notify_fail("");
         return 0;
      }
}
