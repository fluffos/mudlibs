//wangqier     written by jhon darks
#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("王乞儿", ({ "wang qier", "wang", "qier","王乞儿" }) );
        set("nickname", HIR " 赌到山穷水尽" NOR);
        set("gender", "男性");
        set("age", 19);
        set("long",
                "据说他乃当今赌仙，此人年纪轻轻，却好赌如命．．．\n他的一个朋友叫天草四郎，好像也是个赌徒．．．\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 10);
        set("cor", 30);
        set("dur", 30);
        set("agi", 40);
        set("int", 24);
        set("cps", 30);
        set("per", 18);
        set("chat_chance", 1);
        set("chat_msg", ({
                "王乞儿长笑一声：“世上难道无人与我一赌．．．”\n",
                "王乞儿低叹一声：“雨花石雨花石．．．”\n",
        }) );

        set("inquiry", ([

                "雨花石" : "拾之可惜，弃之可叹．．．\n",
        ]) );

        set("max_sen",3000);
        set("max_gin",3000);
        set("max_kee",3000);
        set("force", 2000);
        set("max_force", 2000);
        set("combat_exp", 600000);
        set("score", 5000);
 
        set_skill("unarmed", 100);
        set_skill("force", 100);

        set_skill("begging",120);

 
        set_skill("dodge",100);
        set_skill("literate",100);
        set_skill("throwing",120);
     

        set("title", GRN"九世乞丐"NOR);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
