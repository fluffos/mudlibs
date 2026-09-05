inherit "/obj/treasure";

void reset(int x){
  if(x) return;
  set_id("sign");
  set_short("A sign");
  set_long("\
The sign reads...\n\n\
\tHello!\n\
\tHead west for a special place.\n\n");
}

int get() { return 0; } /* ungettable */

void init(){
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str){
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(!id(str) && str != "the sign"){
    notify_fail("You may only read the sign.\n");
    return 0;
  }
  long();
  return 1;
}