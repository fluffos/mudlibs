main() {
  if (this_player()->query_autohp()) {
    this_player()->set_autohp(0);
    msg("Autohp turned off. You will no longer see your hp every time you take damage.");
  } else {
    this_player()->set_autohp(1);
    msg("Autohp turned on. You will now see your hp whenever you are injured.");
  }
  return 1;
}
