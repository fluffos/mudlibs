#include <std.h>
inherit MONSTER;
void create() {
    string *name;
    int i;

    ::create();

    name = ({ "wolf hunter", "wolverine hunter", "deer hunter",
      "gorilla hunter", "huge hunter", " hunter",
      "grunt hunter", "snake hunter", "bear hunter"});

    i = random(sizeof(name));
    set_name("Hunter");
    set_short(name[i]);
    set_level(i+40);
    set("aggressive", (i+25) );
    set_race("elf");
    set_body_type("elf");
    set_gender("male");
    new("/wizards/detach/forbiden/obj/a8")->move(this_object());
    new("/wizards/detach/forbiden/obj/a9")->move(this_object()); 
    new("/wizards/detach/forbiden/obj/1")->move(this_object());
    new("/wizards/detach/forbiden/obj/1")->move(this_object());  
    this_object()->force_me("wear cloak");
    this_object()->force_me("wear boots");
    this_object()->force_me("wield pike");
    this_object()->force_me("wield pike 2");
    set_id(({ "hunter", name[i] }));
    set_long("This hunter is one of the many mystical hunters "
      "of the forbidden forest.");

}

