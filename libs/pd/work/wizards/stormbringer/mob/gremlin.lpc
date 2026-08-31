#include <std.h>
#include <rain.h>
inherit MONSTER;

void create()
{
   ::create();
   set_name("Gremlin");
   set_short("Gremlin");
   set_long("A short forest Gremlin, which happens to have little but"
" very sharp teeth, and long and very sharp claws. This"
            " Gremlin also seems to hve tough skin");
   set_id(({"gremlin", "monster"}));
   set_gender("male");
   set_class("fighter");
   set_level(25);
   set_race("centaur");
   set_body_type("centaur");
   new(OBJ"chainmail")->move(this_object());
   new(WEA"ssword")->move(this_object());
   this_object()->force_me("wear chainmail");
   this_object()->force_me("wield sword"); 
}
