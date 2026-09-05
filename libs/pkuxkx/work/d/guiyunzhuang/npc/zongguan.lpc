#include <ansi.h>
inherit NPC;

void create()
{
	set_name("总管",({"zong guan","zong","guan"}));
	set("gender", "男性");
	set("long","他看起来威风凛凛,他就是归云庄的管家.\n");
	set("age", 55);

	set("combat_exp",20000);
        set_skill("unarmed", 35);
        set_skill("force", 35);
	set_skill("parry",35);
	set_skill("dodge",30);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
	set("shen_type",1);
	setup();
}
int accept_object(object who,object ob)
{
	object pipe;
	pipe=new(__DIR__"obj/pipe");
	if((string)ob->query("name")=="烟斗"||(string)ob->query("id")=="yan dou")
		{	
			message_vision("总管交给$N一个"YEL"铜哨"NOR".\n",this_player());
			pipe->move(this_player());
			command("say 好吧，既然你给我拿回烟斗，我就给你一个铜哨吧。\n");		
			call_out("dest",1,ob);
			return 1;
		}
}
void dest(object ob)
{
	destruct(ob);
	return;
}

			
