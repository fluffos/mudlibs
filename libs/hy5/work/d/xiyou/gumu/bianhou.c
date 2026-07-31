// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "古墓宝库");
        set ("long", @LONG
这是通往古墓宝库的唯一入口,入口处有两
只妖气冲天的狐狸把守着。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "down" :  __DIR__"zhongting",
        "north" :  __DIR__"mishi",     
        ]));

        set("objects", 
        ([ //sizeof() == 1
        __DIR__"npc/fox" : 2,
        ]));

//       set("outdoors", "changan");
//        set("no_clean_up", 0);
        setup();
//       replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
//     object me = this_player();
        object a;
   if (dir == "north" ) {
                if(objectp(a=present("hubao yaohu", environment(me))) &&
living(a) )
        return notify_fail("又是想盗墓的家伙！撩倒了姑奶奶我就让你进去!\n");
        }   
        return ::valid_leave(me, dir);
}

