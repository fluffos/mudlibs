#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("Desks are all arranged in rows, with a writing board at the front of the room.  "
      "Students sit attentively as their teacher instructs them in the arcane arts.  Each student "
      "carefully waves their wand, trying to levitate themselves.  Most of the students are sitting, "
      "unable to overcome the force of gravity.  Others have plastered themselves to the ceiling, "
      "summoning too much force beneath them.");
    set_exits( ([ "northeast" : ROOMS "mtower23",
                  "southeast" : ROOMS "mtower21" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items((["desks" : "The desks are small, and probably designed for younger pupils.",
        "glasses" : "Small glasses resting on the student's desks.  They're filled with various fluids."
    ]));
}

void reset() {
    object ob;
    ::reset();
    if(!present("teacher", this_object())) {
      ob = new(MOB"tmage");
      ob->set_short(ob->query_short()+ " (levitating)");
      ob->move(this_object());
    }
    if(!present("studying mage", this_object())) {
      ob = new(MOB"smage");
      ob->set_short(ob->query_short()+ " (levitating)");
      ob->move(this_object());
      ob = new(MOB"smage");
      ob->force_me("sit");
      ob->move(this_object());
      if(random(4) == 0)
        new(MOB"smage")->move(this_object());
    }
}
