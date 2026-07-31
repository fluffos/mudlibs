#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"东北大汉",	"id":"han",		"mw":1,	]),
(["name":"瘪三",	"id":"biesan",	"mw":-1,	]),
(["name":"捕头",	"id":"bu tou",	"mw":1,	"weapon":"blade",	]),
(["name":"强人",	"id":"ren",		"mw":-1,	"weapon":"blade",	]),
(["name":"少林僧人","id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"少林恶僧","id":"seng",		"mw":-1,	"weapon":"club",	]),
(["name":"武士",	"id":"wushi",		"mw":1,	"weapon":"sword",	]),
(["name":"强盗头",	"id":"qiang dao",	"mw":-1,	"weapon":"hammer",]),
(["name":"云游僧",	"id":"seng",		"mw":1,	"weapon":"blade",	]),
(["name":"恶僧",	"id":"seng",		"mw":-1,	"weapon":"sword",]),
(["name":"带刀侍卫","id":"shiwei",	"mw":1,	"weapon":"blade",	]),
(["name":"山贼",	"id":"sanzei",	"mw":-1,	"weapon":"throwing",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",50000+random(50000));
	set_temp("apply/attack",90);
	set_temp("apply/defense",90);
	set_temp("apply/armor",50);
	set("max_force",1000);
	if( weapon)	set_skill(weapon,60);
	set_skill("unarmed",60);
	set_skill("parry",60);
	set_skill("dodge",60);
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	
        set("chat_chance", 20);
        set("chat_msg", ({
 (: random_move :)

        }) );		
	set("shen_type",npc["mw"]);
	setup();
	carry_object(__DIR__"weapon/cloth")->wear();
	if( weapon)
		carry_object(__DIR__"weapon/"+weapon)->wield();
	add_money("silver",20+random(20));
}
       
