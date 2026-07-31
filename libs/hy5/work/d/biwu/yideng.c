// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("一灯大师", ({"yideng-dashi", "dashi", "yideng"}));
    set("nickname", HIG "南帝" NOR );
    set("gender", "男性");
    set("age", 52);
    set("long", 
        "他就是号称「南帝」的一灯大师，俗名段智兴，现已逊位为僧。\n"
        "大师一生行善，积德无穷。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 121);
    set("int", 130);
    set("con", 126);
    set("dex", 130);

    set("qi", 353000);
    set("max_qi", 353000);
    set("jing", 353000);
    set("max_jing", 353000);
    set("neili", 353500);
    set("max_neili", 353500);
    set("jiali", 100);
	
    set("combat_exp", 93000000);
    set("score", 0);
     
    set_skill("kurong-changong", 1350);             // 基本内功
    set_skill("unarmed", 1350);             // 基本内功
    set_skill("force", 1350);             // 基本内功
    set_skill("finger", 370);            // 基本指法
    set_skill("dodge", 1350);             // 基本躲闪
    set_skill("parry", 1350);             // 基本招架
    set_skill("six-finger", 980);   // 六脉神剑
    set_skill("taixuan-gong", 980);      // 太玄神功
    set_skill("lingxu-bu", 980);         // 凌虚步
    set_skill("literate",380);           // 读书识字
	
    map_skill("force"  , "kurong-changong");
    map_skill("unarmed" , "six-finger");
    map_skill("finger" , "six-finger");
    map_skill("dodge"  , "lingxu-bu");
    map_skill("parry"  , "six-finger");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "unarmed.liumaijingshen" :),
                (: perform_action, "unarmed.qi" :),
                (: perform_action, "unarmed.zong" :),
                (: perform_action, "unarmed.zongheng" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );



    prepare_skill("finger", "six-finger");

    create_family("大理段家", 17, "弟子");
    setup();

    carry_object("/p/item/ritemtz3/acloth58")->wear();
    carry_object("/p/item/ritemtz3/ahands32")->wear();
}
