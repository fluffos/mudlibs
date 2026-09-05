#include "setdizi.h"

void create()
{
        setcreate(120);
        add("long", "正在此处巡逻。\n看起来其人武功高出普通弟子不少，被掌门人派到牙山，抗击东瀛侵略者。\n");
	add("inquiry", ([
		"here" : "掌门人派出弟子来牙山，就是为了打鬼子！",
		"rumors" : "日军的军舰和我军所差无几，只要大家齐心协力，打败日军轻而易举。",
		"牙山" : "掌门人派出弟子来牙山，就是为了打鬼子！",
		"日本" : "武林中人一致对外全力抗敌，日本鬼子迟早得灭亡！",
		"鬼子" : "武林中人一致对外全力抗敌，日本鬼子迟早得灭亡！",
	]));
	set("chat_chance", 4);
	set("chat_msg", ({
		(: command("killair") :),
		this_object()->query("name")+"正在练习雪山剑法。\n",
		this_object()->query("name")+"正在练习雪山剑法。\n",
		(: command("sing2") :),
		this_object()->query("name")+"警惕的四处张望，看是不是有日本鬼子潜入。\n",
	}));
	setfamily(7);
    set("random_npc",1);
        setup();
        setequip();
}

void init()
{
        setinit();
        ::init();
}

void attempt_apprentice(object ob)
{
	setapp(ob);
}