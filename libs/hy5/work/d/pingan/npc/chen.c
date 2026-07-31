// chen.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("陈小德", ({ "chen xiaode", "chen" }));
        set("long", "陈小德是平安武馆馆长，是扬州武馆陈有德教头的亲弟弟。\n");
        set("gender", "男性");
        set("age", 45);
        set_skill("dodge", 40);
        set_skill("force", 40);
        set_skill("parry", 40);
        set_skill("claw", 40);
        set_skill("hand", 40);
        set_skill("strike", 40);
        set_skill("finger", 40);
        set_skill("cuff", 40);
        set_skill("blade", 40);
        set_skill("stick", 40);
        set_skill("club", 40);
        set_skill("staff", 40);
        set_skill("sword", 40);
        set_skill("throwing", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}
int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 5000)
    {
        message_vision("陈小德望着$N说：你的武功应该历练江湖才能再长进，不能埋没
在这里了。如果你想继续学习下去，可以去扬州城找我哥陈有德。\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/pingan_paied",1);
        message_vision("陈小德对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return 1;
    }
    else
        message_vision("陈小德皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/pingan_paied")==1) return 0;
        return 1;
}


