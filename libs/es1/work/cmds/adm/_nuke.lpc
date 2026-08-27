//#pragma save_binary
//	File	:  /cmds/adm/_nuke.c
//	Creator	:  Watcher@TMI  (02/24/93)
//	Edited  :  Karathan  (07/13/93) to incorporate new banish daemon
//
//	This command allows an admin to remove all reference to
//	a selected user. The user's data files will be saved in
//	the ARCHIVE_DIR tree unless it is undefined.

// 93-07-30 Grendel@tmi-2 Kludged to handle mail boxes

#include <config.h>
#include <login.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX 	"Syntax: nuke [-abd] [user]\n"

int cmd_nuke(string str) {
   string flags, tmp1, tmp2;
   int banish, delete, archive;

   if(!member_group(geteuid(previous_object()), "admin"))  return 0;

   notify_fail( SYNTAX );

   if(!str || str == "")  return 0;

   str = lower_case(str);

   if(sscanf(str, "-%s %s",flags, str) == 2) {
	if(sscanf(" " + flags + " ", "%sb%s", tmp1, tmp2) == 2)
	   banish = 1;
	if(sscanf(" " + flags + " ", "%sd%s", tmp1, tmp2) == 2)
	   delete = 1;
	if(sscanf(" " + flags + " ", "%sa%s", tmp1, tmp2) == 2)
	   archive = 1;
   }

   if(archive && delete) {
   write("Nuke: You cannot both delete and archive a user.n");
   return 1; }

   if(ARCHIVE_DIR && !delete)  archive = 1;

   if(!user_exists(str)) {
   write("Nuke: No such user exists.\n");
   return 1; }

   write("Are you sure you wish to nuke " + capitalize(str) + "? [y/n] ");
   input_to("confirm_deletion", 0, str, banish, delete, archive);

return 1; }

protected int confirm_deletion(string str, string name, int banish,
			    int delete, int archive) {

   if(!str || member_array(lower_case(str), ({ "yes", "y" })) == -1) {
   write("Nuke: Character deletion aborted.\n");
   return 1; }

   if (banish)
       BANISH_D->banish_name(name);

   if(find_player(name)) {

   tell_object(find_player(name),
      "\nA bolt of lightning descends from the heavens, and all goes dark.\n");
   tell_room(environment(find_player(name)),
      "A bolt of lightning suddenly descends from the heavens. It strikes\n" +
      capitalize(name) + " in the chest, leaving only a pile of ashes where " +
      subjective((string)this_player()->query("gender")) + " once stood.\n",
      ({ find_player(name) }));

   find_player(name)->save_data();

   find_player(name)->remove(); }

   //	Either move data files to ARCHIVE_DIR dir, or completely delete

   if(archive) {

   if(!directory_exists(ARCHIVE_DIR + "user/")) {
     mkdir( ARCHIVE_DIR[0..strlen(ARCHIVE_DIR)-2] );
     mkdir( ARCHIVE_DIR + "user" );
     mkdir( ARCHIVE_DIR + "connection" );
     mkdir( ARCHIVE_DIR + "mail" );
   }

   if(file_exists(DATA_DIR+"/std/user/"+name[0..0]+"/"+name+ SAVE_EXTENSION))
   rename(DATA_DIR+"/std/user/" + name[0..0] + "/" + name + SAVE_EXTENSION,
	  ARCHIVE_DIR + "user/" + name + SAVE_EXTENSION);
   rename(PDATA_DIR+name[0..0]+ "/" + name + SAVE_EXTENSION, ARCHIVE_DIR +
	  "connection/" + name + SAVE_EXTENSION);
   if(file_size("/data/mail/"+name+"-mbox.o") >= 0)
	   rename("/data/mail/"+name+"-mbox.o",
		  ARCHIVE_DIR+"mail/"+name+"-mbox.o");
   write("Nuke: Character archived and deleted.\n");
   }

   else {
   if(file_exists(DATA_DIR+"/std/user/"+name[0..0]+"/"+name+SAVE_EXTENSION))
   rm(DATA_DIR + "/std/user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
    rm (PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION );
   if(file_size("/data/mail/"+name+"-mbox.o") >= 0)
	   rm( "/data/mail/"+name+"-mbox.o" );
   write("Nuke: Character deleted.\n");
   }

return 1; }

int help() {

   write( SYNTAX + "\n" +
     "This command completely removes the the data files of the inputted\n" +
     "user, as well as nicely removing them if they are presently online.\n" +
     "If the 'b' flag is given, it will automatically add the user's name\n" +
     "to the mudlib's banish file. If the 'a' flag is selected, then the\n" +
     "user's data files will be archived before character removal, and if\n" +
     "the 'd' flag is set, it will override any archive default sets, and\n" +
     "delete the data files without archiving.\n");

   if(ARCHIVE_DIR)
   write("All character deletions are automatically archived unless the\n" +
	 "delete flag is requested.\n");

return 1; }
