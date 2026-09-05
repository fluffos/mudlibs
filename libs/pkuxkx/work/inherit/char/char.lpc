// char.c
// Modified by iszt@pkuxkx, 2007-03-12, added continue_exert & continue_perform in heart_beat
inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_PROFESSION;
inherit F_SKILL;
inherit F_SHELL;
inherit F_TEAM;
inherit F_TRIGGER;

#pragma save_binary
#include <action.h>
#include <ansi.h>
#include <char.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>



// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
	seteuid(getuid(this_object()));

	set_heart_beat(1);
	tick = 5 + random(10);
	enable_player();

	CHAR_D->setup_char( this_object() );
}

void heart_beat()
{
	int wimpy_ratio, cnd_flag;
	mapping my;
	object ob;
	
	my = query_entire_dbase();
	if(!query_temp("have_block_last_line"))
	{
		//write(ESC+"[2;25r");
		set_temp("have_block_last_line",1);
	}
	//write(ESC+"[s"+ESC+"[1;1f"+HIY+BGRN+"        "+ctime(time())+NOR+ESC+"[u");

	// If we are dying because of mortal wounds?
	if( my["eff_qi"] < 0 || my["eff_jing"] < 0) {
		remove_all_enemy();
		die();
		return;
	}

	// If we're dying or falling unconcious?
	if( my["qi"] < 0 || my["jing"] < 0) {
		remove_all_enemy();
//                  if (query("disable_type") != "<睡梦中>")
		       if (!living(this_object()))
			  die();
		else unconcious();
		return;
	}
/*
	if ( my["neili"] < 0 || my["jingli"] < 0) {
		remove_all_enemy();
		if (my["neili"] < 0)
			my["neili"] = 0;
		if (my["jingli"] < 0)
			my["jingli"] = 0;
		unconcious();
		return;
	}
*/
//whuan 解除内力为负而引起的死亡

//seagate 将气血和精神的自然恢复剥离出来
/*  if ( !userp(this_object()) &&
  	   !is_fighting() )
  {
  	if ( ( my["qi"]<my["eff_qi"] ||
  		     my["jing"]<my["eff_jing"] ) &&
  	      living(this_object()) )
  	{
  		my["qi"]=my["eff_qi"];
  		my["jing"]=my["eff_jing"];
  	}
  }
  else
    nature_recover();
  */

    this_object()->decrease_activity();

    nature_recover();
	Negative_Impact(this_object());
	// Do attack if we are fighting.
	if( is_busy() ) {
		continue_action();
		// We don't want heart beat be halt eventually, so return here.
		return;
	} else {
		continue_exert();
		continue_perform();
		// Is it time to flee?
		if( is_fighting()
		&&      intp(wimpy_ratio = (int)query("env/wimpy"))
		&&      wimpy_ratio > 0
		&&      (       my["qi"] * 100 / my["max_qi"] <= wimpy_ratio
			||      my["jing"] * 100 / my["max_jing"] <= wimpy_ratio) )
			GO_CMD->do_flee(this_object());

		// Do attack or clean up enemy if we have fleed.
		attack();
	}
			if( !userp(this_object()) ) 
			{
                         if( !this_object() || !objectp(this_object()) ) return;    //check null first, or report null point error! by boost 2007-10-23
				this_object()->chat();
				// chat() may do anything -- include destruct(this_object())
			}
			else //如果经验相对上次杀害npc增长超过1000，则判断为完成任务，相应降杀气 by icer
			if ((this_object()->query("combat_exp")-this_object()->query_temp("last_killer_exp")>1000) 
				&& (this_object()->query_temp("last_killer_exp")!=0))
			{
				tell_object(this_object(),"你感觉自己的性情平和了许多，心中的杀气也减少了。\n");
				this_object()->set("shaqi",(int)(this_object()->query("shaqi")/2));
				this_object()->set_temp("last_killer_exp",this_object()->query("combat_exp"));
			}

	if( tick--  ) return;
	else tick = 5 + random(10);

	cnd_flag = update_condition();

	
	// If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P
	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up(0))
	&&      !is_fighting() 
	&&      !interactive(this_object())) {
		if(!objectp(environment()) || (objectp(environment()) && environment()->query("player_num") <= 0))
		{
			set_heart_beat(0);
		}
	}

	if( !interactive(this_object()) ) return;

	// Make us a bit older. Only player's update_age is defined.
	// Note: update_age() is no need to be called every heart_beat, it
	//       remember how much time has passed since last call.
	this_object()->update_age();

	if(query_idle(this_object()) > IDLE_TIMEOUT
			&& this_object()->query("noDeadNetnoIdle") != "Pkuxkx")
		this_object()->user_dump(DUMP_IDLE);
}

