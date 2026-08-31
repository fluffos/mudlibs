
/* shore.h */

#include "/players/whisky/genesis/sys/filter_live.h"
#include "/players/whisky/genesis/sys/break_string.h"


#define _tp   this_player()
#define _tpn  _tp->query_name()
#define _tpp  _tp->query_possessive()
#define _wiz  "/players/whisky/"
#define _dir  "/players/whisky/mordor/shore/"
#define _obj  "/players/whisky/mordor/obj/"
#define _mob  "/players/whisky/mordor/mob/"
#define BS(x) break_string(x+"\n",68)


#define SHOREDESC\
 "You are standing on the sandy beach of a big island. The "+\
 "sky is a bit cloudy and the waves are rocking against steep "+\
 "shore. There are seagulls flying in circles around the cliffs "+\
 "reaching out of the dark blue sea. The sand is dark like the  "+\
 "ash of a volcano. There are skeletons of fish lying around. " 

#define ITEMDESC\
  ({ "beach","The beach is covered with stinking fishbone and\n"+\
             "dark sand",\
     "sand","The sand is dark, wet and stinking",\
     "seagulls","They are flying in circles around the sharp rocks\n"+\
                "reching out of the water.",\
     "sea","The sea is dark blue and there is a fouly smell in the air",\
     "cliffs","You see sharp, dark cliffs reaching out of the water",\
     "skeletons","Skeletons of dead fish, but somehow they seem to move",\
  })
