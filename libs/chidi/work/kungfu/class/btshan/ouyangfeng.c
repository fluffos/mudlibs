//ouyangfeng.c
#include <ansi.h>
inherit BHNPC;
inherit F_MASTER;
void create()
{
    set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
    set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
           +"由于习练「九阴真经」走火入魔，已变得精\n"
           +"神错乱，整日披头散发。\n");
    set("title", "老毒物");
    set("gender", "男性");
    set("age", 53);
    set("nickname", HIR "西毒" NOR);
    set("shen_type",-4);
    set("attitude", "peaceful");
    set("str", 100);
    set("int", 70);
    set("con", 50);
    set("dex", 200);
    set("qi", 20000);
    set("max_qi", 20000);
    set("jing", 10000);
    set("max_jing",10000);
     set("neili",200000);
    set("max_neili", 30000);
    set("jiali", 300);
    set("combat_exp", 80000000);
    set("score", 200000);
    set_skill("force", 1200);
    set_skill("unarmed", 1100);
     set_skill("dodge", 1000);
     set_skill("literate", 1300);
      set_skill("parry", 1150);
     set_skill("staff", 1200);
     set_skill("hamagong", 1100);
     set_skill("chanchu-bufa",1100);
      set_skill("shexing-diaoshou",1200);
     set_skill("sword",1300);
     set_skill("killsword",1300);
      set_skill("lingshe-zhangfa",1000);
     map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "shexing-diaoshou");
   map_skill("sword", "killsword");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
    create_family("白驼山派",1, "开山祖师");
        set("chat_chance",2);
        set("chat_msg",({
         "欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
         "欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
         "欧阳锋道：江湖险恶，困难重重哪！\n",
        }));
    setup();
    carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
    add_money("gold",50);
}
void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<3000000)
        {
          message_vision("欧阳锋对$N笑道：你的经验太低了,我还不能收你！\n",ob);
    return ;
         }
   message_vision("欧阳锋拍拍$N的头，微微点了点头。\n",ob);
   command("recruit " + ob->query("id"));
   //ob->set("title",HIC"西毒传人"NOR);
   return;
}