int visible(object ob)
{
	int lvl, invis;
	
	int i;
    object* seeme_array;
    
	lvl = wiz_level(this_object());

	if( lvl >=wiz_level(ob)&&wizardp(this_object()) ) return 1;

	invis = (int)ob->query("env/invisibility");
	if(intp(invis) && (invis > lvl))
		return 0;
    if (ob->query_temp("guozhan/hide")&&ob->query_temp("guozhan/hide")==environment(ob))//国战特例，埋伏
        return 1;
	if( ob->is_ghost() ) {
		if( is_ghost() ) return 1;
		if( query_temp("apply/astral_vision") ) return 1;
		return 0;
	}
	
	if(ob == this_object()) return 1;

	//在副本机制里玩家只能看到特定的对象.npc则没有限制
	if(userp(this_object()) && environment(this_object()) && environment(ob) && environment(ob)->query("real_dark"))
	{
	    if(ob->query_temp("seeme") == this_object()->query("id")) return 1;
	    if(arrayp(ob->query_temp("seeme_array")))
	    {
	        seeme_array = ob->query_temp("seeme_array");
	        for(i=0;i<sizeof(seeme_array);i++)
	        {
	            if(objectp(seeme_array[i]) && seeme_array[i] == this_object()) return 1;
	        }
	    }
	    return 0;
	}
	return 1;
}

void add_visible_ob(object ob)
{
    object* seeme_array;
    if(!objectp(ob)) return;
        
    if(arrayp(query_temp("seeme_array")))
    {
        seeme_array =  query_temp("seeme_array");
        seeme_array += ({ob});
    }
    else        
    {
        seeme_array = ({ob});
    }
    set_temp("seeme_array",seeme_array);
}

void del_visible_ob(object ob)
{
    object* seeme_array;
    if(!objectp(ob)) return;
        
    if(arrayp(query_temp("seeme_array")))
    {
        seeme_array =  query_temp("seeme_array");
        seeme_array -= ({ob});
    }
    else        
    {
        seeme_array = ({});
    }
    set_temp("seeme_array",seeme_array);
}

void fullme()
{
    object me = this_object();
	if(me->query("qi") < me->query("max_qi"))
	{
	    me->set("qi",me->query("max_qi"));
	}
	if(me->query("eff_qi") < me->query("max_qi"))
	{
	    me->set("eff_qi",me->query("max_qi"));
	}
	if(me->query("jing") < me->query("max_jing"))
	{
	    me->set("jing",me->query("max_jing"));
	}
	if(me->query("eff_jing") < me->query("max_jing"))
	{
	    me->set("eff_jing",me->query("max_jing"));
	}
	if(me->query("jingli") < me->query("max_jingli"))
	{
	    me->set("jingli",me->query("max_jingli"));    
	}
	if(me->query("eff_jingli") < me->query("max_jingli"))
	{
	    me->set("eff_jingli",me->query("max_jingli"));   
	}
	if(me->query("neili") < me->query("max_neili"))
	{
	    me->set("neili",me->query("max_neili"));        
	}
	if(me->query("eff_neili") < me->query("max_neili"))
	{
	    me->set("eff_neili",me->query("max_neili"));    
	}
    me->set("food",me->max_food_capacity());                
    me->set("water",me->max_water_capacity());                    
}

void changewield()
{
	object ob=this_object();
	object wp1,wp2;
	int dmg1,dmg2,dmg3;
	
	wp1 = ob->query_temp("weapon");
	wp2 = ob->query_temp("secondary_weapon");
	if ( objectp(wp1) )
	{
		dmg1=wp1->query("weapon_prop/damage");
    if ( wp1->query("equipped")!="wielded" )
      dmg1=0;
  }
	else
		dmg1=0;
  
	if ( objectp(wp2) )
	{
	  dmg2=wp2->query("weapon_prop/damage");
    if ( wp2->query("equipped")!="wielded" )
      dmg2=0;
  }
	else
		dmg2=0;
		

  
	dmg3=ob->query_temp("apply/damage")-dmg1;
	ob->set_temp("apply/damage",dmg3+dmg2);
	ob->set_temp("secondary_weapon",wp1);
	ob->set_temp("weapon",wp2);
}

