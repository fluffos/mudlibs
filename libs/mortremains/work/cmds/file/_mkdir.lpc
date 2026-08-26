/*
// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam(1-8-92)
// Help added by Brian (1/28/92)
// Watcher generally cleaned up the command (4/9/93)
// Leto added multiple args (eg 'mkdir a b c d') 120194
*/

#include <uid.h>
#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: mkdir [directory]\n"
 
int cmd_mkdir(string str) {

  string rest;
 
   notify_fail( SYNTAX );
 
   seteuid(geteuid(previous_object()));
 
   if(!str || str == "")  return 0;

  if (sscanf(str,"%s %s",str,rest)) cmd_mkdir(rest);
   str = resolv_path("cwd", str);
 
   if(file_exists(str)) {
     	notify_fail("Mkdir: " + str + " already exists as a file.\n");
   return 0; }
 
   if(directory_exists(str)) {
	notify_fail("Mkdir: Directory already exists.\n");
   return 0; }
 
   if((int)master()->valid_write(str, previous_object(), "mkdir") == 0) {
	notify_fail("Mkdir: Creation of " + str + " denied.\n");
   return 0; }
   
   write(mkdir(str) ? "Mkdir: " + str + " created.\n" :
		      "Mkdir: Failed to create " + str + ".\n");
 
return 1; }

string
help() {
 
  return( SYNTAX + "\n"+
   "This command makes a new directory with the name specified.\n"+
        "If no path information is supplied, th new directory will be\n"+
        "a sub directory of the present working directory.  For more\n"+
        "on specifying paths see help cd.\n");
}
/* EOF */
