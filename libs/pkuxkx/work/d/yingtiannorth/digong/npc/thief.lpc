// By Zine
               
#include <ansi.h> 
inherit NPC; 
int is_KARMA_THIEF()
{
	return 1;
}
void check_surrounds()
{
	int caution=0;
	object ob=this_object(),env=environment(ob);
	string *dirs,*can_go=({});
	if (!env) return;
	dirs=keys(env->query("exits"));
	if (member_array("out",dirs)!=-1)
	dirs-=({"out"});
	for (int i=0;i<sizeof(dirs);i++)
	{
		if (load_object(env->query("exits/"+dirs[i]))->query("player_num"))
		caution=1;
		else
		can_go+=({dirs[i]});
	}
	if (sizeof(can_go)<1)
	{
		command("bd");
		command("bd 你们人多，我认输还不行吗？");
		load_object("/d/yingtiannorth/digong/level3exit")->set("allow_pass",1);
		message_vision("$N远远地离开了。\n",ob);
		destruct(ob);
		return;
	}
	if (caution)
	command("go "+can_go[random(sizeof(can_go))]);
	remove_call_out("check_surrounds");
	call_out("check_surrounds",1);
	return;
}
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        
	set("long",
	"他是一个神秘的人物，穿着一身夜行衣。\n"
         );
	set("title",YEL"蟊贼"NOR);
	set("gender", "男性");
	
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
	set("qi", 1000);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("uni_target",1);
	setup();
	carry_object("/d/yingtiannorth/npc/obj/night_cloth")->wear();
	carry_object("/d/city/obj/silk_mask")->wear();
	call_out("check_surrounds",1);
}