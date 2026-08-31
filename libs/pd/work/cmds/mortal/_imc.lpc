/*
 * _imc.c 
 * Made for DarkeMUD
 * Created by Madoc@DarkeMUD
 * See file COPYING in this package for liscence
 * Copyright (c) 2004
 * Do not remove this header!
 * Description : This is a command that works as the interface to the imc_d.
 *               Its meant mostly as an example, chances are you will want to
 *               mesh it into your local mud commands.
 * Changelog   :
 *               Madoc@DarkeMUD 0504 : File released.
 */		
#include <imc.h>
//// varags int help(string str)
//   Takes   : Either nothing, in which case it prints the help index, or a 
//             string that contains a specific command.
//   Returns : Nothing, all information is displayed useing imcwrite which 
//             can be found in imc.h, this package.
//   Use     : Help and syntax on the commands, its accessiable several 
//             different ways so that it will work no matter what help system
//             you use.
varargs int help(string str);
//// int cmd_inc(strig args)
//   Takes   : Arguments that are used to decide what to do.
//   Returns : An int that in most command parsers is meant to say if 
//             the command handled the string it was given or not, always
//             returns 1 Nothing, but it does do whatever command its given.
//   Use     : Well the D's pretty useless without an interface.
//             Some of the code for outgoing packets is actually in here.
int cmd_imc(string args);

// Allows lima portability
// For lima to work this file also has to be renamed to drop the _ out of the filename
#ifdef IMC_LIMA
inherit CMD;
private void main(string args) {
	cmd_imc(args);	
	return;
}
#endif

