#include <std.h>
//#include <yourheaderhere.h>

inherit ROOM;

int cmd_ring(string);

void create()
{
    ::create();
        set_name("bell room");
        set_short("Bell Room");
        set_long("A large room with 3 bells, 1 large, 1 medium, 1 small.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
        ]));
        set_listen("default", "It is quiet");
        set_smell("default", "The air is stale.");
        set_exits(([
        ]));
        
}

void init()
{
    ::init();
    add_action("cmd_ring", "ring");
    
}

int cmd_ring(string str)
{
    if(!str)
    {
    write("Ring what?\n");
    return 1;
    }
    //if(str != "large bell" || str != "medium bell" || str != "small bell")
    //{
    //write("Now why would you want to ring " + str + "!\n");
    //return 1;
    //}
    
    if(str == "large bell")
    {
           write("You ring the large bell and a loud ringing fills the room.");
    }
    if(str == "medium bell")
    {
           write("You ring the medium bell and a loud ringing fills the room.");
    }
    if(str == "small bell")
    {
           write("You ring the small bell and a loud ringing fills the room.");
    }
    
    //large, small, large, medium, large
    
    if(str == "large bell" && this_player()->query("bell_combo") == 0)
    {
           this_player()->set("bell_combo", 1);
    }
    else if(this_player()->query("bell_combo") == 1)
    {
         if(str == "small bell")
         {
                this_player()->set("bell_combo", 2);
         }
         else
         {
                this_player()->set("bell_combo", 0);    
         }
    }
    else if(this_player()->query("bell_combo") == 2)
    {
         if(str == "large bell")
         {
           this_player()->set("bell_combo", 3);
         }
         else
         {
           this_player()->set("bell_combo", 0);                 
         }
    }
    else if(this_player()->query("bell_combo") == 3)
    {
         if(str == "medium bell")
         {
           this_player()->set("bell_combo", 4);
         } 
         else
         {
           this_player()->set("bell_combo", 0);     
         }   
    }
    else if(this_player()->query("bell_combo") == 4)
    {
		if(str == "large bell")
    	{
           this_player()->set("bell_combo", 0);
           write("You got the combo!");
		}
		else
		{
           this_player()->set("bell_combo", 0);	
		}
    }
    
    return 1;
}


