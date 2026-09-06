#include <const.h>

#define MAX_TOPICS 15

int main( string topic ) {
   mixed *possible_files, *possible_dirs;
   string dir, *dir_list, file, *file_list;
   int i;

   WIZ_CHECK

   if( !topic ) {
      notify_fail("==> [Format] man topic\n");
      return 0;
   }

   if( sscanf(topic, "%s/%s", dir, topic) != 2 )
      dir = "";
   else
      dir += "/";
   dir_list = ({ dir });
   possible_dirs = get_dir(DOC_DIR, GETDIR_NAMES | GETDIR_SIZES);
   for( i = 0; i < sizeof(possible_dirs); i += 2 )
   if( possible_dirs[i+1] == -2 )
      dir_list += ({ possible_dirs[i] + "/" + dir });

   possible_files = ({ });

   foreach( dir: dir_list ) {
      file_list = get_dir( DOC_DIR + dir + topic + "*" );
      if( pointerp(file_list) )
      foreach( file: file_list ) {
         if( file_size(DOC_DIR + dir + file) < 0 )
            continue;
         if( file == topic ) {
            possible_files = ({ dir + file });
            dir = 0; // An "early exit" flag; kind of cheap
            break;
         }
         if( sizeof(possible_files) < MAX_TOPICS )
            possible_files += ({ dir + file });
      }
      if( !dir ) break;
   }

   if( sizeof(possible_files) == 0 ) {
      notify_fail("No topics found that match '"+topic+"'\n");
      return 0;
   }

   if( sizeof(possible_files) > 1 ) {
      string buf = "";

      foreach( file : possible_files )
         buf += "  " + file + "\n";
      buf +="Total topics listed: "+sizeof(possible_files);
      if( sizeof(possible_files) == MAX_TOPICS ) // Is possible there are *exactly* MAX_TOPICS items. I don't care.
         buf += " (truncated)";
      msg(buf);
      return 1;
   }

   write( "DISPLAYING "+DOC_DIR+possible_files[0]+"\n");
   "/bin/wiz/more"->main(DOC_DIR + possible_files[0]);
   return 1;
}
