// Room: xiaodian.c 湖边小店

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "湖边小店");
        set("long", @LONG
这是一间简陋的土坯房，门口挂着块裂了几个口子的木招牌。屋中凌乱不堪，
东倒西歪地散落着几件破旧的桌椅，蒙着厚厚的灰尘，墙角结着个蜘蛛网。
LONG
        );

        set("exits", ([
                "north" : __DIR__"tianhu",
        ]));
        set("objects", ([
         __DIR__"npc/wuchou1" : 1,
         __DIR__"npc/wuchou2" : 1,
         __DIR__"npc/wuchou3" : 1,
         __DIR__"npc/wuchou4" : 1,
         __DIR__"npc/wuchou5" : 1
       ]));
        setup();
}
int valid_leave(object me, string dir)
{       
        int i;
        object *inv;
        object inv1;
        object inv2;
        inv = deep_inventory(me);
        if (me->query_temp("has_rumored")) return ::valid_leave(me, dir);

        for( i = 0; i<sizeof(inv); i++)
        {
                inv1 = inv[i];
                if( inv1->query("id") == "chungong tu")
                message( "channel:rumor", HIR"【谣言】某人：听说" + me->query("name") + "搞到了一本"+HIM"春宫图"+HIR"！\n"NOR, users());
                me->set_temp("has_rumored",1);
 
        }
        return ::valid_leave(me, dir);
}
