#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("配丹方",({"dan fang","fang"}));
	set_weight(50);
	if(clonep())
	    	set_default_object(__FILE__);
	else 
	{
      set("long",YEL"女娲石"NOR"的配方是:" NOR + HIG"天山雪莲"NOR + ", "+HIW"千年松果"NOR+","+HIY"老山参"NOR+","+BLK"巨蟒胆"NOR+"。\n"NOR);
               set("unit","个");
              set("value",500);
		setup();
	}
}
