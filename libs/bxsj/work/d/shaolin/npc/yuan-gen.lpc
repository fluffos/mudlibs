// yuangen.c
// creat by tiantian, modify by looklove

#include <ansi.h>
inherit NPC;

int ask_job();

void create()
{
	set_name("缘根", ({ "yuan gen", "yuan", "gen" }) );
	set("gender", "男性" );
	set("age", 38);
	set("long", "他是菜园子的主事僧人，资质平庸，既不能领会禅义，\n"
        "练武也没什么长进，平素最喜多管琐碎事务。\n");
    	set("nickname","菜园管事");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", -1);

	set_skill("unarmed", 50);
	set_skill("dodge", 35);
	set_temp("apply/attack", 5);
	set_temp("apply/attack", 5); 
	set_temp("apply/defense", 5);
	set("combat_exp", 17500 + random(20000));

	set("attitude", "peaceful");
	set("inquiry", ([
		"种菜": (: ask_job :)
	]));
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN"缘根得意洋洋的说道：就是达摩院，罗汉堂的首座犯了戒，只要是罚到菜园子，我一样要问个明白！\n"NOR,
        }) );
                        
	setup();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

int ask_job()
{
	object me=this_player(), ob=this_object();
	int exp1=me->query("combat_exp");
    
	if( me->query("family/family_name") != "少林派" ){
		command("say "+RANK_D->query_respect(me)+"与我少林素无来往，此话不知从何说起。");
		return 1;
	}
    
	if( me->query("class")!="bonze"){
		command("say "+RANK_D->query_respect(me) +"乃俗家弟子，不能在寺内学艺。");
		return 1;
	}
        
        if ( me->query_condition("job_busy")) { 
        	command("say 我现在没空，等会来吧。");
        	return 1;
        }

	if( exp1 < 30000 || exp1 > 60000 ){
		command("say 闲着没事来找作践，我看你恐怕是疯了。");
		command("walkby "+me->query("id"));
		return 1;
	}
    
	if( present("tie tong", me)){
		command("say 你不是拿着铁桶吗？快去干活吧。");
		return 1;
	}

	command("say 我瞧你啊，脸上红红白白，定是偷吃荤腥，是也不是？");
	message_vision(CYN"缘根和尚恶狠狠地对$N说的道：“你每天挑一百担粪水浇菜，只消少了\n"+
		"一担，我用硬扁担、铁棍子打断你的两腿。快去！\n”"NOR,me);
	if(!present("tie tong",environment()))
	new("/d/shaolin/obj/tie-tong")->move(environment(this_object()));
	message_vision("$N从身后拿出一对大铁桶放在地上。\n", ob);
	me->set_temp("jiaoshui_job",1);
	me->apply_condition("job_busy", 5+random(5));
	if( random(10) < 1 ){
		message_vision(CYN"缘根骂道：“贼和尚，瞧不出你小小年纪，居然如此胆大妄为，什么\n"
			+"戒律都去犯上一犯。今日不重重惩罚，如何出得我心中恶气？”\n"NOR,me);
		message_vision("$N折下一根树枝，没头没脑的便向$N头上抽来。\n"NOR,this_object());
    	    	message_vision("$N不敢躲闪，让他抽打，片刻之间，便给打得满头满脸都是鲜血。\n",me);
        	me->add("eff_qi",-(me->query("eff_qi") > 150)?me->query("max_qi")/3:50);
        	if(me->query("eff_qi") <= 0)
            		me->set("eff_qi",1);
        	me->unconcious();
    	}
    	return 1;
}
