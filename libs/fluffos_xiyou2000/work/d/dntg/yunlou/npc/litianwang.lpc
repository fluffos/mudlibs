// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

string *list=({"yg-putuo","yg-moon","yg-wzg",
	"yg-fangcun","yg-hell","yg-jjf",
	"yg-dragon", "yg-xueshan",
	"yg-wudidong",
	});

int work_me();
 
void create()
{
 
	set_name("李靖", ({ "li jing", "jing", "li" }) );
	set("gender", "男性" );
	set("long", "托塔李天王乃是天界元帅，麾下十万天兵天将，法力无边。\n");
	set("age",40);
	set("title", "托塔天王");
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("spi", 30);
	set("per", 30);
	set("class", "xian");
	set("attitude", "heroism");
	set("combat_exp", 1500000);
	set("daoxing", 2000000);
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force",5000);
	set("max_force",3000);
	set("force_factor", 150);
	set("mana", 5000);
	set("max_mana", 3000);
	set("mana_factor", 150);

	set("eff_dx", 600000);
	set("nkgain", 600);

	set_skill("unarmed",170);
	set_skill("dodge",170);
	set_skill("parry",170);
	set_skill("sword", 180);
	set_skill("force", 170);
	set_skill("spells", 170);
 	set_skill("changquan", 170);
	set_skill("liangyi-sword", 180);
	set_skill("baguazhou", 170);
	set_skill("moshenbu", 170);
	set_skill("lengquan-force", 170);
	map_skill("unarmed", "changquan");
	map_skill("force", "lengquan-force");
	map_skill("spells", "baguazhou");
	map_skill("sword", "liangyi-sword");
	map_skill("parry", "liangyi-sword");
	map_skill("dodge", "moshenbu");
	
	set("chat_chance",1);
	set("chat_msg", ({
		    name()+"说道：哪位大仙可愿去下界灭妖？\n",
		    }));

        seteuid(getuid());

set("inquiry", ([
"mieyao": (: work_me :),
"kill": (: work_me :),
"灭妖": (: work_me :),
]));

	setup();
	carry_object("/d/obj/fabao/huangjin-baota");
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/sky/obj/zhanyaojian")->wield();
}
 
int work_me()
{
	object ghost, me;
	int t, lvl;
	me=this_player();
	//for first time.
	if(!me->query("mieyao")) {
		call_out("start_job", 1, me);
		return 1;
	}
	if( (t=(int)me->query("mieyao/time_start")) &&
		!me->query("mieyao/done")) {

	    if(t<=time() &&
		    time()<t+1800) {
		command("heng");
		command(
 		  "say 老夫不是派你去降服"+me->query("mieyao/name")
		  +"吗？\n");
		return 1;
	    }
	    // failed, decrease lvl.
	    if(!me->query_temp("mieyao/level_changed")) {
		lvl=me->query_temp("mieyao/level");
		if(lvl>0) lvl--;
		me->set_temp("mieyao/level",lvl);
		me->set_temp("mieyao/level_changed",1);
	    }
	    // allow ask again.
	} else { // job done
	    if(t<=time() &&
		    time()<t+10) {
		message_vision("$N对手中照妖镜一看，说"+
			"：这位"+RANK_D->query_respect(me)
			+",妖魔已除尽,不妨先去歇息。\n",
			this_object(), me);
		return 1;
	    }
	    // succeed, increase lvl.
	    if(!me->query_temp("mieyao/level_changed")) {
		lvl=me->query_temp("mieyao/level");
		if(lvl<9) lvl++; // total 10 levels: 0, ..., 9
		else
		    lvl=1; // reach the top level, reduce difficulty.
		me->set_temp("mieyao/level",lvl);
		me->set_temp("mieyao/level_changed",1);
	    }
	}
	me->delete("mieyao/time_start");
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	string where;
	object ghost;
	int lvl;

	if(environment(me)!=environment()) return 1;
	if(me->query("mieyao/time_start")) return 1;
	me->delete("mieyao/done");
	me->set_temp("mieyao/level_changed",0);

	// determine levels.
	// use temp mark, if quit, then start over.
	lvl=me->query_temp("mieyao/level");
	
        ghost = new(__DIR__+list[random(sizeof(list))]);
        where=ghost->invocation(me, lvl);
	
	message_vision("$N将手中照妖镜朝下界一晃！\n",this_object());
	message_vision("$N对$n说道：近有"+where+"为非作歹，"
		+"请速去降服！\n"
		,this_object(),me);
	me->set("mieyao/time_start", time());
	me->set("mieyao/name",ghost->query("name"));
	return 1;
}
