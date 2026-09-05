//1.玩家的bc
//2.不可修复物品

inherit NPC;
#include <ansi.h>
int auto_heal();
int auto_perform();

void create()
{
        set_name("大僵尸", ({ "big zombie", "zombie" }) );
        set("gender", "无性");
        set("age", 45 + random(10));
        set("str", 80);
        set("per", 10);
        set("long",
                "这家伙整个脸都烂了，太可怕了，令人望而生畏。\n");
        set("combat_exp", 5800000 + random(5000000));

        set("shen_type", -1);
        set("attitude", "aggressive");

         set("force_factor", 2 + random(100));
         set("max_qi", 100000);
         set("max_jing", 3000 + random(5990));
         set("max_jingli", 3000 + random(5990));
        set("max_neili", 3000 + random(5990));

        set("neili", query("max_neili"));
        set("jingli", query("max_jingli"));
        set("jing", query("max_jing"));

        set_temp("apply/attack", 300 + random(200));
        set_temp("apply/defense", 300 + random(200));
        set_temp("apply/armor", 500 + random(300));
        set_temp("apply/damage", 100 + random(200));

        set("gem_level", ({0, 9444}));
        set("item_drop_odds", ({100, 250, 250, 100, 150, 145, 5 }));
        set("luding_monster", 1);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: auto_heal :),
        }));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                "僵尸嘿嘿地怪叫着: 放下宝藏!\n",
                (: auto_perform :),
        }) );

        set_skill("strike", 380 + random(250));
        set_skill("unarmed", 350 + random(250));
        set_skill("parry", 350 + random(250));
        set_skill("dodge", 350 + random(250));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 50);
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) )
        {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}

int auto_heal()
{
        object ob = this_player();
        int amount;

        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                amount = ob->query("max_qi") / 20;
                ob->add("eff_qi", amount);
                if (ob->query("eff_qi") > ob->query("max_qi")) ob->set("eff_qi", ob->query("max_qi"));
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                amount = ob->query("eff_qi") / 20;
                ob->add("qi", amount);
                if (ob->query("qi") > ob->query("eff_qi")) ob->set("qi", ob->query("eff_qi"));
        }
        if (ob->query("jingli") < ob->query("max_jingli") * 2)
        {
                amount = ob->query("max_jingli") / 20;
                ob->add("jingli", amount);
                if (ob->query("jingli") > ob->query("max_jingli") * 2) ob->set("jingli", ob->query("max_jingli") * 2);
        }
        if (ob->query("eff_jing") < ob->query("max_jing"))
        {
                amount = ob->query("max_jing") / 20;
                ob->add("eff_jing", amount);
                if (ob->query("eff_jing") > ob->query("max_jing")) ob->set("eff_jing", ob->query("max_jing"));
        }
        if (ob->query("jing") < ob->query("eff_jing"))
        {
                amount = ob->query("eff_jing") / 20;
                ob->add("jing", amount);
                if (ob->query("jing") > ob->query("eff_jing")) ob->set("jing", ob->query("eff_jing"));
        }
        if (ob->query("neili") < ob->query("max_neili") * 2)
        {
                amount = ob->query("max_neili") / 20;
                ob->add("neili", amount);
                if (ob->query("neili") > ob->query("max_neili") * 2) ob->set("neili", ob->query("max_neili") * 2);
        }
        return 1;
}

void die()
{
        int i;
        object ob, corpse;
        message_vision("$N摇晃了几下，散成了一堆骨架。\n", this_object());
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
        corpse->set("name", "白骨架");
        corpse->set("long", "一堆白骨架。\n");
        corpse->move(environment(this_object()));

        ob = GEMDROP_D->item_drop(query("gem_level"), query("item_drop_odds"));
        ob->move(corpse);
        ob = GEMDROP_D->item_drop(query("gem_level"), query("item_drop_odds"));
        ob->move(corpse);
        ob = GEMDROP_D->item_drop(query("gem_level"));
        ob->move(corpse);
        for(i = 0; i < 3; i++)
        {
                ob = GEMDROP_D->gem_drop(query("gem_level"));
                ob->move(corpse);
        }
        ob = GEMDROP_D->misc_drop();
        ob->move(corpse);

        corpse->set("no_get_from", 1);
        destruct(this_object());
}

int auto_perform()
{
        object me = this_object();
        object *enemy = me->query_enemy();
        int n = sizeof(enemy);
        object target = enemy[random(n)];
        object owner;
        object here = environment(me);
        int i, j, damage;

        i = random(8);
        switch(i)
        {
                case 0:
                for(j = 0; j < n - 1; j++)
                if(environment(enemy[j]) == here)
                {
                        enemy[j]->receive_damage("qi", 100 + random(500), me);
                        enemy[j]->receive_wound("qi", 100 + random(200), me);
                }
                message_vision(HIG"$N突然喷出一口绿色毒雾，众人\n"NOR, me);
                break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                target->receive_damage("qi", 100 + random(500), me);
                message_vision(HIR"$N，$n\n"NOR, me, target);
                break;
        }

        return 1;
}
