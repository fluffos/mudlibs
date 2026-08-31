
/*
 * _imc.c 
 * Made for DarkeMUD
 * Created by Madoc@DarkeMUD
 * See file COPYING in this package for liscence
 * Copyright (c) 2004
 * Do not remove this header!
 * Description : This is included by both the daemon and the command
 *               it contains settings and defines needed by both.
 *               READ AND FOLLOW ALL COMMENTS UP UNTIL IT SAYS
 *               DO NOT CHANGE BELOW THIS LINE!
 * Changelog   :
 *               Madoc@DarkeMUD 0504 : File released.
 */		
 
// This define is different and special, only uncomment this if you have a lima lib
// or are like a lima in that you have no this_player only this_body and this_user
// And also use lima's privs security system
// If you have those and your not an actual lima, some mods may be required
// Id be happy to help with that if you need it, see email in the CONTACT file in this package
//#define IMC_LIMA 1

/*******************************FILE LOCATIONS***********************************************/
//** You will want to edit these, if the configure script hasnt already done it to the 
//** locations that make sense for your mud, you will need to actually put the file where you 
//** specify. The .h must be in a place where #include "imc.h" will work, or you must change
//** the 3 lines that say that in imc_d.c and _imc.c and imc_socket.c
//** Again, if the configure script has already done it, thats if there is a configure script. 
	//NOTE: This file wont exsist before u run imc_d it will be created
	//	by the d, make sure the d has rights to write wherever you point this
#define IMCFILE_SAVE "/d/guilds/imc/imc.o"
	//NOTE: There is one special code in there %^MUDNAME%^, it dosnt actually exsist
	//      I just use it so I can use a generic rwho header rather then forceing the
	//	user to make up a new one, feel free to make your own.
#define IMCFILE_WHOHEADER "/d/guilds/imc/header"
	//NOTE: do not put the .c on this, even if you use the pure lima one
	//      it'll cause the security check to fail
#define IMCFILE_SOCKET "/daemon/imc_socket"
#define IMCFILE_LOGFILE "/d/guilds/imc/imc_d.log"
#define IMC_D "/daemon/imc_d"
	//NOTE: Don't put the .c on this 
#define IMC_COMMAND "/cmds/creator/_imc"
	
/*************************** END FILE LOCATIONS***********************************************/

/*************************** LOGIN INFO ******************************************************/
//** These will also have to be edited, their used by the script to know what hub and where,
//** You can get login info for the ICE-MAN network automatically by going to the web page at
//** http://iceman.aethiamud.org/ and clicking sign-up. There is no cost to signup it is a free
//** network.

#define IMCLOGIN_HUB       "server-madoc.openimc.org"
#define IMCLOGIN_HUBPORT    8000
	//NOTE: Localnames must be 15 chars max, letters and hyphens ("-") only
#define IMCLOGIN_LOCALNAME "PrimalDarkness-II"
#define IMCLOGIN_CLIENTPW  "pd1231111"
#define IMCLOGIN_SERVERPW  "321pd1111"
/*************************** END LOGIN INFO **************************************************/

/*************************** GENERAL INFO ****************************************************/
//** These are mostly used by Taurus for imc info replys, the ADDRESS define also determines 
//** login info that will be posted at the bottom of your who replys.

#define IMCINFO_VERSION     "IMC2 6.00 Taurus MudOS LPC Client"
#define IMCINFO_WEBPAGE     "http://www.primaldarkness.com"
#define IMCINFO_ADDRESS     "telnet://mud.primaldarkness.com:10000"
#define IMCINFO_ADMINEMAIL  "stormbringer@primaldarkness.com"
#define IMCINFO_DETAILS     "A kind of short desc of your mud."
	//NOTE: These are provided in case you don't call them 'wizards' etc
	//	used only in finger replies
#define IMCINFO_ADMRANKNAME "Admin"
#define IMCINFO_WIZRANKNAME "Wizard"
#define IMCINFO_PLYRANKNAME "Player"

/*************************** END FILE LOCATIONS***********************************************/

/*************************** SETTINGS ********************************************************/
	//NOTE: Both inbound and outbound color support count on the Pinkfish@diskworld color
	//      protocol, even if you dont have it, you can leave the outbound on as it 
	//      converts to imc2 color codes anyway. Comment these lines to disable them
	//	if you do so, all color codes will be stripped instead.
