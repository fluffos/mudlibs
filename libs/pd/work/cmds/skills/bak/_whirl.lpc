

#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_whirl(string str) {
    object tp, ob, pois, env;
    object *all=({});
    int dam, dmg, attack, i;
    string party, name;
    tp = this_player();
   
   
   
if(!this_player()->is_player())
    {
    
    if (!abil())
      {
       return 0;
    }
    if(!sizeof((object *)this_player()->query_wielded())) {
        notify_fail("You need a weapon to whirl with!\n");
        return 0;
    }
    if(!str)
      ob = (object)this_player()->query_current_attacker();
    else {
       ob = present(str, environment(this_player()));
       if(!ob) ob = parse_objects(environment(this_player()), str);
    }
   if(!ob || !living(ob)) {
        notify_fail("That is not here as such.\n");
      return 0;
   }
   if(ob == this_player())
      return notify_fail("Why would you want to do a thing like that?\n");

   if(this_player()->query_ghost()) {
      notify_fail("You cannot attack without a body.\n");
      return 0;
   }
   if (this_player()->query_disable())
     {
      write("You are not balanced enough to whirl.");
      return 1;
     }
 
   if(this_player()->query_casting()) return 1;
   if(this_player()->query_magic_round()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("A magic force prevents you from doing your attack.\n");
      return 0;
   }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    this_player()->set_casting();


    write("You whirl at "+ob->query_cap_name()+"!\n");
    attack = BALANCE_D->get_damage( this_player(), ob, 1, ({ "attack" }),
                                   ({ "strength" }) );
    if (attack < 5)
    return notify_fail("You miss your whirl attempt!\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+ " whirls at "+(string)ob->query_cap_name() + "\n", ({ob, this_player()}));
    tell_object(ob, this_player()->query_cap_name()+" whirls at you.\n");
    ob->damage(attack);
    this_player()->add_sp(-attack/8);
    return 1;
    }
    else {
    if(!abil())
        return 0;
    env = environment(this_player());
    name = "0";
    if (ob && !living(ob))
        return notify_fail("You do not see that here.\n");
    if(tp->query_ghost()) {
        notify_fail("You seem to be somewhat dead.\n");
        return 0;
    }
    if (environment(this_player())->query_property("no attack")) {
        write("Greater powers prevent your malice.");
        return 1;
    }
    //if (tp->query_casting_round()) return 1;
    if (tp->query_disable()) {
        notify_fail("You are too busy to do that!\n");
        return 0;
    }
    if (tp->query_sp() < 50) {
        write("You are too tired to do that.");
        return 1;
    }
    tp->clean_up_attackers();
    all = all_inventory(environment(this_player()));
    i = sizeof(all);
        write("You ready yourself for the attack!");
       this_player()->add_sp(-10);
    for(i = 0; i < sizeof(all); i++) {
    //while (i--) {
        if (this_player()->query_party())
           party = this_player()->query_party();
           else party = "AdkIl898-FL00Jn-neInfe_ron";
        if (!all[i]) continue;
        if(all[i]->query_party() == party) continue;
        if (environment(tp) != environment(all[i])){
            write(""+all[i]->query_cap_name()+" dodged your attack!");
            continue;
        } 
        if (!all[i])
            continue;
        if (!all[i]->is_living()) continue;
        tp->set_disable();
        dam = BALANCE_D->get_damage( tp, all[i], 2, ({ "attack", "attack", "blade", "blade", "perception" }),
        ({ "dexterity", "dexterity", "strength" }) );
        
        dam = dam * (((2.0 / (sizeof(all) + 1)) + (1.0 / (i + 1.0))) / 2);
        if(dam < 1) {
            write("You try to whirl, but can't manage to spin!");
            say(""+tp->query_cap_name()+ " tries to spin at you, but stumbles!");
            return;
        }
        
        if (!all[i]->query_ghost() && all[i] != this_player() && !wizardp(all[i])) {
            if(!this_player()->kill_ob(all[i])) {
                write(all[i]->query_cap_name()+" can't be attacked by you yet.");
                continue;
            }
            if(name == "0") {
                write("Your blade hacks into "+all[i]->query_cap_name());
                say(this_player()->query_cap_name()+
                    " whirls at "+all[i]->query_cap_name()+", hacking into them!", all[i]);
                message("info", this_player()->query_cap_name()+
                    " spins and hacks into you with their blade!", all[i]);
            }
            else {
                write("Your blade hacks into "+all[i]->query_cap_name());
                say(this_player()->query_cap_name()+
                    " whirls at "+all[i]->query_cap_name()+", hacking into them!", all[i]);
                message("info", this_player()->query_cap_name()+
                    " spins and hacks into you with their blade!", all[i]);
            }
            name = all[i]->query_cap_name();
            all[i]->damage(dam);
            this_player()->add_sp(-dam/8);
            if(all[i]->query_hp() < 1) all[i]->heart_beat();
        }
    }
    this_player()->add_skill_points("attack", dam/20);
}
    return 1;
}

int abil() {
 if (this_player()->query_level() < 31) return 0;
 if (this_player()->query_class()=="fighter") return 1; }

void help() {
   write("Syntax: <whirl [(living)]>\n\n"
      "A fighter attack command that causes you to whirl at the objects in the room.\n");
}

