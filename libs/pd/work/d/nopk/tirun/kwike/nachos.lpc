#include <std.h>
inherit OBJECT;

string query_type() { return "food"; }

void
create()
{
    ::create();
    set_value(1);
    set_weight(1);
    set_short("package of nachos");
    set_long("Kwik-E Mart nachos with chilli and cheese.");
    set_name("Nachos");
    set_id(({"nachos", "package of nachos"}));
}

void
init()
{
    ::init();
    add_action("cmd_eat", "eat");
}

int
cmd_eat(string what)
{
   if (!id(what))
       return 0;

   if (environment(this_object()) != this_player())
       return notify_fail("Get the nachos first.");

   if (!this_player()->add_stuffed(this_player()->query_level()))
       return notify_fail("You are too full to eat these delicious nachos...");

   this_player()->heal((this_player()->query_level())/2);

   write("mmmmm nachos.....\n"
         "you spill a little cheese as you munch on your nachos.");
   say(this_player()->query_cap_name()+" spills some cheese off "+
       this_player()->query_title_gender()+" nachos.", this_player());
   remove();
   return 1;
}
