#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"星宿元老",	"id":"yuanlao",	"mw":-1,	]),
(["name":"日月教长老",	"id":"zhanglao",	"mw":1,	]),
(["name":"灵蛇岛岛主",	"id":"daozhu",	"mw":-1,	"weapon":"blade",	]),
(["name":"丐帮长老",	"id":"zhanglao",	"mw":1,	"weapon":"club",	]),
(["name":"天下会会长",	"id":"huizhang",	"mw":1,	"weapon":"blade",	]),
(["name":"嵩山派隐者",	"id":"yinzhe",	"mw":-1,	"weapon":"sword",	]),
(["name":"御前侍卫长",	"id":"zhang",		"mw":1,	"weapon":"sword",	]),
(["name":"少林禅师",	"id":"chanshi",	"mw":1,	"weapon":"blade",]),
(["name":"灵鹫宫长老",	"id":"zhanglao",	"mw":-1,	"weapon":"whip",	]),
(["name":"山大王",		"id":"daiwang",	"mw":-1,	"weapon":"throwing",]),
(["name":"黑社会老大",	"id":"laoda",		"mw":-1,	"weapon":"hammer",	]),
(["name":"无量山掌门",	"id":"zhangmen",	"mw":1,	"weapon":"sword",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",1000000+random(5000000));
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",90);
	set("max_force",2000);
	if( weapon)	set_skill(weapon,200);
	set_skill("unarmed",200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
        set("chat_chance", 20);
        set("chat_msg", ({
 (: random_move :)

        }) );
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	
	set("shen_type",npc["mw"]);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	if( weapon)
		carry_object(__DIR__"weapon/"+weapon)->wield();
	add_money("silver",50+random(50));
}
       
