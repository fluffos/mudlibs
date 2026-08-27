//#pragma save_binary

#define MAX_MESGS	50

// Intermud Mailer by Huthar@portals
// Touched up by Buddha@TMI for his own mudlib (name unknown).
// Zak 930127   Added 'Q' (quit no changes), 's' (save note, mark for
//              delete, 'c' (save note, leave alone)
// Watcher 930327 added 'more' reading of the mail
// Zak 930411   fixed null subject bugs, added 'x' (same as 'q').
//
// Zak 930413   V2.1: rewrote most of it, basically to use mappings
//              added '$' (resync folder), 'n' (set current msg #)
//
// Zak 930502   V2.2: added 'p' (current message info). Now need a space
//              for 1st arg (excess chars chopped off).
// Zak 930601   improved group handling.
//              fixed a lot of the 'reply' code.
// Zak 930603   added do_resync, put in safety valve for null 'from' entry
//
// Zak 930605   upped to v2.5 (why not? :)
// Zak 930606   cleaned up text, refer to mail as `items' not `messages'.
// Zak 930622   fixed reply text.. now puts `<from> writes:' now
// Zak 930703   to save mail, now need a home dir. also, default
//              directory for saving is ~ NOT $CWD.
// Zak 930704   incorporated Dainia@TMI's personal group code. Sets
//              `using_mail' if in mailer. Implemented forwarding
//              (idea was Huthar's)
// Zak 930705   fixed `owner' bugs, display more accurate illegal note #
//              mesg. Display prompt after edit abort().
// Zak 930708   minor bugs fixed: cmsg not reset between resync
//              using_mail not being reset within `frm'
// Zak, 930714  check for null entries in TO/CC fields & ignore them.
// Grendel, 930809 Put a \\n after the subject when saving to a file.
// Grendel, 930904 Fixed a bug in mailing to remote groups
// Inspiral, 931230 added support for udp mail system.
// Inspiral, 940111 'w' option to save to file without headers

#include <mailer.h>
#include <config.h>
#include <mudlib.h>
#include <uid.h>
#include <commands.h>
#include <daemons.h>
#include <net/daemons.h>
#include <net/services.h>
#include <net/macros.h>

inherit OBJECT;


nosave int cmsg, maxmsg, start_flag, in_mailer, quitmailflag;
nosave string owner, tmpfilename;
nosave mapping newmsg;
nosave string mail_a_file;

mapping	my_groups;
mapping	*mailbox;
//      contains:
//      "from", "date", "cc", "subject", "message", "flags", "to"


protected void parse_mailcmd( string cmd );
void get_text();
protected void mail( string arg );


void
create() {
  seteuid( ROOT_UID );
  set( "id", ({ "mailer" }) );
  mailbox = ({  });
  my_groups = ([   ]);
} // create


void
init() {
  int i, j;

  if( in_mailer ) {
    remove();
    destruct( this_object() );
    return;
  }

  my_groups = ([   ]);
  owner = ( string ) this_player() -> link_data( "name" );
  if (!owner) {
    remove();
    destruct(this_object());
    return;
  }

  tmpfilename = temp_file( owner, this_player() ) + ".m";
  restore_object( user_mbox_file( owner ), 1 );
  maxmsg = sizeof( mailbox );

  i = maxmsg;

  if( !i ) {
    cmsg = 0;
    return;
  }

  for( cmsg =  - 1, i = 0; i <maxmsg; i++ )
  if( !( mailbox[i]["flags"]&MAIL_READ ) ) {
    cmsg = i;
    break;
  }

  if( cmsg ==  - 1 ) {
    cmsg = maxmsg - 1;
    if( cmsg < 0 )
      cmsg = 0;
  }
  this_player() -> set( "using_mail", 1 );
} // init


string
get_time( int t ) {
  return extract( ctime( t ), 0, 9 );
} // get_time


