// daerba.c 达尔巴
// by iceland
// Modify by Lklv 2001.10.16

#include <ansi.h>

inherit NPC;
string ask_master();

void create()
{
        object weapon;
        set_name("达尔巴", ({ "daer ba", "daerba" ,"daer","ba"}));
        set("long",@LONG
他是金轮法王座下二弟子，看起来身材削瘦，神情木讷，脑筋不大灵便。
他双臂却骨节突出，双手巨大，天生神力。
LONG
        );
        set("title", HIY "大轮寺金轮法王座下弟子" NOR);
        set("gender", "男性");
	set("class", "huanxi");
        set("age", 45);
  	set("attitude", "peaceful");
	set("shen_type", -1);
        set("str", 50);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("eff_jing", 500);
	set("max_jing", 500);
        set("neili", 1700);
        set("max_neili", 1700);
        set("jiali", 70);
        set("combat_exp", 650000);
        set("score", 60000);
	set("unique", 1);

	set("inquiry", ([
		"金轮法王"   : (: ask_master:),
	]));

        set_skill("huanxi-chan", 140);
        set_skill("literate", 80);
        set_skill("force", 140);
        set_skill("longxiang-boruo", 140);
        set_skill("dodge", 140);
        set_skill("yuxue-dunxing", 140);
        set_skill("staff", 160);
        set_skill("wushang-dali", 160);
        set_skill("hand", 140);
        set_skill("dashou-yin", 140);
        set_skill("parry", 140 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("大轮寺", 11, "弟子");
        set("class", "huanxi");

        setup();
        carry_object(__DIR__"obj/changsheng-jiasha")->wear();
	if (clonep()){
		weapon = unew(BINGQI_D("jgxmc"));
		if(!weapon)weapon=new(BINGQI_D("jingang-zuan"));
		weapon->move(this_object());
		weapon->wield();
		add_money("gold",1);
	}
}

string ask_master()
{
	mapping fam;
	object ob=this_player();

	if (!(fam = ob->query("family")) || fam["family_name"] != "大轮寺")
		return "达尔巴说道：俺师傅是天下第一高手，名扬天下谁个不知，哪个不晓。\n";
	if (ob->query("family/generation") > 11 )
		return RANK_D->query_respect(ob)+"在雪山上呆得还少，还是找你自己得师傅多多请教吧。\n";
	if (ob->query_temp("win_deb"))
		return RANK_D->query_respect(ob)+"我已经服了你，愿意认你做师兄。\n";
	if ((int)ob->query_skill("longxiang-boruo", 1) < 140)
		return "师傅总说我天生愚笨，无法领悟我派神奇的内功，你内功修为还不如我呐，还问什么？\n";
	if ((int)ob->query_skill("huanxi-chan", 1) < 120) {
		command("say 雪山大轮寺欢喜禅意天下无双。");
		return " 在欢喜禅方面，" + RANK_D->query_respect(ob) + "修行的还不够吧？\n";
	}
	ob->set_temp("p_fight",1);
	return "要想见我恩师，就得先赢了我手中这根金刚降魔杵。\n";
}

int accept_fight(object ob)
{
	object me  = this_object();
	object weapon;
	if (!ob->query_temp("p_fight") ) return 0;
	if (!weapon=present("jingangchu",me))
		return notify_fail("达尔巴说道：没了金刚降魔杵，怎么和你比武？\n");
	message_vision("\n达尔巴点点头，说道：我的无上大力杵法厉害之极，打死你可别怨。\n",this_player());
	me->reincarnate();
	me->set("neili",me->query("max_neili"));
	me->set("chat_chance_combat", 40);
	me->set("chat_msg_combat", ({
		(: exert_function, "shield daer ba" :),
	}) );
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("p_fight");
	return 1;
}

int checking(object me, object ob)
{
	if (me->is_fighting()) {
		call_out("checking",1, me, ob);
		return 1;
	}
	if ( !present(ob, environment()) ) return 1;

	if( me->query_temp("last_lost_to") == ob
	 && me->query_temp("last_damage_from") == ob) {
		command( "say 好功夫"+ RANK_D->query_respect(ob) +
			"可以去见师傅做俺的师兄了。\n");
		ob->set_temp("win_deb",1);
		}
	return 1;
}
