 /* Copyright (C) 1998 Apstone, Inc. */
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "天池");
    set("long", @LONG
天池背靠博格达峰，为天山第二高峰，山峰终年积雪。即使是盛夏天气，湖水
的温度也相当低。狭长形的湖面积不大，但湖水清澄，碧蓝碧蓝的，看了就叫人感
到由衷的喜欢。天池四周的山腰上，有许多云杉林，云杉形如宝塔，挺拔、整齐，
很有气势。皑皑雪峰和葱茏挺拔的云松林到映在清澈的湖水中，构成了天池的迷人
的景色。
LONG
    );
    set("long_night", @LONG
天池背靠博格达峰，为天山第二高峰，山峰终年积雪。湖水总是寒冷刺骨。
狭长形的湖面积不大，在夜晚微微天光映照下，浮星点点，明莹如玉。天池四
周的山腰上，夜岚初起，扯动半山如帘的轻雾，漫漫的罩在一丛丛林木上。
远处雪峰映着星光在湖面微微波动，给人一种如梦如幻的感觉。
LONG
    ); 
    set("exits", ([
        "southdown" : __DIR__"tianshan",
    ]));


        //set("no_pk",1);  
    set("outdoors", "xinjiang");
    set("resource/water",1);
    set("liquid/name","冰凉的湖水");
    set("liquid/container", "天池");
        set("coor/x",-1130);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init(){

    if (!random(100) ) {
//        remove_call_out("falling_star");
        call_out("falling_star", random(20), this_player());
    }
} 
void falling_star(object me) {
    object *inv, *watchers;
    int i, age; 
    if(!objectp(me)) {
        return;
    }
    if(environment(me) != this_object() ) {
        return;
    }
    if(me->is_fighting()) {
        return;
    }
    message("vision", HIC"\n流星从远处掠过树林。。。。。\n"NOR, me);
    message("vision", HIW"           在湖面的倒影中拖下一条经久不灭的粼粼光芒。\n"NOR, me);
    age = me->query("age");
    if (age >= 26 && age <= 28 && !me->query("宿命A/天山_流星")) {
        tell_object(me,HIG"\n在看到流星的一瞬间，你默默的在心中许了个愿。\n"NOR);
        me->add("combat_exp",100);
    me->start_busy(10);
    }
}        
