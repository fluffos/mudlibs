//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
一条不算平坦的小路，偶尔会有人骑着马匆匆而过。南边是一个小镇。
LONG );
        set("exits", ([
                "northeast" : "/d/yideng/yideng/road4",
                "south" : __DIR__"lx",
        ]));
        
        set("objects",([
            __DIR__"npc/daoniao":1
        ]));
        
        set("outdoors", "tiezhang");
        setup();
        replace_program(ROOM);
}