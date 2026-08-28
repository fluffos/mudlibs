reset() {
  /* give the dirs, descs and other things as descibed in newroom.c */
  if(!present("bear")) {
    move_object(clone_object("/wizards/celtron/monster"), this_object());
  }
  if(!present("bear")) {
    move_object(clone_object("/wizards/celtron/monster"), this_object());
  }
  if(!present("bear")) {
    move_object(clone_object("/wizards/celtron/monster"), this_object());
  }
}

init() {
  ::init();
  add_action("push", "push");
}

push(str) {
  if(str != "wall") return;
  write("You push the wall and it breaks.\n");
  say("The eastern wall collapses.\n");
  /* remove the east exit */
  remove_exit("east");
  return 1;
}
