#include <std.h>

inherit OBJECT;

int open;
int cont;
string long_desc();
string short_desc();
void create() 
{
 set_name("beer");
 set_short( (: short_desc() :) ); 
 set_long( (: long_desc() :) );
 set_id( ({ "coors", "beer", "coors light" }) );
 set_mass(1);
 set_value(1);
 cont=100;
}
int init()
{
 ::init();
 add_action("cmdOpen", "open");
 add_action("cmdDrink", "drink");
}

int cmdDrink(string str)
{
 if (str!="beer") return 0;
 if (!open)
   {
    write("You try to drink a closed beer.");
    say(this_player()->query_cap_name()+ " tries to drink the closed beer.");
    return 1;
   }
 if (cont==0)
   {
    write("Your beer is empty!");
    return 1;
   }
 cont -= 25;
 write("You drink your beer and start grinning.");
 message("info", this_player()->query_cap_name()+" drink his beer and grins.", environment(this_player()), this_player());
 this_player()->add_intox(3);
this_player()->heal(400);
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

string short_desc()
{
 string str;

 if (cont==100) str = "(full)";
 if (cont==75)  str = "(nearly full)";
 if (cont==50)  str = "(half full)";
 if (cont==25)  str = "(partially empty)";
 if (cont==0)   str = "(empty)";
 return "%^RED%^%^BOLD%^Coors %^WHITE%^Light%^RESET%^ "+str;
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
          
 
