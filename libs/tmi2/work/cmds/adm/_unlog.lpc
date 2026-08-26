/* File    : _unlog.c
// Creator : Grendel@tmi-2
// When    : 93-08-11

// Admin command for removing entries in the various logs.
*/

#include <mudlib.h>
#include <config.h>
#include <flock.h>

// I want to put this in a header file
#ifndef DELIM
#define DELIM "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
#endif

inherit DAEMON;

#define PROG_NAME "unlog"

#define SYNTAX "Usage: "+PROG_NAME+" <logfile> <log_id>\n"
#define TMP_FILE TMP_DIR + PROG_NAME + "_" + getoid(this_player())

// this controls where the old entries go.  Don't define it if you don't
// want them to be stored
#define ATTIC_FILE(x) LOG_DIR + "attic/" + (x)

/* replacement for old member_array() */
int search_almost_member(string s, string *items) {
    int i, l;
    string t;

    if (!(l = s ? strlen(s) : 0) || !(i = items ? sizeof(items) : 0))
        return -1;

    l--;
    while (i--)
        if ((((t = items[i]) ? strlen(t) : 0) > l) && (s == t[0..l]))
            return i;
    return -1;
}

// the unlog command
int cmd_unlog (string arg)
{
  string log_id;
  string log_name, file_name, old_name;
  int index;
  string *entries;
  // general usage variables
  string str;

  notify_fail(SYNTAX);

  if(!arg || arg=="")
      return 0;

  // get the arguments
  if(sscanf(arg,"%s %s", log_name, log_id)!=2)
      return 0;

  // check the file exists
  file_name = LOG_DIR + log_name;
  switch(file_size(file_name))
    {
     case -2:
      notify_fail(PROG_NAME+": "+file_name+" is a directory\n");
      return 0;
     case -1:
      notify_fail(PROG_NAME+": " + file_name + " does not exist\n");
      return 0;
     case 0:
      write(PROG_NAME+": " + file_name + " is empty\n");
      return 1;
    }

  // set our euid
  seteuid(geteuid(previous_object()));

  // check for write access
  if(!master()->valid_write(file_name, geteuid(), "write_file"))
    {
      notify_fail(PROG_NAME+": "+file_name+": permission denied\n");
      return 0;
    }

  // lock the logfile
  if(!file_lock(file_name, F_LOCK))
    {
      notify_fail(PROG_NAME+": could not gain lock on file\n");
      return 0;
    }

  // read the log
  str = read_file(file_name);
  if(!str)
    {
      file_lock(file_name, F_UNLOCK);
      notify_fail(PROG_NAME+": could not read " + file_name +"\n");
      return 0;
    }

  // get the new entries
  entries = explode(str, DELIM);

  // find the timestamped entry
  index = search_almost_member(log_id+"\n", entries);
  if(index == -1)
    {
      // unlock file
      file_lock(file_name, F_UNLOCK);
      notify_fail(PROG_NAME+": no entry with that id\n");
      return 0;
    }

#ifdef ATTIC_FILE
  write_file(ATTIC_FILE(log_name), DELIM + entries[index]);
#endif

  entries -= ({ entries[index] });

  // rename the old log file,
  // write the new log file,
  // delete the old logfile,
  // and release the lock
  old_name=file_name+"." + PROG_NAME + "_old";
  rename(file_name, old_name);
  if(!write_file(file_name, implode(entries,DELIM)))
    {
      notify_fail(PROG_NAME+
		  ": fatal error: could not write to "+file_name+"\n");
      rename(old_name, file_name);
      file_lock(file_name, F_UNLOCK);
      return 0;
    }
  rm(old_name);
  write( "Ok.  That entry has been removed from " + file_name + "\n" );
  file_lock(file_name, F_UNLOCK);

  return 1;
}

string help()
{
  return(SYNTAX + "\n\n" +
#ifdef ATTIC_FILE
  "This admin command moves an entry from a log to an archive file.\n"
#else
  "This admin command deletes an entry from a log.\n"
#endif
      );
}
