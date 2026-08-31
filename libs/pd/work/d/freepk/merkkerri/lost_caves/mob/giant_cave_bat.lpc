#include <std.h>                                    
#include <lost_caves.h>

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("giant cave bat");                               
        set_id( ({ "giant cave bat", "giant bat", "cave bat", "bat" }) );    
        set_short("Giant cave bat");                     
        set_long("A very large bat that hides in these caves. This bat looks like it could take on a dragon and win.");        
        set_level(55 + random(5));                                  
        set_body_type("fowl");                         
        set_race("Cave bat");
    	set_gender("male");                             
        set_alignment(0);                            
        set_class("fighter");                           
        set_subclass("warrior");                             
        set("aggressive", 55);                                 
        set_stats("dexterity",85); 
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
            if(random(100)>75)
            {       
                message("attacker", "The bat screeches at you!", ob);
                message("room", "The giant bat screeches at "+ob->query_cap_name()+ "!", 
                    environment(this_object()), ob);
                ob->set_paralyzed(3,"Your head is ringing from the screeching!");
            }
        }    
}

