// taihubian1.c 太湖边
//Made By:pingpang
inherit ROOM;

void create()
{
    set("short", "太湖边");
    set("long", @LONG
这里风景秀丽，是观光的好地方，来往穿梭着各地游客。
LONG);
        set("exits", ([ /* sizeof() == 2*/
        "east" : __DIR__"bridge",
	"west" : __DIR__"taihujie3",
	"northup" : __DIR__"shanlu1",
	"south" : __DIR__"shulin",
        ]));
	set("objects",([__DIR__"npc/youke":2,]));
        set("outdoors","guiyunzhuang");
	setup();
	replace_program(ROOM);
}
