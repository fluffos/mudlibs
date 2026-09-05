#include <ansi.h>
inherit NPC;
#include "/d/song/obj/askmap.h"
int do_copy(object me,int flag);
int do_back(object me);

void create()
{
        string weapon;
        set_name("戚家军千总", ({ "qian zong","jiang"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个威武的戚家军千总。\n");
        set("combat_exp", 10000000 + random(4000000));
      //  set("attitude", "aggressive");
        set_skill("force", 800);
        set_skill("sword", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("cuff", 800);
        set_skill("blade", 800);
        set_skill("taizu-quan", 800);
        set_skill("qingmang-jian", 800);
        set_skill("wind-blade", 1000+random(180));
          map_skill("blade", "wind-blade");
          map_skill("parry", "wind-blade");
          map_skill("dodge", "qingmang-jian");
          map_skill("sword", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense",500);
        set_temp("apply/armor", 300);
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
        set("loc","泉州");
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        add_money("silver", random(100));


        
        carry_object(weapon)->wield();
        carry_object("/clone/misc/cloth")->wear();
}

//#include "bing.h"
