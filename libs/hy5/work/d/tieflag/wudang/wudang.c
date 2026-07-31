#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "真武观");
        set("long", @LONG
红色的围墙，黄色的大门。门上挂著一块金匾，上书“真武观”
三个龙飞凤舞的大字。大门左右各卧著一只雄伟的石狮。一名头戴黄
色道冠，身穿青色道袍的知客道人，靠门而立。
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"road3",
                "enter" : __DIR__"wudang1",
        ]));
        set("objects", ([ 
                __DIR__"npc/wtaoist" : 1,
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-130);
        set("coor/z",50);
        setup();
} 
int valid_leave(object me, string dir)
{
        object *enemy, ob;
        int i; 
        if( userp(me) && (ob=present("waiter taoist", this_object()))) {
                enemy = ob->query_enemy();
                i = sizeof(enemy);
                while(i--) {
                        if( enemy[i] == me )
                                return notify_fail(HIY + ob->name()+"对" + me->name() 
                                + "喝道：想跑？没那么容易！\n" + HIR + ob->name() + 
                                "把" + me->name() + "挡了回来！\n" +NOR);
                }
        }
        return 1;
}     
