
string query_autoload()
{   
	
	if(!query("save_flag")||query("no_save")||query("rumor"))
	 return 0;
	
	if(!query("long")) set("long",this_object()->short()+"\n");
	return 
	       query("name")+" "+
	       query("long")+" "+
	       query("dlev");	       
	       
	      
}

void autoload(string pa)
{   
    string name,longs;
    int dlev;
    
    if(sscanf(pa,"%s %s "+
                 "%d",
       name,longs,
       dlev)==3)
	{   	    
	    set("name",name);
	    set("long",longs);
	    set("dlev",dlev);
	    
	    set("save_flag",1);
	}
	return;
}
