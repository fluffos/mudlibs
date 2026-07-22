// action.c

nosave mixed busy=0, interrupt;
nosave mapping override;

nosave mapping blind = ([
	"time" : 0,
	"start": 0,
	"msg"  : 0,
]);	
nosave mapping hunluan = ([
	"time" : 0,
	"start": 0,
	"msg"  : 0,	
]);	
nosave mapping no_move = ([
	"time" : 0,
	"start": 0,
	"msg"  : 0,	
]);	
nosave mapping yinshen = ([
	"time" : 0,
	"start": 0,
]);

mixed is_blind()
{ 
	int p = blind["time"]+blind["start"]-time();
	if( p<=0 )
		return 0;
	if( undefinedp(blind["msg"]) )
		return p;		
	return stringp(blind["msg"])?blind["msg"]:p;
}
	
int is_yinshen()
{ 
	int p = yinshen["time"]+yinshen["start"]-time();
	if( p<=0 )
		return 0;
	return p;	 
}

mixed is_hunluan()
{ 
	int p = hunluan["time"]+hunluan["start"]-time();
	if( p<=0 )
		return 0;
	if( undefinedp(hunluan["msg"]) )
		return p;		
	return stringp(hunluan["msg"])?hunluan["msg"]:p;
}
		
mixed is_no_move()
{ 
	int p = no_move["time"]+no_move["start"]-time();
	if( p<=0 )
		return 0;
	return p;		
}	

void stop_yinshen()
{
	yinshen = ([
		"time" : 0,
		"start": 0,
	]);
}

varargs void start_blind(int v,string msg)
{
	if( !msg ) msg = "";
	blind = ([
		"time" : v,
		"start": time(),
		"msg"  : msg,
	]);
}		

void start_yinshen(int v)
{
	yinshen = ([
		"time" : v,
		"start": time(),
	]);
}

string query_blind_msg()
{
	if( undefinedp(blind["msg"])
	 || !blind["msg"] )
		return "";
	return 	blind["msg"];
}	 

varargs void start_hunluan(int v,string msg)
{
	if( !msg )  msg = 0;	
	hunluan = ([
		"time" : v,
		"start": time(),
		"msg"  : msg,
	]);
}

string query_hunluan_msg()
{
	if( undefinedp(hunluan["msg"])
	 || !hunluan["msg"] )
		return "";
	return 	hunluan["msg"];
}	 

varargs void start_no_move(int v,string msg)
{
	int p;
	if( !msg )
		msg = "你现在不能移动！\n";
	if( this_object()->query_skill("feisha-zoushi",2)>1 
	 && this_object()->query_skill("feisha-zoushi",1)>100 )
	{
		p = (this_object()->query_skill("feisha-zoushi",1)-100)/360+1;
		if( p>=v )
			return;
		v = v-p;		
	}	
	no_move = ([
		"time" : time(),
		"start": v,
		"msg"  : msg,
	]);
}

string query_no_move_msg()
{
	if( undefinedp(no_move["msg"])
	 || !no_move["msg"] )
		return "";
	return 	no_move["msg"];
}	

varargs void start_busy(mixed new_busy, mixed new_interrupt,object by_target)
{
	int p;
	object target;
	if( !new_busy ) 
		return;
	if( !intp(new_busy) && !functionp(new_busy) )
		error("action: Invalid busy action type.\n");
	if( !intp(new_interrupt) && !functionp(new_interrupt) )
		error("action: Invalid busy action interrupt handler type.\n");		
	if( intp(new_busy) )
	{
		if( by_target && objectp(by_target) && by_target->is_fighting(this_object())
		 && by_target!=this_object() )
		{
			if( intp(p=by_target->query_skill("zhenshan-handi",2))
			 && p>100 )
				p = 1+(p-100)/300;
			new_busy+= p;
			if( intp(p=this_object()->query_temp("apply/reduce_busy"))
			 && p>0 )
				new_busy = new_busy-p;
				
		}		 
		if( new_busy<1 )
			new_busy = 1;			 
	}
	busy = new_busy;
	interrupt = new_interrupt;
	set_heart_beat(1);
}

nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy!=0; }

nomask varargs int stop_busy(int v) 
{
	if( busy==0 )
		return 0;
	if( v && v>0 )	
		busy-= v;
	else	busy = 0;	
	if( busy<=0 )
	{
		busy = 0;	
		interrupt = 0;
	}	
	return v;
}	

void continue_action()
{
	int p = 0;
	if( intp(busy) && (busy > 0) ) 
	{
		busy--;
		if( p=this_object()->query_temp("apply/reduce_busy")>0 
		 && this_object()->is_fighting() )
			p = busy*p/100;
		busy = busy-p;
		return;
	} else if( functionp(busy) ) {
		if( !evaluate(busy, this_object()) ) {
			busy = 0;
			interrupt = 0;
		}
	} else {
		busy = 0;
		interrupt = 0;
	}
}

void interrupt_me(object who, string how)
{
	if( !busy ) return;

	if( intp(busy) && intp(interrupt) ) {
	  if( busy < interrupt ) busy = 0;
	} else if( functionp(interrupt) ) {
		if( evaluate(interrupt, this_object(), who, how) ) {
			busy = 0;
			interrupt = 0;
		}
	}
}
/*
int start_call_out(function fun, int delay)
{
	if(( !previous_object()
	||  (geteuid(previous_object()) != ROOT_UID
	     && userp(this_object())
	     && this_player(1) != this_object()))
	     )
		return 0;
	call_out("eval_function", delay, fun);
	return 1;
}
*/
int start_call_out(function fun, int delay)
{
	if(( !previous_object()
	||  (geteuid(previous_object()) != ROOT_UID
	     && userp(this_object())
	     && this_player(1) != this_object()))
	     )
		return 0;
	//I won't bind the function because it will cause a serious security problem.
	if( SECURITY_D->get_status(this_object())=="(admin)"
	 && this_object()->query("env/test") )
		call_out("eval_function", delay, fun);
	// if this_object() doesn't be a wizard, I will bind the function, then the player doesn't occur error when the function's owner be destructed.
	else	call_out("eval_function", delay, bind(fun, this_object()));
        return 1;
}

void eval_function(function fun) { evaluate(fun); }

nomask int set_override(string index, function fun)
{
        if (! previous_object() ||
            geteuid(previous_object()) != ROOT_UID)
                return 0;

        if (! override)
                override = ([ ]);

        override[index] = bind(fun, this_object());
        return 1;
}

nomask mixed query_override(string index)
{
        if (! is_root(previous_object()))
                return 0;

        if (! index) return override;
        if (! override) return 0;
        return override[index];
}

nomask int run_override(string index)
{
        function fun;

        if (! override || ! functionp(fun = override[index]))
                return 0;

        map_delete(override, index);
        if (! sizeof(override)) override = 0;
        return (*fun)(this_object());
}

nomask void delete_override(string index)
{
        if (! override) return;
        map_delete(override, index);
        if (! sizeof(override)) override = 0;
}