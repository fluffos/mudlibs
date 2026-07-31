// senlin1.c

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "百木园");
	set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽
的小森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名
字的异种苗木。旁边立着一块牌子(pai zi)。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	    "south" : __DIR__"keting",
	    "north" : __DIR__"neiyuan",
	    "east" : __DIR__"senlin2",
	    "west" : __DIR__"neitang",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
	    "huang song" : "一株高大的黄松，挡住了你的视线。\n",
	    "pai zi" : "百木圣林，非请莫入，只可直行，切勿东向\n",
	]));
	set("outdoors", "meizhuang");
	setup();
}

