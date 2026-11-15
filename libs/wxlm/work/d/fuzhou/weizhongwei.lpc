// jiulou.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "味中味");
	set("long", @LONG
提起“楼外楼”方圆百里无人不知。这里各式闽菜均是
福州一绝。来游湖的人们都一定会来这里尝尝。整个大堂闹
哄哄的挤满了各式人等。店小儿跑来跑去，忙着招呼客人。
墙上挂着价格牌子。
LONG);
	set("exits", ([
	    "west"  : __DIR__"nandajie",
	    "north"  : __DIR__"chufang",
	]));
	set("objects", ([
	    __DIR__"npc/xiaoer3" : 1,
	]));
	set("item_desc", ([
	    "【牌子】" : "
佛跳墙(Fotiaoqiang)   ：五两白银
福建老酒(Jiuping)     ：二两白银\n",
	]));
	setup();
}

