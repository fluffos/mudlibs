#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"关东大汉",	"id":"han",		"mw":1,	]),
(["name":"关西强人",	"id":"ren",	"mw":-1,	]),
(["name":"巡捕头领",	"id":"touling",	"mw":1,	"weapon":"blade",	]),
(["name":"蒙面强盗",	"id":"qiangdao",	"mw":-1,	"weapon":"blade",	]),
(["name":"修行僧",		"id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"铁头陀",		"id":"toutuo",	"mw":-1,	"weapon":"blade",	]),
(["name":"锦衣卫",		"id":"wei",		"mw":-1,	"weapon":"sword",	]),
(["name":"东厂侍卫",	"id":"shiwei",	"mw":-1,	"weapon":"whip",]),
(["name":"云游道士",	"id":"daoshi",	"mw":1,	"weapon":"sword",	]),
(["name":"淫道",		"id":"dao",		"mw":-1,	"weapon":"sword",]),
(["name":"带刀武官",	"id":"guan",		"mw":1,	"weapon":"blade",	]),
(["name":"山贼头",		"id":"dou",		"mw":-1,	"weapon":"hammer",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(HIY+npc["name"]+NOR,({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",250000+random(250000));
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",60);
	set("max_force",1200);
	if( weapon)	set_skill(weapon,100);
	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);
	set("shen_type",npc["mw"]);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
	carry_object("/clone/cloth/cloth")->wear();
	if( weapon)
//		carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",30+random(30));
}
       
