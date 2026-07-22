//zoulang1。c             血河派--走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是血河派内地的走廊，两旁是大理石筑成的柱子，上面刻有一些
花鸟图案，有的还附有一些佛文经段，可见血河派的能工巧匠不乏其人。
由于血河派弟子从不与外界来往，因此此处显得格外阴森恐怖，好象不时
有人影从身边飘过，让人不由望而止步。
LONG);
	set("valid_startroom",1);
	set("outdoors","龙门");
	set("exits", ([
		"east" : __DIR__"gongfengtang",
		"westup" : __DIR__"qixuetang",
	]));
	setup();
}
