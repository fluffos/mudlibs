inherit NPC;
void create()
{
  set_name("多隆",({"duo long"}));
  set("gender","男性");
  set("age",43);
  set("nickname","侍卫总管");
  set("combat_exp",5000000);
  set("force",700);
  set("max_force",700);
  set("force_factor",40);
    set("max_neili",18500);
    set("neili",18500);
    set("qi",18500);
    set("eff_qi",18500);
    set("max_qi",18500);

    set("jing",18500);
    set("eff_jing",18500);
    set("max_jing",18500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 380+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 380+random(180));
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
  add_money("gold",1);
}
#include "shiwei.h"