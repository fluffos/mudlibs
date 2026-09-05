// aaasd 9/21/01
// 感谢icer的指导

#include <ansi.h>
inherit ITEM;

int do_wish(string arg);
int give_gift(string arg, string type);

void init()
{
    add_action("do_wish","wish");
}

void create()
{ 
                
        set_name(HIY"许愿树"NOR,({"wishtree","tree"}));
        set_weight(9999999);
        set("no_get",1);
        set_max_encumbrance(0);
        if(clonep())
                set_default_object(__FILE__);
        else{
                set("unit","棵");
                set("long",HIG"这是一棵神树，你可以向它许愿 (wish)要求\n
                   内力(neili)、精力(jingli)、门忠(score)、\n经验(exp)、潜能(pot)。\n"NOR);
        }
}

int do_wish(string arg)
{
        if (!arg)
        	return notify_fail("你要许什么愿？\n");
	give_gift(arg,"2001年国庆节");	//不同节日改不同type的名称
	return 1; // 应该返回一个值 notice by shure
}

int give_gift(string arg, string type)
{
       object me= this_player();

       if ( (int)me->query("kaizhan/" + type ) ) 
       {
           tell_object(me,"\n贪得无厌的话神仙会生气的！\n");
	   return 0;
       }
       if(arg=="neili") 
       {
           me->add("max_neili",100);
           message_vision(BLU"\n$N双膝跪下，虔诚地许下心愿。\n"NOR,me);
           tell_object(me,"\n你的最大内力增加了100点!\n");
           me->set("kaizhan/" + type,1);
           return 1; 
       }
       if(arg=="jingli") 
       {
           me->add("max_jingli",100);
           message_vision(BLU"\n$N双膝跪下，虔诚地许下心愿。\n"NOR,me);
           tell_object(me,"\n你的最大精力增加了100点!\n");
           me->set("kaizhan/" + type,1);
           return 1;
       }
       if(arg=="score") 
       {
           me->add("score",100);
           message_vision(BLU"\n$N双膝跪下，虔诚地许下心愿。\n"NOR,me);
           tell_object(me,"\n你的门忠增长了100点!\n");
           me->set("kaizhan/" + type,1);
           return 1;
       }
       if(arg=="pot") 
       {
           me->add("potential",500);
           message_vision(BLU"\n$N双膝跪下，虔诚地许下心愿。\n"NOR,me);
           tell_object(me,"\n你的潜能增加了500点!\n");
           me->set("kaizhan/" + type,1);
           return 1;
       } 
       if((arg=="exp")) 
       {
           me->add("combat_exp",1000);
           message_vision(BLU"\n$N双膝跪下，虔诚地许下心愿。\n"NOR,me);
           tell_object(me,"\n你的战斗经验增长了1000点!\n"); //太多了
           me->set("kaizhan/" + type,1);
           return 1;
       }
    return 0;
}


















  