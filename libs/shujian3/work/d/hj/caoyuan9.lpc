// caoyuan9.c 草原
inherit ROOM;
void create()
{
        set("short", "大草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还真不好
走，看来买匹马来代步到是的好主意。
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuan",
            "west" : __DIR__"caoyuan7",
            "east" : __DIR__"caoyuan8",
            "north" : __DIR__"caoyuan",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/yang" : 2
        ]));
        set("outdoors", "草原");
        set("coor/x",-300);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}
