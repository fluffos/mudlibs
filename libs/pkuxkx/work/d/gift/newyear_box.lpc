// item : /u/yom/NewYear_Box.c
// yom 31/12/03

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
    add_action("do_get_out","get_out");
}

void create()
{ 
                
       set_name(HIG"春节礼物盒"NOR,({"gift box","box"}));
        set_weight(9999999);
           set("no_get",1);
        set_max_encumbrance(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","个");
           set("long",RED"这是2004年的春节礼物盒.\n 不想取(get_out)个属于自己的礼物个看看吗？\n"NOR);
                                                  
        }
        
}

int do_get_out(string arg)
{
        object p;
     object me= this_player();

     if (me->query("gift/Chunjie2004") > 1)
     {
        tell_object(me,"取两个就够啦，给别人剩两个啦\n");
        return 1;
     }
     p = new(__DIR__"mofang");
     p->move(me);
     tell_object(me,HIB"你从盒子里摸索了半天，总算打定主意取出一个礼物。\n"NOR);
     me->add("gift/Chunjie2004",1);
     return 1;
}

