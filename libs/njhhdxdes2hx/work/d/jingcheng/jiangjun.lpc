// Room: /d/jingcheng/jiangjun.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m将军府[2;37;0m");
	set("long", @LONG
    这里是当朝大将的官邸，慕名来参拜的人也很多。大门两侧有
两头高大的石狮子。东边是一棵槐树，郁郁葱葱，遮盖了大半个院
子，整个院子里阴阴凉凉的。南边是个空场，大概是将军演武之地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jjun2",
  "north" : __DIR__"xw6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinyu" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);
	if( dir == "south" ){
		if( me->query("family/family_name") == "将军府"
		|| (int)me->query_temp("baishi") == 1
		|| !present( "qin yu", this_object() ) )
		return ::valid_leave(me, dir);
		for( i =sizeof(inv)-1 ; i >=0 ; i -- ){ 
			if( inv[i]->query("id") == "lingpai" ) 
				return ::valid_leave(me, dir);
		}
	return notify_fail(GRN"秦玉一下子伸出一手，拦住你说：不知"+
	RANK_D->query_respect(me)+"到将军府来有何贵干啊？(answer)\n"NOR);
	}
	return ::valid_leave(me, dir);
}
