/*
// File:        _praise.c
// Purpose:     A generic report command, inherited by _bug, _idea, etc
// History:
// 93-02-11     Written by Pallando based on Sulam's _bug.c
//              This file is part of the TMI Mudlib distribution.
//              Please include this header if you use this code.
// 93-07-13     Grendel added timestamping to make possible rlog.
// 93-07-20     Grendel added domain logging.
// 93-09-02     Checking for domain directory added.
//              NB Domains with directories different from their euids
//              will not have report logs.
*/

/****************** GENERIC CMD_REPORT *************************/

#include <config.h>
#include <mudlib.h>

#define TMP_FILE TMP_DIR + report_type + "_" + getoid( this_player() )
// Use getoid not geteuid to handle multiple logins of same character.

// DELIM must be the same as in the rlog and clog commands.
#define DELIM "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"

inherit DAEMON;

string report_type, report_file;

int help();

// NB do _not_ put in a seteuid( geteuid( previous_object() ) )
// It needs to be able to write reports to files in other wizards dirs
int cmd_report( string a )
{
  if( a ) { help(); return 1; }
  write( "Begin writing your " + report_type + " report.\n" );
  this_player()-> edit( TMP_FILE, "callback", this_object() );
  return 1;
}

int callback()
{
  string text, report, author, domain;
  object where;

  text = read_file( TMP_FILE );
  rm( TMP_FILE );
  if( !text )
  {
    write( "Report not found ... aborting.\n" );
    return 1;
  }
  where = environment( this_player() );
  report = (string)this_player()->query("cap_name") + " at " +
    ctime(time()) + (where?(" in "+file_name(where)+"\n"):"\n") + text + "\n";
  log_file(report_file, DELIM + time() + "\n" + report);
  report = capitalize( report_type ) + " : " + report;
  // Temporary measure added by Pallando 94-05-20 because I'm sick of
  // the log directory being deleted.
  write_file( "/adm/priv/backup_logging", report );
  if( where && ( domain = master()-> domain_file( file_name( where ) ) ) )
  {
    if( domain == "User" )
    {
      // Wizards generally don't want copies of reports they
      // make themselves in their own workrooms.
      if( ( author = master()-> author_file( file_name( where ) ) ) &&
          ( author != geteuid( this_player() ) ) )
        write_file( user_path( author ) + "reports", report );
    } else {
      domain = "/d/" + domain;
       if( file_size( domain ) == -2 )
        write_file( domain + "/reports", report );
    }
  }
  write("Thanks for the report.  It is now saved.\n" );
  return 1;
}

void abort() { catch( rm( TMP_FILE ) ); }
// Probably don't need the catch, but I am not certain that TMP_FILE
// will always exist on abortion or what rm does if you try to rm
// a non-existant file.  If someone knows, then change it.

int help()
{
  write( ""+
    "Command: " + report_type + "\n"+
    "This will put you into text entry mode to enter " +
    article( report_type ) + " " + report_type + " report.\n"+
    "Your name, location and the time will be automatically\n"+
    "included in the file with your report, for the attention\n"+
    "of the appropriate wizard.  Please do not hesitate to use\n"+
    "this command often.  Feedback is important.\n"+
    "SEE ALSO:\n"+
    "bug      - for reporting errors in code, security loop-holes, etc\n"+
    "typo - for reporting typographical, grammatical and aesthetic errors\n"+
    "idea      - for reporting your ideas\n"+
    "praise      - for showing approval of some feature of the mud\n"+
    "query      - for anything not a bug, idea, typo or praise. Eg\n"+
    " eg \"where are the docs on variable types\" or any other question\n"+
    " you have which you can't find the answer to by reading the docs.\n"+
  "" );
  return 1;
}

/****************** CMD_PRAISE *********************************/

int cmd_praise( string a ) { return cmd_report( a ); }
create() { ::create(); report_type = "praise"; report_file = "PRAISES"; }
