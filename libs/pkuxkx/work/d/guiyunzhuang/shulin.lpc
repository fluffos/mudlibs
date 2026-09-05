// guiyunzhuang/shulin树林
// Made By:pingpang
inherit ROOM;

void create()
{
        set("short", "树林");
       set("long", @LONG 
这是归云庄前的太湖边上的树林子，里面看起来阴森森的，让人不禁心寒！
LONG);
       set("exits", ([ /* sizeof() ==2 */
        "south" : __DIR__"shulin1",
	"west" : __DIR__"shulin2",
	"east" : __DIR__"shulin4",
	"north" : __DIR__"taihubian1",
        ]));
	set("objects",([__DIR__"npc/liehu":1,]));
        set("outdoors","guiyunzhuang"),
	setup();
}
int valid_leave(object me, string dir)
{
        if ( me->query("id") == "lao hu" &&  dir == "north" ) return 0;

        return ::valid_leave(me, dir);
}
