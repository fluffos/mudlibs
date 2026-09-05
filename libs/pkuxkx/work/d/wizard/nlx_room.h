//自助蜡像
// npc生成头文件，all@pkuxkx，2012/12/07

int block_cmd();

void init()
{   
	object me=this_player();
	object ob,room;
	int laxiang_num;
	string file_num;
	string menpai, menpai_name;	
	room=this_object();
	menpai=room->query("menpai");
	menpai_name=room->query("menpai_name");
	laxiang_num = LAXIANG_D->get_location(menpai)-1;
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
	if (query("count") < 1)
		return;
	if(interactive(me))
	{
    		for (int a=laxiang_num;a>0;a--)
    		{    	    
			file_num=sprintf("%d",a);
    			ob = new("/d/wizard/laxiang2/"+menpai_name+file_num+".lpc");
			ob->move(room);
    		}
	}          
	add("count", -1);
}

int block_cmd()
{        
       string verb = query_verb();  
       if (verb=="say") return 0; //allow say  
       if (verb=="chat") return 0;                
       if (verb=="quit") return 0;                                                         
       if (verb=="look") return 0;                
       if (verb=="out") return 0; 
       return 1;                                   
}                                                 
