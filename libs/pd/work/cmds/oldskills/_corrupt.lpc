#include <std.h>
inherit DAEMON;
int spell();
int cmd_corrupt(string str) {
    object env;
    object *inv;
    int i, tmp_al, damage, max, faith;
   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    this_player()->set_magic_round();
    if(str) return 0;
    env = environment(this_player());
    if(!env) return 0;
    if(this_player()->query_ghost()) {
        write("You howl evilly.\n");
        say("You hear an evil howl.\n");
        return 1;
    }
    if(env->query_property("no magic") || env->query_property("no attack")) {
        notify_fail("A holy force prevents you from corrupting souls.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < 20) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");
    if(faith = (int)this_player()->query_skill("faith") < 25) {
        notify_fail("You do not have the faith to bring about corruption in others.\n");
        return 0;
    }
    if((string)this_player()->query_subclass() == "kataan" && 
      !alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    write("You attempt to corrupt the souls of those about you.\n");
    this_player()->set_disable();
    for(i=0, max = sizeof(inv=all_inventory(env)); i<max; i++) {
        if(!living(inv[i])) continue;
        if(wizardp(inv[i])) continue;
        if(this_player() != inv[i] && !this_player()->kill_ob(inv[i]))
          continue;
        tmp_al = 2000 - (int)inv[i]->query_alignment();
        inv[i]->add_sp(-(random(50)+50));
        this_player()->add_mp(-damage/7);
        damage = faith - to_int(percent(tmp_al, 3000));
        if(damage < 1) damage = 1;
        faith = (int)inv[i]->query_skill("faith");
        damage += faith;
        damage -= (int)inv[i]->query_skill("magic_defense")/3;
        this_player()->add_skill_points("faith", damage/5);
        this_player()->add_alignment(-(random(9)));
        this_player()->set_casting(damage/10);
        if(inv[i] != this_player()) {
          if(inv[i]->query_ansi()) tell_object(inv[i], 
            bold(yellow((string)this_player()->query_cap_name()+" has corrupted your soul.\n")));
          else tell_object(inv[i],
            this_player()->query_cap_name()+" has corrupted your soul.\n");
        }
    }
    return 1;
}
void help() {
    write("Syntax: <corrupt>\n\n"
        "This spell weakens the faith of followers of good.\n"
    );
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_subclass() != "kataan" && tp->query_subclass() != "white") return 0;
   if (tp->query_skill("magic attack") < 20) return 0;
   if (tp->query_skill("faith") < 25) return 0;
   if (tp->query_level() < 5) return 0;
   return 1;
}
