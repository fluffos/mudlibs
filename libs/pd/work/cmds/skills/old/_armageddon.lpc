// a dungeonware.net production based on rapture and acidrain -00.09.18-
// coded for Primal Darkness by Asmodeus
#include <std.h>
#include <common_fun.h>
inherit DAEMON;
int spell();
int cmd_armageddon(string str) {
    object env, tmp_ob;
    object *inv, *chambres;
    int i, tmp,j, tmp2;
    string *sorties;
   
   if (!spell()) {
      write("Only light monks can cast this spell.");
      return 1;
   }
    if(str) return 0;
    env = environment(TP);
    if(!env) return 0;
    if(TP->query_ghost()) {
        notify_fail("Nothing can be summoned while in the afterlife.\n");
        return 0;
    }
    if(env->QPP("no magic") || env->QPP("no attack")) {
        notify_fail("Your god would not be pleased if that was cast here.\n");
        return 0;
    }
    if((int)TP->query_mp() < 500) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if((int)TP->QSK("faith") < 250) {
        notify_fail("You do not have the faith to summon this.\n");
        return 0;
    }
   if ((int)TP->query_casting()) {
       notify_fail ("You are busy in another spell.");
       return 0;
   }
    TP->set_magic_round();
    call_out("do_armageddon", 5, env);
    TP->add_mp(-(int)TP->query_mp()*3/4);
    TP->set_paralyzed(5);
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
            call_other(sorties[i], "???");
            if(!(tmp_ob = find_object(sorties[i]))) continue;
            if(tmp_ob->QPP("no magic")) continue;
            chambres += ({ tmp_ob });
        }
        chambres = distinct_array(chambres);
    }
   for(i=0, tmp=sizeof(chambres); i<tmp; i++) {
        inv = all_inventory(chambres[i]);
        for(j=0, tmp2=sizeof(inv); j<tmp2; j++) {
            if(!living(inv[j])) continue;
                  if(!inv[j]->query_ansi()) tell_object(inv[j],
         "%^BOLD%^WHITE%^A sudden silence fills the land...\n");
else tell_object(inv[j], blue("%^BOLD%^WHITE%^A sudden silence falls upon the land...\n"));
        }
    }
 
    return 1;
}
void do_armageddon(object env) {
    mapping who;
    object *inv, *chambres;
    string *sorties;
    int i, j, tmp2, tmp, tmp_al, damage;
    object tmp_ob;
    if(!present(TP, env)) {
      write("You are unable to move.\n");
      if(env)
        TP->move(env);
    }
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
            call_other(sorties[i], "???");
            if(!(tmp_ob = find_object(sorties[i]))) continue;
            if(tmp_ob->QPP("no magic")) continue;
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
    write("%^BOLD%^WHITE%^The area erupts and explodes from %^YELLOW%^armageddon%^WHITE%^!\n");
    for(i=0; i<tmp; i++) {
     if (i==tmp) continue;
        if(TP != inv[i] && !inv[i]->kill_ob(TP, 0))
          continue;
if(inv[i] != TP) {
if(inv[i]->query_ansi()) tell_object(inv[i],
"%^BOLD%^WHITE%^"+TP->QCN+" has called upon the powers of %^YELLOW%^armageddon%^WHITE%^!\n");
else tell_object(inv[i],
"%^BOLD%^WHITE%^"+TP->QCN+" has called upon the powers of %^YELLOW%^armageddon%^WHITE%^!\n");
}
        tell_object(inv[i], "The explosions burn and smash your body!\nYour body is overwhelmed by the power of the gods!");
        tmp_al = who[inv[i]][0] + 2000;
        damage = (int)TP->QSK("faith") + TP->QST("wisdom") -
to_int(percent(tmp_al, 3000));
        if(damage < 1) damage = 1;
        damage = (damage*(who[inv[i]][1]))/100;
        if(damage>TP->query_max_hp())
        damage=(int)TP->query_max_hp()/2;
        inv[i]->damage(damage);
if(inv[i]->query_hp() < 1) inv[i]->set_hp(1);
    }
    return;
}
void help() {
    write("Syntax: <armageddon>\n\n"
        "The most powerful spell of the monk.  This spell floods the area with the forces of armageddon.  This spell should be used with caution.\n"
    );
}
int spell() {
   if (!TP) return 0;
   if (TP->QCL != "monk") return 0;
   if (TP->QSK("faith") < 250) return 0;
   return 1;
}
