#include <std.h>

inherit OBJECT;

int uses;
void create()
{
 set_name("ointment");
 set_short("A vial of ointement");
 set_long("This is a clearish pink vial of ointment. You can <apply ointment>"
          " and it will heal you.");
 set_id( ({ "vial", "ointment" }) );
 set_mass(2);
 set_value(10);
}

void set_uses(int x)
{
 uses = x;
}
void init()
{
 ::init();
 add_action("fApply", "apply");
}

int fApply(string str)
{
 if (!str || (str!="ointment" && str!="vial") )
   {
    notify_fail("Apply what?\n");
    return 0;
   }
 if (this_player()->query_disable())
   {
    write("You are too busy doing something else.");
    return 1;
   }
 this_player()->set_disable();
 write("You feel the ointment healing you");
 say( this_player()->query_cap_name() +"rub ointment upon
"+this_player()->query_title_gender()+" %^BOLD%^%^BLACK%^body.");
this_player()->heal( 50 + random(100) );
 this_object()->remove();
 return 1;
}
