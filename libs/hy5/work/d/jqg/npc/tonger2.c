// /NPC tonger.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("绿衣僮儿", ({ "luyi tonger", "luyi", "tonger"}));
       set("long", "他是绝情谷的绿衣弟子，长得眉清目秀。\n");
       set("gender", "男性");
       set("age", 15);
       set("shen_type",1);
       set("attitude", "peaceful");
  
       set("str", 14);
       set("int", 20);
       set("con", 25);
       set("dex", 20);
       set("per", 23);

       set("qi", 300);
       set("max_qi", 300);
       set("jing", 200);
       set("max_jing", 200);
       set("eff_jingli",200);
       set("combat_exp", 10000);

       setup();
       carry_object("/clone/misc/cloth")->wear();
}
