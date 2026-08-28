//	Command which handles the inform daemon which provides system
//	info to players and wizzes
//	Diewarzau 3/17/94



int cmd_inform(string str) {
    string *inf_types;
    string tmp;
    int i,j;
    string *inf_heard, *inf_block;

    inf_heard = this_player()->query_inform();
    inf_block = this_player()->query_all_inf_blocked();
    if(!inf_heard) inf_heard= ({});
    if(!inf_block) inf_block = ({});
    if(!str) {
	if(!sizeof(inf_heard))
	    return notify_fail("No information is available to you.\n");
	i=sizeof(inf_heard);
	while(i--) {
	    tmp = "You ";
            if(member_array(inf_heard[i],inf_block) > -1)
		tmp += "do not ";
	    tmp += "receive mesages concerning ";
	    tmp += implode(explode(inf_heard[i],"_")," ") + ".";
	    write(tmp);
	}
	return 1;
    }
    str = implode(explode(str," "),"_");
    if(member_array(str,inf_heard) < 0) 
	return notify_fail("Invalid information type.\n");
    if(member_array(str,inf_block) > -1)
	{
	 write("No longer blocking type: "+implode(explode(str,"_")," "));
	 inf_block = exclude_array(inf_block,member_array(str,inf_block));
	}
	else
	{
	 write("Now blocking type: "+implode(explode(str,"_")," "));
	 inf_block = distinct_array(inf_block + ({ str }));
	}
    this_player()->set_inf_block(inf_block);
    return 1;
}

int help() {
    write("inform: mortal command\n"+
	"\nform: inform <message-type>\n"+
	"\nIf message-type is supplied, it toggles whether or not you\n"+
	"hear messages of that type.  If not, it lists all message\n"+
	"types available to you and whether or not you currently\n"+
	"hear them.  Deals with information messages like login/outs.\n");
    return 1;
}
