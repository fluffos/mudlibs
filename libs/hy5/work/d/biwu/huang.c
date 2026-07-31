#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
    set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "桃花岛主");
    set("nickname", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long", 
        "他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 121);
    set("int", 130);
    set("con", 126);
    set("dex", 130);
    set("per", 130);

    set("chat_chance", 1);
    set("chat_msg", ({
        "黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
        "黄药师低头沉思，悠然不语。\n",
    }));
    set("inquiry", ([
        "黄蓉"     : "你敢直称我女儿的闺名？ \n",
        "九阴真经" : "如果你能帮我取得真经上册，我一定重重谢你。\n",
    ]));

    set("qi", 355000);
    set("max_qi", 355000);
    set("jing", 353000);
    set("max_jing", 353000);
    set("neili", 353500);
    set("max_neili", 353500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 19500000);
    set("score", 0);
	         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
    set_skill("leg", 1200);             // 基本内功
    set_skill("force", 1000);             // 基本内功
    set_skill("bibo-shengong", 980);     // 碧波神功
    set_skill("claw", 1200);              // 基本爪法
    set_skill("hand", 1200);              // 基本手法
    set_skill("finger", 1200);            // 基本指法
    set_skill("tanzhi-shentong", 980);   // 弹指神通
    set_skill("unarmed", 1200);           // 基本拳脚
    set_skill("strike", 1200);            // 基本拳脚
    set_skill("luoying-zhang", 980);     // 落英神剑掌
    set_skill("xuanfeng-leg", 980);      // 旋风扫叶腿
    set_skill("dodge", 1200);             // 基本躲闪
    set_skill("anying-fuxiang", 980);    // 暗影浮香
    set_skill("parry", 1000);             // 基本招架
    set_skill("sword", 1000);             // 基本剑法
    set_skill("luoying-shenjian", 980);  // 落英神剑
    set_skill("yuxiao-jian", 980);       // 玉箫剑法
    set_skill("lanhua-shou", 980);       // 兰花拂穴手
    set_skill("qimen-wuxing",980);       // 奇门五行
    set_skill("count",1150);              // 阴阳八卦
    set_skill("literate",1250);           // 读书识字
	
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "yuxiao-jian");
    map_skill("sword"  , "yuxiao-jian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
  set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.tianwai" :),                
                (: perform_action, "sword.yuxiao" :),                
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
    set("inquiry", ([
        "秘籍" : (: ask_me :),
        "旋风扫叶腿法" : (: ask_me :),
    ]));


    create_family("桃花岛", 1, "岛主");
    setup();
	
    //carry_object(__DIR__"obj/yuxiao")->wield();
    carry_object(__DIR__"obj/bupao")->wear();
    carry_object("/p/item/ritemtz3/wsword18")->wield();
    carry_object("/p/item/ritemtz3/ahands19")->wear();
   // carry_object("clone/book/jiuyin2");
    
}

