// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("任我行", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "日月神教教主"NOR );
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，
身材甚高，一头黑发，穿的是一袭青衫。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 70);
	set("per", 27);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
       create_family("日月神教",1,"弟子");	
	set("max_qi", 26000);
	set("max_jing", 26000);
	set("neili", 54000);
	set("max_neili", 54000);
	set("jiali", 400);
	set("combat_exp", 9000000);
	set("score", 500000);

	set_skill("literate", 180);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("sword", 260);
	set_skill("changquan", 360);
	set_skill("kuihua-xinfa", 360);
	set_skill("lingxu-bu", 360);
	set_skill("damo-jian", 360);
	set_skill("taiji-jian", 360);
	set_skill("huifeng-jian", 360);
	set_skill("taishan-sword", 360);
	set_skill("hengshan-jian", 360);
	set_skill("hengshan-sword", 300);
	set_skill("huashan-sword", 360);


	set_skill("songshan-jian", 380);
  set_skill("luoyan-jian",380);
  set_skill("shiba-pan",380);
  set_skill("liuhe-dao",380);
  set_skill("hengshan-jian",380);
  
  
  
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "kuihua-xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
          set_skill("sword", 380);
          set_skill("parry", 300);
        set_skill("literate",200);
          set_skill("dodge", 300);
          set_skill("unarmed", 300);
          set_skill("whip", 250);
          set_skill("force", 300);
         set_skill("tmzhang", 380);
        set_skill("staff", 160);
         set_skill("tmjian", 380);
         set_skill("tmdao", 380);
         set_skill("pmshenfa", 380);
          set_skill("strike",300);
          set_skill("cuff",300);
         set_skill("blade", 300);
         set_skill("tmdafa", 320);
set_skill("tmquan", 380);
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                	(: perform_action, "sword.jianshen" :),
                		(: perform_action, "sword.moshen" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "blade.xuan" :),                	
                (: perform_action, "blade.yueshen" :),                	
                (: perform_action, "strike.huashen" :),                
                (: perform_action, "strike.zhen" :),                
                (: perform_action, "strike.tmduan" :),                
                (: perform_action, "cuff.tianmo" :),                
                (: perform_action, "cuff.dimo" :),                
                (: perform_action, "cuff.renmo" :),

        }) );

prepare_skill("cuff","tmquan");

prepare_skill("strike","tmzhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("inquiry", ([
                "比剑" :  (: ask_bijian :),
                "剑法" :  (: ask_bijian :),
                "黑木令" : "要拿黑木令？老夫想先看看你的剑法！\n",
                "任盈盈" : "你难道知道她在哪吗？\n",
                "任我行" : "我就是威震江湖的日月神教教主，你就拜我为师吧。\n",
                "日月神教" : "是的！快加入我们神教吧，这样你的武功就没人能敌。\n",
	]) );
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
if (random(2)==0) 
{
	carry_object("/clone/weapon/changjian")->wield();
}
else
{
carry_object("/clone/weapon/gangdao")->wield();
}
}

void attempt_apprentice(object ob)
{
         if (ob->query_int() < 30) {
              command("say " + RANK_D->query_respect(ob) +
                        "走开走开，我不想和傻瓜说话。");
                return;
        }
         if (ob->query_dex() < 25) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我黑木崖与世隔绝，向来不与您这种成名人物打交道，您请回吧！;\n");
                return;
        }
        command("say 哈哈！ 那我就收下你吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","日月神教任教主亲传弟子");
}

int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n
$n笑道：“不用客气，你来解我寂寞，可多谢你啦。”\n", me, ob );
	message_vision("$N道：“不敢。”\n
$n点了点头，说道：“我只想瞧瞧你的剑法，并非真的过
招，再说，我也未必能胜得了你。”\n\n", me, ob);
	say(HIR"任我行大喝一声：“少林剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才一招。”\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"任我行大喝一声：“武当剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才两招。”\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"任我行大喝一声：“峨嵋剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才三招。”\n");
		return 1;
	}
	command("enable sword songshan-jian");
	say(HIR"任我行大喝一声：“嵩山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才四招。”\n");
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"任我行大喝一声：“泰山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才五招。”\n");
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"任我行大喝一声：“华山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才六招。”\n");
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"任我行大喝一声：“衡山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才七招。”\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"任我行大喝一声：“恒山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“还是没过八招。”\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("任我行说道：“这位" + RANK_D->query_respect(me)+"不错，我就送你一块黑木令吧。”\n");
	return 1;
}
