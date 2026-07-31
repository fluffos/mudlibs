// jiading.c
inherit NPC;

void create()
{
        set_name("家丁", ({
                "jia ding",
                "ding",
        }));
        set("long",
                "他是一位身着青衣的梅庄家丁，衣服的袖口上绣着一朵梅花。\n"
                "手中拿着一对判官笔，似乎有一身武艺。\n"
        );

        set("gender", "男性");
        //set("attitude", "aggressive");
        set("class", "fighter");

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 500);
        set("pursuer", 1);
        set("combat_exp", 200000);
        set("score", 1);

set_skill("painting", 320);
        set_skill("force", 120);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("dagger", 200);
        set_skill("shigu-bifa", 340);
        set_skill("literate", 130);
set_skill("jiangjun-zhang",300);
set_skill("kuihua-xinfa", 200);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "shigu-bifa");
        map_skill("dagger", "shigu-bifa");

create_family("梅庄", 3, "弟子");
        setup();

        carry_object(__DIR__"obj/panguan-bi")->wield();
        carry_object(__DIR__"obj/qingyi")->wield();
}

