main(string arg) {
  mixed *history, tell;

  history = this_player()->query_tell_history();

  if ( sizeof(history) == 0 ) {
    msg("Your tell history is empty at the moment.");
    return 1;
  }

  msg("~CTITTell History~CDEF\n------------");

  foreach (tell : history) {
    if (tell[0][0..2] == "to ")
      msg("(~CCOM"+tell[1]+"~CDEF) ~CDRK"+tell[0]+"~CDEF: "+tell[2],
          strlen(tell[0])+13);
    else

      msg("(~CCOM"+tell[1]+"~CDEF) ~CACT"+tell[0]+"~CDEF: "+tell[2],
          strlen(tell[0])+13);
  }
  return 1;
}
