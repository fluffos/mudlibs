// liumang.c 流氓

inherit NPC;


//常用的npc名字
string *name_list = ({
	"女子",
	"老头子",
	// "小孩",
	"流氓",
	"乞丐",
	"巡抚",
	"官兵",
	"小贩",
	"壮年男子",
	"妇人",
	"老者",
	"岩田",
	"公府仆卫",
	"赶刀客",
	"江湖剑客",
	"江湖豪客",
	"慕杰",
	"地龙岛探子",
});

void create()
{
	string name;
	name = name_list[random(sizeof(name_list))];
	set_name(name, ({ "npc " + random(1000), "npc" }));

	set("gender", "男性");
	set("age",18 + random(30) );
	set("long", "这是" + name + "。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
