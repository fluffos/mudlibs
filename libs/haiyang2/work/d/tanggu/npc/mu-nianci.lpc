// mu nianci.c 穆念慈
// By tangfeng 2004

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("穆念慈",({"mu nianci", "mu", "nianci"}));
	set("long", "这位姑娘虽然穿着朴素，但秀丽之质难以掩却。\n");
	set("age", 25);
	set("attitude", "friendly");
	set("shen", 0);
	set("per", 30);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("no_get", 1);
	set("no_bark", 1);
	set("job_npc", 1);
	set("no_ansuan", 1);

	set("max_qi", 14500);
	set("max_jing", 13200);
	set("eff_jingli", 13500);
	set("jiali", 200);
	set("combat_exp", 5500000); 
	set("unique", 1);
	set("no_clean_up",1);//考虑ing

	set_skill("dodge",320);
	set_skill("force", 320);
	set_skill("literate", 300);
	set_skill("strike", 320);
	set_skill("tiezhang-zhangfa", 320);
	set_skill("shuishangpiao", 320);
	set_skill("shenzhao-jing", 320);
	set_skill("parry", 320);
	//set_skill("medicine", 380);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "shuishangpiao");
	map_skill("parry", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	set("inquiry", ([
		"郭靖"	:	"郭大侠现在应该还在襄阳，镇守边境。",
		"杨康":	    "...............................冤孽！",
	]));

	setup();
	carry_object("/d/city/npc/obj/pink_cloth")->wear();
	carry_object(__DIR__"shoe")->wear();

}
