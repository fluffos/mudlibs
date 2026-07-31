//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//海上三星

inherit NPC;
#include "/d/migong/romnpc2.c"
string ask_me();
void create()
{
        set_name("福星", ({"fu xing", "xing"}));
   set("title", "蓬莱三老");
   set("gender", "男性");
   set("long", "霄汉中间一老人，手捧如意飞蔼绣。葫芦藏蓄万年丹，宝篆名书千纪寿。
洞里乾坤任自由，壶中日月随成就。遨游四海任清闲，散淡十洲容福胄。
曾赴蟠桃醉几遭，醒时名月还依旧。方面玉颜多神俊，三缕长苒飘颌边。\n");
        set("attitude", "peaceful");
        set("combat_exp", 12000000);
   create_family("五庄观", 2, "弟子");
   set("age", 70);
   set("per", 100);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "老福星");
   set("max_kee", 1000);
   set("max_jing", 1000);
   set("force", 1000);
   set("max_force", 1000);
   set("force_factor", 40);
   set("max_mana", 600);
   set("mana",600);
   set("mana_factor", 50);
   
 

        set("inquiry", ([
     "碧藕"     : "我没那玩意，去问问老寿星吧！\n",
                "交梨"     : "我没那玩意，去问问老禄星吧！\n",
     "name"     : "老夫福星是也。\n",
     "here"     : "此乃蓬莱仙岛也。\n",
     "下棋"      : "你个臭棋篓子，谁要跟你下棋！\n",
     "围棋"     : "连围棋都不知道？\n",

        ]));

   set("time", 1);
   setup();
   initlvl((300+random(300)),8);
   carry_object("/d/obj/cloth/bai")->wear();   
   carry_object("/d/qujing/nanhai/obj/jp2");
}



void die()
{

        if( environment() ) {
        message("sound", "\n\n只听一声鹤鸣，福星化作一道白光向天上直冲而去。。。\n\n
半空中有人哈哈笑了几声。。。\n\n", environment());
        }

        destruct(this_object());
}






