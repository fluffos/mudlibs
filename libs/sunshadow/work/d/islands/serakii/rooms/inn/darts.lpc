#include <std.h>
#include "../../serakii.h"


inherit VAULT;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_name("dark room in the Rook's Rest");
   set_short("%^C059%^dark room%^C061%^ in the Rook's Rest%^CRST%^");
   set_long("%^C094%^This smaller room off of "+
   "the inn is cozier and has a number of "+
   "%^C059%^small booths%^C094%^ along the wall "+
   "for more private dining and drinking. Along "+
   "the south wall a large area has been cleared "+
   "and a %^C254%^dart board%^C094%^ has been hung. "+
   "Over the dart board a %^C180%^backpack %^C094%^has "+
   "been nailed to the wall. There is a small %^C059%^staircase %^C094%^that "+
   "looks to lead to the second floor of the inn.\n%^CRST%^");


set_items(([
		({"backpack"}) : "%^C143%^Strangely, what looks like a backpack made of a giant creature's testicles has been hung over the dart board. It seems either the players here are really bad or there is some meaning behind the backpack because a good number of darts have impacted on the rough wrinkly skin%^CRST%^",
		({"walls","wall"}) : "%^C246%^The walls "+
	   "are formed from %^C243%^giant stone "+
	   "blocks%^C246%^. They are thick and strong "+
	   "enough to protect you from anything "+
	   "happening outside.%^CRST%^\n",
       ({"sconces","crystals"}) : "%^C242%^Iron "+
	   "sconces%^C246%^ line the walls at regular "+
	   "intervals, filled with %^C092%^sma%^C165%^"+
	   "l%^C092%^l glow%^C165%^i%^C092%^ng cryst%^C165%^"+
	   "a%^C092%^ls%^C056%^ %^C246%^that fill the "+
	   "room with %^C165%^g%^C093%^e%^C165%^ntle lig%^C093%^h%^C165%^t%^C246%^.%^CRST%^\n%^CRST%^",
]));

set_smell("default","%^C058%^You smell %^C125%^"+
"rich food%^C058%^ and %^C094%^wood fire%^CRST%^");
set_listen("default","%^C061%^You hear %^C063%^constant "+
"conversation%^C061%^ around you%^CRST%^");



    set_exits(([
                   "west" : INN"inn",
				   "up" : INN"landing",
        ]));


}

void init() {
   ::init();
   add_action("read", "read");
}

void reset() {
    object ob;
  ::reset();
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("rooks_rest");
        ob->move(TO);
    }
}

 int read(string str) {
    object ob; 
    string stuff,*names;
    int length, x;

    
    if(str == "list" && ob = present("dartboard")) {
        write("This is a list of those who have been witnessed achieving a mastery at darts here in Rooks Rest.");
        names = ob->query_mastery_list();
        if(!sizeof(names)) { 
            return 1;
        }
        for(x = 0;x < sizeof(names);x++) {
            tell_object(TP,"%^BOLD%^%^GREEN%^"+capitalize(names[x])+"%^RESET%^\n");
        }
        return 1;
    }

}