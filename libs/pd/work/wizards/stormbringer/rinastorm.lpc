// a dungeonware.net production based on rapture -00.06.22-
// updated to a healing rain 10/30/2002
// coded for Primal Darkness by Stormbringer
#include <std.h>
inherit DAEMON;
int spell();
int cmd_rainstorm(string str) {
    object env, tmp_ob;
    object *inv, *chambres;
    int i, tmp,j, tmp2, healrounds;
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
  healrounds= this_player()->query_skill("nature")/15;
  healrounds+= this_player()->query_skill("conjuring")/15;
  healrounds+= this_player()->query_skill("faith")/15;
  if (healrounds < 3) healrounds=3;
  if (healrounds > 7) healrounds=5+random(healrounds-2);
  if (healrounds > 10) healrounds=9+random(healrounds*4/3);
    this_player()->set_magic_round(2);
    call_out("do_rain", 2, env);
    this_player()->add_mp(-(int)this_player()->query_mp()/2);
    this_player()->set_paralyzed(2);
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
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
          "%^BLUE%^The winds begin to blow as a gentle rain moves in.\n%^RESET%^");
else tell_object(inv[j], blue("The winds begin to blow as a gentle rain moves in.\n"));
        }
    }
 
    return 1;
}
void do_rain(object env) {
    mapping who;
    object *inv, *chambres;
    string *sorties;
    int i, j, tmp2, tmp, tmp_al, healing, healrounds;
    object tmp_ob;
  if (healrounds < 1) {
     end_rain();
     return;
  }
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
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
    write("A healing rain begins to rain down upon the land.\n");
    for(i=0; i<tmp; i++) {
     if (i==tmp) continue;
        tell_object(inv[i], "%^BLUE%^BOLD%^Rain falls from the heavens!\nYou feel rejuvinated as the rain refreshes you!%^RESET%^");
        tmp_al = who[inv[i]][0] + 2000;
        healing = (int)this_player()->query_skill("nature") - to_int(percent(tmp_al, 3000));
        if(healing < 1) healing = 1;
        healing = (healing*(who[inv[i]][1]))/100;
        if(healing>this_player()->query_max_hp())
         healing=(int)this_player()->query_max_hp()/2;
        inv[i]->heal(healing/10);
        inv[i]->add_poisoning(-(healing/15));
        if(inv[i] != this_player()) {
          if(inv[i]->query_ansi()) tell_object(inv[i], 
            bold(blue((string)this_player()->query_cap_name()+" has summoned a rainstorm.\n")));
          else tell_object(inv[i],
            this_player()->query_cap_name()+" has summoned a rainstorm.\n");
        }
    }
  healrounds--;
  if (healrounds % 2)
    call_out("do_rain",2);
  else
    call_out("do_rain",3);
    return;
}
void end_rain(object env) {
object *inv;
int j;  
  tell_object(inv[j], "%^BLUE%^BOLD%^The rainstorm trickles to a stop and the clouds dissapate%^RESET%^");
  
}
void help() {
    write("Syntax: <rainstorm>\n\n"
        "The powerful may summon a healing rain into an area. \n"
    );
}
int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "clergy") return 0;
   if (o->query_subclass() != "druid") return 0;
   if (o->query_level() < 20) return 0;
   return 1;
}
