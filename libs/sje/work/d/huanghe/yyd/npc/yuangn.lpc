// yuangn.c 袁冠男
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();

void create()
{
        object ob;
        set_name("袁冠男", ({ "yuan guannan", "yuan", "guannan"}));
        set("gender", "男性");
        set("unique", 1);
        set("age", 22);
        set("long", "他是一个英俊的少年书生，手中轻轻摇着折扇。\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 4000);
        set("qi", 4000);
        set("jing",1600);
        set("eff_jing", 1600);
        set("jingli", 2200);
        set("eff_jingli", 2200);
        set("neili", 5000);
        set("max_neili", 5000);
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

        set("chat_chance", 3);
        set("chat_msg", ({
            "袁冠男长声吟到：“黄金逐手快意尽，昨日破产今朝贫，丈夫何事空啸傲？不知烧却头上巾......”\n",
            "袁冠男纵声长吟：“天子重英豪，文章教尔曹，万般皆下品，唯有读书高......”\n", 
        }) );

        set("inquiry", ([
//           "夫妻刀法"  : (: ask_yyd :),
        ]));

        setup();
        if (clonep()) {
                ob = unew(__DIR__"obj/yuan");
                if (!ob) ob = new(BINGQI_D("blade"));
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",2);
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
        me->set_temp("mb",1);
        command("hmm");
        command("whisper "+me->query("id")+" 听师父师母说，教他们刀法的高僧圆寂在极南的小岛上。");
        return "这夫妻刀法，是当年一位高僧传给我的师父的，你如果真有信心和毅力，就去找那位高僧吧！\n";
}
*/
