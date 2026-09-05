// 山路
// edit: by zine Oct 19 2010


#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIG"山林"NOR);
	set("long", @LONG
这里是一片郁郁葱葱的山林，进来以后你几乎寸步难行，你可以原路退(tui)
回，也可以继续探索(tansuo)。
LONG
	);
    set("no_task",1);
    set("no_die",1);
    set("real_dark",1);
    set("no_sleep_room",1);
	setup();
	
}

void init()
{
    object me=this_player();
	add_action("do_tui", ({ "tui" }));
    add_action("do_special",({ "special" }));
    add_action("do_explore", ({ "tansuo" }));
	me->listen_to_die(this_object());
}

int die_notify(object victim)
{
    int pot,exp;
    exp=random(15000-(victim->query("kar")*victim->query("int")*4));
    if (exp<5000)
    {
        exp=5000;
    }
    pot=exp/2;
    ANTIROBOT_D->same_as_fullme(victim);
    exp=REWARD_D->add_exp(victim,-exp);
    pot=REWARD_D->add_pot(victim,-pot);
    tell_object(victim,RED+"你在山林里损失了：\n");
    tell_object(victim,"\t"+chinese_number(-exp)+"点经验；\n");
    tell_object(victim,"\t"+chinese_number(-pot)+"点潜能；\n"NOR);

    victim->remove_listen_to_die(this_object());
    return 1;
}

int do_special()
{
    tell_object(this_player(),"在这片原始森林里，似乎所有技能都失灵了。\n");
    return 1;
}

int checkst(object me)
{
    
    string* desc=({"你仔细查看自己的脚印，很自信地选择了一个方向。\n","你静下心，认真思考出路。\n","你顺着河流走，几乎就要走出这片原始森林了。\n","你像个没头苍蝇一样乱转，似乎回到了原地。\n",});
    string* color=({HIW,HIY,HIG,HIR,HIM});
    int exp;
    if (me->query_temp("tuitimes")>6+random(10))
    {
        if (base_name(environment(me))!="/d/nanchang/shanlin")
        {
            tell_object(me,"你莫名其妙已经走出了原始森林。\n");
            return 1;
        }

        else
        {
            if (random(100)>49)
            {
                me->move("/d/nanchang/z_xiaolu1");
            }
            else
            {
                me->move("/d/nanchang/z_xiaolu2");
            }
            me->remove_listen_to_die(this_object());
            write ("你终于走出了原始森林。\n");
            me->set_temp("tuitimes",0);
            return 1;
         
        }
    }
    else
    {
        if (base_name(environment(me))!="/d/nanchang/shanlin")
        {
            tell_object(me,"你莫名其妙已经走出了原始森林。\n");
            me->remove_listen_to_die(this_object());
            return 1;
        }
        tell_object(me,color[random(sizeof(color))]+desc[random(sizeof(desc))]+NOR);
        me->add_temp("tuitimes",1);
        me->add_busy(2);
        call_out("checkst",2,me);
        return 1;
    }
}

int do_tui()
{
        object me = this_player();
        
        if( this_player()->is_busy() )
                return notify_fail("你正忙着呢，怎么退啊？\n");
        if ( me->is_fighting())
                return notify_fail("你在战斗呢。\n");
        message_vision("$N开始寻找来时的路径。\n", me);
        me->set_temp("tuitimes",0);
        call_out("checkst",1,me);
        return 1;
}

int do_explore()
{
    
	object me = this_player();
    object laohu;
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("喘口气再走吧！\n");
        }
    message_vision(HIY"$N"+HIY+"分开两旁的树枝，艰难地向老林深处进发。\n"NOR,me);
    me->add_busy(2+random(5));
    if ((random(100)>94 && !me->query("zhuangquest"))||wizardp(me))
        {
            laohu=new(__DIR__"npc/laohu");
            tell_object(me,"一声虎啸，一只猛虎从山林里冲了出来。\n");
   		    laohu->set_temp("seeme",me->query("id"));
    		laohu->do_copy(me);
    		laohu->move(this_object());
    		laohu->kill_ob(me);
    		me->kill_ob(laohu);
            return 1;
        }
    else
        {
            tell_object(me,"周围很安静，什么都没有发现。\n");
            return 1;
        }
    
}

