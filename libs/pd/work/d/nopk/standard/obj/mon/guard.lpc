#include <std.h>
inherit MONSTER;

void create() {
 ::create();
	set_name("guard");
        set_id( ({ "guard", "bank guard", "big ogre" }) );
        set("race", "ogre");
        set_gender("male");
        set("short", "Bank guard");
        set("long", "A big, ugly ogre hired to guard the "
                 "newly open bank.\n");
        set_level(14);
        set_body_type("human");
        set_hp(500 + random(100));
        set_class("fighter");
        set_spell_chance(10);
        set_spells( ({ "parry", "Bugga" }) );
        mon->set_skill("defense", 70);
        mon->set_skill("blade", 90);
        mon->set_emotes(9,
          ({ "%^CYAN%^Guard says: %^RESET%^Goshdang thief!",
             "Guard grunts.",
             "%^CYAN%^Guard says: %^RESET%^No way youre getting past me!",
             "%^CYAN%^Guard says: %^RESET%^You disgust me."}), 1);
        mon->set_emotes(3,
          ({ "Guard munches on a rat pie.",
             "%^CYAN%^Guard says: %^RESET%^I hate rogues." }), 0);
        mon->set_wielding_limbs( ({ "right hand", "left hand" }) );
        mon->move(this_object());
        weapon = new(WEAPON);
        weapon->set_name("broadsword");
        weapon->set_id( ({ "broadsword", "sword" }) );
        weapon->set("short", "Broadsword");
        weapon->set("long", "A huge broadsword.");
        weapon->set_wc(13);
        weapon->set_type("blade");
        weapon->set_weight(7);
        weapon->set_value(91);
        weapon->move(mon);
        mon->force_me("wield broadsword in right hand");
        key = new(OBJECT);
        key->set_name("key");
        key->set_id( ({ "bank key", "key", "bronze key" }) );
        key->set("short", "Bronze key");
        key->set("long", "An unremarkable bronze key.");
        key->set_weight(29);
        key->set_value(35);
        key->move(mon);

