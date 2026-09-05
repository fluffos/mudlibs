#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
    add_action("do_worship","worship");
}

void create()
{ 
                
       set_name(HIW"圣诞"HIY"的"HIR"许愿树"NOR,({"xmas tree","xmas"}));
        set_weight(9999999);
           set("no_get",1);
        set_max_encumbrance(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","棵");
           set("long","
这是巫师组临时买来的圣诞树，听说上面的圣诞老人
有不同寻常的神奇力量，如果你对此树祈祷(worship)
也许会使自己永葆青春!信与不信，试试吧，即使能
年轻几岁也是好的。" + HIW"

               ___
             /`   `'.
            /   _..---;
            |  /__..._/  .--.-.
            |.'  e e | ___\_|/____
           (_)'--.o.--|    | |    |
          .-( `-' = `-|____| |____|
         /  (         |____   ____|
         |   (        |_   | |  __|
         |    '-.--';/'/__ | | (  `|
         |      '.   \    )"";--`\ /
         \        ;   |--'    `;.-'
          |`-.__ ..-'--'`;..--'`\\n\n"NOR


);
                                                  
        }
        
}

int do_worship(string arg)
{
	    object me;
	    me=this_player();
	    
     if (me->query("qidao/2002"))
     {
        tell_object(me,MAG"你面对圣诞树祈祷，可再也感觉不到那种神奇的力量。\n"NOR);
        return 1;
     }
     if( (int)me->query("mud_age") < 518400 ) 
     {
     message_vision(HIR"行云跳出来对你哈哈大笑：这么点小屁孩儿也学人家祈祷？回家复习功课去吧！\n"NOR, me);
     me->add("neili",500);     
     return 1;
     }    	
     tell_object(me,HIY"你面对圣诞树，心中默默祈祷...\n"NOR);
     me->set("qidao/2002",1);
     me->add("mud_age", -200000);
     message_vision(MAG"$N祈祷完毕站起身来，脸上泛起一阵红晕。\n"NOR, me);
     tell_object(me, HIG"你突然觉得身轻如燕，好像年轻了几岁！\n"NOR);
     return 1;
}

