// A quicky object used to convert the standard document files into
// help files recognized by the XPanse MUDlib. This is very rapid
// hacking, clean it up if you like.

#include <rtlimits.h>

string category, cat_name, doc_dir;

unlimited() {
   string *dir_list;
   string curr;
   string mytxt;

   dir_list = get_dir(doc_dir);
   write("Getting files from "+doc_dir+", "+sizeof(dir_list)+" found.\n");
   foreach( curr: dir_list ) {
      mytxt = read_bytes( doc_dir + curr, 0, file_size(doc_dir+curr) );
      write("Converting file "+doc_dir+curr+", "+strlen(mytxt)+" ("+file_size(doc_dir+curr)+") bytes\n");
      mytxt = implode( explode(mytxt, "\t"), "        " );
      mytxt = implode( explode(mytxt, "        "), "#|#" );
      if( mytxt ) {
         write_file( "/help/"+cat_name+"/"+curr+".hlp",
                     category + "\n" +
                     upper_case(curr) + "\n" +
                     mytxt);
      }
   }
}


// doc_dir must end with /
// cat_n shouldn't. Files will be dumped in /help/cat_n/whatever.hlp
make_help( string cat, string cat_n, string doc_d ) {
   category = cat;
   cat_name = cat_n;
   doc_dir = doc_d;
   unlimited();
//   limited(#'unlimited);
}