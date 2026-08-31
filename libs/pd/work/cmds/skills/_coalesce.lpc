#include <std.h>
inherit DAEMON;
mapping waiting;

int spell();

string type() { return "defense"; }

void create()
{
    waiting = ([]);
}

int query_waiting(object ob) { return waiting[ob]; }

int cmd_coalesce(string str) {
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
            return notify_fail("Coalesce what?\n");
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
        write("They have already had this cast upon them.\n");
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
        write("%^ORANGE%^You %^YELLOW%^snap%^RESET%^%^ORANGE%^ your finger and watch as " +ob->query_cap_name()+ 
            "'s %^BOLD%^%^RED%^blood%^RESET%^%^ORANGE%^ turns to %^BLACK%^%^BOLD%^metal%^ORANGE%^!%^RESET%^");
    
        message("target", "%^ORANGE%^" +tp->query_cap_name()+" snaps " +tp->query_possessive()+ 
            " finger, and suddenly you feel your %^BOLD%^%^RED%^blood %^BOLD%^%^BLACK%^hardening%^RESET%^%^ORANGE%^!%^RESET%^",
            ob);
        
        message("room", "%^ORANGE%^" +tp->query_cap_name()+" snaps " +tp->query_possessive()+ " finger, and suddenly " 
            +ob->query_cap_name()+ " seems to look slower!", environment(tp), ({tp,ob}));  
        if(!tp->kill_ob(ob) && ob->is_monster()) 
        {
                write(ob->query_cap_name()+" can't be attacked by you yet.");
                return 1;
        }
    }
    else
    {
        write("%^ORANGE%^You %^YELLOW%^snap%^ORANGE%^ your finger and watch as your %^BOLD%^%^RED%^blood%^ORANGE%^ turns to %^BLACK%^%^BOLD%^metal%^ORANGE%^!%^RESET%^");
        message("room", "%^ORANGE%^" +tp->query_cap_name()+" snaps " +tp->query_possessive()+ " finger, and suddenly " 
           +" they seems to look slower!", environment(tp), tp);  
    
    }

    time = (tp->query_stats("wisdom")/2 + random(tp->query_stats("intelligence")/6)) - ob->query_stat("wisdom")/5;    

    waiting[ob] = time;

    ob->add_skill_bonus("attack", -2*(ob->query_skill("attack"))/3, time);
    ob->add_stat_bonus("dexterity", -2*(ob->query_stats("dexterity"))/3, time);
    
    ob->add_skill_bonus("defense", ob->query_skill("defense")/3, time);
    ob->add_stat_bonus("constitution", ob->query_stats("constitution")/3, time);
   
    tp->set_disable();
    
    tp->add_mp(-(this_player()->query_skill("wizardry")/8 + (1+random(this_player()->query_stats("wisdom")/4))));
    
    call_out("debuff_off", time, ob);
    
    return 1;
}
void debuff_off(object ob) {
        if(!ob) return;
        message("target", "%^ORANGE%^You feel your blood loosen up!%^RESET%^", ob);
        message("room", "%^ORANGE%^"+ob->query_cap_name()+" looks like "+ob->query_subjective()+
            " can move quicker than before!", environment(ob), ob);
        ob->fix_vital_bonus();
        
        map_delete(waiting, ob);
}
void help() {
        write("Syntax: <coalesce [(living)]>\n"
        "The wizard hardens the blood of the  "
        "target, slowing them down, but making "
        "them tougher.\n");
}
int spell() {
   object tp;
   tp = this_player();

   if (!tp) return 0;
   if (tp->query_level() < 15) return 0;
   if (tp->query_skill("wizardry") < 90) return 0;
   if (tp->query_subclass() != "wizard") return 0;
   return 1;

    

}
