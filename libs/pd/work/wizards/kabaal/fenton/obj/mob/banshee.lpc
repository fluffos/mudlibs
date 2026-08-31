#include <std.h>;
#include <fenton.h>;
inherit MONSTER;
int i;
void create() {
::create();
    set_name("banshee");
    set_short("%^BOLD%^%^WHITE%^Banshee%^BOLD%^RED%^ (floating)");
    set_long("This is the spirit of an evil female elf.  She hates all that is "
"living.  Her hair is ratty and unkept.  Her dress is tattered and dirty.");
    set_id(({"banshee", "elf"}));
    set_race("elven spirit");
    set_body_type("human");
    set_gender("female");
    set_skill("attack", 250); 
    set_stats("stregnth", 75);
    set_stats("dexterity", 50);
    set_stats("constitution", 60);

  set("aggressive",45);
  set_class("cleric");
    set_level(35);
    set_spell_chance(50);    
    set_spells(({"paralyze"}));
    }
void heart_beat()
{
 ::heart_beat();
 i++;
 if (i > 15) {
    i = 5;
    this_object()->force_me("emote cries out in pain.");
   }
}
