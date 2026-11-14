/*
 * secure/net/gopher.c
 *
 * (C) Copyright 1993 Nightfall
 *
 * Deepthought, 26-Jan-93
 *
 * This object may be used with or without modifications as long
 * as credit to its origin is given.
 * 
 * This is a special player object which handles incoming
 * Nightfall Gopher Services requests.
 *
 * This object provides gopher control strings which can be
 * evaluated by gopher clients. It effectively turns LPC into
 * a language for providing a flexible, programmable gopher
 * server.
 *
 * This LPmud implementation is written for Nightfall, which runs with
 * Amylaar's gamedriver and our own custom mudlib. It is probably 
 * usable with other mudlibs after small changes. The mudlib needs
 * the capability to start this special player object from the
 * login object.
 *
 * It provides some query-type functions typically present also in
 * 'normal' player objects.
 *
 * TODO: Bring me up to date and tie me into /secure/login.c
 */
#include <nightday.h>
#include <rooms.h>
#include <properties.h>
#include <daemons.h>

#define NOPROMPT set_prompt("")
#if __HOST_NAME__ == "quest"
#define NAMEANDPORT "134.2.170.99\t4250"
#elif __HOST_NAME__ == "leander"
#define NAMEANDPORT "192.124.28.80\t4250"
#else
#define NAMEANDPORT "134.2.62.161\t4250"
#endif

IsServiceDaemon() { return 1; }
QueryShort() { return "Nightfall Gopher Services Daemon (deaf)"; }
QueryName() { return "GOPHER"; }
QueryRealName() { return "gopher"; }
QueryPlayer() { return 1; }

query_prevent_shadow() { return 1; }

IsServiceDemon() { return 1; }

/*
 * This is the function that gets called by /secure/login after name and
 * password is verified and this object is loaded.
 */
start_player(str) {
  object p;
  string file;
    /*
    log_file("GOPHER","Restarting the GOPHER player\n");
    */
    /*myself = this_player();*/


  if (p=find_player("deepthought")) {
    tell_object(p,"gopher: ["+str+"/"+query_mud_port()+"/"+query_ip_name()+"]\n");
  }
    switch(str) {
	case "root":
	    listfile("What is Nightfall","what");
	    listfile("How Nightfall Gopher Service works","how");
	    listfile("List Users logged into Nightfall","who");
	    listfile("Nightfall Status","status");
	    listdir("Documents and papers about MUDs","docs");
	    listdir("LPC Books","lpcbooks");
#if __HOST_NAME__ == "quest"
	    write("8Enter Nightfall\t\t134.2.170.99\t4242\n");
#else
	    write("8Enter Nightfall\t\t134.2.62.161\t4242\n");
#endif
	    write("8Enter Morgengrauen\t\t128.176.121.56\t4711\n");
	    write(".\n");
	    break;
	case "what":
	    cat("/etc/nightfall.description");
	    write(".\n");
	    break;
	case "how":
	    cat("/etc/gopher.description");
	    write(".\n");
	    break;
	case "status":
	    nightfall_status();
	    write(".\n");
	    break;
	case "who":
	    who_list();
	    write(".\n");
	    break;
	case "lpcbooks":
listfile("Introduction",			"lpcbooks/basic/Introduction");
listfile("Basic 1: Introduction to the Coding Environment","lpcbooks/basic/chapter1");
listfile("Basic 2: The LPC Program",		"lpcbooks/basic/chapter2");
listfile("Basic 3: LPC Data Types",		"lpcbooks/basic/chapter3");
listfile("Basic 4: Functions",			"lpcbooks/basic/chapter4");
listfile("Basic 5: The Basics of Inheritance",	"lpcbooks/basic/chapter5");
listfile("Basic 6: Variable Handling",		"lpcbooks/basic/chapter6");
listfile("Basic 7: Flow Control",		"lpcbooks/basic/chapter7");
listfile("Basic 8: The Data Type Object",	"lpcbooks/basic/chapter8");

listfile("Intermediate 1: Introduction",	"lpcbooks/intermediate/chapter1");
listfile("Intermediate 2: The LPMud Driver",	"lpcbooks/intermediate/chapter2");
listfile("Intermediate 3: Complex Data Types",	"lpcbooks/intermediate/chapter3");
listfile("Intermediate 4: The LPC Pre-Compiler",	"lpcbooks/intermediate/chapter4");
listfile("Intermediate 5: Advanced String Handling",	"lpcbooks/intermediate/chapter5");
listfile("Intermediate 6: Intermediate Inheritance", "lpcbooks/intermediate/chapter6");
listfile("Intermediate 7: Debugging",		"lpcbooks/intermediate/chapter7");
listfile("Copyright",				"lpcbooks/intermediate/Copyright");
	    write(".\n");
	    break;
	case "docs":
	    cat("/doc/papers/gopher_index");
	    write(".\n");
	    break;
	default:
	    if (str[0..8] == "lpcbooks/") {
		int siz,pos;
		str = MASTER->full_path(str[8..]);
		siz = file_size("/doc/LpcBooks"+str);
		if (siz > 0) {
			for (pos = 0; pos < siz; pos += 200)
			    write(read_bytes("/doc/LpcBooks"+str,pos,200));
			}
		else {
			write("Error in accessing information\n");
		}
		write(".\n");
		break;
	    }
	    if (str[0..3] == "doc/") {
		int siz1,pos1;
		str = MASTER->full_path(str[3..]);
		siz1 = file_size("/doc/papers"+str);
		if (siz1 > 0) {
			for (pos1 = 0; pos1 < siz1; pos1 += 200)
			    write(read_bytes("/doc/papers"+str,pos1,200));
		}
		else {
			write("Error in accessing information\n");
		}
		write(".\n");
		break;
	    }
	    break;
    }
    destruct(this_object());
    return 1;
}

/*
 * where() is a function which returns the physical country from
 * which the player is logged in. The simul-efun country() is
 * used to return a best guess of the country name from the
 * ip name (usually the top level domain is quite descriptive).
 */
where(ob) { return COUNTRY_D->country(lower_case(query_ip_name(ob))); }

/*
 * We are called from the info-serv by the command @mudwho and
 * should return a list of players. Edit /secure/net/RWHO_BANNER
 * for the top lines to be sent before the player list.
 */
who_list() {
    string a, b;
    int i, nu;
    string *lines;
    object *list;

    list = users();
    nu = 0;
    for (i = 0; i < sizeof(list); i++) {
	string sh;
	sh = list[i]->QueryShort();
	if (sh) {
	    write(capitalize(sh)+" [" +where(list[i])+"]\n");
	    nu++;
	}
    }
    if (nu) 
	write("*** There are "+nu+" users connected.\n");
    else
	write("*** There are no users connected.\n");
    return 1;
}


nightfall_status() 
{
  write("/d/archwiz/common/room/tower/center"->clock());
}

listfile(desc, fname)
{
    write("0"+desc+"\tgopher:"+fname+"\t"+NAMEANDPORT+"\n");
}

listdir(desc, fname)
{
    write("1"+desc+"\tgopher:"+fname+"\t"+NAMEANDPORT+"\n");
}
