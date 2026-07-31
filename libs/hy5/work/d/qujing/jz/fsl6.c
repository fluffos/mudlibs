// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "封神台入口");
        set ("long", @LONG
     ※※※※※※※※※※※ 
         ※※※封  神  台※※※ 
         ※※※※※※※※※※※ 

这是通往封神台的唯一入口,入口处有两名守卫把守着。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "up": __DIR__"fst1",  
      "southdown": __DIR__"fsl5", 
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/qujing/jz/npc/guard.c" : 2,
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
   if (dir == "up" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("密林守卫拦住你说道:封神台不是什么人都能去的,你还是回头吧。\n");
        }   
        return ::valid_leave(me, dir);
}

