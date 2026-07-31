// zhang.c 张三丰
#include <ansi.h>
inherit NPC;
void create()
{
    object ob;
        set_name("小张三丰", ({ "zhang sanfeng", "zhang", "sanfeng" }));
        set("nickname", "邋遢真人");
        set("title",HIW"武当派开山祖师"NOR);
        set("long", 
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的白色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000); 
        set("unique", 1);

        set_skill("force", 100);
        set_skill("yinyun-ziqi", 100);
        set_skill("dodge", 100);
        set_skill("tiyunzong", 100);
        set_skill("cuff", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("taiji-jian", 100);
        set_skill("taoism", 100);
        set_skill("blade", 100);
        set_skill("literate", 100);
        set_skill("wudang-quan", 100);
        set_skill("xuanxu-daofa", 100);
        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        map_skill("blade", "xuanxu-daofa");
        prepare_skill("cuff", "taiji-quan");
        set("class", "taoist");

        setup();

        carry_object("/d/wudang/obj/white-robe")->wear();
        carry_object(__DIR__"obj/zwj")->wield();
        carry_object("/clone/medicine/rsg");
        carry_object("/clone/medicine/rsg");
        carry_object("/clone/medicine/rsg");
}
