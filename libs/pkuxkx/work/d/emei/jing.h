#include <ansi.h>
void init()
{
    add_action("do_nianjing",({"nianjing","nian"}));
}

int nianjing(object me)
{
	object env;
    int n,n1;
	string *jing=({"观自在菩萨，行深般若波罗蜜多时，","照见五蕴皆空，度一切苦厄。","舍利子，色不异空，空不异色，",
        "色即是空，空即是色，受想行识， 亦复如是。","舍利子，是诸法空相，","不生不灭， 不垢不净，不增不减。",
        "是故空中无色，无受想行识，","无眼耳鼻舌身意，无色声香味触法，","无眼界，乃至无意识界，无无明，",
        "亦无无明尽，乃至无老死，亦无老死尽。","无苦集灭道， 无智亦无得，以无所得故。","菩提萨埵，依般若波罗蜜多故，",
        "心无挂碍，无挂碍故，","无有恐怖，远离颠倒梦想，究竟涅槃。","三世诸佛， 依般若波罗蜜多故，得阿耨多罗三藐三菩提。",
        "故知般若波罗蜜多是大神咒，是大明咒，","是无上咒，是无等等咒，","能除一切苦，真实不虚。","故说般若波罗蜜多咒，即说咒曰：",
        "揭谛揭谛，波罗揭谛，波罗僧揭谛，菩提娑婆诃。"});

    if (objectp(me))
    {
        env=environment(me);
    } 
    else
    {
        return 1;
    }
    if (me->query_temp("emnewbiejob/newbie/count")>30+random(30))
	{
		tell_object(me,HIG"你觉得自己完全静下心来了。\n"NOR);
		me->set_temp("emnewbiejob/newbie/count",0);
		me->set_temp("emnewbiejob/newbie/finish",1);
		if (random(3))
                {
                    if (me->query_skill("mahayana",1)<120)
                    {
                    
                        me->set_skill("mahayana",(int)me->query_skill("mahayana",1)+1);
                        tell_object(me,"通过这段的默念佛经，你觉得自己佛学的造诣提高了。\n");
                        tell_object(me,HIC+"你的大乘涅磐功进步了！\n"+NOR);
                        if (!random(3)&&me->query("combat_exp")>1000)
                        {
                            n=1+random(50);
                            me->add("combat_exp",n);
                            me->add("exp/emnewbiejob", n);
                            n1=random(n*2);
                            if ((int)me->query("potential")>(int)me->query("combat_exp")*2)
                            {
                                n1=n1/2;
                                me->add("combat_exp",n1);
                                me->add("exp/emnewbiejob", n1);
                                n=n+n1;
                            }
                            me->add("potential",n1);
                            me->add("pot/emnewbiejob", n1);
                            write("你额外获得了"+chinese_number(n)+"点经验，"+chinese_number(n1)+"点潜能。\n");
                        }
                    }
                    else
                    {
                        n=1+random(50);
                        me->add("combat_exp",n);
                        me->add("exp/emnewbiejob", n);
                        n1=random(n*3/2);
                        me->add("potential",n1);
                        me->add("pot/emnewbiejob", n1);
                        write("你额外获得了"+chinese_number(n)+"点经验，"+chinese_number(n1)+"点潜能。\n");
                    }
                }
		if (random(3))
                {
                    if (me->query_skill("literate",1)<120)
                    {
                        me->set_skill("literate",(int)me->query_skill("literate",1)+1);
                        tell_object(me,"通过这段的默念佛经，你觉得自己的读书写字提高了。\n");
                        tell_object(me,HIC+"你的读书写字进步了！\n"+NOR);
                    }
                    else
                    {
                        n=1+random(50);
                        me->add("combat_exp",n);
                        me->add("exp/emnewbiejob", n);
                        n1=random(n*2);
                        me->add("potential",n1);
                        me->add("pot/emnewbiejob", n1);
                        write("你额外获得了"+chinese_number(n)+"点经验，"+chinese_number(n1)+"点潜能。\n");
                    }
                    
                }
		return 1;
	}
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你现在心烦意乱，无法静下来诵读佛经。\n");
		return 1;
	}
	if (env->query("short")==me->query_temp("emnewbiejob/newbie/place"))
	{
		me->add_temp("emnewbiejob/newbie/count",1);
		message_vision("$N轻轻诵读："+jing[random(sizeof(jing))]+"\n",me);
		call_out("nianjing",2,me);
		return 1;
	}
	else
	{
		message_vision("$N轻轻诵读："+jing[random(sizeof(jing))]+"\n",me);
		tell_object(me,"你现在心烦意乱，无法静下来诵读佛经。\n");
		return 1;
	}
}

int do_nianjing()
{
    object me=this_player();
    object env=environment(me);
	
    
	if (!env)
	{
		return 0;
	}
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
    if (me->query_temp("emnewbiejob/newbie/start_nianjing"))
    {
        tell_object(me,"你已经开始诵读经文了。\n");
        return 1;
    }
	else
	{
		message_vision(HIW"$N找了个蒲团坐下，轻轻诵读佛法。\n"NOR,me);
        me->set_temp("emnewbiejob/newbie/start_nianjing",1);
		call_out("nianjing",2,me);
		return 1;
	}
}