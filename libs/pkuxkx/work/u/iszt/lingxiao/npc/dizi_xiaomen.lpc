#include "setdizi.h"

void create()
{
        setcreate(2);
        add("long", "正在此处练剑。\n");
	add("inquiry", ([
		"here" : "这里便是闻名天下的凌霄城了。在下奉命在此看守角门。",
	]));
	set("chat_chance", 14);
	set("chat_msg", ({
		this_object()->query("name")+"正在练习雪山剑法。\n",
		this_object()->query("name")+"正在练习雪山剑法。\n",
		(: command("think") :),
		this_object()->query("name")+"警惕的四处张望，防止奸邪之徒作恶。\n",
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