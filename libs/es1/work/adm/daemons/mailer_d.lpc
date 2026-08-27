//	File	:  /adm/daemons/mailer_d.c
//	Creator	:  Huthur@Portals
//	Modified:  Watcher@TMI  (03/27/93)  to allow mailing from bboards
//		    using checks of mailer against this_player(1).
//		    Hopefully this is secure...
//
//	This is the mailer daemons which handles all the mailing
//	activity for the mud.
//
// Zak, 930413		rewritten totally to use mappings
// Dainia, 930622	implemented personal groups
// Zak, 930704		incorporated Dainia's code into this version.
//
//	Version 2.5, 930704
//


#include <config.h>
#include <mailer.h>
#include <uid.h>

// #define QUERY_NAME query("name")
#define QUERY_NAME link_data("name")		// XXX: for TMI 1.0 mudlibs


// The following are the variables that will be saved as the datafiles

mapping *mailbox, my_groups;

nosave	string	file, maildir;
nosave	int	maxmsg;


int
valid_access(string frm)
{
    string accessor, tmp ;
    mixed *owner ;
	// Let root do as they please
    if(geteuid(previous_object()) == ROOT_UID)
	return 1;

	// Next two ifs check to see if this is a trusted mailer
    if(sscanf(file_name(previous_object()),"%s#%*s",tmp))
	accessor = tmp;
    if(member_array(accessor,TRUSTED_MAILERS) >= 0)
	return 1;

	// If a frm == 0 then this is a read operation. If the player may
	// always read mail if he is the owner of the box.
    if(file)
    {
	owner = explode(file,"/");
	if(!owner || !owner[sizeof(owner)-1])
	    return 0;
	owner = owner[sizeof(owner)-1];
	sscanf(owner,"%s-mbox",owner);
//	if ( (string)this_player(1)->QUERY_NAME == owner && !frm )
	if ( this_player(1)->QUERY_NAME == owner && !frm )
	    return 1;
    }

	// If frm != 0 then make sure that frm == this_player(1) to
	// prevent forgeries...
    if(frm == (string)this_player(1)->QUERY_NAME)
	return 1;

    return 0; // Not a legal operation!
} // valid_access


create()
{
    seteuid(ROOT_UID);
    maildir = MAILDIR;
    mailbox = ({ });
    maxmsg = 0;
    file = 0;
} // create


void
update_mbox(string owner)
{
    if (file != MAILDIR + owner + "-mbox")
    {
	if (file)
	    save_object(file);
	file = MAILDIR + owner + "-mbox";
	mailbox = ({ });
	restore_object(file);
	if (!mailbox)
	    mailbox = ({ });
	maxmsg = sizeof( mailbox );
    }
} // update_mbox


int remote_mail(string rcvr, mapping data)
{
    string own, mud;

    if(sscanf(rcvr,"%s@%s",own,mud) != 2)
	return 0;
// printf("Well, remote_mail to %s@%s starting...\n", own, mud);
    MAIL_SERVER->remote_mail(own, mud, data);
    return 1;
} // remote_mail


varargs void
remove_message(string owner, int num)
{
    update_mbox(owner);

    if (!valid_access(0))
    {
	printf("Illegal access attempt to mailer_d.\n");
	return;
    }
    if ( num < 0 || num >= maxmsg )
	return;
		// remove msg & decrement maxmsg
    mailbox = mailbox[0 .. num - 1] + mailbox[ num + 1 .. --maxmsg];
} // remove_message


int
add_message(string owner, mapping data)
{
    string own, mud;

    owner = lower_case(owner);
    if (remote_mail(owner, data))
	return 1;
#if 0		// handled elsewhere
    if (sscanf(owner,"%s@%s",own,mud) == 2)
    {
	MAIL_SERVER->remote_mail(own, mud, data);
	return 1;
    }
#endif
    if (!user_exists(owner))
        return 0;
    update_mbox(owner);
    if (!valid_access(data["from"]))
    {
	printf("Illegal access attempt to mailer_d.\n");
	return 0;
    }
    mailbox += ({ data });
    maxmsg++;
    return 1;
} // add_message


