// caoyuan1.c 草原

inherit ROOM;

void create()
{
        set("short", "大草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还真不好
走，看来买匹马来代步到是的好主意。南边和西边都有好多帐篷，往东可以看
见沙漠的边缘。
LONG);
        set("exits", ([
            "northeast" : __DIR__"caoyuan",
            "west" : __DIR__"caochang",
            "south" : __DIR__"majiu",
            "north" : __DIR__"caoyuan2",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/yang" : 2
        ]));
        set("outdoors", "草原");
        set("coor/x",-310);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}