string
implode_caps( string *a ) {
  int i;
  string temp;

  i = sizeof( a );

  while( i-- )
    if( a[i] ) {
	  temp = "";
	  if( sscanf( a[i], "%s@%s", a[i], temp ) )
	     temp = "@" + nntoh( temp );
      a[i] = capitalize( a[i] ) + temp;
    }

  return( implode( a, ", " ) );
} // implode_caps


int
validate_num( string str ) {
  int num;

  if( str == "" )
    num = cmsg + 1;
  else
    sscanf( str, "%d", num );
  if( num < 1 || num> maxmsg )
    num = 0;  // force num to -1 on exit
  return--num;
} // validate_num


int
inccmsg() {
  if( !maxmsg )
    cmsg = 0;
  else if( ++cmsg >= maxmsg )
    cmsg = maxmsg - 1;
  return cmsg;
} // inccmsg


int *numlist( string str ) {
   mixed *ret, *tmp;
   int i, j, x, y;

   ret = ({ });
   str = replace_string( str, " ", "" );
   tmp = explode( str, "," );

   i = sizeof( tmp );
   while( i-- ) {
      if( sscanf( tmp[i], "%d-%d", x, y ) == 2 ) {
         while( x <= y ) {
             ret += ({ x });
             x++;
          }
      }
      else
         ret += ({ to_int( tmp[i] ) });
   }

   ret = uniq_array( ret );
   return ret;
}


protected
varargs void
headers( int start, int newonly ) {
  int i, cnt;

  if( !maxmsg )  {
    printf( "No mail.\n" );
    cmsg = 0;
    return;
  }
  cnt = 0;

  for( i = start; i < maxmsg; i++ )  {
    if( newonly && ( mailbox[i]["flags"]&MAIL_READ ) )
      continue;
    cnt++;

    if( !mailbox[i]["from"] )    {
	  mailbox[i]["flags"] |= OWNERDELETED;
      continue;
    }

     if( !mailbox[i]["idx"] ) mailbox[i]["idx"] = mailbox[i]["date"] + "";

    printf( "%s%s%2d %-30s (%s) %s\n",
      mailbox[i]["flags"]&MAIL_READ ? " " : "U",
      i == cmsg ?( mailbox[i]["flags"] & OWNERDELETED ? "<" : ">" )
      :( mailbox[i]["flags"] & OWNERDELETED ? "*" : " " ),
      i + 1,
      capitalize( mailbox[i]["from"] ),
      intp( mailbox[i]["date"] )?
      ctime( mailbox[i]["date"] )[0..9] : mailbox[i]["date"][0..9],
      mailbox[i]["subject"][0..25] );
  }
  if( newonly == 2 && !cnt ) // for 'from' command
    printf( "No new mail.\n" );
} // headers


protected
string *
expand_to( string *raw_list ) {
  int i, j;
  string a, b, lcname, *zeta;
  mapping grps, rtn;

  rtn = ([   ]);
  grps = ( mapping ) GROUP_OB -> query_groups();

  raw_list -= ({ "" });
   raw_list -= ({ 0 });
  i = sizeof( raw_list );

  while( i-- )  {
    if( !raw_list[i] )
      continue;

    lcname = lower_case( raw_list[i] );

    if( !undefinedp( rtn[lcname] ) )
      continue;

    if( sscanf( lcname, "%s@%s", a, b ) == 2 )    {
        b = nntoh( b );
         if( !(int) DNS_MASTER -> dns_mudp( b ) ||
          !(int) DNS_MASTER -> query_named_service( b, "mail_q" ) ) {
        printf( "Cannot locate mud or mud doesn't support DNS mail: %s.\n",
                   b );
          printf( "Aborting send to %s@%s.\n", a, b );
          continue;
      }
      if( !a || a == "" )
        printf( "You must specify a username at the remote site.\n" );
      else
        rtn[lcname] = 1;
    }    else    {
      if( sscanf( raw_list[i], "(%s)", a ) )
        lcname = a;
      if( !user_exists( lcname ) )      {
        if( !undefinedp( grps[lcname] ) )        {
          lcname = "(" + lcname + ")";
          if( undefinedp( rtn[lcname] ) )
            rtn[lcname] = 1;
        }        else        {
          zeta = my_groups[lcname];
          if( undefinedp( zeta ) || !sizeof( zeta ) )
            printf( "No such user or group: %s.\n", lcname );
          else          {
            j = sizeof( zeta );
            while( j-- )
              rtn[zeta[j]] = 1;
          }
        }
      }
      else
        rtn[lcname] = 1;
    }
  }
  return( keys( rtn ) );
} // expand_to


