// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
// last changed by bibi on 4,12 1998
// last changed for 去掉所有的busy，现在set_amount() (in /inherit/item/combined.c)   
// 已经改好，不必再有这些busy了
// modified to baituo master by jas 2003.2
// modified by iszt@pkuxkx, 2007-01-15, add ask_silver
// modified by iszt@pkuxkx, 2007-02-16, change to inherit banker

#include <ansi.h>

inherit F_MASTER;
inherit NPC;
inherit SILVER_NPC;
inherit BANKER;


void create()
{
    string name,*tmp,*pinying;
	name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));	
	set("long", "他是月记蒙古分号的老板。\n");
	set("title", HIG+"月记银号蒙古分号老板"+NOR);
	set("gender", "男性");
	set("age", random(20)+40);
	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
    set("random_npc",1);
	set("qi", 800); 
	set("max_qi", 800);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	this_object()->query("name")+"骄傲的说道：本银号已经有上百年的历史，在江南可以说是第一家。\n",
	this_object()->query("name")+"笑着说道：在本店存钱无利息，客官您看着办吧。\n",
	this_object()->query("name")+"哭丧着脸说道：巫师为了体谅玩家，连取钱手续费都不收了，让本店赔了一大笔。\n",
	this_object()->query("name")+"微微一笑，说道：本店还办理不同面额货币的兑换业务。\n",
	this_object()->query("name")+"微微一笑，说道：如果想一次性存入身上所有黄金，可以cun all gold，同样也可以cun all silver,coin等等。\n",
	}));

	
	set_skill("literate", 50);
	
	

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
    set("score",5000);
    setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	npc::init();
	banker::init();
}

