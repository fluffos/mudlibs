 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("蓝一尘", ({ "master yichen", "master", "master lan" }) );
        set("nickname", HIC "神眼神剑"NOR);
        set("gender", "男性" );
        set("reward_npc", 1);
        set("difficulty", 40);
        set("no_heal",1);
        set("age", 54);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("agi",25);
        set("skill_public",1);
        
        set("attitude","friendly");
        set("max_neili", 15000);
        set("force", 15000);
        set("force_factor", 50);
        
        set("max_qi",99999999);
        set("max_jing",999999);
        set("max_jing",999999);
        set("eff_qi",999999);
        set("qi",999999);
        set("combat_exp", 10000000);
        set("score", 200000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "蓝一尘神色凝重望着密林深处，一字字道：大好男儿，当浴血锄奸，\n慨然踏死，杨铮啊杨铮，你放心去吧。蓝某绝不让人踏入密林半步。\n",
        }) ); 
        set("long",
"
这个人头戴着顶宽边竹笠，戴的很低。不但盖住了眉毛挡住了眼睛，
连一张脸都隐藏在竹笠的阴影里。一条左腿已经齐膝而断。
\n"
        ); 
        create_family("蓝山剑宗", 3, "宗主");
        
        set("收信",0);
        
      set("qi", 29000);
    set("max_qi", 29000);
    set("jing", 18000);
    set("max_jing", 18000);
    set("neili", 53500);
    set("max_neili", 53500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
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

        set("ranks",({"门人","剑奴","剑手","剑客","剑师",
                      "剑痴","剑侠","护法","大护法",
                      "长老","大长老","令主"}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
        setup();
        carry_object(__DIR__"obj/bluesword")->wield();
        carry_object(__DIR__"obj/shirt")->wear(); 
} 
 
 
int accept_object(object who, object ob)
{
if(ob->query("name") == "给蓝一尘的信" ) {
if(query("收信")) {
        message_vision(HIY"蓝一尘“哦”了一声，“怎么又来一个送信的，难道是假冒的不成？“\n",this_object());
        return 1;
}       
if(ob->query("送信人")==who)
{
    message_vision(HIY "蓝一尘“哦”了一声，拆开信来，阅罢喟然长叹不语。稍倾，向$N点了点头，道：
阁下实为信人，如不嫌弃，将来某或可传你我所学。不过现下还有件事情想请阁下
代劳。密林木屋乃杨铮亡父故居。杨铮发妻已独守三日未出，你可购些饭菜送去。\n"NOR,this_player()); 
        who->set_temp("libie/离别钩_送信成功",1);
        set("收信",1);
        return 1;
}
else
{
    say(HIR"蓝一尘冷冷的说：你这个狄青麟的走狗，想以假信骗我，却也没那么容易。\n"NOR);
        kill_ob(who);
        return 1;
}
}
return 0;
} 
int recognize_apprentice(object ob)
{
        if(ob->query("libie/离别钩_杀死狄青麟"))
                return 1;
}  
void reset()
{
        if(query("收信")) {
                add("收信",1);
                if (query("收信")>8) set("收信",0);
        }
}      
