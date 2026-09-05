// zhike.c 知客

#include <ansi.h>

inherit NPC;

void heal();
string ask_lost();

mapping budbook=
	([
	"道德经「上卷」":"/d/wudang/obj/daodejing-i",
	"道德经「下卷」":"/d/wudang/obj/daodejing-ii",
	"阴符经":"/d/wudang/obj/taobook-1",
	"庄子·内篇「上卷」":"/d/wudang/obj/taobook-2",
	"庄子·内篇「下卷」":"/d/wudang/obj/taobook-3",
	"庄子·外篇「上卷」":"/d/wudang/obj/taobook-4",
	"庄子·外篇「下卷」":"/d/wudang/obj/taobook-5",
	"庄子·杂篇「上卷」":"/d/wudang/obj/taobook-6",
	"庄子·杂篇「下卷」":"/d/wudang/obj/taobook-7"]);
		
void create()
{
	set_name("知客道长", ({ "zhike daozhang", "zhike" }));
	set("long", 
		"他是武当山的知客道长。\n");
	set("gender", "男性");
	set("title", RED "武当派" NOR + GRN "道长" NOR);
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
		(: perform_action , "cuff.zhen" :)
        }) );
  set("inquiry", ([
    "借书" : "目前对武当弟子开放道教典籍外借手续，本处典籍皆可外借(jie)，每人限定一本。",
  	"遗失" : (: ask_lost :)
  	]));

	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 20);
	set_skill("taoism", 20);
	set_skill("taiji-shengong", 40);
	set_skill("cuff", 20);
	set_skill("taiji-quan", 30);

	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "taiji-quan");

	create_family("武当派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

//道教典籍遗失以后将降低门派评价，损失一定程度钱财
string ask_lost()
{
	mapping fam;
	object me;
	
	me=this_player();
	if (!(fam = me->query("family")) || fam["family_name"] != "武当派")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";
	else if(!me->query("family/book"))
		return "你没有从我这里外借图书，也无需进行遗失登记。";
	else if(member_array(me->query("family/book"), keys(budbook))==-1)
		return "我这里只提供道教典籍的遗失登记！";
	else if(me->query("score")<10)
		return "你先对门派做出更多贡献才能给予你图书的遗失登记。";
	else if(me->query("balance")<10000)
		return "遗失登记需要1两黄金的金钱补偿，你的存款不足以完成遗失登记。";
	
	me->add("score",-10);
	me->add("balance",-10000);
	me->delete("family/book");
	return "已经注销了你的图书租借记录，你可以继续外借佛经了！";
}

void init()
{
  add_action("do_jie", "jie");
}

//借道教典籍，武当弟子都可以借道教典籍
int do_jie(string arg)
{
	object me,book;
	mapping fam;
	
	me=this_player();
	if(!arg)
		return notify_fail("必须给出想借的道教典籍名字！\n");
	else if(me->query("family/book"))
		return notify_fail("你先还上图书才能再往外借！\n");
	else if (!(fam = me->query("family")) || fam["family_name"] != "武当派")
		return notify_fail(RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？");
	else if(member_array(arg, keys(budbook))==-1)
		return notify_fail("目前仅提供道教典籍：道德经、阴符经、庄子！\n");
	else if(me->query("combat_exp")<2000)
		return notify_fail("经验过2000点以后才能开通借书服务！\n");
	
	book=new(budbook[arg]);
	book->set("name",arg);
	me->set("family/book",arg);
	book->move(me);
	tell_room(environment(),query("name")+"递给你一本"+book->query("name")+"，并对你说：请注意保管，用完典籍及时归还，如有遗失请过来登记！\n");
	return 1;
}

int accept_object(object me, object ob)
{
	object tob=this_object();
	mapping fam;
	
	if (!(fam = me->query("family")) || fam["family_name"] != "武当派") {
		command("say "+RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？");
		return 0;
	}
	else if(!me->query("family/book")||member_array(me->query("family/book"), keys(budbook))==-1) {
		command("say 你没有从我这里外借过图书！");
		return 0;
	}
	else if(me->query("family/book")!=ob->query("name")) {
		command("say 你从我这里借走道教典籍："+me->query("family/book")+"和你给我的"+ob->query("name")+"似乎不符！");
		return 0;
	}
	else {
		message_vision("$N归还了借走的道教典籍「"+me->query("family/book")+"」。\n", me);
		me->delete("family/book");
		remove_call_out("destroying");
		call_out("destroying",1,ob);
		return 1;
	}
}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}

void destroying(object ob)
{
	destruct(ob);
	return;
}