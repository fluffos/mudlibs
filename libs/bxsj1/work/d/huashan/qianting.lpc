//Room: /d/huashan/qianting.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "前厅");
        set("long", @LONG
上得山来，忽然面前一片开阔，很多华山派弟子各自忙碌着。南边的房屋
门上挂着一块匾，上书五个大字「有所不为轩」。
LONG );
        set("exits",([
	"northdown" : __DIR__"taijie",
	"south" : __DIR__"zhengqi",
	"west" : __DIR__"celang1",
	"east" : __DIR__"celang2",
	]));

	set("outdoors", "华山" );

        set("coor/x",80);
  set("coor/y",-10);
   set("coor/z",80);
   setup();

        "/clone/board/huashan_b"->foo();
}
