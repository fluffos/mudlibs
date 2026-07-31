//【蜀山剑派】dhxy-evil 2000.7.5
// Modified by Longer@ALL_XYJ 2001-12-19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();
void create()
{
       set_name("剑圣", ({ "jian sheng", "sheng", "swordsman" }));
        set("title","");
        set("long", 
"蜀山剑派祖师爷，满头白发的老人，两眼炯炯有神。\n");

        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","swordsman");
        
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 8000);
        set("max_force", 5000);
        set("max_mana",5000);
        set("mana",8000);
        set("force_factor", 100);
        set("mana_factor", 100);
        set("combat_exp", 3000000);
        set("daoxing", 5000000);

       
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);

        setup();
        
       
        carry_object("/d/xiyou/shushan/obj/qxsword")->wield();
}
