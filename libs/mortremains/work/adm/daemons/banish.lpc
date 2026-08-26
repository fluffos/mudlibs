//	File	: /adm/daemons/banish.c
//	Creator	: Someone@TMI
//	Updated	: Karathan  (7/13/93)  Unified banish code.
//		  Karathan  (8/11/93)  Bug tidying, streamlined.
//		  Karathan  (8/12/93)  Bug tidying; added email registration
//		   command backing code.
//                Leto added some copy() and a ROOT_UID check, 19-12-94

#include <uid.h>
#include <daemons.h>

//  Name changed deliberately because regexp() requires a different name format
//  to the previous version.  Note that '*fuck*' will not do - '.*fuck.*' is
//  required.  '*fuck*' functions as '*'.
#define SAVE_F        "/adm/etc/banishes"
#define OLD_SAVE_F    "/adm/etc/ban_site"
#define BANNED_NAMES  ({ })
#define BANNED_SITES  ({"192.129.84.3" })

string *names, *sites, *mailreg;

void save();


void create()
{
    int i, j, flag;
    string str;

    seteuid(ROOT_UID);
    if (file_exists(SAVE_F + ".o"))
	restore_object(SAVE_F);
    else if (file_exists(OLD_SAVE_F + ".o"))
      { restore_object(OLD_SAVE_F);
	if (names && sizeof(names) > 0)
	   for (i = 0; i < sizeof(names); i++)
	      { for (flag = j = 0, str = ""; j < strlen(names[i]); j++)
		  { if (names[i][j] == '?')
		      { if (j > flag)
			    str += names[i][flag..(j - 1)];
			str += "."; flag = j + 1; }
		    if (names[i][j] == '*')
		      { if (j > flag)
			    str += names[i][flag..(j - 1)];
			str += ".*"; flag = j + 1; } }
		if (flag)
		    names[i] = str; }
	save(); }
    if (!names)
	names = BANNED_NAMES;
    if (!sites)
	sites = BANNED_SITES;
    if (!mailreg)
	mailreg = ({ });		// Should never be defaults for this!
}


//  Check incoming ip number against list of banned sites. Allow partial
//  matches so that 129.51 also catches 129.51.8.24, etc.
int check_banned_site(string ip)
{
    int i, j, a1, a2, a3, a4, b1, b2, b3, b4;
 
    if (!sites)
	return 0;
    if (sscanf(ip, "%d.%d.%d.%d", a1, a2, a3, a4) != 4)
	return -1;			// -1 indicates unable to break down ip
    for (i = 0; i < sizeof(sites); i++)
      { j = sscanf(sites[i], "%d.%d.%d.%d", b1, b2, b3, b4);
	if (a1 != b1)
	    continue;
	if (j > 1 && a2 != b2)
	    continue;
	if (j > 2 && a3 != b3)
	    continue;
	if (j > 3 && a4 != b4)
	    continue;
	return 1; }
    return 0;
}


//  Check incoming name against list of banned names. Banned names can include
//  standard regexp wildcards if they wish.
int check_banned_name(string name)
{
    int i;
    string *test;

    if (!names || name == "")
	return 0;
    test = ({ name });
    for (i = 0; i < sizeof(names); i++)
	if (name == names[i] || sizeof(regexp(test, names[i])) > 0)
	    return 1;
    return 0;
}


//  Check incoming name against list of email-registration names.  Return is the
//  encrypted password registered for that character or the empty string.
string check_mailreg_name(string name)
{
    int i;

 if (geteuid(previous_object()) != ROOT_UID) return "NO GO\n"; // Leto
    if (!mailreg || name == "")
	return "";
    for (i = 0; i < sizeof(mailreg); i += 2)
	if (name == mailreg[i])
          return copy(mailreg[i + 1]); // Leto
    return "";
}


//  Add a site to the list of banished sites (admin calls only).
int banish_site(string ip)
{
    if (geteuid(previous_object()) != ROOT_UID || ip == "")
	return 0;
    if (member_array(ip, sites) == -1)
      { sites += ({ ip });
	save(); return 1; }
    return -1;			// -1 indicates the site is already banished
}


//  Remove a site from the list of banished sites (admin calls only).
int remove_banished_site(string ip)
{
    if (geteuid(previous_object()) != ROOT_UID || ip == "")
	return 0;
    if (member_array(ip, sites) >= 0)
      { sites -= ({ ip });
	save(); return 1; }
    return -1;			// -1 indicates the site had not been banished
}


//  Add a name to the list of banished names (admin calls only).
int banish_name(string name)
{
    if (geteuid(previous_object()) != ROOT_UID || name == "")
	return 0;
    if (member_array(name, names) == -1)
      { names += ({ name });
	save(); return 1; }
    return -1;			// -1 indicates the name is already banished
}


//  Remove a name from the list of banished names (admin calls only).
int remove_banished_name(string name)
{
    if (geteuid(previous_object()) != ROOT_UID || name == "")
	return 0;
    if (member_array(name, names) >= 0)
      { names -= ({ name });
	save(); return 1; }
    return -1;			// -1 indicates the name had not been banished
}


//  Add a name to the list of email-registration names (admin calls only).
int add_mailreg_name(string name, string password)
{
    int i;

    if (geteuid(previous_object()) != ROOT_UID || name == "" || password == "")
	return 0;
    i = member_array(name, mailreg);
    if (i == -1)
      { mailreg += ({ name, password });
	save(); return 1; }
    mailreg[i + 1] = password;
    save(); return -1;		// -1 indicates an existing password has been
}				// altered


//  Remove a name from the list of email-registration names (admin calls and
//  logind.c via newuserd.c only).
int remove_mailreg_name(string name)
{
    int i;
    string password;

    if (geteuid(previous_object()) != ROOT_UID || name == "")
	return 0;
    i = member_array(name, mailreg);
    if (i == -1)
	return -1;		// -1 indicates the name had not been added
    password = mailreg[i + 1];
    mailreg -= ({ name, password });
    save(); return 1;
}


//  Return the list of banished sites (admin calls only).
string *query_banished_sites()
{
    if (geteuid(previous_object()) != ROOT_UID)
	return ({ });
   return copy(sites);
}


//  Return the list of banished names (admin calls only).
string *query_banished_names()
{
    if (geteuid(previous_object()) != ROOT_UID)
	return ({ });
   return copy(names); // Leto
}


//  Return the list of email-registration names (admin calls only).
string *query_mailreg_names()
{
    if (geteuid(previous_object()) != ROOT_UID)
	return ({ });
    return copy(mailreg); // Leto
}


void save()
{ 
    save_object(SAVE_F);
}
