// menlang.c
// By River@SJ
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short", HIC"浴"HIW"."HIR"血"HIW"."HIM"意念武馆"HIM"★"NOR);
        set("long", @LONG
武馆接待处顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔也就两三尺
的距离，朱红色的琉璃瓦，嫩黄色的地砖。门廊正中站着一个少年，看见你来
了，他笑嘻嘻地迎了上来。往北走就进入武馆的前院了。
LONG
     );        
     set("valid_startroom", 1);
        set("exits", ([
            "north" : __DIR__"qianting",
              "out": "/d/city/kedian",
        ]));

        set("no_fight",1);
        
        set("objects", ([
               __DIR__"npc/dizi4" : 1,
                 "d/city/npc/shizhe" : 1,
        ]));

        setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me,string dir)
{    
     object *inv = deep_inventory(me);
     object *obj;
//   if ( dir =="out")
//       return notify_fail("两扇黑漆漆的大门紧紧地关闭着，看来不能出去。\n");
     if(( me->query("combat_exp") < 2000000) 
      && dir != "north"
      && (present("sun jun", environment(me))))
         return notify_fail("孙均上前把手一伸：江湖险恶，你还是在武馆学点东西再出去吧。\n");  
     if (!me->query("离馆") 
      && dir !="north"
      && (present("sun jun", environment(me))))
         return notify_fail ("孙均把手一伸，拦住你的去路：没有馆主老人家的同意，不得私自离馆。\n");
     if (!me->query_temp("marks/离馆") 
      && dir !="north" 
      && (present("sun jun", environment(me))))
         return notify_fail ("孙均伸手一拦：你总得和我打声招呼才能走啊。\n");
     obj = filter_array(inv,(:get_object:));
     if( sizeof(obj)
      && dir !="north"
      && (present("sun jun", environment(me))))
         return notify_fail ("孙均朝你嘿嘿一笑：想偷偷带谁出去？\n");
         return ::valid_leave(me, dir);
}

