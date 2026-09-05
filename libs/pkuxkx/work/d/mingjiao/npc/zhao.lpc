#include <ansi.h>
inherit NPC;
void create()
{
        set_name("赵一伤", ({"zhao yishang","yishang","zhao"}) );
        set("gender", "男性" );
        set("title",  HIY"神箭八雄"NOR);
        set("age", 48);
        set("long",
"这是绿柳山庄的神箭八雄中的老大。
此人高大威猛，不用箭时就使一把雷震挡,功夫不弱。\n");
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
        set_skill("hammer",55);
        set("attitude","heroism");
        set("shen_type",1);set("score",500);setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/leizhendang")->wield();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object me)
{
	      if ( objectp(me) )
          command("say 这位" + RANK_D->query_respect(me)
 + "远来敝庄，有失远迎。");
}
