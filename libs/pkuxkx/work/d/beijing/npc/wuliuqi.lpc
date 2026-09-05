// wuliuqi.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("吴六奇", ({"wu liuqi", "wu","liuqi"}));
	set("title", HIR"天地会"HIY"洪顺堂"MAG"香主"NOR);
	set("nickname", "铁丐");
	set("gender", "男性");
	set("age", 50);
	set("long",
		"这个老叫化，便是天下闻名的“铁丐”吴六奇，向来嫉恶如仇。\n"
		"他在官居广东提督之时，手握一省重兵，受了查伊璜的劝导，\n"
		"心存反清复明之志，暗入天地会，任职洪顺堂香主。\n"
	);

	set("attitude", "peaceful");

	set("str", 34);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);

	set("shen_type", 1);
	set("combat_exp", 1500000);

	set_skill("force", 195);			// 基本内功
	set_skill("huntian-qigong", 190);	// 混天气功
	set_skill("strike", 190);		// 基本拳脚
	set_skill("xianglong-zhang", 185);	// 降龙十八掌
	set_skill("dodge", 190);			// 基本躲闪
	set_skill("xiaoyaoyou", 195);		// 逍遥游
	set_skill("parry", 185);			// 基本招架
	set_skill("begging", 150);		// 叫化绝活
	set_skill("checking", 150);		// 道听途说

	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");

	prepare_skill("strike", "xianglong-zhang");

	create_family("天地会", 2, "弟子");

	set("chat_chance", 3);
	set("chat_msg", ({
	"吴六奇忽然放开喉咙唱起曲来：“走江边，满腔愤恨向谁言？。。。。\n"
	"。。。。。。寒涛东卷，万事付空烟。精魂显大招，声逐海天远。\n",
        "吴六奇突然说道: 松柏二枝分左右，中节洪华结义亭。\n",
        "吴六奇突然说道: 福德祠前来誓愿，反清复明我洪英。\n",
	}));
        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武功。\n",
                "反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
