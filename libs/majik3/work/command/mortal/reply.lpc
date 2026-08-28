int main(string str)
{  
    object ob;
    string *ltell;
    string viimoisin,who;

    if (!str) {
	write("Reply what?\n"); 
	return 1; 
    }
    else {  
	ltell = THIS->query_last("tell");
	viimoisin = ltell[sizeof(ltell)-1];
	sscanf(viimoisin,"%s told you", who);
	if(ob = find_player(lower_case(who))) 
	    THIS->force_us("tell "+ob->query_name()+" "+str);
	else 
	    write("No such player.\n");
    } 
    return 1;
}
query_position()
{
  return POS_RESTING;
}

