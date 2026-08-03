inherit NPC;
int ask_lineup();
int ask_heal();
void create()
{
        set_name("峨嵋弟子", ({ "dizi" }));
        set("long","这是一个峨嵋弟子。\n");
        
        set("gender", "女性");
        set("age", random(10)+20);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 18+random(5));
        set("int", 20+random(5));
        set("con", 18+random(5));
        set("dex", 22+random(5));

        set("max_qi", 2000+random(500));
        set("max_jing", 2000+random(200));
        set("neili", 3500+random(500));
        set("max_neili", 3000+random(500));
        set("max_jingli",2000+random(500));
        set("eff_jingli",2500+random(500));
        set("jiali", 50);
        set("combat_exp", 800000+random(200000));

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("linji-zhuang", 150);
        set_skill("anying-fuxiang", 150);
        set_skill("huifeng-jian", 150);
        set_skill("sword", 150);
        set_skill("strike", 150);
        set_skill("sixiang-zhang", 150);
        set_skill("linji-jianzhen",150);

        map_skill("force", "linji-zhuang");
        map_skill("sword", "huifeng-jian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("parry", "huifeng-jian");
        map_skill("strike","sixiang-zhang");
        prepare_skill("strike", "sixiang-zhang");

        set("inquiry", ([
                "布阵": (: ask_lineup :),
                "疗伤": (: ask_heal:),
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.jue" :),
                (: exert_function, "wuwo" :),
                (: exert_function, "riyue" :),
                (: exert_function, "youming" :),
        }));

        setup();
}

int ask_lineup()
{
      object me = this_player();
      if (me->query_temp("xy/job")!=2)
      {
              command("?");
              return 1;
      }
      command("nod");
      command("lineup with " + me->query("id"));
      return 1;
}

int ask_heal()
{
      object me = this_player();
      if (me->query_temp("xy/job")<2)
      {
              command("?");
              return 1;
      }
        command("exert tiandi "+me->query("id"));
      command("nod");
      return 1;
}

