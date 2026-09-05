//97.11,23
//create bye hacky
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("赵志敬", ({
                "zhao zhijing",
                "zhao",
                "zhijing",
        }));
        set("long",
                "他就是全真教真人王处一的弟子赵志敬\n"
        );
        set("gender", "男性");
        set("title",HIB"全真派"NOR+GRN"道长"NOR);
        set("attitude", "friendly");
        set("class", "taoist");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 40);
        set("combat_exp", 15000);
        set("score", 100);
        set_skill("force", 60);
        set_skill("xiantian-gong", 50);
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 150);
        set_skill("sword", 60);
        set_skill("quanzhen-jian", 40);
        set_skill("parry", 50);
        set_skill("literate", 60);
        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("sword", "quanzhen-jian");
        map_skill("parry", "quanzhen-jian");
       
        
        create_family("全真派", 3, "弟子");
        setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/robe")->wear(); 
}
