#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);

void create()
{
        string weapon;
        set_name("戚家军兵丁", ({ "qi bing","bing"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个威武的戚家军兵丁。\n");
        set("combat_exp", 8000000 + random(4000000));
       // set("attitude", "aggressive");
        set_skill("force", 500);
        set_skill("sword", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("cuff", 500);
        set_skill("blade", 500);
        set_skill("taizu-quan", 500);
        set_skill("qingmang-jian", 500);
        set_skill("wind-blade", 800+random(180));
          map_skill("blade", "wind-blade");
          map_skill("parry", "wind-blade");
          map_skill("dodge", "qingmang-jian");
          map_skill("sword", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 220);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
                set("max_qi", 4500);
        set("eff_jingli", 8000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 300);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        add_money("silver", random(100));


        
        carry_object(weapon)->wield();
        carry_object("/clone/misc/cloth")->wear();
}

//#include "bing.h"
