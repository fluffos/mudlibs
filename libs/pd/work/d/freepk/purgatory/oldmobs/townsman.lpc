#include <std.h>
#include <purgatory.h>
inherit MONSTER;
int bladego();

void create() {
 ::create();
   set_name("Purgatory townsman");
   set_short("Purgatory townsman");
   set_id(({"townsman", "man"}));
   set_long("%^BOLD%^%^BLACK%^Strung out and weary, this townsman looks to be at his wits end."
            "%^BOLD%^%^BLACK%^ His eyes search around like a frightened cat.  ");
   set_level(45+random(15));
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_emotes(2,({ "The townsman keeps looking at his watch anxiously." }),0);
   set_die((:  bladego  :));
new(EQ"dleggings")->move(this_object());
force_me("wear leggings");
new(EQ"ccloak")->move(this_object());
force_me("wear cloak");
new(EQ"bboots")->move(this_object());
force_me("wear boots");
new(WEAP"fblade")->move(this_object());
force_me("wield blade");
new(WEAP"fblade")->move(this_object());
force_me("wield blade");
new(EQ"dgauntlets")->move(this_object());
force_me("wear gauntlets");
}
int bladego() {
object ob;
   tell_room(environment(this_object()),"The townsman yells into your face as he dies.", ({ }));
  if (present("blade", this_object())) {
      ob = present("blade", this_object());
      catch ( ob->remove() );
   }
  if (present("blade", this_object())) {
      ob = present("blade", this_object());
      catch ( ob->remove() );
   }
//this_object()->remove();
  return 1;
}
