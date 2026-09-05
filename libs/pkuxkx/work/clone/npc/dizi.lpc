//门派弟子，门忠符合条件的玩家可以拥有随从弟子。
//可以命令他们做事。 
//开放对导师的track，稍有区别，不能busy导师，by yhzzyahoo
inherit NPC;

#include <family.h>
#include <combat.h>
#include <ansi.h>
//随从弟子十大功能：从1到10，逐渐强大。门派威望第十的可以获得第一个功能，第九的获得第一第二两个功能。第一的可以获得全部。类推
//每次使用消耗门忠。

/*
1. 修改随从ID
2. 超远程遥控。
3. 超远程呼叫。不需要follow，避免跟丢
4. 修理兵器耐久。
5. 寻人。类似pp
6. reload随机盔甲。被npc焚毁的盔甲随从可以帮忙reload，无需relog
7. reload随机武器。同上
8. 治疗。消除中毒，刺腕等负面影响
9. 急救。玩家晕倒后自动get，并恢复部分气血
10.解玩家busy，以随从受伤为条件，换取玩家busy解除
*/
int special_function(object pl,string funcname,mixed param);
int change_id(object pl,string id);
int remote_ctrl(object pl,string cmd);
int remote_call(object pl);
int fix_weapon(object pl,string id);
int find_char(object pl,string id);
int reload_equip(object pl);
int cure(object pl);
int first_aid(object pl);
int stop_busy(object pl);


int execute_cmd(object commander,string cmd);

//find char 是第一个功能，但是消耗不低
mapping special_functions = ([
//    功能名    门忠要求  消耗门忠        功能函数
    "findchar":({5000,    20,         (:find_char:),0,"追踪"}),		
	"changeid":({3000,     1,         (:change_id:),1,"隐姓"}),
	"remotectrl":({3500,   1,         (:remote_ctrl:),2,"遥控"}),		
	"remotecall":({4000,     10,         (:remote_call:),3,"召唤"}),		
	"fixweapon":({4500,     1,         (:fix_weapon:),4,"修理"}),    
    "reloadequip":({11500,     20,         (:reload_equip:),5,"重装装备"}),    	
	"cure":({7500,     15,         (:cure:),6,"治疗"}),
	"firstaid":({15000,     30,         (:first_aid:),7,"急救"}),		    	    			
	"stopbusy":({18000,     35,         (:stop_busy:),8,"解围"})		    	    					
]);



string *specialsk=({
    "ironskin","health","energy","chainless","sociability","greedy","agile",
    "might","constitution","perceive",   
    });      
    
string *specialsk_cn=({
   "铜皮铁骨","气息悠长","聚精会神","金蝉脱壳","长袖善舞","饕餮之力","身轻如燕",
    "力大无穷","镇蕴七星","传音搜魂",   
    });      



int* score_lvl = ({3000,5000,10000,30000,60000,90000,120000,150000,200000,250000});
string* basic_sk = ({"force","dodge","parry","sword","blade","staff","throwing","spear","hammer","hand","strike","dagger","whip","claw","cuff",
										"finger"});
int ask_skill();

string random_special(object who)
{
        string msg;
        while(1)
        {
         msg=specialsk[random(sizeof(specialsk))];
         if(who->query("special_skill/"+msg)) continue;
         break;
        } 
        return msg;    
}

int change_id(object pl,string id)
{
    int i;

	if(!id || sizeof(id) > 8)
	{
		tell_object(pl,"随从的ID不能超过八个字母。\n");
		return 0;
	}
    for(i=0;i<sizeof(id);i++)
    {
        if((id[i] >= 'a' && id[i] <= 'z') || (id[i] >= 'A' && id[i] <= 'Z')) continue;
        else 
        {
            tell_object(pl,"随从的ID只能包含字母。\n");
            return 0;
        }
    }
    id = id + " dizi";
	set_name(query("name"),({id,"dizi"}));
    tell_object(pl,"是！弟子以后就以"+id+"行走江湖！\n");
	return 1;
}

