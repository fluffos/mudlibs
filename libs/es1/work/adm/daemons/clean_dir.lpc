
//	File	:  /adm/daemons/clean_dir.c
//	Creator	:  Watcher@TMI  (02/04/93)
//	Updated	:  Watcher@TMI  (02/20/93) for recursive dir wipe
//
//	This daemon cleans the contents of inputed directory.
//	However, any directory selection within the SECURE (adm)
//	directory tree will be blocked.  If flag is set,
//	even the PROTECTed files will be deleted.

#include <mudlib.h>
#include <config.h>
#include <uid.h>

inherit DAEMON ;

#define	PROTECT	({ "README" })

protected int remove_contents(string path, int flag);

int clean_dir(string dir, int flag) {
   string tmp;

   //	Check euid of initiator to confirm correct permissions

   if(geteuid(previous_object()) != ROOT_UID &&
      !member_group(geteuid(previous_object()), "admin"))
	return 0;

   if(!dir || dir == "")  return 0;

   if(file_size(dir) != -2)  return 0;		//  Not a directory

   //	Protect the SECURE directory ... just in case :)

   if(sscanf(dir, SECURE_DIR + "%s", tmp) == 1)  return 0;

return remove_contents(dir + "/", flag); }


//  This function recursively cleans a specific directory path
//  If flag = 1, it will not protect PROTECTed files

protected int remove_contents(string path, int flag) {
   mixed *dir;
   string what;
   int loop;

   //	Get directory contents array

   dir = get_dir( path );
   if(!dir || !sizeof(dir))  return -1;

   //	Loop through and delete contents of dir array

   for(loop=0; loop<sizeof(dir); loop++) {
   what = path + dir[loop];

   //	If selection is a directory ... recursively clean and remove it

   if(file_size( what ) == -2) {
   remove_contents(what + "/", 1);
   rmdir(what);
   }

   //	If file isn't protected ... remove it

   if(flag || member_array(dir[loop], PROTECT) == -1)
	rm(what);

   }

return 1; }
