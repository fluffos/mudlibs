#include <std.h>
inherit MONSTER;

void create()
{
   ::create();
   set_name("Gremlin");
   set_short("Morgoth's Helper, Darknight");
   set_long("A short forest Gremlin, which happens to have little but"
" very sharp teeth, and long and very sharp claws. This"
            " Gremlin also seems to hve tough skin");
      set_id(({"gremlin", "monster", "darknight", "helper"}));
   set_gender("male");
   set_class("fighter");
   set_level(10);
   set_race("gremlin");
   set_body_type("human");
   new("/wizards/morgoth/chainmail")->move(this_object());
   new("/wizards/morgoth/ssword")->move(this_object());
   this_object()->force_me("wear chainmail");
   this_object()->force_me("wield sword"); 
}
