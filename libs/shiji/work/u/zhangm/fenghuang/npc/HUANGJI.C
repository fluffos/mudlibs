#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;void create()
{
        set_name("黄吉", ({ "huang ji", "huang" }));
        set("age", 35);
        set("title", HIY "神剑" NOR);
        set("gender", "男性");
        set("long", "为人真挚，和善，以剑法出名有神剑之称。\n");
        set("attitude", "peaceful");

        set("qi", 3000);        set("max_qi", 3000);
        set("jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("max_jing", 2000);
        set("str", 40);
        set("dex", 40);
        set("per", 30);
        set("combat_exp", 800000);
        set("shen_type", 1);

        set_skill("unarmed", 180);
        set_skill("literate", 120);
        set_skill("dodge", 140);
        set_skill("parry", 170);
        set_skill("blade", 100);
        set_skill("force", 160);
        set_skill("wuzu-xinfa", 140);
        set_skill("shaolin-shenfa", 140);
        set_skill("jile-dao", 150);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);
        map_skill("blade", "jile-dao");
        map_skill("parry", "jile-dao");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "wuzu-xinfa");
        create_family("凤凰星",10,"弟子");              set("chat_chance_combat", 10);
        setup();
        carry_object("/u/zhangm/fenghuang/obj/blade")->wield();
        carry_object("/u/zhangm/fenghuang/obj/pixue")->wear();
        carry_object("/u/zhangm/fenghuang/obj/junfu")->wear();
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ((string)ob->query("family/family_name") == "凤凰星")
             {
               message_vision("黄吉冲着$N点点头，微微笑了笑。\n",ob);
               return;
              }
 }

void attempt_apprentice(object ob)
{
     command("say 好吧，我收下你。\n");
     command("recruit "+ob->query("id"));
     return;
}


