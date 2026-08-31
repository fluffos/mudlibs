#include <std.h>
inherit MOUNT;

void create() {
   ::create();
     set_name("unicorn");
     set_id( ({ "unicorn", "white unicorn" }) );
     set_short("%^BOLD%^WHITE%^White %^RED%^Unicorn");
     set_level(30);
     set_exp(random(50));
     set_long("The unicorns are wondrous creatures of magic and mystery. Few know where they came from, and it is amazing that this one is so tame. It has a shiny white coat the colour of snow, and its mane and horn have a golden tinge.");
     set_body_type("unicorn");
     set_race("unicorn");
     set_gender("male");
}

int __Ride(string str) {
    object ob;
    if(!str || str=="") {
      write("Ride what?");
      return 1;
      }
    ob = present(str, environment(this_player()));
    if(ob != this_object())
      return 0;
    if(this_player()->query_guild() != "illuminati") 
      return notify_fail("The unicorn bucks you off.\n");
    return ::__Ride(str);
}

string query_guild() {
       return "illuminati";
}
