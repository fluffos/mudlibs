//      /bin/user/_spook.c
//      from the Carnage mudlib
//      scares an opponent
//      created by Seeker 02/15/2000



#include <std.h>
int spell();
inherit DAEMON;

void spook_run(object ob, int i)
{
 string *sorties;
 int times=i;

 if (!ob) return;

 message("info", "%^GREEN%^%^BOLD%^"+(string)ob->query_cap_name()+" runs in fright.", environment(ob), ob);

 while (times--) {
 sorties = (string *)environment(ob)->query_destinations();
  ob->move(sorties[random(sizeof(sorties))]);
   message("info", "%^GREEN%^%^BOLD%^"+(string)ob->query_cap_name()+" runs in and cowers in the corner.", environment(ob), ob);

  }
 message("info", "%^GREEN%^%^BOLD%^You run in fright.", ob);
 
}
int cmd_spook(string str) {
    object ob;
    int conj, mag, dam, owis, mwis;

    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A magic force prevents you from doing that.\n");
        return 0;
    }
    if(!str) ob = (object)this_player()->query_current_attacker();
    else ob = present(lower_case(str), environment(this_player()));
    if(!ob && str) ob = parse_objects(environment(this_player()), lower_case(str));
    if(!ob) {
        notify_fail("Spook whom?\n");
        return 0;
    }
    if (ob==this_player())
      {
       notify_fail("Are you feeling ok?\n");
       return 0;
      }
    if(!living(ob)) {
        notify_fail("Do you expect it to scream, too?\n");
        return 0;
    }
    if(this_player()->query_ghost()) {
        notify_fail("You howl instead of spook.\n");
        return 0;
    }
    if(this_player()->query_casting()) {
        notify_fail("You cant think right now.\n");
        return 0;
    }    
    if(!ob->kill_ob(this_player(),0)) return 1;
    if( (conj = (int)this_player()->query_skill("illusion")) < 40 ) {
        notify_fail("You fail.\n");
        return 0;
    }
    mag = (int)this_player()->query_skill("magic attack");
    owis = (int)ob->query_stats("wisdom");
    mwis = (int)this_player()->query_stats("wisdom");
    dam = (mag+conj)*random(7)/20-(owis*5/7-mwis*2/4);
    if (dam <= 0)
      {
       message("info", "You accidentally spook yourself!", this_player());
       message("info", (string)this_player()->query_cap_name()+" spooks "+(string)this_player()->query_title_gender()+"self.", environment(this_player()), this_player());
       this_player()->set_paralyzed(1 + random(3));
       return 0;
      }
    if((int)this_player()->query_mp() < dam+10) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    this_player()->add_mp(-(dam+15));
    ob->set_paralyzed(1 + random(3), "You are too scared to do anything.");
    this_player()->set_magic_round();
    this_player()->add_skill_points("conjuring", dam);
    this_player()->add_skill_points("magic attack", dam);
    write("%^BLUE%^%^BOLD%^You stare deeply into "+ob->query_cap_name()+"'s eyes.\n");
say(this_player()->query_cap_name()+"%^BLUE%^%^BOLD%^ stares deeply into "+ob->query_cap_name()+"'s eyes.\n", ob);
tell_object(ob, "%^BLUE%^%^BOLD%^"+this_player()->query_cap_name()+" stares deeply into your eyes.\n");
    call_out("spook_run", dam/2, ob, dam/2);
    return 1;
}

void help() {
    write("Syntax: <spook [enemy]>\n\n"
        "Spook scares an enemy for a cetain amount of time by scaring "
        "the wits out of them.");
}

int spell() {
   if (this_player()->query_skill("illusion") > 39 &&
      this_player()->query_subclass() == "illusionist") return 1;
}
