// wanfoding.c
// 万佛顶
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY "万佛顶" NOR);
        set("long",@long
这里是峨嵋山上的万佛顶，由于已经是在万丈高山之巅，气候是比较寒冷
的。北面有几间木棚，大概是峨嵋派的男弟子们自己动手搭建的安身之所。里
面是万佛顶上的万佛塔，西面是九老洞。
long);
        set("outdoors", "峨眉山");
        set("exits",([
             "north":__DIR__"mupeng",
             "west" : __DIR__"jiulaodong",
             "enter" : __DIR__"wanfota",
]));
        setup();
}

void init()
{
   object me, room;
   me = this_player();
   room = this_object();
   if(interactive(me) && (objectp(present("zhi huan", me)))){
        message_vision(HIR"只听得前面一个冷冰冰地声音说道：拿了铁指环就想走？\n"NOR, me);   
        new(__DIR__"npc/shouta")->move(environment(me));        
        room->delete("exits");
        }       
}

int valid_leave(object me, string dir)
{
 if (dir == "north" && me->query("gender") == "女性" )
    return notify_fail("这里是男弟子的休息室，你最好不要进去！\n");
 if (dir == "enter" && (me->query("class") != "bonze" && me->query("family/family_name") != "峨嵋派" ) )
    return notify_fail("这里是峨嵋派的佛家圣地，你最好不要进去！\n");
    return ::valid_leave(me, dir);
} 
