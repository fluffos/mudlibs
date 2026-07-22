inherit ROOM;
#include <room.h>

void create()
{
      set("short","客厅");
      set("long",@LONG
这里是山庄中接待客人的地方，两排红木雕成的椅子整齐的摆放在那里
中间的茶几上放着鲜果和茶具,整个大厅显得宽敞明亮,墙上挂着几幅山水
画波墨流彩,湖清风静,使大厅在安静之中装饰着典雅,还没看见主人,几个
茶童站在那里忙前忙后

LONG);
                set("objects",([
         "/u/legato/npc/yun chengfeng":1,
       ]));

      set("exits",([ /* sizeof() == 1 */
          "north": __DIR__"bedroom",
          "east"  : __DIR__"shufang",
          "west"  : __DIR__"fanting",
          "south": __DIR__"path1",
]));
    
      setup();


}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "雁荡派") && 
                objectp(present("yun chengfeng", environment(me))))
           return notify_fail("云乘风喝道：家师内室，不得入内。\n");

        return ::valid_leave(me, dir);
}

