// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
int give_good(object who);
int give_bad(object who);
int test_player (object who);
void create()
{
   set_name("黑汉", ({ "hei han", "han" }));
   set("title", "黑风洞洞主");   
   set("long", @LONG
黑汉本是山间野兽，不知从哪里学到一身好本领。
后遇见南海观音，被南海观音收为徒弟。
LONG);
   set_level(69);
   set("gender", "男性");
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

void die ()
{
  object me = this_object();
  message_vision ("\n突然观音菩萨喊道：手下留情。\n",me);
  message_vision ("\n观音菩萨拿出紧箍咒套向$N头上。\n",me);
  message_vision ("\n$N倒在地上现出原形：原来是一只黑熊怪。\n",me);
  message_vision ("\n观音菩萨道：此怪倒是有些慧根，我收了去，自有用处，你等继续西去吧。\n",me);
  destruct(me);
}