void
prompt() {
  if( maxmsg )
    printf( "[%d of %d]& ", cmsg + 1, maxmsg );
  else
    printf( "& " );
} // prompt


protected
varargs void
do_mail( string cmd ) {
  in_mailer = 1;

  if( cmd && cmd != "" )  {
    quitmailflag = 1;
    mail( cmd );
    return;
  }
  if( !in_edit( this_player() ) && !in_input( this_player() ) )
    prompt();
  input_to( "parse_mailcmd" );
} // do_mail


protected
void
get_cc( string arg ) {
  int i, max;
  string *rtn;
  string tmpfile;

 arg = replace_string( arg, ",", " " );
  if( !pointerp( newmsg["cc"] ) ) newmsg["cc"] = ({ });

    newmsg["cc"] = expand_to( uniq_array( newmsg["cc"] + explode( arg, " " ) ) );

  rtn = ( string * ) MAILBOX_D -> send_mail( newmsg );

  max = sizeof( rtn );

  if( max )
    printf( "Mailing to: %s\n", implode_caps( rtn ) );
  else  {
    tmpfile = sprintf( "%s/%s.dead-letter", TMP_DIR, owner );
    printf( "No recipients found. Appending to: '%s'\n", tmpfile );
    write_file( tmpfile, newmsg["message"] + "\n" );
  }

  if( quitmailflag )
  {
    MAILBOX_D -> flush_files( my_groups );
    this_player() -> delete( "using_mail" );
    destruct( this_object() );
  }
  else
    do_mail();
} // get_cc


protected
void
get_to( string arg ) {
  if( arg == "" )  {
    printf( "No users/groups specified.\n" );
    do_mail();
    return;
  }

  newmsg = ([   ]);
   arg = replace_string( arg, ",", " " );
  newmsg["from"] = capitalize( owner );
  newmsg["date"] = time();
  newmsg["to"] = expand_to( explode( arg, " " ) );

  if( !sizeof( newmsg["to"] ) )  {
    if( quitmailflag )    {
      this_player() -> delete( "using_mail" );
      destruct( this_object() );
    }
    else
      do_mail();
    return;
  }
  newmsg["cc"] = ({  });
  if( !mail_a_file ) {
      printf( "Subject: " );
      input_to( "get_subject" );
  }
  else this_object() -> get_subject();
} // get_to


protected
void
mail( string arg ) {
  sscanf( arg, "%s<%s", arg, mail_a_file );
  if( stringp( mail_a_file ) && strlen( mail_a_file ) ) {
     mail_a_file = replace_string( mail_a_file, " ", "" );
     mail_a_file = resolv_path( "cwd", mail_a_file );

   if( !file_exists( mail_a_file ) || !master()->valid_read( mail_a_file,
		geteuid( this_player() ), "read_file" ) ) {
        write( "File: " + identify( mail_a_file ) +
	       " does not exist.  Continuing.\n" );
	     mail_a_file = 0;
     }
  }
  else mail_a_file = 0;

  if( arg == "" )  {
    printf( "To: " );
    input_to( "get_to" );
    return;
  }
  get_to( arg );
} //  mail


