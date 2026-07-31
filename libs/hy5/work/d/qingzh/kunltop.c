// kunltop.c 昆仑山顶峰
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;
void haoqing(object ob);

void create()
{
	set("short",BLINK+HIY "巍巍昆仑"NOR);
	set("long", HIW @LONG
你登上了昆仑山的顶峰！白雪皑皑，一片银装。
    站在这里放眼看去，只见茫茫群峰拜于脚下，江山万里尽收无遗，真乃江山多娇，
不觉感到豪情万丈，更联想到他日武功盖世之时就如同登临此峰，傲视群雄，号令武林
何等的威风... 
    想到得意之处便想对着群峰大喊(aload)：“天下武林，唯我独...
LONG 
NOR	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"northdown" : __DIR__"kunlun12",
		"southdown" : __DIR__"kunlun11",
	]));
		set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,
	]));	

//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
//	replace_program(ROOM);
}


void init()
{
	object ob;
	
	ob = this_player();
	remove_call_out("haoqing");
	call_out("haoqing",0,ob);

	add_action("do_aload", "aload");
}

void haoqing(object ob)
{
	int imqi,ioqi;
		
	imqi = (int)ob->query("max_qi");
	ioqi = (int)ob->query("qi");
//	ob->receive_damage("qi", ioqi );
        if(ioqi < imqi) 
                 tell_object(ob,HIR"    忽然风云突变，风雪扑面而来！刹时寒刺骨，飞雪割面，\n"
                                     "你被冻得龇牙咧嘴、鼻涕直流，刚才的一番豪情壮志早被这副\n"
                                     "这副狼狈相清扫的踪迹全无了！\n"
                                     "    你只想找个避风处躲起来！\n"NOR);
//	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));        
}
		
int do_aload(string arg)
{
        object me;
        me = this_player();
	if( random((int)me->query_skill("force")) <= 180) 
	{
//		me->receive_damage("qi", 50);
//		me->receive_wound("qi",  50);
		message_vision(HIR"$N这一喊可了不得了，只见山蹦地裂，乾坤倒转...雪崩了！！！  啊...\n"NOR, me);
		switch ( random(2) )
		{
			case 0 :
				me->move(__DIR__"kunlun11");
				break;
			case 1 	:
				me->move(__DIR__"kunlun12");
				break;
		}
		tell_object(me, HIR"你随积雪一起从山上滚了下来，只觉得浑身无处不疼，在雪中无法喘息，重伤之下...\n"NOR);
		message("vision", HIR"只见" + me->query("name") + "从山上与崩塌的大雪一同骨碌碌地滚了下来，一头插在雪堆里只见两脚朝天，半天爬不起来！\n"NOR, environment(me), me);
		if((int)this_player()->query("qi")<250) this_player()->die();
       		else this_player()->unconcious();
		return 1;
	}
        if (!arg||arg!="天下武林，唯我独尊！") return notify_fail("你瞎喊什么？\n");
	message_vision(HIY
		"\n$N这一声喊过，天地为之动容，山风为之喝彩，想必$N将成就一番大事业！\n"NOR, this_player());
        if (me->query("shen") > 0)  me->set("shen",(int)me->query("shen") + 100);
        else me->set("shen",(int)me->query("shen") - 100);
	message_vision(HIC
		"\n$N感动了上天，神增加了！\n"NOR, this_player());
	return 1;
}
