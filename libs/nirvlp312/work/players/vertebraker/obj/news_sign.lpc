#include <ansi.h>
id(str) {
  return str=="news sign" || str== "sign";
}


long()
 {
  write("\n\
A sign that says:\n\
  Boards are gone. Type 'read news' instead.\n\n");
}

short() {
  return "A news sign ["+HIB+"read me"+NORM+"]";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "sign") return 0;
  long();
  return 1;
}
