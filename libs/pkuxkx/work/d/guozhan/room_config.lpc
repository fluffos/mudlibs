inherit ROOM;
#include <ansi.h>
int arrowing(object me);

void init()
{
    object ob=this_object();
    object me=this_player();
	add_action("do_catch","duo");
	add_action("do_killall","killall");	
 	add_action("do_look","look");
    add_action("do_hide","maifu");
    add_action("do_shout","sha");
    add_action("do_leave","leave");
    add_action("do_forbid","");
    add_action("do_qian","qian");
	set("no_die",1);
    me->listen_to_die(me);
    if (ob->query("arrow")&&userp(me)&&living(me)&&me->query_temp("guozhan/side")!=ob->query("side"))
    {
        arrowing(me);
    }
    if (ob->query("flag"))
    {
        me->add_busy(3+random(3));
    }
}

int do_qian()
{
    object me=this_player();
    object ob=this_object();
    object *all=all_inventory(ob);
    object room,target;
    int damage,i,j=0;
    if (!ob->query("waterside"))
    {
        tell_object(me,"这里没有水，你要怎么下潜。\n");
        return 1;
    }
    if (ob->query_temp("person"))
    {
        if (ob->query_temp("person")!=me->query_temp("guozhan/side"))
        {
            room=load_object(ob->query("lower_layer"));
            if (target=room->query("hideman")&&present(target,room)&&living(target))
            {
                damage=me->query("eff_qi")/2;
                me->receive_damage("qi", damage,target);
                tell_object(me,"你悄悄潜入水下，却觉得腹部剧痛，被人狠狠捅了一刀。\n");
            }
            
            
            me->move(room);
            me->add_busy(4);
            me->kill_ob(target);
            target->kill_ob(me);
        }
        else
        {
            tell_object(me,"水下已有你的同伴在隐匿，人多反而不美。\n");
            return 1;
        }
    }
    else
    {
        for (i=0;i<sizeof(all);i++)
        {
            if (all[i]->query_temp("guozhan/side")!=me->query_temp("guozhan/side"))
            {
                j=1;
            }
        }
        if (j=1)
        {
            tell_object(me,"敌人虎视眈眈之下，你还要去洗澡吗？\n");
            return 1;
        }
        message_vision("$N潜入水底，静待敌人。\n");
        ob->set_temp("person",me->query_temp("guozhan/side"));
        room=load_object(ob->query("lower_layer"));
        me->move(room);
        me->set_temp("guozhan/hide",room);
        room->set("hideman",me);
        return 1;
    }
}

int arrowing(object me)
{
    int damage,chance;
    object ob=this_object();
    object flag1,flag2,flag3;
    flag1=load_object(__DIR__"flag1");
    flag2=load_object(__DIR__"flag2");
    flag3=load_object(__DIR__"flag3");
    if (flag1->query("flag_owner")&&flag2->query("flag_owner")&&flag3->query("flag_owner")
            &&flag1->query("flag_owner")==me->query_temp("guozhan/side")
            &&flag2->query("flag_owner")==me->query_temp("guozhan/side")
            &&flag3->query("flag_owner")==me->query_temp("guozhan/side"))
    {
        tell_object(me,"全场三面战旗尽在大"+me->query_temp("guozhan/side")+"掌握，"+ob->query("side")+"军弓手已经舍弃这里，丧胆而走。\n");
        return 1;
    }
    if (!present(me,ob))
    {
        tell_object(me,"一蓬箭雨落在你的身后，你很庆幸，逃了出来。\n");
        return 1;
    }
    if (!living(me))
    {
        return 1;
    }
    if (me->query_temp("riding")&&present(me->query_temp("riding"),ob))
    {
        chance=1;
    }
    tell_room(ob,"漫天的箭雨从"+ob->query("short")+"两旁射了出来。\n");
    damage=(int)me->query("max_qi")/100*(4+random(3));
    if (chance&&random(2))
    {
        message_vision("$N突然提高马速，间不容发地躲过了"+ob->query("side")+"军攒射。\n",me);
        call_out("arrowing",3,me);
        return 1;
    }
    tell_object(me,RED"你中箭了！\n"NOR);
    
    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
    call_out("arrowing",3,me);
    return 1;
}

