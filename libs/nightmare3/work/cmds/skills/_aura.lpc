//    /cmds/skills/_aura.c
//    From the Nightmare Mudlib
//    A spell that creates a glowing shield around the caster
//    by Kalinash@Nightmare on May 1, 1994.

#include <std.h>

inherit DAEMON;

int alignment_check(object ob);

int cmd_aura(string who) {
    object ob, me, orb;
    int cost, defense, prot, length;
    string Class;

    me = this_player();
    Class = me->query_class();
    if(environment(this_player())->query_property("no magic"))
        return notify_fail("Something is blocking your concentration.\n");
    if(Class != "mage" && Class != "kataan" && Class != "monk"
      && Class != "cleric")
        return notify_fail("You mumble in confusion.\n");
    if(!who) who = me->query_name();
    if(!ob=find_player(who))
        return notify_fail(sprintf("%s doesn't seem to be on the mud.\n",
          capitalize(lower_case(who))));
    if(!present(ob, environment(this_player())))
        return notify_fail(sprintf("%s isn't here!\n",
          capitalize(lower_case(who))));
    if((Class == "monk" || Class == "cleric") && !alignment_check(me))
        return notify_fail("You have betrayed the source of your power.\n");
    me->set_magic_round();
    cost = 60 + (random(2000/((int)this_player()->query_stats("wisdom")+1)));
    defense = (int)this_player()->query_skill("magic defense");
    cost = cost + (int)ob->query_magic_protection(0)*15;
    if((int)me->query_mp() < cost)
        return notify_fail("Too low on magic energy.\n");
    if(me == ob)
        prot = (1+defense/25);
    else
        prot = (1+defense/20);
    me->add_mp(-cost);
    length = random(defense*10)+100;
    if(length > 600) length = 600;
    ob->add_magic_protection( ({ 0, prot, length }) );
    orb = new("/std/obj/aura_orb");
    orb->move(ob);
    orb->set_time(length);
    orb->start();
    if(me == ob)
        me->add_skill_points("magic defense", random(10));
    else {
        me->add_skill_points("magic defense", random(20));
        me->add_exp(5);
    }
    if(Class == "monk" && (int)ob->query_alignment() < 0)
        me->add_alignment(-random(10));
    else if(me != ob && (int)me->query_alignment() > 0 &&
        (int)ob->query_alignment() > 0)
        me->add_alignment(random(10));
    if(ob == me)
        message("my_action", "%^YELLOW%^You create a glowing shield "
          "around your body.%^RESET%^", me);
    else {
        message("my_action", sprintf("%%^YELLOW%%^You create a "
          "glowing shield around the body of %s",
          (string)ob->query_cap_name()), me);
        message("their_action", sprintf("%%^YELLOW%%^%s creates a "
          "glowing shield around your body.", me->query_cap_name()),
          ob);
    }
    message("other_action", sprintf("%s mumbles a %s of protection.",
      (string)me->query_cap_name(), Class == "mage" ? "spell" : "prayer"),
      environment(me), me);
    return 1;
}

int alignment_check(object ob) {
    if( (int)ob->query_alignment() > 200) return 1;
    if( (string)ob->query_class() == "cleric" &&
      (int)ob->query_alignment() > 0) return 1;
    return 0;
}

void help() {
    message("help", "Usage: <aura [whom]>\n\nThis spells creates a "
      "glowing shield around the body of [whom].", this_player());
    return;
}


