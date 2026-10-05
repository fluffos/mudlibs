inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
        set_name("文学教官", ({ "literate master", "master" }));
        set("long",
"他是凤凰军校的教官，专门教学习能力的。\n");
        set("gender", "男性");
        set("age", 35);
        set("no_get", 1);
        set_skill("literate", 120);
        set("combat_exp", 200000);
        set("shen_type", 1);
        setup();

}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("xmark/学员"))
                return 0;
        ob->add_temp("xmark/学员", 0);
        return 1;
}


