inherit "inherit/treasure";

object listen_ob, player_ob;

void reset(status arg) {
  if (arg) return;
  set_name("stethoscope");
  set_short("Stethoscope");
  set_long("The stethoscope has two tubes that plug into your ears.\n" +
           "Maybe you can apply it to something.\n");
  set_weight(1);
  set_value(15);
}

void init() {
  add_action("apply", "apply");
  add_action("apply", "use");
}

status apply(string str) {
  string what;
  object ob;

  if (environment() != this_player()) {
    notify_fail("You have to get it first!\n");
    return 0;
  }
  if (!str) {
    notify_fail("Usage: apply stethoscope to <item>\n");
    return 0;
  }
  if (sscanf(str, "stethoscope to %s", what) != 1) {
    notify_fail("Apply stethoscope to what?\n");
    return 0;
  }
  if (!(ob = present(what, this_player()))) {
    if (!(ob = present(what, environment(this_player())))) {
      write("There is no " + what + " here.\n");
      return 1;
    }
  }
  if (living(ob) || ob->use_stethoscope(this_object())) {
    write("You listen to the " + what + ".\n");
    listen_ob = ob;
    player_ob = this_player();
    set_heart_beat(1);
    return 1;
  }
  notify_fail("You can't do that!\n");
  return 0;
}

/* Detect if the player leaves the object */

void heart_beat() {
  if (!(player_ob || listen_ob)) {
    set_heart_beat(0);
    return;
  }
  if (!present(listen_ob, environment(player_ob)) ||
      environment() != player_ob) {
    listen_ob = 0;
    return;
  }
  if (living(listen_ob))
    tell_object(player_ob, "Dunk dunk\n");
}

object query_listening() { return listen_ob; }

