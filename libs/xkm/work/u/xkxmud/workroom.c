//workroom.c   ☆侠客☆(Xkxmud)的工作室
//☆侠客☆(Xkxmud)
//     /u/xkxmud/workroom.c
//Time:001_2002.05.24
//Time:002_2002.08.25
//Time:003_2002.08.28

#include <ansi.h>
//#include "/u/xkxmud/h/xkxmud"
//#include "/u/xkxmud/h/xkxmud2"
inherit ROOM;

void create ()
{
       set("short",HIY"☆侠客草庐☆"NOR);
       set ("long", HIG"
这里是☆侠客☆办公的地方。
屋里陈设很简单，一张桌子、一张床，接近门口处
摆着一个架子，架子上停落着一只鹦鹉，刚才就是
它在叫，可爱吧！
"NOR);
       set("exits", ([ 
//             "try" : __DIR__"o/try",
//             "up" : __DIR__"wldt/wldt",
               "ws" : "/d/wizard/wizard_room",
               "hy" : "/u/jhy/workroom",
               "down" : "/d/city/guangchang",
//               "east" : __DIR__"room/qinglong_dian",
//               "west" : __DIR__"room/baihu_dong",
//               "south" : __DIR__"room/zhuque_tang",
//               "north" : __DIR__"room/xuanwu_gong",
       ]));
       set("objects", ([
//               "/adm/daemons/xkxmud_msgd" : 1,
       ]));

       set("no_death", 1);
       set("no_fight", 1);
       set("no_kill", 1);
       set("cost", 0);
       set("valid_startroom", 1);
       set("no_clean_up", 0);
       setup();
       "/clone/board/xkxmud_b"->foo();
}
void init()
{
       object me = this_player();
       if( getuid(this_player())=="xkxmud")
       {
               tell_room( environment(me), HIG"绿鹦鹉"HIG"叫道：“参见"HIG"☆侠客☆"HIG"陛下！！！”\n"NOR);
//               add_action("do_dream","dream");
//               add_action("set_invisibility","setwiz");
//               add_action("get_invisibility","getwiz");
       }
       else if( getuid(this_player())=="jhy")
       {
               tell_room( environment(me), HIG"绿鹦鹉"HIG"叫道：“参见"HIB"≈海洋≈"HIG"陛下！！！”\n"NOR);
//               add_action("do_dream","dream");
//               add_action("set_invisibility","setwiz");
//               add_action("get_invisibility","getwiz");
       }
       else if( getuid(this_player())=="rainrose")
       {
               tell_room( environment(me), HIG"绿鹦鹉"HIG"叫道：“参见"HIC"雨"HIR"玫瑰"HIG"仙子！！！”\n"NOR);
//             add_action("do_dream","dream");
//             add_action("set_invisibility","setwiz");
//             add_action("get_invisibility","getwiz");
       }
       else
       {
               tell_room( environment(me), HIG"绿鹦鹉"HIG"高声道：“报告，" + me->query("title") + " "
                       + me->query("name") + "(" + me->query("id") + ")" + HIG"前来拜访！！！”\n"NOR);
//                  add_action("do_t_say","say");
          }
}
