#include <std.h>
#include <arlon.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "A green snake", "A rattle snake", "A cobra snake",
           "A king snake" });

 i = random(sizeof(name));
   set_name("snake");
   set_short(name[i]);
  set_level(i+3);
   set_race("snake");
   set_body_type("snake");
   set_gender("male");
   set_id(({ "snake", name[i] }));
 if (name[i]=="A green snake")
   set_long("The green snake slithers around trying to wrap around "
            "your leg to suffocate it. The green scales around it "
            "serve as good protection.");
 if (name[i]=="A rattle snake")
   set_long("The rattle snakes rattler shakes and the noise like "
            "a musical instrument.");
 if (name[i]=="A cobra snake")
   set_long("The cobra snake is one big snake. It doesnt seem to be "
            "very happy about your presence for it is trying to stick "
            "its venomous teeth into you.");
 if (name[i]=="A king snake")
   set_long("The king snake is huge! The snake sits wrapped up in itself "
            "pretending it is asleep, and waiting to lash out and attack.");

 new( WEA "fangs" )->move(this_object()); 
 this_object()->force_me("wield fangs");
}

