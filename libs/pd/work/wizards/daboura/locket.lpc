#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("%^BOLD%^%^RED%^locket%^RESET%^");
        set_id( ({ "locket", "necklace" }) );
        set_short("Small %^BOLD%^%^RED%^heart%^RESET%^ shaped locket");
        set_long("A lovely locket made of pure silver. It has several smaller hearts engraved on its surface. It looks as if it can be opened.");
        set_ac(0);
        set_curr_value("gold", 0);
        set_limbs( ({ "head" }) );
        set_weight(5);
        set_type("necklace");
        
}

void init()
{
    ::init();
    add_action("open_func", "open"); // function, command
}

int open_func(string str)
{
    if(str == "locket")
    {
        write("You carefully open the locket to see what is inside.");
        call_out("opened_locket",2);
    }
    else
        write("Open what?");
    return 1;
}

void opened_locket()
{
    write("You find a picture of Jared inside the locket, he seems to be almost smiling at you.");
}
 

int query_auto_load()
{
    if (this_player()->query_name() == "azire") return 1;
    return 0;
}
