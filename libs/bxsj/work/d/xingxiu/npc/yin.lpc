#include <ansi.h>

inherit NPC;

void create()
{
        object ob;
        set_name("尹克西", ({ "yin kexi", "yin", "kexi" }));
        set("title", "西域大贾");
        set("long", "他高鼻深目，曲发黄须，是个胡人，颈悬明珠腕带玉镯，
珠光宝器。是波斯大贾，世代贩卖珠宝。使一条镶金嵌玉
的黄金软鞭。
\n");
        set("gender", "男性");       
        set("age", 43);
        set("attitude","peaceful");
        set("str", 32);
        set("dex", 24);
        set("con", 26);
        set("int", 25);
        set("shen", -7000);
        set("env/wimpy", 60);
        set("unique", 1);

        set_skill("parry", 120);
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("whip", 120);
        set_skill("linji-zhuang", 120);       
        set_skill("huifeng-bian", 120);  
        set_skill("xiaoyaoyou", 120);
        set_skill("yingzhua-shou", 120);
        set_skill("hand", 120);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "yingzhua-shou");
        map_skill("whip", "huifeng-bian");
        prepare_skill("hand", "yingzhua-shou");
        set("combat_exp", 750000);

        set("max_qi", 2200);
        set("max_jing", 2000);
        set("eff_jingli", 1500);
        set("jiali", 50);
        set("inquiry", ([            
            "金轮法王" : "嘿嘿，我迟早会把那个老和尚的国师名号抢过来。", 
        ]));

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
            "尹克西眼睛向你斜望，嘴角边微微冷笑。\n",
            (: random_move :),
        }));
        if (clonep()) {
                ob = unew(BINGQI_D("jinlong-bian"));
                if (!ob) ob = unew(BINGQI_D("changbian"));
                ob->move(this_object());
                ob->wield();        
                carry_object(ARMOR_D("changpao"))->wear();
        }        
}

void kill_ob(object me)
{     object ob=this_object();
      command("hehe");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);         
      ::kill_ob(me);
}
