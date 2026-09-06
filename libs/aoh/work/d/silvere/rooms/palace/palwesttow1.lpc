// The western tower of the palace, royal guard HQ
// created:       Taurec   [11-May-1998]
// last changed:

// TODO: Add "real" Windows and Details, Timedesc
// TODO: Add takeable banners :)
// TODO: Someone who climbs through the window should crash
// TODO: through the roof into another palaceroom :)

#include <nightday.h>
#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The royal guard's HQ");
   Set(P_INT_LONG,
    "Banners, pictures that depict battles, crossing spears and "
    "polished shields adorn this room's walls. This must be the "
    "office of a highgrade officer of the royal guard. Almost "
    "hidden behind two big pennants there's a desk with a little sign "
    "on it. A stairway leads further up to the towertop and down "
    "to the armoury. @@TimeMsg@@ On one wall there's a board with "
    "several notes on it.\n");
   Set(P_TIME_MSG,
     ([DAY_DEFAULT_MSG:
        "Through several huge windows, you've got a beautiful view over "
        "the surrounding city and landscape.",
       NIGHT_DEFAULT_MSG:
        "The torches in the wall enlighten the room and "
        "through the big windows, you see lots of cozy lights coming out "
        "of hundreds of homes down there in the city. Above, thousands of "
        "stars illumine the sky."
     ]));
   Set(P_INT_WIZMSG,
" Up   : To the towertop. \n"
" Down : back to the armoury of the palace.\n");


   AddDetail(({"board"}),"Lot's of \"wanted\" posters and similar "
    "notes are on the board. You could try to read them.\n");
   AddDetail(({"posters","notes","poster","note"}),
    "One of them catches your eye. You might read it.\n");
   AddReadMsg(({"posters","notes","poster","note"}),
    "\n                 WANTED!\n"
    "        DEAD or alive (better dead).\n"
    "A band of smugglers make our harbour insecure.\n"
    "Everyone who has hints about the whereabouts of \n"
    "these criminals will be kingly REWARDED. Please \n"
    "inform Capt. Ayerson about everything you know.\n\n"
    "Capt. Luminor Ayerson, chief of Royal Guard, HQ.\n");
   AddDetail(({"banners","banner"}),"Banners of all sizes adorn "
    "the room. Most of them show the four petrified griffins of "
    "Silvere.\n");
   AddDetail(({"spear","spears"}),"A layer of dust covers these "
    "spears. You conclude that they are out of use since a long "
    "time. They're fixed firmly to the wall.\n");
   AddDetail(({"shields","shield"}),"The shields are now only "
    "for decorate purposes. Scratches and dents suffuse their "
    "surface, coming from heavy use. They're fixed firmly to the "
    "wall.\n");
   AddDetail(({"pennants","pennant"}),"These two pennants hang "
    "down from the desk, showing - what else - those griffins "
    "of Silvere again.\n");
   AddDetail(({"desk","table"}),"Lots of official scrolls and forms "
    "cover the desk. There are also maps of the city and the "
    "surrounding area on it. Letters with the royal seal lie "
    "here and there, spread over the table orderless.\n");
   AddDetail(({"picture","pictures"}),"Most of these pictures "
    "show scenes of battles and brave heroic heros fighting against "
    "hordes of dark hooded riders and other oozy looking entities, "
    "and - of course - several poor dragons wondering about why "
    "there's suddenly a sharp spear or sword sticking in their "
    "throat, while some ant-like thing scurries around its legs.\n");
   AddDetail(({"staircase","stairs","flight","stairway"}),
     "The staircase leads upwards and downwards in a tight spiral.\n");
   AddDetail(({"wall","walls"}),"The walls are adorned by tons of "
     "banners, crossing spears, pictures and polished shields. "
     "There's nothing special to them.\n");
   AddDetail(({"sign","little sign","small sign"}),
    "Is a little sign. There's something written on it.\n");
   AddReadMsg(({"sign","little sign","small sign"}),
    "Cpt. Luminor Ayerson, Royal Guard HQ.\n");

   AddWindow("window",
             "It's a big window with a wooden frame. You've got "
             "a nice view over the whole complex of the palace. "
             "Hmm... perhaps you could climb through it?\n",
             SIL_PALACE("palfall1"));
//             ([PV_WINDOW_OTHERLONG:
//               "Deep below you see the palace square. This is for "
//               "sure not the best place to do a belly landing.\n"
//             ]));

   AddItem(NPC("rg_chief"),REFRESH_REMOVE,1);

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -30,20,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
    "You walk into the wall like an idiot. Somehow you have the "
    "feeling, that everyone laughs at you.\n");
   AddExit("down", SIL_PALACE("palwest11"));
   AddExit("up", SIL_PALACE("palwesttow2"));
}