/* 用于perform时检查双手空闲状态，NPC可视情况无视此约束 add by labaz 20140111*/
int check_hand()
{
    object right_weapon, left_weapon, shield;
    object me = this_object();
    int use = 0;

//    if ( inherits(NPC, me) ) return use;

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");
    shield = me->query_temp("armor/shield");

    if ( objectp(right_weapon) )
    {
        if ( right_weapon->query("flag") & 1 ) // weapon.h #define TWO_HANDED	1
        {
            use += 2;
        }
        else
        {
            use += 1;
        }
    }

    if ( objectp(left_weapon) )
    {
        if ( left_weapon->query("flag") & 1 )// weapon.h #define TWO_HANDED	1
        {
            use += 2;
        }
        else
        {
            use += 1;
        }
    }

    if ( objectp(shield) )
    {
        use += 1;
    }

    return use;
}

// 吃食物/饮水可以提供短时buff效果. lordstar 20180424
// 移除上一次食物效果
void remove_food_effect()
{
	mixed food_apply;
	int i;
	mapping food_eff;
	string *effs;
	object me = this_object();
	
	if (!objectp(me)) return;
	remove_call_out("remove_food_effect");
	food_apply = me->query_temp("last_food");
	if (food_apply && food_eff = food_apply["apply"])
	{	
		effs = keys(food_eff);
		for (i=0; i<sizeof(effs); i++)
		{
			me->add_temp("apply/"+effs[i], -1 * food_eff[effs[i]]);
		}
	}
	me->delete_temp("last_food");
	me->delete_temp("active_buffer/food");
}

void remove_liquid_effect()
{
	mixed liquid_apply;
	int i;
	mapping liquid_eff;
	string *effs;
	object me = this_object();
	
	if (!objectp(me)) return;
	remove_call_out("remove_liquid_effect");
	liquid_apply = me->query_temp("last_liquid");
	if (liquid_apply && liquid_eff = liquid_apply["apply"])
	{	
		effs = keys(liquid_eff);
		for (i=0; i<sizeof(effs); i++)
		{
			me->add_temp("apply/"+effs[i], -1 * liquid_eff[effs[i]]);
		}
	}
	me->delete_temp("last_liquid");
	me->delete_temp("active_buffer/liquid");
}

// 吃食物可以提供短时buff效果. lordstar 20180424
void apply_foodliquid_effect(object foodliquid, string type)
{
	int i, dur;
	string msg, *effs;
	mixed foodliquid_apply;
	mapping foodliquid_eff;
	object me = this_object();
	
	if (!objectp(foodliquid)) return;
	if (!foodliquid_apply = foodliquid->query(type+"_apply")) return;
	if (!foodliquid_eff = foodliquid_apply["apply"]) return;
	
	// 移除上一次食物效果
	switch (type)
	{
		case "food": remove_food_effect(); break;
		case "liquid": remove_liquid_effect(); break;
		default: return;
	}
	
	me->set_temp("last_"+type, foodliquid_apply);
	me->set_temp("last_"+type+"/filename", base_name(foodliquid));

	effs = keys(foodliquid_eff);
	for (i=0; i<sizeof(effs); i++)
	{
		me->add_temp("apply/"+effs[i], foodliquid_eff[effs[i]]);
	}

	me->set_temp("active_buffer/"+type+"/name", foodliquid->query("name"));
	effs = foodliquid_apply["desc"];
	if (sizeof(effs)<=0)
	{
		me->set_temp("active_buffer/"+type+"/effect1", "提高能力");
	}
	else
	{
		for (i=0; i<sizeof(effs); i++)
		{
			me->set_temp("active_buffer/"+type+"/effect"+(i+1), effs[i]);
		}
	}
	dur = foodliquid_apply["duration"];
	if (dur<=0) dur = 10;
	me->set_temp("active_buffer/"+type+"/last_time", time() + foodliquid_apply["duration"]);

	if (stringp(msg = foodliquid->query(type+"_apply/message")))
		tell_object(me, msg);
	else {
		if (type == "food")
			tell_object(me, "品尝美味的食物让你的能力得到了提高！\n");
		else
			tell_object(me, "畅快淋漓的豪饮让你的能力得到了提高！\n");
	}
	call_out("remove_"+type+"_effect", dur);
}

void apply_food_effect(object food)
{
	apply_foodliquid_effect(food, "food");
}

void apply_liquid_effect(object liquid)
{
	if (!objectp(liquid) || !liquid->query("liquid_apply")
		|| liquid->query("liquid/type") != liquid->query("liquid_apply/liquidtype")
		|| liquid->query("liquid/name") != liquid->query("liquid_apply/liquidname") ) 
		return;
	apply_foodliquid_effect(liquid, "liquid");
}
