#include <ansi.h>

void init()
{
        call_out("dest", 1800);
	add_action("do_guankan", ({"guankan","kan"}));
	add_action("do_wancheng", ({"wancheng","wancheng"}));
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
"据飞鸽传书，改犯目前出没于「"+me->query_temp("ch_weizhi")+"」附近。\n");
		if(now_time > time*3/4) write("你现在有充足的时间去寻找目标。\n");
		if(now_time > time/2 && now_time <= time*3/4) write("已经过去一小半时间了。\n");
		if(now_time > time/4 && now_time <= time/2) write("你还有一半的时间去追踪目标。\n");
		if(now_time > time/8 && now_time <= time/4) write("你的时间已经不多了。\n");
		if(now_time > 0 && now_time <= time/8) write("官府好象已经快有新的目标了，你要抓紧时间了。！\n");
		return 1;
	}
}

int do_wancheng(string arg)
{
	object me, target;
	int exp,pot,gfjob_times,now_time;

	if(!arg) return notify_fail("你要干什么？\n");
	me = this_player();
	target = present(arg, environment(me));
	now_time = me->query_condition("guanfu_task");

	if(!target) return notify_fail("找不到这个东西。\n");
	if(target->query("id") != "corpse") return notify_fail("你并没有完成任务。\n");
	if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("那个并不是目标！\n");
	if(target->query("userp")) return notify_fail("嘿嘿，想作弊？没门！\n");
	if(target->query("my_killer") != me->query("id")) return notify_fail("你晚了一步，目标已经被人杀了。\n");
        if(target->query_temp("mark/dune1")) return notify_fail("那已经是一具已经被人杀过的尸体了。\n");

	me->add("gf_job",1);
	gfjob_times=(int)me->query("gf_job");
	if (gfjob_times < 1) gfjob_times = 1;
    message_vision(HIW"$N冷笑一声，从怀中掏出文书看了看，微运内劲将文书向空中飞射出去。"
"\n但见文书化做片片雪片，飞落在$n身上。\n"NOR, me, target);
    write(WHT"很好！你成功地完成了任务。目前你已经为官府做了"+gfjob_times+"次贡献。\n"NOR);
	
	target->set("long", target->query("long")+"上面飞落着许多纸片。\n");
	
        target->set_temp("mark/dune1",1);
	me->delete_temp("guanfu_time");
	me->clear_condition("guanfu_task");
	me->delete_temp("guanfu_target");
	me->delete_temp("ch_weizhi");
	me->delete_temp("path_rooms");
	me->delete_temp("gstart_rooms");
	me->delete_temp("mark/gkill3");

	if ((int)me->query("combat_exp")<120000){
         pot=60+random(60+me->query("max_pot")*3/2);
                if (pot > 200) pot =200;
         exp=(100+random(3)*50); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>120000 && 
	me->query("combat_exp")<380000){
         pot=70+random(80 + me->query("max_pot"));
                if (pot >220) pot =220;
         exp=(150+random(3)*70); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
		destruct(this_object());
		return 1;
	}
	if ((int)me->query("combat_exp")>380000 && 
         me->query("combat_exp")<780000){
         pot=90+random(100 + me->query("max_pot")*3/2);
                if (pot > 280) pot =280;
         exp=(200+random(3)*80); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>780000 && 
         me->query("combat_exp")<1000000){
         pot=120+random(120 + me->query("max_pot")*3/2);
                if (pot > 350) pot =350;
         exp=(250+random(3)*80); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
         destruct(this_object());
         return 1;
	}
	pot=150+random(150 + me->query("max_pot")*3/2);
                   if (pot > 400) pot =400;
	exp=(300+random(3)*100); 
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->add("gf_job",1);
	 write("此次工作获得"+exp+"点经验，"+pot+"点潜能，\n");
	destruct(this_object());
	return 1;
        
}

void dest()
{
       object me;
       me = this_player();
       write("文书已经被你揉的模糊不清了，看来已经没什麽用了，你只好随手丢掉。\n", me);  
       destruct(this_object());
}
