// /d/hmy/baihutang.c

inherit ROOM;

void create()
{
	set("short", "白虎堂");
	set("long", @LONG
大堂内摆放着各种各样的武器，还有不同大小的沙袋、石锁、石盘等器具，
中央还竖立着几十根高低不等的木桩，教中弟子都在此练习武艺。 
LONG
	);
	set("exits", ([ 
	  "east" : __DIR__"zhuquetang",
	  "south" : __DIR__"changlang",
	]));
	set("objects", ([ 
	  __DIR__"npc/sang" : 1,
	]));

	setup();
}
