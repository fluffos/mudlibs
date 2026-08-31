#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("jake");
    set_short("Jake the Metalhead");
    set_long("Jake is a short buff metalhead.");
    set_id(({"jake", "metalhead"}));
    set_level(50);
    set_race("human");
    set_body_type("human");
    set_gender("male");

    add_money("gold", 10000);     
    add_money("platinum", 5000);

    set_skills(({"attack", 500, "melee", 500,);    
    set_stats("strength", 50);  

    set_spell_chance(80);       
    set_spells(({"headbutt", "jab", "rush"}));    
    
    new("/wizards/leviathas/arm/bracelet1") ->move(this_object());
    command("wear vest");
    if(random(2))  {
      new("/wizards/leviathas/arm/jrsboots2") ->move(this_object());
      command("wear boots");
    }

  
   
