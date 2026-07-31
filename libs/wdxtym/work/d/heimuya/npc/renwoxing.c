// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "riyue.h"

int ask_pfm(string arg);
int accept_ask(object me, string topic);
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
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 500000);
	set("max_jing", 300000);
	set("neili", 500000);
	set("max_neili", 500000);
	set("jiali", 400);
	set("combat_exp", 5000000);
	set("score", 500000);

    set_skill("force", 280);
    set_skill("unarmed", 280);
    set_skill("dodge", 280);
    set_skill("parry", 280);
    set_skill("sword", 280);
    set_skill("blade", 280);
    set_skill("strike", 280);
    
    set_skill("riyue-xinfa", 280);
    set_skill("tianmo-zhang", 280);
    set_skill("tianmo-dao", 280);
    set_skill("tianmo-jian", 280);
    set_skill("xuwu-piaomiao", 280);
    set_skill("piaomiao-shenfa", 280);
    set_skill("xixing-dafa", 280);
    set_skill("literate", 300);
    /*
    set_skill("taiji-jian", 100);
    set_skill("huifeng-jian", 100);
    set_skill("songshan-sword", 100);
    set_skill("taishan-sword", 100);
    set_skill("huashan-sword", 100);
    set_skill("hengshan-sword", 100);
    set_skill("hengshan-jian", 100);
    set_skill("damo-jian", 100);
*/
    map_skill("force", "riyue-xinfa");
    map_skill("sword", "tianmo-jian");
    map_skill("blade", "tianmo-dao");
    map_skill("strike", "tianmo-zhang");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");
    
	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.chuanxin" :),
		(: perform_action, "sword.moxiao" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set("inquiry", ([
    "#11-一剑穿心"  : (: ask_pfm("一剑穿心") :),
		/*"比剑" :  (: ask_bijian :),
		"剑法" :  (: ask_bijian :),*/
		"黑木令" : "要拿黑木令？老夫想先看看你的剑法！\n",
	]) );
     create_family("日月神教", 1, "第一代教主");
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
void reset_skill()
{
	command("enable sword tianmo-jian");
}
int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n
$n笑道：“不用客气，你来解我寂寞，可多谢你啦。”\n", me, ob );
	message_vision("$N道：“不敢。”\n
$n点了点头，说道：“我只想瞧瞧你的剑法，并非真的过
招，再说，我也未必能胜得了你。”\n\n", me, ob);
	command("enable sword damo-jian");
	say(HIR"任我行大喝一声：“少林剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才一招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"任我行大喝一声：“武当剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才两招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"任我行大喝一声：“峨嵋剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才三招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword songshan-sword");
	say(HIR"任我行大喝一声：“嵩山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才四招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"任我行大喝一声：“泰山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才五招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"任我行大喝一声：“华山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才六招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"任我行大喝一声：“衡山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才七招。”\n");
		reset_skill();
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"任我行大喝一声：“恒山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“还是没过八招。”\n");
		reset_skill();
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("任我行说道：“这位" + RANK_D->query_respect(me)+"不错，我就送你一块黑木令吧。”\n");
	reset_skill();
	return 1;
}
void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;
	
	if (ob->query("gender", 1) =="无性") {
		tell_object(ob, "我平生最讨厌的就是阉人，滚开！\n");
		return;
	}
	if (ob->query("shen", 1) > -100000) {
		tell_object(ob, "你还不够邪恶，我暂时不能收你。\n");
		return;
	}
	if (ob->query_skill("riyue-xinfa", 1) < 160) {
		tell_object(ob, "你的日月心法还没练到家。\n");
		return;
	}
	if (ob->query_skill("kuihua-shengong", 1) > 1 ) {
		tell_object(ob, "你已经学会东方老贼的葵花神功，我怎能收你？\n");
		return;
	}
	if (ob->query("family/master_id") == "dongfang bubai") {
		tell_object(ob, "你个臭不要脸的，东方老贼派你来做卧底的吗？！\n");
		return;
	}
	if (ob->query("family/master_id") != "xiang wentian") {
		tell_object(ob, "我一生只收向问天推荐过来的弟子，可惜你不是。\n");
		return;
	}
   
	command("say 好吧！我就收下你了。");
	command("recruit " + ob->query("id"));
}
int ask_pfm(string arg)
{
	if (arg) {
		object me = this_player();
		
		return accept_ask(me, arg);
	}
	return 1;
}
int accept_ask(object me, string topic)
{
	if (me->query("family/family_name") == "日月神教")
	switch (topic)
	{
        case "一剑穿心" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianmo-jian/chuanxin",
                           "name"    : "一剑穿心",
                           "sk1"     : "tianmo-jian",
                           "lv1"     : 200,]));
                break;

        default:
			break;
	}
	tell_object(me, name()+"：你说什么？再说一遍？\n");
	return 1;
}

