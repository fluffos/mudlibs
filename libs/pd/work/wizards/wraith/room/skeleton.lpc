#include <std.h>
#include <purgatory.h>
inherit MONSTER;
int slimego();
int i;

void create() {
 ::create();
   set_name("%^BOLD%^%^BLACK%^A Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^");
   set_short("%^BOLD%^%^BLACK%^A Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^");
   set_id(({"skeleton", "monster", "guard"}));
   set_long("%^BOLD%^%^BLACK%^Risen from the grave, this skeleton is forced by Death to guard his city.");
   set_level(90);
   set("aggressive", 120);
   set("magic defense", 350);
   set_gender("dead");
   set_race("skeleton");
   set_heart_beat(1);
   set_body_type("human");
   set_class("mage");
   set_skill("agility", 280);
   set_skill("defense", 280);
   set_skill("attack",300);
   set_skill("magic defense",400);
   set_skill("faith",300);
   set_emotes(2,({ "The clunk of bones can be heard as the guard makes his patrol." }),0);
   set_die((:  slimego  :));

new(EQ"skeletoncloak")->move(this_object());
force_me("wear cloak");

new(EQ"skeletonboots")->move(this_object());
force_me("wear boots");

new(EQ"slime")->move(this_object());
force_me("wear slime");

new(EQ"eyeearrings")->move(this_object());
force_me("wear earrings");

new(EQ"skeletongloves")->move(this_object());
force_me("wear gloves");

new(EQ"earbelt")->move(this_object());
force_me("wear belt");


}
int slimego() {
object ob;
   tell_room(environment(this_object()),"%^BOLD%^%^WHITE%^The skeleton turns to dust as it dies.", ({ }));
  if (present("slime", this_object())) {
      ob = present("slime", this_object());
      catch ( ob->remove() );
   }

  if (present("boots", this_object())) {
      ob = present("boots", this_object());
      catch ( ob->remove() );
   }

  if (present("cloak", this_object())) {
      ob = present("cloak", this_object());
      catch ( ob->remove() );
   }

  if (present("gloves", this_object())) {
      ob = present("gloves", this_object());
      catch ( ob->remove() );
   }
this_object()->remove();
  return 0;
}