// See function prototype for overall documantation on this function
int cmd_imc(string args) {	
	string *split, *linelist;
	string who, where,what;
	int i,x;
	mapping mudinfo;
	if(IMC_D->imc_query_ban(imc_name(IMC_TP),IMCBAN_LOCAL)) {
		imcwrite(IMCMSG_BAN,IMC_TP);
		return 1;
	}
	if(!args || strlen(args) < 3) {
		help();
		return 1;
	}
	if((int)IMC_D->imc_query_linkdown() && lower_case(args[0..3]) != "link") {
		imcwrite(IMCERROR_LINKDOWN,IMC_TP);
		return 1;
	}
	if(args == "mudlist") {
		imcwrite(imc_formated_mudlist(IMC_D->imc_query_mudlist()),IMC_TP);		
		return 1;
	}	
	split = explode(args," ");
	split[0] = lower_case(split[0]);
	switch(split[0]) {
		case "tell" :		 
		//imc tell player@mud message
		//Outgoing imc tells
			if(sizeof(args) < 2) {
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				help("tell");
				return 1;
			}
			if(lower_case(split[1]) == "toggle") {
				i = IMC_D->imc_toggle_setting(IMC_TP,"tellblock");
				if(i==0) imcwrite(IMCMSG_TELLBLOCKOFF,IMC_TP);
				if(i==1) imcwrite(IMCMSG_TELLBLOCKON ,IMC_TP);
				return 1;
				
			}
			if(sscanf(args,"tell %s@%s %s",who,where,what) != 3) {
				imcwrite(IMCERROR_TELLWRONGFORMAT,IMC_TP);
				return 1;
			}
			who = lower_case(who);
			where = lower_case(where);
			if(where == IMCLOGIN_LOCALNAME) {
				imcwrite(IMCERROR_LOCALSEND,IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			//if we're sending, we're unblocking
			if(IMC_D->imc_query_setting(IMC_TP,"tellblock")) {
				IMC_D->imc_toggle_setting(IMC_TP,"tellblock");
				imcwrite(IMCMSG_TELLBLOCKOFF,IMC_TP);
			}
			split[1] = capitalize(split[1]);
			IMC_D->imc_send_packet("tell",imc_name(IMC_TP),sprintf("%s@%s",who,where),what);
			IMC_D->imc_dmesg("tellsnoop","%^BOLD%^%^RED%^" + imc_name(IMC_TP) + " tells " + 
				 	split[1] + ":%^RESET%^ " +what);
			imcwrite(IMCSETTING_PRETEXT+"%^BOLD%^%^RED%^You tell " + split[1] + ":%^RESET%^ " 
				+ what,IMC_TP);
			return 1;
		case "reply" :
		// imc reply message
		// Reply to last person to send this player an imc tell
			if(sizeof(split) == 1) {
				who = IMC_D->imc_query_reply(IMC_TP);
				imcwrite(replace_string(IMCMSG_REPLYADDY,"$RA",who),IMC_TP);
				return 1;
			}
			if(sscanf(args,"reply %s",what) != 1) {
				help("reply");
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				return 1;
			}
			if(sscanf(IMC_D->imc_query_reply(IMC_TP), "%s@%s",who,where) != 2) {
				imcwrite(IMCERROR_NOREPLY,IMC_TP);
				return 1;
			}
			who = lower_case(who);
			where = lower_case(where);
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			IMC_D->imc_dmesg("tellsnoop","%^BOLD%^%^RED%^" + imc_name(IMC_TP) + " tells " + 
				 	sprintf("%s@%s",who,where) + ":%^RESET%^ " +what);			
			IMC_D->imc_send_packet("tell",imc_name(IMC_TP),sprintf("%s@%s",who,where),what);
			imcwrite(IMCSETTING_PRETEXT+"%^BOLD%^%^RED%^You tell " + IMC_D->imc_query_reply(IMC_TP) + ":%^RESET%^ " + what,IMC_TP);		
		return 1;
		case "who" :
		case "rwho" : 
		//imc who mudname
		//Outgoing rwho requests
			if(sizeof(split) == 1) {
				help("rwho");
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				return 1;
			}			
			where = lower_case(split[1]);
			if(sizeof(split) == 1) {
				help("rwho");
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				return 1;
			}
			if(where == lower_case(IMCLOGIN_LOCALNAME)) {
				imcwrite(IMCERROR_LOCALSEND,IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			IMC_D->imc_send_packet("who",imc_name(IMC_TP),lower_case(split[1]),0,"type=who");
			imcwrite(IMCSETTING_PRETEXT+IMCMSG_WHOSENT,IMC_TP);	
			IMC_D->imc_dmesg("querys","RWHO sent to "+lower_case(split[1])+ " from " + (imc_name(IMC_TP)));			
			return 1;
		case "whois" :		
		case "finger" :
		//imc whois person@mud
			if(sizeof(split) == 1) {				
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				return 1;
			}			
			write("neener");
			if(sscanf(split[1],"%s@%s",who,where) != 2) {
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				return 1;
			}
			write("neener");
			if(where == lower_case(IMCLOGIN_LOCALNAME)) {
				imcwrite(IMCERROR_LOCALSEND,IMC_TP);
				return 1;
			}
			write("neener");
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			what = "finger " + who;
			split[1] = lower_case(split[1]);	
			IMC_D->imc_send_packet("who",imc_name(IMC_TP),split[1],0,"type=\""+what+"\"");
			
			IMC_D->imc_dmesg("querys",capitalize(what) +  " query sent to " +split[1] + " from " +
					 imc_name(IMC_TP));
			imcwrite(IMCSETTING_PRETEXT+IMCMSG_INFOSENT,IMC_TP);			
			return 1;			 
		case "info" :		
		//imc info mudname type
		//Outgoing imc info requests		
			if(sizeof(split) == 1) {				
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				help("info");
				return 1;
			}			
			where = lower_case(split[1]);
			if(sizeof(split) == 1) {
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				help("info");
				return 1;
			}
			if(where == lower_case(IMCLOGIN_LOCALNAME)) {
				imcwrite(IMCERROR_LOCALSEND,IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			if(sizeof(split) == 3)      what = split[2];
			else if(sizeof(split) == 4) what = split[2] + " " +  split[3];
			else what = "help";
			split[1] = lower_case(split[1]);
			IMC_D->imc_send_packet("who",imc_name(IMC_TP),split[1],0,"type=\""+what+"\"");
			IMC_D->imc_dmesg("querys",capitalize(what) +  " query sent to " +split[1] + " from " +
					 imc_name(IMC_TP));
			imcwrite(IMCSETTING_PRETEXT+IMCMSG_INFOSENT,IMC_TP);			
			return 1;
			
		case "lines" :
		//imc lines
		//imc lines toggle
		//Outputs current status of lines, what we're listening to, what we're not, if we're global
		//blocking or not etc.
			if(sizeof(split) == 1) {
				what = "%^BOLD%^Channel listing %^RESET%^[%^BOLD%^"+
					imc_name(IMC_TP)+"%^RESET%^]\n\n";
				linelist = IMC_D->imc_query_linelist();
				if(!linelist) {
					what += IMCERROR_NOLINELIST + "\n";
					return 1;
				}
				i=sizeof(linelist);
				while(i--) {
					if(!IMC_D->imc_query_line_access(imc_name(IMC_TP),linelist[i])) continue;
					if(IMC_D->imc_query_listening(IMC_TP,linelist[i])==1)
						 what += ""+sprintf("[X]  %-30s  ",linelist[i])+"";
   					else what += ""+sprintf("[ ]  %-30s  ",linelist[i])+"";
					if(i%2 == 0) what += "\n";
      
				}
				imcwrite("%^BLUE%^+-------------------------------------------------------------+",IMC_TP);
				if(IMC_D->imc_query_setting(IMC_TP,"globalblock")) 
					what += "\nGlobal block [%^BOLD%^ON%^RESET%^]\n";
				else
					what += "\nGlobal block [%^BOLD%^OFF%^RESET%^]\n";
				imcwrite(what,IMC_TP);			
				imcwrite("%^BLUE%^+-------------------------------------------------------------+",IMC_TP);
				return 1;							
			}
			if(lower_case(split[1]) == "toggle") {
				i = IMC_D->imc_toggle_setting(IMC_TP,"globalblock");
				if(i==1) imcwrite(IMCMSG_GLOBALBLOCKON,IMC_TP);
				if(i==0) imcwrite(IMCMSG_GLOBALBLOCKOFF,IMC_TP);
				return 1;				
			}
			if(lower_case(split[1]) == "list") {
				if(!imc_admin(IMC_TP)) break;
				mudinfo = IMC_D->imc_query_lineinfo();
				linelist = keys(mudinfo);
				i = sizeof(linelist);
				what = sprintf("%-22s %-8s %-20s %-8s %s\n",
				"Name","LocalNme","Owner","Admin","policy");
				while(i--) {
					what += sprintf("%-22s %-8s %-20s %-8s %s\n",mudinfo[linelist[i]]["channel"],
						   linelist[i],
						   mudinfo[linelist[i]]["owner"],
						   mudinfo[linelist[i]]["adminonly"]?"1":"0",				
						   mudinfo[linelist[i]]["policy"]);
				}
				what += "\n  *Admin denotes if the line is admin only or not";
				imcwrite(what,IMC_TP);
				return 1;
				
						
			}			
			imcwrite(IMCERROR_WRONGARGS,IMC_TP);
			help("lines");
			return 1;			
		case "hist" :
		// imc hist linename
		// imc hit tell
		// Gives the last messages on a line, or in your tellhist, size of hist is determined by
		// IMCSETTING_MAXHIST in imc.h
			if(sizeof(split) == 1) {
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				help("hist");
				return 1;
			}				
			split[1] = lower_case(split[1]);				
			if(split[1] == "tell") {
				//useing it to store tellhist here
				linelist = IMC_D->imc_querytellhist(imc_name(IMC_TP));			
				i = sizeof(linelist);
				if(!i) {
					imcwrite(IMCERROR_NOTELLHIST,IMC_TP);
					return 1;
				}
				for(x=0;x<i;x++) imcwrite(linelist[x],IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_line(lower_case(split[1]));
			if(!mudinfo) {
				imcwrite(replace_string(IMCERROR_NOTAWAREOFLINE,"$LN",split[1]),IMC_TP);
				return 1;
			}
			if(!IMC_D->imc_query_line_access(imc_name(IMC_TP),split[1])) {
				imcwrite(replace_string(IMCERROR_NOTAWAREOFLINE,"$LN",split[1]),IMC_TP);
				return 1;
			}
			if(!mudinfo["history"]) {
				imcwrite(IMCERROR_NOHISTORY,IMC_TP);
				return 1;
			}
			i = sizeof(mudinfo["history"]);
			for(x=0;x<i;x++) imcwrite(mudinfo["history"][x],IMC_TP);
			return 1;
		case "list" :
		//list linename
		//Shows a list of the LOCAL people listening to the linename given		
			if(sizeof(split) == 1) {
				help("list");
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				return 1;
			}				
			split[1] = lower_case(split[1]);
			mudinfo = IMC_D->imc_query_line(lower_case(split[1]));
			if(!mudinfo) {
				imcwrite(replace_string(IMCERROR_NOTAWAREOFLINE,"$LN",split[1]),IMC_TP);
				return 1;
			}
			if(!IMC_D->imc_query_line_access(imc_name(IMC_TP),split[1])) {
				imcwrite(replace_string(IMCERROR_NOTAWAREOFLINE,"$LN",split[1]),IMC_TP);
				return 1;
			}
			// list of users in this case
			linelist = IMC_D->imc_query_wholistening(split[1]);
			if(sizeof(linelist) == 0) {
				imcwrite(IMCMSG_NOONELISTENING,IMC_TP);
				return 1;
			}
			imcwrite("%^BLUE%^+-------------------------------------------------------------+",IMC_TP);
			imcwrite("%^BOLD%^People active on [%^BLUE%^" + split[1] + "%^RESET%^]\n",IMC_TP);
			imcwrite(imc_format_page(linelist,3),IMC_TP);	
			imcwrite("%^BLUE%^+-------------------------------------------------------------+",IMC_TP);
				
			return 1;
		case "beep" :
		// imc beep player@mud
		// Sends out a beep packet to the target player@mud
			if(sscanf(args,"beep %s@%s",who,where) != 2) {
				imcwrite(IMCERROR_BEEPWRONGFORMAT,IMC_TP);
				return 1;;
			}
			who = lower_case(who);
			where = lower_case(where);
			if(where == IMCLOGIN_LOCALNAME) {
				imcwrite(IMCERROR_LOCALSEND,IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			IMC_D->imc_send_packet("beep",imc_name(IMC_TP),sprintf("%s@%s",who,where));
			IMC_D->imc_dmesg("tellsnoop","%^BOLD%^%^RED%^" + imc_name(IMC_TP)+" beeps " + capitalize(split[1]) + "%^RESET%^ ");
			imcwrite(IMCSETTING_PRETEXT+"%^BOLD%^%^RED%^You beep " + capitalize(split[1]) + "%^RESET%^ ",IMC_TP);
			return 1;
		case "find" :
		case "locate" :
		// imc find playername
		// Sounds out a whois packet, muds that have a player with that name reply
			if(sizeof(split) == 1) {				
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				help("whois");
				return 1;
			}
			who = lower_case(split[1]);
			IMC_D->imc_send_packet("whois",imc_name(IMC_TP),split[1]+"@*");
			IMC_D->imc_dmesg("querys","Find query for " + split[1]+"@*" + " sent by " + imc_name(IMC_TP));
			return 1;
		case "afk" :
		// imc afk 
		// imc afk toggle
		// imc afk message I am afk!
		// imc afk reset		
		// Interface for the built in afk system
		// tells to a player who is set afk reply with the afk message set
			if(sizeof(split) == 1) {
				imcwrite("You AFK message is currently: " 
				+ IMC_D->imc_query_afkmsg(IMC_TP),IMC_TP);
				return 1;
			}
			what = lower_case(split[1]);
			switch(what) {
				case "toggle" :
					i = IMC_D->imc_toggle_setting(IMC_TP,"afk");
					if(i==1) imcwrite(IMCMSG_AFKON,IMC_TP);
					if(i==0) imcwrite(IMCMSG_AFKOFF,IMC_TP);					
					return 1;				
				case "message" :					
					sscanf(args, "afk message %s",what);					
					what = IMC_D->imc_setafkmsg(IMC_TP,what);
					imcwrite(replace_string(IMCMSG_AFKSET,"$AFK",what),IMC_TP);
					return 1;
				case "reset" :
					what = IMC_D->imc_setafkmsg(IMC_TP,0);
					imcwrite(replace_string(IMCMSG_AFKSET,"$AFK",what),IMC_TP);					
					return 1;
				default :
					imcwrite(IMCERROR_WRONGARGS,IMC_TP);
					help("afk");
					return 1;					
			}
		case "ping" :
		// imc ping mudname
		// Sends outa  ping request to the target mud, they are supposed to reply with the paths between
		// them, shows kind of a traceroute through the hubs on reply
			if(!imc_admin(IMC_TP)) {
				imcwrite(IMCERROR_ADMINONLY,IMC_TP);
				return 1;
			}						
			if(sizeof(split) == 1) {
				imcwrite(IMCERROR_WRONGARGS,IMC_TP);
				help("ping");
				return 1;
			}
			where = lower_case(split[1]);
			if(where == lower_case(IMCLOGIN_LOCALNAME)) {
				imcwrite(IMCERROR_LOCALSEND,IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_mud(where);
			if(!mapp(mudinfo)) {
				imcwrite(IMCERROR_UNKNOWNMUD,IMC_TP);
				return 1;
			}
			IMC_D->imc_dmesg("querys","Ping sent to " +lower_case(split[1])+ " by " + imc_name(IMC_TP));
			IMC_D->imc_send_packet("ping",imc_name(IMC_TP),lower_case(split[1]));
			imcwrite(IMCSETTING_PRETEXT+IMCMSG_PINGSENT,IMC_TP);	
			return 1;					
		case "stats" :
		// imc stats
		// Displays packet stats from the daemon
		// Not sure we really need this, but hey blitz does it
		// and its not like its complicated.
			if(!imc_admin(IMC_TP)) {
				imcwrite(IMCERROR_ADMINONLY,IMC_TP);
				return 1;
			}
			mudinfo = IMC_D->imc_query_stats();
			imcwrite("%^BOLD%^IMC2 Stats so far this session:",IMC_TP);
			imcwrite("%^CYAN%^Recieved packets:    %^BOLD%^" + mudinfo["RX"],IMC_TP);
			imcwrite("%^CYAN%^Recieved bytes:      %^BOLD%^" + mudinfo["RS"],IMC_TP);
			imcwrite("%^CYAN%^Transmitted packets: %^BOLD%^" + mudinfo["TX"],IMC_TP);
			imcwrite("%^CYAN%^Transmitted bytes:   %^BOLD%^" + mudinfo["TS"],IMC_TP);
			return 1;
		case "bans" :
		// imc bans
		// Displays a list of current local and remote bans		
			if(!imc_admin(IMC_TP)) {
				imcwrite(IMCERROR_ADMINONLY,IMC_TP);
				return 1;
			}			
			imcwrite("%^BOLD%^The following people have been banned:\n",IMC_TP);
			what = "%^CYAN%^Local:%^RESET%^\n";
			what += imc_format_page(IMC_D->imc_query_all_bans(IMCBAN_LOCAL),3);
			what += "\n%^CYAN%^Remote:%^RESET%^\n";
			what += imc_format_page(IMC_D->imc_query_all_bans(IMCBAN_REMOTE),3);
			imcwrite(what,IMC_TP);			
			return 1;
		case "ban" :
		// imc ban remote player@mud
		// imc ban local player
		// Bans a user from using imc
		// Remote bans ignore packets from players or muds that are banned		
			if(!imc_admin(IMC_TP)) {
				imcwrite(IMCERROR_ADMINONLY,IMC_TP);
				return 1;
			}						
			if(sizeof(split) != 3) {
				imcwrite(IMCERROR_INVALIDBAN,IMC_TP);
				return 1;
			}			
			split[1] = lower_case(split[1]);		
			split[2] = lower_case(split[2]);
			if(split[1] == "local") {
				// Banning yourself is a BadThing
				if(imc_name(IMC_TP) == split[2]) {
					imcwrite(IMCERROR_INVALIDBAN,IMC_TP);
					return 1;
				}				
				// Banning admin is a SillyThing
				if(imc_admin(IMC_TP)) {
					imcwrite(IMCERROR_BANADMIN,IMC_TP);
					return 1;
				}	
				imcwrite(IMC_D->imc_add_ban(split[2],IMCBAN_LOCAL),IMC_TP);
				return 1;
			}
			if(split[1] == "remote") {
				imcwrite(IMC_D->imc_add_ban(split[2],IMCBAN_REMOTE),IMC_TP);
				return 1;
			}
			imcwrite(IMCERROR_WRONGARGS,IMC_TP);		
			help("ban");
			return 1;
		case "link" :
		// imc link
		// imc link up
		// imc link down
		// imc link restart
		// Controls the imc2 link with the hub
			if(!imc_admin(IMC_TP)) {
				imcwrite(IMCERROR_ADMINONLY,IMC_TP);
				return 1;			
			}
			if(sizeof(split) == 1) {
				what = ((int)IMC_D->imc_query_linkdown()?"%^RED%^DOWN%^RESET%^":"%^GREEN%^UP%^RESET%^");
				imcwrite(replace_string(IMCMSG_LINKSTATUS,"$LS",what),IMC_TP);
				return 1;
			}
			split[1] = lower_case(split[1]);
			if(split[1] == "up") {
				IMC_D->imc_link_on();
				IMC_D->imc_dmesg("misc","IMC2 Link started by "+imc_name(IMC_TP) +"!");
				imcwrite(IMCMSG_LINKON,IMC_TP);
				return 1;
			}
			if(split[1] == "down") {
				IMC_D->imc_link_off();
				imcwrite(IMCMSG_LINKOFF,IMC_TP);
				IMC_D->imc_dmesg("misc","IMC2 Link severed by "+imc_name(IMC_TP) +"!");				
				return 1;
			}
			// restarts the d, also removes and reloads 
			// the object, useful for updateing options in the .h
			if(split[1] == "restart") {
				imcwrite("Shutting down link..",IMC_TP);
				IMC_D->imc_link_off();
				imcwrite("Killing the daemon..",IMC_TP);
				IMC_D->remove();
				destruct(find_object(IMC_D));
				imcwrite("Reloading daemon and starting link..",IMC_TP);				
				IMC_D->imc_link_on();
				imcwrite("Restart complete, unloading command..",IMC_TP);
				IMC_D->imc_dmesg("misc","IMC2 Link restarted by " + imc_name(IMC_TP) + "!");
				destruct(this_object());	
				return 1;
			}
			imcwrite(IMCERROR_WRONGARGS,IMC_TP);
			help("link");
			return 1;						
			break;
		case "option" :
		case "options" :
		// imc option
		// imc option optionname
		// imc option toggle
		// Monitoring stuff, first format gives a list sort of like lines for the options and if your
		// listening to them, second turns on or off optionname, third toggles global option block
			if(!imc_admin(IMC_TP)) {
				imcwrite(IMCERROR_ADMINONLY,IMC_TP);
				return 1;			
			}
			linelist = IMC_D->imc_dmesgs();							
			if(sizeof(split) == 1) {
				what = "%^BOLD%^Option listing %^RESET%^[%^BOLD%^"+imc_name(IMC_TP)+"%^RESET%^]\n\n";
				i=sizeof(linelist);
				while(i--) {
					if(IMC_D->imc_query_setting(IMC_TP,linelist[i])==1)
						 what += ""+sprintf("[X]  %-30s  ",linelist[i])+"";
   					else what += ""+sprintf("[ ]  %-30s  ",linelist[i])+"";
					if(i%2 == 0) what += "\n";
      
				}
				imcwrite("%^BLUE%^+-------------------------------------------------------------+",IMC_TP);
				if(IMC_D->imc_query_setting(IMC_TP,"optionglobalblock")) 
					what += "\nOption Global block [%^BOLD%^ON%^RESET%^]\n";
				else
					what += "\nOption global block [%^BOLD%^OFF%^RESET%^]\n";
				imcwrite(what,IMC_TP);			
				imcwrite("%^BLUE%^+-------------------------------------------------------------+",IMC_TP);
				return 1;
			}
			split[1] = lower_case(split[1]);
			if(split[1] == "toggle") {
				i = IMC_D->imc_toggle_setting(IMC_TP,"optionglobalblock");
				if(i == 0) imcwrite(IMCMSG_OPTIONBLOCKOFF,IMC_TP);
				if(i == 1) imcwrite(IMCMSG_OPTIONBLOCKON,IMC_TP);
				return 1;				
			}
			if(member_array(split[1],linelist) == -1) {
				imcwrite(IMCERROR_INVALIDOPTION,IMC_TP);
				return 1;
			}			
			i = IMC_D->imc_toggle_setting(IMC_TP,split[1]);
			if(i == 0) imcwrite(IMCMSG_OPTIONOFF,IMC_TP);
			if(i == 1) imcwrite(IMCMSG_OPTIONON,IMC_TP);				
			return 1;
		case "data" :
		// imc data
		// imc data purge playername
		// Shows who has data in the daemon, also allows you to purge it, useful if for example
		// you have a wizard, thats becomne a player and u dont want them to tellsnoop anymore:)
			if(sizeof(split) == 1) {
				what = "\n%^BOLD%^The following players have settings in the daemon:%^RESET%^\n";
				what += imc_format_page(IMC_D->imc_query_players(),3);
				what += "\n%^BOLD%^You may use imc data purge playername to purge a players settings.\n";
				imcwrite(what,IMC_TP);
				return 1;								
			}
			if(sizeof(split) != 3) {
					imcwrite(IMCERROR_WRONGARGS,IMC_TP);
					help("data");
					return 1;				
			}
			if(lower_case(split[1]) == "purge") {				
				imcwrite(IMC_D->imc_purge_player(lower_case(split[2])),IMC_TP);
				return 1;
			}
			return 1;
		case "help" :
			if(sizeof(split) == 1) help();
			else help(split[1]);			
			return 1;
		default :
		// imc channelname message
		// imc channelnameemote message
		// imc channelname
		// Channel talking functions, first form sends a message, second sends an emote
		// third blocks or unblocks a line
			split[0] = lower_case(split[0]);
			if(sscanf(split[0],"%semote",where) == 1) i = 1;
			else i = 0;			
			if(!where) where = split[0];			
			if(member_array(where,IMC_D->imc_query_linelist()) != -1 && sizeof(split) == 1) {
				i = (int)IMC_D->imc_toggle_block(IMC_TP,split[0]);
				if(i == 0)
					imcwrite(replace_string(IMCMSG_BLOCKEDLINE,"$LN",split[0]),IMC_TP);
				if(i == 1)
					imcwrite(replace_string(IMCMSG_UNBLOCKEDLINE,"$LN",split[0]),IMC_TP);
				if(i == -1)
					imcwrite(replace_string(IMCERROR_NOTAWAREOFLINE,"$LN",split[0]),IMC_TP);
				return 1;
			}			
			who = imc_name(IMC_TP);
			if(i==0) what = args[sizeof(where)+1..sizeof(args)];
			if(i==1) what = args[sizeof(where)+6..sizeof(args)];						
			if(member_array(where,IMC_D->imc_query_linelist()) != -1) {			
					if(IMC_D->imc_query_block(IMC_TP,where)) {
						IMC_D->imc_toggle_block(IMC_TP,where);
						imcwrite(replace_string(IMCMSG_UNBLOCKEDLINE,"$LN",split[0])
							,IMC_TP);						
					}					
					IMC_D->imc_send_packet("chat",who, "*@*",what, "channel="+where+" emote="+i);
					return 1;
			}
			
	}
	imcwrite("IMC2 Command not recognised, see 'help imc'.",IMC_TP);
	return 1;
	
}
// See function prototype for overall documantation on this function
varargs int help(string str) {
	string what;
	string *mortcmds;
	mortcmds = ({"mudlist","tell","reply","info","hist","list","beep","find",
		     "locate","whois","afk","lines","help","finger" });		  
	what = "Example command for interacting with the imc_d\n"
		       "Created by: Madoc@DarkeMUD 0504\n\n";		
	if(!str) {
		what += "Commands:\n" + imc_format_page(mortcmds,4) + "\n";
		what += "Type imc help channels for help on imc channels.\n";
		what += "Type imc help <commandname> for help on a specific command\n";
		imcwrite(what,IMC_TP);
		return 1;
	}
	
	str = lower_case(str);
	switch(str) {
		case "mudlist" :
			what += "[imc mudlist]\nDisplays the local muds mudlist.\n\n";
			break;
		case "tell" :
			what += 
		"[imc tell <player@mud> <message>]\n"
		"[imc tell toggle]\n\n"	
		"First form ends an imc2 tell to the target player@mud.\n"
		"Second form toggles your recieving of imud2 tells on or off\n"
		"Example: imc tell madoc@darkemud Hi!\n\n"
		"See also: reply, hist\n";
			break;		
		case "reply" : 
			what +=
		"[imc reply <message>]\n"
		"Replys to the last player that sent you an imc2 tell.\n"
		"Example: imc reply Hi to you too!\n\n"
		"See also: tell, hist\n";
			break;
		case "info" :
			what +=
		"[imc info <mudname> <type>]\n"
		"Sends an info request to the specified mud.\n"
		"Send a help type info request to see what the remote mud replies to.\n"
		"Example: imc info darkemud help\n"
		"         imc info darkemud help\n"
		"	 imc info darkemud istats\n\n"
		"\nSee also: finger\n";
		case "hist" :
			what +=
		"[imc hist <channelname>]\n"
		"Shows a short history of things said on that line.\n\n"
		"[imc hist tell]\n"
		"Shows the last few tells sent to you over imc2.\n\n"
		"See also: tell, reply, channels\n";
		break;
		case "list" :
			what +=
		"[imc list <channelname>]\n"
		"Shows a list of the LOCAL players listening to that line.\n\n"
		"See also: tell, hist, reply\n";
			break;
		case "beep" :
			what += 
		"[imc beep <player@mud>]\n"
		"Beep someone on a remote mud, uses the ansi 'beep' code so if their terminal "
		"supports it, their client will actually beep. Can be very annoying. Beeps are "
		"also ignored if you are blocking imc2 tells.\n\n";		
			break;
		case "find" :
		case "locate" :
			what +=
		"[imc locate <playername>]\n"
		"[imc find <playername>]\n"
		"Sends out a locate request over imc2, any mud with a player by that name will reply.\n\n";
			break;
		case "finger" :
		case "whois" :
			what +=
		"[imc finger <player>@<mud>]\n"
		"[imc whois  <player>@<mud>]\n"
		"Sends out a finger request to the target player@mud.\n"
		"Example: imc finger madoc@darkemud\n\n"
		"See also: info\n";
			break;
		case "afk" :
			what +=
		"[imc afk message <message>]\n"
		"[imc afk toggle]\n"
		"[imc afk reset]\n"
		"In the first form, sets your afk message that is sent to remote muds when you are set afk to "
		"<message>. The second form is what you use to set yourself afk or not. The third resets your "
		"afk message to the default.\n\n";
			break;
		case "lines" :
			what += 
			"[imc lines]\n"
			"[imc lines toggle]\n";
			if(imc_admin(IMC_TP)) what += "[imc lines list]\n";			
			what += "Shows what lines your listening to/not listening to, and the second form toggles blocking of all "
			        "lines on and off";
			if(imc_admin(IMC_TP)) {
				what += "imc lines list will show all available channels on the network, even if noone"
				        " on the mud can hear them, ie they are private.";
			}			
			what += "\n\n";
			break;
		case "channels" :
		case "channel" :
			what += 
			"[imc <channel> <message>] To send a message\n"
			"[imc <channel>emote <message>] To emote\n"
			"[imc <channel>] To block/unblock a channel\n"
			"[imc hist <channel>] To hist a channel\n"
			"[imc list <channel>] Lists LOCAL people\n"
			"[imc lines] Lists lines you can hear and your status on them.\n"
			"Example: imc ochat Neener!\n"
			"         imc ochatemote neeners!\n";
			break;
			
		default :
			what += "Unknown command, type imc help for list.\n";
	}
	/*
		"\timc <channelname> <message>\n"
		"\timc <channelname>emote <message>\n"
		"\timc help\n";
		if(imc_admin(IMC_TP)) {
			what += "//// ADMIN ONLY COMMANDS ////\n"
				"\timc ping <mudname>\n"
				"\timc stats\n"
				"\timc bans\n"
				"\timc ban remote <player@mud> || <mud>\n"
				"\timc ban local <player>\n"
				"\timc link\n"				
				"\timc link down\n"
				"\timc link up\n"
				"\timc link restart\n"				
				"\timc lines list\n"
				"\timc option || options\n"
				"\timc data\n"
				"\timc data purge <playername>\n";					
		}
	what += "\n\nSpecific command help:\n\n";
		" imc lines.\n\n"
		"[imc <channelname> <message>]\n"
		"[imc <channelname>emote <message>]\n"
		"This is how you speak on imc2 lines.\n"
		"Example: imc ibchat hiya!\n"
		"         imc ibchatemote dances.\n\n";
		
	if(imc_admin(IMC_TP)) {
		what += "[imc ping <mudname>]\n"
			"Sends a traceroute request to the target mud.\n\n"
			"[imc bans]\n"
			"Shows a pretty list of both the local and remote bans.\n\n"
			"[imc ban local <playername>]\n"
			"[imc ban remote <mud>]\n"
			"[imc ban remote <player@mud>]\n"
			"The first form is used to ban localplayers from using imc2. The second is used to ban an"
			" entire remote mud. The third, a specific player on a remote mud. To remove a ban simply "
			"ban an already banned person/mud. Note on banning muds, you must use *@mudname.\n"
			"Example: imc ban local madoc\n"
			"         imc ban remote *@darkemud\n"
			"         imc ban remote madoc@darkemud\n\n"
			"[imc link]\n"
			"[imc link down]\n"
			"[imc link up]\n"
			"[imc link restart]\n"			
			"The first form returns the current status of the link. The second brings it down, if the link "
			"is severed like this, or by the hub disconnecting the socket, the link STAYS down until it "
			"recieves an 'up' or restart'. The third form brings the link up. The fourth is special, it "
			"kills the link, unloads the daemon, reloads it and brings the link back up, then it removes "
			"this command from memory, useful for updateing options in the imc.h\n\n"
			"[imc lines list]\n"
			"Lists the lines available, even if noone on the current mud has access to them and their not"
			" localized.\n\n"		
			"[imc option <optionname>]\n"
			"[imc option]\n"
			"[imc option toggle]\n"
			"First form toggles if your listening to the given option or not. Second displays a pretty "
			"list of the options, and weather your listening to them or not. The thing toggles a global "
			"block of option messages. "
			"You may use option, or options, it goes to the same command.\n\n"
			"[imc data]\n"
			"[imc data purge <playername>]\n"
			"First form shows all players that have data in the imc_d, second purges the settings "
			"for a specific player\n";
	}		
	what += "\nUse tact when speaking over imc2 lines/tells or you will be banned from their use.\n";
	what += "\nNOTE: if you are a wiz or admin, and are invisible, tells and beeps etc will be bounced "
	        " you will still get them, but the person will be told your not here.";
	*/
	imcwrite(what,IMC_TP);
	return 1;
}
