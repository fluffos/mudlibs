inherit NPC;
mixed ask_me();
void create()
{
	set_name("圆心和尚", ({
		"yuanxin heshang",
		"yuanxin",
		"monk",
	}));
	set("long",
		"他是一位身材魁梧的武僧，身穿一袭黄布袈裟。\n"
		"似乎武功基础扎实。\n"
	);
	set("nickname", "罗汉堂护寺武僧");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("place","/d/shaolin/wstang2");
	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 250000);
	set_skill("force", 100);
	set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	set("inquiry", ([
		"武技"     : (: ask_me :)
	]));
	set("unique", 1);
	create_family("少林派", 41, "弟子");
	setup();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

#include "/kungfu/class/shaolin/wuseng.h"