//如果是找同门师兄弟的npc，门忠double，非同门的npc，4倍。玩家8倍
int find_char(object pl,string id)
{
    object ob,where,uniob;
    int order,order2;
    string region,env;
    string place;

    if (pl->is_busy())
    {
        tell_object(pl,"你正忙着呢！\n");
        return 0;
    }
   
    if(pl->query("jingli") < 100)
    {
        tell_object(pl,"你的精力不足。\n");
        return 0;
    }

    ob = find_player(id);
    if( !ob ) ob = find_living(id);
    
   /* if( !ob || !pl->visible(ob)) 
    {
        tell_object(pl,"回报，江湖中似乎没这个人。\n");
        return 1;
    }*/
            
    if( !ob ) 
    {
        tell_object(pl,"回报，江湖中似乎没这个人1。\n");
        return 1;
    }
	if (!pl->visible(ob))
	{
        tell_object(pl,"回报，江湖中似乎没这个人2。\n");
        return 1;
	}

    if ( userp(ob) && (wiz_level(ob)>1))
    {
        tell_object(pl,"回报，我们无法探查神的踪迹\n");
        return 1;
    }
            
    write(HIR""+name()+"听令，全力调查"+id+"的踪迹。\n"NOR);

    order = FAMILY_D->get_family_order(pl->query("family/family_name"));
        
    where = environment(ob);
    if (!where) 
    {
        tell_object(pl,"回报，我们找不到此人...\n");
        return 1;
    }

    pl->add("jingli",-50);
	pl->start_busy(3);

	if (!wiz_level(ob))
	{
		
		if((int)pl->query("combat_exp")/5 <= random((int)ob->query("combat_exp")))
				tell_object(ob, HIR"你发觉"
				 +pl->query("family/family_name")+"弟子把你包围了。\n"NOR);
	}
    env = where->query("short");
    region = TASK_D->place_belong(where);
    if(region)
    {
        place = region + "的" + env;
    }
    else
    {
        place = env;
    }
	if (!wiz_level(ob))
		write(sprintf(HIW"回报，本门弟子查到"NOR"%s"+HIW+"正在以下地区活动，并暂时拖住了此人。\n"NOR,ob->short()));
	else
		write(sprintf(HIW"回报，本门弟子查到"NOR"%s"+HIW+"正在以下地区活动。\n"NOR,ob->short()));
    ANTIROBOT_D->mxpantirobot_ex(pl,place);
    
	if (!wiz_level(ob))
	{
    if((int)pl->query("combat_exp")/5 <= random((int)ob->query("combat_exp")))
                tell_object(ob, HIR"你发觉"
                +pl->query("family/family_name")+"的弟子突然包围了你。\n"NOR);
	}


    if(userp(ob)) 
    {
        order2 = FAMILY_D->get_family_order(ob->query("family/family_name"));
        if(order2 != -1 && random(order) > random(order2))
        {
            tell_object(pl,ob->query("family/family_name")+"门下弟子把人救走了！\n");
            return 8;
        }
    }
	if (!wiz_level(ob))
	{
    ob->set_temp("pause_move/start",time());
    ob->set_temp("pause_move/duration",random(10/order)+20);
	}

    if(userp(ob)) return 8;;

    if((objectp(uniob=ob->query("uni_target")))) 
    {
        if( (uniob->query("id")!=pl->query("id")))
        {
            if(uniob->query("family/family_name") == pl->query("family/family_name"))
            {
                return 4;
            }
            else
            {
                return 6;
            }
        }
    }
    else
    {
        //非任务npc double，避免用来对付其他npc
        return 3;
    }
	return 1;
}

