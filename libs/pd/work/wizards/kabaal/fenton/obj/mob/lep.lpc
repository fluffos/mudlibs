#include <std.h>
#include <fenton.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("leprechaun");
   set_short("Leprechaun");
   set_id(({"leprechaun"}));
   set_long("This old and wise man is in a bit of a jam.  His son has "
            "been terrorizing the whole city, and is worried something "
	    "may happen to that little guy. ");
  set_class("mage");
  set_subclass("wizard");   
  set_level(38);
    set_spell_chance(65);    
    set_spells(({"bolt", "missile"}));
   set_gender("male");
   set_race("leprechaun");
   set_heart_beat(1);
   set_body_type("human");
    add_money("gold", 495);
   new("/wizards/kabaal/fenton/obj/arm/suit")->move(this_object());
   this_object()->force_me("wear suit");
 }

void heart_beat()
{
 ::heart_beat();
 i++;
 if (i > 10) {
    i = 5;
    this_object()->force_me("emote worries about his son.");
   }
}
