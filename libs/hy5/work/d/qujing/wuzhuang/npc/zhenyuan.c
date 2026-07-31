// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0

inherit NPC;
inherit F_MASTER;
#include "/d/migong/romnpc2.c"

string expell_me(object me);
string keyword(object me);
string sword_xiaofeng(object me);
string sword_sanqing(object me);
string asked_guo(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
   set_name("镇元大仙", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
   set("title", "五庄观观主");
   set("gender", "男性" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "交游遍三界，桃李漫五行。好一位地仙之祖！\n");
   set("class", "xian");
   set("combat_exp", 5600000);
   set("attitude", "peaceful");
   set("taskguai",1);
   create_family("五庄观", 1, "祖师");
   set("rank_info/respect", "观主");
   set_skill("unarmed", 220);
  

   set("max_qi", 4500);
   set("max_jing", 4500);
   set("neili", 5000);
   set("max_neili", 2500);
   set("neili", 7000);
   set("max_neili", 3500);   
   set("force_factor", 200);
   set("mana_factor", 200);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.


   set("inquiry", ([
     "name": "老夫镇元。\n",
     "here": "这里是五庄观，不过住的可不是道士。\n",

   ]) );

   setup();
   initlvl((1380+random(1380)),16);
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/ruler")->wield();
}





void init()
{
        
     object ob = this_player();
        if( ob->query_temp("kill_tree") )
        {
        command("say 小杂毛，如果不把我的人参果树救活，别怪老夫不客气了。");
        command("slap "+ob->query("id"));
        }

}

