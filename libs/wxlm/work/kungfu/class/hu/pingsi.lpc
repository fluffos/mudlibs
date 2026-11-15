// pingsi.c


inherit NPC;
inherit F_GUARDER;

void create()
{
    set_name("平老四", ({"ping si", "ping"}));
    set("gender", "男性");
    set("age", 65);
    set("long", "他是胡家忠心耿耿的仆役。\n");
    set("attitude", "peaceful");
    set("str", 20);
    set("int", 20);
    set("con", 24);
    set("dex", 20);

    set("qi", 4000);
    set("max_qi", 4000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3000);
    set("max_neili", 3000);
    set("combat_exp", 150000);

    set_skill("force", 40);
    set_skill("blade", 40);
    set_skill("dodge", 40);
    set_skill("parry", 40);
    set_skill("unarmed", 40);

    create_family("关外胡家", 0, "仆佣");

    set("inquiry",([
	"阎基":     "阎基... 这个狗贼。\n",
	"胡亿刀":   "那，那是老主人，唉！\n",
	"苗仁凤":   "苗大侠可不是坏人。\n",
	"赵开山":   "他对我家主人的交情那是没得说的。 \n",
    ]));

    set("coagents", ({
	    ([ "startroom" : "/d/guanwai/xiaowu",
	       "id"	: "hu fei" ]),
    }));

    setup();

    set("title", "胡家仆佣");
    carry_object("/clone/cloth/cloth")->wear();
}
