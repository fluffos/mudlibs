//Zine 艄公，长江边收钱的，钱多船就快

inherit NPC;
#include <ansi.h>
int intro();
void create()
{
        
        set_name("燕青", ({ "yan qing"}) );
        set("title", HIW+"浪子"+NOR);
        set("gender", "男性");
        set("age", 20+random(10));
        set("str", 20);
        set("dex", 20);
        set("long", "他就是传说中的浪子燕青。\n");
        set("combat_exp", 20000000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 1000);
        set_skill("force", 1000);
        set_skill("sword", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("neili", 20000); 
        set("max_neili", 20000);
        set("jiali", 1);

        set("shen_type",1);
        set("score",200);
        setup();
        call_out("intro",2);
       	carry_object("/clone/armor/cloth")->wear();
}

int intro()
{
    int i;
    object * all;
    all=all_inventory(environment(this_object()));
    command("say 你是小翘的好朋友吧，既然有缘我就传你武学的心法吧。");
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("yanqing"))
        {
            tell_object(all[i],"你掌握了燕青拳的心法。\n");
        }
    }
    call_out("goodbye",1);
    return 1;
}

int goodbye()
{
    command("wave");
    destruct(this_object());
    return 1;
}
