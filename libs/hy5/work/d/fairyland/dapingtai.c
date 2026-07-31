// Room: /u/qingyun/jyzj/dapingtai.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大平台");
	set("long", @LONG
这是一个三面皆空的极高的平台，平台有十余丈方园，可是半天临空，上
既不行，下亦不能，眼前只有茫茫云海，更无去路，平台之上有的是白皑皑的
冰雪，既无树木，更无野兽。这时你看见平台的左侧山壁处有一个黑黝黝的山
洞(dong)。
LONG	);
	set("exits", ([
		"west" : __DIR__"dashibi",
	]));
	set("outdoors", "kunlun");
        set("item_desc", ([
		"dong" : "一个黑黝黝的山洞，似乎可以钻(zuan)进去。\n"
	]));
	setup();
}

void init()
{
	add_action("do_zuan", "zuan");
	add_action("do_jump", ({"jump", "tiao", "yue"}));
}

int do_zuan(string arg)
{
object fang,who;
	object me = this_player();
who=me;
	if (arg == "dong") {
      if(!query("iskillok"))
      {
      message_vision("突然从周围传来二声娇喝 杀了我们家的狗狗，拿你的命来还吧!\n",who);	
      	fang = load_object(__DIR__"npc/zhu-jiuzhen");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object(__DIR__"npc/zhu-jiuzhen2");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 1;
      }			
		  	if((!(int)who->query_temp("book1231")))
	{
		message("vision", me->name() + "一个溜身，可是怎么也钻不进山洞。\n", environment(me), ({me}));
		return 1;	
	}
		  	if((!(int)who->query_temp("book1232")))
	{
		message("vision", me->name() + "一个溜身，可是怎么也钻不进山洞。\n", environment(me), ({me}));
		return 1;	
	}

		
		message("vision", me->name() + "一个溜身，钻进了山洞。\n", environment(me), ({me}));
		write("你急急忙忙的钻进了洞里，头撞上了山石，直痛你得哇哇大叫。\n");
		me->move(__DIR__"shandong");
		message("vision", me->name() + "钻了进来，头部撞到了山石上。\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "down"){
		message("vision", me->name() + "以纵身，向下跳去。\n", environment(me), ({me}));
		write("你不顾死活地向下跳去。\n");
		me->move(__DIR__"xuedi");
		write(HIR"\n啊......你从上面摔了下来，摔得浑身是痛，浑身是伤。\n\n"NOR);
                me->set_temp("last_damage_from", "跳下悬崖摔");
                me->receive_damage("qi", me->query("max_qi"));
                me->receive_wound("qi", me->query("max_qi") / 2);
		message("vision", me->name() + "从上面摔了下来。\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