int
do_from( string arg ) {
  if (file_name(previous_object()) != CMD_FROM)
    return 0;

  start_flag = 0;
  init();
  cmsg =  - 1;  // don't print cur message marker in 'frm'

  if( arg == "new" )
    headers( 0, 2 );
  else
    headers( 0 );
  in_mailer = 0;
  this_player() -> delete( "using_mail" );
  destruct( this_object() );
  return 1;
} // do_from


protected
int
update_box() {
  int i, num;
  i = maxmsg;

  while( i-- )  {
    if( mailbox[i]["flags"] & OWNERDELETED )    {
      num++;
      MAILBOX_D -> remove_message( owner, i );
    }
    else
      MAILBOX_D -> set_flags( owner, i, mailbox[i]["flags"] );
  }
  return num;
} // update_box


protected
void
do_quit( string cmd ) {
  int num, size;

  if( cmd == "Q" )
    printf( "No changes to mailbox.\n" );
  else  {
    num = update_box();
    if( !num )
      printf( "No items deleted.\n" );
    else
      printf( "%d item%s deleted.\n", num, ( num == 1 ? "" : "s" ) );
  }
   if( !member_group( geteuid( this_player() ), "admin" ) &&
    (size = sizeof( mailbox ) - num) > MAX_MESGS ) {
      printf( "You have %d messages, and our limit is %d.\n"
              "Please delete %d message(s) before you quit.\n",
              size, MAX_MESGS, size - MAX_MESGS );
      do_mail();
      return;
   }
  MAILBOX_D -> flush_files( my_groups );
  this_player() -> delete( "using_mail" );
  in_mailer = 0;
  destruct( this_object() );
  return;
} // do_quit


int
done_more() {
  do_mail();
  return 1;
} // done_more


protected
void
get_subject( string sub ) {
  int i, max;

  if( mail_a_file )
    sub = "File: " + mail_a_file;

  if( sub == "" )  {
    printf( "Null subject line. Hope that's ok.\n" );
    sub = "<no subject>";
  }
  newmsg["subject"] = sub;
  printf( "\n\nFrom   : %s\nTo     : %s",
	 newmsg["from"], implode_caps( newmsg["to"] ) );
  printf( "\nDate   : %s\nSubject: %s\n",
    ctime( newmsg["date"] ), newmsg["subject"] );
  rm( tmpfilename );
  if( !mail_a_file )
  this_player() -> edit( tmpfilename, "get_text", this_object() );
  else {
	 write( "Inserting file " + identify( mail_a_file ) +
		" into message buffer.\n" );
     get_text();
  }
} // get_subject


void
abort() {
  if( previous_object() != find_player( owner ) ) return;
  rm( tmpfilename );

  if( quitmailflag )  {
    this_player() -> delete( "using_mail" );
    destruct( this_object() );
    return;
  }
  prompt();  // because abort() is still technically `in_edit()'
  do_mail();
} // abort


void
get_text() {
  if( previous_object() != find_player( owner ) ) return;
  if( mail_a_file )
    newmsg["message"] = read_file( mail_a_file );
  else
  newmsg["message"] = read_file( tmpfilename );
  if( !newmsg["message"] || newmsg["message"] == "" )
    newmsg["message"] = "Blank message!\n";
  rm( tmpfilename );

  if( !this_player() -> getenv( "mail_no_cc" ) )  {
    printf( "Cc: " );
    input_to( "get_cc" );
    return;
  }

  get_cc( "" );
}


protected
void
do_header( string arg ) {
  int start;

  if( arg == "" )
    headers( 0 );
  else  {
    if( ( start = validate_num( arg ) ) ==  - 1 )
      printf( "Mail # out of range.\n" );
    else
      headers( start );
  }
} // do_header


protected
void
do_setpos( string arg ) {
  int p;
  if( ( p = validate_num( arg ) ) ==  - 1 )
    printf( "No such item #%s\n", arg );
  else  {
    printf( "Current item set to %d\n", p + 1 );
    cmsg = p;
  }
} // do_setpos


