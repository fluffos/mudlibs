inherit "/std/Object";

void init() {
  ::init();
  add_action("nice_try", "quit");
  return;
}

int nice_try(string null) {
  message("info", "%^RED%^%^BOLD%^You may not quit while on a holy mission.",
	  this_player());
  return 1;
}

