// /d/emei/maocaowu.c 峨嵋派 茅草屋
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间清幽的小茅草屋，四周墙壁是用粗大的树干捆扎起来的，屋
顶上方铺满了稻草。屋内摆设比较简单，除几种常用的桌椅外，在中间墙
壁上挂了一张『踏雪图』。
LONG
	);
	set("exits", ([ 
                "north" : __DIR__"liba", 
		]));
	set("objects", ([ 
	CLASS_D("emei") + "/zhou" : 1,
      ]));

	setup();
	replace_program(ROOM);
}
