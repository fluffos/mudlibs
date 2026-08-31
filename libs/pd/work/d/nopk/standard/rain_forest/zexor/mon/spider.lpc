#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("spider");
   set_short("A large %^BOLD%^%^BLACK%^black %^RESET%^and %^RED%^red%^RESET%^ spider");
   set_long("This is a large spider with a black and white "
       "body and fur. It looks very poisonous."); 
   set_level(35);
   set_id(({"spider", "large spider", "monster"}));
   set_body_type("arachnid");
   set_race("spider");
   new(OBJ"antana")->move(this_object());
}
