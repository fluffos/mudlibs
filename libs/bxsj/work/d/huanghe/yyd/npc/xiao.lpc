// xiao.c 萧半和
// zly 99.6.11

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("萧半和", ({"xiao banhe", "banhe", "xiao"}));
        set("gender", "男性");
        set("title", HIY"晋阳大侠"NOR);
        set("shen_type", 1);
        set("age", 50);
        set("long", 
"这便是天下知名的晋阳大侠萧半和，他躯体雄伟，满腮虬须，长袍
马褂，极是威武。\n"
        );
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 26);

        set("max_qi", 2000);
        set("qi", 2000);
        set("eff_jingli", 1800);
        set("max_jing", 2000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 80);

        set("combat_exp", 1000000);
        
        set_skill("force", 180);             // 基本内功
        set_skill("huntian-qigong", 180);    // 混天气功
        set_skill("strike", 180);            // 基本掌法
        set_skill("xianglong-zhang", 180);   // 降龙十八掌
        set_skill("dodge", 180);             // 基本躲闪
        set_skill("xiaoyaoyou", 180);        // 逍遥游
        set_skill("parry", 180);             // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
	prepare_skill("strike","xianglong-zhang");

        set("chat_chance", 3);
        set("chat_msg", ({
            "萧半和冷哼一声，说道：“你们这些狗腿子别想拿到鸳鸯刀。”\n",
            "萧半和叹了一口气，说道：“我这个女儿呀，真是调皮，不知道这一次能不能改改。”\n", 
        }) );

        set("inquiry", ([
        "鸳鸯刀" : "听说里面藏有天下无敌的秘密。\n",
        "萧中慧" : "那是我的乖女儿。她现在正在练功呢，说完，呵呵地笑了起来。\n",
        "袁冠男" : "那是我的乖女婿。说完，露出慈祥的笑容。\n",
        "太岳四侠" : "他们现在帮忙守着后山呢，你有什么事情吗？\n",
        ]));

        setup();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",1);
}
