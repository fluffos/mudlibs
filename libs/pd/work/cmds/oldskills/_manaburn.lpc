//by Hermes
inherit DAEMON;
int spell();
int cmd_manaburn(string str) 
{
        object tp, ob;
        int attack, wisdom, skip, which, i, damaged;
        string what, *strengths, *weaknesses;
        object *inv;
        if (!spell()) 
        {
                write("What?\n");
                return 1;
        }
        this_player()->set_magic_round(1);
        tp = this_player();
        if(tp->query_ghost()) 
        {
                notify_fail("Your voice is hollow.\n");
                return 0;
        }
        if (this_player()->query_disable())
                return notify_fail("You are busy.\n");
        if(environment(tp)->query_property("no magic")) 
        {
                notify_fail("Something seems to be blocking your
concentration.\n");
                return 0;
        }
        if((int)tp->query_mp() < 350) 
        {
                notify_fail("Too low on magic power.\n");
                return 0;
        }
        if(!str) 
        {
                ob = (object)tp->query_current_attacker();
                if(!ob) 
                {
                        notify_fail("Who do you wish to burn?\n");
                        return 0;
                }
        }
        else 
        {
                ob = present(str, environment(tp));
                if(!ob) 
                {
                        sscanf(str, "%s %d", what, which);
                        inv = all_inventory(environment(tp));
                        for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) 
                        {
                          if(inv[i]->id(what)) 
                          {     
                                skip++;
                        if(skip == which) ob = inv[i];
                  }
                        }
                        if(!ob) 
                        {
                                notify_fail("No "+str+" here!\n");
                        return 0;
                        }
                }
        }
        if(!living(ob)) 
        {
                notify_fail(ob->query_cap_name()+" is not a living thing!\n");
                return 0;
        }
        if(ob == tp) 
        {
                notify_fail("How horrid.\n");
                return 0;
        }
        if(ob->is_player() && !interactive(ob)) 
        {
                notify_fail("You cannot attack link-dead players.\n");
                return 0;
        }
        if(!this_player()->kill_ob(ob)) 
        {
                write(ob->query_cap_name()+" can't be attacked by you yet.");
                return 1;
        }
        tp->force_me("say %^BLACK%^%^BOLD%^Although it be your life force true, mana will burn within you!\n");
        //*************************DAMAGE**********************************
        
attack = ((int)tp->query_stats("wisdom") * 3 + (int)tp->query_stats("intelligence") * 3 + ((int)tp->query_skill("magic attack")/2));
        wisdom = ((int)ob->query_skill("magic defense") / 5);
        attack = attack - wisdom;
        attack = attack * 3/2;
        //*************************DAMAGE**********************************
        tell_object(ob, "%^BOLD%^You collapse in pain as your mana turns into scorching fire in your body!\n");
    tell_room(environment(tp), "%^BOLD%^"+tp->query_cap_name()+" points at "+(string)ob->query_cap_name()+" and " + ob->query_subjective() + " screams in pain.\n", ({ ob, tp }));
    write("%^BOLD%^You focus your efforts into turning " + ob->query_cap_name() + "'s mana into deadly fire in " + ob->query_possessive() + " veins.\n");
        if (attack > ob->query_mp())
        {
                attack = ob->query_mp();
        }
        damaged = attack * 2/3;
        ob->add_mp(-attack);
        tp->set_casting(damaged);
        tp->set_disable();
        tp->add_skill_points("magic attack", (attack/5));
tp->add_alignment(-25);
        tp->add_mp(-(200 + random(150)));
        return 1;
}
        void help() 
{
        write("Syntax: <manaburn [(living)]>\n"
        "The ability of the Monk to combust the mana in their"
        "opponents bodies and turn it into pain is great use against mages"
        "\n");
}
int spell() {
object tp;
tp = this_player();
if (!tp) return 0;
if (tp->query_subclass() != "monk") return 0;
if (tp->query_level() < 35) return 0;
return 1;
}
