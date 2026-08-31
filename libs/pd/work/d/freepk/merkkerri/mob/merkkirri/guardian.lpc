#include <mjungle.h>
#include <std.h>
inherit MONSTER;
 
void create() {
    ::create();
    set_name("guardian");
    set_short("Guardian of the Tomb");
    set_long("The guardian is a shadowy blue spectre.  Its eyes are a firey orange and it wears the clothing of an ancient Merkkirri warrior.");
    set_id(({"guardian", "spectre", "guardian of the tomb"}));
    set_level(30);
    set_heart_beat(1);
    set_race("gnoll");
    set_body_type("gnoll");
    set_gender("male");
    set("alignment", -1000);
    set_stats("intelligence", 60);
    set_stats("wisdom", 60);
    set_class("mage");
    set_subclass("pyromancer");
    set_skill("magic defense",75);
    set_skill("conjuring", 150);
    set_skill("magic attack", 200);
    set_skill("healing", 50);
    set_emotes(10, ({"The guardian's eyes glow brightly.", "The guardian nearly fades from view."}),1);
    set_spell_chance(45);
    set_spells(({"shroud", "scorch", "burn"}));
    set_lang_prof("merkish", 10);
    set_speech(30,"merkish", ({"The winds of death both burn and freeze...", "Entering our place of rest was a mistake...", "Join our suffering..."}),1);
    set("aggressive", 20);
    new(MOB "cryptkey")->move(this_object());
}