protected
void
read_mail( int num ) {
  string tmp_msg, to, cc;
  int i, max;

  to = cc = "";
  max = sizeof( mailbox[num]["to"] );

  for( i = 0; i <max; i++ )
    to += capitalize( mailbox[num]["to"][i] ) + " ";
  max = sizeof( mailbox[num]["cc"] );

  if( max )  {
    cc = "Cc     : ";

    for( i = 0; i < max; i++ )    {
      if( !mailbox[num]["cc"][i] )
        continue;
      cc += capitalize( mailbox[num]["cc"][i] ) + " ";
    }
    cc += "\n";
  }

  if( !mailbox[num]["from"] )
    mailbox[num]["from"] = "Unknown Sender (mailerob)!";

  tmp_msg = sprintf(
    "Item #%d%s\nTo     : %s\n%sFrom   : %s\nDate   : %s\n"
    "Subject: %s\n===================================\n"
    "%s\n",
    ( num + 1 ),
    ( mailbox[num]["flags"] & OWNERDELETED )? " \t[DELETED]" : "",
    to,
    cc,
    capitalize( mailbox[num]["from"] ),
    intp( mailbox[num]["date"] )?
    ctime( mailbox[num]["date"] ): mailbox[num]["date"],
    mailbox[num]["subject"],
    MAILMESG_D -> get_mesg( mailbox[num]["idx"] )
    );

  this_player() -> more( explode( tmp_msg, "\n" ), 1, "Message #" + ( num + 1 ) );

  mailbox[num]["flags"] |= MAIL_READ;
} // read_mail


protected
void
do_help( string arg ) {
  if( arg == "long" )
    this_player() -> more( MAILER_LONG, 1 );
  else
    this_player() -> more( MAILER_SHORT, 1 );
} // do_help


protected
void
delete_mail( string str ) {
  int i, num;
  int *list;

  if( !str || str == "" )
     list = ({ "" });
  else
  list = numlist( str );
  i = sizeof( list );

  while(i--) {
    if( ( num = validate_num( list[i] + "" ) ) ==  - 1 )  {
      printf( "Illegal item value: %d\n", list[i]+1 );
      do_mail();
      continue;
    }

    if( mailbox[num]["flags"] & OWNERDELETED )  {
      printf( "Item #%d already deleted.\n", num + 1 );
      continue;
    }

    mailbox[num]["flags"] |= OWNERDELETED;
    printf( "Item #%d marked for deletion.\n", num + 1 );
  }
} // delete_mail


protected
void undelete_mail( string str ) {
  int num;

  if( ( num = validate_num( str ) ) ==  - 1 )  {
    printf( "Illegal item value.\n" );
    return;
  }

  if( !( mailbox[num]["flags"] & OWNERDELETED ) )  {
    printf( "Item #%d is not deleted.\n", num + 1 );
    return;
  }
  mailbox[num]["flags"] &= ~OWNERDELETED;
  printf( "Item #%d has been restored.\n", num + 1 );
} // undelete_mail


protected
void do_reply( string cmd, string numstr ) {
  int num, i, max;

  if( ( num = validate_num( numstr ) ) ==  - 1 )  {
    printf( "Illegal item number!\n" );
    return;
  }

  newmsg = ([   ]);
  if( cmd == "r" )  {
    newmsg["to"] = ({ mailbox[num]["from"] });
  }  else  {
    newmsg["to"] = uniq_array( ({ mailbox[num]["from"] })
      + mailbox[num]["to"] );
    newmsg["cc"] = mailbox[num]["cc"];
  }

  newmsg["from"] = capitalize( owner );
  newmsg["date"] = time();
  newmsg["subject"] = mailbox[num]["subject"];
  if( strlen( newmsg["subject"] ) < 4 || newmsg["subject"][0..3] != "RE: " )
    newmsg["subject"] = "RE: " + newmsg["subject"];

  printf( "\n\nFrom    : %s\nTo     : %s\n", newmsg["from"],
    implode_caps( newmsg["to"] ) );

  if( sizeof( newmsg["cc"] ) )
    printf( "Cc     : %s\n", implode_caps( newmsg["cc"] ) );
  printf( "Date   : %s\nSubject: %s\n",
	 ctime( newmsg["date"] ), newmsg["subject"] );
  rm( tmpfilename );

  if( this_player() -> getenv( "mail_use_reply_text" ) )  {
    newmsg["message"] = sprintf( "%s writes:\n> %s",
      capitalize( mailbox[num]["from"] ),
      replace_string( (string) MAILMESG_D -> get_mesg( mailbox[num]["idx"] ),
			"\n", "\n> " ) );
    write_file( tmpfilename, newmsg["message"] + "\n" );
  }
  this_player() -> edit( tmpfilename, "get_text", this_object() );
} // do_reply


