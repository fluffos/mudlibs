// move.c

#pragma optimize

#include <dbase.h>
#include <ansi.h>
#include <room.h>

nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
	encumb += w;
	if( encumb < 0 )
		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
	if( encumb > max_encumb ) this_object()->over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
	if( !interactive(this_object()) ) return;
	tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
	if( !environment() ) {
		weight = w;
		return;
	}
	if( w!=weight ) environment()->add_encumbrance( w - weight );
	weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

string ride_suffix (object me)
{
	string ridemsg = 0;
	object ridee = 0;
	
	ridee = me->ride();
	if (ridee)
		ridemsg = ridee->query("ride/msg")+"在"+ridee->name()+"上";
	return ridemsg;
}

varargs int move(mixed dest, int silently)
{
	object ob, env;
	object *inv;
	string str,*dirs;
	int i, depth;
	mapping exits;
	object *inv1;
	int *count;
	int j;
	
	// If we are equipped, unequip first.
	if( query("equipped") && !this_object()->unequip() )
		return notify_fail("你没有办法取下这样东西。\n");
	
	// Find the destination ob for moving.
	if( objectp(dest) )
		ob = dest;
	else if( stringp(dest) ) {
		call_other(dest, "???");
		ob = find_object(dest);
		if(!ob) return notify_fail("move: destination unavailable.\n");
	} else
		return notify_fail(sprintf("move: invalid destination %O.\n", dest));
	
	// Check if the destination ob can hold this object.
	// Beforce checking it, we check if the destination is environment of
	// this_object() (or environment of its environment). If it is, then
	// this could be like get something from a bag carried by the player.
	// Since the player can carry the bag, we assume he can carry the this
	// object in the bag and encumbrance checking is unessessary.
	env = this_object();
	while(env = environment(env)) if( env==ob ) break;
	if( !env && (int)ob->query_encumbrance() + weight()
		> (int)ob->query_max_encumbrance() ) {
		if( ob==this_player() )
			return notify_fail( this_object()->name() + "对你而言太重了。\n");
		else
			return notify_fail( this_object()->name() + "对" + ob->name() + "而言太重了。\n");
	}
	
	//icer added to limit maximum number of objects one player can hold
	if ( living(ob) && (!ob->query("container")) )  //user or npc，if want to hold more things,just set container = 1
	{
		if (sizeof(all_inventory(ob)) >= 400)
			if (ob == this_player())
				return notify_fail("你身上的物品数量已经到了极限，拿不了更多的东西了。\n");
			else
				return notify_fail(ob->name() + "身上的物品数量已经到了极限，拿不了更多的东西了。\n");
	}	
	
	// Move the object and update encumbrance
	if( environment() ) environment()->add_encumbrance( - weight());
	move_object(ob);
	ob->add_encumbrance(weight());
	
	// If we are players, try look where we are.
	if( !this_object() ) return 0;
	if( interactive(this_object())		// are we linkdead?
		&&	living(this_object())			// are we still concious?
		&&	!silently ) {
		if( query("env/brief")|| query("env/brief")== "YES" )
		{
			str = environment()->query("short") + "\n";
			inv = all_inventory(environment());
			for (i = 0; i < sizeof(inv); i++) 
			{
				if (!arrayp(inv1))
				{
					inv1=({inv[i]});
					count=({1});
				}
				else
				{
					for (j = 0; j < sizeof(inv1); j++)
						if  ( (base_name(inv[i])==base_name(inv1[j])) && (inv[i]->query("name") == inv1[j]->query("name")) )
							break;
						if (j == sizeof(inv1) || userp(inv[i]))
						{
							inv1+=({inv[i]});
							count+=({1});
						}
						else
							count[j]+=1;
				}                
			}
			for(i=0; i<sizeof(inv1); i++) 
			{
				if( inv[i]==this_player() ) continue;
				
				if( !userp(inv[i]) && inv[i]->query("no_show") ) continue;
				if( !this_object()->visible(inv[i]) ) continue;
				
				if(count[i]==1)
					str += "    "+inv1[i]->short()+"\n";
				else
					str +="    "+chinese_number(count[i]) +"" + inv1[i]->query("unit") +""+ inv1[i]->short()+"\n";
			}
			
			if (query("env/brief") > 1 && query("env/brief")!= "YES")
			{
				if( mapp(exits = environment()->query("exits")) ) 
				{
					dirs = keys(exits);
					for(i=0; i<sizeof(dirs); i++)
						if( (int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED )
							dirs[i] = 0;
						dirs -= ({ 0 });
						if( sizeof(dirs)==0 )
							str += "    这里没有任何明显的出路。\n";
						else if( sizeof(dirs)==1 )
							str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
						else
							str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
							implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
				}
			}
			tell_object(this_object(), str);
		}
		else
			command("look");
	}
	
	if( this_object()->is_character() && (depth = (int)environment()->query_temp("depth")) ) {
		this_object()->start_busy(depth);
		message_vision("$N一不小心跌进了陷坑里，连忙手忙脚乱地往上爬。\n", this_object());
		environment()->add_temp("depth", -1);
	}
	if ((this_object()->query("is_monitored") || file_name(this_object())[0..2]=="/u/") && userp(ob) && (!this_object()->query_temp("no_monitor")))
		MONITOR_D->report_system_object_msg (ob,"得到了"+
		this_object()->query("name")
		+"("+file_name(this_object())+")。");
	if(file_name(this_object())[0..2]=="/u/" && userp(ob)&&!wizardp(ob)) 
		{
			MONITOR_D->report_system_object_msg(ob,"刚的到的"
				+this_object()->query("name",1)+"不翼而飞了！\n");
			destruct(this_object());
			return notify_fail("玩家不能使用超级物件！\n");
		}
	return 1;
}

void remove(string euid)
{
	object default_ob;
	
	if( !previous_object()
		||	base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() can only be called by destruct() simul efun.\n");
	
	if( userp(this_object()) && euid!=ROOT_UID ) {
		log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
			euid, this_object()->query("id"), ctime(time())));
		error("你(" + euid + ")不能摧毁其他的使用者。\n");
	} else if( this_object()->query("equipped")) {
		if(	!this_object()->unequip() )
			log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
	}
	
	// We only care about our own weight here, since remove() is called once
	// on each destruct(), so our inventory (encumbrance) will be counted as
	// well.
	if( environment() )	environment()->add_encumbrance( - weight );
	if( default_ob = this_object()->query_default_object() )
		default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
	if( userp(this_object()) ) {
		tell_object(this_object(), "一阵时空的扭曲将你传送到另一个地方....\n");
		move(VOID_OB);
	}
}

object ride()
{
	object me = this_object();
	string ridemsg = "";
	object ridee;
	
	if (ridee = me->query_temp("ridee")) { 
		if ((environment(ridee) != environment(me) &&
			environment(ridee) != me) ||
			(ridee->is_character() && ! living(ridee))) {
			me->set_temp("ridee",0);
			ridee->set_temp("rider",0);
			ridee = 0;
		}
	}
	if (! ridee) {
		me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
		me->set_temp("ride/dodge",0);
	}
	return ridee;
}

