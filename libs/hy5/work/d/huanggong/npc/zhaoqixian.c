inherit NPC;
void create()
{
  set_name("赵齐贤",({"zhao qixian","zhao"}));
  set("gender","男性");
  set("nickname","御前侍卫");
  set("age",34);
  set("combat_exp",1500000);
  set("force",300);
  set("force_factor",24);
  set("chat_chance",3);
  set("chat_msg",({
  "赵齐贤道:昨晚宫中不大太平,幸好我躲在被窝中.\n",
  "赵齐贤道:刺客招供是平西王派来的,这老小子好大胆.\n",
  "赵齐贤道:跟了桂公公,升官发财不用愁.\n",
  }));
    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
  setup();
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("d/city/npc/obj/tiejia")->wear();
  carry_object("d/city/npc/obj/toukui")->wear();
  add_money("silver",50);
 }
#include "shiwei.h"
