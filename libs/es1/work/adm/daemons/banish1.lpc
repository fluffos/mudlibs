#include <uid.h>
#include <daemons.h>

#define SAVE_F        "/adm/etc/banishes"
#define OLD_SAVE_F    "/adm/etc/ban_site"
#define BANNED_NAMES  ({ })
#define BANNED_SITES  ({ })

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
	sites = BANNED_SITES ;
    if (!mailreg)
	mailreg = ({ });		// Should never be defaults for this!
}

int strexam(string src,string pot)
{
    int i,j,flag ;
    string *part ;
   
    if( src == pot ) return 1 ;
    if( !strsrch(pot,"*")) return 0 ;
    
    part = explode(pot,"*") ;
    
    for(i=0;i<sizeof(part);i++)
       {
          if(strsrch(part[i],src) == -1)
            {  flag = 0 ;
               break ;
             }
          else
            {  flag = 1 ;
               src = src[sizeof(part[i])..sizeof(src)] ;
               continue ;
             }
        }        
    return flag ;
}

int check_banned_site(string ip)
{
    int i ;

    if (!sites) return 0;
    
    for(i=0;i<sizeof(sites);i++)
       {  
          if(strexam(ip,sites[i]))
            {   
               return 1 ;
               break ;
             }
        }     
    return 0 ;
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

    if (!mailreg || name == "")
	return "";
    for (i = 0; i < sizeof(mailreg); i += 2)
	if (name == mailreg[i])
	    return mailreg[i + 1];
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
    return sites;
}


//  Return the list of banished names (admin calls only).
string *query_banished_names()
{
    if (geteuid(previous_object()) != ROOT_UID)
	return ({ });
    return names;
}


//  Return the list of email-registration names (admin calls only).
string *query_mailreg_names()
{
    if (geteuid(previous_object()) != ROOT_UID)
	return ({ });
    return mailreg;
}


void save()
{ 
    save_object(SAVE_F);
}
