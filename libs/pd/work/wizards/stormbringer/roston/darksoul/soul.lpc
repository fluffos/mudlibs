#include <std.h>
#include <roston.h>

inherit OBJECT;

int uses;
void create()
{
 set_name("soul");
 set_short("%^BOLD%^%^BLACK%^A soul%^RESET%^");
 set_long("%^BOLD%^%^BLACK%^This is a soul "
          "of a past D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S"
          "%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s members. You "
          "can use the power of the soul by the command of <invoke>"
          " soul.");
 set_id( ({ "soul", "dark soul" }) );
 set_mass(2);
    set_curr_value("silver", 288);
}

void set_uses(int x)
{
 uses = x;
}
void init()
{
 ::init();
 add_action("fApply", "invoke");
}

int fApply(string str)
{
 if (!str || (str!="soul" && str!="dark soul") )
   {
    notify_fail("Apply what?\n");
    return 0;
   }
   
 if (this_player()->query_paralyzed())
   return notify_fail(this_player()->query_paralyze_message());

  if (this_player()->query_disable())
   {
    write("You are too busy doing something else.");
    return 1;
   }
 this_player()->set_disable();
 write("%^BOLD%^%^BLACK%^You invoke the power of the soul into your body.");
 say( this_player()->query_cap_name() +"%^BOLD%^%^BLACK%^ invokes a soul into
"+this_player()->query_title_gender()+" %^BOLD%^%^BLACK%^body.");
call_out("do_soul", 6, this_player() );
   this_object()->move("/d/standard/temporary");
 return 1;
}

int do_soul(object ob)
{
 ob->heal( 110 + random(200) );
 message("info", "%^BOLD%^%^WHITE%^Your eyes roll back in your head as you heal.",ob);
 this_object()->remove();
 return 1;
}
