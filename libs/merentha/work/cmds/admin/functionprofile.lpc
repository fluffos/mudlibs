// Petrarch
// Merentha Lib 1.0
// <functionprofile>

varargs int command(string obj) {
object ob, *ob_list;
mapping item=([]);
string *list;

#ifndef __PROFILE_FUNCTIONS__
  message("command", "PROFILE_FUNCTIONS was not compiled into the driver.", this_player());
#else
  if(obj) {
    ob=present(obj, this_player());
    if(!ob) ob=present(obj, environment(this_player()));
    if(!ob) ob=find_object(obj);
    if(!ob) return notify_fail("Could not find "+obj+"\n");
    ob_list=({ob});
  } else ob_list=objects();

  message("command", "Dumping function profiles into /log/functionprofile.out", this_player());
  rm("/log/functionprofile.out");
  write_file("/log/functionprofile.out","Object\tFunction\tCalls\tSelf\tChildren\n");
  foreach (ob in ob_list) {
    list=function_profile(ob);
    foreach (item in list) {
      write_file("/log/functionprofile.out", file_name(ob)+"\t"+item["name"]+"\t"+item["calls"]+"\t"+item["self"]+"\t"+item["children"]+"\n");
    }
  }
  message("command", "Dumping complete!", this_player());
#endif
  return 1;
}

string help() {
return "Syntax: functionprofile <object>\n\nDumps a function profile list into /log/functionprofile.out.  If you do not specify an <object> then function profiles for all objects are dumped.";
}
