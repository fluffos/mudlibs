// chen.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("陈有德", ({ "chen youde", "chen" }));
        set("long", "陈有德是扬州武馆馆长。\n");
        set("gender", "男性");
        set("age", 45);
set("pubmaster",1);
        set_skill("chang-quan", 200);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("claw", 100);
        set_skill("hand", 100);
        set_skill("strike", 100);
        set_skill("finger", 100);
        set_skill("cuff", 100);
        set_skill("blade", 100);
        set_skill("stick", 100);
        set_skill("club", 100);
        set_skill("staff", 100);
        set_skill("sword", 100);
        set_skill("throwing", 100);
	set_skill("luoyan-jian", 200);
	set_skill("shiba-pan", 200);
	set_skill("songshan-jian", 200);
	set_skill("liuhe-dao", 200);
	set_skill("hengshan-jian", 200);
	set_skill("feixian-sword", 200);
	map_skill("parry", "chang-quan");
	map_skill("cuff", "chang-quan");
	prepare_skill("cuff", "chang-quan");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}
int accept_object(object who, object ob)
{

    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/yangzhou_paied",1);
        message_vision("陈有德对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return 1;
    }
    else
        message_vision("陈有德皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}


