// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// move.c
// 4/24/98 mon adds max_items related stuff.
//Last Created By snowtu 2007.05.01加入Valid_move()函数判定
#pragma optimize

#include <dbase.h>
#include <room.h>
#include <ansi.h>

nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;

varargs int _move(mixed dest, int silently);
void dest_obj(object obj);

nosave int max_items=50; // default max_items.
nomask void set_max_items(int e) {max_items=e;}
nomask int query_max_items() {return max_items;}

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }

nomask void add_encumbrance(int w)
{
	encumb += w;
	if( encumb < 0 )
        	log_file("move.bug", file_name(this_object())+this_object()->query("id")+" encumbrance underflow. env:"+file_name(environment())+" w:"+w+"\n");
	if( encumb > max_encumb ) this_object()->over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
	if( !userp(this_object()) ) return;
	tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }

nomask void set_weight(int w)
{
	if( !environment() ) 
        {
        	weight = w;
        	return;
        }
	if( w!=weight ) environment()->add_encumbrance( w - weight );
	weight = w;
}

nomask int weight() { return weight + encumb; }

string ride_suffix (object me)
{
	string ridemsg = 0;
	object ridee = 0;

	ridee = me->ride();
	if(ridee)
        	ridemsg = ridee->query("ride/msg")+"在"+ridee->name()+"上";
	return  ridemsg;
}

// silently=1: no look.
// silently=2: only room name. (for follow)
// silently=0: full look.
// mon 4/20/98
varargs int move(mixed dest, int silently)
{
	if(_move(dest, silently)) return 1;
	call_out("dest_obj", 2, this_object());
	return 0;
}

// destruct obj if it failed to move and has no environment.
void dest_obj(object obj)
{
	if(obj && !environment(obj))
        	destruct(obj);
}

varargs int _move(mixed dest, int silently)
{
	object ob, env, *inv, me;
	int i;
	mapping exits;
	string str="", str1="", *dirs,nomove;
	string ridemsg="";

	me = this_object();

	if( environment() && objectp(environment()) && me->is_character() )
        {
        	if( stringp(nomove=environment()->valid_move(me)) )
                	return notify_fail( nomove );
        }
	if( query("equipped") && !this_object()->unequip() )
        	return notify_fail("你没有办法取下这样东西。\n");
	if( objectp(dest) )
        	ob = dest;
	else if( stringp(dest) ) 
        {
        	ob = load_object(dest);
        	if(!ob)
                	return notify_fail("move: destination unavailable.\n");
        } 
	else    return notify_fail(sprintf("move: invalid destination %O.\n", dest));

  // check for max_items.
	if( (!me->is_character() || ob->is_job() ) && sizeof(all_inventory(ob))>=ob->query_max_items() ) 
        {
        	if( ob==this_player() )
                	return notify_fail("你身上装不下更多东西了。\n");
        	else if( userp(ob) )
                	return notify_fail(ob->name()+"身上装不下更多东西了。\n");
        	else    { // for rooms and container.
                	string name=ob->name();
                	if(!name) name=ob->query("short");
                	if(!name) name=ob->short();
                		return notify_fail(name+"已经太拥挤了。\n");
                }
        }

	env = this_object();
	if( env==ob ) 
        	return notify_fail("你不能把物品放入自身之中。\n");//mon 8/25/97
	while( env=environment(env) ) 
        {
        	if( env==ob ) 
                	break;
        }
	if( !env && (int)ob->query_encumbrance()+weight()> (int)ob->query_max_encumbrance() ) 
        {
        	if( ob==this_player() )
                	return notify_fail( this_object()->name() +"对你而言太重了。\n");
        	else    return notify_fail( this_object()->name() +"对" + ob->name() + "而言太重了。\n");
        }

	if( environment() )
        {
        	environment()->add_encumbrance( - weight());
        	if( userp(environment()) 
          	&& this_object()->value()>=10000 )
	                environment()->save();
        }
	ob->add_encumbrance(weight());
	move_object(ob);

	if(!this_object()) return 0; //mon 8/24/97

	if( interactive(this_object())   // are we linkdead?
  	 && living(this_object())    // are we still concious?
  	 && silently!=1 ) 
        {
		if(this_object()->query_temp("new_id")&&!this_object()->query("start"))
                {
                	this_object()->set("start",1);
                	tell_object(this_object(),"\n");
                }
        	else if( silently==2 || this_object() -> query("env/brief_all") )
                	tell_object(this_object(), environment()->query("short") ? environment()->query("short")+"\n": "\n");
        	else if( this_object()->query("env/brief") )
                {
                	str = sprintf( "%s\n",
                        	environment()->query("short") ? environment()->query("short"): "",file_name(environment()));
                	if( mapp(exits = environment()->query("exits")) ) 
                        {
                        	dirs = keys(exits);
                        	for(i=0; i<sizeof(dirs); i++)
                                {
                                	if( (int)environment()->query_door(dirs[i],"status") & DOOR_CLOSED )
                                        	dirs[i] = 0;
                                }
                        	dirs -= ({ 0 });
                        	if( sizeof(dirs)==0 )
                                	str += "  这里没有任何明显的出路。\n";
                        	else if( sizeof(dirs)==1 )
                                	str += "  这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                        	else    str += sprintf("  这里明显的出口是 " + BOLD + "%s" + NOR + " 和 "+ BOLD + "%s" + NOR + "。\n",          implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
                        }
                	inv = all_inventory(environment());
                	i=sizeof(inv);
                	while(i--) 
                        {
                        	if( !me->visible(inv[i]) ) 
                                	continue;
                        	if( inv[i]==me ) 
                        		continue;
                        	if(ridemsg=ride_suffix(inv[i]) )
                                	str1 = " " + inv[i]->short() + " <"+ridemsg +">\n"+str1;
                        	else    str1 = " " + inv[i]->short() + "\n"+str1;
                        }
                	tell_object(this_object(), str+str1);
                }
        	else command("look");
        }
// the following is made by snowcat on 6/20/1997
// modified by mon 8/29/97
	if( (this_object()->query("is_monitored") 
          || file_name(this_object())[0..2]=="/u/")
  	 && userp(ob) )
        	MONITOR_D->report_system_object_msg (ob,"得到了"+this_object()->query("name")+"("+file_name(this_object())+")。");
	return 1;
}

