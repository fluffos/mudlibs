
#include <ansi.h>
inherit NPC;
void dest()
{
	object ob=this_object();
	if (environment())
	{
		if (ob->query("owner")&&objectp(ob->query("owner"))&&query("pin")==ob->query("owner")->query_temp("gongsun/pin"))
		tell_object(ob->query("owner"),"你突然心里泛起一丝不祥的预感，也许永远都找不到绝情谷失踪的弟子了。\n");
		if (ob)
		{
			message_vision("$N突然变成了一摊黄水。\n",ob);
			destruct(ob);
		}
	}
}
void create()
{
	int i=random(2);
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=i?NAME_D->create_name():NAME_D->create_female_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"弟子"+NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", i?"男性":"女性");
	set("age", 20+random(10));
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("random_npc",1);
	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();
	call_out("dest",210);
}
void owner(object me)
{
	set("owner",me);
	set("pin",me->query_temp("gongsun/pin"));
}
int to_die(object me)
{
	object ob;
	if (environment(me)==environment())
	{
		message_vision("$N看着$n，似乎有很多话要说……\n",this_object(),me);
		tell_object(me,"仔细查看(chakan)"+this_object()->name()+"的伤势，也许能发现什么。\n");
	}
	message_vision("$N头一歪，就死在了这里。\n",this_object());
	ob=new(__DIR__"corpse");
	ob->set("owner",me);
	ob->set_corpse(this_object());
	ob->move(environment());
	destruct(this_object());
	return 1;
}
void init()
{
	object me=this_player();
	if (me==query("owner"))
	{
		command("ah");
		call_out("to_die",1,me);
	}
}