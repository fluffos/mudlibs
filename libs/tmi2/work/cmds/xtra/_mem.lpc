 
//	File	:  /cmds/xtra/_mem.c
//	Creator	:  Bub@Tabor  (4/9/93)
//	Updated	:  Inspiral@Tabor  (4/9/93)
//	
//	Integrated into the TMI-2 mudlib by Watcher  (5/93)
//
//	Uses the memory_info() efun to provide information on the
//	mud's present memory consumption levels.

#include <mudlib.h>
 
inherit DAEMON;

string parse_mem( int mem );

int cmd_mem( string da_ob )
{
   int i, j, mem;
   object ob;
   
   if( da_ob )
      {
      ob = get_object( da_ob );
      if( !ob )
         {
	 write("Mem: Could not locate " + da_ob + ".\n");
         return 1;
      }
      mem = memory_info( ob );
   }
   else
      mem = memory_info();
   if( ob )
      printf("%s is presently consuming %s of memory.\n",
	     identify(ob), parse_mem(mem));
   else
 
   printf("%s is presently consuming %s of memory.\n",
	  capitalize(mud_name()), parse_mem(mem));
   return 1;
}


string parse_mem( int mem ) {
   if( mem > (1024 * 1024) )
	return (sprintf("%.3fM", (mem + 0.0) / 1024 / 1024));
   else
      return  ( mem / 1024 ) + "K" ;
}

int help()
{
   write(
      "Syntax:  mem [object]\n\n"
      "This command will tell you how much memory the specified object\n"
      "is using currently. If no object is given, total memory used \n"
      "by the mud is shown.\n" );
   return 1;
}