int do_forbid(string arg)
{
    object me=this_player();
    object ob=this_object();
    string verb =ob->query_verb();
    if(ob->query("hide")&& me->query_temp("guozhan/hide")==ob&&verb != "shout"&&verb !="leave")
	{
		write("埋伏的时候不能乱动，否则一定会暴露踪迹。如果敌人来了，你可以给敌人迎头痛击(sha)，你也可以先行离开(leave)。\n");
		return 1;
    }
}

int do_leave()
{
    object me=this_player();
    object ob=this_object();
    object room;
    if (ob->query("shuidi"))
    {
        room=load_object(ob->query("upper_layer"));
        room->delete_temp("person");
        me->delete_temp("guozhan/hide");
        me->move(room);
        tell_room(room,me->query("name")+"湿漉漉地从水下冲了出来。\n");
        return 1;
    }
    if (ob->query("hide"))
    {
        if (me->query_temp("guozhan/hide")!=ob)
        {
            return 0;
        }
        message_vision("$N从阴影中出现，移除了伪装。\n",me);
        me->add_busy(2);
        tell_object(me,"长时间保持一个姿势，你活动了一下腿脚。\n");
        me->delete_temp("guozhan/hide");
        ob->add_temp("maifu/number",-1);
        if (ob->query_temp("maifu/number")<=0)
        {
            ob->delete_temp("maifu/side");
        }
    }
    return 1;
}

int do_shout()
{
    object me=this_player();
    object ob=this_object();
    object target;
    object *all=all_inventory(ob);
    object *enemy=({});
    int i,target_flag=0;
    if (me->query_temp("guozhan/hide")!=ob)
    {
        return 0;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]&&all[i]->query_temp("guozhan/side")&&all[i]->query_temp("guozhan/side")!=me->query_temp("guozhan/side"))
        {
            target_flag=1;
        }
    }
    if (target_flag!=1)
    {
        tell_object(me,"你刚要大吼一声“杀敌”，却发现此地根本没有一个敌人。悻悻地继续埋伏在一边。\n");
        return 1;
    }
    message_vision("$N大喝一声：“杀啊！”，身边所有"+me->query_temp("guozhan/side")+"国战士全部从暗处冲了出来，向对手展开搏杀！",me);
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query_temp("guozhan/side")&&all[i]->query_temp("guozhan/side")!=me->query_temp("guozhan/side")&&random(10))
        {
            message_vision("$N大吃一惊，暗道不好，心神更乱。",all[i]);
            all[i]->add_busy(6+random(6));
            enemy+=({all[i]});
        }
        if (all[i]->query_temp("guozhan/side")&&all[i]->query_temp("guozhan/side")==me->query_temp("guozhan/side"))
        {
            target=enemy[random(sizeof(enemy))];
            all[i]->kill_ob(target);
            all[i]->delete_temp("guozhan/hide");
            ob->add_temp("maifu/number",-1);
            if (ob->query_temp("maifu/number")<=0)
            {
                ob->delete_temp("maifu/side");
            }
            tell_object(all[i],"你从暗处冲了出来。正对上"+target->name()+"，捉对厮杀起来。\n");
        }
    }
    return 1;
}

int showup(object me)
{
    int i;
    object ob=this_object();
    object *all=all_inventory(ob);
    me->add_busy(10);
    write("你已陷入敌人重重包围。\n");
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query_temp("guozhan/hide")==ob&&all[i]->query_temp("guozhan/side")!=me->query_temp("guozhan/side"))
        {
            all[i]->kill_ob(me);
            all[i]->delete_temp("guozhan/hide");
            ob->add_temp("maifu/number",-1);
            if (ob->query_temp("maifu/number")<=0)
            {
                ob->delete_temp("maifu/side");
            }
        }
    }
    return 1;
}

