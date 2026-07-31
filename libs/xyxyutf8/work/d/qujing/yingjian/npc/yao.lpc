//Cracked by Roath


inherit NPC;

void create()
{
   set_name("水妖", ({ "shui yao", "yao"}));
   set("gender", "男性" );
   set("age", 35);
   set("long","盘踞在水下的老妖怪。\n");
   set_level(75);
   set("force_factor", 40);
   set("attitude","aggressive");
   set_skill("unarmed", 750);
   set_skill("wuxing-quan", 750);
   set_skill("dodge", 750);
   set_skill("baguazhen", 750);
   set_skill("parry", 750);
   set_skill("hammer",750);
   set_skill("kaishan-chui",750);
   set_skill("force", 750);
   set_skill("zhenyuan-force", 750);
   set_skill("spells",750);
   set_skill("taiyi", 750);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("hammer", "kaishan-chui");
   map_skill("dodge", "baguazhen");
   set("chat_chance_combat", 70);
   set("chat_msg_combat", ({
     (: cast_spell, "qiankun" :),
    }) );
   setup();
   carry_object("/obj/cloth")->wear();
   carry_object("/d/qujing/village/obj/hammer")->wield();
}