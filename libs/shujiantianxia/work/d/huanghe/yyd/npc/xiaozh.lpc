// xiaozh.c 萧中慧
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();

void create()
{
        object ob;
        set_name("萧中慧", ({ "xiao zhonghui", "xiao", "zhonghui"}));
        set("gender", "女性");
        set("unique", 1);
        set("age", 20);
        set("long", "
她是晋阳大侠萧半和的女儿，她容貌娇美，神色中散发着一股勃勃英气。\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 3000);
        set("qi", 3000);
        set("jing",1600);
          set("max_jing", 1600);
        set("jingli", 2200);
        set("eff_jingli", 2200);        
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 50);

        set("combat_exp", 1500000);
        
        set_skill("force", 180);             // 基本内功
        set_skill("huntian-qigong", 180);    // 混天气功
        set_skill("blade", 180);             // 基本刀法
        set_skill("wuhu-duanmendao", 190);
//      set_skill("fuqi-daofa", 180);        // 夫妻刀法
        set_skill("dodge", 180);             // 基本轻功
        set_skill("xiaoyaoyou", 180);        // 逍遥游
        set_skill("parry", 180);             // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");

        set("inquiry", ([
            "太岳四侠" : "那是四个活宝。说完，已经笑得腰都弯了。\n",
            "袁冠男" : "你认识袁大哥？袁大哥现在在哪里？说完，脸唰地红了起来。\n",
            "萧半和" : "爹爹马上就要过五十大寿了，发了很多英雄帖呢。你有吗？\n",
//          "夫妻刀法"  : (: ask_yyd :),
        ]));

        set("chat_chance", 3);
        set("chat_msg", ({
            "萧中慧忽然满脸红晕，低声念道：“清风引屋佩瑶台，明月照状成金屋。”\n",
            "萧中慧低声说道：“过两天就是爹爹的寿诞了，该送什么礼物呢？”\n", 
        }) );

        setup();
        if (clonep()) {
                ob = unew(__DIR__"obj/yang");
                if (!ob) ob = new(BINGQI_D("blade"));
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/red-cloth")->wear();

}
}

/*string ask_yyd()
{
        object me=this_player();
        if(me->query_skill("blade", 1) <120)
                return "你先把刀法的基础打好再说吧。\n";
        if(me->query("fuqi"))
                return "咦，你不是已经学到了夫妻刀法了吗？\n";
        if(me->query_temp("mb"))
                return "咦，我不是刚才告诉你了吗？\n";
        command("blush");
        return "这夫妻刀法，是当年师母传给我的。\n";
}
*/
