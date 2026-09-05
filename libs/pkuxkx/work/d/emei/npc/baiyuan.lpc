//
//create bye cuer
inherit NPC;

int ask_bangzhu();

void create()
{
        set_name("白猿", ({
                "baiyuan",
                "yuan",
          }));
        set("long",
                "这是一头白猿。\n"
        );
        set("gender", "男性");
        set("attitude", "friendly");
        set("age", 24);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 40);
        set("combat_exp", 10000);
        set("score", 100);
        set_skill("force", 60);
        set_skill("linji-zhuang", 60);
        set_skill("dodge", 70);
        set_skill("zhutian", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("finger", 70);
        set_skill("parry", 60);
        set_skill("mahayana", 70);
        set_skill("literate", 60);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "tiangang-zhi");
        prepare_skill("finger", "tiangang-zhi");
        set("chat_chance",5);
        set("chat_msg", ({
             "白猿以企盼的眼光看着你。\n",
             "白猿急得抓耳挠腮。\n",
             "白猿拉着你的衣服，期待着你的帮助。\n",
                        }) );
        set("inquiry",([
              "帮助" : ( : ask_bangzhu : ),
                ]));

        setup();
}
   
int ask_bangzhu()
{
 object me = this_player();
 me->set_temp("tui",1);
 say("白猿虽然不能说话，但好象很有灵性。\n");
 say("白猿指着一块大石头大吼。\n");
 say("白猿想让你推（tui）这块石头。\n");
 return 1;
}
