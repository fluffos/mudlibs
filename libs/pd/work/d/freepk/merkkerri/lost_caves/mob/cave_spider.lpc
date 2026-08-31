#include <std.h>                                    
#include <lost_caves.h>

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("cave spider");                               
        set_id( ({ "cave spider", "spider"}) );    
        set_short("Cave spider");                     
        set_long("A normal sized cave spider, which is not to say that it isn't about as large as a boulder.");        
        set_level(55 + random(5));                                  
        set_body_type("arachnid");                         
        set_race("cave spider");
    	set_gender("male");                             
        set_alignment(0);                                                         
        set("aggressive", 75);                                 
        set_stats("dexterity",95);  
        set_max_hp(5500);
        set_hp(5500);
        set_max_sp(1000);
        set_sp(1000);
}                  


void heart_beat()
{
    object ob;
    ::heart_beat();
        if(!environment(this_object())) return;

        if(ob = this_object()->query_current_attacker())
        {
            if(random(100)>80)
            {       
                message("attacker", "The spider bites you!", ob);
                message("room", "The cave spider bites "+ob->query_cap_name()+ "!", 
                    environment(this_object()), ob);
                ob->damage(25+random(25));
                ob->add_poisoning(10+random(20));
            }
        }    
}

