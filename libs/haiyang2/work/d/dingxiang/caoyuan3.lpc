// caoyuan3.c 草原
inherit ROOM;
void create()
{
        set("short", "草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还
真不好走，看来买匹马来代步到是的好主意。西边可以看见燕原集，往
东去就是沙漠了。
LONG);
        set("exits", ([
            "southdown" : __DIR__"caoyuan2",
            "northwest" : __DIR__"shop",
            "southeast" : __DIR__"road1",
            "eastdown" : __DIR__"caoyuan",
            "northeast":__DIR__"caoyuan6",
          "west" : "/d/xinjiang/zhenlong",	
        ]));
        set("outdoors", "dingxiang");
        setup();
        replace_program(ROOM);
}
