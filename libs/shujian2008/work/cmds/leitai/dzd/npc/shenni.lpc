// /d/dzd/npc/shenni.c

#include <ansi.h>
inherit NPC;

int ask_leave();

void create()
{
	set_name(HIY"南海神尼"NOR, ({
		"nanhai shenni",
		"shenni",
		"shitai",
	}));
	set("long",
		"她就是在大智岛上修行的南海神尼，虽然武功高强，但看上去跟常人无异。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("per",30);
       set("unique", 1);
	set("class", "bonze");
	set("inquiry",([
		//"leave" : (: ask_leave :),
		//"离开" : (: ask_leave :),
		//"离岛" : (: ask_leave :),
		]));

	setup();

	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}

int ask_leave()
{
	object me = this_player();

	message_vision(HIW"“好吧”，$n"+HIW"随手招过一个女尼，“送这位" + RANK_D->query_respect(me) +"出岛。”\n"NOR,me,this_object());
	me->delete_temp("out_dzd");
	me->delete_temp("last_damage_from");
	call_out("leave_dzd",2,me);
	return 1;
}



void leave_dzd()
{
	int i,j,exp,pot,max;	
	string *oblist;
	object *obj;
	object me = this_player();
	oblist = ({"ziwei jian","zhujing bingchan","yuwang","yufeng ping","xueshen yuchanwan","haitang fen","qimenbagua tupu",
			"pi mao","tanxiang mujian","huqin","hansha sheying","wangnangu dujing","bishou","hulu","wujin beixin"});

	tell_object(me,"你在女尼的指引下，终于离开了大智岛。\n");
	me->delete("maoxian_dzd");

	obj = all_inventory(me);
	max = sizeof(obj);
	for(i=0;i<max;i++) {
		if(member_array(obj[i]->query("id"),oblist) != -1)
			destruct(obj[i]);
	}
	me->move("/d/fuzhou/haigang");
	
	//link_ob->set("dzd_gift",me->query("dzd_gift"));
	//根据gift 奖励 :)
	/*
		dzd_gift
			killed  杀死敌人数目
			found    发现意外
			dead  死亡标记
			win   独活标记
	*/	
	
	/*
	if(!me->query_temp("dzd_winner")) {
		tell_object(me,HIY"你觉得自己的武功虽回复如初，却已不如以前了。\n"NOR);
		me->set("combat_exp",me->query("old_exp") - 2000 );
		me->delete("old_exp");

	}
	else {
		tell_object(me,HIW"经过大智岛的磨难，你感觉自己的武功突飞猛进！\n"NOR);
		exp = 8000 + random(4000);
		me->set("combat_exp",me->query("old_exp") + exp );
		me->delete("old_exp");
		pot = me->query("max_pot");
		tell_object(me,HIW"这次大智岛探险，你总共获得了"
			+ CHINESE_D->chinese_number( exp ) 
                 + "点实战经验，" 
                 + CHINESE_D->chinese_number( pot )
                 + "点潜能。\n"NOR);
              me->add( "potential", pot );
              if( me->query("potential") > me->query("max_pot") )
                me->set("potential", me->query("max_pot") );
	}
	*/
	me->delete("dzd_gift");
	write("这里给出奖励。\n");		
}

