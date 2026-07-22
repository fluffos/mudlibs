// /d/hmy/qiandian.c

inherit ROOM;

int valid_leave(object me, string dir);

void create()
{
	set("short", "前殿");
	set("long", @LONG
来到一座雄伟的殿堂，大殿两旁分别立着八尊威武的塑像，高约八尺，手
中持着不同的武器，神态动作各异，而大殿当中设有一座祭坛，坛上燃烧着蓝
色的火焰，异常诡秘。
LONG
	);
	set("valid_startroom", "1");
	set("exits", ([ 
	  "east" : __DIR__"changlang",
	  "west" : __DIR__"shibanlu",
	]));
	set("objects", ([ 
		__DIR__"npc/shizhe" : 2,
	]));

	setup();
}
