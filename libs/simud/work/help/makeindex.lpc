// More rapid hacking ...

#include <sys/rtlimits.h>
#include <const.h>

string category, cat_name, doc_dir;
string * file_index;

void unlimited() {
   string *dir_list;
   string curr, ext, buf;
   int i, longest;

   dir_list = get_dir(doc_dir);
   write("Getting files from "+doc_dir+", "+sizeof(dir_list)+" found.\n");
   file_index = ({ });
   longest = 0;
   // Want to guarantee ordering
   for( i = 0; i < sizeof(dir_list); i++ ) {
      if( dir_list[i][<4..<1] != ".hlp" || read_file(doc_dir + dir_list[i], 1, 1)[0] == '!' )
         continue;
      dir_list[i] = dir_list[i][..<5];
      file_index += ({ dir_list[i] });
      if( strlen(dir_list[i]) > longest ) longest = strlen(dir_list[i]);
   }

   buf="INDEX\nINDEX OF "+doc_dir+"\n~CREF";
   for( i = 0; i < sizeof(file_index); i++ )
      buf += pad( file_index[i], longest + 1, JUST_LEFT );

   rm( doc_dir + "index.hlp" );
   write_file( doc_dir + "index.hlp", buf+"\n\n" );
}


// doc_d is where files will be indexed. It should be a full path.
void make_help( string doc_d ) {
   if( file_size(doc_d) != -2 ) raise_error("makeindex: "+doc_d+" is not a directory");
   if( doc_d[<1] != '/' ) doc_d += "/";
   doc_dir = doc_d;
   unlimited();
}
