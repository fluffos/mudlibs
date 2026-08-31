#include <std.h>

inherit OBJECT;

int open;
int long_desc();

void create() 
{
 set_name("beer");
 set_short("%^RED%^%^BOLD%^Coors %^WHITE%^Light%^RESET%^");
 set_long( (: long_desc() :) );
 set_id( ({ "coors", "beer", "coors light" }) );
 set_mass(1);
 set_value(1);
}
int init()
{
 ::init();
 add_action("cmdOpen", "open");
 add_action("cmdDrink", "drink");
}

int cmdDrink(string str)
{
 if (present(str, this_player()) != this_object()) return 0;
 if (!open) return notify_fail("You must open it first.");
 write("You chug down your beer and start grinning.");
 message("info", this_player()->query_cap_name()+" chugs his beer and grins.", environment(this_player()), this_player());
 this_player()->add_hp(40);
 this_player()->add_sp(90);
 if (this_player()->query_mp() > 51)
  this_player()->add_mp(-50);
 if (!wizardp(this_player())) {
    this_player()->add_intox(420);
    write("Your mortal body can barely handle the alcohol in this drink!");
 } else this_player()->add_intox(30);
 this_object()->remove();
 return 1;
} 
int cmdOpen(string str)
{
 if (!str || str!="beer") 
   {
    return 0;
   }
 if (open)
   {
    write("Your beers already open slick.");
    return 1;
   }
 write("You open your beer and makes a hissing noise.");
 message("info", this_player()->query_cap_name()+" opens a beer.", environment(this_player()), this_player());
 open = 1;
 return 1;
}
int drop()
{
 if (!open) return 0;
 
 write("You drop your beer and spill it all over the floor.");
 message("info", this_player()->query_cap_name()+ " spills his beer all over the ground.", environment(this_player()), this_player());
 this_object()->remove();
 return 1;
}

string long_desc()
{
 string str;
 
 if (open) str = "\nThe can is open."; 
   else str = "\nThe can is closed.";

 return "The can has little peices of ice stuck to the side of "
          "it, making you think how cold and great tasting it would "
          "be to drink it. It is a round all can that has white "
          "mountains."+str;
}
          
 
