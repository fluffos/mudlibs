// zombie.c
#include <ansi.h>
inherit NPC;

void copy_status(object me, object ob);
void invocation(object me, object who);

void create()
{
	set_name("僵尸", ({ "zombie" }) );
	set("long","这是一具被人用符咒控制的僵尸，从它苍白的脸上看不出任何喜怒哀乐。\n");
	set("max_kee", 500);
	set("max_sen", 500);
	set("max_mana", 200);
	set("mana", 200);
	set("max_force", 200); 
	set("force", 200);
	set("age", 50);
	set("str", 25);
	set("cor", 30);
	set("chat_chance", 15);
	set("chat_msg_combat", 
	({
        	"僵尸口中发出荷荷的叫声。\n",
        	"僵尸的脸上开始痉挛，一阵抽搐，发狂似地大叫。\n",
        	"僵尸五指箕张，咬牙切齿，露出狰狞的笑容。\n",
	}) );
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_temp("apply/damage", 15);
	setup();
}

void init()
{
	add_action("do_release", "release");
}

int do_release()
{
	object who=this_player();

	if( who != this_object()->query("possessed") )
        	return 0;
	message_vision("$N向$n挥了挥手，$n慢慢地走开了。\n", who, this_object());
	destruct( this_object() );
	return 1;
}

int is_zombie() { return 1; }

void animate(object who,int time)
{
	object me=this_object();
	set("possessed", who);
	set("zombine",([
        	"start" : time(),
        	"time"  : time,
	]));
	copy_status(me, who);
	invocation(me, who);
	set_follow(who);
}

void copy_status(object me, object ob)
{
	mapping skill_status,map_status;
	string *sname,*mname;
	int i;

	skill_status=me->query_skills();
	sname=keys(skill_status);
	for(i=0;i<sizeof(skill_status);i++) 
        	me->delete_skill(sname[i]);

	skill_status=ob->query_skills();
	sname=keys(skill_status);
	for(i=0;i<sizeof(skill_status);i++) 
        	me->set_skill(sname[i],skill_status[sname[i]]);
	if( mapp(map_status = me->query_skill_map()) ) 
        {
        	mname  = keys(map_status);
        	for(i=0; i<sizeof(map_status); i++) 
	                me->map_skill(mname[i]);
        }
	map_status = ob->query_skill_map();
	mname  = keys(map_status);
	for(i=0; i<sizeof(map_status); i++) 
        	me->map_skill(mname[i], map_status[mname[i]]);
	
	me->set_level(ob->query_level()*4/5);
	me->setup();
	me->powerup();
}

void invocation(object me, object who)
{
	int i;
	object *enemy;

	message_vision(HIY"\n$N加入战斗。\n\n"NOR, me);

	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) 
        {
        	if( enemy[i] && living(enemy[i]) ) 
                {
                	kill_ob(enemy[i]);
                	if( userp(enemy[i]) ) 
                		enemy[i]->fight_ob(this_object());
                	else	enemy[i]->kill_ob(this_object());
                }
        }
	set_follow(who);
}

void die()
{
	if( environment() ) 
        	message("sound", "僵尸慢慢地倒了下去，化为一滩血水。\n", environment());
	destruct(this_object());
}

int heal_up()
{
	object master;
	if( time()>query("zombine/time")+query("zombine/start") )
        {
        	die();
        	return 0;
        }       
	if( objectp(master = query("possessed")) 
  	 && master->query("mana") > 100 
  	 && master->query("kee") > 100 ) 
        {
        	message("tell",HIR"你觉得体内的力量被" + name()+HIR"一点一点地吸去了。\n"NOR, master);
        	master->add("mana", -20);
        	return ::heal_up()+1;
        } 
	else    
	{
        	die();
        	return 0;
        }
}