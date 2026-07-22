// caoyuan1.c 草原
inherit ROOM;
void create()
{
        set("short", "草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还真不好
走，看来买匹马来代步到是的好主意。北边和西边都有好多帐篷，往东可以看
见沙漠的边缘。
LONG);

        set("exits", ([
            "eastdown" : __DIR__"caoyuan",
            "northwest" : __DIR__"shop",
            "west" : __DIR__"pmchang",
            "north" : "/d/xueshan/caoyuan/caohai1",
            "south" : __DIR__"caoyuan1",
            "northup" : __DIR__"road1",
        ]));

        set("outdoors", "草原");
        set("coor/x",-310);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
       if( dir == "north" && !userp(me))
            return notify_fail("...\n");      
       return ::valid_leave(me, dir);
}