protected
void
add_group( string str ) {
  string *members, *res, grp, a, b;
  mapping grps;
  int i, n;

  if( !str || str == "" )  {
    printf( "No group specified.\n" );
    return;
  }
   str = replace_string( str, ",", " " );
  members = explode( str, " " );
  n = sizeof( members );

  if( n == 1 )  {
    printf( "No group members named.\n" );
    return;
  }
  grp = lower_case( members[0] );
  members = members[1..( --n )];
  i = n;

  while( i-- )
    members[i] = lower_case( members[i] );

  if( member_array( grp, members ) !=  - 1 )  {
    printf( "You cannot name a group as a member of itself.\n" );
    return;
  }
  grps = ( mapping ) GROUP_OB -> query_groups();

  if( !undefinedp( grps[grp] ) )  {
    printf( "A pre-defined mud group of that name already exists.\n" );
    return;
  }

  if( user_exists( grp ) )  {
    printf( "A player exists with the name you chose for your group.\n" );
    return;
  }

  if( !my_groups )
    my_groups = ([   ]);
  if( !my_groups[grp] )
    my_groups[grp] = ({  });

  res = allocate( n );
  i = 0;

  while( n-- )  {
    if( ( sscanf( members[n], "%s@%s", a, b ) == 2 )
      || ( user_exists( members[n] ) ) )
      res[i++] = members[n];
  }
  if( i )
    my_groups[grp] += res[0..--i];
  printf( "Personal group %s added to.\n", grp );
} // add_group


protected
void
remove_group( string str ) {
  string *members;
  string grp;
  int i, n;

  if( !str || str == "" )  {
    printf( "No group specified.\n" );
    return;
  }
   str = replace_string( str, ",", " " );
  members = explode( str, " " );
  n = sizeof( members );

  if( n == 1 )  {
    printf( "No members named for removal.\n" );
    return;
  }
  grp = lower_case( members[0] );
  members = members[1..( --n )];
  i = n;

  while( i-- )  {
    members[i] = lower_case( members[i] );
    if( member_array( members[i], my_groups[grp] ) !=  - 1 )
      my_groups[grp] -= ({ members[i] });
    else
      printf( "%s: Not a member of group %s.\n", members[i], grp );
  }
  if( !sizeof( my_groups[grp] ) )
    map_delete( my_groups, grp );
  printf( "Removal complete.\n" );
} // remove_group


protected
void
do_groups( string arg ) {
  mapping grps;
  string *groups;
  int i;

  grps = ( mapping ) GROUP_OB -> query_groups();
  groups = keys( grps );
  i = sizeof( groups );

  while( i-- )
    if( sizeof( grps[groups[i]] ) == 1 )
      map_delete( grps, groups[i] );

  if( arg != "" )  {
    if( !sizeof( grps[arg] ) && !sizeof( my_groups[arg] ) )    {
      printf( "That group does not exist!\n" );
      return;
    }
    printf( "Members of groups (%s):\n%-#75s\n", arg,
      my_groups[arg] ? implode( my_groups[arg], "\n" )
      : implode( grps[arg], "\n" ) );
    return;
  }
  groups = keys( grps );
  if( my_groups )
    groups += keys( my_groups );
  printf( "Current active groups:\n%-#75s\n", implode( groups, "\n" ) );
} // do_groups


