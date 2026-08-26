// Petrarch
// Merentha Lib 1.0
// <inheritlist>

varargs int command(string obj) {
object ob;
string *list;
  if(!obj) return notify_fail("Syntax: inheritlist <object>\n");
  ob=present(obj, this_player());
  if(!ob) ob=present(obj, environment(this_player()));
  if(!ob) ob=find_object(obj);
  if(!ob) return notify_fail("Could not find "+obj+"\n");
  
  message("command", "Inherited list of object = "+file_name(ob)+"\n"+format_page(inherit_list(ob), 2), this_player()); 
  message("command", "Deep Inherited list of object = "+file_name(ob)+"\n"+format_page(deep_inherit_list(ob), 2), this_player()); 

  return 1;
}


string help() {
return "Syntax: inheritlist <object>\n\nReturns a list of object which <object> has inherited.";
}