#define IMCSETTING_COLORSUPPORTIN  1
#define IMCSETTING_COLORSUPPORTOUT 1
	//NOTE: is put at the end of all local output from message
	//      if ur mud already puts one, take out the \n
	//      leave the reset without it some muds (TMI-2) bleed color
//#define IMCSETTING_EXTRAENDLINE "%^RESET%^\n"
#define IMCSETTING_EXTRAENDLINE "%^RESET%^"
	//NOTE: If a problem develops where the hub is no longer giving echo packets
	//	it can seem like localecho is broken, this is NOT a bug in the client
	//	its a problem hubs have occationaly I discovered, if that happens
	//	comment out this. Also, if you dont like the slight delay after you 
	//      send a message, but before the localecho comes up, comment this out
#define IMCSETTING_ECHOPACKET 1

#define IMCSETTING_MAXHIST         10
	//NOTE: Disabled by default, this file can get HUGE!!
	//	If you want robust sort of logging see about
	//      using imc_dmesg in imc_d.c to split output to
	//      seperate files
#define IMCSETTING_LOGGING         1
#define IMCSETTING_RESETCOLOR      "%^WHITE%^"
#define IMCSETTING_PRETEXT         "\n[%^YELLOW%^IMC%^RESET%^] "	
	//NOTE: Feel free to change these, but if you do, only leave 1 set uncommented
	//      only the first uncommented set will be used.
	// Darkemud style [linename : Madoc] Hi! || [linename] Madoc hi's!
#define IMCSETTING_LINESAY         IMCSETTING_PRETEXT + "[%^BLUE%^%^BOLD%^$LN%^RESET%^ : $WHO] $WHAT"
#define IMCSETTING_LINEEMOTE       IMCSETTING_PRETEXT + "[%^BLUE%^%^BOLD%^$LN%^RESET%^] $WHO $WHAT"
	// Diku style    Madoc <linename> Hi! || <linename> Madoc hi's!
//#define IMCSETTING_LINESAY         IMCSETTING_PRETEXT + "$WHO <%^BLUE%^$LN%^RESET%^> $WHAT"
//#define IMCSETTING_LINEEMOTE       IMCSETTING_PRETEXT + "<%^BLUE%^$LN%^RESET%^> $WHO $WHAT"
/***********************END SETTINGS ********************************************************/

