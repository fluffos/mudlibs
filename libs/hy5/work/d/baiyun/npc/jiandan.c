 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("剑胆" , ({ "jian dan","jian" }) );
    set("nickname",HIG"漱清泉"NOR);
    set("long", "一袭白衣迎风而振，散发击剑而歌，腰间随意挂着一个汉白玉的葫芦，徐徐的\n海风中荡漾着醉人的酒香。\n");
        set("attitude", "friendly");
    set("age", 32);
        set("gender", "男性" );
        create_family("白云城",1, "狂生");
            set("neili",15000);
        set("max_neili",15000);
        set("max_qi",15000);
        set("max_jing",15000);
        set("jing",15000);
        set("qi",15000);
    set("per",40);
    set("combat_exp", 3000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "剑胆举起青葫芦饮了几口，铺开宣纸，笔走龙蛇，曼声长吟：往日书剑江湖，\n
长街奔马。今日明月醇酒，高山流水。快哉！\n",
        "剑胆击剑放歌：五花马，千金裘，呼儿将出换美酒，与尔同销万古愁！\n",
        }) );
set_skill("dodge", 200);
    set_skill("feixian-steps", 500);
    set_skill("feixian-sword", 500);
    set_skill("sword", 200);
    set_skill("unarmed", 100);


    map_skill("dodge","feixian-steps");
    map_skill("sword","feixian-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}     
