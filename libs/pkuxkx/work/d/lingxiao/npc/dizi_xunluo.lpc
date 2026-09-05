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
        set("random_npc",1);
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

int accept_object(object who, object ob)
{
	object npc = this_object();
	if (ob->query("money_id"))
	{
		if (ob->value() >= 1000000)
		{
			command("nod");
			tell_object(who, HIG + npc->query("name")+ HIG"偷偷对你道：「去吧！城内会有兄弟为你开门的。」\n"NOR);
			who->set_temp("lingxiao_bribe_bridge", 1);
			return 1;
		}
		else
		{
			command("say 就这么点钱，打发叫化子么？");
			return 0;
		}
	}
	command("say 你无缘无故给我东西干什么？");
	return 0;
}