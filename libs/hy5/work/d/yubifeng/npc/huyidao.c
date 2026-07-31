// huyidao.c
#include <ansi.h>
inherit NPC;
string ask_book();

void create()
{
	set_name("胡一刀", ({"hu yidao", "hu", "yidao"}));
	set("gender", "男性");
	set("nickname", "辽东大侠");
	set("age", 35);
	set("long","这人生得当真凶恶，一张黑漆脸皮，满腮浓髯，头发却又不结辫子，蓬蓬松松的堆在头上。他生平只要遇到做坏事的，立时一刀杀了，所以名字叫作胡一刀。\n");
	set("attitude", "peaceful");
        set("no_get", "1");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 17);
	
	set("qi", 13000);
	set("max_qi", 13000);
	set("jing", 11000);
	set("max_jing", 11000);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 100);
	set("combat_exp", 590000);
	set("score", 20000);
	 
	set_skill("force", 110);             // 基本内功
	set_skill("hujia-daofa", 350);       // 胡家刀法	
	set_skill("blade", 120);             // 基本刀法
	set_skill("hunyuan-yiqi", 120);      // 混元一气功
	set_skill("dodge", 120);             // 基本躲闪
	set_skill("shaolin-shenfa", 320);    // 胡家身法
	set_skill("parry", 120);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	set("book_count",1);
	setup();
	carry_object("/clone/misc/cloth")->wear();

}

