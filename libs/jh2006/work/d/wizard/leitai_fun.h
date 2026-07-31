
string look_leitai()
{
    	object me, room;
    	me = this_player();
    
    	if (me->is_busy()) 
          	return "你正忙着呢。\n";
    	me->start_busy(2);
    	if (!(room = find_object(query("leitai"))))
          	room = load_object(query("leitai"));
        if( !room ) 
        	return "比武擂台没有准备好，请通知巫师。\n";  
    	message_vision("$N挤到擂台边，伸长了脖子向上望去。\n", me);
    	"/cmds/std/look.lpc"->look_room(this_player(), room); 
    	return "";
}

int valid_leave(object me, string dir)
{
	object room;
	int i;
	
	if( dir != "out" && !wizardp(me)){
		if (!objectp(room = find_object(this_object()->query("exits/"+dir))))
          		room = load_object(this_object()->query("exits/"+dir));
          	
        	i = room->query_temp("num");
        	if( i > 15 ){
        		me->start_busy(1);
        		return notify_fail(room->query("short")+"已经人满为患，你挤不进去！\n");
        	}
        }
	if(query_temp("num")) add_temp("num", -1);
	return ::valid_leave(me,dir);
}

int do_action(string arg)
{
	this_player()->start_busy(2);
   	write("\n你正要有所动作，突然身旁有人将你一拍：好好看比武，别乱动！\n\n");
   	return 1;
}