int fix_weapon(object pl,string arg)
{

    object ob,who, uitem;
    int cost;

    who = pl;

    if(!arg)
    {
        tell_object(pl,"你要修复什么装备？\n");
        return 0;
    }
    if(!ob=present(arg,who))
    {
        tell_object(pl,"你要修复什么装备？\n");
        return 0;
    }

    if(!ob->is_gems())
    {
        tell_object(pl,"这个东西我可修复不了！\n");
        return 0;
    }

    if(!ob->query("weapon_prop"))
    {
        tell_object(pl,"目前只能修复武器！\n");
        return 0;
    }

            
    if(ob->query("max_rigidity") < 2)
    {
        tell_object(pl,"这件装备已经彻底损坏无法修理了。\n");
        return 0;
    }

    uitem=new(UITEM_OB);
    uitem->set("id", pl->query("id"));
//    if ( uitem->check_save() )
      uitem->restore();
    
    if(ob->query("max_rigidity") < ob->query("rigidity"))
    {
        //bug weapon
        ob->set("max_rigidity", ob->query("rigidity"));
        if(ob->query("gem_ob_autoloaded") == 1)
        {
            if ( ob->query("autoload_serial") )
              uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
        }				        	
    }			                
    
    if(ob->query("rigidity") == ob->query("max_rigidity"))
    {
        tell_object(pl,"你的东西根本没坏。\n");
        uitem->save();
        destruct(uitem);
        return 0;
    }            
    
    cost = (ob->query("max_rigidity") - ob->query("rigidity")) / 100;
    if(ob->query("forge/material1_level"))
    {
        cost += 1 * ob->query("forge/material1_level");
    }

    if(ob->query("forge/material2_level"))
    {
        cost += 1 * ob->query("forge/material2_level");
    }

    if(ob->query("forge/material3_level"))
    {
        cost += 1 * ob->query("forge/material3_level");
    }	

    if(ob->query("forge/material4_level"))
    {
        cost += 1 * ob->query("forge/material4_level");
    }				
    
    cost = cost*3/2;
    if(cost < 1) cost = 1;
        
    if(random(2000) < (ob->query("max_rigidity") - ob->query("rigidity")))
    {
        write("由于常年使用，你的武器耐久永久性的下降了1点。\n");
        ob->add("max_rigidity",-1);
    }
    ob->set("rigidity",ob->query("max_rigidity"));
    
    if(ob->query("gem_ob_autoloaded") == 1)
    {
        if ( ob->query("autoload_serial") )
          uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
    }		

    uitem->save();
    destruct(uitem);
    tell_object(pl,name()+"告诉你：您的装备修理好了\n");
    
    return cost;
}

int reload_equip(object pl)
{
	int i;
	
	object	uitem;		
	object* invs = all_inventory(pl);
	
	for(i=0;i<sizeof(invs);i++)
	{
		if( invs[i]->query("gem_ob_autoloaded") )
		{
			destruct(invs[i]);
		}
	}	
	
  uitem=new(UITEM_OB);
  uitem->set("id", pl->query("id"));
//  if ( uitem->check_save() )
    uitem->restore();
  
  if ( uitem->load_equip(pl) )
    tell_object(pl,name()+"告诉你：您的装备。\n");
  
  destruct(uitem);
  return 1;
}

int cure(object pl)
{
    string msg = name()+"为你治疗了";
    int cured = 0;

    if(pl->query("eff_qi") < pl->query("max_qi")/2)
    {
        msg += "【皮肉】";
        pl->set("eff_qi",pl->query("max_qi")/2);
        cured = 1;
    }
    if(pl->query("eff_jing") < pl->query("max_jing")/2)
    {
        msg += "【心力】";
        pl->set("eff_jing",pl->query("max_jing")/2);
        cured = 1;
    }
    if (pl->query_condition("cannt_eq"))
    {
        msg += "【刺腕】";        
        pl->clear_condition("cannt_eq");
        cured = 1;
    }
    msg += "的伤势。\n";

    if(cured != 1)
    {
        tell_object(pl,name()+"疑惑的说，您什么伤都没有。\n");
        return 1;
    }
    tell_object(pl,msg);
    return 1;
}

