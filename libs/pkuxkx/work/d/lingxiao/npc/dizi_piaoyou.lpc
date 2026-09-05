#include "setdizi.h"

void create()
{
        setcreate(55);
        add("long", "正在看戏。\n");
	add("inquiry", ([
		"here" : "这里是戏台，我们大家都很喜欢在这里看戏(watch)呢。",
		"戏台" : "这里是戏台，我们大家都很喜欢在这里看戏(watch)呢。",
		"看戏" : "你要看戏，输入watch就可以。",
		"戏子" : "哈哈！那都是我的师兄弟！",
		"鬼子" : "鬼子就是鬼子，白老爷子前几天还派出了几个武功高强的师兄下山去牙山打鬼子。",
		"日本人" : "那不是人，那是鬼子。",
		"表演" : "怎么样？还精彩么？",
		"精彩" : "精彩的还在后面呢！打鬼子！",
		"打鬼子" : "你要是武功够高，就去跟白老爷子说，去打鬼子！",
	]));
	set("chat_chance", 14);
	set("chat_msg", ({
		(: command("good") :),
		(: command("great") :),
		(: command("zeze") :),
		(: command("end") :),
		(: command("baixing") :),
		(: command("baowei") :),
		(: command("boat") :),
		(: command("linger") :),
		(: command("trillx") :),
		(: command("sing2fy") :),
		(: command("sing2") :),
		(: command("lama") :),
		(: command("tongfy") :),
		(: command("sex") :),
		(: command("xiang") :),
		(: command("u&me2") :),
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