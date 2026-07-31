inherit ROOM;
void create()
{
        set("short", "前花园");
        set("long", @LONG
浣花的著名之处在这里可略见一斑，四边花草甚多，但唯有牡丹最胜。那花不是寻
常玉楼春之类，乃“姚黄”“魏紫”有名异品，一本价值五千。那花正种在朱门对面，
周围以湖石拦之。其花大如丹盘，五色灿烂，光华夺目。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guanyuge",
  "southwest" : __DIR__"qiao",
]));
	set("outdoors","huanhua");
        set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