/*************************** MESSAGES *******************************************************/
//** Editable error messages and messages, feel free to change them
//** $LN etc are tags filled in by Taurus later via replace_string
#define IMCERROR_UNKNOWNMUD mud_name() + " is not aware of that mud."
#define IMCERROR_LOCALSEND "Use local commands for that function."
#define IMCERROR_NOMUDLIST "No muds are currently connected to the network."
#define IMCERROR_NOLINELIST "No lines in list, maby not connected to IMC2?"
#define IMCERROR_SAVEFAILED "Save of player settings failed!"
#define IMCERROR_COULDNOTCREATESOCKET "Could not create outgoing socket!"
#define IMCERROR_WRONGARGS "Argument missing or not understood, see 'imc help'."
#define IMCERROR_NOTAWAREOFLINE "You are not aware of a line called $LN."
#define IMCERROR_NOHISTORY "That line has no history."
#define IMCERROR_TELLWRONGFORMAT "Tell must be in the format tell player@mud message."
#define IMCERROR_BEEPWRONGFORMAT "Beep must be in the form beep player@mud and is a silly feature."
#define IMCERROR_NOREPLY "You must have recieved a tell to reply to."
#define IMCERROR_NOSUCHBAN "There is no such class of ban."
#define IMCERROR_BANADMIN  "You cannot ban admin, silly."
#define IMCERROR_INVALIDBAN "You must specify WHO to ban, see help"
#define IMCERROR_ADMINONLY "You must be of admin rank to use that IMC command."
#define IMCERROR_LINKDOWN  "The IMC2 link is currently down, link is the only command available."
#define IMCERROR_NOTELLHIST "You have no tell history."
#define IMCERROR_INVALIDOPTION "That option is not valid type."
#define IMCERROR_NOPURGE     "Cannot find any settings for that name."
#define IMCERROR_COULD_NOT_FIND_PLAYER "Sorry, no such player online."
#define IMCERROR_PLAYERBLOCKINGTELLS "Sorry, this player is blocking tells."
#define IMCMSG_WHOSENT         "Who query sent."
#define IMCMSG_NOONEHOME       "This world is devoid of life."
#define IMCMSG_GLOBALBLOCKON   "Global blocking of IMC2 lines enabled."
#define IMCMSG_GLOBALBLOCKOFF  "Global blocking of IMC2 lines disabled."
#define IMCMSG_BLOCKEDLINE     "You are now blocking $LN."
#define IMCMSG_UNBLOCKEDLINE   "You are no longer blocking $LN."
#define IMCMSG_NOONELISTENING  "Noone visible listening to that line."
#define IMCMSG_FINDREPLY       "imcpfind $WHO : $WHO@WHERE is online.\n\r"
#define IMCMSG_REPLYADDY       "Current reply address: $RA"
#define IMCMSG_DEFAULTAFK      "That person is currently afk."
#define IMCMSG_AFKON           "You are now marked as AFK."
#define IMCMSG_AFKOFF          "You are no longer marked as AFK"
#define IMCMSG_AFKSET          "Your AFK reply is now set to: $AFK"
#define IMCMSG_PINGSENT        "%^GREEN%^Ping? Pong!%^RESET%^ Query sent."
#define IMCMSG_BANON           "New ban added."
#define IMCMSG_BANOFF          "Ban removed."
#define IMCMSG_BAN             "You have been banned from using IMC2."
#define IMCMSG_TELLBLOCKON     "You are now blocking all IMC2 tells."
#define IMCMSG_TELLBLOCKOFF    "You are no longer blocking tells"
#define IMCMSG_INFOSENT        "Query Sent."
#define IMCMSG_LINKSTATUS      "The IMC2 link is currently [$LS]"
#define IMCMSG_LINKON          "The IMC2 link is comeing up."
#define IMCMSG_LINKOFF         "The IMC2 link has been disconnected."
#define IMCMSG_OPTIONOFF       "You are no longer listening to that option."
#define IMCMSG_OPTIONON        "You will now recieve messages from that option."
#define IMCMSG_OPTIONBLOCKON   "You are now blocking all option messages."
#define IMCMSG_OPTIONBLOCKOFF  "You are now listening to your selected options."
#define IMCMSG_PURGED         "Player settings for that player purged."
/********************** END MESSAGES ********************************************************/


//*************** NOTHING BELOW THIS LINE SHOULD BE EDITED UNLESS YOU KNOW EXACTALLY WHAT YOUR DOING

#define IMCBAN_LOCAL 1
#define IMCBAN_REMOTE 2
private string imc_chr(int code);

	
// Close to darkes format page, but that used arrange_string
// which i cant copy because i have no idea who wrote it
// this version is stripped down and dosnt take color into account
private string imc_arrange_string(string src,int len) {
	int i;
	i = strlen(src);
	if(i == len) return src;	
	if(i > len) {
		return src[0..len];
	}
	else {
		i = len - i;
		while(i--) src += " ";
	}
	return src;
}
private string imc_format_page(string *items, int columns) {
    int width, i, j, x;
    string ret;

    if(!columns) columns = 2;
    ret = "";
    width = 75/columns;
    for(i=0, x = sizeof(items); i<x; i+=columns) {
        for(j=0; j<columns; j++) {
            if(i+j >= x) break;
            ret += imc_arrange_string(items[i+j], width);
        }
        ret += "\n";
    }
    return ret;
}
// This is used to return non displayable charactors
// such as beep, or the ansi escape code, actually
// thats the only 2 things I use it for:)
private string imc_chr(int code) {
	string a = " ";
	a[0] = code;
	return a;
}
/********************** COMPATABILITY ********************************************************/
//// These are functions that are used a lot, but I wasnt sure if they would be the same on all
//// codebases, damn glad I did it that way, lima is wierd! (from my pov :) )
//// Some of them do dual checks, thats what allows drop in support for TMI-2 AND nightmare/darkelibs
#ifdef IMC_LIMA
#define IMC_TP this_user()
#define IMC_FIND_PLAYER find_body
#else
#define IMC_TP this_player()
#define IMC_FIND_PLAYER find_player
#endif

// SPECIAL_FUNCTIONS: functions that may need to be remapped

	//NOTE: this should return if the passed player object is invisible
	//	only used to hide invis admin from the rwho list
