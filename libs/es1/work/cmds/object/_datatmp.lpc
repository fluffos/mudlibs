//#pragma save_binary

//	File	:  /cmds/xtra/_datatmp.c
//
//      modified from _data.c to see temp data
//               by Indra@ES   (4/29/95)

#include <priv.h>
#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: data [object]\n"

int cmd_datatmp(string str) {
   mapping tmp_list;
   mixed *tmp_klist;
   object what;
   string text;
   int loop;

   if(!str || str == "")  str = "me";

   str = lower_case(str);

   what = get_object(str);

   if(!what) {
   notify_fail("Data: Could not locate that object.\n");
   return 0; }

   tmp_list = (mapping)what->query_temp_ob_data();

   if(!tmp_list || !mapp(tmp_list)) {
   notify_fail("Data: That object does not have any temp data.\n");
   return 0; }

   tmp_klist = keys(tmp_list) ;
   tmp_klist = sort_array(tmp_klist, "sort_keys", this_object());

   if(!tmp_klist || !sizeof(tmp_klist)) {
   notify_fail("Data: That object does not have any temp data.\n");
   return 0; }

   text = "Object :\t" +identify(what)+ "\n\n";

   for(loop=0; loop<sizeof(tmp_klist); loop++)  {
		if( !stringp(tmp_klist[loop]) ) {
			write( "key = "+tmp_klist[loop]+"\n");
			write( "value = "+tmp_list[tmp_klist[loop]]+"\n");
			continue;
		}
      if(strlen(tmp_klist[loop]) > 7)  text += tmp_klist[loop] + "\t: ";
      else text += tmp_klist[loop] + "\t\t: ";

      text += wrap( identify(tmp_list[tmp_klist[loop]]), 60);
   }

   if( sizeof(tmp_klist) > 0) text+= "\n" ;
   text+="A total of "+sizeof(tmp_klist)+" temp data properties.\n\n";

   this_player()->more( explode(text, "\n") );

return 1; }

//  This function is used to sort the key array.

protected int sort_keys(string one, string two) {
	if( !stringp(one) || !stringp(two) ) return 0;
   return strcmp(one, two);  }

//  This function strips out the secured props from the data array.

protected int filter_props(string prop, object target) {

   if(member_array((int)target->query_permission(prop),
	({ MASTER_ONLY, PRIVATE, OWNER_ONLY })) != -1)   return 0;

return 1; }

int help() {

   write( SYNTAX + "\n" +
     "This command allows you to view the saved object data set for a\n" +
     "specified object, in a \"more\" printout format. If no argument is\n" +
     "given, the calling user will be used.\n");

return 1; }