int do_hide()
{
    object ob=this_object();
    object me=this_player();
    int i;
    object *all=all_inventory(ob);
    if (!ob->query("hide"))//可埋伏地点必须有hide标记，以及hide_max埋伏人数，Zine.
    {
        tell_object(me,"这里地势开阔一览无余，根本无法埋伏！\n");
        return 1;
    }
    if (ob->query_temp("maifu/side")!=me->query_temp("guozhan/side"))
    {
        message_vision("$N发现此处地势险要，刚准备埋伏下去，却发现身边出现了很多敌军。\n",me);
        showup(me);
        return 1;
    }
    if (ob->query_temp("maifu/number")>=ob->query("hide_max"))
    {
        tell_object(me,"已经有很多人埋伏于此，藏更多人恐怕会被敌人发现。\n");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {   
        if (!me->query_temp("guozhan/hide_notice_fail")&&all[i]->query_temp("guozhan/side")&&all[i]->query_temp("guozhan/side")!=me->query_temp("guozhan/side"))
        {
            tell_object(all[i]->name()+"在一旁看着你呢，还埋伏个啥？开杀吧。\n",me);
            me->set_temp("guozhan/hide_notice_fail",1);
        }
    }
    me->delete_temp("guozhan/hide_notice_fail");
    message_vision("$N找了个地方藏了起来，准备伏击敌军。\n",me);
    me->set_temp("guozhan/hide",ob);
    ob->set_temp("maifu/side",me->query_temp("guozhan/side"));
    ob->add_temp("maifu/number",1);
    return 1;
}

int do_killall()
{
	int i;
	object* invs = all_inventory();
    object me=this_player();
    object ob=this_object();
    if (ob->query("hunzhan"))
    {
        for (i=0;i<sizeof(invs)-1;i++)
        {
            invs[i]->kill_ob(invs[i+1]);
        }
        if (sizeof(invs)>0)
        {
            message_vision("$N大喝一声，向所有周围人出手。乱局却越扩越大。\n",me);
        }
        return 1;
        
    }
	for(i=0;i<sizeof(invs);i++)
	{
		if(invs[i]->query_temp("guozhan/side") != me->query_temp("guozhan/side"))
		{
			me->kill_ob(invs[i]);
		}
	}
	me->add_busy(1+random(2));
    return 1;
}

int do_look(string arg)
{
    object ob=this_object();
    if(arg == "flag" && ob->query("flag"))
    {
        write("这是"+ob->query("flag")+"\n");
        if(ob->query("flag_owner"))
        {
            write("这面"+ob->query("flag")+"现在被"+ob->query("flag_owner")+"国军队控制着。\n");
        }
        return 1;
    }
    return 0;  
}

int countdown_flag(object me,object ob)
{
    if (me->is_fighting())
    {
        tell_object(me,"你正在被攻击，只好先放弃升旗。\n");
        ob->delete_temp("flag_catcher");
        return 1;
    }
    if (!living(me))
    {
        ob->delete_temp("flag_catcher");
        return 1;
    }
    if (environment(me)!=ob)
    {
        tell_object(me,"你跑到哪里去了，"+me->query_temp("guozhan/side")+"国大旗没有被升起来。\n");
        ob->delete_temp("flag_catcher");
        return 1;
    }
    me->add_busy(1);
    ob->add_temp("flag_catch",1);
    if ((int)ob->query_temp("flag_catch")>9)
    {
        ob->set("flag_owner",me->query_temp("guozhan/side"));
        me->add_temp("guozhan/credit",5);
        message("chat",HIR"【国战】"+me->query("name")+HIR+ob->query("short")+"升起大"+me->query_temp("guozhan/side")+"战旗。\n"NOR,users());
        return 1;   
    }
    call_out("countdown_flag",1,me,ob);
    return 1;
}

int do_catch()
{
	int i;
	object me = this_player();
    object ob =this_object();
	object* invs = all_inventory();
    string flag;
    object flag_catcher;
	if(me->is_busy())
	{
	    return notify_fail("你正忙着呢。\n");
    }
	if(ob->query("flag"))
	{		
        if(me->query_temp("guozhan/side") == ob->query("flag_owner"))
        {
	        return notify_fail("这面"+ob->query("flag")+"掌握在你们"+me->query_temp("guozhan/side")+"国阵营。\n");
        }
		if (ob->query_temp("flag_catcher")==me)
        {
            return 1;
        }
        if (ob->query_temp("flag_catcher")!=me)
        {
            flag_catcher=ob->query_temp("flag_catcher");
            tell_object(me,flag_catcher->query("name")+"正在升起大"+flag_catcher->query_temp("guozhan/side")+"军旗，快去阻止他。\n");
            return 1;
        }
        else
        {
            ob->set_temp("flag_catch",0);
            ob->set_temp("flag_catcher",me);
            if (ob->query("flag_owner"))
            {
                if (me->query_temp("guozhan/side")=="明")
                {
                    flag="清";
                }
                else
                {
                    flag="明";
                }
                me->start_busy(1);
                message_vision("$N挥剑斩下"+flag+"军大旗，准备插上"+me->query_temp("guozhan/side")+"国战旗。\n",me);
                countdown_flag(me,ob);
            }
            else
            {
                me->start_busy(1);
                message_vision("$N准备插上"+me->query_temp("guozhan/side")+"国战旗。\n",me);
                countdown_flag(me,ob);
            }
        }	
	}
	else
	{
		return notify_fail("这里没有战旗。\n");
	}
	return 1;
}

int enter_permit(object me,object nextroom)
{
    object flag1,flag2,flag3;
    if (me->query_temp("guozhan/side")==nextroom->query("side"))
    {
        return 1;
    }
    else
    {
        flag1=load_object(__DIR__"flag1");
        flag2=load_object(__DIR__"flag2");
        flag3=load_object(__DIR__"flag3");
        if (flag1->query("flag_owner")!=me->query_temp("guozhan/side")
            ||flag2->query("flag_owner")!=me->query_temp("guozhan/side")
            ||flag3->query("flag_owner")!=me->query_temp("guozhan/side"))
        {
            return 0;
        }
    }
}

int valid_leave(object me, string dir)
{   
    object ob=this_object();
    object horse,juma;
    mapping exit=ob->query("exits");
    object nextroom;
    int real_difficulty,horse_bonus=0;
    if (me->query_temp("riding")&&present(me->query_temp("riding"),ob))
    {
        if (ob->query("land_type")=="shandi")
        {
            horse_bonus=-1;
        }
        else if (ob->query("land_type")=="shanlin")
        {
            horse_bonus=0;
        }
        else if (ob->query("land_type")=="pingyuan")
        {
            horse_bonus=2;
        }
        else
        {
            horse_bonus=1;
        }
    }
    real_difficulty=3-horse_bonus+(int)ob->query("hardness");
    if (!wizardp(me)&&time()-(int)me->query_temp("guozhan/last_go")<real_difficulty)
    {
        return notify_fail("你气息不匀，稍稍歇息再走吧。\n");
    }
    if (!exit[dir])
    {
        return notify_fail("这个方向不通。\n");
    }
    if (find_object(exit[dir]))
    {
        nextroom=find_object(exit[dir]);
    }
    if (nextroom->query("land_type")=="non_horse"&&me->query_temp("riding")&&present(me->query_temp("riding"),ob))
    {
        return notify_fail(nextroom->query("short")+"无法骑行上去。\n");
    }
    if (nextroom&&nextroom->query("daying")&&!enter_permit(me,nextroom)&&!ob->query("wanglou"))
    {
        return notify_fail("必须夺下全场三面战旗，才能直接杀入"+nextroom->query("side")+"军大营。\n");
    }
    if (present("ju ma",ob)&&me->query_temp("riding"))
    {
        horse=me->query_temp("riding");
        juma=present("ju ma",ob);
        if (juma->query("is_juma")&&present(horse,ob))
        {
            return notify_fail("你的坐骑被拒马挡着过不去了，你还是下来牵马过去吧。\n");
        }
    }
    me->set_temp("guozhan/last_go",time());
    return ::valid_leave(me, dir);
}

int die_notify(object victim)
{
    object killer;
    if(!objectp(victim) || !userp(victim)) return 0;
    else
    {
        if (victim->query_temp("guozhan/side")=="明") //复活在赛场
        victim->set_temp("revive_room","/d/guozhan/ming_ying");
        else
        victim->set_temp("revive_room","/d/guozhan/qing_ying");
        killer = victim->get_damage_origin_object();
        if(objectp(killer) && userp(killer) )
        {
            if(killer->query_temp("guozhan/side") != victim->query_temp("guozhan/side"))
            {
                killer->add_temp("guozhan/credit",1);
            }
        }
    }
    return 0;
}
