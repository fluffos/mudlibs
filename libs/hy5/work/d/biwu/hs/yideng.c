// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("一灯大师", ({"yideng dashi", "dashi", "yideng"}));
    set("title", HIC "南帝" NOR );
    set("gender", "男性");
    set("age", 52);
    set("long", 
        "他就是号称「南帝」的一灯大师，俗名段智兴，现已逊位为僧。\n"
        "大师一生行善，积德无穷。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 60);
    set("int", 60);
    set("con", 66);
    set("dex", 60);
        set_temp("no_kill",1);
    set("qi", 39000);
    set("max_qi", 39000);
    set("jing", 39000);
    set("max_jing", 39000);
    set("neili", 50500);
    set("max_neili", 50500);
        set("jiali", 100);
        set("szj/passed",1);
//        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 50);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 580);
	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);
    set("combat_exp", 8500000);
    set("score", 0);
	 
        set_skill("unarmed", 400);
        set_skill("force", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("cuff", 400);
        set_skill("strike", 500);
        set_skill("sword", 500);
        set_skill("staff", 500);
        set_skill("finger", 400);
        set_skill("buddhism", 500);
	set_skill("kurong-changong", 500);
        set_skill("tiannan-step", 500);
        set_skill("jinyu-quan", 500);
        set_skill("wuluo-zhang", 500);
        set_skill("duanjia-sword", 500);
        set_skill("yiyang-zhi", 500);
        set_skill("six-finger", 350);
        set_skill("sun-finger", 500);
	set_skill("literate", 500);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("unarmed", "six-finger");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");

//	prepare_skill("cuff", "jinyu-quan");
//	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dragon" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "unarmed.liumaijingshen" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );

    setup();

carry_object("/p/item/ritemtz3/ahands13")->wear();
carry_object("/clone/misc/cloth")->wear();
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
if (me==ob){
me->set("qi",1);
me->set("eff_qi",1);
me->set("jing",1);
me->set("eff_jing",1);
}

if (me->query_temp("hsljn"))
{
me->set_temp("hslj/3",1);
message("channel:chat", "【华山论剑】听说"+me->name() + "打败了"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
       // me->add("combat_exp",300);
        //me->add("potential",100);
}
        destruct(ob);
        return;
}