// Petrarch
// Merentha Lib 1.0
// <money>

string help() {
  return "Syntax: money\n\nDisplays how much money you are carrying.";
}

int command() {
mapping money=this_player()->query_money();
string *types=keys(money), ret="";
int i=sizeof(types),m,j;
  
j=this_player()->getenv("SCREEN");
if(!j) j=75;
j-=4;
if(!i) ret="You have no money.";
else {
  while(i--) {
    if (m=this_player()->query_money(types[i])) 
      types[i]="%^ORANGE%^"+m+" %^GREEN%^"+types[i];
    else types-=({types[i]});
  }
  ret=format_page(types,3,j);
}
message("command", border(ret, "money", j+4), this_player());
return 1;
}
