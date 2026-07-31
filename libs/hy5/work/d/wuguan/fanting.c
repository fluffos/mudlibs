#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是武馆内用餐的地方。屋里布置很简单, 只摆着几张桌椅
几个人在一声不响地吃着。一个厨子在不停的忙碌着，你可以向他
要食物和水。
LONG);
        set("exits", ([
                "east" :"/d/wuguan/shilu-4",
        ]));

        set("objects", ([
//           __DIR__"npc/wang" : 1,
           __DIR__"npc/xiaost" : 1,
        ]));       
        set("no_fight", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
	object *ob;
        ob = deep_inventory(me);
	i = sizeof(ob);
	    
        if ((dir == "east") && present("wang chuzi", environment(me)) ){
           if(present("tea", environment(me)))
              return notify_fail("王厨子拦住你道：你还是先把茶喝完再走吧。\n"); 
           while (i--) 
              if (ob[i]->query("food_remaining")) {
                  switch ( random(2) ){
                      case 0: return notify_fail("王厨子不高兴的伸手拦住了你说：还是先把东西吃完了再走吧。\n"); break;
                      case 1: return notify_fail("王厨子拦住你道：饮食不得带出饭厅。\n"); break;
                      }
                  }
           }
       return ::valid_leave(me, dir);
}
