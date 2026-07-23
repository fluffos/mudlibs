 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIB"天湖"NOR); 
        set("long", @LONG
转过一个山拗，群峰环抱之中，竟然是白茫茫的一片湖水。原来这个大湖，便
是世界的第一高湖，藏名叫做“腾格里海”，但见湖水清澈，碧波荡漾，湖中有片
片闪光的浮冰，湖边水连天，天连水，恍如湖泊就在天上。藏胞称为『纳木错』,
意即天湖。湖边绿草如茵，杂花生树。      
LONG); 
        set("type","street");
        set("exits",([
                "southup":__DIR__"shanyao",
        ]) );
        set("outdoors", "guanwai");
        set("coor/x",-1280);
        set("coor/y",-100);
        set("coor/z",100); 
        set("resource/water",1);
     set("liquid",([
            "name":"冰水",
            "container":"腾格里海"])); 
        setup();
} 
int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "southup" )
        {
        if( me->query("str") < 28 )
            return notify_fail("抬头远眺，圣母雪峰直插云霄，雪连天，天接雪，不知何处才是尽头，\n你心中一悚，刚刚迈出去的脚不自禁又收了回来。。。\n");
                else
                {
                 message_vision(HIR "\n\n$N但觉热血沸腾，壮怀激烈，仰天长啸一声，大步向着世界之颠迈进。\n\n"NOR,me);
                         return 1;
                }
        }
        return 1;
}  
