inherit NPC;
void create()
{
        set_name("苏鲁克", ({ "suluke", "su"}));
        set("gender", "男性");
        set("age", 45);
        set("long", "他就是哈萨克第一勇士苏鲁克。\n");
        set("attitude", "heroism");
        set("combat_exp", 110000);
        set("shen", 1100);
        set("str", 33);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 60000);
        set("max_jing", 60000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 10);
          set_skill("dodge", 520);
        set_skill("parry", 530);
        set_skill("force", 550);
	set_skill("taixuan-gong", 550);
        set_skill("shenzhao-jing", 380);
        map_skill("dodge","taixuan-gong");
        map_skill("force","taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed","taixuan-gong");
      set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 30);
        setup();
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object("/d/hj/obj/jiunang");
}