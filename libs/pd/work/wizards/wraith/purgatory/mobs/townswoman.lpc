#include <std.h>
#include <purgatory.h>
inherit MONSTER;
int staffgo();
int i;

void create() {
 ::create();
   set_name("Purgatory Townswoman");
   set_short("Purgatory Townswoman");
   set_id(({"townswoman", "woman", "monster"}));
   set_long("%^BOLD%^%^WHITE%^This woman lives in Purgatory, her eyes are searching"
            "%^BOLD%^%^WHITE%^ around for more children so she can make clothes for her husband.");
   set_level(40+random(20));
   set_hp(4000);
   set_skill("blunt",351);
   set_gender("female");
   set_race("human");
   set_heart_beat(1);
   set_body_type("human");
   set_exp(18500);
   set_emotes(2,({ "%^BOLD%^%^WHITE%^The Townswoman searches frantically for more children. " }),0);
   set_die((:  staffgo  :));

new(EQ"searrings")->move(this_object());
force_me("wear earrings");

new(EQ"bdress")->move(this_object());
force_me("wear dress");

new(EQ"phat")->move(this_object());
force_me("wear hat");

new(EQ"sgloves")->move(this_object());
force_me("wear gloves");

new(EQ"mboots")->move(this_object());
force_me("wear boots");

new(WEAP"gstaff")->move(this_object());
force_me("wield staff");

new(WEAP"gstaff")->move(this_object());
force_me("wield staff");


}
int staffgo() {
object ob;
   tell_room(environment(this_object()),"The townswoman screams bloody murder as she dies.", ({ }));
  if (present("staff", this_object())) {
      ob = present("staff", this_object());
      catch ( ob->remove() );
   }

  if (present("staff", this_object())) {
      ob = present("staff", this_object());
      catch ( ob->remove() );
   }
this_object()->remove();
  return 0;
}