private int imc_invis(object ob) { 	
#ifdef IMC_LIMA
	if(!ob->is_body()) ob = ob->query_body();
	if(!ob) return 0;
	if(!interactive(ob->query_link())) return 0;	
	return (ob->is_visible())?0:1;
#else
	if(!ob) return 0;
	if(!interactive(ob)) return 0;
	if(!ob->query_invis()) return ob->query("invisible");
	return ob->query_invis(); 
#endif	
}
	//NOTE: this should return if the passed player object is an admin
	//      and therefore should be hidden from the who list if invisible
	//      also be able to tell snoop, see incomeing packets shutdown
	//	and/or restart the link etc
private int imc_admin(object ob) { 
#ifdef IMC_LIMA
	if(ob->is_body()) ob = ob->query_link();
#endif
	if(!ob) return 0;
	if(!interactive(ob)) return 0;
         return archp(ob);
}
	//NOTE: this should return if the passed player object is a wizard
	//      and therefore should be hidden from the who list if invisible	
private int imc_wizard(object ob) { 	
#ifdef IMC_LIMA
	if(ob->is_body()) ob = ob->query_link();	
#endif
	if(!ob) return 0;
	if(!interactive(ob)) 0;
         return wizardp(ob);
}
	//NOTE: This should return the mud handle of the player object in question	
private string imc_name(object ob) { 
	string ret;
#ifdef IMC_LIMA	
	if(!ob->is_body()) ob= ob->query_body();
	if(!ob) return "Unknown";
	if(!interactive(ob->query_link())) return "Unknown";			
	return capitalize(ob->query_body()->living_query_name());
#else 
	ret = ob->query_name();
	if(!ret) ret = ob->query("name");
	if(!ret) return "IMCNAME did not port well";	
	return capitalize(ret); 
#endif
}


	//NOTE: All writes pass threw this function
	//      so if you want to change the message class, or add profanity filters
	//      or crud like that, do it here	
private void imcwrite(string str,object who) { 
	str = replace_string(str,"\\n","\n");
	str = replace_string(str,"\\r","\r");
	str = replace_string(str,imc_chr(92)+imc_chr(34),imc_chr(34));	
	// specifically just below this comment but above the ifdef
#ifdef IMC_LIMA
	tell(who,str+"\n");
#else
	message("imc",str+ IMCSETTING_EXTRAENDLINE,who); 
#endif	
	
}

private string imc_formated_mudlist(mapping mudlist) {
	string ret, *mapkeys;
	int i, expired;
	mapkeys = sort_array(keys(mudlist),-1);	
	i = sizeof(mapkeys);
	if(!i) return IMCERROR_NOMUDLIST;	
	ret  = "\n%^BOLD%^Network Connection Listing%^RESET%^";
	ret += sprintf("\n%-35s %-55s %-20s",
		"%^GREEN%^Name%^RESET%^","%^CYAN%^IMC2 Version%^RESET%^","%^BOLD%^%^GREEN%^Network%^RESET%^\n");
	while(i--) {
		if(mudlist[mapkeys[i]]["status"] == 1) {
			ret += sprintf("\n%-35s %-55s %-20s",
					"%^GREEN%^"         + mudlist[mapkeys[i]]["name"]    + "%^RESET%^",
					"%^CYAN%^"          + mudlist[mapkeys[i]]["version"] + "%^RESET%^",
					"%^BOLD%^%^GREEN%^" + mudlist[mapkeys[i]]["network"] + "%^RESET%^");
		}
		else {
			ret += sprintf("\n%-35s %-55s %-20s",
					"%^BOLD%^%^RED%^"   + mudlist[mapkeys[i]]["name"]    + "%^RESET%^",
					"%^BOLD%^%^RED%^"   + mudlist[mapkeys[i]]["version"] + "%^RESET%^",
					"%^BOLD%^%^RED%^"   + mudlist[mapkeys[i]]["network"] + "%^RESET%^");
			expired +=1;
		}
	}
	ret += "\n%^BOLD%^" + (sizeof(mapkeys)-expired) + " active and "+expired+ 
	       " %^RED%^expired%^RESET%^%^BOLD%^ connections found.";
	return ret;
}
/********************** END COMPATABILITY ********************************************************/

