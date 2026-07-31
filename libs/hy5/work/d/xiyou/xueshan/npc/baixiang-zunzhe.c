
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// baixiang-zunzhe.c...weiqi, 97.09.15.

inherit NPC;
string ask_chuxian();
   string ask_cancel();
void create()
{
   set_name("白象尊者", ({"baixiang zunzhe", "baixiang", "zunzhe"}));
   set("title", "明王护法");
   set("gender", "男性" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("long", "这位白象尊者是有名的大力士。以前在狮驼山做二大王，\n狮驼山被剿灭后他跟着青狮老魔投奔大鹏明王，做了护法尊者。\n生平最怕的是老鼠，看到尖嘴猴腮的人就讨厌。\n");
   set("class", "yaomo");
   set("combat_exp", 800000);
   set("attitude", "peaceful");
   create_family("大雪山", 2, "弟子");
 

   set("max_kee", 1200);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 800);
   set("max_mana", 400);   
   set("force_factor", 60);
   set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

   setup();
   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}
