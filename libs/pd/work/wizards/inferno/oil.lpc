#include <std.h>
inherit OBJECT;

int do_oil(object ob);

void create()
{
 set_name("oil");
 set_short("a vial of healing oil");
 set_long("A vial of enchanted healing oil. What it has been enchanted "
   "to do, or by whom, you have no idea.");
 set_id( ({ "oil", "healing oil" }) );
 set_mass(2);
 set_value(10);
}

void init()
{
 ::init();
 add_action("fApply", "rub");
}

int fApply(string str)
{
 if (!str || (str!="oil" && str!="healing oil") )
   {
    notify_fail("Apply what?\n");
    return 0;
   }
 if (this_player()->query_paralyzed())
   return notify_fail(this_player()->query_paralyze_message());

 write("You rub the oil to your bleeding wounds.");
 say( this_player()->query_cap_name() +" rubs healing oil on "+this_player()->query_title_gender()+" wounds.");
 do_oil(this_player());
 return 1;
}
   

int do_oil(object ob)
{
 int i;
 string *st;
ob->heal( 110 + random(200) );
ob->add_hp(110 + random(220) );
ob->add_sp((110 + random(220))*2 );
st = ob->query_limbs();
i = sizeof(st);
while(i--)
 ob->heal_limb(st[i], 110 + random(220) );

 message("info", "The oil goes through your wounds and heals them.",ob);
 message("info", "Miraculously, the vial refills itself.", ob);
 return 1;
}

int query_auto_load() { return 0; }
