// caoyuan.c 草原
inherit ROOM;
void create()
{
        set("short", "草原边缘");
        set("long", @LONG
这里是大草原和沙漠接壤之地，青草由稀至密，向西绵绵延伸而去。
地上有几行骆驼踏过的蹄印，看样子这里常常有商队来往。西南方好象有
些炊烟。
LONG);
        set("exits", ([
           "southwest" : __DIR__"caoyuan1",
            "northwest" : __DIR__"caoyuan2",
            "northup" : __DIR__"caoyuan3",
            "north" : __DIR__"dadao1",
            "south" : __DIR__"caoyuan1",
            "east":__DIR__"ximen",
        ]));
        

        
        set("outdoors", "dingxiang");
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/steps",1);
       if (dir == "south") me->add_temp("mark/steps",-1); 
        
       if (dir=="north"&&me->query_temp("mark/steps")<4){
       	  me->add("water",-10-random(10));
       	  if(me->query("water")<=0)
       	   me->set("water",0);
       	  return notify_fail("你非常口渴，几乎走不动路了！\n");
       }
       if (dir=="south"&&me->query_temp("mark/steps")>-4){
       	  me->add("water",-10-random(10));
       	  if(me->query("water")<=0)
       	   me->set("water",0);
       	  return notify_fail("你非常口渴，几乎走不动路了！\n");
       }
        me->delete_temp("mark/steps");
        return ::valid_leave(me, dir);
}
