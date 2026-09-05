inherit ROOM;
#include <ansi.h>
#include "/d/southmountain/xitianmu/ecology.h"
int gene_animals();
int clear_room();
void create()
{
	set("short", "山间路"+NOR);
	set("long", @LONG
这里是进入白狼山的山间路。
LONG
	);
        set("outdoors", "heishan");

	set("exits", ([
		"north" : __DIR__"bailangn2",
		//"southeast" : __DIR__"shanluw1",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
	set("init_time",time());
	gene_animals();
	clear_room();
}
int clear_room()
{
	object *all=all_inventory(this_object());
	for (int i=0;i<sizeof(all);i++)
	{
		if (!all[i]->is_character())
			destruct(all[i]);
	}
	tell_object(this_object(),"大风吹走了地上的东西。\n");
	set("no_clean_up", 1);
	set("no_reset", 1);
	remove_call_out("clear_room");
	call_out("clear_room",800);
}
int gene_animals()
{
	gene_eco(__DIR__"npc/bear","/d/northmountain/heishan/",10);
	gene_eco(__DIR__"npc/deer","/d/northmountain/heishan/",10);
	remove_call_out("gene_animals");
	call_out("gene_animals",1200);
	return 1;
}