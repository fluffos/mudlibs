// by kiden

#include <ansi.h>
inherit F_CLEAN_UP;

int report(object me,string name);
int help(object me);

mapping name_location=
([
 "倚天剑":         "/d/emei/houshan/npc/obj/yitian-jian",
 "屠龍刀":         "/d/bhdao/npc/obj/tulong-dao",
 "兵器谱":         "/clone/book/bingqipu",
 "沥泉神匕":       "/d/qilincun/obj/liquanbi",
 "沥泉神叉":       "/d/qilincun/obj/liquancha",
 "沥泉神鞭":       "/d/qilincun/obj/liquanbian",
 "沥泉神杵":       "/d/qilincun/obj/liquanchu",
 "沥泉神锤":       "/d/qilincun/obj/liquanchui",
 "沥泉神刀":       "/d/qilincun/obj/liquandao",
 "沥泉神斧":       "/d/qilincun/obj/liquanfu",
 "沥泉神棍":       "/d/qilincun/obj/liquangun",
 "沥泉神戟":       "/d/qilincun/obj/liquanji",
 "沥泉神剑":       "/d/qilincun/obj/liquanjian",
 "沥泉神枪":       "/d/qilincun/obj/liquanqiang",
 "沥泉神杖":       "/d/qilincun/obj/liquanzhang",       
]);

int main(object me, string arg)
{
        string* name=keys(name_location);

    if ((int)me->query("special_skill/perceive")<1 && !wizardp(me))
    return notify_fail("你并不具备这个传音搜魂的能力。\n");
                      
    if (time()-me->query_temp("scan_time") < 5 )
                return notify_fail("不要频繁的查询，谢谢！\n");

    me->set_temp("scan_time",time());


        if(!arg)
        {
                help(me);
                return 1;
        }

        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");

        if( me->query("jingli") < 100 )
                return notify_fail("你的精神不够。\n");

  printf(HIY"你默运玄功，将功力聚集于耳目，顿时觉得灵台一片空明。\n"NOR);  
        me->add("jingli",-50);
/*
        if( arg =="all" )
        {
                tell_object(me,"\n");
                foreach(string temp in name)
                        report(me,temp);
                return 1;
        }
*/      
        report(me,arg);
        return 1;
}

int report(object me,string name)
{
        string location,msg;
        object* obj_list,owner;

        if( undefinedp(location=name_location[name]) )
        {
                help(me);
                return 1;
        }

        msg = location->in_mud() ? HIR "已经" NOR : HIC "不" NOR ;
        msg+= "存在"+name+"。\n";
        msg = "你感觉到"+msg;

        obj_list = children(location);
        if( sizeof(obj_list) > 2 )
        {
                CHANNEL_D->do_channel(this_object(), "sys",
                "你觉得有不止一个人拥有"+name+"，但是不知道是谁。\n");
        }
        owner = environment(obj_list[0]);
  if(location->in_mud()){
        if( !owner || !objectp(owner))
                msg+=HIY"不过你无法断定拥有者是谁。\n"NOR;
        else if (owner->is_character())
                msg+=HIC"你感觉好像在"+owner->query("name")+"身上。\n"NOR;
        else if (!owner->query("short"))
 msg+=HIG"你感觉好像在"+environment(owner)->query("short")+"的"+owner->query("name")+"里面。\n"NOR;
/*
 msg+=HIG"你感觉好像在"+ environment(owner)->query("short")?environment(owner)->query("short"):environment(owner)->query("name")+"的"+owner->query("name")+"里面。\n"NOR;
*/
        else
                msg+=HIG"你感觉好像在"+owner->query("short")+"里面。\n"NOR;
    }

        tell_object(me,msg);
        return 1;
}

int help(object me)
{
        string* name=keys(name_location);

        write(@HELP
指令格式 : uni_ob 倚天剑

这个指令告诉你所指定的神兵是否已经被玩家持有。
只有拥有传音搜魂(perceive)能力的玩家才能使用这个命令。

HELP
    );
        write("以下为可以感应的神兵中文名称列表:\n");
        write("=======================================\n");
        foreach(string temp in name)
                write(temp+"\n");
        write("=======================================\n");
    return 1;
}
