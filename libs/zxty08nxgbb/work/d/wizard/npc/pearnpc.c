inherit NPC;


void create()
{
        set_name(HIW"阿龙"NOR, ({"pear_npc", "pear"}));
        set("title", HIG"[天 涯"HIR" ☆"NOR+WHT" 最 杰 出"HIR" ☆"HIG" 玩 家]"NOR); 
        set("long", HIW "天涯的最杰出的老玩家之一,无论是在游戏中,还是在生活\n
                         工作中,都是异常的优秀,堪称龙中之龙。\n"NOR);
        set("gender", "男性");
        set("combat_exp", 10000);
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("per", 30);
        set("no_die", 1);
        set_skill("dodge",20);
        set_skill("unarmed",20);

       
        setup();
         carry_object("/d/wizard/npc/obj/colorcloth")->wear();
        add_money("coin", 40+random(30));
}

