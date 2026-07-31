#include <ansi.h>
inherit NPC;
//inherit F_MASTER;


void create()
{
    set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
        set("long", 
                "他就是桃花岛的岛主，江湖上人人闻名变色的东邪黄药师。\n"
                "他身穿一件青色长袍，腰带上斜插着一只玉箫。\n"
                "他形相清癯，丰姿隽爽，萧疏轩举，湛然若神。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 51);
    set("int", 50);
    set("con", 56);
    set("dex", 50);
        set_temp("no_kill",1);
    set("chat_chance", 1);
    set("chat_msg", ({
        "黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
        "黄药师低头沉思，悠然不语。\n",
    }));
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 200);
	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);
    set("qi", 36000);
    set("max_qi", 36000);
    set("jing", 36000);
    set("max_jing", 36000);
    set("neili", 43500);
    set("max_neili", 43500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 8500000);

	 
    set_skill("leg", 500);             // 基本内功
    set_skill("force", 500);             // 基本内功
    set_skill("bibo-shengong", 500);     // 碧波神功
    set_skill("claw", 500);              // 基本爪法
    set_skill("hand", 500);              // 基本手法
    set_skill("finger", 500);            // 基本指法
    set_skill("tanzhi-shentong", 500);   // 弹指神通
    set_skill("unarmed", 500);           // 基本拳脚
    set_skill("strike", 500);            // 基本拳脚
    set_skill("luoying-zhang", 500);     // 落英神剑掌
    set_skill("xuanfeng-leg", 500);      // 旋风扫叶腿
    set_skill("dodge", 500);             // 基本躲闪
    set_skill("anying-fuxiang", 500);    // 暗影浮香
    set_skill("parry", 500);             // 基本招架
    set_skill("sword", 500);             // 基本剑法
    set_skill("luoying-shenjian", 500);  // 落英神剑
    set_skill("yuxiao-jian", 500);       // 玉箫剑法
    set_skill("lanhua-shou", 500);       // 兰花拂穴手
    set_skill("qimen-wuxing",500);       // 奇门五行
    set_skill("count",500);              // 阴阳八卦
    set_skill("literate",500);           // 读书识字
	
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "yuxiao-jian");
    map_skill("sword"  , "yuxiao-jian");
//	prepare_skill("finger", "tanzhi-shentong");
//	prepare_skill("hand", "lanhua-shou");
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.wuyin" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
//    create_family("桃花岛", 1, "岛主");
    setup();
	
    carry_object("/p/item/ritemtz3/wsword13")->wield();
    carry_object("/kungfu/class/taohua/obj/bupao")->wear();
//    carry_object("clone/book/jiuyin2");
    
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",HIG"比武结束！\n\n"
		+ name() + HIG"身形一闪，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void unconcious()
{
die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
if (me==ob)
{
me->set("qi",1);
me->set("eff_qi",1);
me->set("jing",1);
me->set("eff_jing",1);
}

if ( me->query_temp("hsljn"))
{
me->set_temp("hslj/1",1);
message("channel:chat", "【华山论剑】听说"+me->name() + "打败了"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        //me->add("combat_exp",300);
        //me->add("potential",100);
}
        destruct(ob);
        return;
}