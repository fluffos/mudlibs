#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "后院门");
        set("long", @LONG
青石小路穿过了花丛，到这里为止。一个小小的月形门立在此处。
门上的墙壁上刻著“后院”两个字。门旁挂著一块木牌，上写“非武
当弟子，请勿擅入！”
LONG
        );
        set("exits", ([ 
                "enter" : __DIR__"wudang3",
                "west" : __DIR__"wuroad3",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",140);
        set("coor/y",-130);
        set("coor/z",50);
        setup();
} 
int valid_leave(object me, string dir)
{
        int i;
        object *inv, ro; 
        if( dir != "enter" ) return 1;
        if( !me->query_temp("marks/偷"))  {
                me->set_temp("marks/彭长净", 0);
                return 1;
        } 
        message_vision(HIY "你听到你身後有几个声音大叫：＂有贼呀！来抓贼呀！＂\n"NOR, me);
        message_vision(HIR "接著「咚」地一声，$N的脑后被人重重地打了一棍。\n"NOR, me);
        me->unconcious();
        message_vision(HIY "两个真武道士把$N所有的东西搜了一遍。\n\n"NOR, me);
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                destruct(inv[i]);
        }
        message_vision(HIY "两个真武道士把$N抬了出去。\n"NOR, me);
        me->set_temp("marks/偷", 0);
        me->set_temp("marks/彭长净", 0);
        ro = find_object(__DIR__"road1");
        if(!objectp(ro)) load_object(__DIR__"road1");
        me->move(ro);
        message("vision", HIY "两个真武道士把" + me->name() + "重重地摔在了地上，然后转身离开了。\n"NOR, environment(me));
        return notify_fail("。。。。。。\n");
}       
