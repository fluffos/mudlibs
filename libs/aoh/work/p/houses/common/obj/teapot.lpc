inherit "std/thing";
int full;

create(arg){
 ::create(arg);
 SetShort("a teapot");
 SetLong("Usually it is filled with tea!\n");
 SetWeight(620);
 SetValue(20);
 AddId("teapot");
 reset();
}

init() {
:: init();
 add_action("trink","drink");
}

trink(str) {
  if (str!="tea") return 0;
  if (full<1) {write("The pot is empty!\n"); return 1;}
  full-=1;
  write("You drink a cup of the finest darjeeling tea.\n");
  say(this_player()->QueryName() + " drinks a cup of tea.\n");
  call_other(this_player(),"Heal",2);
  return 1;
}

reset() {
  full=15;
}
