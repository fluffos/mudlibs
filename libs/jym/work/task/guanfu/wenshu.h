#include <ansi.h>

void init()
{
        call_out("dest", 1800);
        add_action("do_guankan", ({"guankan","kan"}));
        add_action("do_wancheng","wancheng");
	add_action("do_fangqi","giveup");
}

int do_guankan(string arg)
{
        int now_time, time;
        object me;

        me = this_player();
        now_time = me->query_condition("guanfu_task"); 
        time = me->query_temp("guanfu_time");

        if(!arg) return 0;
        if( arg=="wenshu" ) {
                write(
                        "\n这是一张扬州知府悬赏捉拿江洋大盗的文书，上面栩栩如生的画着一个"
"\n人的头像，下面有一行小字，上面写着：\n“江洋大盗「"+me->query_temp("guanfu_target")+"」，悬赏捉拿”。"
"据飞鸽传书，此犯目前出没于「"+me->query_temp("ch_weizhi")+"」附近。\n");
                if(now_time > time*3/4) write("你现在有充足的时间去寻找目标。\n");
                if(now_time > time/2 && now_time <= time*3/4) write("已经过去一小半时间了。\n");
                if(now_time > time/4 && now_time <= time/2) write("你还有一半的时间去追踪目标。\n");
                if(now_time > time/8 && now_time <= time/4) write("你的时间已经不多了。\n");
                if(now_time > 0 && now_time <= time/8) write("官府好象已经快有新的目标了，你要抓紧时间了。！\n");
              if(now_time <= 0) {
                          write("文书已经被你揉的模糊不清了，看来已经没什麽用了，你只好随手丢掉。\n"); 
                        destruct(this_object());}
                return 1;
        }
}

int do_wancheng(string arg)
{
// object ob;
        object me, target;
        int exp,pot,gfjob_times,now_time, job_time;

        if(!arg) return notify_fail("你要干什么？\n");
        me = this_player();
        target = present(arg, environment(me));
        now_time = me->query_condition("guanfu_task");

        if(!target) return notify_fail("找不到这个东西。\n");
        if(target->query("id") != "corpse") return notify_fail("你并没有完成任务。\n");
        if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("那个并不是目标！\n");
        if(target->query("victim_user")) return notify_fail("嘿嘿，想作弊？！\n");
        if(target->query("my_killer") != me->query("id")) return notify_fail("你晚了一步，目标已经被人杀了。\n");
        if(target->query_temp("mark/dune1")) return notify_fail("那已经是一具已经被人杀过的尸体了。\n");

    message_vision(HIW"$N冷笑一声，从怀中掏出文书看了看，微运内劲将文书向空中飞射出去。"
"\n但见文书化做片片雪片，飞落在$n身上。\n"NOR, me, target);
        target->set("long", target->query("long")+"上面飞落着许多纸片。\n");
        target->set_temp("mark/dune1",1);
        me->delete_temp("guanfu_time");
        me->clear_condition("guanfu_task");
		me->clear_condition("gf_busy");
//        me->apply_condition("gf_busy",10+random(3));
        me->delete_temp("guanfu_target");
        me->delete_temp("ch_weizhi");
        me->delete_temp("path_rooms");
        me->delete_temp("gstart_rooms");
        me->delete_temp("mark");
       exp=150;
		job_time = (int)me->query("gf_job");
		if (job_time > 500) job_time = 500;
        	if (job_time<= 50) exp = exp + job_time * 2; 
		else if (job_time<300 && job_time>=50) exp=exp*2 +  job_time /2 + random(job_time/2); 
		else exp=exp*3+  job_time /2 + random(job_time/4); 
        pot= exp/2 + random(exp/4);
		gfjob_times = 1;
		JOB_GIFTD->job_gift(me,(["combat_exp": exp,
					 "potential": pot,
                                         "gf_job": gfjob_times,]),

			               (["job_name":"gf_jobs",
                                         "job_name_cn":"缉拿江洋大盗",
                                         "job_time_limit":30,]));

        destruct(this_object());
        return 1;
}


int do_fangqi()
{
    object me = this_player();
    message_vision("$N确定要放弃文书任务吗？确定<y>，取消<n>。\n",me);
    add_action("do_yes","y");
    add_action("do_no","n");
    return 1;
}

int do_yes()
{
    object me = this_player();
    int index = 200 + random(50);

    me->delete_temp("guanfu_time");
    me->clear_condition("guanfu_task");
    me->clear_condition("gf_busy");
    me->delete_temp("guanfu_target");
    me->delete_temp("ch_weizhi");
    me->delete_temp("path_rooms");
    me->delete_temp("gstart_rooms");
    me->delete_temp("mark");
    if(me->query("combat_exp") > 250) me->add("combat_exp",-index);
    if(me->query("potential") > 250) me->add("potential",-index/2);

    message_vision("$N放弃了官府任务。\n",me);
    tell_object(me,sprintf("此次失信于官府，信心被受打击。经验损失%d点，潜能损失%d点。\n",index,index/2));

    destruct(this_object());
    return 1;
}

int do_no()
{
    object me = this_player();
    return notify_fail("取消放弃。\n");
}

void dest()
{
       object me;
       me = this_player();
       write("文书已经被你揉的模糊不清了，看来已经没什麽用了，你只好随手丢掉。\n", me);  
       destruct(this_object());
}
