//封神台
//by junhyun@SK
inherit ROOM;
void create ()
{
        set ("short", "封神台");
        set ("long", @LONG
     ※※※※※※※※※※※ 
         ※※※封  神  台※※※ 
         ※※※※※※※※※※※ 

这里就是千年封神台，当年许多神仙妖魔都曾经
在此接受洗礼，脱去凡身，步入神界。
LONG);

        set("exits", 
        ([ //sizeof() == 4
      "down": __DIR__"fsl6", 
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
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("密林守卫拦住你说道:封神台不是什么人都能去的,你还是回头吧。\n");
        }   
        return ::valid_leave(me, dir);
}

