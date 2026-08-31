string *colours = ({ "RESET","BOLD","FLASH","BLACK","RED","BLUE","CYAN",
"MAGENTA","ORANGE","YELLOW","GREEN","WHITE","BLACK",
"B_RED","B_ORANGE","B_YELLOW","B_BLACK","B_CYAN",
"B_WHITE","B_GREEN","B_MAGENTA","STATUS","WINDOW",
"INITTERM","ENDTERM" });

string get_last_color(string str) {
  string *woo, ret;
  int i;

ret = "";
  woo = explode(str, "%^");
  i = sizeof(woo);
while (i--)  if (member_array(woo[i],colours)!=-1) ret += woo[i]+" ";

  return ret;
  

}