protected
void
get_forward_to( string arg, int num ) {
  string t;

  if( arg == "" )  {
    printf( "No users/groups specified.\n" );
    do_mail();
    return;
  }
  newmsg = ([   ]);
   arg = replace_string( arg, ",", " " );
  newmsg["from"] = owner;
  newmsg["date"] = time();
  newmsg["to"] = expand_to( explode( arg, " " ) );

  if( !sizeof( newmsg["to"] ) )  {
    do_mail();
    return;
  }
  newmsg["cc"] = ({  });
  t = mailbox[num]["subject"];
  if( strlen( t ) <  5 || t[0..4] != "FWD: " )
    t = "FWD: " + t;
  newmsg["subject"] = t;
  printf( "\n\nFrom    : %s\nTo     : %s\n", newmsg["from"],
    implode_caps( newmsg["to"] ) );

  if( sizeof( newmsg["cc"] ) )
    printf( "Cc     : %s\n", implode_caps( newmsg["cc"] ) );
  printf( "Date   : %s\nSubject: %s\n",
	 ctime( newmsg["date"] ), newmsg["subject"] );
  rm( tmpfilename );
  newmsg["message"] = sprintf( "BEGIN FORWARDED TEXT:\n%s writes:\n> %s",
    capitalize( mailbox[num]["from"] ),
    replace_string( (string) MAILMESG_D -> get_mesg( mailbox[num]["idx"] ),
		"\n", "\n> " ) );
  write_file( tmpfilename, newmsg["message"] + "\n" );
  this_player() -> edit( tmpfilename, "get_text", this_object() );
} // get_forward_to


protected
void
do_forward( string arg ) {
  string target;
  int num;

  if( !arg || arg == "" )  {
    printf( "To: " );
    input_to( "get_forward_to", 0, cmsg );
    return;
  }
  num = 0;

  if(  sscanf( arg, "%d %s", num, target ) != 2
    && sscanf( arg, "%d", num ) != 1 )  {
    printf( "Usage: f <num> [<destination>]\n" );
    return;
  }
  if( sscanf( arg, "%d %s", num, target ) != 2 )
    num = cmsg;

  if( ( num = validate_num( num + "" ) ) ==  - 1 )  {
    printf( "Illegal item number!\n" );
    return;
  }

  if( !target )  {
    printf( "To: " );
    input_to( "get_forward_to", 0, num );
    return;
  }
  get_forward_to( target, num );
} // do_forward


protected
varargs
void
do_save( string cmd, string arg, int flag )
{
  string file, dir, to, cc;
  int i, num, max;

  dir = user_path( this_player() -> query( "name" ) );
  if( !directory_exists( dir ) ) {
    printf( "Sorry, but only wizards with directories can save mail.\n" );
    return;
  }
  num = 0;
  if( arg == "" || ( sscanf( arg, "%s %d", file, num ) != 2 &&
    sscanf( arg, "%s", file ) != 1 ) )
  {
    printf( "Usage: %s <file> [<num>]\n", cmd );
    return;
  }
  if( sscanf( arg, "%s %d", file, num ) != 2 )
    num = cmsg + 1;

  if( ( num = validate_num( num + "" ) ) ==  - 1 )
  {
    printf( "Illegal item number!\n" );
    return;
  }
  file = resolv_path( dir, file );
  if( !master() -> valid_write( file, ( string ) this_player() -> query( "name" ), "do_save" ) )
  {
    printf( "%s: Permission denied.\n", file );
    return;
  }
  if( sizeof( mailbox[num]["cc"] ) )
    cc = implode_caps( mailbox[num]["cc"] );
  else
    cc = "";

  if( !flag )
  write_file( file, sprintf( "\
    From : %s\nTo : %s\n%sDate : %s\nSubject: %s\n\
    ==================================\n",
    capitalize( mailbox[num]["from"] ),
    implode_caps( mailbox[num]["to"] ),
    cc,
    intp( mailbox[num]["date"] )?
    ctime( mailbox[num]["date"] ): mailbox[num]["date"],
    mailbox[num]["subject"] ) );
  write_file( file,
	 sprintf( "%s\n",
		 (string) MAILMESG_D -> get_mesg( mailbox[num]["idx"] ) ) );

  printf( "Item '%s' written to: %s.\n", mailbox[num]["subject"], file );
  if( cmd == "s" || cmd == "w" )
    mailbox[num]["flags"] |= OWNERDELETED;
} // do_save


