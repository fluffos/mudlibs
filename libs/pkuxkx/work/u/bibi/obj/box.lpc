#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIC"烟花盒"NOR, ({"camera"}));
   set_weight(500);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这个是用来放烟花用的，当然放别的也行！\n");
     set("unit", "个");
     set("value", 100000);
     set("material", "steel");
  }
     setup();
}

void init()
{
     add_action("do_firework","firework");
}

int do_firework()
{
        object *list;
	int i,j;
	list = users();
        j = sizeof(list);
    for(i=0;i<j;i++)
	tell_object(list[i],"\n【闲聊】\n");
	return 1;
}


	
