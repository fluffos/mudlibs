//Tirun Sewers lv 2
//By Nightshade

#include <std.h>
#include <sewer.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Tirun Sewers");
    set_properties( (["light" : 1, "night light" : 0]) );
    set_property("indoors", 1);
    set_listen("default", "Drip..    Drip..    Drip..");
    set_smell("default", "The air is heavy with a foul stench.");
    set_long("This level of the sewers seems to have been abandoned for ages.  "+
             "Who knows what kind of strange creatures may live down here.  "+
             DESCRIPTOR->do_descript()+
             "A hole is in the ceiling here.");
    set_exits( (["north" : ROOMS+"2lv10"
             ,"west" : ROOMS+"2lv16"
             ,"east" : ROOMS+"2lv18"
             ,"south" : ROOMS+"2lv24"
              ]) );
    set_items( ([ "grate" : "%^ORANGE%^The rusty grate would do no one any good."
                 ,({"muck","floor"}) : "A thick layer of muck makes walking difficult."
                 ,"slime" : "%^GREEN%^It slowly oozes, leaving a trail along the wall."
                 ,"hole" : "There are many small holes everywhere in the sewers."
                 ,"water" : "The water drips from small cracks in the ceiling."
                 ,"junk" : "This is all trash that people have thrown down here "
                           "because they've been too lazy to put it in a trash container."
                 ,"hole" : "You could probably climb out if you needed to get out of here."
                 ]) );
}

void init() {
  ::init();
  add_action("climb", "climb");
}

int climb(string str) {
  if(str != "out")
    return 0;
  write("You pull yourself out of the slime of the lower level.");
  this_player()->move_player(ROOMS"33", "through the hole");
  return 1;
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
                new(MOB+"wererat")->move(this_object());
            else if(x < 35)
                new(MOB+"mansnake")->move(this_object());
            else if(x < 40)
                new(MOB+"bigooze")->move(this_object());
            else if(x < 45)
                new(MOB+"adultwyrm")->move(this_object());
            else
                new(MOB+"mslug")->move(this_object());
        x = random(50);
        if(present("monster 5",this_object()))
            break;
        }
    }
}
