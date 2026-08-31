#include <std.h>
#include <daemons.h>

#define OWLSMIND_PROP "owlsmind_spell_time"

inherit DAEMON;

int spell();

string type() { return "faith"; }

int query_waiting(object ob) { return ob->query(OWLSMIND_PROP) > time(); }

int cmd_owlsmind(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i, time, amount;
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
		return notify_fail("You must specify a target.\n");	
	}
    else if(str == "me") 
    {
        ob = tp;
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
    
    
    if (query_waiting(ob)){
        write("Your spell does nothing.\n");
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
        write("%^GREEN%^You call upon the primal nature of the %^BLACK%^%^BOLD%^wise owl%^RESET%^%^GREEN%^!");
        message("target", "%^GREEN%^You feel the power of the %^BLACK%^%^BOLD%^wise owl%^RESET%^%^GREEN%^ enter your body!", ob);
        message("room", "%^GREEN%^"+ob->query_cap_name()+
        	" seems to look wiser.", environment(tp), ob);  
    }
    else
    {
       write("%^GREEN%^You call the primal nature of the %^BLACK%^%^BOLD%^wise owl%^RESET%^%^GREEN%^ on yourself!");
       message("room", "%^GREEN%^"+ob->query_cap_name()+
        	" seems to look wiser.", environment(tp), ob);  
       
    }

    time = (tp->query_stats("wisdom")*8 + random(tp->query_stats("intelligence")*5));
    ob->set(OWLSMIND_PROP, time()+time);

	amount = 5;	

    ob->add_skill_bonus("magic attack", tp->query_base_skill("nature")/5, time);
    ob->add_stat_bonus("wisdom", tp->query_base_stats("wisdom")/4, time);

    tp->set_disable();
    tp->add_skill_points("nature", time/20 + 2);
    tp->add_mp(-(this_player()->query_skill("nature")/10 + (1+random(this_player()->query_stats("wisdom")/6))));
    
    DELAY_D->add_delay(time, this_object(), "debuff_off", ob, 1);
    
    return 1;
}
void debuff_off(object ob) {
        if(!ob) return;
        message("target", "%^GREEN%^You feel the nature of the wise owl leave you!", ob);
        message("room", "%^GREEN%^"+ob->query_cap_name()+" seems less wise."
			, environment(ob), ob);
        
}
void help() {
        write("Syntax: <owlsmind [(living)]>\n"
        "Druids can call on the primal nature of the "
		"wise owl, and bestow its gift on the target.\n");
}
int spell() {
   	object tp;
   	tp = this_player();

   	if (!tp) return 0;

   	if (tp->query_skill("nature") < 180) return 0;
   	if (tp->query_subclass() != "druid") return 0;
    
   	
	return 1;
}

