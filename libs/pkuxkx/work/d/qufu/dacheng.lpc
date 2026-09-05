// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"大成殿"NOR);
        set("long", "这里因宋徽宗推崇孔子“集古圣先贤之大成”，是故称为大成殿。大殿正中\n是一尊"+HIY+"孔子像"+NOR+"(xiang)。\n");
        set("exits", ([
               "out" : __DIR__"kongmiao",
               
               
                
        ]));
        set("item_desc", ([
		"xiang" : "这是文圣的塑像，你看到之后不禁涌起拜祭(baiji)的冲动。\n",
	    ]));
        set("least_msg",1);
//        set("outdoors", "qufu");
        setup();
   
}

void init()
{
	add_action("do_baiji","baiji");
}

int do_baiji(string arg)
{
	object me;
	int times;
	me = this_player();

	if(!arg || (sscanf(arg, "xiang %d", times) != 1 && arg != "xiang"))
		return notify_fail("你想拜祭什么？\n");

	if(!times)
		times = 1;
	if(times > 50)
		return notify_fail("那么多次，心不够诚啊。\n");
  if(me->is_busy())
  {
  	write("你正忙着呐。\n");
  	return 1;
  }	

	if( (int)me->query("jing",) < 50 * times||
		  me->query("neili")<50 )
	{
		write("你的精不够，无法继续拜祭。\n");
		return 1;
	}

	message_vision("$N对着孔子像拜了下去。\n", me);

	if( (int)me->query_skill("literate",1) < 350)
	{
		return 1;
	}
	if( (int)me->query_skill("literate",1) > 500)
	{
		return 1;
	}

	tell_object(me,"你对着孔子像拜祭之后，突然福至心灵，对论语中的道理有所领悟。\n");
	me->add("jing", -50 * times);
	me->add("neili", -(times/2+1));

	me->improve_skill("literate",(int)(me->query("int")) * times);

	return 1;
}
