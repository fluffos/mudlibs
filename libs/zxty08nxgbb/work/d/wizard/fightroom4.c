// Room: /d/wizard/fightroom4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "石拱门");
    set("long", @LONG
只见正门上面筒瓦泥鳅脊，拱门阁俱是细雕花样，并无朱粉涂饰，清一色水
磨群墙，白石台阶，凿成西番莲花样，左右雪白粉墙，下面虎皮石砌成纹理。拱
门的上面挂个一块檀木大匾，匾上刻着『以 武 会 友』四个烫金大字。
LONG
    );
    set("exits", ([ 
  "west" : __DIR__"fightroom5",
  "north" : __DIR__"fightroom1",
]));
    setup();
}
