/* IMMORTAL BAN COMMAND 
 *
 *       -- Must be over lv 30 to use it I guess
 * 
 */
#define info(x)         THIS->force_us("info "+x);
int
main (string str)
{
    string name,host,reason,name_host;
    int i,j,time,pos;
    string *ar;
    string *n_ar;
    if(read_file("data/ban/ban.o")) {
	ar = explode(read_file("/data/ban/ban.o"),"\n");
    }
    else
	ar = ({});
    if(THIS->query_security() < 30) {
	write("Permission Denied.\n");
	return 1;
    }
    if (!str)
    {
	notify_fail(wrap("Usage   : ban <[name or @host]> <time> <reason>\n"+
	    "Example   : ban madrid 1 idiot\n"+
	    "This would ban madrid  for one days reason idiot.\n"
	    "You can also ban a site with ban.\n"+
	    "Example   : ban @majik.netti.fi 2 foo\n"+
            "You can also remove the ban something.\n"+
            "Example   : ban @majik.netti.fi 0 foo.\n"));
	return 0;
    }
    if(str == "debug") {
	for(i=0;i<sizeof(ar);i++) {
	    write("banned : "+ar[i]+"\n");
	}
	return 1;
    }
    if(sscanf(str,"%s %d %s",name_host,time,reason) != 3) {
	notify_fail(wrap("Usage   : ban <name or @host> <time> <reason>\n"+
	    "Example   : ban madrid 1 idiot\n"+
	    "This would ban madrid  for one days reason idiot.\n"
	    "You can also ban a site with ban.\n"+
	    "Example   : ban majik.netti.fi 2 foo\n"+
            "You can also remove the ban something.\n"+
            "Example   : ban @majik.netti.fi 0 foo.\n"));

	return 0;
    }
    else {
	if(time == 0) { 
	    if((pos = member_array(64,name_host)) >= 0) {
		host = replace_string(name_host,"@","",pos,sizeof(name_host));
		if(member_array(host,ar) >= 0) {
		    ar -= ({host});
		    write("Removed ban on host "+host+".\n");
		    info(THIS->query_cap_name()+
		      " has removed the ban on host "+host);
		    write_file("/data/ban/ban.o",implode(ar,"\n"),1);
		    return 1;
		}
		else {
		    write("That host is not currently banned.\n");
		    return 1;
		}
	    }
	    else {
		if(member_array(name_host,ar) >= 0) {
		    ar -= ({name_host});
		    write_file("/data/ban/ban.o",implode(ar,"\n"),1);   
		    write("Removed ban on "+name_host+".\n");  
		    info(THIS->query_cap_name()+" has removed the ban "+
		      "on player "+capitalize(name_host));
		    return 1;
		}
		else {
		    write("That player has not been banned yet.\n");
		    return 1;
		}
	    }
	}
	else {
	    if((pos = member_array(64,name_host)) >= 0) {
		host = replace_string(name_host,"@","",pos,sizeof(name_host));
		if(member_array(host,ar) < 0) {
		    ar += ({host});
		    write("Banned host "+host+".\n");
		    info("Host "+host+" banned.");
		    write_file("/data/ban/ban.o",implode(ar,"\n"),1);
		    return 1;
		}
		else {
		    write("That player is already banned.\n");
		    return 1;
		}
	    }
	    else {   
		if(member_array(name_host,ar) < 0) {
		    ar += ({name_host});
		    write_file("/data/ban/ban.o",implode(ar,"\n"),1);
		    write("Banned player "+name_host+" for "+
		      time+" days, reason : "+reason+"\n");
		    info(capitalize(name_host)+" banned.");
		    return 1;
		}
		else {
		    write("That player is already banned.\n");
		    return 1;
		}
	    }
	}
    }
}
