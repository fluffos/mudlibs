string player_name(string name) {
  return lower_case(replace_string(replace_string(name, "-", ""), "'",  ""));
}

int player_exists(string name) {
  name=player_name(name);
  return file_exists("/save/users/"+name[0..0]+"/"+name+".o");
}

