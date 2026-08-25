//filename: /cmds/verbs/kill.c
// modified by fire on 21, march, 1998 
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// this need to add some limit
#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
mixed direct_kill_str(string str) {
	return 1;
}
mixed do_kill_str(string str)
{
	object o;
    mixed ret;
	write("杀人有犯王法，要练武就用fight吧。\n");
	return;
 
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("自己打自己？笑话。\n");
		return;
	}
	ret=FIGHT_D->can_fight(this_body(),o);
}
mixed * query_verb_info()
{
     return ({ ({"STR" }) });
}

/*
void beg_kill(object ob)
{
	this_body()->start_fight(ob);
}
void answer_kill(object ob)
{
	ob->targetted_action("$N对$T答到：“$r$m,吾岂惧汝哉。\n\n",this_body());
	call_out((:beg_kill:),1,ob);
}
void do_kill_liv(object ob)
{
    if (ob == this_body())     
	printf("要自杀得想个别的办法。\n");
    else
	{
	this_body()->targetted_action("$N对$T大吼一声：“$r$m,敢和$S大战三百回合吗？\n\n",ob);
	call_out((:answer_kill:),1,ob);
	}
}
void do_kill() 
{
	printf("你要杀谁呀？\n");
}
void do_kill_str(string str)
{
   mixed ob;
	write("杀人有犯王法，要练武就用fight吧。\n");
	return;
   ob=NORMAL_D->get_monster(this_body(),str);
   if(objectp(ob))
	do_kill_liv(ob);
   else
	   write("你要杀谁？\n");
}
mixed * query_verb_info()
{
   return ({ ({ "STR","", "LIV" }) });
}
 */