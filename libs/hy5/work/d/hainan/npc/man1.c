#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"行人",	"id":"xing ren",	"mw":1,	]),
(["name":"商人",	"id":"shang ren",	"mw":-1,	]),
(["name":"旅客",	"id":"lv ke",		"mw":1,	]),
(["name":"门人",	"id":"men ren",	"mw":1,	]),
(["name":"学徒",	"id":"xue tu",	"mw":1,	]),
(["name":"无赖汉",	"id":"wu lai",	"mw":-1,	]),
(["name":"浪人",	"id":"lang ren",	"mw":-1,	]),
(["name":"行者",	"id":"xing she",	"mw":1,	]),
(["name":"亡命徒",	"id":"tu",		"mw":-1,	]),
(["name":"客商",	"id":"ke shang",	"mw":-1,	]),
(["name":"小侍",	"id":"xiao shi",	"mw":1,	]),
(["name":"老色鬼",	"id":"se gui",	"mw":-1,	]),
(["name":"青年",	"id":"qing nian",	"mw":1,	]),
(["name":"年轻人",	"id":"nian qing",	"mw":1,	]),
});


void create()
{
	mapping npc;
	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	if( random(10)<5)	set("gender","男性");
	else set("gender","女性");
	set("age",20+random(30));
	set("combat_exp",55000+random(555000));
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
	set_skill("unarmed",230);
	set_skill("parry",230);
	set_skill("dodge",230);
	set("shen_type",npc["mw"]);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5+random(5));
}
       
