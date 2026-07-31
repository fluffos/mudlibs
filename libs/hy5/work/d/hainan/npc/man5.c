#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"明教帮众",	"id":"bang",		"mw":1,	]),
(["name":"日月邪教徒",	"id":"tu",		"mw":-1,	]),
(["name":"天地会帮众",	"id":"bang",		"mw":1,	"weapon":"blade",	]),
(["name":"丐帮弟子",	"id":"dizi",		"mw":1,	"weapon":"club",	]),
(["name":"天下会帮众",	"id":"bang",		"mw":1,	"weapon":"blade",	]),
(["name":"星宿弟子",	"id":"dizi",		"mw":-1,	"weapon":"blade",	]),
(["name":"御前侍卫",	"id":"shiwei",	"mw":1,	"weapon":"sword",	]),
(["name":"武当派弃徒",	"id":"dizi",		"mw":-1,	"weapon":"sword",]),
(["name":"华山派弃徒",	"id":"dizi",		"mw":-1,	"weapon":"sword",	]),
(["name":"灵鹫宫使者",	"id":"shizhe",	"mw":-1,	"weapon":"whip",]),
(["name":"灵蛇岛使者",	"id":"shizhe",	"mw":-1,	"weapon":"blade",	]),
(["name":"明教接引使",	"id":"shi",		"mw":1,	"weapon":"hammer",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",500000+random(500000));
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",80);
	set("max_force",1500);
	if( weapon)	set_skill(weapon,150);
	set_skill("unarmed",150);
	set_skill("parry",150);
	set_skill("dodge",150);
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
	add_money("silver",40+random(40));
}
       
