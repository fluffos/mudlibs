// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void consider();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("title", HIG"北丐"NOR);
	set("gender", "男性");
	set("age", 75);
set("beggarlvl",9);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 60);
	set("int", 64);
	set("con", 60);
	set("dex", 64);

	set("chat_chance", 1);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
	}));
	set("qi", 19000);
	set("max_qi", 19000);
	set("jing", 19400);
	set("max_jing", 19400);
	set("neili", 68000);
	set("max_neili", 68000);
	set("jiali", 500);
	        set_temp("no_kill",1);
	set("combat_exp", 5000000);
	set("score", 500000);
	set("shen", 100000);
	         set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over500", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        set("xlz/hang", 1);
         set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
	set_skill("force", 500);             // 基本内功
	set_skill("huntian-qigong", 500);    // 混天气功
	set_skill("unarmed", 500);           // 基本拳脚
	set_skill("xianglong-zhang", 500);   // 降龙十八掌
	set_skill("dodge", 500);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 450);        // 逍遥游
	set_skill("parry", 500);             // 基本招架
	set_skill("staff", 500);             // 基本棍杖
	set_skill("dagou-bang", 500);        // 打狗棒法
	set_skill("begging", 500);           // 叫化绝活
	set_skill("checking", 550);          // 道听途说
	set_skill("training", 550);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.zhuang" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.duo" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
	setup();
	
    carry_object("/kungfu/class/gaibang/obj/yuzhu_zhang")->wield();
    carry_object("/kungfu/class/gaibang/obj/jiaohuaji");
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

if (me->query_temp("hsljn"))
{
me->set_temp("hslj/2",1);
message("channel:chat", "【华山论剑】听说"+me->name() + "打败了"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        //me->add("combat_exp",300);
        //me->add("potential",100);
}
        destruct(ob);
        return;
}
