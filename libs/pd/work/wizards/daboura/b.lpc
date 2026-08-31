#include <std.h>                                    

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("healing mob");                               
        set_id( ({ "healing mob", "mob" }) );    
        set_short("Healing mob");                     
        set_long("A strange blob of a mob that heals itself.");        
        set_level(25 + random(5));                                  
        set_body_type("blob");                         
        set_race("blob");
    	set_gender("male");                             
        set_alignment(0);                            
        set("aggressive", 5);                         
}                  


void heart_beat()
{
    if(!environment(this_object())) return;
    
     
    
    if(sizeof(this_player()->query_attackers()) >= 2)
    {
        if(this_player()->query_hp() < 0)
        {
             message("info", this_player()->query_cap_name()+" dies a horrible death!", environment(this_object()));
         this_object()->die();
        }
       return;
    }
    else if(sizeof(this_player()->query_attackers()) > 0)
    {
        message("info", this_player()->query_cap_name()+" heals itself!", environment(this_object()));
        this_player()->heal(100);
    }
    
}
