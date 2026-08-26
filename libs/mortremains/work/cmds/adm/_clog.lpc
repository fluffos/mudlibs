/* File: _clog.c
// Creator: Grendel@tmi-2 07-23-93
//
// Admin command for commenting entries in the various logs.
*/

#include <mudlib.h>
#include <config.h>
#include <flock.h>

// I want to put this in a header file
#ifndef DELIM
#define DELIM "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
#endif

inherit DAEMON;

#define PROG_NAME "clog"
#define SYNTAX "Usage: "+PROG_NAME+" clear | <logfile> <log_id>\n"
#define TMP_FILE TMP_DIR + PROG_NAME + "_" + getoid(this_player())

mapping file_info;

// set euid and initialise the mapping
void
create()
{
  seteuid(getuid());
  file_info=([ ]);
}


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

// the clog command
int
cmd_clog(string arg)
{
  string log_id, euid;
  int id_num;
  string file_name;
  int index;
  string *entries;
  // general usage variables
  string str, str2, *strs;
  int i;
  object ob;

  // get the euid for permissions and for name checking
  euid = geteuid(previous_object());
  if (!euid)
    {
      notify_fail(PROG_NAME+": fatal error: you have no euid!\n");
      return 0;
    }

  notify_fail(SYNTAX);

  if (!arg || arg=="")
    return 0;

  // this is in case things get FUBAR and someone is unable to use
  // the command because the entry from the attempt that went FUBAR
  // never got cleared
  // In an ideal world we wouldn't need this :-)
  if (arg=="clear")
    {
      // make sure there is an outstanding entry
      if (undefinedp(file_info[euid]))
	{
	  notify_fail(PROG_NAME+": no entry to clear\n");
	  return 0;
	}
      // clear file lock
      if (file_info[euid]["file_name"] &&
	  query_lock_object(file_info[euid]["file_name"]) == this_player())
	file_lock(file_info[euid]["file_name"], F_UNLOCK);
      // check for temporary files
      if (file_size(TMP_FILE) >= 0)
	rm(TMP_FILE);
      // clear the entry
      map_delete(file_info,euid);
      write(PROG_NAME+": entry cleared\n");
      return 1;
    }

  // the argument isn't "clear" so make sure we aren't already commenting
  if (!undefinedp(file_info[euid]))
    {
      notify_fail(
	  PROG_NAME+"%s: fatal error: you are already commenting a log\n");
      return 0;
    }

  // get the arguments
  if (sscanf(arg,"%s %s",file_name,log_id) != 2)
    return 0;

  // check the file exists
  file_name = LOG_DIR + file_name;
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

  // check for write access
  if(!member_group(euid, "janitors"))
    if(!master()->valid_write(file_name, euid, "write_file"))
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

  // get the entries
  entries=explode(str, DELIM);

  // find the timestamped entry
//  index = member_array(log_id+"\n", entries, 1);
  index = search_almost_member(log_id+"\n", entries);
  if(index == -1)
    {
      // unlock file
      file_lock(file_name, F_UNLOCK);
      notify_fail(PROG_NAME+": no entry with that id\n");
      return 0;
    }
  // check the format of the entry
  if((sscanf(entries[index],"%d\n%s\n%s", i, str, str2)) != 3)
    {
      // unlock file
      file_lock(file_name, F_UNLOCK);
      notify_fail(sprintf("%s: %s in %s is badly formatted\n", PROG_NAME,
				  log_id, file_name));
      return 0;
    }

  // store the relevant variables globaly
  file_info[euid] = (["file_name":file_name,"index":index,"entries":entries]);
  // get the comment
  printf("Entry:\n%s", entries[index]);
  write("Enter your comment:\n");
  this_player()->edit(TMP_FILE, "edit_done", this_object());
  return 1;
}

