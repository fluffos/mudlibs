
// Room: /d/beijing/shiweiying.c
#include <ansi.h>
inherit ROOM;
#include "beijing_defs.h"

void create()
{
        set("short", HIY"侍卫营大门"NOR);
        set("long",
HIC"这里是京城侍卫们的地盘。大门虽然不如王公大臣府第的豪华
阔绰，可也是毫不含糊的。侍卫们平日鱼肉乡里，京城百姓走到这儿
可都是小心谨慎，见了侍卫们就陪笑脸。\n"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"jiaochang",
        "south" : __DIR__"dongzhidajie",
        "northdown" : __DIR__"shiwei_wuqiku",
        ]));

        set("objects", ([
        __DIR__"npc/shiwei3":2,
        __DIR__"npc/shiwei_jiaotou":1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object *ob;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
	if( dir != "north" || me->query("class") == "officer" 
		|| me->query_temp("chaoting/toujun"))
		return ::valid_leave(me, dir);
	ob = all_inventory( environment( me ));
	for(i=0; i<sizeof(ob); i++)
	{
		if( living(ob[i]) && (ob[i]->query("id") == "sandeng shiwei"
			|| ob[i]->query("id") == "shiwei jiaotou"))
			return notify_fail("侍卫伸手把你给拦住了。\n「干什么的？是想投军么？……」\n");
	}
	return ::valid_leave(me, dir);
}
