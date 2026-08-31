#ifndef __OCEAN__D_
#define __OCEAN__D_

#define ICE             4
#define STRONG_CURRENTS 3
#define LAND            2
#define OK_TO_MOVE      1
#define LOOK_LAND       ({"+"})
#define LOOK_REEF       ({"#"})
#define LOOK_WATER      ({"-"})
#define LOOK_VILLAGE    ({"V"})
#define LOOK_ISLE       ({"1","2","3","4","5"})
#define LOOK_SAND       ({"a","b","c","d","e"})
#define LOOK_ISLANDS    LOOK_ISLE + LOOK_SAND

#define SHIP "/wizards/whit/ocean/ship/ship"
#define SHIP_UPGRADES "/wizards/whit/ocean/ship/shipgrades"
#define SHIP_COMBAT "/wizards/whit/ocean/ship/shipcombat"
#define SHIP_DESCRIBE "/wizards/whit/ocean/ship/shipdescribe"
#define DIR_BOATS "/wizards/whit/ocean/save/"

#define ZERO ({ 34, 31 })
#define DAY_EMOTE ({"The waves hit the side of the ship with loud thumps.", \
    "The salty smell of ocean air washes over the ship.", \
    "The sounds of a work on the ship are here.", \
    "The sun gleams brightly over the ocean waters.", \
    })
#define NIGHT_EMOTE ({"The waves gently lap over the side of the ship", \
    "The stars reflect brightly off of the ocean waters.", \
    "The deck of the ship is very quiet.", \
    "The stars reflect brightly off of the ocean waters.", \
    })
#define STORM_EMOTE ({"Storm clouds cover the sky, a grey", \
    "Rain starts pouring from the skies, making it hard to navigate.", \
    "There is a slight breakup in the rain.  The deck of the ship is soaked.", \
    "The sky can be seen just for a moment, but it covered back up by the clouds.", \
    })
#define EMOTE_TIME 60
#define STATIC_SHIPS ([])


/*
#define STATIC_SHIPS ([ \
    "ghost" : ([ \
        "owner":"", \
        "coords":({1,1}), \
        "room":"Room to go to." \
    ])\
])
*/

#endif
