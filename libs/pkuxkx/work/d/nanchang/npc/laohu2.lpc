
#include <ansi.h>

inherit NPC;

void die();
void consider();
int kill_target();

void create()
{
	string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", "男性" );
	set("age", 22+random(22));
	set("long", "这是一个披着虎皮的怪人，看上去杀气腾腾的样子。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("random_npc",1);
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
                (: consider() :)
        }) );
    set("ningxue", 1);
	setup();
    carry_object("/d/nanchang/obj/cloth")->wear();
	
	call_out("kill_target",10);
}

int do_copy(object me)
{
	object ob=this_object();
    int i;
	int exp,exp2,lv;
    lv=100;
    if(!objectp(me))
		return 0;
	set("uni_target", me);
    exp = me->query("combat_exp");
	exp2=exp/100;
	while (lv*lv*lv<exp2)
	{
		lv=lv+10;
	}
    lv=lv*10;
	ob->set_skill("literate", lv);
    ob->set_skill("force", lv);
    ob->set_skill("dodge", lv);
    ob->set_skill("parry", lv);
    ob->set_skill("whip", lv);
    ob->set_skill("sword", lv);
    ob->set_skill("hand", lv);
    ob->set_skill("claw", lv);
    ob->set_skill("cangming-gong", lv);
    ob->set_skill("danxin-jian", lv);
    ob->set_skill("lingding-piao", lv);
    ob->set_skill("jiulong-bian", lv);
    ob->set_skill("fulong-shou", lv);
    ob->set_skill("yunlong-zhua", lv);
    ob->map_skill("dodge", "lingding-piao");
    ob->map_skill("force", "cangming-gong");
    ob->map_skill("hand", "fulong-shou");
    ob->map_skill("parry", "danxin-jian");
    ob->map_skill("claw", "yunlong-zhua");
    ob->map_skill("sword", "danxin-jian");
    ob->map_skill("whip", "jiulong-bian");
    ob->prepare_wskill("sword","danxin-jian");
    ob->prepare_wskill("whip","jiulong-bian");
    ob->prepare_skill("hand","fulong-shou");
    ob->prepare_skill("claw","yunlong-zhua");
    
    set("max_qi", me->query("max_qi")*3/2);
	set("eff_qi", me->query("max_qi"));
	set("qi", me->query("max_qi"));
	set("max_jing", me->query("max_qi"));
	set("eff_jing", me->query("max_qi"));
	set("jing", me->query("max_qi"));
	set("max_jingli", me->query("max_qi"));
	set("jingli", me->query("max_qi"));
	set("max_neili", me->query("max_qi"));
	set("neili", me->query("max_qi"));
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
                case 0:
                        command("perform hand.fuxue " + target->query("id"));
                        break;
                case 1: 
                        command("perform claw.ningxue " +target->query("id"));             
                        break;
        }
}

void die()
{
	object me = query("uni_target");
    object ob = this_object();
    int reward,pot;
    if (me)
    {
        
        message_vision("$N大喝一声，终于死去。\n",ob);
        if (!me->query("zhuangquest"))
        {
            me->set("zhuangquest",1);
            me->set_temp("zhuangquest",1);
            reward=(me->query("kar")*50+random(1000))*(4+random(3));
            reward=REWARD_D->add_exp(me,reward);
            pot=REWARD_D->add_pot(me,reward);
            tell_object(me,HIG+"杀死"+ob->query("name")+"后你获得了：\n");
            tell_object(me,"\t"+chinese_number(reward)+"点经验；\n");
            tell_object(me,"\t"+chinese_number(pot)+"点潜能；\n"NOR);
            tell_object(me,"也许，你可以去找长老领赏了。\n");
        }
    }
	::die();	
}



int visible(object ob)
{
    if(query("uni_target") != ob) return 0;
    return 1;
}

int kill_target()
{
	object target = query("uni_target");
	if(objectp(target))
	{
		command("kill "+target->query("id"));
	}
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}

