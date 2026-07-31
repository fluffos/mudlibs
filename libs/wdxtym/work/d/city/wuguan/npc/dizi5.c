//dizi5.c 卜垣 by river

inherit NPC;

#include <ansi.h>
void create()
{
        set_name("卜垣", ({ "bo yuan", "bo", "yuan"}));
        set("title","襄阳武馆五弟子");
        set("long", "他是万震山的五弟子，文质彬彬，一点不象个武林中人。\n");
        set("gender", "男性");
        set("age", 24);
        set("combat_exp", 4500);
        set("shen_type", 1);

        set_skill("literate", 30);
        set_skill("force", 45);
        set_skill("strike", 45);
        set_skill("sword", 45);
 
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int prevent_learn(object ob, string skill)
{
        if (skill == "literate")
                return 0;
        return 1;
}

int is_apprentice_of(object ob)
{
        return 1;
}

int recognize_apprentice(object ob)
{
        int money=20, level = ob->query_skill("literate", 1);

        if (level>10) money=10;
        if (level>20) money=20;
        if (level>30) money=50;  

        ob->delete_temp("mark/literate");
        switch(MONEY_D->player_pay(ob, money)){
                case 0:
                case 2:
                return notify_fail("你现在学习一次所需要的费用是"+MONEY_D->money_str(money)+"，你身上带的零钱不够了。\n");
        }
        ob->set_temp("mark/literate", 1);
        return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ( ob->query_skill("literate") >= 30 ) return;
        command("hi " + ob->query("id"));
        command("say 这位" + RANK_D->query_respect(ob)+ "，虽说练武比读书重要，但你目不识丁，如何去理解那\n"+
                "些武功秘籍呢？你可以跟我学点读书写字 "HIY HBCYN"xue bo literate"CYN" 。"NOR);
}
