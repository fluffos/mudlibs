inherit NPC;
#include <ansi.h>

void create()
{
        set_name("王富贵", ({"wang fugui", "wang", "fugui"}));
        set("gender", "男性");
        set("age", 54);
        set_level(16);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 160);
	set_skill("parry", 160);
        set_skill("dodge", 160);
	create_family2("将军府","洛阳王家",4,"大总管");
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}
