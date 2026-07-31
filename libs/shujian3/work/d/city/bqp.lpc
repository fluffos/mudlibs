// 兵器铺
// bqp.c -- Oct 25,97
// Looklove 2001/2/27

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
           set("short",HIR"兵器铺"NOR);
           set("long",@long
这是一间灯火通明的兵器铺，里边放着一排排的兵器架，上面放满了兵
器。一位老师傅和一个中年男子正在打造着一件希奇古怪的兵器，你从来没
有见过这个兵器，不禁想上去与他们搭个话。墙上有一个大招牌(sign)。
long ); 
        set("objects",([
        "/clone/npc/tiejiang_test" : 1,
        "/d/city/npc/tiejiang" : 1,
//	"/clone/npc/agent" : 1,
                ]));
                  
        set("exits",([
                "west" : __DIR__"datiepu",
                ]));
        
        set("item_desc",([
                "sign" : 
                "
                 本店承定各种兵器。

                 用     ding <weapon_type> <color> <weapon_name>  来订造.
                        例如 : ding sword $HIY$ 碧血剑
                                 
                Notes: weapon_type   blade,sword,club,staff,feibiao,hook;
                        color         $HIG$ $HIR$ etc, see help nick
                             for the full list of supported color;
                        weapon_name   你所要打造的兵器的中文名字

                        ***   对于不雅观的兵器,巫师将予以没收!   ***\n"
           ]));
        set("coor/x",130);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
}

