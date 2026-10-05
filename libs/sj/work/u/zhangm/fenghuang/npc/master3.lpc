inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
        set_name("格斗技能教官", ({ "parry master", "master" }));
        set("long",
"他是凤凰军校的教官，专门教格斗技能的。\n");
        set("gender", "男性");
        set("age", 35);
        set("no_get", 1);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("force", 100);
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

