//by fly@YSZZ

#include <ansi.h>
void init()
{
       remove_call_out("dest");
         call_out("dest", 900,this_player());
//        add_action("do_fangqi", ({"si"}));
        add_action("do_guankan", ({"guankan","kan"}));
        add_action("do_wancheng", ({"qidao","wancheng"}));
}
int do_guankan(string arg)
{
        object me;
        me = this_player();
        if(!arg) return 0;
        if( arg=="wenshu" ) {
         if (me->query_temp("guanfu_target") && me->query_temp("ch_weizhi")){
         write(WHT"\n这是一张开封知府悬赏捉拿妖神的文书，上面栩栩如生的画着一个人的"NOR+
               WHT"\n头像，下面有一行小字，上面写着："NOR+
               YEL"\n        「"NOR+HBRED+me->query_temp("guanfu_target")+NOR+WHT"」        \n"NOR+
               HIY"\n据飞鸽传书，要犯目前出没于「"+me->query_temp("ch_weizhi")+"」附近。\n\n"NOR);
                return 1;
         }else {
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
        string ttime; 
        object me, target;
        int exp,pot,gfjob_times,now_time,pot_reward,exp_reward;

        if(!arg) return notify_fail("[官府]:你要干什么？\n");
        me = this_player();
        target = present(arg, environment(me));
        now_time = me->query_condition("guanfu_task");

        if(!target) return notify_fail("[官府]:找不到这个东西。\n");
        if(target->query("id") != "corpse") return notify_fail("[官府]:你并没有完成任务。\n");
        if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("[官府]:那个并不是目标！\n");
        if(target->query("victim_user")) return notify_fail("[官府]:嘿嘿，想作弊？！\n");
//        if(target->query("kill_by") != me) return notify_fail("[官府]:你晚了一步，目标已经被人杀了。\n");
        if(target->query_temp("mark/dune1")) return notify_fail("[官府]:那已经是一具已经被人通缉过的尸体了。\n");

        me->add("gf_job",1);
        gfjob_times=(int)me->query("gf_job");
        if (gfjob_times < 1) gfjob_times = 1;
        message_vision(HIW"$N点了点头，从怀中掏出文书确定了一下，合十向上天祈祷。\n"NOR, me, target);
        message_vision(HIW"但见文书幻化做片片雪片，慢慢地将$n覆盖。\n"NOR, me, target);
        write(WHT"目前你已经为朝廷捉拿了"+gfjob_times+"个要犯。\n"NOR);
        target->set("name", HIB""+me->name()+"缉缴的"NOR+target->query("name"));
        target->set("long", target->query("long")+HBRED"上面飞落着许多纸片，而死无收尸，正是叛徒的下落。\n"NOR);
        target->set_temp("mark/dune1",1);
        me->delete_temp("guanfu_time");
        me->clear_condition("guanfu_task");
        me->delete_temp("guanfu_target");
        me->delete_temp("ch_weizhi");
        me->delete_temp("path_rooms");
        me->delete_temp("gstart_rooms");
        me->delete_temp("mark/gkill3");
        exp=(int)me->query("combat_exp");
        if(exp<30000) {
            exp_reward=500+random(200);
            pot_reward=300+exp/300;
        } else if(exp<300000) {
            exp_reward=700+random(200);
            pot_reward=400+exp/6000;
        } else if(exp<3000000) {
            exp_reward=900+random(200);
            pot_reward=400+exp/60000;
        } else {
            exp_reward=1000+random(200);
            pot_reward=600+random(500);
        }
        exp_reward=exp_reward/2+(int)me->query("gf_job")+random(exp_reward/4);
        if (exp_reward>1000) exp_reward=800+random(500);
        pot_reward=pot_reward/2+(int)me->query("gf_job")+random(pot_reward/4);
        if (pot_reward>1000) pot_reward=800+random(400);
        if (pot_reward<350) pot_reward=300+random(100);
        if(!me->query_temp("guanfu/last_damage")) {
        exp_reward=exp_reward/3;
        pot_reward=pot_reward/3;
       }
        exp_reward=exp_reward*(2+random(2))/3;
        pot_reward=pot_reward*(2+random(2))/3;
        me->delete_temp("guanfu/last_damage");
        me->add("potential",pot_reward);
        me->add("office_number",1+random(3));
        me->add("combat_exp",exp_reward);
        ttime=ctime(time())[8..strlen(ctime(time()))];
   log_file("guanfu_job",sprintf("%s%s(%s)官府任务奖励:%i点EXP %i点POT（%i点EXP）\n",
      ttime,me->name(1), getuid(me),exp_reward, pot_reward,(me->query("combat_exp")-(int)me->query_temp("mark/combat_exp"))));
        me->delete_temp("mark/combat_exp");
        message_vision(HIY"\n$N黯然回顾一下刚才凶险的格斗之景，不禁心有所悟。\n"NOR, me, target);
        write(MAG"你默然领悟了"NOR+exp_reward+MAG"点道行，被奖励了"NOR+pot_reward+MAG"点潜能。\n"NOR);
        destruct(this_object());
        return 1;
}

void dest(object me)


{
         me=this_player();
      if (!me) return;
         write(YEL"[官府]:文书时间过长已经模糊不清。\n"NOR);  
         write(YEL"[官府]:你的官府任务失败。\n"NOR);  
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

/*
int do_fangqi(string arg)
{
        object me, target;

        if(!arg) return notify_fail("[官府]:你要干什么？\n");
        me = this_player();
       if (time()<(me->query("gf_time")+120))
        return notify_fail(HIR"[官府]"NOR+":你怎么如此没有耐心,没有毅力！\n");
        if( arg=="wenshu" ) {
       write(YEL"[官府]:文书时间过长已经模糊不清。\n"NOR, me);  
       write(YEL"[官府]:你随手就扔了这份文书败。\n"NOR, me);  
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
        me->add("office_number",-5-random(3));
            target =present("wenshu", me);
       write("target"+target->query("name")+"\n"NOR, me);  
       destruct(target);
                return 1;
        }
}
*/

