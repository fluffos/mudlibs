// ai.c
#include <ansi.h>

int main(object me, string arg)
{
        mapping fa1,fa2;
        object ob,obj;
		int doing_cost;
        seteuid(getuid());

        if(!arg||!objectp(ob=present(arg,environment(me))) ) 
                return notify_fail("你想和谁亲热?\n");

        if (me->query("marry/lover")!=ob->query("id")) 
                return notify_fail("只有夫妻间才能亲热.\n");

    if( !ob->is_character() )
        return notify_fail("看清楚一点呀！。\n");

//        if(undefinedp(obj=ob->query_temp("ai_dest"))||obj!=me)  
//        {
//                me->set_temp("ai_dest",ob);
//                return 1;
//        }

    if((string)ob->query("gender") == (string)me->query("gender"))
		{
        tell_object(me,"你不怕" + RED"AIDS"NOR + "吗？\n");
        return 1;
    }

        if (!(userp(ob)))
            return notify_fail("Loving只能在玩家之间进行\n");

        if ((int)me->query("jing") * 100 / (int)me->query("max_jing") < 70)
                return notify_fail("你现在精太少了，还是身子骨要紧啊！\n");
   
	if( (int)me->query("qi") < 100 )
        return notify_fail("你的体力不足，小心死在床上！\n");

        if (!(environment(me)->query("owner") == me->query("id") || environment(me)->query("owner") == ob->query("id")))
                return notify_fail("你们也不怕被人看见?\n");

        if (me->query("gender") == "无性")
                return notify_fail("晕!你突然想起来你的那个没有了。\n");

        if (ob->query("gender") == "无性")
                return notify_fail("晕!你突然想起来他的那个没有了。\n");

         if(me->query_condition("make_love")!=0)
                return notify_fail("刚作完还想来,神仙也受不了啊!\n");

    if( userp(ob))
      if ((object)ob->query_temp("asking_who")!=me )
	{
        if (me->query("gender") == "男性")
        {
        message_vision(HIM"$N"+HIM"有些不怀好意地看着$n"+HIM"，嘴角露出暧昧的笑容......\n"NOR,me,ob);
		me->set_temp("asking_who", ob);
        ob->set_temp("asked_who",me);
        tell_object(ob, MAG "如果你愿意和对方....，请你也对" + me->name() + MAG"("+(string)me->query("id")+")"+ "下一次 loving 指令。\n" NOR);
        write(HIY "你必须等对方同意才能继续。\n" NOR);
        return 1;
        }
        else
		{
		message_vision(HIM"$N"+HIM"看了$n"+HIM"一眼，脸唰地红了起来，不好意思地转过头去，轻轻地咬着嘴唇......\n"NOR,me,ob);
        me->set_temp("asking_who", ob);
        ob->set_temp("asked_who",me);
        tell_object(ob, MAG "如果你愿意和对方....，请你也对" + me->name() + MAG"("+(string)me->query("id")+")"+ "下一次 loving 指令。\n" NOR);
        write(HIY "你必须等对方同意才能继续。\n" NOR);
        return 1;
		}
	}
	else{
        if(me->query("gender")=="男性")
        { 
			    message_vision(HIM"\n$N"+HIM"有些不怀好意地看着$n"+HIM"，嘴角露出暧昧的笑容......\n"NOR,me,ob);
                message_vision(MAG"\n$n"+MAG"呵呵地朝着$N"+MAG"笑.\n",ob,me);
				message_vision(HIB"\n$N"+HIB"温柔地抱起$n"+HIB"，$n"+HIB"的身体在$N"+HIB"怀里轻轻颤动了一下。\n$N"+HIB"用热唇轻轻的给了$n"+HIB"一吻。\n"NOR, me,ob);
                message_vision(HIM"\n$n"+HIM"轻轻抱起$N"+HIM"走向床边.\n"NOR,ob,me);                 
        }
        else
        { 
			    message_vision(HIM"\n$N"+HIM"看了$n"+HIM"一眼，脸唰地红了起来，不好意思地转过头去，轻轻地咬着嘴唇......\n"NOR,me,ob);
			    message_vision(MAG"\n$N"+MAG"羞红了脸,低下头去.\n"NOR,me);
				message_vision(HIB"\n$N"+HIB"主动地搂着$n"+HIB"，$n"+HIB"也张开双臂，把$N"+HIB"紧紧地搂在怀里。\n$N"+HIB"用热唇轻轻的给了$n"+HIB"一吻。\n"NOR, me,ob);
                message_vision(HIM"\n$N"+HIM"轻轻抱起$n"+HIM"走向床边.\n"NOR,ob,me); 
        }
	}
    me->delete_temp("asking_who");
    ob->delete_temp("asked_who");

    me->set_temp("doing_with",ob);
	doing_cost = 50;
    me->set_temp("make_cost",doing_cost);
    me->set_temp("doing_cost",doing_cost);
    me->start_busy("doing","halt_do");

    ob->set_temp("doing_with",me);
    doing_cost = 50;
    ob->set_temp("make_cost",doing_cost);
    ob->set_temp("doing_cost",doing_cost);
    ob->start_busy("doing","halt_do");

        return 1;
}

