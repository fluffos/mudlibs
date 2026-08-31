// ::Inferno(12/06/2000);
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_holyfire(string str) {
    object ob, env;
    if (!spell())
        return notify_fail("What?\n");
    if(str) {
        ob = present(str, environment(this_player()));
    }
    env = environment(this_player());
    if (ob && !living(ob))
        return notify_fail("You do not see that here.\n");
    if (ob==this_player())
        return notify_fail("The heavens do not permit suicide.. dork ;)\n");
    if (this_player()->query_ghost())
        return notify_fail("Fight? You already lost! You're dead!!");
    if (this_player()->query_alignment() < 750){
        notify_fail("You have betrayed your alignment.");
        return 0;
    }
    if (this_player()->query_disable() || this_player()->query_magic_round())
        return notify_fail("You are busy doing something else.\n");
    if (env->query_property("no attack") || env->query_property("no magic"))
        return notify_fail("Greater powers prevent your malice.\n");
    if (this_player()->query_mp() < 150)
        return notify_fail("Your magic is not strong enough to summon the fire of "
          "the heavens.\n");
    write("%^BOLD%^Holy fire builds within your soul, fueling you from within!");
    this_player()->set_paralyzed(1, "The blinding holy fire within you holds you "
      "back.");
    this_player()->set_disable(1);
    call_out("do_dmg", 1, ob, this_player());
    return 1;
}
void do_dmg(object ob, object tp) {
    int i, dmg, align, mod;
    object *all;
    message("prompt", "%^BOLD%^White flame spills from your body, engulfing your "
      "opponents!\n", tp);
    tell_room(environment(tp), "%^BOLD%^White flame spills from "+
      tp->query_cap_name()+"'s body, engulfing "+tp->query_title_gender()+
      " opponents!", ({ tp }));
    tp->clean_up_attackers();
    all = tp->query_attackers();
    i = sizeof(all);
    if(!ob)
        while (i--) {
            if (!all[i]) continue;
            if (environment(tp) != environment(all[i])){
                write("%^ORANGE%^The fire fades away.");
                tell_room(environment(tp), "%^ORANGE%^The fire around "+tp->query_cap_name()+" fades away.", ({ tp }));
                return;
            } 
            if (!all[i]){
                write("%^ORANGE%^The fire fades away.");
                tell_room(environment(tp), "%^ORANGE%^The fire around "+tp->query_cap_name()+" fades away.", ({ tp }));
                return;
            }
            if(!this_player()->kill_ob(all[i])) {
                write(all[i]->query_cap_name()+" can't be attacked by you yet.");
                continue;
            }
            align = all[i]->query_alignment();
            if (align <= 0) mod = 1; else
            if (align > 0) mod = 50; else
            if (align > 100) mod = 100; else
            if (align > 300) mod = 150; else
            if (align > 500) mod = 200; else
            if (align > 700) mod = 300; else
            if (align > 1000) mod = 450;
dmg = tp->query_skill("faith")*3/2;
            dmg += tp->query_stats("wisdom")*3/2;
dmg += tp->query_skill("magic attack");
            dmg -= all[i]->query_stats("intelligence")*2/3;
            dmg -= all[i]->query_skill("magic defense")/3;
            dmg -= mod;
            dmg *= 5/4;
            if (dmg < 30) {
                tell_room(environment(tp), "%^BOLD%^%^WHITE%^Holy%^RESET%^%^ORANGE%^fire "
                  "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^s"
                  "%^RESET%^%^ORANGE%^"+tp->query_cap_name()+"%^BOLD%^%^WHITE%^!",
                  ({ ob }));
                tell_object(all[i], "%^BOLD%^%^WHITE%^Holy%^RESET%^%^ORANGE%^fire "
                  "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^s "
                  "%^RESET%^%^ORANGE%^you%^BOLD%^%^WHITE%^!");
                tell_room(environment(tp), "%^BOLD%^Flame passes over %^RESET%^"
                  +all[i]->query_cap_name()+"'s%^BOLD%^ body, not harming "
                  +all[i]->query_possessive()+"him at all.", ({ all[i] }));
                tell_object(all[i], "Flame passes over your body, not harming you at all.");
                continue;
            }
            tell_room(environment(tp), "%^BOLD%^%^WHITE%^Holy%^RESET%^%^ORANGE%^fire "
              "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^s "
              "%^RESET%^%^ORANGE%^"+all[i]->query_cap_name()+"%^BOLD%^%^WHITE%^!", ({ ob }));
            tell_object(all[i], "%^BOLD%^%^WHITE%^Holy%^RESET%^%^ORANGE%^fire "
              "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^s "
              "%^RESET%^%^ORANGE%^you%^BOLD%^%^WHITE%^!");
            all[i]->damage(dmg, "holy");
            tp->add_mp(-(dmg/14))*i;
            if(all[i]->query_hp() < 1) all[i]->heart_beat();
        }
    if (ob) {
        if (!ob){
            write("%^ORANGE%^The fire fades away.");
            tell_room(environment(tp), "%^ORANGE%^The fire around "+tp->query_cap_name()+" fades away.", ({ tp }));
            return;
        }
        if(environment(ob) != environment(tp)){
            write("%^ORANGE%^The fire fades away.");
            tell_room(environment(tp), "%^ORANGE%^The fire around "+tp->query_cap_name()+" fades away.", ({ tp }));
            return;
        }
            align = ob->query_alignment();
            if (align <= 0) mod = 1; else
            if (align > 0) mod = 50; else
            if (align > 100) mod = 100; else
            if (align > 300) mod = 150; else
            if (align > 500) mod = 200; else
            if (align > 700) mod = 300; else
            if (align > 1000) mod = 450;
        dmg = tp->query_skill("faith")*3/2;
        dmg += tp->query_stats("wisdom")*3/2;
        dmg += tp->query_skill("magic attack")*2/3;
        dmg -= ob->query_stats("intelligence")*2/3;
        dmg -= ob->query_skill("magic defense")*2/3;
        dmg -= mod;
        dmg *= 5/4;
        tell_room(environment(tp), "%^BOLD%^%^WHITE%^Holy%^RESET%^%^ORANGE%^fire "
          "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^s "
          "%^RESET%^%^ORANGE%^"+ob->query_cap_name()+"%^BOLD%^%^WHITE%^!", ({ ob }));
        tell_object(ob, "%^BOLD%^%^WHITE%^Holy%^RESET%^%^ORANGE%^fire "
          "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^s "
          "%^RESET%^%^ORANGE%^you%^BOLD%^%^WHITE%^!");
        if(!this_player()->kill_ob(ob)) {
            write(all[i]->query_cap_name()+" can't be attacked by you yet.");
            return;
        }
        if (dmg < 30) {
            tell_room(environment(tp), "%^BOLD%^Flame passes over %^RESET%^"
              +ob->query_cap_name()+"'s %^BOLD%^body, not harming "
              +ob->query_possessive()+"him at all.", ({ ob }));
            tell_object(ob, "Flames pass over your body, not harming you at all.");
        } else
            ob->damage(dmg, "holy");
    }
    tp->add_skill_points("magic attack", dmg/25);
    tp->add_skill_points("faith", dmg/25);
    tp->add_mp(-(dmg/7));
    return;
}
void help() {
    write(@ENDTEXT
%^RESET%^Syntax: <holyfire [living]>  or  <holyfire>
Within their very soul, the Archangels build this holy fire until it totally 
consumes them. At this point, blinding holyfire explodes from their body, 
engulfing each of the angel's enemies. By using an argument with holyfire, 
you can attack single targets with holyfire. Targets are affected according 
to their alignment.
ENDTEXT);
}
int spell() {
    object o;
    o = this_player();
    if (o->query_level() < 50) return 0;
    if (o && o->query_race() == "archangel")
        return 1;
}
