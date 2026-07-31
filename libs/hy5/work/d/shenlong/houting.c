// houting.c
inherit ROOM;
void create()
{
	set("short", "神龙教后厅");
	set("long", @LONG
这是神龙教的议事场所--潜龙厅.此厅较小,前面有两张大竹椅,
两边摆着五个小凳.
LONG );
	set("exits", ([
		"south" : __DIR__"dating",
		"north" : __DIR__"midao",
	]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([
		CLASS_D("shenlong")+"/yin": 1,
           "quest/menpai/shenlong/shi" : 1,
"/d/shenlong/obj/shenshe" : 2,
	]));
	set("outdoors","shenlong");
	setup();
	replace_program(ROOM);
}

