// a dungeonware.net production based on rapture -00.06.22-
// coded for Primal Darkness by Stormbringer
#include <std.h>
inherit DAEMON;
int spell();
int cmd_acidrain(string str) {
    object env, tmp_ob;
    object *inv, *chambres;
    int i, tmp,j, tmp2;
    string *sorties;
   
   if (!spell()) {
      write("Only those of great conjuring can cast this spell.");
      return 1;
   }
    if(str) return 0;
    env = environment(this_player());
    if(!env) return 0;
    if(this_player()->query_ghost()) {
        notify_fail("Nothing can be summoned while in the afterlife.\n");
        return 0;
    }
    if(env->query_property("no magic") || env->query_property("no attack")) {
        notify_fail("A holy force prevents your storm.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < 500) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if((int)this_player()->query_skill("nature") < 100) {
        notify_fail("You do not have the conjuring to summon this.\n");
        return 0;
    }
   if ((int)this_player()->query_casting()) {
       notify_fail ("You are busy in another spell.");
       return 0;
   }
 /*   for(i=0, tmp =sizeof((inv=users())); i<tmp; i++) {
        if(inv[i]->query_blocked("shout")) continue;
        if(!inv[i]->query_ansi()) tell_object(inv[i],
          "%^BLUE%^The winds begin to blow as a storm moves in.\n%^RESET%^");
else tell_object(inv[i], blue("The winds begin to blow as a storm moves in.\n"));
    }
*/
    this_player()->set_magic_round();
    call_out("do_acidrain", 5, env);
    this_player()->add_mp(-(int)this_player()->query_mp()/2);
    this_player()->set_paralyzed(5);
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
           // if (file_name(sorties[i]) < 0) continue;
            call_other(sorties[i], "???");
            if(!(tmp_ob = find_object(sorties[i]))) continue;
            if(tmp_ob->query_property("no magic")) continue;
            chambres += ({ tmp_ob });
        }
        chambres = distinct_array(chambres);
    }
   for(i=0, tmp=sizeof(chambres); i<tmp; i++) {
        inv = all_inventory(chambres[i]);
        for(j=0, tmp2=sizeof(inv); j<tmp2; j++) {
            if(!living(inv[j])) continue;
                  if(!inv[j]->query_ansi()) tell_object(inv[j],
          "%^BLUE%^The winds begin to blow as a storm moves in.\n%^RESET%^");
else tell_object(inv[j], blue("The winds begin to blow as a storm moves in.\n"));
        }
    }
 
    return 1;
}
void do_acidrain(object env) {
    mapping who;
    object *inv, *chambres;
    string *sorties;
    int i, j, tmp2, tmp, tmp_al, damage;
    object tmp_ob;
    if(!present(this_player(), env)) {
      write("The winds of the storm force you to remain at the place\n"
            "of your summoning.");
      if(env)
        this_player()->move(env);
    }
/*    for(i=0, tmp = (sizeof(inv = users())); i<tmp; i++) {
        if(inv[i]->query_blocked("shout")) continue;
        tell_object(inv[i], "%^BLUE%^BOLD%^Acid Rain pours down upon you!%^RESET%^");
    }*/
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
             
           // if (file_name(sorties[i]) < 0) continue;
            call_other(sorties[i], "???");
            if(!(tmp_ob = find_object(sorties[i]))) continue;
            if(tmp_ob->query_property("no magic")) continue;
            chambres += ({ tmp_ob });
        }
        chambres = distinct_array(chambres);
    }
    for(i=0, tmp=sizeof(chambres), who = ([]); i<tmp; i++) {
        inv = all_inventory(chambres[i]);
        for(j=0, tmp2=sizeof(inv); j<tmp2; j++) {
            if(!living(inv[j])) continue;
            who[inv[j]] = ({
              (int)inv[j]->query_alignment(), (int)inv[j]->query_hp()
            });
        }
    }
    tmp = sizeof((inv=keys(who)));
    write("Acid begins to rain down apon the land.\n");
    for(i=0; i<tmp; i++) {
     if (i==tmp) continue;
        if(this_player() != inv[i] && !inv[i]->kill_ob(this_player(), 0))
          continue;
        tell_object(inv[i], "%^BLUE%^BOLD%^Acid rain falls from the heavens!\nYour skin begins to burn where the vicous liquid touches you!%^RESET%^");
        tmp_al = who[inv[i]][0] + 2000;
        damage = (int)this_player()->query_skill("nature") - to_int(percent(tmp_al, 3000));
        if(damage < 1) damage = 1;
        damage = (damage*(who[inv[i]][1]))/100;
        if(damage>this_player()->query_max_hp())
         damage=(int)this_player()->query_max_hp()/2;
        inv[i]->damage(damage);
        if(inv[i] != this_player()) {
          if(inv[i]->query_ansi()) tell_object(inv[i], 
            bold(blue((string)this_player()->query_cap_name()+" has summoned a great storm of acid rain.\n")));
          else tell_object(inv[i],
            this_player()->query_cap_name()+" has summoned a great storm of acid rain.\n");
        }
    }
    return;
}
void help() {
    write("Syntax: <acidrain>\n\n"
        "The powerful may summon this storm into an area. This should be used with *extreme* caution.\n"
    );
}
int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "mage") return 0;
   if (o->query_subclass() != "druid") return 0;
   if (o->query_level() < 20) return 0;
   return 1;
}
