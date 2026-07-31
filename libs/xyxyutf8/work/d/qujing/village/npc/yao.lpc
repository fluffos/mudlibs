//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/npc/yao.c

inherit NPC;

void create()
{
   set_name("食人魔", ({ "shiren mo", "yao"}));
   set("gender", "男性" );
   set("age", 35);
   set("long","一个专门吃人的老妖怪。\n");
   set_level(41);
   set("force_factor", 40);
   set("attitude","aggressive");
   set_skill("unarmed",410);
   set_skill("wuxing-quan",410);
   set_skill("dodge",410);
   set_skill("baguazhen",410);
   set_skill("parry",410);
   set_skill("hammer",410);
   set_skill("kaishan-chui",410);
   set_skill("force",410);
   set_skill("zhenyuan-force",410);
   set_skill("spells",130);
   set_skill("taiyi",410);
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