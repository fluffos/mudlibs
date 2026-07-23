//by fly@YSZZ

#include <ansi.h>

void init()
{
    add_action("do_guankan", ({"guankan","kan"}));
    add_action("do_wancheng", ({"qidao","wancheng"}));
}

void dest(object me)
{
     me=this_player();
     if (!me) return;
     tell_object(me, YEL"[官府]:文书时间过长已经模糊不清。\n"NOR
                    +YEL"[官府]:你的官府任务失败。\n"NOR);
    me->delete_temp("guanfu_target");
    me->delete_temp("guanfu_time");
    me->clear_condition("guanfu_task");
    me->delete_temp("guanfu_target");
    me->delete_temp("ch_weizhi");
    me->delete_temp("path_rooms");
    me->delete_temp("gstart_rooms");
    me->delete_temp("mark/gkill1");
    me->delete_temp("mark/gkill2");
    me->delete_temp("mark/gkill3");
    destruct(this_object());
}

int do_guankan(string arg)
{
    object me;
    me = this_player();
    if(!arg) return 0;

//ephq 十分钟
    if( time() - this_object()->query("time") > 900 ) 
    {
        dest(me);
        return 1;
    }
    if( arg=="wenshu" ) 
    {
        if( me->query_temp("guanfu_target") && me->query_temp("ch_weizhi") )
        {
            write(WHT"\n这是一张开封知府悬赏捉拿妖神的文书，上面栩栩如生的画着一个人的"NOR+
                  WHT"\n头像，下面有一行小字，上面写着：\n"NOR+
                  YEL"\n        「"NOR+HBRED+me->query_temp("guanfu_target")+NOR+WHT"」        \n"NOR+
                  HIY"\n据飞鸽传书，要犯目前出没于「"+me->query_temp("ch_weizhi")+"」附近。\n\n"NOR);
                  return 1;
        }
        else 
        {
            write(WHT"\n这是一张开封知府悬赏捉拿妖神的文书，上面却形象模糊地画着一个人的"NOR+
                  WHT"\n头像，下面有一行小字，上面写的东西早就模糊不已。"NOR+
                  HIY"\n而飞鸽传书太慢，要犯目前出没地点不定。\n"NOR+
                  HIY"任务几乎渺茫，难度不小。\n\n"NOR);
                  return 1;
        }
    }
}

int do_wancheng(string arg)
{
    object me, target;
    int gfjob_times, now_time, pot_reward, exp_reward;

    if(!arg) return notify_fail("[官府]:你要干什么？\n");
    me = this_player();
    target = present(arg, environment(me));
    now_time = me->query_condition("guanfu_task");

    if( !target )
        return notify_fail("[官府]:找不到这个东西。\n");
        
    if( target->query("id") != "corpse" )
        return notify_fail("[官府]:你并没有完成任务。\n");
    
    if( target->query("victim_name") != me->query_temp("guanfu_target") )
        return notify_fail("[官府]:那个并不是目标！\n");
        
    if( target->query("victim_user") )
        return notify_fail("[官府]:嘿嘿，想作弊？！\n");
        
    if( target->query("killer_id") != me->query("id") )
        return notify_fail("[官府]:你晚了一步，目标已经被人杀了。\n");
        
    if( target->query_temp("mark/dune1") )
        return notify_fail("[官府]:那已经是一具已经被人通缉过的尸体了。\n");

    me->add("gf_job",1);
    gfjob_times=(int)me->query("gf_job");
    if( gfjob_times < 1 ) gfjob_times = 1;
    message_vision(HIW"$N"HIW"点了点头，从怀中掏出文书确定了一下，合十向上天祈祷。\n"NOR, me, target);
    message_vision(HIW"但见文书幻化做片片雪片，慢慢地将$n覆盖。\n"NOR, me, target);
    write(WHT"目前你已经为朝廷捉拿了"+gfjob_times+"个要犯。\n"NOR);
    destruct(target);

    me->delete_temp("guanfu_time");
    me->clear_condition("guanfu_task");
    me->delete_temp("guanfu_target");
    me->delete_temp("ch_weizhi");
    me->delete_temp("path_rooms");
    me->delete_temp("gstart_rooms");
    me->delete_temp("mark/gkill3");
    
    if( gfjob_times < 1000 ) 
    {
        exp_reward = 400+random(200);
        pot_reward = 400+random(200);
    } 
    else if( gfjob_times < 2000 ) 
    {
        exp_reward = 500+random(300);
        pot_reward = 500+random(300);
    } 
    else if( gfjob_times < 5000 ) 
    {
        exp_reward = 600+random(400);
        pot_reward = 600+random(400);
    } 
    else if( gfjob_times < 10000 )
    {
        exp_reward = 700+random(500);
        pot_reward = 700+random(500);
    }
    else if( gfjob_times < 20000 )
    {
        exp_reward = 800+random(600);
        pot_reward = 800+random(600);
    }
    else if( gfjob_times < 50000 )
    {
        exp_reward = 900+random(700);
        pot_reward = 900+random(700);
    }
    else
    {
        exp_reward = 1000+random(800);
        pot_reward = 1000+random(800);
    }

    exp_reward = exp_reward+random((int)me->query_skill("force",1)/2);
    pot_reward = pot_reward+random((int)me->query_skill("force",1)/4);

    if( !me->query_temp("guanfu/last_damage") ) 
    {
        exp_reward = exp_reward/3;
        pot_reward = pot_reward/3;
    }
  
    me->delete_temp("guanfu/last_damage"); 

    me->add("combat_exp", exp_reward);
    me->add("potential", pot_reward);    
    
    me->delete_temp("mark/combat_exp");
    
    if( me->query("office_nubmer") > 25000 ) me->set("office_nubmer",25000);
    else me->add("office_number",1+random(2));    
    
    message_vision(HIY"\n$N"HIY"黯然回顾一下刚才凶险的格斗之景，不禁心有所悟。\n"NOR, me, target);
    write(MAG"你默然领悟了"NOR+exp_reward+MAG"点道行，被奖励了"NOR+pot_reward+MAG"点潜能。\n"NOR);
    if( (me->query("gf_job")%50) == 0 ) 
    {
        me->add("repute",1);
        write(HIG"恭喜，你因追杀叛徒有功，被额外奖励了"HIR"一"HIG"点声望。\n"NOR);
    }
    destruct(this_object());
    return 1;
}
