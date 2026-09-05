//Zine 艄公，长江边收钱的，钱多船就快

inherit NPC;
#include <ansi.h>
int intro();
void create()
{
        
        set_name("李师师", ({ "li shishi"}) );
        set("title", HIG+"倾国倾城"+NOR);
        set("gender", "女性");
        set("age", 20+random(10));
        set("str", 20);
        set("dex", 20);
        set("long", "她就是传说中的李师师。\n");
        set("combat_exp", 200000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);

        set("neili", 200); 
        set("max_neili", 200);
        set("jiali", 1);

        set("shen_type",1);
        set("score",200);
        setup();
        call_out("intro",1);
       	carry_object("/clone/armor/cloth")->wear();
}

int intro()
{
    command("smile");
    call_out("goodbye",2);
    return 1;
}

int goodbye()
{
    command("wave");
    destruct(this_object());
    return 1;
}
