#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h");
   set_short("%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h");
   set_id(({"monster", "Death"}));
   set_long("%^BOLD%^%^BLACK%^A figure clad in dusty black robes, his face hidden"
            " %^BOLD%^%^BLACK%^within the folds of his hood. Gleaming red %^BOLD%^%^RED%^e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^RESET%^%^BOLD%^%^BLACK%^ are the only things discernable from that void.\n"
            "%^BOLD%^%^BLACK%^A pair of %^BOLD%^%^WHITE%^S%^BOLD%^%^BLACK%^k%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^s %^RESET%^%^BOLD%^%^BLACK%^hands peek out from the robes to grip\n"
            "%^BOLD%^%^BLACK%^an aged looking scythe that has see many years of use.");
   set_level(80);
   set_gender("male");
   set_race("reaper");
   set_heart_beat(1);
   set_body_type("demon");
   add_action("scythe","scythe");
   set_spells(({"scythe"}));
   set_spell_chance(30);
   set_emotes(2,({ "%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^RESET%^%^BOLD%^%^BLACK%^ walks idly around the room, tapping people on their shoulders and wondering why they keep falling over before he has time to ask his question......" }),0);

new(WEAP"scythe")->move(this_object());
force_me("wield scythe");

new(EQ"dcloak")->move(this_object());
force_me("wear cloak");
}
int scythe() {
    object ob;
    ob = this_object()->query_current_attacker();
    tell_object(ob, "%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^RESET%^%^BOLD%^%^BLACK%^'s eyes begin to glow. ");
    tell_object(ob, "%^BOLD%^%^BLACK%^You feel a chill race down your spine.");
    tell_room(environment(this_object()), "%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^'s hand reaches out for "+ob->query_cap_name()+".", ({ob}));
    tell_room(environment(this_object()), ob->query_cap_name()+" screams in fear!", ({ob}));
    call_out("scythe2", 5, ob);
    return 1;
}
int scythe2(object ob) {
    if (!present(ob, environment())) return 1;
    tell_object(ob, "%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^ raises his scythe overhead and brings it crashing down on your neck!");
    tell_room(environment(this_object()), "%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h raises his scythe over "+ob->query_cap_name()+" and brings it craching down on "+ob->query_subjective()+" killing them instantly!", ({ob}));
    ob->die();
    if (present("corpse",environment(this_object()))) {
        tell_room(environment(this_object()), "%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^RESET%^%^BOLD%^%^BLACK%^ reaches down to the corpse and drags it to the fires of hell.");
        force_me("sacrifice corpse");
    }
    return 1;
}

