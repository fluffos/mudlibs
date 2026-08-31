#include <std.h>

inherit OBJECT;

int uses;
void create()
{
 set_name("flask");
 set_short("%^BOLD%^%^WHITE%^Fl%^YELLOW%^a%^WHITE%^sk %^YELLOW%^of %^WHITE%^O%^YELLOW%^i%^WHITE%^l");
 set_long("%^BOLD%^%^WHITE%^This flask of oil holds great healing power, you may %^YELLOW%^<quaff>%^WHITE%^ flask to open its power.");
 set_id( ({ "flask", "flask of oil","oil" }) );
 set_mass(3);
 set_value(10);
}

void set_uses(int x)
{
 uses = x;
}
void init()
{
 ::init();
 add_action("fApply", "quaff");
}

int fApply(string str)
{
 if (!str || (str!="flask" && str!="oil") )
   {
    notify_fail("Quaff what?\n");
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
 write("%^BOLD%^%^WHITE%^You Quaff down a Fl%^YELLOW%^a%^WHITE%^sk %^YELLOW%^of %^WHITE%^O%^YELLOW%^i%^WHITE%^l.");
 say( this_player()->query_cap_name() +" Quaffs a Flask of healing oil.");
call_out("do_soul", 6, this_player() );
   this_object()->move("/d/standard/temporary");
 return 1;
}

int do_soul(object ob)
{
 ob->heal( 175 + random(255) );
 message("info", "%^BOLD%^%^WHITE%^Your eyes glow %^YELLOW%^Golden%^WHITE%^ your cuts vanish your body is healed.",ob);
 this_object()->remove();
 return 1;
}
