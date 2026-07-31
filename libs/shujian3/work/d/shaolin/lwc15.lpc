//lwc15.c

inherit ROOM;

void create()
{
	set("short", "中心武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年的踩
踏已使得这些石板如同镜子般平整光滑。武场中央竖立着一个金光闪闪的金
人，几位老僧神色庄严，脚踏八卦方位围绕，缓缓发招。
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc11",
		"north" : __DIR__"lwc13",
	        "west" : __DIR__ "lwc16",
                "south" : __DIR__ "lwc18",
        ]));
         set("objects",([
		__DIR__"obj/jin-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",90);
  set("coor/y",270);
   set("coor/z",110);
   setup();

}

