//Tirun Sewers
//By Nightshade

#include <std.h>
#include <sewer.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Tirun Sewers");
    set_properties( (["light" : 1, "night light" : 1]) );
    set_property("indoors", 1);
    set_listen("default", "Drip..    Drip..    Drip..");
    set_smell("default", "The air is heavy with a foul stench.");
    set_long(DESCRIPTOR->do_descript());
    set_exits( (["north" : ROOMS+"39"
             ,"west" : ROOMS+"1"
             ,"east" : ROOMS+"3"
             ,"south" : ROOMS+"4"
              ]) );
    set_items( ([ "grate" : "%^ORANGE%^The rusty grate would do no one any good."
                 ,({"muck","floor"}) : "A thick layer of muck makes walking difficult."
                 ,"slime" : "%^GREEN%^It slowly oozes, leaving a trail along the wall."
                 ,"hole" : "There are many small holes everywhere in the sewers."
                 ,"water" : "The water drips from small cracks in the ceiling."
                 ,"junk" : "This is all trash that people have thrown down here "
                           "because they've been too lazy to put it in a trash container."
                 ]) );
}

void reset() {
    int x;
    ::reset();

    if(sizeof(query_destinations()))
    if(sizeof(all_inventory(get_object(this_object()->query_destinations()[0]))))
      return;

    if(!present("monster",this_object())) {
        x = random(40)+10;
        while(x >= 25) {
            if(x < 30)
                new(MOB+"rat")->move(this_object());
            else if(x < 35)
                new(MOB+"snake")->move(this_object());
            else if(x < 40)
                new(MOB+"ooze")->move(this_object());
            else if(x < 45)
                new(MOB+"wyrm")->move(this_object());
            else
                new(MOB+"slug")->move(this_object());
        x = random(50);
        if(present("monster 5",this_object()))
            break;
        }
    }
}