int first_aid(object pl)
{
    if(pl->query_temp("no_get")) return 0;
    pl->move(this_object());
    pl->set("eff_qi",1);
    pl->set("qi",1);
    pl->set("eff_jing",1);
    pl->set("jing",1);
    pl->remove_all_enemy();
  //  pl->start_busy(0);
    tell_object(pl,name()+"道，事急矣，请到弟子处暂避一时!\n");
    return 1;
}

int stop_busy(object pl)
{
    if(!pl->is_busy() || !pl->is_fighting())
    {
        tell_object(pl,name()+"说到：现在平安无事，有什么要我做的吗？\n");
        return 0;
    }
    if(random(3))
    {
        tell_object(pl,name()+"见你手忙脚乱,挺身而出，为你解围，不幸受了重伤！\n");
        pl->start_busy(0);
        receive_damage("qi",query("max_qi")/2);
        receive_wound("qi",query("max_qi")/2);
    }
    else
    {
        tell_object(pl,name()+"护主心切，可惜力有未逮。\n");
        receive_damage("qi",query("max_qi")/4);
        receive_wound("qi",query("max_qi")/4);
    }
    return 1;
}

int remote_ctrl(object pl,string cmd)
{
    return execute_cmd(pl,cmd);
}

int remote_call(object pl)
{
    object* inv;
    int i;
    if(is_busy() || is_fighting())
    {
        tell_object(pl,name()+"告诉你，我脱不开身.\n");
        return 1;
    }
    if(environment()->query("no_suicong"))
    {
        tell_object(pl,name()+"告诉你，那里我去不了。\n");
        return 1;
    }
    inv = deep_inventory(this_object());
    for(i=sizeof(inv)-1; i>=0; i--)
    {
        if(userp(inv[i]))
        {
            tell_object(pl,name()+"告诉你，有个人拖累着我，离不开啊。\n");
            return 1;
        }
    }

    tell_object(pl,name()+"快马加鞭，出现在你面前\n");
    move(environment(pl));
    return 1;
}

void create()
{
	set_name("随从弟子",({"dizi","suicong dizi"}));
	set("long",
	"这是一个随从弟子\n"
	);
    set("inquiry",([
        "技能":(:ask_skill:),
        ]));
    set_max_encumbrance(1000000);
	setup();
}

int ask_skill()
{
    string* sklname;
    int i;
    int order;
    object pl = this_player();
	if(!userp(pl) || pl != query("owner"))
	{
		return 0;
	}

    order = FAMILY_D->get_family_order(pl->query("family/family_name"));

    tell_object(pl,name()+"告诉你,我可以使用的技能有：");

    sklname = keys(special_functions);
    for(i=0;i<sizeof(sklname);i++)
    {
        if (pl->query("suicongdizi/"+sklname[i]) || ( order != -1 && order <= sizeof(special_functions) - special_functions[sklname[i]][3]))
        {
            tell_object(pl,special_functions[sklname[i]][4]);
            tell_object(pl,",");
        }
    }
    tell_object(pl,"请示下。\n");
    return 1;
}

void init()
{
	add_action("do_name","name");
	add_action("do_protect","protect");
	add_action("do_changeid","changeid");
	add_action("do_findchar","track");
	add_action("do_fix","fix");
  	add_action("do_reload","reload");
    add_action("do_stopbusy","stopbusy");
    add_action("do_cure","cure");
}

