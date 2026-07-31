// Last Modified by Winder on May. 29 2601
// Npc: /kungfu/class/nanshaolin/tianjing.c

#include "tian.h";
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_yes();
string ask_me();
string ask_murenxiang();

void create()
{
	set_name("天镜大师", ({ "tianjing dashi", "tianjing", "dashi"}));
	set("long",
		"他是一位白须的老僧，身穿一袭金丝绣红袈裟。他身材不高，\n"
		"太阳穴微凸，双目炯炯有神。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 120);
	set("max_qi", 30000);
	set("max_jing", 12600);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali",260);
	set("combat_exp", 6000000);
	set("score", 10000);
set_skill("ruying-leg", 360);
		set_skill("zhanzhuang-gong", 360);
	set_skill("shaolin-cuff", 360);
	set_skill("shaolin-leg", 360);
	set_skill("yiwei-dujiang", 360);
	set_skill("boluomi-hand", 360);
	set_skill("jingang-strike", 360);
	set_skill("wuxiang-finger", 360);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 260);
	set_skill("yijinjing", 260);
	set_skill("force", 260);
	set_skill("yijinjing", 260);
	set_skill("dodge", 260);
	set_skill("shaolin-shenfa", 300);
	set_skill("cuff", 260);
	set_skill("hunyuan-yiqi", 300);
	set_skill("luohan-quan", 300);
	set_skill("jingang-quan", 300);
	set_skill("leg", 260);
	set_skill("zui-gun", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("hand", 260);
	set_skill("fengyun-shou", 300);
	set_skill("qianye-shou", 300);
	set_skill("strike", 260);
	set_skill("sanhua-zhang", 300);
	set_skill("sanhua-zhang", 300);
	set_skill("weituo-gun", 300);
	set_skill("banruo-zhang", 300);
	set_skill("finger", 260);
	set_skill("yizhi-chan", 300);
	set_skill("yizhi-chan", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("yizhi-chan", 300);
	set_skill("claw", 260);
	set_skill("qianye-shou", 300);
	set_skill("yingzhua-gong", 300);
	set_skill("longzhua-gong", 300);
	set_skill("staff", 260);
	set_skill("pudu-zhang", 300);
	set_skill("wuchang-zhang", 300);
	set_skill("blade", 260);
	set_skill("cibei-dao", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("club", 260);
	set_skill("zui-gun", 300);
	set_skill("zui-gun", 300);
	set_skill("sword", 260);
	set_skill("damo-jian", 300);
	set_skill("whip", 260);
set_skill("hunyuan-yiqi", 260);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("leg", "nianhua-zhi");

	map_skill("strike", "banruo-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
	map_skill("staff", "wuchang-zhang");
	map_skill("blade", "xiuluo-dao");
	map_skill("club", "zui-gun");
	map_skill("parry", "wuxiang-finger");
  map_skill("parry","wuxiang-finger");
  map_skill("unarmed","wuxiang-finger");
  map_skill("finger","wuxiang-finger");
  map_skill("hand","boluomi-hand");
  map_skill("strike","jingang-strike");
	//prepare_skill("finger", "wuxiang-finger");
	prepare_skill("hand", "boluomi-hand");
	prepare_skill("strike", "jingang-strike");

//set_skill("hellfire-whip", 360);
set_skill("buddha-club", 380);
//set_skill("lunhui-zhang", 320);
set_skill("zhanzhuang-gong", 320);
set_skill("buddhism", 350);
	map_skill("club", "buddha-club");
	//map_skill("whip", "hellfire-whip");
	//map_skill("staff", "lunhui-zhang");
		map_skill("force", "zhanzhuang-gong");
		
	map_skill("dodge", "shaolin-shenfa");
  map_skill("parry","ruying-leg");
  map_skill("unarmed","ruying-leg");
  map_skill("leg","ruying-leg");
	prepare_skill("leg", "ruying-leg");
       
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		
(: perform_action, "club.baifo" :),
(: perform_action, "club.fantian" :),
(: perform_action, "club.pili" :),
(: perform_action, "club.qiankun" :),
(: perform_action, "club.wu" :),
		 (: perform_action, "leg.ruying" :),
		(: exert_function, "powerup" :),
		(: exert_function, "lianhua" :),	
		(: exert_function, "bighammer" :),	
		(: exert_function, "pudu" :),										
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);

	set("inquiry",([
		"木人巷" : (: ask_murenxiang :),
	]));


	create_family("南少林派", 18, "达摩院首座");
	setup();
		carry_object(__DIR__"obj/gclub")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_yes", "yes");
	add_action("do_nod", "nod");
}

string ask_murenxiang()
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";
	if (me->query("muren_winner") && !wizardp(me)) 
		return RANK_D->query_respect(me) + "不是已经闯过木人巷了么，可不要拿老衲开这等玩笑。";
	if (me->query("combat_exp", 1) < 10000)
		return RANK_D->query_respect(me) + "的功力不够，还是不要进木人巷为好！";
//	if (me->query("score") < 10000)
//	        return RANK_D->query_respect(me) + "阅历不够，还是不要进木人巷为好！"; 
	command("look " + this_player()->query("id"));
	command("nod");
	me->set_temp("ask_muren", 1);
	say(HIC"天镜大师沉声说道：木人巷乃我少林最为凶险的去处之一，其中遍布手持利器的木人，\n闯阵者只能向前走，并无返回之路，且在一处不要停留太长时间。\n"NOR);
	return "你如决心已定，就告诉我(yes)！\n";
}

int do_yes()
{
	object me = this_player();

	if( !me->query_temp("ask_muren") ) return 0;
	message_vision("$n转身奋力推开身后的佛像，后面露出一个小门，\n\n$n伸出手在$N后背一推，将$N推进门内！\n\n$n迅速将佛像推回原位。\n\n", me, this_object());
	me->move("/d/nanshaolin/entrance");
	me->look();
	return 1;
}

