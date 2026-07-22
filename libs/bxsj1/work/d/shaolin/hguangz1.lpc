//hguangz1.c

inherit ROOM;

void create()
{
	set("short", "后殿广场");
	set("long", @LONG
这里是后殿广场，由大青石板拼成的地面上有几处凹凸的踏痕，似是以
前有高手施展内功所遗留的印记。几位执役僧正认真的进行清扫。
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
		      "east" : __DIR__ "hguangz2",
                      "north" : __DIR__ "hguangz4",
                      "southwest" : __DIR__ "huaishu5",
                      ]));
	set("coor/x",40);
  set("coor/y",330);
   set("coor/z",120);
   set("coor/x",40);
 set("coor/y",330);
   set("coor/z",120);
   setup();
	
}
int init()
{
//     add_action("do_ta","ta");   
}

int do_ta(string arg)
{         object me;
	me = this_player();
 if ( !living(this_player()) || arg != "sign" )
                 return 0;
        if ((int)me->query_skill("leg", 1) > 31)
        return notify_fail("再踏脚印已经无法再提高你的基本腿法了！\n");
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("你太累了，已经没有力气来踩踏脚印了！\n");              
        return 1;
}
        me->receive_damage("jing", random(35));
        message_vision("$N正在踩踏地面上的脚印。\n", me);  
        write("你觉得踩踏脚印对你的基本腿法有所促进。\n");
                  me->improve_skill("leg", me->query("int"));       
         return 1;
}


