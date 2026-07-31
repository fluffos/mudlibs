#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"壮汉",	"id":"han",		"mw":1,	]),
(["name":"老流氓",	"id":"liumang",	"mw":-1,	]),
(["name":"捕快",	"id":"bu kuai",	"mw":1,	"weapon":"gangdao",	]),
(["name":"流串犯",	"id":"fan",		"mw":-1,	"weapon":"gangdao",	]),
(["name":"武僧",	"id":"seng",		"mw":1,	"weapon":"changqiang",	]),
(["name":"恶头陀",	"id":"toutuo",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"侠客",	"id":"xiake",		"mw":1,	"weapon":"gangjian",	]),
(["name":"强盗",	"id":"qiang dao",	"mw":-1,	"weapon":"lianzi",]),
(["name":"壮士",	"id":"shi",		"mw":1,	]),
(["name":"恶汉",	"id":"ehan",		"mw":-1,	]),
(["name":"壮丁",	"id":"ding",		"mw":1,	]),
(["name":"凶汉",	"id":"han",		"mw":-1,	]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(HIG+npc["name"]+NOR,({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",25000+random(25000));
	set_temp("apply/attack",60);
	set_temp("apply/defense",60);
	set_temp("apply/armor",40);
	set("max_neili",800);
	if( weapon)	set_skill("blade",200);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("parry",40);
	set_skill("dodge",40);
	set("shen_type",npc["mw"]);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if( weapon)
		carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",10+random(10));
}
       