//只在副本有效
int do_protect(string arg)
{
	object pl = this_player();
	int cd = 5;
	
	if(this_player() == query("owner") && environment()->query("real_dark") == 1)
	{
		if(is_busy() || is_fighting() || !living(this_object()))
		{
			tell_object(pl,query("name")+"现在帮不了你。\n");
			return 1;
		}
		
		cd = 60 - pl->query("score")/300;
		if(cd < 10) cd = 10;
			
		if(time() - query("last_protect_time") < cd)
		{
			tell_object(pl,query("name")+"暂时不能帮你。\n");
			return 1;
		}
		
		if(FAMILY_D->get_family_order(query("family/family_name")) > 10)
		{
			tell_object(pl,query("name")+"鼓起勇气上前助阵，却很快败下阵来。\n");
			return 1;			
		}
		
		if(query("obey") < 5)
		{
			tell_object(pl,query("name")+"并不想帮你，怕是你平日里做的不够多吧？\n");
			return 1;
		}
		
		message_vision("$N怒叱道：无知鼠辈，竟敢与我"+query("family/family_name")+"为敌，还不快束手就擒！\n",this_object(),pl);		
		pl->remove_all_killer();
		set("last_protect_time",time());
		return 1;
	}
	
	return 0;
}
int do_name(string arg)
{
	if(!stringp(arg) || sizeof(arg) == 0 || sizeof(arg) > 32) return 0;

	arg = replace_string(arg,"//","");
	arg = replace_string(arg,"\"","");
	arg = replace_string(arg,"'","");
	arg = replace_string(arg,"(","");
	arg = replace_string(arg,")","");
	arg = replace_string(arg,";","");


	if(LOGIN_D->check_legal_name(arg) != 1) return 1;

	if(this_player() == query("owner"))
	{
		set("name",arg);
		write("是！弟子今后就以"+arg+"为名行走江湖\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

int do_changeid(string id)
{
	if(!id || !stringp(id))
	{
		return 0;
	}
	return special_function(this_player(),"changeid",id);
}

int do_findchar(string id)
{
	if(!id || !stringp(id))
	{
		return 0;
	}
	return special_function(this_player(),"findchar",id);
}

int do_fix(string arg)
{
	if(!arg || !stringp(arg))
	{
		return 0;
	}
   	return special_function(this_player(),"fixweapon",arg);
}

int do_reload(string arg)
{
	if(!arg || !stringp(arg))
	{
		return 0;
	}
    if( arg == "all")
    {
        return special_function(this_player(),"reloadequip",arg);
    }
    else
    {
        return notify_fail("命令格式为reload all！\n");
    }
}

int do_stopbusy()
{
    return special_function(this_player(),"stopbusy","");
}

int do_cure()
{
    return special_function(this_player(),"cure","");
}

//根据owner,确定弟子的门派，武功等级，以及对owner的服从程度
//根据factor,决定技能，经验。这个factor是根据门派威望排名来的
//再根据owner自己的门忠，一起决定技能，经验。
void set_up_dizi(object owner,int factor)
{
	string fam;
	string* skills;
	int i;
	int level,exp,sklvl;
	int score;//门忠
	string special,special_name;
	object* partners;

	if(!userp(owner) || !owner->query("family/family_name")) return;
	fam = owner->query("family/family_name");
	if(!arrayp(family_skills[fam])) return;
	score = owner->query("score");
	for(i=0;i<sizeof(score_lvl);i++)
	{
		if(score < score_lvl[i]) break;
	}

	if( i==0 ) return;

	level = i;

	exp = owner->query("combat_exp");
	//55% ~ 100%
	exp = exp / 100 * (5 * level + 50);
	exp = exp / 10 * factor;
	sklvl = pow(exp/100.0,1.0/3)*10;
	//根据exp, full skill	
	skills = family_skills[fam];
	for(i=0;i<sizeof(skills);i++)
	{
		set_skill(skills[i],sklvl);
	}
	//基本功夫，全部
	for(i=0;i<sizeof(basic_sk);i++)
	{
		set_skill(basic_sk[i],sklvl);
	}

	//玩家自己去enable
	set("combat_exp",exp);
	set("max_neili",sklvl/2*3*10);
	set("max_jingli",sklvl/2*3*10);
	set("max_qi",query("max_neili")*2<=0?1:query("max_neili")*2);
	set("eff_qi",query("max_qi"));
	set("qi",query("max_qi"));
	
	set("max_jing",query("max_neili")*2<=0?1:query("max_neili")*2);
	set("eff_jing",query("max_jing"));
	set("jing",query("max_jing"));
	
	set_temp("seeme",owner->query("id"));
    set_temp("do_attack_from", owner);

	//服从程度，随mud_age增加
	if(!owner->query("suicongdizi/obey"))
	{
		set("obey",1);
	}
	else
	{
		set("obey",owner->query("suicongdizi/obey"));
	}
	set("owner",owner);
	//如果owner是掌门大弟子，随机获得特技一项
	if(owner->query("id") == FAMILY_D->get_dadizi(owner->query("family/family_name")) && !owner->query("suicongdizi/special"))
	{
        special = random_special(this_object());
        special_name = specialsk_cn[member_array(special,specialsk)];
		this_object()->set("special_skill/"+special,1);
		write("作为掌门大弟子，随从也应当强一些，就派一名懂得"+special_name+"的弟子跟随你吧。\n");
		owner->set("suicongdizi/special",special);
	}
	else 
	{
		if(owner->query("id") != FAMILY_D->get_dadizi(owner->query("family/family_name")) && owner->set("suicongdizi/special"))
		{
			write("你已经不是掌门大弟子了，随从也没必要这么强了。\n");
			owner->delete("suicongdizi/special");
		}
		else if(owner->query("id") == FAMILY_D->get_dadizi(owner->query("family/family_name")) && owner->query("suicongdizi/special"))
		{
			this_object()->set("special_skill/"+owner->query("suicongdizi/special"),1);
		}
	}
	//设置id和名字，唯一化
	set_name(owner->query("name")+"的随从弟子",({owner->query("id")+" suicong"}));
	set("family/family_name",owner->query("family/family_name"));
	set("long",query("family/family_name")+owner->query("name")+"随从弟子。\n");
	set("gender",owner->query("gender"));
	set("age",owner->query("age")/2);
	set("is_suicongdizi",1);
	
	partners = owner->query_temp("partners");
	
	if(!arrayp(partners)) partners = ({this_object()});
	else partners += ({this_object()});
		
	owner->set_temp("partners",partners);
	setup();
	set("keep_heart_beat",1);
}

void heart_beat()
{
	//检查owner是否还存在
	if(!objectp(query("owner")))
	{
		message_vision("$N吃惊的说道：什么？居然失踪了？\n",this_object());
		destruct(this_object());
		return;
	}
	if(random(1000) == 1 && query("obey") < 10) 
	{
		add("obey",1);
		query("owner")->add("suicongdizi/obey",1);
	}
	::heart_beat();
}

void die()
{
	object* partners;
	if(!objectp(query("owner")))
	{
		message_vision("$N吃惊的说道：什么？居然失踪了？\n",this_object());
		destruct(this_object());
		return;
	}
	query("owner")->set("suicongdizi/obey",0);
	tell_object(query("owner"),query("name")+"死了。\n");
	
	partners = query("owner")->query_temp("partners");
	
	if(arrayp(partners)) partners -= ({this_object()});		
	query("owner")->set_temp("partners",partners);	
	::die();
}

int execute_cmd(object commander,string cmd)
{
	string* cmds;
	if(!userp(commander) || commander != query("owner"))
	{
		return 0;
	}
	
	if(random(10) < query("obey"))
	{
        cmd=ALIAS_D->process_global_alias(cmd);
		command(cmd);

		return 1;
	}
	tell_object(commander,query("name")+"拒绝执行你的命令，你不禁感到羞怒。\n");
	commander->add_busy(1);
	return 0;
}

//降低敌人的攻击力
int help_defense(object partner,object enemy)
{
	string msg;
	int power = 0;
	
	msg = query("name")+"抓住"+enemy->query("name")+"攻击"+partner->query("name")+"露出的破绽，从旁出招，延缓了"+enemy->query("name")+"的攻势\n";
	
	if(random(10) < query("obey") && !is_busy())
	{
		power = COMBAT_D->skill_power(this_object(),"parry",SKILL_USAGE_DEFENSE,enemy);
		tell_object(partner,msg);
		tell_object(enemy,msg);
		return random(power) + 1;
	}
	else
	{
		return 0;
	}
}

//降低敌人的防御力
int help_attack(object partner,object enemy)
{
	string msg;
	mapping prepare;
	object weapon;
	string attack_skill;
	
	int power = 0;
	
	msg = query("name")+"见"+enemy->query("name")+"忙于防御"+partner->query("name")+"露出的破绽，从旁出招，进一步打开了"+enemy->query("name")+"的门户\n";
	
	if(random(10) < query("obey") && !is_busy())
	{
		weapon = query_temp("weapon");
		
		prepare = query_skill_prepare();
		if (!prepare) prepare = ([]);
		if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
		else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
		else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
		else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[query_temp("action_flag")];
			
		power = COMBAT_D->skill_power(this_object(),attack_skill,SKILL_USAGE_ATTACK,enemy);
		tell_object(partner,msg);
		tell_object(enemy,msg);
		return random(power) + 1;	
	}
	else
	{
		return 0;
	}
}
int is_suicong_dizi()
{
	return 1;
}

int special_function(object pl,string funcname,mixed param)
{
	int ret;
	int* funcprop;
    int order;
	if(!userp(pl) || pl != query("owner"))
	{
		return 0;
	}
	

	if(random(10) >= query("obey"))
	{		
        tell_object(pl,"你的随从弟子看来对你并不十分信任\n");
		return 1;
	}		

    if(!living(this_object()) || is_busy() || is_fighting())
    {
        tell_object(pl,"你的随从弟子正自顾不暇。\n");
		return 1;
    }

	if(undefinedp(special_functions[funcname])) return 0;

    order = FAMILY_D->get_family_order(pl->query("family/family_name"));
    if(order == -1 || order > sizeof(special_functions) - special_functions[funcname][3])
    {
        if(!pl->query("suicongdizi/"+funcname))//特别奖励的技能，永久可用。无视门派威望。
        {
            tell_object(pl,short()+"沮丧的告诉你，本门势力衰弱，弟子无能为力。\n");
            return 1;            
        }
        else
        {
            tell_object(pl,HIB"恭喜！你可以永久使用随从弟子的"+special_functions[funcname][4]+"技能。\n"NOR);
        }
    }

	if(pl->query("score") < special_functions[funcname][0]) 
	{
		tell_object(pl,"你对门派的忠诚度不够"+chinese_number(special_functions[funcname][0])+"\n");
		return 1;		
	}
    
    param = ALIAS_D->process_global_alias(param);
	ret = evaluate(special_functions[funcname][2],pl,param);		
     
    //ret 代表消耗的门忠倍数。0表示失败了，不消耗。
    if(ret == 0) 
    {
        //tell_object(pl,"失败了。\n");
        return 1;
    }
    
	pl->add("score",-ret*special_functions[funcname][1]);
    tell_object(pl,"你调用门派力量，消耗门忠"+chinese_number(ret*special_functions[funcname][1])+"点\n");
	return ret;
}


//给超级狂欢周准备的，随机奖励一个技能
string random_reward_skill(object pl)
{
    int i;
    string* sklname = keys(special_functions);
	if(pl->query("suicongdizi/get_reward")) return "";
    i = random(sizeof(sklname));
    pl->set("suicongdizi/"+sklname[i],1);
	pl->set("suicongdizi/get_reward",1);
    return special_functions[sklname[i]][4];
}