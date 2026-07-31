#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);
void yun_zhao(); 

void create()
{
      string weapon;
        set_name("黑衣人", ({ "heiyi ren","ren"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个穿着黑色夜行衣的人。\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
           
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
	    set("chat_chance_combat", 50);
        set("chat_msg_combat", 
			({ 
             (: yun_zhao :),
            }));
     
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int flag)
{
        int i,j;
        object ob;
        ob = this_object();
        i = me->query_skill("dodge",1);
        j = me->query_skill("force",1);
        i = i>j?i:j;
		if(flag==0)
		i = i - random(20);
		else 
	    i = i + random(20);
        if( i < 60) i = 60;
   
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set("max_qi",     ob->query_skill("force")*6); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili",  ob->query_skill("force")*8); 
        ob->set("jiali", ob->query_skill("force")/6);
        ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
		call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
  destruct(me); 
  return 1;
}

void yun_zhao()
{	object me,weapon;
    mapping prepare;
    string attack_skill;
	me=this_object();
    prepare = me->query_skill_prepare();
	weapon=me->query_temp("weapon");
	if (!prepare) prepare = ([]);
    if ( sizeof(prepare) == 0) attack_skill = "unarmed";
	if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
	if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
	if ( weapon ) attack_skill = weapon->query("skill_type");
	attack_skill=me->query_skill_mapped(attack_skill);
    command("beizhao "+sprintf("%d",random(5)+1)+" "+
		               sprintf("%d",random(5)+1)+" "+
					   sprintf("%d",random(5)+1)+" for "+attack_skill);
	command("beizhao "+sprintf("%d",random(10)+1)+" "+
		               sprintf("%d",random(10)+1)+" "+
					   sprintf("%d",random(10)+1)+" for "+attack_skill);
    //command("beizhao 1 for shenghuo-lingfa");
//	me->set_temp("skill_name",me->query_skill_mapped(attack_skill));
//	me->set_temp("zhao_count",1);
//	me->set_temp("zhaoshu"+sprintf("%d",0),4);
	command("yunzhao");
}
void die()
{
	object corpse;
	mixed killer;
	if( !living(this_object()) ) revive(1);
	else delete_temp("faint_by");
	COMBAT_D->announce(this_object(), "dead");
	if( !(killer = query_temp("last_damage_from")) )
	killer = "莫名其妙地";
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());
	set_temp("last_damage_from", "莫名其妙地");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}
   