void remove(string euid)
{
	object default_ob;
	if( !previous_object()
   	|| base_name(previous_object())!=SIMUL_EFUN_OB )
        	error("move: remove() can only be called by destruct() simul efun.\n");
	if( userp(this_object()) && euid!=ROOT_UID ) 
        {
        	log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",euid, this_object()->query("id"), ctime(time())));
        	error("你(" + euid + ")不能摧毁其他的使用者。\n");
        } 
	else if( this_object()->query("equipped")) 
        {
        	if(  !this_object()->unequip() )
                	log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
        }
	if( environment() )  
        	environment()->add_encumbrance( - weight );
	if( default_ob = this_object()->query_default_object() )
        	default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
	if( userp(this_object()) ) 
        {
        	tell_object(this_object(),"一阵时空的扭曲将你传送到另一个地方．．．\n");
        	move(VOID_OB);
        }
}

//snowtu 2006 rewrite for Pet SystemV2.0
object ride ()
{
	int i;
  	object me = this_object();
  	string *data,ridemsg = "";
  	mapping prop;
  	object ridee;

  	if( ridee = me->query_temp("ridee")) 
  	{ 
		if( (environment(ridee) != environment(me) 
		  && environment(ridee) != me) 
		 || (ridee->is_character() && ! living(ridee))) 
		{
      			me->set_temp("ridee",0);
      			ridee->set_temp("rider",0);
      			ridee = 0;
    		}
  	}
  	if( !ridee ) 
  	{
  		if( mapp(prop=me->query_temp("ride")) )
  		{
  			data = keys(prop);
  			for(i=0;i<sizeof(data);i++)
				me->add_temp("apply/"+data[i],-prop[data[i]]);
		}		
    		me->set_temp("ride/dodge",0);
  	}
  	return ridee;
}