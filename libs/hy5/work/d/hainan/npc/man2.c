#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"×³ºº",	"id":"han",		"mw":1,	]),
(["name":"ÀÏÁ÷Ã¥",	"id":"liumang",	"mw":-1,	]),
(["name":"²¶¿ì",	"id":"bu kuai",	"mw":1,	"weapon":"blade",	]),
(["name":"Á÷´®·¸",	"id":"fan",		"mw":-1,	"weapon":"blade",	]),
(["name":"ÎäÉ®",	"id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"¶ñÍ·ÍÓ",	"id":"toutuo",	"mw":-1,	"weapon":"blade",	]),
(["name":"ÏÀ¿Í",	"id":"xiake",		"mw":1,	"weapon":"sword",	]),
(["name":"Ç¿µÁ",	"id":"qiang dao",	"mw":-1,	"weapon":"throwing",]),
(["name":"×³Ê¿",	"id":"shi",		"mw":1,	]),
(["name":"¶ñºº",	"id":"ehan",		"mw":-1,	]),
(["name":"×³¶¡",	"id":"ding",		"mw":1,	]),
(["name":"Ð×ºº",	"id":"han",		"mw":-1,	]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",25000+random(25000));
	set_temp("apply/attack",60);
	set_temp("apply/defense",60);
	set_temp("apply/armor",40);
	set("max_force",800);
	if( weapon)	set_skill(weapon,40);
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("dodge",40);
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
	add_money("silver",10+random(10));
}
       
