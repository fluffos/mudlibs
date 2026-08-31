#include <std.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("hay");
 set_short("A bale of hay");
 set_long("The bale of hay is tied up using twine. It is for the "
          "Arlon horses to eat.");
 set_id( ({ "bale of hay", "hay", "bale" }) );
 set_mass(40);
 set_value(1);
}


void init()
{
 ::init();
 add_action("feed", "feed");
}

int feed(string str)
{
 if (!str || str=="" || (str!= "horse" && str!="horses" )) 
  { 
   write("Feed who?");
   return 1;
  }
 if (!present("horse", environment(this_player())))
   {
    write("You dont see any horses around.");
    return 1;
   }
 write("You feed the bale of hay to the horses.");
 say( this_player()->query_cap_name()+" feeds the bale of hay to the horses.");
 write("You feel you have done a special deed.");
 this_player()->set_mini_quest("horses", 50, "You fed the starving horses in Arlon.");
 this_object()->remove();

 return 1;
}
