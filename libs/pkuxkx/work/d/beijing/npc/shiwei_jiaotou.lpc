// Npc: shiwei jiaotou

inherit NPC;
string ask_for_toujun();
int auto_kill(object player);
void create()
{
	set_name("侍卫教头", ({"shiwei jiaotou", "jiaotou", }));
	set("long",
	"这是京城侍卫的总教头，听说他原来曾在丐帮混，\n"
	"后来不知怎么的就来了京城，打败了三十六名禁军侍卫，\n"
	"多总管就让他当了个教头。\n");

	set("gender", "男性");
	set("attitude", "heroism");
	set("class","officer");

	set("age", 39);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 300000);
	set("score", 100);


	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("cuff", 120);
	set_skill("strike",120);
	set_skill("finger", 120);
	set_skill("claw",120);
	set_skill("hand", 120);
	set_skill("sword",120);
	set_skill("blade",120);
	set_skill("staff",120);

    set_skill("xuantian-wuji", 120);
    set_skill("kunlun-shenfa", 120);
    set_skill("qingmang-jian", 120);
    set_skill("kunlun-zhang", 120);
    set_skill("liuhe-dao", 120);

    map_skill("force", "xuantian-wuji");
    map_skill("sword", "qingmang-jian");
    map_skill("blade", "liuhe-dao");
    map_skill("dodge", "kunlun-shenfa");
    map_skill("strike", "kunlun-zhang");
    map_skill("parry", "kunlun-zhang");
    prepare_skill("strike", "kunlun-zhang");
	set("inquiry", ([
                "投军" :(:ask_for_toujun:),
                "入伍" :(:ask_for_toujun:),
	     ]) );

	set("shen_type",1);set("score",500);setup();

	carry_object(__DIR__"obj/shiweicloth")->wear();
}
void init ()
{
    auto_kill(this_player());
}
string ask_for_toujun()
{
  	object me ,ob;
  	me = this_player();

 	if (!me->query_condition("bjkiller"))
 	{
                command("say 请进！");
 		me->set_temp("chaoting/toujun",1);
                return "大清正需要壮士这样的人才，快去吧。";
	}
	else return "大胆！居然自投罗网！";

}
#include "/d/beijing/autok.h"
