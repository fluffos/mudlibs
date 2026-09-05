string query_save_file()
{
		return replace_string(file_name(),"/file/","/save/");
}

int save()
{
        string file;
		int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                return result;
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file,1))
        {
                return 1;
        }
        return 0;
}

string check_str(string str)
{ 
    str=replace_string(str,"\"","");
    str=replace_string(str,";","");
    str=replace_string(str,"\\","");
    str=replace_string(str,"/","");
    str=replace_string(str,"'","");
    str=replace_string(str,"`","");
    str=replace_string(str,",","");
    str=replace_string(str,"!","");
    str=replace_string(str,"~","");
    str=replace_string(str,"{","");
    str=replace_string(str,"}","");
    str=replace_string(str,"$","");
    str=replace_string(str,"&","");
    return str;
}

int do_set_long(string arg)
{
	if (!arg)
		return notify_fail("格式：set_long <描述>\n");
	arg=check_str(arg);
	set("long",changecolor(arg)+"\n");
	save();
	restore();
	tell_object(this_player(),"修改描述成功。\n");
	return 1;
}

void init()
{
	object link_ob,me,*inv;
	string id,mes,outroom;
	int roomvalue,createtime,checktime,i,closetime;
	me=this_player();
	link_ob=me->query_temp("link_ob");
	if(!link_ob) return;
	id=link_ob->query("id");

//这里加上判断房间物品时间，损坏程度等等
	roomvalue=(int)query("roomvalue");
	checktime=(int)query("checktime");
	createtime=(int)query("createtime");
	if( !checktime )
		checktime=createtime;
//	一年，24小时=86400
	roomvalue-=(int)((time()-checktime)/17280);//一天降5点roomvalue
	//这里要加上再减roomvalue的语句，客栈越豪华，赚钱越多，roomvalue减得越快
	if(roomvalue<0) roomvalue=0;
	set("ckecktime",time());
	if(roomvalue==0)
	{
		if(query("room_ok"))
		{
			delete("room_ok");
			CHANNEL_D->do_channel(this_object(), "rumor", "听说" + query("host") + "的" + query("short") + "由于修缮不力倒塌了。");
		}
		tell_object(me,HIR+BNK"你发现这个房间马上就要倒了，看来需要赶紧离开了。\n"NOR);
		set("short","倒塌的小屋");
		set("long","这是一间倒塌了的房间，你还是尽快离开得好。\n");
		call_out("kickplayer",5,me,environment(me));//5秒钟后不离开，房子倒塌，玩家被砸晕
	}
	set("roomvalue",roomvalue);
	save();
//检查房间完毕，检查物品
//应该把物品都destruct掉
	inv=all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("selfcreate"))//表明是自己创建得
		{
			//暂时什么都不做，需要把物品也做成需要save得object
		}
	}
		if(roomvalue==0)
			mes=HIR"你发现这间房子摇摇欲坠，不禁害怕起来。\n"NOR;
		else if(roomvalue<100)
			mes="这是一间很普通的房子。\n";
		else if(roomvalue<500)
			mes="这是一间装修过得房子，看起来马马虎虎。\n";
		else if(roomvalue<1000)
			mes="很不错的房间，看起来很舒适。\n";
		else if(roomvalue<2000)
			mes="这是一间很不错的房间，看起来很豪华。\n";
		else if(roomvalue<3000)
			mes="一间金壁辉煌的房间，看起来已经有点奢侈了。\n";
		else
			mes=HIY"这个房间看起来如同皇宫一样，看得出主人真是奢侈极了。\n"NOR;

	if( id==query("host") )
	{//短描述固定
		add_action("do_set_long","set_long");//设定房间描述
	}
}
