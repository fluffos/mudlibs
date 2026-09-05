// shoot.c 射箭,by Zine 2012.7

#include <ansi.h>

inherit F_CLEAN_UP;

int improve_arrow(object me)
{
    if ((int)me->query_skill("arrow",1)*(int)me->query_skill("arrow",1)*(int)me->query_skill("arrow",1)*(int)me->query_skill("arrow",1)<me->query("combat_exp"))
    {
        me->improve_skill("arrow",2+random(3));
        tell_object(me,HIC+"你在实战中『神射之术』获得了进步！\n"+NOR);
        return 1;
    }
    else
    {
        tell_object(me,"限于天资，你的『神射之术』似乎进入了瓶颈！\n");
        return 1;
    }
}

int improve_arrow2(object me,object target,int accuracy)
{
    int circle;
    if ((int)me->query_skill("arrow",1)<15&&(int)me->query_skill("arrow",1)*(int)me->query_skill("arrow",1)*(int)me->query_skill("arrow",1)*(int)me->query_skill("arrow",1)<me->query("combat_exp"))
    {
        circle=accuracy/5;
        if (circle<1)
        {
            circle=1;
        }
        if (circle>10)
        {
            circle=10;
        }
        tell_object(me,"走到近处一看，你原来射中了"+chinese_number(circle)+"环。\n");
        me->improve_skill("arrow",1+random(2));
        tell_object(me,HIC+"你在练习中『神射之术』获得了进步！\n"+NOR);
        if (base_name(environment(me))=="/d/menggu/kongdi"&&target->query("shediao_quest_ba"))
        {
            target->shediao_nextquest(me);
        }
        return 1;
    }
    else
    {
		if (base_name(environment(me))=="/d/menggu/kongdi"&&target->query("shediao_quest_ba"))
        {
            target->shediao_nextquest(me);
        }
        tell_object(me,"限于天资，你的『神射之术』似乎进入了瓶颈！\n");
        return 1;
    }
}

int arrow_target(object me,object target,int accuracy)
{
    if (random(50)<accuracy)
    {
        message_vision("$N嗖的一箭射上箭靶。\n",me);
        improve_arrow2(me,target,accuracy);
    }
    else
    {
        message_vision("$N射出的箭远远偏离了箭靶。\n",me);
    }
    return 1;
}

int main(object me,string arg)
{
    object target,nextroom,ob,*bows;
    int coe,damage,accuracy,flag,i;
    string target_id,dir;
    mapping exit;
	bows=all_inventory(me);
	for (i=0;i<sizeof(bows);i++)
	{
		if (bows[i]->query("is__bow")&&bows[i]->query("equipped"))
		{
			ob=bows[i];
		}
	}
	if (!ob)
	{
		tell_object(me,"必须找到一把弓并装备起来，才能开射。\n");
		return 1;
	}
    if (!ob->query("arrow")||!ob->query("arrow_file"))
    {
        tell_object(me,ob->query("name")+"上并没有任何箭，你要把箭搭(da)在弓上，才能开射。\n");
        return 1;
    }
	if (!me->query("shediaoquest/zhebie"))
	{
		tell_object(me,RED+"你根本没学过开弓射箭的功夫。\n"+NOR);
		return 1;
	}
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要射谁？\n");
        return 1;
    }
    if (present(arg,environment(me)))
    {
        target=present(arg,environment(me));
        flag=1;
        if (!target->is_character()&&!target->query("is_arrow_target"))
        {
            tell_object(me,"你只可以向活物或者箭靶放箭！\n");
            return 1;
        }
    }
    else if (sscanf(arg, "%s at %s", target_id,dir)==2 )
    {
        exit=environment(me)->query("exits");
        if (!exit[dir])
        {
            tell_object(me,"你无法向这个方向射箭！\n");
            return 1;
        }
        if (find_object(exit[dir]))
        {
            nextroom=find_object(exit[dir]);
        }
        if (!present(target_id,nextroom))
        {
            tell_object(me,nextroom->query("short")+"并没有"+target_id+"这个人！\n");
            return 1;
        }
        target=present(target_id,nextroom);
        flag=2;
        if (!target->is_character())
        {
            tell_object(me,"你只可以向活物放箭！\n");
            return 1;
        }
	if (target->query("job_eid"))
		{
            tell_object(me,"这种目标不能放箭！\n");
            return 1;
		}

    }
    else
    {
        tell_object(me,"你可以用shoot <某人/箭靶>命令或者shoot <某人> at <方向>命令放箭！\n");
        return 1;
    }

    if (environment(target)->query("no_fight"))
    {
        tell_object(me,"你不能袭击"+environment(target)->query("short")+"的人！\n");
        return 1;
    }
