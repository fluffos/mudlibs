// qian.c by binlang
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("钱二败", ({"qian erbai","qian","erbai"}) );
        set("gender", "男性" );
        set("title",  HIY"神箭八雄"NOR);
        set("age", 46);
        set("long",
"这是绿柳山庄的神箭八雄中的老二。
此人身强力壮，不用箭时就使一支方天画戟。\n");
        set_temp("apply/attack", 35);
        set_temp("apply/defense", 35);
        set_temp("apply/damage",20);
        set("combat_exp", 50000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set_skill("unarmed",55);
        set_skill("dodge",55);
        set_skill("parry",55);
        set_skill("force",55);
        set_skill("halberd",55);
        set("attitude","heroism");
        set("shen_type",1);set("score",500);setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/fangtianji")->wield();

}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}
void greeting(object me)
{
        command("say 这位" + RANK_D->query_respect(me)
 + "到了敝庄，有什么招待不周的地方多多包涵。");
}
