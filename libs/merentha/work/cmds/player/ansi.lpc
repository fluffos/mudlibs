// Petrarch
// Merentha Lib 1.0
// <ansi>

string help() {
return "Syntax: ansi\n\nThis command will toggle your colours on and off.";
}

int command() {
string term=this_player()->getenv("terminal");
  if(term!="ansi") {
    this_player()->setenv("terminal", "ansi");
    message("command","%^RED%^A%^GREEN%^N%^BLUE%^S%^CYAN%^I%^MAGENTA%^%^BOLD%^ O%^ORANGE%^N",this_player());
   return 1;
}
    this_player()->setenv("terminal", "unknown");
message("command", "ANSI OFF", this_player());
return 1;
}

