//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/dahan.c
 

inherit NPC;
#include <ansi.h>
string ask_jiasha();

void create()
{
   set_name("黑熊怪", ({ "hei xiong", "bear", "monster" }));
   set("long", "山间野兽，不知从哪里学到一身好本领。");
   set("gender", "男性");
   set_level(69);
   set("age", 30);
   set("attitude", "heroism");
   set("per", 9);
   set("force_factor",690);
   set("mana_factor", 20);

   set_skill("literate",690);
   set_skill("spells",690);
   set_skill("buddhism",690);
   set_skill("unarmed",690);
   set_skill("jienan-zhi",690);
   set_skill("dodge",690);
   set_skill("lotusmove",690);
   set_skill("parry",690);
   set_skill("force",690);
   set_skill("lotusforce",690);
   set_skill("staff",690);
   set_skill("lunhui-zhang",690);
   set_skill("spear",690);
   set_skill("huoyun-qiang",690);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");

   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :),
     (: cast_spell, "yinshen" :),
   }) );
   setup();
   carry_object("/d/qujing/guanyin/obj/boots")->wear();
   carry_object("/d/qujing/guanyin/obj/head")->wear();
   carry_object("/d/qujing/guanyin/obj/heilvshi")->wear();
   carry_object("/d/qujing/guanyin/obj/kaijia")->wear();
   carry_object("/d/qujing/guanyin/obj/zaopao")->wear();
   carry_object("/d/qujing/guanyin/obj/zaoying")->wield();
}

void unconcious ()
{
	die ();
}

void die ()
{
  object me = this_object();
  message_vision(HIR"只见$N摔倒在地，现了本形。原来是只黑熊！\n"NOR,me);
  message_vision("大黑熊急急忙忙的跑进了草丛中。\n",me);
  destruct (me);
}

        
