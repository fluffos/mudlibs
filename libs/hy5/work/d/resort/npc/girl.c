 // girl.c
inherit NPC; 
void create()
{
        set_name("小翠", ({ "xiao cui", "cui", "xiao" }) );
        set("class","legend");
        set("gender", "女性" );
        set("age", 15);
        set("str", 10);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27); 
        set("attitude", "peaceful"); 
        set("max_neili", 100);
        set("force", 100);
        set("force_factor", 10); 
        set("long",     "小翠是铁雪山庄的丫环，经常偷吃茶园里的糕点。\n");  
        set("combat_exp", 100000); 
      set_skill("leg", 380);             // 基本内功
    set_skill("force", 280);             // 基本内功
    set_skill("bibo-shengong", 380);     // 碧波神功
    set_skill("claw", 200);              // 基本爪法
    set_skill("hand", 320);              // 基本手法
    set_skill("finger", 320);            // 基本指法
    set_skill("tanzhi-shentong", 380);   // 弹指神通
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("strike", 280);            // 基本拳脚
    set_skill("luoying-zhang", 380);     // 落英神剑掌
    set_skill("xuanfeng-leg", 380);      // 旋风扫叶腿
    set_skill("dodge", 280);             // 基本躲闪
    set_skill("anying-fuxiang", 380);    // 暗影浮香
    set_skill("parry", 200);             // 基本招架
    set_skill("sword", 320);             // 基本剑法
    set_skill("luoying-shenjian", 380);  // 落英神剑
    set_skill("yuxiao-jian", 380);       // 玉箫剑法
    set_skill("lanhua-shou", 380);       // 兰花拂穴手
    set_skill("qimen-wuxing",380);       // 奇门五行
    set_skill("count",380);              // 阴阳八卦
    set_skill("literate",380);           // 读书识字
	  set_skill("chixin-jian", 380);             // 基本内功
    set_skill("canglang-bian", 380);             // 基本内功
    set_skill("whip", 380);             // 基本内功
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));

        setup(); 
        carry_object(__DIR__"obj/thin_sword")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
} 
      
