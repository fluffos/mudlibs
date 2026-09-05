#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
    add_action("do_zhua","zhua");
}

void create()
{ 
                
       set_name(HIY"行云"HIG"的"HIR"结婚蛋糕"NOR,({"wedding cake","cake"}));
        set_weight(9999999);
           set("no_get",1);
        set_max_encumbrance(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","块");
           set("long","
这是行云与Nikita的结婚蛋糕。好像很美味的样子，
你可以抓(zhua)一块尝尝。" + HIM"

                               )\\
                              (__)
                               /\\
                              [[]]
                           @@@[[]]@@@
                     @@@@@@@@@[[]]@@@@@@@@@
                 @@@@@@@      [[]]      @@@@@@@
             @@@@@@@@@        [[]]        @@@@@@@@@
            @@@@@@@           [[]]           @@@@@@@
            !@@@@@@@@@                    @@@@@@@@@!
            !    @@@@@@@                @@@@@@@    !
            !        @@@@@@@@@@@@@@@@@@@@@@        !
            !              @@@@@@@@@@@             !
            !             ______________           !
            !            HAPPY WEDDING DAY         !
            !             --------------           !
            !!!!!!!                          !!!!!!!
                 !!!!!!!                !!!!!!!
                     !!!!!!!!!!!!!!!!!!!!!!!\n\n"NOR
);
                                                  
        }
        
}

int do_zhua(string arg)
{
        object c;
     object me= this_player();

     if (me->query("wed/pick"))
     {
        tell_object(me,MAG"客人很多，一人一块噢。\n"NOR);
        return 1;
     }
      c = new("/d/gift/advent/gao");
     c->move(me);
     tell_object(me,HIG"你随手抓下一块蛋糕，准备分享行云的喜悦。\n"NOR);
     me->set("wed/pick",1);
     return 1;
}

