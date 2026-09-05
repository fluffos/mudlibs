//Cracked by Roath
// Npc:
// Date:
// kane, 28/9/97
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("贾老六", ({
		"jia laoliu",
		"laoliu",
		"jia",
	}));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("long",
		"他头顶头秃秃地，一根小辫子上没剩下几根头发，脸上有个大刀疤。\n"
		+ "当年在扬州之时，曾大骂盐枭，骂他们不敢杀官造反，只会走私漏\n"
		+ "税，做没胆子的小生意，结果得罪了青龙帮，遭人追杀，茅十八也\n"
		+ "因此和青龙帮结仇。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 30000);
	set("score", 10);


	set_skill("hand", 70);
	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("yunlong-shou", 60);
	set_skill("yunlong-shenfa", 60);
	map_skill("hand", "yunlong-shou");
	map_skill("dodge", "yunlong-shenfa");
	create_family("天地会", 5, "会众");
	prepare_skill("hand", "yunlong-shou");

        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
                "反清复明" : "去棺材店和天桥仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",

       ]) );
	set("chat_chance", 3);
	set("chat_msg", ({
	"贾老六忽然说：扬州盐贩子真可恶。\n",
        "贾老六突然说道: 忠义堂前兄弟在，城中点将百万兵。\n",
        (:random_move:),
	}));
	setup();

      carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

