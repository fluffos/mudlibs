// chuniang.c



inherit NPC;
inherit F_DEALER;
#include <chaocai.h>

void create()
{
	set_name("厨娘", ({"chu niang", "chu", "niang"}));
	set("long", "她是一个看上去普普通通的厨娘，常年累月的在厨房烧菜作饭，一双"
			"粗糙的大手，油腻的围裙，貌不惊人，可是她做的饭菜深得却是川中"
			"一绝，为人似乎十分傲慢，看来不是一般的人物。" );
	set("gender", "女性");
	set("age", 35);
	set("no_get", 1);
	set("attitude", "friendly");

	set("inquiry",([
		"工作" : (: ask_job :),
	]));

	set("age", 30);

	set("str", 21);
	set("skill_chuniang", 1);
	set("max_exp", 2500000);//炒菜经验上限
	set("int", 22);
	set("con", 30);
	set("dex", 21);

	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 50);
	set_skill("cooking", 200);
	set_skill("chuancai-jiyi", 200);
	set_skill("unarmed", 50);

	set("vendor_goods", ({
		"/clone/misc/cailiao",
	}));

	setup();
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

