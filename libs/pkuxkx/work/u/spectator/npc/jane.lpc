// jane.c

#include <ansi.h>

inherit NPC;

void create()
{
    set_name("阿霞",({ "jane" }) );
    set("gender", "女性");
    set("title",RED "天龙寺" NOR + HIY "特使" NOR);
    set("long", "她是一个身着白衣的妙龄女子，长发飘飘，身态娥娜。\n");
    set("age", 18);
    set("combat_exp", 3000000);

    set("per", 30);
    set("kar", 30);
    set("str", 15);
    set("dex", 15);
    set("con", 20);
    set("int", 30);

    set_skill("force", 300);
    set_skill("dodge", 300);
    set_skill("finger", 300);
    set_skill("parry", 300);
    set_skill("liumai-shenjian", 300);
    set_skill("literate", 300);
    set_skill("yiyangzhi", 300);
    set_skill("beiming-shengong", 300);
    set_skill("lingbo-weibu", 300);

    map_skill("finger", "liumai-shenjian");
    map_skill("force", "beiming-shengong");
    map_skill("dodge","lingbo-weibu");
    map_skill("parry", "liumai-shenjian");
    prepare_skill("finger","liumai-shenjian");
    prepare_skill("dodge","lingbo-weibu");
    create_family("天龙寺", 2, "俗家弟子");
    setup();
    carry_object("/d/gumu/obj/white")->wear();
}

void init()
{
    object ob;
    ob=this_player();

    message_vision("欢迎来到百花谷。\n",ob);
    ::init();
}
