#include "setdizi.h"

void create()
{
        setcreate(2);
        add("long", "正在专心练剑。\n");
	add("inquiry", ([
		"here" : "这里便是闻名天下的凌霄城了。",
		"练剑" : "本派剑法变化精微，要想练好非下一番苦功不可。",
	]));
	set("chat_chance", 14);
	set("chat_msg", ({
		(: command("exercise 100") :),
		this_object()->query("name")+"正在专心练习雪山剑法。\n",
		(: command("sweat") :),
		(: command("fight dizi 2") :),
		(: command("halt") :),
		(: command("wield sword") :),
		YEL"这凌霄城虽是苦寒，"+this_object()->query("name")+YEL"的额头仍由于专心练剑而渗出点点汗珠。\n"NOR,
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