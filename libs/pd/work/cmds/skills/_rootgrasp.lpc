#include <std.h>
inherit DAEMON;

int spell();

string type() { return "defense"; }

int cmd_rootgrasp(string str) {
    object ob, tp;
    int time, rounds, i, which, skip, rand, bonus, intt;
	object *inv;
    string what;
    
	if (!spell()) {
        return notify_fail("What?\n");
    }
    tp = this_player();
    
	if(environment(tp)->query_property("no magic") &&
      !wizardp(tp)) {
        return notify_fail("A magic force prevents you from doing that.\n");
    }
    
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            return notify_fail("What did you want to grasp?\n");
        }
    }
    else {
        ob = present(str, environment(tp));
        if(!ob) {
            sscanf(str, "%s %d", what, which);
            inv = all_inventory(environment(tp));
            for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
                if(inv[i]->id(what)) {
                    skip++;
                    if(skip == which) ob = inv[i];
                }
            }
            if(!ob) {
                notify_fail("No "+str+" here!\n");
                return 0;
            }
        }
    }
	 
    if(!living(ob))
        return notify_fail("You spell fails.\n");
        
    if(tp->query_ghost())
        return notify_fail("You appear to be dead.\n");

    if(!tp->ok_to_kill(ob))
        return notify_fail("You cannot attack them.\n");

    if (tp->query_disable())
      return notify_fail("You are busy.\n");

    if(tp->query_casting()) 
        return notify_fail("You are already casting a spell!\n");

	intt = tp->query_stats("intelligence");
	if(intt < 20)
	{
		rand = random(6);
		bonus = 0;	
	}	
	else if(intt >= 20 && intt <= 25)
	{
		rand = random(5);
		bonus = 0;		
	}	
	else if(intt >= 26 && intt <= 35)
	{
		rand = random(5);
		bonus = 1;		
	}	
	else if(intt >= 36 && intt <= 45)
	{
		rand = random(4);
		bonus = 1;		
	}		
	else if(intt >= 46 && intt <= 60)
	{
		rand = random(4);
		bonus = 2;		
	}
	else if(intt >= 61 && intt <= 90)
	{
		rand = random(3);
		bonus = 2;		
	}
	else if(intt >= 91 && intt <= 130)
	{
		rand = random(2);
		bonus = 3;		
	}
	else if(intt >= 131 && intt <= 180)
	{
		rand = random(2);
		bonus = 4;		
	}
	else
	{
		rand = 0;
		bonus = 5;		
	}			
    time = tp->query_skill("nature") + tp->query_skill("faith");
    time = time/2;
    
    time = time - (ob->query_stats("wisdom")*2);

	if(time < 162)
		rounds = 2;
	else if(time >=162 && time < 230)
		rounds = 3; 
	else if(time >=230 && time < 330)
		rounds = 4;		
	else if(time >=330 && time < 450)
		rounds = 5;
	else
		rounds = 6;
		
	rounds = rounds + bonus - rand;
	
    if (rounds < 1)
		return notify_fail("The roots fail to graps " +ob->query_cap_name()+ "!\n");

    if(tp->query_mp() < 35) 
        return notify_fail("Too low on magic power.\n");
    
    if(ob->query_paralyzed()) {
        write("The roots grab you!");
        tp->set_paralyzed(rounds);
        return 1; 
    }
    
	tp->add_mp(-(tp->query_skill("nature")/7 + (1+random(tp->query_stats("wisdom")/3))));
    
	this_player()->set_disable();
    
    ob->set_paralyzed(rounds, "The roots prevent your movement!");
      
    tp->add_skill_points("faith", time/20 + 2);
    tp->add_skill_points("nature", time/20 + 2);  
    
	write("%^GREEN%^You call upon %^BOLD%^m%^RESET%^%^GREEN%^o%^BOLD%^t%^RESET%^%^GREEN%^h%^BOLD%^e%^RESET%^%^GREEN%^r nature to put a stop to those who %^RED%^betray%^RESET%^%^GREEN%^ her!%^RESET%^\n");
	
	message("target", "%^GREEN%^A large number of %^ORANGE%^roots%^GREEN%^ sprout from the ground and %^RED%^grab%^GREEN%^ you!", ob);    

	message("room", "%^GREEN%^Large %^ORANGE%^roots%^GREEN%^ sprout out from the ground and %^RED%^grab%^GREEN%^ "
		+ob->query_cap_name()+ "!"
		, environment(tp), ob);
	
    return 1;
}
void help() {
    write("Syntax: <rootgrasp [enemy]>\n\n"
      "A druid can call upon mother nature to "
      "entangle the target in a large number of "
      "roots that sprout from the ground."
    );
}
int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_subclass() != "druid") return 0;
    if (tp->query_skill("nature") < 162) return 0;
	
    
    return 1;

}
