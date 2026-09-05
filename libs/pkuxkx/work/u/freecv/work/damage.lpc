// damage.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;  
int medical;
string use_skill;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
    int val;

    if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    if( type!="jing" && type!="qi" )
	error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");

    if( objectp(who) ) set_temp("last_damage_from", who);
    val = (int)query(type) - damage;

    if( val >= 0 ) set(type, val);
    else set( type, -1 );

    set_heart_beat(1);

    return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
    int val;

    if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    if( type!="jing" && type!="qi" )
	error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");

    if( objectp(who) ) set_temp("last_damage_from", who);
    val = (int)query("eff_" + type) - damage;

    if( val >= 0 ) set("eff_" + type, val);
    else {
	set( "eff_" + type, -1 );
	val = -1;
    }

    if( (int)query(type) > val ) set(type, val);

    set_heart_beat(1);

    return damage;
}

int receive_heal(string type, int heal)
{
    int val;

    if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    if( type!="jing" && type!="qi" )
	error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

    val = (int)query(type) + heal;

    if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
    else set( type, val );

    return heal;
}

int receive_curing(string type, int heal)
{
    int max, val;

    if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    if( type!="jing" && type!="qi" )
	error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

    val = (int)query("eff_" + type);
    max = (int)query("max_" + type);

    if( val + heal > max ) {
	set("eff_" + type, max);
	return max - val;
    } else {
	set( "eff_" + type, val + heal);
	return heal;
    }
}

void unconcious()
{
    object defeater,room,*inv;
    int i;
    object where;
    where=environment(this_object());
    if( !living(this_object()) ) return;

    //yuer add for tongtian-xuangong


    //
	    if( wizardp(this_object()) && query("env/immortal") ) return;

       if (this_object()->query("id") == "pal" && this_object()->is_character() ) return;
    if( objectp(defeater = query_temp("last_damage_from")) )
	COMBAT_D->winner_reward(defeater, this_object());

    this_object()->remove_all_enemy();

    message("system", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,
      this_object());

    if(userp(this_object()))
    { 
	room=new("/adm/single/temproom");
	inv=all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	    inv[i]->move(room);
	this_object()->set_temp("block_msg/all", 1);
	this_object()->move("/clone/misc/tmp_void",1);        
	this_object()->disable_player(" <昏迷不醒>");
	this_object()->move(where);//jason add this lines to avoid add_action crash

	inv=all_inventory(room);
	for(i=0;i<sizeof(inv);i++)
	    inv[i]->move(this_object());
	destruct(room);
    }

    else 
	this_object()->disable_player(" <昏迷不醒>");

    set("jing", 0);
    set("qi", 0);
    set_temp("block_msg/all", 1);
    COMBAT_D->announce(this_object(), "unconcious");
    call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
    object room,obj,*inv;
    object tempenv;
    int sign=0;
    int i;
    remove_call_out("revive");
    // here is for put in horse bug
    // debug by akuma 	
    tempenv=environment();	

    while(sign==0) {
	if(environment(tempenv) )
	{			
	    tempenv=environment(tempenv);
	}
	else
	{
	    sign=1;

	}
    }

    this_object()->move(tempenv);

    if(userp(this_object()))
    { 
	room=new("/adm/single/temproom");
	inv=all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	    inv[i]->move(room);

	this_object()->enable_player();
        this_object()->delete_temp("block_msg/all");

	inv=all_inventory(room);
        for(i=0;i<sizeof(inv);i++) {
	    inv[i]->move(this_object());
            if (inv[i]->query("armor_type")) inv[i]->wear();
        }
	this_object()->delete("disable_type");
    }
    else 
	this_object()->delete("disable_type");
    this_object()->enable_player();

    if( !quiet ) 
    {
	if (userp(this_object()))
	{
	    COMBAT_D->announce(this_object(), "revive");
	    this_object() -> set_temp("block_msg/all", 0);
	    message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,this_object());
	}
	else
	    set_temp("block_msg/all", 0);
    }
}

