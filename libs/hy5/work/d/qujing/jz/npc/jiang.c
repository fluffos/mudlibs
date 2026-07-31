//Cracked by Roath
inherit NPC;
#include <ansi.h>
string ask_fish();
string ask_bingfa();

void create()
{
  set_name("姜太公", ({ "jiang taigong","jiang"}));
  set("long", "他就是那个钓鱼的姜太公。\n");
  set("gender", "男性");
  set("age", 57);
  set("str", 50);
  set("max_qi", 1200);
  set("max_jing", 1200);
  set("neili", 3000);
  set("max_neili", 2000);
  set("force_factor", 60);
  set("max_neili", 2000);
  set("neili", 2000);
  set("mana_factor", 60);
  set("combat_exp", 1500000);
	set("combat_exp",1500000);	
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("force", 150);
  set_skill("spells", 150);
  set_skill("unarmed", 150);
  set_skill("staff", 150);

  set("chat_chance", 10);
  set("inquiry", ([
        "钓鱼" : (: ask_fish :),
        "fish" : (: ask_fish :),
        "兵法" : (: ask_bingfa :),
        ]));
  set("chat_msg", ({
                "姜太公说道：愿者上钩...愿者上钩。\n",
                        }));
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
   carry_object("/d/qujing/jz/obj/yugan");  
}
string ask_fish()
{
        object ob = this_player();
        object me = this_object();

           if( ob->query("combat_exp") < 1000000  )
                return "没看到我在钓鱼吗？\n";

        command("hehe");
        ob->set_temp("just_wait",time());
        return "既然"+ RANK_D->query_respect(ob)
        +"对钓鱼感星期，可否陪老夫钓会鱼？\n";
}


