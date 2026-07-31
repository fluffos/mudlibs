 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "百花宫");
        set("long", @LONG
这是快活王专为白飞飞而重造的百花宫，宫中倒是装饰地简单雅致，引人注目
的是满目的大红绸缎四处悬挂，大大小小的“喜”字贴在各种装帧上，格外夺目，
屋中两个打扮地花枝招展的喜娘忙碌个不停，一个梳头师傅正精心地为新娘白飞飞
梳头打扮。
LONG
        ); 
        set("exits", ([ 
                "south" : __DIR__"eaststrt2",
        ]));
        set("indoors", "loulan");
        set("objects", ([
                  __DIR__"npc/xiniang" : 2,
                  __DIR__"npc/hairjiang" : 1,
                  __DIR__"npc/ms_wang" : 1,
        ]) ); 
        set("coor/x",-1000);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
} 
void init()
{
        object me; 
        if( interactive(me = this_player()) ) 
        {
                call_out("greeting", 0, me);
        }
} 
int greeting(object me)
{
        object room; 
        if( userp(me) && !me->query_temp("marks/jade_to_zhu") )
        {
                room = find_object("/d/loulan/eaststrt2");
           if(!objectp(room)) 
                        room = load_object("/d/loulan/eaststrt2");
                message_vision(HIY"“新娘正在上装，非礼勿视”，几个喜娘推推搡搡的把$N赶了出来．．．\n"NOR,me);
                me->move(room);
        }
}       