protected
varargs
void
do_resync( int flag )
{
  if( !flag )
    printf( "Re-syncing folder.\n" );
  ( void ) update_box();
  MAILBOX_D -> flush_files( my_groups );
  in_mailer = 0;  // to stop init from remove()ing us..
  init();
  headers( 0, this_player() -> getenv( "mail_entry_unread" ) == 0 ? 0 : 1 );
  in_mailer++;
} // do_resync


protected
void
parse_mailcmd( string cmd )
{
  string arg, ocmd, tmp;
  int num;

  ocmd = cmd;
  arg = "";

  if( cmd == "" || cmd == "n" || cmd == "+" )
  {
    if( start_flag && cmsg == inccmsg() )
      ocmd = "-1";
    else
      ocmd = "" + ( cmsg + 1 );
    cmd = "n";  // makes switch() below easier.
  }
  else
  {
    sscanf( cmd, "%s %s", cmd, arg );
    cmd = cmd[0..0];
  }

  switch( cmd )
  {
    case "d":
    delete_mail( arg );
    break;
    case "g":
    do_groups( arg );
    break;
    case "a":
    add_group( arg );
    break;
    case "A":
    remove_group( arg );
    break;
    case "m":
    mail( arg );
    return;
    case "f":
    do_forward( arg );
    break;
    case "#":
    do_setpos( arg );
    break;
    case "-":
    case "p":
    start_flag = 1;
    cmsg--;
    if (cmsg < 0) {
        printf( "At first item.\n" );
        cmsg = 0;
    } else {
        read_mail( cmsg );
        return;
    }
    break;
    case "R":
    case "r":
    do_reply( cmd, arg );
    return;
    case "Q":
    case "q":
    case "x":
    do_quit( cmd );
    return;
    case "u":
    undelete_mail( arg );
    break;
    case "?":
    do_help( arg );
    break;
    case "i":
    case "h":
    do_header( arg );
    break;
    case "c":
    case "s":
    do_save( cmd, arg );
    break;
    case "w":
    do_save( cmd, arg, 1 );
    break;
    case "$":
    do_resync();
    break;
    case "n":
    default:
    if( ocmd && sscanf( ocmd, "%d", num ) )
    {
      if( num> 0 && num  <= maxmsg )
      {
        cmsg = num - 1;
        start_flag = 1;
        read_mail( num - 1 );
        return;
      }
      else
        if( cmd == "n" )
          printf( "At last item.\n" );
      else
        printf( "Invalid note number.\n" );
    }
    else
      printf( "Invalid mail command.\n" );
    break;
  } // switch
  do_mail();
} // parse_mailcmd


int start_mail( string arg )
{
	if( member_array(file_name( previous_object() ), TRUSTED_MAILERS)==-1 ) {
	   	write( "You can't do that!\n" );
    	destruct( this_object() );
		return 0;
	}

  start_flag = 0;
  if( !arg ) //  Don't show headers if just mailing
  {
    printf( "InterMUD Mailer v3.2  [? for help]\n" );
    do_resync( 1 );
  }
  do_mail( arg );
  return 1;
} // start_mail


int
valid_shadow()
{
  return 1;
}
