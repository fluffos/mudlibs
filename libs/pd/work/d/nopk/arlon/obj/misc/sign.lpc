#include <std.h>

inherit OBJECT;

void create()
{
 set_name("sign");
 set_short("A wooden sign");
 set_long("A wooden sign, it seems to have somethin written on it.");
 set_id( ({ "sign", "wooden sign" }) );
 set_mass(1);
 set_value(1);
 set_prevent_get("The sign is buried.");
}

void init()
{
 ::init();
 add_action("read", "read");
}
int read(string str)
{
 if (str!="sign") 
   {
    notify_fail("Read what?");
    return 0;
   }
 write(""
"|--------------------|\n"
"|   Welcome to the   |\n"
"|   town of Arlon.   |\n"
"|--------::----------|\n"
"         ::\n"
"__\\|/____::________\\/_");

return 1;
}
int get() { return 0; }
