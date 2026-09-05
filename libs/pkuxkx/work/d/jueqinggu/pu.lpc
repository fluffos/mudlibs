// Room: /city/kedian3.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"花圃"NOR);
	set("long", @LONG
这里是一座花圃，种植着被精心照料的情花(hua)。
LONG);


	set("exits", ([
	//	"east" : __DIR__"zoudao2",
    //    "northup" : __DIR__"shanpo",
        "out" : __DIR__"huapu",
	]));
    set("item_desc", ([
		"hua" : "情花娇艳欲滴，让人忍不住采摘(cai)一朵。\n", 
	]));
    set("outdoors", "jueqinggu");
	setup();
}

void init()
{
    add_action("do_cai","cai");
}

int do_cai()
{
    object hua;
    object me=this_player();
    if (!me->query_temp("绝情丹"))
    {
		F_POISON->poison_attack(this_object(),me,"anran_poison", me->query_condition("anran_poison")+10+random(20));
        message_vision(RED"$N暗道一声：不妙，手上被情花刺开了一道小口子。\n"NOR,me);
        return 1;
    }
    else
    {
        hua=new(__DIR__"obj/flower");
        hua->move(me);
        me->delete_temp("绝情丹");
        message_vision("$N动作潇洒的摘下了一朵情花。\n",me);
        return 1;
    }
}