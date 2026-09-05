/* help
 *
 * Illarion - Nov 2004
 *
 * Suggests similar filenames
 * "all" lists contents of the helpdir instead of using the all file
 * Note there should still be an all file
 *
 */

#define HELPDIR "/doc/helpdir/"
#define HELPDOC "/doc/help"
#define HELPALL "/open/help_all"
#define MORE(x) write(read_bytes(x,0,file_size(x)));

string *valid_chars;
string full_list;

status valid_chars(string str) {
  int s;
  if(!str)
    return 0;
  if(!valid_chars)
    valid_chars=explode("abcdefghijklmnopqrstuvwxyz1234567890_%","");
  str=lower_case(str);
  s=strlen(str);
  while(s--)
    if(member_array(str[s..s],valid_chars) == -1)
      return 0;
  return 1;
}

string make_nice_list(string *list,int col_size,int cols,string lead) {
  int x,s;
  string liststr;
  s=sizeof(list);
  if(lead) liststr=lead;
  else liststr="";
  for(x=0;x<s;x++) {
    liststr+=pad(list[x],col_size);
    if((x+1)%cols==0)
      liststr+="\n"+(lead?lead:"");
  }
  if(x%cols!=0)
    liststr+="\n";
  return liststr;
}

void display_help_files(string *files) {
  int s,x;
  string output;
  s=sizeof(files);
  output="";
  for(x=0;x<s;x++)
    output+=files[x]+" ";
  write(format(output));
} 

status cmd_help(string str) {
  if(!str) {
    MORE(HELPDOC);
    return 1;
  }
  if(str == "all") {
    if(!full_list) {
      string *all_files;
#ifndef __LDMUD__
      all_files=filter_array(get_dir(HELPDIR),"valid_chars",this_object());
#else
      all_files=filter(get_dir(HELPDIR),"valid_chars",this_object());
#endif
      full_list=make_nice_list(all_files,19,4,"  ");
      full_list="                                 [help all]\n"+
                "-----------------------------=========+"+
                "=========-----------------------------\n\n"+
                full_list;
      rm(HELPALL);
      write_file(HELPALL,full_list);
    }
    MORE(HELPALL);
    return 1;
  }
  if(!valid_chars(str)) {
    write("No help found for "+str+".\n");
    return 1;
  }
  if(file_size(HELPDIR+str) < 0) {
    string *alt_filenames;
    int x,s;
    alt_filenames=get_dir(HELPDIR+"*"+str+"*");
    if(sizeof(alt_filenames))
#ifndef __LDMUD__
      alt_filenames=filter_array(alt_filenames,"valid_chars",this_object());
#else
      alt_filenames=filter(alt_filenames,"valid_chars",this_object());
#endif
    if((s=sizeof(alt_filenames))) {
      write("There is no help for :"+str+".  Here are some similar topics:\n");
      write(make_nice_list(alt_filenames,19,4,"  "));
    } else {
      write("No help found for: "+str+".\n");
    }
  } else {
    MORE(HELPDIR+str);
  }
  return 1;
}
