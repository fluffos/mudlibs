#include <ansi.h>
inherit NPC;
string interpret(object ob);
int check_me(object me,string *codes,int flag)
{
	int count=0;
	object ob,*obj=({}),*inv=all_inventory(me);
	if (!me->query_temp("allow_exchange"))
	{
		command("say 给一两金子先！");
		return 1;
	}
	for (int j=0;j<sizeof(codes);j++)
	for (int i=0;i<sizeof(inv);i++)
	if (interpret(inv[i])==codes[j])
	{
		count+=1;
		obj+=({inv[i]});
		if (wizardp(me))
		tell_object(me,"count:"+count+" "+inv[i]->query("name")+"\n");
		break;
	}
	if (count<sizeof(codes))
	return 0;
	else
	{
		for (int k=0;k<sizeof(obj);k++)
		destruct(obj[k]);
		ob=new("/obj/vein/dan"+flag);
		ob->move(me);
		tell_object(me,this_object()->query("name")+"给你一"+ob->query("unit")+ob->query("name")+"。\n");
		me->delete_temp("allow_exchange");
		return 1;
	}
}
int ask_dan()
{
	object me=this_player();
	string *codes=({"#3#gu","#2#jin","*9"});
	if (!check_me(me,codes,1)) 
	{
		command("say 需要水神龙骨、山精金和合欢，找齐再来吧。");
	}
	return 1;
}
int ask_dan2()
{
	object me=this_player();
	string *codes=({"#3#jia","#4#bing","*5"});
	if (!check_me(me,codes,2)) 
	{
		command("say 需要水玄武甲、风玄冰和当归，找齐再来吧。");
	}
	return 1;
}
void create()
{
	set_name("海小超", ({ "hai xiaochao", "hai" }));
	set("title", "无商不奸");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
        set("long", "在玩家没有掌握炼丹术之前，做做倒手工作，整点零花钱。\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("inquiry", ([
			"凝元丸" : (: ask_dan :),
            "凝真丹" : (: ask_dan2 :),
			]));
	setup();
    carry_object("/clone/armor/cloth")->wear();
        add_money("silver", 10);
        //add_money("gold", 1);
}

string interpret(object ob)
{
	int code;
	if (ob->query("drugcode"))
	return "*"+ob->query("drugcode");
	else if (ob->is_gem())
	return "#"+ob->query("level")+"#"+ob->query("material");
	else
	return "other";
}

int accept_object(object who, object ob)
{       
	if (ob->query("money_id") && ob->value() >= 10000) 
	{
        who->set_temp("allow_exchange",1);
		ob->move(VOID_OB);
		destruct(ob);
		command("thank");
		return 1;
	}
}

