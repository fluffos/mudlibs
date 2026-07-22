#include <ansi.h>

void die()
{
	object who;
	if( environment() )
	{
		if( environment()->is_sea() )
			message("vision","\n一道巨浪打来，"+name()+"躲闪不及，被浪花卷的无影无踪！\n\n",environment());
		else	message("vision","\n"+name()+"叹了一口气，衣袖一甩，架起祥云急匆匆离去了！\n\n",environment());	
	}
	who = query("owner");
	if( who && who->query_temp("pendding/fc_visite")
    	 && !who->is_knowing("puti_panlong") 
    	 && !who->query_temp("pendding/fc_visite_wzg")
    	 && !who->query_temp("pendding/fc_visite_sea")
    	 && !who->query_temp("pendding/baxian_sea") )
	{
		command("chat* sigh "+geteuid(who));
		who->set("family/guanli_baxian_fail",time());
		tell_object(who,HIY"【灵台观礼】八仙过海：你没有成功调解八仙与敖广之间的恩仇，任务失败了！\n"NOR);
		who->delete_temp("pendding/wzg_baxian1");
		who->delete_temp("pendding/wzg_baxian2");
		who->delete_temp("pendding/wzg_baxian3");
		who->delete_temp("pendding/wzg_baxian4");
		who->delete_temp("pendding/wzg_baxian5");
		who->delete_temp("pendding/wzg_baxian6");
		who->delete_temp("pendding/wzg_baxian7");
		who->delete_temp("pendding/wzg_baxian8");
		who->delete_temp("pendding/wzg_sea1");
		who->delete_temp("pendding/wzg_sea2");
		if( environment(who)->is_sea() )
			environment(who)->remove_room();
	}
	destruct(this_object());
}	

void unconcious()
{
	die();
}

void drug_me(string file)
{
	object ob;
	if( ob=carry_object(file) )
		command("eat "+geteuid(ob));
	command("exert recover");
	command("exert refresh");
}

int accept_object(object who,object obj)
{
	string file;
	if( obj->query("name")!="金创药" 
	 && obj->query("name")!="混元丹" )
		return 0;
	EMOTE_D->do_emote(this_object(), "thank",geteuid(who),CYN,0,0,0);
	file = base_name(obj);
	call_out("drug_me",2,file);
	return 1;
}