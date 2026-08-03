
void init()
{
        object me;
        me = this_player();

        me->set_temp("wdpass/address",environment(me)->query("wdpass"));
        if (interactive(me) 
         && ! me->is_fighting()
         && me->query_temp("wdpass/done") < 9){
                remove_call_out("greeting");
                call_out("greeting", 4 + random(5), me);
        }
}

int greeting(object me)
{
        string str, steps;
        string* step = ({"south", "north", "east", "west"});

        if( !me) return 0;
        if( query("wdpass") != me->query_temp("wdpass/address")) return 0;

        str = step[random(sizeof(step))];
        switch (str){
            case "south": steps ="南"; break;
            case "north": steps ="北"; break;
            case "east":  steps ="东"; break;
            case "west":  steps ="西"; break;
            default : return notify_fail("发生问题，请向巫师汇报。\n");
        }
        if( me->query_temp("wdpass/done") < 8 ){
            me->set_temp("wdpass/step", str);
            me->set_temp("wdpass/steps", steps);
        }
        else { 
            me->set_temp("wdpass/step", "south");
            me->set_temp("wdpass/steps", "南");
        }
        me->delete_temp("wdpass/dontgo");
        tell_object(me,HIY"你站在小径上，四周打量，仿佛看见"+ me->query_temp("wdpass/steps") +"面有些亮光。\n"NOR);
        return 1;
}

int valid_leave(object me, string dir)
{
	if( dir != me->query_temp("wdpass/step")){
		me->add_temp("wdpass/fail", 1);
		if( me->query_temp("wdpass/done") > 0)
 		   me->set_temp("wdpass/done", 0);
 		else
 		   me->add_temp("wdpass/done", -1);
		if ( me->query_temp("wdpass/fail") >= 4 +random(3)
		  && dir == "north"){
		  	me->delete_temp("wdpass");
                        tell_room(environment(me), me->name()+"往北面的"YEL"小径"NOR"快步离开。\n"NOR, ({ me }));
			me->move(__DIR__"xiaolu2");
                        tell_room(environment(me), me->name()+"从"YEL"小径"NOR"快步走了过来。\n"NOR, ({ me }));
			return notify_fail("");
		}
	}
	else {
		me->add_temp("wdpass/done", 1);
		if (me->query_temp("wdpass/done") >= 9){
                        me->delete_temp("wdpass");
                        tell_room(environment(me), me->name()+"往南面的"WHT"院门"NOR"快步离开。\n"NOR, ({ me }));
	       	        me->move(__DIR__"yuanmen");
                        tell_room(environment(me), me->name()+"从"YEL"小径"NOR"快步走了过来。\n"NOR, ({ me }));
		        return notify_fail("");
		}
	}
       	me->delete_temp("wdpass/step");
        return ::valid_leave(me, dir);
}
