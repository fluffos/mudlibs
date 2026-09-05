id(str) { return (str == "more_verte_object"); }
drop() { return 1; }
get() { return 1; }
string more_file;
int more_line;
init() { add_action("more", "x123321123321"); }
#define CHUNK 20
more(str)
{
   string tmore;
   string pwd;
   object myself;
   string tilda,blah;
   myself=this_player();
   if(this_player()) pwd=this_player()->get_path();
   if(!pwd) pwd="";
   
   if (!str)
      return (destruct(this_object()), 0);
   
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
      tilda=extract(tmore,1,strlen(tmore));
      tmore = "/players/"+myself->query_real_name()+tilda;
   }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   if(file_size(tmore) < 1) {
      write("That file does not exist.\n");
      destruct(this_object());
      return 1;
   }
   more_file = str;
   more_line = 1;
   if (cat(more_file, more_line, CHUNK) == 0) {
      write("No such file\n");
      destruct(this_object());
      return 1;
   }
   input_to("even_more");
   write("More: (line " + (CHUNK + 1) + ") ");
   return 1;
}

static even_more(str) {
   if (str == "" || str == "d")
      more_line += CHUNK;
   else if (str == "q") {
      write("Ok.\n");
      destruct(this_object());
      return;
   } else if (str == "u") {
      more_line -= CHUNK;
      if (more_line < 1)
         more_line = 1;
   }
   if (cat(more_file, more_line, CHUNK) == 0) {
      more_file = 0;
      write("EOF\n");
      destruct(this_object());
      return;
   }
   write("More: (line " + (more_line + CHUNK) + ") ");
   input_to("even_more");
}
