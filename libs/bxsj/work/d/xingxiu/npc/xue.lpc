#include <ansi.h>

inherit NPC;
string color,cname,info;
void create_weapon(object client);
void remove_serving(object me);

string ansi_convert(string str)
{
        str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);
        return str;
}

void create()
{
        set_name("薛烛", ({ "xue zhu", "xue", "zhu" }));
        set("gender", "男性");
        set("age",42);
	set("long","这是一位饱经风霜的中年大汉，只见他双手的拇指食指具已不见，只剩下六根手指。\n");
	set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("attitude", "friendly");
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        object  ob;

        add_action("do_ding", "make");
        add_action("do_yes","yes");
        add_action("do_no","no");
        ::init();
         if(interactive(ob = this_player()) && visible(ob))
                say("薛烛做了个鞠说道：这位"+RANK_D->query_respect(ob)+"请进。\n");
}

int do_ding(string str)
{
        object ob = this_object();
        object me = this_player();

	if(me->query_skill("staff", 1) < 50 || !me->query_skill_mapped("staff")){
		command("say 对不起，我现在手指已断，只能打些钢杖出来。\n");
		return 1;
	}
	me->delete_temp("xue/order");
	if(!(str) || sscanf(str, "%s %s",color,cname) != 2)
		return notify_fail("用 <make 武器颜色 武器名称> 来打造特殊钢杖。\n");
	if(ob->query_temp("serving")){
		command("say 对不起呀，我正忙着呢！\n");
		return 1;
	}
	ob->set_temp("serving",1);
	ob->start_call_out( (: call_other,this_object(), "remove_serving",ob :), 60 );

	cname = sprintf("%s%s",color,cname);
	cname = ansi_convert(cname);
	info = sprintf("\n钢杖的新名称是：%s\n",cname);
	message_vision(HIY"$N对着$n比画了半天，看来$N是想打造一根叫作"+cname+HIY"的新钢杖。\n"NOR, me, ob);
	command("nod");
	command("say 你确定了是要打造这根？"+info+GRN"  (确定请打<yes|no>)"NOR);
	me->set_temp("xue/order",1);
	return 1;
}

int do_yes()
{
	object me = this_player();
	if(me->query_temp("xue/order")){
		if(MONEY_D->player_pay(me,30000) == 1)   //weapon's price 3 gold
			create_weapon(me);
		else{
			remove_call_out("remove_serving");
			this_object()->delete_temp("serving");
			me->delete_temp("xue/order");
			return  notify_fail("你身上带的钱不够了！\n");
		}
		return 1;
	}
	return 0;
}
int do_no()
{
	object me = this_player();
	if(me->query_temp("xue/order")){
		this_object()->delete_temp("sreving");
		tell_object(me,"是吗？那你要重新打造什么样的兵器？\n");
		remove_call_out("remove_serving");
		me->delete_temp("xue/order");
		return 1;
	}
	return 0;
}

void create_weapon(object me)
{
        object ob = this_object();
        object weapon;
        int str,damage,weight;
        str = me->query_str();
        damage = str+random(15);

	if(damage >= 60) damage = 60;
        weapon = new("/clone/weapon/gangzhang");
        weapon->set("name",cname + NOR);
        weapon->set("long", "这是一根由薛烛打造的"+me->name()+"的"+weapon->query("name")+"。\n");
        weapon->set("value",0);
        weapon->set("no_drop",1);
        weapon->set("no_get",1);
        weight = random(weapon->query_weight() * 2 * str / 30 +1);
        weapon->set("weapon_prop/damage",damage);
        weapon->set_weight(weight);
        weapon->move(me);
        command("say 你的兵器打造好了。\n");
        message_vision("$N交给$n一柄新打造的"+weapon->query("name")+"。\n", ob,me);
        ob->delete_temp("serving");
        me->delete_temp("xue/order");
}

void remove_serving(object me)
{
	me->delete_temp("serving");
}
