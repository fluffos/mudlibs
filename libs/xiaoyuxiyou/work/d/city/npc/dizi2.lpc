#include <ansi.h>
inherit NPC;

void create()
{
set_name("武馆弟子", ({ "wuguan dizi", "dizi", "trainee" }) );
set_level(3+random(10));
set("gender", "男性" );
set("age", 18+random(10));
set("long", "你看到一位身材高大的汉子，正在辛苦地操练着。\n");
set("age", 16+random(30));
set("combat_exp", 800000000);
set("daoxing", 80000000);

set("attitude", "peaceful");
set_skill("unarmed", 110);
set_skill("dodge", 120);
set_skill("parry", 120);
set_skill("literate", 100);
set_skill("spells", 150);
        
set("per", 15);
set("str",40);
set("int",40);
set("con",40);
set("max_kee",5000);
set("max_sen", 5000);
set("max_mana", 6000);
set("max_force", 6000);
set("mana", 200000);
set("mana_factor", 1000);
setup();
	carry_object(0,"cloth",random(2))->wear();        
	carry_object(0,"shoes",random(2))->wear(); 
}
 
void unconcious ()
{
die ();
}  

void die()
{
powerup(1,1);
this_object()->clean_up_enemy();
} 

void heart_beat()
{
object me = this_object();
string str;
::heart_beat();

if ( me->is_busy() )
      return;
if ( query("eff_kee") < query("max_kee") )
        QUEST_D->addEffKee(me);
if ( query("kee") < query("eff_kee") )
        QUEST_D->addKee(me);
if ( query("sen") < query("eff_sen") )
        QUEST_D->addSen(me);
if ( query("eff_sen") < query("max_sen") )
        QUEST_D->addEffSen(me);
}

varargs int receive_wound(string type, int damage, object who)
{
string skill;
if ( damage>10 )
        damage = 10;
if ( who && who->is_fighting(this_object()) && random(who->query_int())>20 )
        {
        if ( who->query_temp("weapon") )
                  skill = who->query_temp("weapon")->query("skill_type");
        else    skill = "unarmed";
        if ( stringp(who->query_skill_mapped(skill)) )
                  skill = who->query_skill_mapped(skill);
        if ( who->query_skill(skill,1)<700 )   who->improve_skill(skill,random(2),1);
        }
return  ::receive_wound(type,damage,who);
}

varargs int receive_damage(string type, int damage, object who)
{
string skill;
if ( damage>10 )
        damage = 10;
if ( who && who->is_fighting(this_object()) && random(who->query_int())>23 )
        {
        if ( who->query_temp("weapon") )
                  skill = who->query_temp("weapon")->query("skill_type");
        else    skill = "unarmed";
        if ( stringp(who->query_skill_mapped(skill)) )
                  skill = who->query_skill_mapped(skill);
        if ( who->query_skill(skill,1)<700 )   who->improve_skill(skill,random(3),1);
        }
return  ::receive_damage(type,damage,who);
}
        
int accept_fight(object who)
{
if ( !who || !present(who,environment()) )
       return 0;
this_object()->clean_up_enemy();
if ( this_object()->is_fighting() )
      return 0;
if ( who->is_fighting() && !who->is_fighting(this_object()) )
        return 0;
return 1;
}

void set_skills(object me) 
{
mapping skill=me->query_skills();
int max_value=10;
string *skillnames;

if ( !skill ) 
        return;
skillnames = keys(skill);
for (int i=0;i<sizeof(skillnames);i++) 
        if(skill[skillnames[i]]>max_value)
                max_value=skill[skillnames[i]];
set("max_force",me->query("max_force")*(10+random(3))/10);
set("daoxing",me->query("daoxing")*(10+random(3))/10);
set("combat_exp",me->query("combat_exp")*(10+random(3))/10);
if (query_skill("unarmed")<max_value) 
        {    
        max_value=max_value*(10+random(3))/10;
        set_skill("force",max_value);
        set_skill("moonforce",max_value);
        map_skill("force","moonforce");
        set_skill("spells",max_value);
        set_skill("moonshentong",max_value);
        map_skill("spells","moonshentong");
        set_skill("unarmed", max_value);
        set_skill("baihua-zhang", max_value);
        map_skill("unarmed", "baihua-zhang");
        set_skill("dodge", max_value*2+random(2));
        set_skill("hammer",max_value*2+random(2));
        set_skill("parry",max_value*2);
        }
this_object()->powerup(0,1);
set("fighting_ob",me);
}

void fight_ob(object who)
{
if ( !who || !present(who,environment()) )
      return;
if ( !living(who) )
     {
     remove_killer(who);
     who->remove_killer(this_object());
     who->revive();
     return;
     }
this_object()->clean_up_enemy();
if ( objectp(query("fighting_ob")) 
  && this_object()->is_fighting(query("fighting_ob")) 
  && who!=query("fighting_ob") )
        {
        say(name()+"说道：我的对手是"+query("fighting_ob")->name()+"。\n");
        remove_killer(who);
        who->remove_killer(this_object());
        return;
        }
set_skills(who);
::fight_ob(who);
}

void kill_ob(object who)
{
fight_ob(who);
}

void init()
{
add_action("do_kill","kill");
}

int do_kill(string arg)
{
object who,me=this_player();
if ( !arg )
        return 0;
who = present(arg,environment());
if ( !who )
        return 0;
if ( userp(who) )
        return 1;
if ( who==this_object() )
        {
        if ( me->is_fighting() && !me->is_fighting(this_object()) )
                return 1;
        }
else  if ( me->is_fighting(who) )
        {
        write("加油加油！\n");
        return 1;
        }
return 0;
}
