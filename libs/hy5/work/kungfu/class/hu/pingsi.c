#include <ansi.h>

inherit NPC;


int ask_job();
int ask_fail();
mixed ask_me();

void create()
{
        set_name("平四", ({ "ping si", "ping", "si" }));
        set("gender", "男性");
        set("age", 65);
        set("title", "胡家仆佣");
        set("long", "他是胡家忠心耿耿的仆役。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 4000);
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
        	"阎基"   : "阎基…哼…这个狗贼。",
                "胡一刀" : "那……那是老主人，唉。",
                "苗人凤" : "苗大侠可不是坏人。",
                "赵半山" : "他对我家主人的交情那是没得说的。",
        ]));
        set("coagents", ({
                ([ "startroom" : "/d/guanwai/xiaowu",
                   "id"        : "hu fei" ]),
        }));

        setup();
        set("startroom", "/d/guanwai/xiaoyuan");
        carry_object("/clone/cloth/cloth")->wear();
}

