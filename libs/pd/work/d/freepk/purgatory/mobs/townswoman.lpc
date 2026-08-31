#include <std.h>
#include <purgatory.h>
inherit MONSTER;
int staffgo();

void create() {
 ::create();
   set_name("Purgatory Townswoman");
   set_short("Purgatory Townswoman");
   set_id(({"townswoman", "woman", "monster"}));
   set_long("%^BOLD%^%^WHITE%^This woman lives in Purgatory, her eyes are searching"
            "%^BOLD%^%^WHITE%^ around for more children so she can make clothes for her husband.");
    set_level(65+random(10));
   set_gender("female");
   set_race("human");
   set_body_type("human");
   set_emotes(2,({ "%^BOLD%^%^WHITE%^The Townswoman searches frantically for more children. " }),0);

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
