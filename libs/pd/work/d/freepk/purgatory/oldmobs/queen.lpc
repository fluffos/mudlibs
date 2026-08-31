#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Queen Shorla");
   set_short("Queen Shorla");
   set_id(({"monster", "queen", "shorla", "Shorla"}));
   set_long("Gracefully sitting next to her King, the Queen has a bored look on her face"
            " as she looks around the court for more playthings.");
   set_level(80);
   set_gender("female");
   set_race("archangel");
   set_body_type("sauran");
   set_class("clergy");
   set_subclass("cleric");
   set_spell_chance(41);
   set_alignment(0);
   set_emotes(2,({ "Shorla gazes around the room with a sparkle in her eyes.", "Shorla winks at you suggestively." }),0);
   set_spells(({"lifetap" }));


new(EQ"slippers")->move(this_object());
force_me("wear slippers");

new(EQ"shimmeringdress")->move(this_object());
force_me("wear dress");

new(EQ"sash")->move(this_object());
force_me("wear sash");

new(EQ"coronet")->move(this_object());
force_me("wear coronet");

new(WEAP"scepter")->move(this_object());
force_me("wield scepter");
}

