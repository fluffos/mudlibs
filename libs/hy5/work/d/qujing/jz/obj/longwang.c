//Cracked by Roath

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
          set_name("°½¹ã", ({"ao guang", "ao","guang","longwang","wang"}));

   set("long","°½¹ãÊÇ¶«º£µÄÁúÍõ£¬ÆäĞÖµÜ·Ö±ğÕÆ¹Ü¶«£¬Î÷£¬ÄÏ£¬±±ËÄº£¡£
ÓÉÓàÆäË®×åÖÚ¶à£¬ÉùÊÆºÆ´ó£¬Ù²È»¶À°ÔÒ»·½¡£\n");
          set("gender", "ÄĞĞÔ");
          set("age", 66);
   set("title", "¶«º£ÁúÍõ");
   set("class","dragon");
          set("attitude", "aggressive");
          set("shen_type", 1);
        set("combat_exp", 1260000);
        set("rank_info/respect", "±İÏÂ");
          set("per", 20);
          set("str", 30);
          set("max_qi", 3000);
          set("max_jing", 400);
          set("max_jing", 800);
          set("neili", 3000);
          set("max_neili", 1500);
          set("force_factor", 120);
          set("max_neili", 800);
          set("neili", 1600);
          set("mana_factor", 40);
          set("combat_exp", 1200000);
          set_skill("unarmed", 200);
          set_skill("dodge", 180);
          set_skill("force", 180);
          set_skill("parry", 180);
          set_skill("hammer", 190);
          set_skill("staff", 180);
          set_skill("spells", 150);
    

          create_family("¶«º£Áú¹¬", 1, "Ë®×å");
          set_temp("apply/armor",150);
          set_temp("apply/damage",125);
          setup();
initlvl((200+random(100)),6);
        carry_object("/d/obj/cloth/longpao")->wear();
}


void init()
{
     object ob = this_player();
     string env;
     env=environment()->query("short");
     if( env == "[1;33mµöÓãÌ¨[m"&& ob->query("fish") ) 
     message("channel:chat",HIC+"¡¾°½¹ã¡¿£ºËûÄÌÄÌµÄ"+ ob->query("name") +"£¬ÄãÃÇË­ÔÙ¸ÒµöÓã£¬±ğ¹ÖÀÏ×Ó²»¿ÍÆø¡£\n"+NOR,users());

}
