#include <std.h>
inherit OBJECT;

string query_type() { return "food"; }

void
create()
{
    ::create();
    set_value(1);
    set_weight(1);
    set_short("chocolate candy");
    set_long("A chocolate candy made by the Great Pumpkin!");
    set_name("candy");
    set_id(({"candy", "chocolate candy"}));
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
       return notify_fail("Get the candy first.");

   if (!this_player()->add_stuffed(this_player()->query_level()))
       return notify_fail("You are too full to eat the chocolate candy!");

   this_player()->heal((this_player()->query_level())/5);

   write("Yum Yum! Thank you Great pumpkin!");
   say(this_player()->query_cap_name()+" thanks the great pumpking for such a great piece of candy!");
   this_object()->remove();
   return 1;
}
