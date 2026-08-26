// Petrarch
// Merentha Lib 1.0
// <getconfig>

varargs int command(string obj) {
string *list;
int i=-1;
  
  message("command", "MUD Name       : "+get_config(0), this_player());
  message("command", "Host           : "+get_config(1), this_player());
  message("command", "Swapfile       : "+get_config(9), this_player());
  message("command", "Include        : "+get_config(13), this_player());
  message("command", "Port           : "+get_config(15), this_player());
  message("command", "Address Server : "+get_config(16), this_player());
  message("command", "Clean up       : "+get_config(17)+" seconds",this_player());
  message("command", "Reset          : "+get_config(18)+" seconds", this_player());
  message("command", "Swap           : "+get_config(19)+" seconds", this_player());
  message("command", "Inherit Chain  : "+get_config(22), this_player());
  message("command", "Max Eval       : "+get_config(23), this_player());
  message("command", "Max Array      : "+get_config(26), this_player());
  message("command", "Max Buffer     : "+get_config(27), this_player());
  message("command", "Max Mapping    : "+get_config(28), this_player());
  message("command", "StrLen         : "+get_config(29), this_player());
  message("command", "Max Bits/Field : "+get_config(30), this_player());
  message("command", "Max Byte Trans : "+get_config(31), this_player());
  message("command", "Max read_file  : "+get_config(32), this_player());
  message("command", "String Hash    : "+get_config(34), this_player());
  message("command", "Object Hash    : "+get_config(35), this_player());
  message("command", "Max users      : "+get_config(36), this_player());

  return 1;
}

string help() {
return "Syntax: getconfig\n\nReturns configuration information based on the driver and startup scripts.";
}
