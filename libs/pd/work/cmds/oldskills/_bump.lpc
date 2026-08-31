#include <std.h>

inherit DAEMON;
int abil();
int cmd_bump(string str) {
    object ob;
    string former, ex, tmp;
    string *exits;
    int kplah;

    if(this_player()->query_ghost()) return 0;
    if(!str) {
        notify_fail("Bump whom?\n");
        return 0;
    }
    if(!(ob = present(lower_case(str), environment(this_player())))) {
        notify_fail("No "+capitalize(str)+" here.\n");
        return 0;
    }
    if(!living(ob)) {
        write("You bump the "+str+".");
        say(this_player()->query_cap_name()+" bumps the "+str+".");
        return 1;
    }
    if(!this_player()->ok_to_kill(ob)) return notify_fail("You cannot bump them yet.\n");
    if(ob->query_property("no bump") ||
       environment(ob)->query_property("no bump") ||
       environment(ob)->query_property("no attack") ) {
        write(ob->query_cap_name()+" growls at you.");
        say(ob->query_cap_name()+" growls at "+this_player()->query_cap_name()+" as "+this_player()->query_subjective()+" tries to push "+ob->query_objective()+".", ob);
        return 1;
    }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    kplah = (int)this_player()->query_stats("strength") -
      ((int)ob->query_stats("strength") + (int)ob->query_stats("dexterity"))/2;
    if(kplah < 1) {
        this_player()->add_hp(-(random(15)));
        this_player()->add_sp(-(random(20)));
        write(ob->query_cap_name()+" shoves you to the ground!");
        say(this_player()->query_cap_name()+" is shoved to the ground while trying to bump "+ob->query_cap_name()+".");
        tell_object(ob, this_player()->query_cap_name()+" is thrown to the ground while trying to bump you.");
        return 1;
    }
    kplah += random((int)ob->query_skill("melee"));
    if (kplah < random(101)) {
        write("The "+(string)ob->query_race()+" holds "+(string)ob->query_possessive()+" ground.\n");
        say(this_player()->query_cap_name()+" fails in an attempt to push "+ob->query_cap_name()+" aside.", ob);
        tell_object(ob, this_player()->query_cap_name()+" gives you a bit of a bruise trying to push you.");
        ob->add_hp(-(random(7)));
        this_player()->add_sp(-(random(10)));
        this_player()->add_hp(-(random(20)));
        return 1;
    }
    exits = environment(ob)->query_exits();   
    ex = exits[ random(sizeof(exits)) ];
    if (environment(ob)->query_door(ex))
      if (environment(ob)->query_closed(environment(ob)->query_door(ex)))
        {
        write("You throw "+(string)ob->query_cap_name()+" into the "+environment(ob)->query_door(ex)+".");
        say(this_player()->query_cap_name()+" throws "+ob->query_cap_name()+" into the "+environment(ob)->query_door(ex)+".", ({ this_player(), ob }));
        tell_object(ob, this_player()->query_cap_name()+" throws you into the "+environment(ob)->query_door(ex)+".");
        ob->add_hp(-(random(7)));
        this_player()->add_sp(-(random(10)));
        this_player()->add_hp(-(random(20)));
        return 1;
        }
    if(environment(ob)->query_pre_exit_function(ex)) {
      write("A magical force prevents you from pushing "+ob->query_cap_name()+" "+ex+".");
      say(this_player()->query_cap_name()+" tries to push "+ob->query_cap_name()+
          " towards the "+ex+", but a magical force prevents stops "+objective(this_player())+".", ob);
      tell_object(ob, this_player()->query_cap_name()+" tries to push you towards the "+ex+", but a"
          " magical force prevents stops "+objective(this_player())+".");
      return 1;
    }
    tmp = environment(ob)->query_exit(ex);
   
    write("You push the "+(string)ob->query_race()+" out of the way.");
    say(this_player()->query_cap_name()+" pushes "+ob->query_cap_name()+" out of the way.", ob);
    tell_object(ob, this_player()->query_cap_name()+" pushes you out of the way.\n");
    this_player()->add_hp(-(random(10)));
   this_player()->add_sp(-(random(10)));
    ob->add_hp(-(random(5)));
    former = file_name(environment(ob));
    ob->move(tmp);
    if(!ob->is_player()) call_out("return_home", 14, ({ ob, former }) );
    return 1;
}

void return_home(mixed *borg) {
   if(!borg) return;
   if (!borg[0]) return;
    borg[0]->move_player(borg[1], "angrily");
    message("info", "%^BOLD%^%^GREEN%^"+borg[0]->query_cap_name()+" arrives angrily.%^RESET%^", environment(borg[0]), borg[0]);
}

void help() {
    write("Syntax: <bump [enemy]>\n\n"
      "Allows you to push people out of the way, but you better be strong!\n");
}
int abil() {
   return 1;
}