/*	if (target->query("job_eid"))
		{
            tell_object(me,"这种目标不能放箭！\n");
            return 1;
		}
*/
    if (target->query_temp("arrow_shoot_by")==me)
    {
        tell_object(me,target->query("name")+"之前刚吃过你的亏，恐怕不会再上当了。\n");
        return 1;
    }
    coe=(int)(int)me->query_skill("arrow",1)-to_int(sqrt(to_float(target->query_skill("parry",1))));
    if ((int)me->query_skill("arrow",1)>(int)target->query("dex")*5)
    {
        accuracy=coe-(int)target->query("dex")*2+4*(int)me->query("shediaoquest/zhebie");
    }
    else
    {
        accuracy=coe-(int)target->query("dex")+4*(int)me->query("shediaoquest/zhebie");
    }
    if (accuracy<50&&accuracy>10)
    {
        accuracy=(50-accuracy)/2+accuracy;
    }
    else if (accuracy>99)
    {
        accuracy=99;
    }
    else if (accuracy<=10)
    {
        accuracy=10;
    }
    else
    {
        accuracy=accuracy;
    }
    damage=(int)me->query("str")*20+(int)me->query_str()*2+(int)ob->query("arrow_assist");
    damage+=random(damage/2);
    if (environment(me)==environment(target))
    {
        accuracy+=10;
        damage=damage/2;
    }
    if (wizardp(me))
    {
        tell_object(me,"ACCURACY_VALUE:"+accuracy+"\n");
        tell_object(me,"DAMAGE_VALUE:"+damage+"\n");
    }
    if (!target->query("is_arrow_target"))
    {
        if (flag==1)
        {
            message_vision(HIR+"只见$N平端起"+ob->query("name")+HIR+"，抽冷一箭向"+target->query("name")+HIR+"射去。\n"+NOR,me);
        }
        else
        {
            message_vision(HIR+"只见$N把"+ob->query("name")+HIR+"拉成满月，一箭向"+nextroom->query("short")+HIR+"的"+target->query("name")+HIR+"疾射而去。\n"+NOR,me);
        }
    }
    else
    {
        message_vision(HIR+"只见$N平端起"+ob->query("name")+HIR+"，瞄准半天，一箭向"+target->query("name")+HIR+"射去。\n"+NOR,me);
    }
    if (!target->query("is_arrow_target"))
    {
        if (me->query_temp("shediaoquest/shediao_step5")&&target->query("is_heidiao"))
        {
            message_vision(HIR+"$N右膝跪地，左手稳稳托住铁弓，更无丝毫颤动，右手运劲，将一张二百来斤的硬弓拉了开来。\n"+NOR,me);
            message_vision(HIR+"$N眼见两头黑雕比翼从左首飞过，左臂微挪，瞄准了黑雕项颈，右手五指松开。\n正是：弓弯有若满月，箭去恰如流星。黑雕待要闪避，箭杆已从颈对穿而过。\n"+NOR,me);
            target->set("killed_by",me);
			target->intro(me);
            target->die();
			return 1;
        }
		if (me->query_temp("mengguquest/hunter/start")&&time()-me->query_temp("mengguquest/hunter/start")<=500&&target->query("is__firefox"))
        {
            message_vision(HIR+"$N抽冷向"+target->name()+HIR+"射出了一箭。。。\n"+NOR,me);
            message_vision(HIR+"这一箭无论速度、力量都堪称完美，直接射穿火狐狸的眼睛，丝毫没有伤及皮毛。\n"+NOR,me);
            target->set("killed_by",me);
            target->over(me);
			return 1;
        }
        else if (random(100)<accuracy)
        {
            target->receive_damage("qi", damage, me);
            target->receive_wound("qi", damage, me);
            target->add_busy(1+random(3));
            if (flag==1)
            {
                message_vision(HIW+"$N"+HIW+"一声惨叫，发现身上已被$n"+HIW+"射中一箭！\n"+NOR,target,me);
                if (!userp(target))
                {
                    target->kill_ob(me);
                }
                else
                {
                    target->fight_ob(me);
                }
            }
            else
            {
                tell_room(nextroom,HIW+target->query("name")+HIW+"一声惨叫，发现身上已被"+me->query("name")+HIW+"射中一箭！\n"+NOR);
                tell_object(me,"你一箭正好射中"+target->query("name")+"。\n");
                if (!userp(target))
                {
                    tell_room(environment(me),HIR+target->query("name")+HIR+"大喝一声，冲了过来！\n"+NOR);
                    target->move(environment(me));
                    target->kill_ob(me);
                }
                else
                {
                    tell_object(target,"你发现正是"+me->query("name")+"在"+environment(me)->query("short")+"偷袭你！\n");
                }
            }
            if ((int)target->query("combat_exp")>(int)me->query("combat_exp")/5*4)
            {
                improve_arrow(me);
            }
        }
        else
        {
            if (flag==1)
            {
                message_vision(HIW+"$N"+HIW+"放箭射向$n"+HIW+"，险险落空了！\n"+NOR,me,target);
                if (!userp(target))
                {
                    target->kill_ob(me);
                }
                else
                {
                    target->fight_ob(me);
                }
            }
            else
            {
                tell_room(nextroom,HIW+target->query("name")+HIW+"一闪身，躲过了"+me->query("name")+HIW+"射出的一箭！\n"+NOR);
                tell_object(me,"你这一箭彻底落空了。\n");
                if (!userp(target))
                {
                    tell_room(environment(me),HIR+target->query("name")+HIR+"大喝一声，冲了过来！\n"+NOR);
                    target->move(environment(me));
                    target->kill_ob(me);
                }
                else
                {
                    tell_object(target,"你发现正是"+me->query("name")+"在"+environment(me)->query("short")+"偷袭你！\n");
                }
            }
        }
        target->set_temp("arrow_shoot_by",me);
    }
    else
    {
        arrow_target(me,target,accuracy);
    }
    ob->delete("arrow");
    ob->delete("arrow_file");
    ob->add("arrow_assist",-(int)ob->query("extra_assist"));
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : shoot <某物> 
shoot <某人> 或者 shoot <某人> at <方向>

这个指令可以让你向他人放箭，你也可以向箭靶练箭。
前提是你必须装备了一把弓，这只弓也上了箭。
 
HELP
    );
    return 1;
}
