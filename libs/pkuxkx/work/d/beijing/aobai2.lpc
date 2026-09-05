// Room: /city2/aobai2.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"鳌府大门"NOR);
	set("long",
HIC"一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门
两侧。门额上悬挂一方横匾，写着‘满洲第一勇士鳌拜府’几个大字，门外
有官兵把守，戒备森严。门上挂着两个灯笼，赫然写着“鳌”字。\n"NOR
	);
	set("exits", ([
		"east" : __DIR__"aobai1",
		"west" : __DIR__"aobai3",
	]));
	set("objects", ([
		__DIR__"npc/bj_bing" : 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    
    if(dir != "west" || (me->query("class") == "officer" && me->query("pin") < 7 ) || me->query("special_skill/sociability"))
        return ::valid_leave(me, dir);
    
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "guan bing" )
        {
        if( me->query("class") != "officer")
            return notify_fail("官兵拦住你骂道：“你以为你是谁啊？一个寻常百姓，难道还想进府见鳌大人？！\n你这" + RANK_D->query_rude(me) +"快给我滚远点儿，不然别怪我不客气！”\n");
        return notify_fail("官兵拦住你骂道：“你以为你是谁啊？一个小小芝麻官，难道还想进府见鳌大人？！\n你这" + RANK_D->query_rude(me) +"快给我滚远点儿，不然别怪我不客气！”\n");
        }
    }
    return ::valid_leave(me, dir);
}