int doing(object me)
{
    object obj;
    int doing_cost;
    int doing,step;
    if (!me) return 1;

    doing_cost = (int)me->query_temp("doing_cost");
    obj=(object)me->query_temp("doing_with");

    if (doing_cost < 1)
	{
		call_out("halt_do",0,me,obj);
		obj->start_busy(0);
        return 0;
	}

    doing_cost--;
    me->set_temp("doing_cost", doing_cost);

    me->add_temp("time_count",1);

    if (me->query("jing") > 10)
        me->add("jing", -random(10));
    else
	{
		doing_cost = 1;
		me->set_temp("doing_cost", doing_cost);
		obj->set_temp("doing_cost", doing_cost);
	}

    if (!obj || !present(obj, environment(me)))
	{
		message_vision(HIM"obj disappear!\n"NOR,me,obj); 
        me->start_busy(0);
        return 0;
    }

    doing=doing_cost*100/me->query_temp("make_cost");
    if (obj->query("gender")!="男性")
        if (doing_cost == 49)
		call_out("do_tuo",0,me,obj);
	if( doing < 90 && random(5) == 0 && obj->query("gender")!="男性" )
	{
	step = random(doing);
	step = step*4/doing;
	switch (step)
	{
	case 1:
		remove_call_out("do_hug");
	    call_out("do_hug",0,me,obj);
	break;
	case 2:
		remove_call_out("do_kiss");
	    call_out("do_kiss",0,me,obj);
		break;
	case 3:
		remove_call_out("do_touch");
	    call_out("do_touch",0,me,obj);
		break;
	case 4:
		remove_call_out("do_make");
	    call_out("do_make",0,me,obj);
		break;
	default:
		remove_call_out("do_make");
	    call_out("do_make",0,me,obj);
		break;
	}
	}

    if (doing_cost > 0)
        return 1;

    obj->start_busy(0);
    return 1;
}

int halt_do(object me)
{
	object ob;
	ob=(object)me->query_temp("doing_with");
    //me->add("max_jingli",2);
    me->add("jing",-50);
    ob->add("jing",-50);
    me->enable_player();
    ob->enable_player();
    me->delete_temp("block_msg/all");
    ob->delete_temp("block_msg/all");
    me->delete("disable_type");
    ob->delete("disable_type");
    me->write_prompt();
    ob->write_prompt();
    me->apply_condition("make_love",30);
    ob->apply_condition("make_love",30);
    message_vision(RED"\n不知过了多少时候, 床前红烛燃尽.\n"NOR,me,ob);
    tell_object(ob,HIC+me->name()+HIC"坐起身来对着你笑.\n"NOR);
    tell_object(me,HIC+ob->name()+HIC"坐起身来对着你笑.\n"NOR);
//    me->delete_temp("ai_dest");
//    ob->delete_temp("ai_dest");
    me->delete_temp("doing_with");
    ob->delete_temp("doing_with");
	me->delete_temp("asking_who");
    ob->delete_temp("asking_who");
    me->delete_temp("time_count");
    me->delete_temp("unconcious");
    me->delete_temp("make_cost");
	if(me->query("gender") == "男性")
	{
		me->unconcious();
	}
    return 1;
}

void do_tuo(object me,object obj)
{
    object ob,ob2,*inv;
	int i;

    message_vision(BLU "\n$N"+BLU"脱下自己的衣带，光着身子钻进被窝。\n" NOR, me);
	ob = me->query_temp("weapon");//右手兵器
	ob2 = me->query_temp("secondary_weapon");//左手兵器
	if(objectp(ob))
		ob->unequip();
	if(objectp(ob2))
		ob2->unequip();
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		inv[i]->unequip();

    message_vision(BLU "\n$N"+BLU"轻轻解开$n"+BLU"的衣带，露出了洁白的肌肤。\n" NOR, me,obj);
	ob = obj->query_temp("weapon");//右手兵器
	ob2 = obj->query_temp("secondary_weapon");//左手兵器
	if(objectp(ob))
		ob->unequip();
	if(objectp(ob2))
		ob2->unequip();
	inv = all_inventory(obj);
	for(i=0; i<sizeof(inv); i++)
		inv[i]->unequip();
}

void do_hug(object me,object obj)
{
        message_vision(MAG"\n$N"+MAG"紧紧抱住了$n"+MAG"，$n"+MAG"觉得一片温馨。\n"NOR, me ,obj);
        
}

void do_kiss(object me,object obj)
{
    message_vision(HIY"\n$N"+HIY"吻遍了$n"+HIY"的每一寸肌肤!\n"NOR, me,obj);
}

void do_touch(object me,object obj)
{
        message_vision(HIW"\n$N"+HIW"抚摸着$n"+HIW"柔柔的身体!\n"NOR, me,obj);
}

void do_make(object me,object obj)
{
	switch(random(3))
	{
	case 0:
		message_vision( HIM "\n    月光穿过窗户，轻撒在床前....... \n" NOR,me,obj);
	break;
	case 1:
		message_vision( HIM "\n$N喉咙里发出满足的叹息声。。。。\n" NOR,me,obj);
	break;
	case 2:
	message_vision( HIM "\n$n脸色潮红，轻声喘息\n" NOR,me,obj);	
	break;
	}
}

int help(object me)
{
        write(@HELP
这个指令可以让夫妻之间作爱。
 
HELP
    );
    return 1;

}
