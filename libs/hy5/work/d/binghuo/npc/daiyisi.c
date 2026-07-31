// daiyisi.c
// Last Modified by winder on Oct. 30 2001

#include "ansi.h";
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
string ask_fan();
int ask_yy();
int ask_mj();

void create()
{
	set_name("黛绮丝", ({"dai yisi", "dai", "yisi", }));
	set("long",
"黛绮丝站在窗前眼望大海，听到你进来却不回头。只见她背影曼
妙，秀发飘拂，后颊肤若白玉，荣光照人，端丽难言。谢逊说她
当年乃武林中第一美人，此言当真不虚，遥想光明顶上，碧水潭
边，紫衣如花，长剑胜雪，不知倾倒了多少英雄豪杰。\n");

	set("nickname", HIM "紫衫龙王" NOR);
	set("gender", "女性");
	set("attitude", "peaceful");

	set("age", 33);
	set("shen_type", 1);
	set("fan",2);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 23500);
	set("max_jing", 21500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);

	set("combat_exp", 1900000);
	set("score", 800000);

	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("throwing", 250);
	set_skill("parry", 140);
	set_skill("sword", 140);
	set_skill("cuff", 140);
	set_skill("hand", 140);
	set_skill("jiuyang-shengong", 360);
	set_skill("qingfu-shenfa", 340);
	set_skill("changquan", 340);
	set_skill("liehuo-jian", 340);
	set_skill("duoming-jinhua", 350);
	set_skill("literate", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("throwing", "duoming-jinhua");
	map_skill("parry", "changquan");
	map_skill("sword", "liehuo-jian");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.lianhuan" :),
        }) );
	set("inquiry", ([
		"谢逊"   : (: ask_fan :),
		"屠龙刀" : (: ask_fan :),
		"冰火岛" : (: ask_fan :),
              "明教" : (: ask_mj :),
             "银叶先生" : (: ask_yy :),
             "屠龙刀" : "等我拿到屠龙刀再去找灭绝老尼算帐!\n",
	]) );
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform duo") :),
	}) );
	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIW"护教法王"NOR);
	create_family("明教", 34, "弟子");
	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		this_player()->start_busy(2);
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_fan()
{
	mapping fam;
	object *allob,env,ob,me=this_player();
	string *sname;
	int i, count, here = 0;

 if (query("fan")<=0)
 return "帆布已经用完了。";

	add("fan",-1);
	ob = new("/d/binghuo/obj/fan");
	ob->move(me);
	message_vision("$N获得一面帆布。\n",me);

	return "好吧，海上艰险，给你一块帆布，你自己去找谢三哥吧。";

}



int ask_mj()
{
        message_vision("黛绮丝似在梦呓一般道:都是过去的事了,还提他做甚!
突然回过头来厉声问$N道:你究竟是谁,到底来干什么的?\n",this_player());
        return 1;
}

int ask_yy()
{
       message_vision("黛绮丝凄然道:他,他死得好冤哪!都是胡青牛这狗贼害的,我不会放过他的,
忽又凄然道:明教，明教，原来还不过是为了明教!\n",this_player());
       return 1;
}
#include "fawang.h"
