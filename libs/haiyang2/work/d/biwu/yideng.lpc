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
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("qi", 13000);
    set("max_qi", 13000);
    set("jing", 13000);
    set("max_jing", 13000);
    set("neili", 13500);
    set("max_neili", 13500);
    set("jiali", 100);
	
    set("combat_exp", 13000000);
    set("score", 0);
    set_skill("force", 350);             // 基本内功
    set_skill("finger", 370);            // 基本指法
    set_skill("dodge", 350);             // 基本躲闪
    set_skill("parry", 350);             // 基本招架
    set_skill("liumai-shenjian", 380);   // 六脉神剑
    set_skill("taixuan-gong", 380);      // 太玄神功
    set_skill("lingxu-bu", 380);         // 凌虚步
    set_skill("literate",380);           // 读书识字
	
    map_skill("force"  , "taixuan-gong");
    map_skill("finger" , "liumai-shenjian");
    map_skill("dodge"  , "lingxu-bu");
    map_skill("parry"  , "liumai-shenjian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
	set("chat_chance_combat", 80);
 	 set("chat_msg_combat", ({
                (: perform_action, "finger.liumaijinhun" :),
        }) );



    prepare_skill("finger", "liumai-shenjian");

    create_family("大理段家", 17, "弟子");
    setup();

    carry_object("/clone/misc/cloth")->wear();
}
