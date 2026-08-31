#include <std.h>

inherit MONSTER;
int ran;
void create() {
 ::create();
   set_short("a large raccoon");
   set_id(({ "raccoon" }));
   set_name("raccoon");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
   set_long("A large raccoon with grey fur with black rings around "
            "it's tail and a black mask around it's eyes.");
   set_body_type("canine");
   set_race("raccoon");
  if (!random(2))
   set_gender("male");
  else
   set_gender("female");
   set_alignment(25);
   add_money("gold", random(20));
}
