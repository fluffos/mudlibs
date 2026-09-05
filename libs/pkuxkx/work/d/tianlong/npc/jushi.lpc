#include <ansi.h>
inherit NPC;

void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("long",
                "他是一个信佛的居士。\n");
        set("title",HIC "居士"NOR);
        set("gender", "男性");
        set("age", 16+random(60));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        set("max_qi", 200);
        set("max_jing", 150);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 3000);
        set("score", 3000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 20);
        set_skill("parry", 30);
        set("random_npc",1);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        call_out("moving",1);
        call_out("dest",300);
}

int moving()
{
    random_move();
    if (!random(4))
    {
        random_move();
    }
    call_out("moving",60);
    return 1;
}

int dest()
{
    object ob=this_object();
    message_vision("$N找到了回家的路，匆匆忙忙离开了。\n",ob);
    destruct(ob);
    return 1;
}


