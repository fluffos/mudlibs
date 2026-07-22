// Room: rimulundian.c

inherit ROOM;
#include <room.h>
#include <ansi.h>

void create()
{
        set("short", "日木伦殿");
        set("long", @LONG
大殿高四层，上覆金顶，辉煌壮观。不但有中原的建筑风格，也吸收了天竺
和回纥等建筑艺术特色。正殿大柱上斗拱架梁浮雕精美，有人物、天鹅、象等鸟
兽。殿前围墙正中有扇黑漆小门通向寺前各处。
LONG
        );

         set("exits", ([
                "north" : __DIR__"hufazhacang",
                "west" : __DIR__"yueliangmen",
                "east" : __DIR__"chiyangmen",
                "southeast" : __DIR__"zhaitang",
                "out" : __DIR__"xiekemen",
        ]));

          set("objects", ([__DIR__"npc/fanseng" : 2]));
        
        setup();
        create_door("out", "黑漆木门", "enter", DOOR_CLOSED);                   
}
int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
        
         object *obj;
        
          
        if ((string)me->query("gender") == "男性" && dir == "west"
           && present("hufa lama", environment(me)))
                return notify_fail("护法喇嘛拦住你道：那里是本寺女弟子休息的居所，你去不大方便吧？\n");

        if ((string)me->query("gender") == "女性" && dir == "east"
           && present("hufa lama", environment(me)))
                return notify_fail("护法喇嘛拦住你道：那里是本寺男弟子休息的居所，你去不大方便吧？\n");
        if(dir == "southeast"&& me->query("family/family_name")!= "大轮寺"
           && present("hufa lama", environment(me)))
             return notify_fail(CYN"护法喇嘛拦住你说道:最近寺内伙食紧张，外派弟子请到寺外自行解决。\n"NOR);
        obj = filter_array(deep_inventory(me),(:get_object:));
        if( sizeof(obj) && dir=="southeast" ) {
                write (HIR"你刚想偷偷背个人进去，结果负重太多，脚下一个绊拴，摔倒在地。\n"NOR);
                obj[0]->move(environment(me));
                me->unconcious();
        return 1;
        }
        return ::valid_leave(me, dir);
        
}
