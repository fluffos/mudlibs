#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("necromancer");
    set_short("Isbar, the Powerful Necromancer");
    set_long("He looks you over and cackles like a mad man.  His "
"voice is hoarce, and he looks like he's about 300 years old.");
    set_id(({"isbar", "necromancer", "powerful necromancer"}));
    set_race("drow elf");
    set_body_type("human");
    set_gender("male");
    add_money("gold", 5450);
    add_money("platinum", 1500);
    set_skill("magic attack", 300); 
    set_stats("stregnth", 500);
    set_stats("dexterity", 500);
    set_stats("constitution", 500);
    set_stats("intelligence", 500);
    set_stats("wisdom", 500);
    set("aggressive",500);
    set_class("mage");
    set_subclass("necromancer");
    set_level(1000);
    set_spell_chance(100);    
    set_spells(({"shadowburst", "bolt"}));
new("/wizards/kabaal/fenton/obj/wep/immstaff")->move(this_object());
this_object()->force_me("wield staff");
    }
