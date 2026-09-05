/*
This is an example of a treasure object, with a long description
that can change on the fly.  You can also use this same method
on different kinds of objects.
It also has an example of a simple read function, but in most
cases you'd just do set_read in the reset function.
					-Feldegast
*/

inherit "/obj/treasure";

reset(arg) {
  set_id("watch");
  set_alias("pocket watch");
  set_short("A pocket watch");
  set_weight(1);
  set_value(800);
}

long() {
  write("This is a gentleman's gold pocket watch with a fine chain\n"+
        "to hang it in his coat and an inscription on its back.\n"+
        "The time reads: "+ctime(time())+"\n");
}

init() {
  add_action("cmd_read","read");
}

cmd_read(str) {
  if(str=="watch" || str=="inscription") {
    write("The inscription reads:\n"+
          "\t\tFor my darling Steven Gerard,\n"+
          "\t\t\t\tLove,\n"+
          "\t\t\t\tMary\n");
    return 1;
  }
  notify_fail("Read what?\n");
}
