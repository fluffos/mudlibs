// Petrarch
// Merentha Lib 1.0
// <memoryinfo>

varargs int command(string obj) {
object ob;

  if (obj) {
    ob=present(obj, this_player());
    if(!ob) ob=present(obj, environment(this_player()));
    if(!ob) ob=find_object(obj);
    if(!ob) return notify_fail("Could not find "+obj+"\n");
    message("command", file_name(ob)+" = "+memory_info(ob)+" bytes",this_player());
    return 1;
  }
  message("command", "The MUD is using = "+memory_info()/1024+" Kbytes", this_player());
  return 1;
}

string help() {
return "Syntax: memoryinfo <object>\n\nReturns the number of bytes of memory the object is using.  If no object is named it returns the total amount of memory the MUD is currently using.";
}
