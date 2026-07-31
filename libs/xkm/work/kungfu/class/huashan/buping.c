//Cracked by Roath
// buping.c 封不平
// qfy Oct 21, 1996

#include <ansi.h>
inherit NPC;
string ask_me();
string ask_kfkj();

void create()
{
	set_name("封不平", ({ "feng buping", "feng", "buping" }));
	set("long", 
"封不平是华山剑宗的第一高手。剑气之争剑宗一败涂地，封不平隐\n"
"居苦练，誓雪此辱。他内外兼修，不仅剑法了得，内功亦是不凡。\n");
	set("gender", "男性");
	set("age", 47);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 28);
	set("int", 30);
	set("con", 27);
	set("dex", 28);
	set("shen", 0);
	
	set("max_qi", 1200);
	set("max_jing", 850);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 920000);
	set("score", 5000);

	set_skill("force", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("sword", 155);
	set_skill("strike", 130);
	set_skill("cuff", 130);
	set_skill("huashan-shenfa", 140);
	set_skill("zixia-gong", 130);
	set_skill("huashan-jianfa", 155);
	set_skill("hunyuan-zhang",130);
	set_skill("pishi-poyu", 130);
	set_skill("ziyin-yin", 100);
	set_skill("zhengqi-jue", 100);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 13, "剑宗弟子");
	
	set("inquiry", ([
	    "剑宗" : "剑宗才是华山的正统，以剑为宗，以气为辅，才是武学的精要。\n",
	    "气宗" : "哼！气宗武功庸俗不堪，奉气轻剑，乱七八糟。\n",
	    "岳不群" : "别提那伪君子！可恶！\n",
	    "华山剑法" : "那便是本派绝学，天下一等一的剑法！尤其是「天外飞龙」一招，飞剑杀敌，无人能挡。\n",
	    "紫霞功" : "那是本门内功心法。\n",
	    "思过崖" : "那是本派弟子修行思过之处。\n",
	    "风清扬" : "啊！我已多年不见风师叔，不清楚他的下落。\n",
	    "飞剑" : "「天外飞龙」是本派绝招，飞剑出击，中者立毙！\n",
	    "飞剑杀敌" : "「天外飞龙」是本派绝招，飞剑出击，中者立毙！\n",
	    "天外飞龙" : (: ask_me :),
            "狂风快剑" : (: ask_kfkj :),
	]));

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init() 
{
	object ob, me = this_object();

	::init();
	if (interactive(ob=this_player()) && ob->query("family/master_id") == "feng buping"
	&& ob->query("shen") < -100 ) {
		command("say " + RANK_D->query_rude(ob) + "竟敢在外胡作非为，败坏本派名声！" );
		me->kill_ob(ob);
	}
}

int accept_fight(object ob)
{
	object me = this_object();
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		call_out("checking", 1, me, ob);
		return 0;
	}       

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say 好家伙，让你尝尝本人自创的狂风快剑，你也该死得瞑目了吧！");
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int my_max_qi = me->query("max_qi");
	object weapon;

	if (me->is_fighting()) {
	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
		command("exert recover");
	   }

	   if ( !me->query_temp("attack_pending") 
	   && objectp(weapon = me->query_temp("weapon")) ) {
		me->set_temp("attack_pending", 1);
		remove_call_out("fast_attack");
		call_out("fast_attack", 3, me, ob);
	   }

	   call_out("checking", 1, me, ob);
	   return 1;
	}

	if (!me->is_fighting()) {
		me->delete_temp("attack_pending");
		remove_call_out("fast_attack");
	}

	if ( !present(ob, environment()) && me->query("attack_pending")==1 ) {
	   me->delete_temp("attack_pending");
	   return 1;
	}

	return 1;
}

int fast_attack(object me, object ob)
{
	int i, num;

	me->delete_temp("attack_pending");

	if (!me->query_temp("weapon")) return 1;
	num = random(2)+3;

	message_vision(RED"\n封不平脸色沉重，使出其绝技「狂风快剑」，运剑如风似电般向$N连刺了"+chinese_number(num)+"剑。\n"NOR, ob);

	for (i=1; i<num+1; i++) {
	    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	}

	return 1;
}

