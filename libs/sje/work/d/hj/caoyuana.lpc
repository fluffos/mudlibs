// caoyuana.c 草原
inherit ROOM;
void create()
{
        set("short", "草原边缘");
        set("long", @LONG
这里是大草原和沙漠接壤之地，青草由稀至密，向西绵绵延伸而去。地上
有几行骆驼踏过的蹄印，看样子这里常常有商队来往。西南方好象有些炊烟。
LONG);
        set("exits", ([
            "east" : "/d/xingxiu/shamo4",
            "westup" : __DIR__"caoyuan2",
            "southwest" :__DIR__"caoyuan1",
            "north" : __DIR__"caoyuan",
            "south" : __DIR__"caoyuan",
        ]));
        set("outdoors", "草原");
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/steps",1);
       if (dir == "south") me->add_temp("mark/steps",-1);         
       if (me->query_temp("mark/steps") == 4){
            me->move(__DIR__"hswz");
            me->delete_temp("mark/steps");
             return notify_fail("唉。。。\n");
       }  
       if (me->query_temp("mark/steps") == -4){  
           me->move(__DIR__"caoyuan8");
           me->delete_temp("mark/steps");
             return notify_fail("唉。。。\n");
       }           
       return ::valid_leave(me, dir);
}
