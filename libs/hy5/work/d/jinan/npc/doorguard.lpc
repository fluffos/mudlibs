#include <ansi.h> 
inherit NPC;
int give_guard();
void create()
{
        set_name("殷羡", ({ "yinxian" }) );
        set("long",
                "一个锦衣华服的带刀侍卫，也是钦差大人殷正廉的远方侄儿。
殷大人命其负责济南府众侍卫调度,朝廷将领可向他征召护卫(guard).\n"); 
        set("attitude", "heroism");
        set("title", "朝廷命官 四品带刀侍卫");
        set("vendetta_mark","authority");
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("cor", 26);
        set("cps", 55); 
        set("combat_exp", 5000000); 
        set_skill("unarmed", 150+random(500));
        set_skill("blade", 100+random(500));
        set_skill("parry", 100+random(500));
        set_skill("dodge", 100+random(500));
        set_skill("move", 100+random(500));
        set_skill("qiusheng-blade",150);
        set_skill("liuquan-steps",150); 
        map_skill("parry","qiusheng-blade");
        map_skill("blade","qiusheng-blade");
        map_skill("dodge","liuquan-steps");
        map_skill("move","liuquan-steps"); 
        set_temp("apply/damage", 200+random(200));
        set_temp("apply/armor", 200); 
        set("chat_chance", 1);
        set("chat_msg", ({
"殷羡眼睛里闪着光，苦笑道：后天便是叶孤城与西门吹雪决战紫禁城之\n日。哎！可殷大人却丢了尚方宝剑，实在又离开不得。。。\n"
        }) ); 

    setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
    carry_object(__DIR__"obj/peidao")->wield();
} 
