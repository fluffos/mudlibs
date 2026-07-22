// condition.c
#include <condition.h>

mapping conditions;

nomask int update_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) 
		return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) 
	{
		cnd_d = find_object(CONDITION_D(cnd[i]));
		if( !cnd_d ) 
		{
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));

			if( err || !cnd_d ) 
			{
				log_file("condition.err",sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",CONDITION_D(cnd[i]), this_object(), err) );
				map_delete(conditions, cnd[i]);
				continue;
			}
		}
		
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		if( !( flag & CND_CONTINUE ) ) 
		{
		    if(conditions) map_delete(conditions, cnd[i]);
		    else break;
		}
		update_flag |= flag;
	}
	if( !sizeof(conditions) ) conditions = 0;

	return update_flag;
}

nomask void apply_condition(string cnd, mixed info)
{
	object cnd_d;
	mixed err,Ncon;
	
	cnd_d = find_object(CONDITION_D(cnd));
	if( !cnd_d ) 
	{
		err = catch(call_other(CONDITION_D(cnd), "???"));
		cnd_d = find_object(CONDITION_D(cnd));
		if( err || !cnd_d ) 
		{
			log_file("condition.err",sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",CONDITION_D(cnd), this_object(), err) );
			return;
		}
	}
	Ncon = this_object()->query_temp("no_condition");
	if( Ncon && cnd_d->can_free() )
	{
		if( stringp(Ncon) )
			message_vision(Ncon,this_object());
		return;
	}		
	if( cnd_d->no_apply(this_object()) )
		return;
	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else	conditions[cnd] = info;
}

nomask varargs mixed query_condition(string cnd)
{
	if(!cnd) 
		return conditions;
	if( !mapp(conditions) || undefinedp(conditions[cnd]) ) 
		return 0;
	return conditions[cnd];
}

nomask varargs void clear_condition(string name)
{
	mixed *cnd;
	int i;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) 
		return 0;
	
	if(name) 
	{ 
		//不能不clear函数强制清除的cond，比如任务之类，只能因
		//update_condition()而自动清除
		if( CONDITION_D(name)->no_clear_condition() )
			return;		
	    	map_delete(conditions, name);
	    	if( !sizeof(conditions) ) 
	    		conditions = 0;
	    	return;
	}

	cnd = keys(conditions);

	while(i--) 
	{
		cnd_d = load_object(CONDITION_D(cnd[i]));
	  	if(!cnd_d) 
	  	{
	      		map_delete(conditions, cnd[i]);
	      		continue;
	  	}
		if( !(cnd_d->no_clear_condition()) )
	      		map_delete(conditions, cnd[i]);
	}
	if( !sizeof(conditions) ) conditions = 0;
}
 
