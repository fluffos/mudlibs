/*
/ Command: whod
/ coded by: Anar  (@ Enchanted Rock)
/ Changed by Ardana to improve functionality.
/ There were some big bugs in 'mortal' and 'domainless', so these are
/ removed, since they aren't real domains anyway.
/ syntax: whod <domain name>
/ purpose: lists all wizards belonging to that domain
/ Stolen by Cyanide 8-20-96 - Now just has to fix it.
/ 03 Apr 98 - Cyanide ported it to Nightfall's Keep. Wow.
*/

#include <daemons.h>
#include <domains.h>
inherit "/std/cmd_m" ;
string *domains;

void create()
{
    int i,j,k,c;
    string *usrs,*dirform,str;
    object player,lnk;
    ::create();               
    usrs=({});
    c=0;
    domains=DOMAIN_LIST+({"all"});
    for (i=0;i<sizeof(domains);i++)
    {
	if (file_exists("/tmp/"+domains[i])) rm("/tmp/"+domains[i]);
    }
    dirform=get_dir("/u/*",0);
    for (i=0;i<sizeof(dirform);i++)
    {usrs= get_dir("/u/"+dirform[i]+"/",0);
	for (j=0;j<sizeof(usrs);j++)
	{
	    sscanf(usrs[j],"%s",usrs[j]);
	    player=FINGER_D->restore_data(usrs[j]);
	    if (player)
	    {
		if (c>67) {write_file("/tmp/all","\n");c=0;}
		write_file("/tmp/all",player->query("cap_name")+"::");
		c+=sizeof(player->query("cap_name"))+2;
		lnk=player->query_link(player);
		for (k=0;k<sizeof(domains);k++)       
		{
		    if (DOMAIN_D->query_domain(lnk,domains[k]))
		    {
			write_file("/tmp/"+domains[k],
			  sprintf("%|14s:%|10s:%|14s",player->query("cap_name"),
			    DOMAIN_D->query_domain_level(lnk,DOMAIN_LIST[k]),
			    DOMAIN_D->query_domain_sponsor(lnk,DOMAIN_LIST[k])));
			write_file("/tmp/"+domains[k],"\n");
		    }
		}
	    }
	}
    }
}

int cmd_whod(string arg)
{
    int i,j,k;
    string *names, *level, *under, tmp;
    i=0;
    k=0;                                
    if(!arg) return notify_fail("SYNTAX:  whod <domainname>\n");
    if (arg=="domains"|| arg=="domain")
    {
	for (i=0;i<sizeof(domains);i++)
	{
	    write(sprintf("%s",domains[i]+"\n"));
	}
	return 1;
    }
    if (!file_exists("/tmp/"+arg))
	return notify_fail("That is not an active domain group.\n");
    else
    {
	this_player()->more("/tmp/"+arg,0,1);
	return 1;
    }
}


string help() {       
    return ( "Usage: whod <domain name> \n\n "+
      "See also: who, finger, people.\n") ;
}                         