void
edit_done()
{
  string comment, euid;
  int timestamp;
  string info, main_entry;
  string file_name, old_name, *entries;
  int index;
  string str;

  seteuid(getuid());
  //check the euid
  euid = geteuid(previous_object());
  if(!euid)
    {
      write(PROG_NAME+": fatal error: you have no euid!\n");
      return;
    }
  // make sure it is a valid call
  if(undefinedp(file_info[euid]))
    {
      write(PROG_NAME+": fatal error: no record of comment attempt\n");
      return;
    }
  // check the mapping has the correct structure.  If so, get the info
  // and delete the entry
  if( !(file_name=file_info[euid]["file_name"]) ||
      !(entries=file_info[euid]["entries"]) ||
      !(index=file_info[euid]["index"],entries[index]) )
    {
      file_lock(file_name, F_UNLOCK);
      rm(TMP_FILE);
      write(PROG_NAME+": fatal error: data object corrupted - aborting\n");
      return;
    }
  map_delete(file_info, euid);

  // get the comment
  comment = read_file(TMP_FILE);
  rm(TMP_FILE);
  if(!comment || comment=="") {
      // unlock file
      file_lock(file_name, F_UNLOCK);
      write("Comment not found: aborting\n");
      return;
  }

  // amend the entry (already checked the format)
  sscanf(entries[index], "%d\n%s\n%s", timestamp, info, main_entry);

  // format the new entry - this makes sure players will see the commented
  // version - normally you dont see your own entries
  if(info[0..1] != "->")
      info="->" + info;
  //say who the comment if from:
  comment=sprintf("COMMENT:\n%s-%s %s\n", comment,
			  capitalize(euid), ctime(time()));

  // rename the old log file,
  // write the new log file,
  // delete the old logfile,
  // and release the lock
  entries[index] = sprintf("%d\n%s\n%s%s\n", time(), info, main_entry, comment);
  old_name = file_name+".clog_old";
  rename(file_name, old_name);
  if(!write_file(file_name, implode(entries,DELIM)))
    {
      write(PROG_NAME+": fatal error: could not write to "+file_name+"\n");
      rename(old_name, file_name);
    }
  else
    {
      rm(old_name);
      write( "Ok.  Your comment has been added to " + file_name + "\n" );
    }
  file_lock(file_name, F_UNLOCK);
}

// if the edit doesn't complete
void
abort()
{
  string euid;

  // get the euid
  euid = geteuid(previous_object());
  if(!euid)
    {
      write(PROG_NAME+": fatal error: you have no euid!\n");
      return;
    }
  // make sure it is valid
  if(undefinedp(file_info[euid]))
    {
      write(PROG_NAME+": fatal error: no record of comment attempt\n");
      return;
    }
  // if the temp file exists, delete it
  if(file_size(TMP_FILE)>=0)
      rm(TMP_FILE);
  // clear the lock on the log
  file_lock(file_info[euid]["file_name"], F_UNLOCK);
  // clear the entry from the mapping
  map_delete(file_info, euid);
} // abort handled

string help()
{
  return(SYNTAX + "\n" + @HELP_TEXT
This admin command is used to add comments to entries in log files
generated in /log with the "praise" family of commands.  Each entry in
such a log has an id number.  This number is displayed when the entry
is read with "rlog".  This id is supplied to this command, which will
then input a comment, and update the id number.  It will also add "->"
to the name of the person who made the original entry.  This will
prevent "rlog" from skipping that entry when the original person reads
the log.
The "clear" option is to be used if something breaks while the
comment is being entered, and the command cannot be used because it
thinks that admin is already making a comment.
This command makes use of the file-locking daemon.
HELP_TEXT
      );
}

/* Notes:
// Security:
//   An entry isn't made in the global mapping until access has been
//   checked, so the existence of such an array is considered sufficent
//   proof the euid has write permission to that file
// Design decision: the file_info mapping is indexed on the euid
//   of the user of the command.  This could have been done based
//   on the "iod" of the user object, which would have allowed
//   someone to log on more than once and comment different logs.
//   However I don't see much neccessity for this, and it would
//   make the code a little less "asthetically sound" :-)
//   If you think it sould be done this way on your mud, and you think
//   it is worth the effort go ahead.

// 07-25-93 Grendel@tmi-2
*/

int clean_up() { return 0; }
