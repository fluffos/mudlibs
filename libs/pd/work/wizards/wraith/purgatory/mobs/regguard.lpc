#include <std.h>
#include <purgatory.h>
inherit MONSTER;
int bladego();
int i;

void create() {
 ::create();
   set_name("Pugatory Guard");
   set_short("Purgatory Guard");
   set_id(({"monster", "guard"}));
   set_long("This guard keeps a vigilant lookout for trespassers during the day. At night thats another story....");
   set_level(65);
   set("aggressive", 48);
   set_gender("male");
   set_race("human");
   set_heart_beat(1);
   set_body_type("human");
   set_class("fighter");
   set_subclass("antipaladin");
   set_skill("blade", 425);
   set_skill("attack", 350);
   set_skill("stealing", 350);
   set_skill("murder", 350);
   set_skill("defense", 350);
   set_skill("double wielding", 350);
   set_skill("magic defense", 350);
   set_emotes(2,({ "The guard keeps looking over his shoulder for some reason." }),0);
   set_die((:  bladego  :));

new(EQ"dgauntlets")->move(this_object());
force_me("wear gauntlets");

new(EQ"dazzlingleggings")->move(this_object());
force_me("wear leggings");

new(EQ"dazzlingboots")->move(this_object());
force_me("wear boots");

new(WEAP"dazzlingblade")->move(this_object());
force_me("wield blade");

new(WEAP"dazzlingblade")->move(this_object());
force_me("wield blade");

new(EQ"dazzlingarmour")->move(this_object());
force_me("wear armour");
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

  if (present("boots", this_object())) {
      ob = present("boots", this_object());
      catch ( ob->remove() );
   }

  if (present("leggings", this_object())) {
      ob = present("leggings", this_object());
      catch ( ob->remove() );
   }


  if (present("gauntlets", this_object())) {
      ob = present("gauntlets", this_object());
      catch ( ob->remove() );
   }
this_object()->remove();
  return 0;
}