void die()
{
    object corpse, killer,room,obj,*inv;
    object thekiller;
    int i;
    object rum_ob = load_object("/d/huashan/npc/referee");

    if( !living(this_object()) ) revive(1);
	//只有试剑山庄用no_death参数，其他地方一定不要用！
	if (environment(this_object())->query("no_death") && userp(this_object()))
	{
		killer = query_temp("last_damage_from");

		if ( objectp(killer) )
				CHANNEL_D->do_channel(rum_ob, "rumor",
					sprintf("%s被" + killer->name() + "干掉了。", this_object()->name(1)));
		else
				CHANNEL_D->do_channel(rum_ob, "rumor",
					sprintf("%s被干掉了。", this_object()->name(1)));
	    	COMBAT_D->announce(this_object(), "dead");
		if( this_object()->query("sjsz/entrance")=="east" )
			this_object()->move("/d/bwdh/sjsz/east_xiangfang");
		else
			this_object()->move("/d/bwdh/sjsz/west_xiangfang");
	        if( this_object()->query("max_neili")<0 ) this_object()->set("max_neili",0);
		if( this_object()->query("max_jingli")<0 ) this_object()->set("max_jingli",0);
		if( this_object()->query("eff_qi")<0 ) this_object()->set("eff_qi",this_object()->query("max_qi"));
		if( this_object()->query("eff_jing")<0 ) this_object()->set("eff_jing",this_object()->query("max_jing"));
	    	if( this_object()->query("qi")<0 ) this_object()->set("qi",this_object()->query("max_qi"));
		if( this_object()->query("jing")<0 ) this_object()->set("jing",this_object()->query("max_jing"));
		remove_call_out("revive");
		return;
	}
	/*
    //yuer add for tongtian-xuangong
    use_skill = this_object()->query_skill_mapped("force");
    if( use_skill == "tongtian-xuangong")
    {
	this_object()->set("qi",100); 
	this_object()->set("eff_qi",100);
	this_object()->set("jing",100);
	this_object()->set("eff_jing",100);
	return;
    }
*/
       if (this_object()->query("id") == "pal" && this_object()->is_character() ) return;
    //
    if( wizardp(this_object()) && query("env/immortal") ) return;
    //icer added for 保护新手不被太牛的人pk
    /*
	    if (objectp(thekiller = query_temp("last_damage_from") ))
	    if( userp(thekiller) && userp(this_object()) )
	    {
		    if ((int)(thekiller->query("combat_exp") / (this_object()->query("combat_exp") + 1)) > 10)
		    {
			    message_vision(HIW"根据《新手PK保护法》有关条例，$N被自动保护。\n"NOR,this_object());
			    this_object()->move("/clone/misc/void");        
		    this_object()->set("eff_qi",10);
		    this_object()->set("qi",10);
		    this_object()->set("eff_jing",10);
		    this_object()->set("jing",10);
			    return;
		    }
	    }
    */

    // Clear all the conditions by death.
    this_object()->clear_condition();
    this_object()->delete("shaqi");
    this_object()->delete_temp("jingji_exp");
    this_object()->delete_temp("last_exp");
    this_object()->delete_temp("jingji_potential");
    this_object()->delete_temp("xiangbo_level");
//    this_object()->delete_temp("last_damage_from");
    if( this_object()->query("max_neili")<0 ) this_object()->set("max_neili",0);
    if( this_object()->query("max_jingli")<0 ) this_object()->set("max_jingli",0);
    if( this_object()->query("eff_qi")<0 ) this_object()->set("eff_qi",0);
    if( this_object()->query("eff_jing")<0 ) this_object()->set("eff_jing",0);
    COMBAT_D->announce(this_object(), "dead");
    if( objectp(killer = query_temp("last_damage_from")) ) {
        set_temp("my_killer", killer->query("id"));
        delete_temp("last_damage_from");
	COMBAT_D->killer_reward(killer, this_object());
    }
    this_object()->delete_temp("last_damage_from");

    if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());

    this_object()->remove_all_killer();
    all_inventory(environment())->remove_killer(this_object());

    this_object()->dismiss_team();
    if( userp(this_object()) ) {
	if (this_object()->is_busy())
	    this_object()->interrupt_me();
	//icer added for maybe cause bug
	//          set("jing", 1); set("eff_jing", 1);
	//         set("qi", 1);   set("eff_qi", 1);
	ghost = 1; if ( wizardp(this_object()) ) ghost = 0;
	this_object()->move(DEATH_ROOM);
	this_object()->add("ghost",1);
	DEATH_ROOM->start_death(this_object());
	this_object()->save();
    } else
	destruct(this_object());
}

void reincarnate()
{
    ghost = 0;
    set("eff_jing", query("max_jing"));
    set("eff_qi", query("max_qi"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
    int update_flag, i;
    mapping my;

    //	if( this_object()->is_fighting() ) return -1;

    update_flag = 0;                                              
    //      yuer add for medcial skill
     medical = (int)this_object()->query_skill("medical-skill", 1)/2;
    //      medical skill
    my = query_entire_dbase();

    if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
    if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

    if( my["water"] < 1 && userp(this_object()) ) return update_flag;

    my["jing"] += my["con"] / 3 + my["max_jingli"] / 10 + medical;
    if( my["eff_jing"] < my["max_jing"] )
	my["eff_jing"] += medical/5;


    if( my["jing"] >= my["eff_jing"] ) {
	my["jing"] = my["eff_jing"];
	if( my["eff_jing"] < my["max_jing"] ) { my["eff_jing"] ++; update_flag++; }
    } else update_flag++;

    my["qi"] += my["con"] / 3 + my["max_neili"] / 10 + medical;
    if( my["eff_qi"] < my["max_qi"] )
	my["eff_qi"] += medical/5;


    if( my["qi"] >= my["eff_qi"] ) {
	my["qi"] = my["eff_qi"];
	if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"] ++; update_flag++; }
    } else update_flag++;

    if( my["food"] < 1 && userp(this_object()) ) return update_flag;

    if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
	my["jingli"] += (int)this_object()->query_skill("magic", 1) / 2;
	if( my["jingli"] > my["max_jingli"] ) my["jingli"] = my["max_jingli"];
	update_flag++;
    }

    if( my["max_neili"] && my["neili"] < my["max_neili"] ) {
	my["neili"] += (int)this_object()->query_skill("force", 1) / 2;
	if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
	update_flag++;
    } 

    return update_flag;
}
