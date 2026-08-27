object myplayer;
void dispell_me()
{
	if(myplayer)
	{
	 	tell_object(myplayer,"The aura of fear surrounding you disappates.\n");
		myplayer->set_wimpy(0);
	}
	call_out("dest_me",0);
}

int query_wimpy() { return 100; }
int set_wimpy(int wimpy)
{
   myplayer->set_wimpy(100);
   return 100;	
}   

void setup_shadow(object victim)
{
   if(victim) 
   {
   	shadow(victim,1);
   	myplayer = victim;
   	myplayer->set_wimpy(100);
   	myplayer->run_away();
	
   }
   else call_out("dest_me",0);
}
void dest_me()
{
   destruct(this_object());
}
      	
