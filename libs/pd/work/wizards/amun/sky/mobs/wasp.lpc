#include <std.h>
#include <amun.h>
inherit MONSTER;
int do_string(string);
void create() {
    ::create();
    set_name("Wasp");
    set_id( ({ "wasp" }) );
    set_level( 55 );
    set_short("Wasp" );
    set_long("The wasp is perched on a rock peacefully, not wanting to be disturbed. She has a large stinger on her backside and long wings that can keep her in flight for a long time." );
    set_race( "wasp" ); 
    set_gender( "female" );
    set_body_type("insctwgd");
    set_skill("melee", 250);
    set_class("fighter");
    set_subclass("paladin");
    set_aggressive(40);
    set_alignment(150);
    set_spells( ({ "sting" }) );
    set_spell_chance(30);
    add_action("do_sting", "sting");
}
int do_sting(string str) {
    object tp = this_player();
    object tgt;
    object env = environment(tp);

    if (tp != this_object()) return 0;

    if (str) tgt = present(str, env);
    else tgt = tp->query_current_attacker();

    if (!tgt || tgt == tp) return 0;

    message("combat", tp->query_cap_name()+" pierces you with his stinger!", tgt);
    message("combat", tp->query_cap_name()+" pierces "+tgt->query_cap_name()+" with his stinger!", env, tgt);
    tgt->set_paralyzed(3, "The stinger has paralyzed you!");

    return 1;
}
