#include <std.h>
inherit DAEMON;
mapping waiting;

int spell();

string type() { return "other"; }

void create()
{
    waiting = ([]);
}

int query_waiting(object ob) { return waiting[ob]; }

int cmd_mercurial(string str) {
        object tp, ob;
        int attack, wisdom, skip, which, i, time;
        string what, *strengths, *weaknesses;
        object *inv;
    
    if (!spell()) 
    {
      return 0;
    }
    
    tp = this_player();
    
    if(tp->query_casting()) return notify_fail("You are already casting a spell!\n");
    if (tp->query_disable())
        return notify_fail("You are too busy to cast this spell.\n");
    
    tp->set_magic_round(1);
    
    if(!str) 
    {
        ob = (object)tp->query_current_attacker();
        if(!ob) 
        {
            return notify_fail("Mercurial what?\n");
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
    
    
    if (waiting[ob]){
        write("You spell bounces off into the sky.\n");
        return 1;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something seems to be blocking your spell.\n");
        return 0;
    }
    if (this_player()->query_disable())
        return notify_fail("You are too busy.\n");
    if(ob != tp)
    {
        write("%^ORANGE%^You look towards the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^ORANGE%^ and call down an %^BOLD%^%^BLACK%^anc%^GREEN%^i%^BLACK%^ent%^RESET%^ %^RED%^power%^RESET%^%^ORANGE%^ down upon " +ob->query_cap_name()+ 
            "!%^RESET%^");
        
        message("target", "%^ORANGE%^" +tp->query_cap_name()+
            " looks toward the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^ORANGE%^, and suddenly you feel more %^BOLD%^%^RED%^powerful%^RESET%^%^ORANGE%^!%^RESET%^",
            ob);
        
        message("room", "%^ORANGE%^" +tp->query_cap_name()+" looks toward the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^ORANGE%^, suddenly "
            +ob->query_cap_name()+ " looks quicker!", environment(tp), ({tp,ob}));  
        
        ob->force_me("grin");
    }
    else
    {
        write("%^ORANGE%^You call down an %^BOLD%^%^BLACK%^anc%^GREEN%^i%^BLACK%^ent%^RESET%^%^ORANGE%^ power down from the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^ORANGE%^!%^RESET%^");
        message("room", "%^ORANGE%^" +tp->query_cap_name()+" looks to the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^ORANGE%^ " 
           +" and seems to look quicker!", environment(tp), tp);  
        tp->force_me("grin");
    }

    time = (tp->query_stats("wisdom")*2 + random(tp->query_stats("intelligence")));
    waiting[ob] = time;

    
    ob->add_skill_bonus("stealing", ob->query_skill("stealing")/5, time);
    ob->add_stat_bonus("dexterity", ob->query_stats("dexterity")/4, time);
    ob->add_stat_bonus("intelligence", ob->query_stats("intelligence")/5, time);
    ob->add_stat_bonus("wisdom", ob->query_stats("wisdom")/5, time);
   
    tp->set_disable();
    
    tp->add_mp(-(this_player()->query_skill("wizardry")/8 + (1+random(this_player()->query_stats("wisdom")/4))));
    
    call_out("debuff_off", time, ob);
    
    return 1;
}
void debuff_off(object ob) {
        if(!ob) return;
        message("target", "%^ORANGE%^You feel something leave your body!%^RESET%^", ob);
        message("room", "%^ORANGE%^"+ob->query_cap_name()+" looks like "+ob->query_subjective()+
            " is far slower!", environment(ob), ob);
        
        map_delete(waiting, ob);
}
void help() {
        write("Syntax: <mercurial [(living)]>\n"
        "A powerul wizard can tap into ancient "
        "energies and increase the power of the "
        "target.\n");
}
int spell() {
   object tp;
   tp = this_player();

   if (!tp) return 0;
   if (tp->query_level() < 50) return 0;
   if (tp->query_skill("wizardry") < 275) return 0;
   if (tp->query_subclass() != "wizard") return 0;
   return 1;

    

}
