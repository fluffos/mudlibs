#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("nickname",random(2)?"疑犯":"线人");
	set("gender", "男性");
    set("attitude","heroism");
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
	set("inquiry", ([
	
		 "问话": (: ask_me :),
		 "yourself": (: ask_me :),
		]));
	setup();
}
int ask_me()
{
	int i;
	object me=this_player(),ob=this_object();
	if (me->query_temp("songtasks/yushitai/task")!=1)
	{
		return notify_fail("在御史台，没御史中丞的手令，谁也不得过问任何事情。\n");
	}
	if (ob->query("player")!=me)
	{
		return notify_fail(ob->name()+"不是你提堂的证人或嫌犯。\n");
	}
	message_vision("$N对$n道：“快把你知道的都交代清楚。”\n",me,ob);
	i=random(2);
	if (random(100)>49)
	{
		command("say 小人不是"+ob->query("not_place")[i]+"人士。");
	}
	else 
	{
		command("say 小人不是"+ob->query("not_do")[i]+"的。");
	}
	return 1;
}