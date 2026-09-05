// 尸首

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
object money;
if(!query("money"))
{

switch(random(40)){
case 2:
case 4:
case 6:
case 10:
case 15:
case 20:
case 30:
money=new("/clone/money/silver");
money->move(this_object());
break;
case 38:
money=new("clone/money/gold");
money->move(this_object());
break;
default:
money=new("clone/money/coin");
money->move(this_object());
break;
}
set("money",1);
}
}

void create()
{
        set_name(HIC"尸体"NOR, ({"corpse" }));
        set_weight(200000);
set("no_get",1);
 set_max_encumbrance(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "前来示威百姓的尸体。\n");
                set("unit", "具");
                set("material", "meat");
        }
        setup();
}

