// Room: /d/tianshan/shishi.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "秘密石室");
	set("long", @LONG
这里是灵鹫宫的秘密石室，只见石室四壁岩石打磨得甚是光滑，石壁上刻
满了无数径长尺许的圆圈，每个圈中都刻了各种各样的图形，有的是人像，有
的是兽形，有的是残缺不全的文字，更有些只是记号和线条，圆圈旁注著「甲
一」、「甲二」、「子一」、「子二」等数字，圆圈之数若不逾千，至少也有
八九百个，墙上似乎有一行小字(Zi)，南边的墙上覆盖了一层厚厚的冰块。
LONG);   
	 set("item_desc", ([                    
                "zi": HIW"\n此墙左边是吾刻的是天山六阳掌要诀，右边是天山折梅手口诀。把南边墙\n"+
			"上的冰块(south bing)打破可以离开石室。\n\n"+
			"		                        天山童姥字\n\n"NOR,
        ])); 
	setup();
}

void init()
{
	add_action("do_learn", ({"yanxi", "learn"}));    
	add_action("do_break", ({"break", "po"}));    
}

int do_learn(string arg)
{
	object me;
	int improve, cost;
	me = this_player();
	improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);

	if( !arg || arg=="" ) return 0;

	if (arg == "east wall" ){             
		if( !me->query("tonglao/ok"))  
			return notify_fail("你看着墙壁看了半天，也不明白上面写的是什么。\n");
		if(me->query_skill("liuyang-zhang", 1) > 80 )  
			return notify_fail("墙上的六阳掌要诀对你来说太浅了。\n");

		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
			message_vision("$N专心的看着墙上的六阳掌要诀，突然头昏脑胀。\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$N默诵六阳掌要诀，不由在石室里比划起来。\n",me);  
		me->improve_skill("liuyang-zhang", improve);            
		me->add("jing", -cost);
		me->add("jingli", -cost);                        
		return 1;
	}
	if (arg == "west wall" ){             
		if( !me->query("tonglao/ok"))  
			return notify_fail("你看着墙壁看了半天，也不明白上面写的是什么。\n");
		if(me->query_skill("zhemei-shou", 1) > 80 )  
			return notify_fail("墙上的折梅手口诀对你来说太浅了。\n");

		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
			message_vision("$N专心的看着墙上的折梅手口诀，突然头昏脑胀。\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$N默诵折梅手口诀，不由在石室里比划起来。\n",me);  
		me->improve_skill("zhemei-shou", improve);            
		me->add("jing", -cost);
		me->add("jingli", -cost);                        
		return 1;
	}
	return 0;
}

int do_break(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "south bing" ){   
		message_vision("冰面应声而碎，现出一个大洞。\n", me); 
		message_vision("$N弯下身子，钻进了那个大洞，外面一阵寒风吹过，大洞又被积雪盖住了。\n", me);                      
		me->move(__DIR__"shanjin1");
		message("vision", me->name() + "从旁边一个不引人注目的大洞里钻了出来。\n",environment(me), ({me}) );
		return 1;
	}
	return 0;
}
