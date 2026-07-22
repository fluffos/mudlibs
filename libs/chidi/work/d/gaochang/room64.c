// Room: room64.c
inherit ROOM;
void create()
{
        set("short", "昆仑山");
        set("long", @LONG
四下无声，只有风吹松涛，幽韵天成，仰视苍天，注视群山，令人不觉怆然
而发思古之幽情！往前看，只见一道飞岩，下临绝崖，往下看，峭壁如刀削，云
卷雾涌，深不见底。
LONG
        );
        set("exits", ([
  "north" : __DIR__"room61",
]));

        set("outdoors", "room64");
    setup();
}

void init()
{
   add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me,room;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪跳？\n");          
        message_vision("$N犹豫了一下，鼓气勇气，跳了下去。\n",me);

        if ((int)me->query_skill("dodge",1) < 600 ) {
                        message("vision",me->name()+"急剧向下坠去。看来是凶多吉少了!\n", environment(me), ({me}) );
                        if (!room=find_object(__DIR__"room66"))
                        room=load_object(__DIR__"room66");
                        me->move(room);
                        message("vision","砰！的一个人掉了下来。\n", room,({me}));
                        me->set_temp("die_for","掉下绝崖摔");
                        me->die();
                        return 1;
                }

           if (random(100)>50){ 
            if (!room=find_object(__DIR__"room66"))
              room=load_object(__DIR__"room66");
       }else{
                if (!(room=find_object(__DIR__"room75")))
                  room=load_object(__DIR__"room75");
           }

           me->move(room);
           message("vision","砰！的一个人掉了下来。\n", room,({me}));
           return 1; 
}

