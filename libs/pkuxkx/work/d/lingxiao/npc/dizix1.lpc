#include "setdizi.h"

void create()
{
        setcreate(55);
        add("long", "正在此处巡逻。\n");
	add("inquiry", ([
		"here" : "这里便是闻名天下的凌霄城了。",
		"巡逻" : "本人奉命在这附近巡逻，防止奸邪之徒作恶。",
	]));
	set("chat_chance", 14);
	set("chat_msg", ({
		(: random_move :),
		this_object()->query("name")+"正在练习雪山剑法。\n",
		this_object()->query("name")+"正在练习雪山剑法。\n",
		(: command("haha") :),
		this_object()->query("name")+"警惕的四处巡逻，防止奸邪之徒作恶。\n",
	}));
        setfamily(7);
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