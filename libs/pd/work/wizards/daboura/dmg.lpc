#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("dmg formula");
    set_id(({ "damage formula", "formula" }));
    set_short("damage formula");
    set_long("damage formula");
    set_weight(0);
    set_curr_value("gold", 0);
}

void init()
{
    ::init();
    add_action("dmg_formula", "damage"); // function, command
}


void dmg_formula(string num) {

        float dmg = 0.0, total = 0.0;
        int i;
    
        dmg = 0.0;
        total = 0.0;
        if(!num)
            notify_fail("Need to pass a number!");

        if(sscanf(num,"%d",num) < 1) {
            notify_fail("Invalid number, must be greater than 0.\n");
        }

       
        for( i = 0; i < num; i++ )
        {
            dmg = 100 * (((2.0 / (num + 1)) + (1.0 / (i + 1.0))) / 2);
            total += dmg;
            write("Monster " + (i + 1) + " takes " + dmg +"% damage.\n");
        }
        
        write("Total damage done: " + total + "%\n");
        
        return 1;
}
