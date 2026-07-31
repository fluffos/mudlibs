
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("小痞子", ({ "pizi" }) );
        set("title", "痞子帮");
        set("gender", "男性" );
        set("age", 23);
        set("cor", 30);
        set("long",
                
"他是个在胡同里呆着的痞子，他们不敢惹官兵，武林中的人。\n"                              
                "但是他们经常欺负老百姓。\n");

        set("combat_exp", 3000);
        set("attitude", "friendly");
        set("max_force", 2000);   
        set("force", 2000);             
        set_skill("unarmed", 10);
        set_skill("parry", 30);
        set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/linen")->wear();
        add_money("gold", 1);
}

int accept_fight(object me)
{
        command("say 咦... 要打就真打吧，光是较量多没意思？");
        command("grin");
        kill_ob(me);
        return 1;
}

