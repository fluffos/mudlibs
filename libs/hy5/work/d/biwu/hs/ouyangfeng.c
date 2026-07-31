//ouyangfeng.c

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
		   +"由于习练「九阴真经」走火入魔，已变得精\n"
		   +"神错乱，整日披头散发。\n");
	set("gender", "男性");
	set("age", 53);
	set("title", HIR "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

	set("str", 60);
	set("int", 69);
	set("con", 60);
	set("dex", 68);
        set_temp("no_kill",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over500", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 300);
        	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);
	set("qi", 39500);
	set("max_qi", 39500);
	set("jing", 36900);
	set("max_jing", 36900);
	set("neili", 68000);
	set("max_neili", 68000);
	set("jiali", 150);
	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);
	set("combat_exp", 8500000);
	set("score", 500000);

	set_skill("force", 500);
	set_skill("unarmed", 450);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",270);
	set_skill("hand",270);
	set_skill("training",500);
	set_skill("staff", 500);
	set_skill("hamagong", 500);
	set_skill("chanchu-bufa", 500);
	set_skill("shexing-diaoshou", 500);
	set_skill("lingshe-zhangfa", 500);
	set_skill("hamashengong", 500);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.chanshen" :),                
                (: perform_action, "hand.huixuan" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "dodge.chanfei" :),                              
        }) );
        set("chat_chance",2);
        set("chat_msg",({
         "欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
         "欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
         "欧阳锋道：江湖险恶，困难重重哪！\n",
        }));
	setup();
carry_object("/p/item/ritemtz3/wstaff10")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",50);
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
me->set_temp("hslj/4",1);
message("channel:chat", "【华山论剑】听说"+me->name() + "打败了"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        //me->add("combat_exp",300);
        //me->add("potential",100);
}
        destruct(ob);
        return;
}