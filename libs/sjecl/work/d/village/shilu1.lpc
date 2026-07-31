// Room: /d/village/shilu1.c

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村中人
家不多，而且大都生活很艰辛。这是一条南北向的碎石路，西面是间结实的民
宅。
LONG
        );
        set("exits", ([
		"west"  : __DIR__"minfang1",
		"north" : __DIR__"shilu2",
		"south" : __DIR__"sexit",
	]));
        set("outdoors", "华山");

	setup();
}

void init()
{
	object me = this_player();
	int times = me->query("random_job");
	if ((int)me->query("combat_exp") >1500000 
	&&  random(me->query("kar")) > 10
	&& (times < 5)
	&&  !(me->query_temp("hs/meetjob"))
	&&  me->query("neili") > 4000
        &&  random(600) == 251
 ) {
		tell_object(me, YEL"你正在路上走着，忽然路旁的民宅里传出“救命！”的喊声。\n"+
				"你不由得停下脚步，想走过去看个究竟。\n"NOR);
		me->add_busy(4 + random(4));
		me->set("random_job",times + 1);
		call_out("do_helpme", 4, me);
	}
} 

void do_helpme(object me)
{
	object ob;
	if (!me) return;
	tell_object(me, YEL"突然，从民宅里冲出一个人，你定睛一看，原来是个衣冠不整的少妇。\n"NOR);
	tell_object(me, HIC"那少妇惊慌地打量着你，上气不接下气的说道：“这位" + RANK_D->query_respect(me) + "，西面屋子里有个歹人，\n"NOR);
	tell_object(me, HIC"欲对小女子非礼，" + RANK_D->query_respect(me) + "能否救我一命？大恩大德，自有厚报。\n"NOR);
	tell_object(me, YEL"那少妇说完，飞也似的向北面逃去。\n"NOR);
	tell_object(me, YEL"你转过身向西面望去，发现那少妇所说的歹人就在里面。\n"NOR);
        ob=new(__DIR__"npc/chdd");
        ob->move(__DIR__"minfang1");
	me->set_temp("hs/meetjob", 1);
}