string ask_me()
{
	object ob = this_player(), me = this_object();
	mapping obfam;
	obfam = (mapping)ob->query("family");

	if ( !obfam || obfam["family_name"] != "华山派" ) {
	   if ( ob->query_temp("feilong") < 3 ) {
		command( "sneer" );
		ob->add_temp("feilong", 1);
		return "咱们豪无渊源，你问这做什么？还是别太好奇的好。\n";
	   }
	   else {
		message_vision("$N脸色微变，目中阴鹭一闪，发出一阵冷笑。\n", me);
		ob->delete_temp("feilong");
		me->kill_ob(ob);
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return "你三番四次想探听华山剑法的奥密，居心叵测！是否想对本派不利？你即然对华山剑法如此憧景，只好用华山剑法送你上路了。\n";
	   }
	}
	
	command( "look "+ob->query("id") );

	if ( ob->query_skill("huashan-jianfa", 1) < 100 )
		return "你的华山剑法修为不够，学不了「天外飞龙」。";

	if ( ob->query_skill("zixia-gong", 1) < 70 )
		return "剑宗以剑为宗，以气为辅，并非弃气不用，你的紫霞功可得再下一番苦功。";

	if ( ob->query_skill("zixia-gong", 1) > ob->query_skill("huashan-jianfa", 1) ) {
		command( "sneer" );
		return "你是气宗的人，却来向我请教，教我如何担当得起？";
	}

	if ( ob->query("huashan/feilong") )
		return "咦，我不是传了你「天外飞龙」吗？多下功夫好好练习，别堕了华山剑宗的威名！";

	command( "say 好！我便传你「天外飞龙」。看仔细了！" );

	message_vision("$N剑走龙蛇，白光如虹，凝重处如山岳巍峙，轻灵处若清风无迹，变幻莫测。\n"
		      +"舞到急处，$N一声大喝，长剑脱手飞出，化作一道惊虹，直没至柄插入一株树中。\n", me);

	ob->set("huashan/feilong", 1);

	return "你今后得要勤加练习，别辜负了我的一番教导。";
}

string ask_kfkj()
{
        object ob = this_player(), me = this_object();
        mapping obfam;
        obfam = (mapping)ob->query("family");

        if ( !obfam || obfam["family_name"] != "华山派" ) {
           if ( ob->query_temp("kuangfeng") < 3 ) {
                command( "sneer" );
                ob->add_temp("kuangfeng", 1);
                return "江湖中人最忌偷学他门决学，再这样我就不客气了。\n";
           }
           else {
                message_vision("$N脸色微变怒道：“既然你三番五次戏弄于我，领死吧！”。\n", me);
                ob->delete_temp("kuangfeng");
                me->kill_ob(ob);
                remove_call_out("checking");
                call_out("checking", 1, me, ob);
                return "既然你如此痴迷华山剑宗绝技，那么让你见识一下，去见阎王吧！\n";
           }
        }

        command( "look "+ob->query("id") );
        if ( ob->query_skill("huashan-jianfa", 1) < 100 )
                return "你的华山剑法如此之差，如何学的我门绝学「狂风快剑」。";
        if ( ob->query_skill("zixia-gong", 1) < 100 )
                return "剑宗以剑为宗，以气为辅，并非弃气不用，你的紫霞功可得再下一番苦功。";

        if ( ob->query_skill("zixia-gong", 1) > ob->query_skill("huashan-jianfa", 1) ) {
                command( "walkby" );
                return "气宗、剑宗对敌多年，难道你想偷窥我剑宗绝学？";
        }

        if ( ob->query("huashan/kuangfeng") )
                return "狂风快剑我已经传授于你，何必又来叨扰为师！";

        command( "say 既然你有意兼学我剑宗绝技，可见你并无气、剑芥蒂！我便传你「狂风快剑」。看仔细了！" );

         message_vision(HIG"$N仰天一声清啸，斜行而前，长剑横削直击，迅捷无比，未到五六招，剑势中已发出隐隐风声。\n$N出剑越来越快，风声也是渐响，剑锋上所发出的一股劲气渐渐扩展，旁观众人只觉寒气逼人，\n$N脸上一红，一柄长剑更使得犹如疾风骤雨一般。\n\n"NOR, me);

        ob->set("huashan/kuangfeng", 1);
          message_vision(HIR"$N说道：这套剑法一显之后，便露了底，此后再和一流高手相斗，对方先已有备，\n便难收出奇制胜之效。\n\n"NOR, me);
       return "好好练习，不要坠了我华山剑宗的名声。";
}
