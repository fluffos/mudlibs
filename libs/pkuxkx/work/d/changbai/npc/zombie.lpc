// /d/changbai/npc/zombie.c 大僵尸
// Modified by becool 05/10/2008 : 减少掉宝数至3
inherit NPC;
int auto_heal();
void create()
{
        set_name("大僵尸", ({ "big zombie", "zombie" }) );
        set("gender", "无性");
        set("age", 45 + random(10));
        set("str", 500);
        set("per", 10);
        set("long",
                "这家伙整个脸都烂了，太可怕了，令人望而生畏。\n");
        set("combat_exp", 35800000 + random(10000000));
        set("shen_type", -1);
        set("attitude", "aggressive");
         set("force_factor", 2 + random(100));
         set("max_qi", 150000+random(5990));
         set("max_jing", 150000 + random(5990));
         set("max_jingli", 150000 + random(5990));
        set("max_neili", 150000 + random(5990));
        set("neili", query("max_neili"));
        set("jingli", query("max_jingli"));
        set("jing", query("max_jing"));
        set_temp("apply/attack", 300 + random(200));
        set_temp("apply/defense", 300 + random(200));
        set_temp("apply/armor", 300 + random(300));
        set_temp("apply/damage", 200 + random(200));
        set("gem_level", ({0, 9444}));
        set("item_drop_odds", ({100, 250, 250, 100, 150, 145, 5 }));
        set("luding_monster", 1);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: auto_heal :),
        }));
        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
                "大僵尸嘿嘿地怪叫着: 放下宝藏!\n",
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
        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
//        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
//        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
//        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
//        GEM_D->drop(this_object(),this_object()->get_damage_origin_object());
/*
        ob = GEMDROP_D->misc_drop();
        ob->move(corpse);
*/
        corpse->set("no_get_from",1);
        corpse->set("no_get",1);
        destruct(this_object());
}
