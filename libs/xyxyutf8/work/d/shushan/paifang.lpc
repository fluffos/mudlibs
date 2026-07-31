#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "迎客牌坊");
        set("long",@LONG 
威严的石牌坊，不知道什么时候修建的石柱瘢痕累累，但是台阶却一尘不染，
高大的牌坊上面飞舞着：
LONG);
	set("long2",HIG"\n\t    蜀      山      剑      派  "NOR"\n\n");
        set("exits", ([
  		"north" : __DIR__"square",
  		"southdown" : __DIR__"path1",
	]));
	set("objects",([
        	__DIR__"npc/zhike" : 2,
        	__DIR__"npc/qingmo" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "shushan" );
        setup();
  	call_other("/obj/board/sword_b", "???");
}
