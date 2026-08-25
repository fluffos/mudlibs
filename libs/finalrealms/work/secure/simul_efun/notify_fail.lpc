void notify_fail(mixed str) {
  if(!this_player())
    return;

  if (intp(str))
    str = "" + str;

  this_player()->set_notified(1);
  efun::notify_fail(sprintf("%-=*s", this_player()->query_cols(), str));

} /* notify_fail() */