mixed
mail_status(string owner)
{
    int cnt, i;

    update_mbox(owner);
    i = maxmsg;
    while (i--)
    {
	if (!(mailbox[i]["flags"] & MAIL_READ))
	    cnt++;
    }
    return ([ "unread" : cnt, "total" : maxmsg ]);
} // mail_status


void
edit_message(string owner, int num, mapping msg)
{
    update_mbox(owner);
    if (!valid_access(msg["from"]))
    {
	printf("Illegal access attempt to mailer_d.\n");
	return;
    }
    if (num < 0 || num >= maxmsg)
	return;
    mailbox[num] = msg;
} // edit_message


void
flush_files(mapping groups)
{
    if (groups)   // incase someone forgets to pass an arg
	my_groups = groups;
    if (file)
	save_object(file);
} // flush_files


void
set_flags(string owner, int num, int flags)
{
    update_mbox(owner);
    if (!valid_access(0))
    {
	printf("Illegal access attempt to mailer_d.\n");
	return;
    }
    if ( num < 0 || num >= maxmsg )
	return;
    mailbox[num]["flags"] = flags;
} // set_flags


void
biff(string str, string from, string subject)
{
    string	grp, *grparr;
    object	ob;
    int		i;

    if(sscanf(str, "(%s)", grp))
    {
	grparr = ((mapping)GROUP_OB->query_groups())[grp];
	i = sizeof(grparr);
	while(i--)
	    biff(grparr[i], from, subject);
	return;
    }

		/* XXX: query_env() is query() on TMI */
    if ((ob = find_player(str)) && (ob->query_env("mail_notification")))
	tell_object(ob, sprintf("\
>>> New mail has arrived from: %s.\n>>> Subject: %s\n",
capitalize(from), subject));
} // biff


string *
expand_to(mixed str)
{
    string grp, *rtn;
    int i, max;
    mapping grps;
    string t1,t2;

    rtn = ({});
    i = sizeof(str);
    while (i--)
    {
	if(!str[i])
	    continue;
	str[i] = lower_case(str[i]);
	if(sscanf(str[i],"%s@%s",t1,t2) == 2)
	{
	    rtn += ({ str[i] });
	    continue;
	}
	if(sscanf(str[i],"(%s)",grp))
	{
	    grps = (mapping)GROUP_OB->query_groups();
	    if(sizeof(grps[grp]))
		rtn += expand_to(grps[grp]);
	    else
		printf("Group `%s' doesn't exist.\n", grp);
	    continue;
	}
	if(user_exists(str[i]))
	    rtn += ({ str[i] });
	else
	    printf("User `%s' not found.\n", str[i]);
    }
    return rtn;
} // expand_to


string *
send_mail(mapping newmsg)
{
    int		i, j;
    string	*tmpto, *rtn;
    mapping	tmp;

// printf("in send_mail\n");
    if (newmsg["from"] != (string)this_player(1)->QUERY_NAME
	&& !valid_access(newmsg["from"]))
    {
	printf("Illegal access attempt to mailer_d.\n");
	return ({});
    }

    tmpto = uniq_array( expand_to(newmsg["to"]) + expand_to(newmsg["cc"]) );
    i = sizeof(tmpto);
    rtn = allocate(i);
    j = 0;
    while (i--)
	if (!remote_mail(tmpto[i], newmsg))
	    rtn[j++] = tmpto[i];
    rtn = rtn[0..j-1];

    while (j--)
    {
	add_message(rtn[j], newmsg);
	biff(rtn[j], newmsg["from"], newmsg["subject"]);
    }
    return tmpto;
} // send_mail


int valid_shadow()
{
    return 1;
}
