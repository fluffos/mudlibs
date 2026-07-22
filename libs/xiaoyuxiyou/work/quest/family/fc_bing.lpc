inherit ROOM;
#include <ansi.h>

void create()
{
	set ("short", "练功场");
  	set ("long", @LONG


LONG);
	set("broadcast",1);
	setup();
}

void broadcast_room (object room, string str)
{
	string prefix;
	string s1 = str, s2 = "", s3;	
	int i;	
	if( !room )
		return;
	prefix = query("short");
	prefix = sprintf(HIR"【"HIY"%s"HIR"】"NOR,prefix);
    	reset_eval_cost();
  	s1=replace_string(s1,"\n"NOR,"\n");
	while (strsrch(s1,"\n\n") != -1)
    		s1 = replace_string(s1,"\n\n","\n");
	while (sizeof(s1)>1 && s1[sizeof(s1)-1]=='\n')
  	{
    		s1 = s1[0..(sizeof(s1)-2)];
    		s2 = "\n";
  	}
  	if( sizeof(s1) <= 1)
    		return;
	s1 = replace_string(s1,"\n","\n"+prefix);
	tell_room (room, prefix+s1+ NOR+"\n");     
}

void broadcast(string msg) 
{
	object room=load_object("/d/lingtai/inside2");
  	if(room) 
  		broadcast_room(room,msg);
}

void init()
{
	add_action("do_exert","exert");
	add_action("do_eat","eat");
}

int do_eat()
{
	return err_msg("ok\n");
}
	
int do_exert()
{
	string verb;
	object me = this_player();
	if( userp(me) )
	{
		verb = query_verb();
		if( verb=="exert recover" )
		{
			if( random(10)>0 )
			{
				tell_object(me,"你深深吸了几口气，脸色看起来好多了。\n");
				return 1;
			}
		}
		me->start_busy(random(2));
	}
	return 0;
}
				
