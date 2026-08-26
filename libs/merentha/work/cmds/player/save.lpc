// Petrarch
// Merentha Lib 1.0
// save.c

string help() {
return "Syntax: save\n\nThis command saves your character.  Your \
character is automatically saved every 5 minutes as well, but this command \
will update your player file immediatly.  You will also automatically be \
updated when you quit.\n\nSee also: quit";
}


varargs int command(string str) {
  if(str) return 0;
  this_player()->save_player(this_player()->query_name());
  message("info", "Your character has been saved.", this_player());
  return 1;
}

