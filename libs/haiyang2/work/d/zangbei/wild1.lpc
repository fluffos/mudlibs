 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "昆仑山区");
        set("long", @LONG
昆仑山的西麓，山峦起伏，风景秀丽，向北有著名的二郎山，神仙阁。据说山
里还住着一个人，这个人爱花，他住的地方就是座花海，一片花城。在不同的季节
中，那里总有不同的花盛开，他总是住在花开得最盛的那个地方。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"wild2",
//屏蔽老伯的路径
                "north": __DIR__"erlang",
                "south": __DIR__"mroom",
        ]));
	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 
        set("outdoors", "zangbei");
        set("coor/x",-1030);
        set("coor/y",150);
        set("coor/z",0);
        setup();
        
}    
