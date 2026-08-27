//	File	: /adm/daemons/banish.c
//	Creator	: Someone@TMI
//	Updated	: Karathan  (7/13/93)  Unified banish code.
//		  Karathan  (8/11/93)  Bug tidying, streamlined.
//		  Karathan  (8/12/93)  Bug tidying; added email registration
//		   command backing code.

#include <uid.h>
#include <daemons.h>

//  Name changed deliberately because regexp() requires a different name format
//  to the previous version.  Note that '*fuck*' will not do - '.*fuck.*' is
//  required.  '*fuck*' functions as '*'.
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

int exam_str(string src,string pot)
{
    int i ;
   
    if( pot=="*" || src == pot ) return 1 ;
    i = strsrch( pot,"*") ;    
    if((i>0)&& (src[0..i-1]==pot[0..i-1]) ) return 1 ;
    return 0 ;
}

//  Check incoming ip number against list of banned sites. Allow partial
//  matches so that 129.51 also catches 129.51.8.24, etc.
int check_banned_site(string ip)
{
    int i, j ,banlen ,usrlen ,f_exam ,b_exam ;
    string *usr,*banished,baned ;

    if (!sites) return 0;
    
   // explode the ip where user from    
    usr = explode(ip,".") ;

    for(i=0;i<sizeof(sites);i++)
       {  
         usrlen = sizeof(usr) ;
         banished = explode(sites[i],".") ;
         banlen = sizeof(banished) ;

         if( usrlen < banlen) continue ;
         else { 
               for(j=0 ; j < banlen ; j++)
                  { f_exam = exam_str(usr[j],banished[j]) ;
                    if( f_exam!=1 )break ;
                   }
               for(j=1 ; j < banlen+1 ; j++)
                  { b_exam = exam_str(usr[usrlen-j],banished[banlen-j]) ;
                    if( b_exam!=1 )break ;
                   }
               if(f_exam||b_exam)
                  { write(sites[i]+" is banished.\n");
                    return 1 ;}
              }
        }     
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
