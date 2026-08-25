// troopinfo.c
// by group on Mar 2000
string s_ret;
string p_where;
int i_amt;
int get_t_id(string tid)
{
   string id;
   if(tid[0..4]!="troop") return -1;
   id=tid[5..<1];
   return to_int(id);
}


void start(string arg)
{
        int troop_id;
	string p_id,t_name;
	string chars;
	int t_id,pt_id;

        p_id=this_body()->query_primary_id();
	pt_id=TROOP_D->get_char_troop(this_body()->query_id()[0]);	
	if(!pt_id)
	{write("战争中才可以查看部队指挥官。\n");
	return;
	}
	
	if(t_id=get_t_id(arg)<0)
	{write("你要查看哪一只部队？\n");
		return;
	}
	
	t_id = get_t_id(arg);	
	t_name = TROOP_D->get_troops(t_id,"name");	
 	if(TROOP_D->get_troops(t_id,"area")!=TROOP_D->get_troops(pt_id,"area"))
	{ write("你管别的战场干嘛？\n");
		return;
	}

	write(t_name+"中的指挥官有:  \n");
	   chars=TROOP_D->get_troops(t_id,"chars");
   foreach(string c in chars)
   {
      write (CHAR_D->get_char(c,"name")+"("+c+") \n");	
            
   }

	return;
}
