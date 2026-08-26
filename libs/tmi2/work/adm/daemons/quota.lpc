/*
// File:      /adm/daemons/quota.c
// Purpose:   maintain preset disk quotas by checking how much disk space
//            a user is using before allowing them to use more
// 93-05-15   Created by Watcher@TMI-2
//            This file is part of the TMI-2 distribution.
//            Please keep this header if you use any of this code.
// 93-07-30   Grendel@TMI-2 Fixed a bug which didn't allow anyone
//            to write to the root directory properly.
// 93-08-18   Pallando@TMI-2 Fixed another bug which was still preventing
//            mv from working with files in the root directory.
*/
 
#include <uid.h>
#include <mudlib.h>
 
inherit DAEMON;
 
#define MAX_RECURSION	6
 
#define DEFAULT_QUOTA	200
#define STUDENT_QUOTA	100
 
#define USER_QUOTAS	"/adm/etc/user_quotas"
 
void load_quotas();
int dir_size(string where, int level);
 
mapping quotas;
 

void create() {  seteuid(getuid());  load_quotas();  }
 
//  This function loads up all the preset user quotas

void load_quotas() {
   string *tmp, file, name;
   int loop, amount;

   quotas = ([ ]);			// Initialize the quotas mapping

   file = read_file(USER_QUOTAS);
   if(!file || !(tmp = explode(file, "\n")))  return;

   for(loop=0; loop<sizeof(tmp); loop++)
     if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "" ||
	sscanf(tmp[loop], "%s:%d", name, amount) != 2)  continue;
     else  quotas[name] = amount;

}
 
 
//  Allow an external user quota query to go through...but if it isn't
//  coming from a ROOT daemon, only give them a copy of the mapping.
 
mapping query_quotas() {  
 //if(geteuid(previous_object()) == ROOT_UID)  return quotas;
 //else return copy(quotas);
   return copy(quotas);
}
 
 
//  This function actually performs the quota check and returns whether
//  the write is allowed or not to the master system.
 
int quota_check(string dir) {
   string *path;
   int quota;
 
   if(!dir || !stringp(dir)) return 0; // error
 
   //	Parse out the directory path

   path = explode(dir, "/");
 
   if(!path || !sizeof(path)) return 1; // root directory
 
   //	If an admin is trying to write somewhere ... let them.

   if(this_player() && adminp(geteuid(this_player())))
	return 1;

   //	First lets see if the requested file/dir is actually a
   //	user directory ... at least at the root user dir level.
 
   if(path[0] == "u" && sizeof(path) >= 3) {

	//  Let Admins use as much space as they want ... they know best.

	if(adminp(path[2]))  return 1;
 
	//  Check to see if there is a preset quota in place for
	//  this particular user, if not, use the DEFAULT_QUOTA.
 
	quota = quotas[path[2]];
	if(!quota)  quota = DEFAULT_QUOTA;
 
	//  Will this write put the user beyond their quota?

	if(dir_size("/u/" + path[1] + "/" + path[2], 0)/1000 >= quota)
	  return 0;
 
	else return 1; 
   }
 
   else if(path[0] == "student" && sizeof(path) > 3) {

        //  Check to see if there is a preset quota in place for
        //  this particular user, if not, use the STUDENT_QUOTA.

        quota = quotas[path[2]];
        if(!quota)  quota = STUDENT_QUOTA;

        //  Will this write put the user beyond their quota?

  	if(dir_size("/student/" + path[1], 0)/1000 >= quota)
          return 0;

        else return 1;
   }
 
   //	Well, if we've gotten this far, its probably an admin or
   //   system directory, and since there are no quotas there, 
   //	let the file write continue.
 
return 1; }
 

//  This function performs the actual totaling of the files and
//  subdirectories within the requested directory.
 
int dir_size(string path, int level) {
   string *dir;
   int loop, size, sub;

   if(level > MAX_RECURSION) return 0;

   size = file_size(path);
 
   if(size == -1)  return 0;
 
   if(size == -2) {
     size = 0;
     dir = get_dir(path + "/");

     if(dir) {
     	sub = sizeof(dir);
	for(loop=0; loop<sub; loop++)
	  size += dir_size(path + "/" + dir[loop], level + 1);
      }
 
   }
 
return size; }
 
