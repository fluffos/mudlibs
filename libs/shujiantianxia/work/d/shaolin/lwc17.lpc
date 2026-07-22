//lwc17.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年的踩
踏已使得这些石板如同镜子般平整光滑。武场中央竖立着一个制作精巧的木
人，一些年青僧人正自围着它练功。
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc18",
		"north" : __DIR__"lwc16",
	]));
          set("objects",([
		__DIR__"obj/mu-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",260);
   set("coor/z",110);
   setup();

}

