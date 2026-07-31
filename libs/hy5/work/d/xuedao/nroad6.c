// nroad6.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你走在一山路上，四周有一座座小山丘。远处可以看见终年积雪
的山尖。周围的树草已经很难看得到了。
LONG );
        set("exits",([
                "north"   : __DIR__"nroad7",
                "southup" : __DIR__"nroad5",
        ]));
        set("objects",([
                __DIR__"npc/huatiegan" : 1,
        ]));
//	set("no_clean_up", 0);
        set("outdoors", "xueshan");
        setup();
//        replace_program(ROOM);
}

void init()
{
	object me = this_player();
	if (!me->query_temp("szj/shui")) return;
	call_out("clone_shui", 1, me);
}

void clone_shui(object me)
{
	object *ob,obj;
	int i,j;

	if( environment(me) != this_object()) return;

	j=0;
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if ( (!userp(ob[i])) && ((string)ob[i]->query("id")=="shui sheng"))
		j=1;
	}
	if (!j) {
		obj=new(__DIR__"npc/shuisheng.c");
		obj->move(environment(me));
		message_vision(HIC"只听得叮玲玲，叮玲玲一阵铃声，一骑马自西至东，沿着江边驰来。\n"NOR, me);
	}
}
