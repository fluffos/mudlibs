// pretty much stolen wholesale from /bin/tellhist.c
// frobnitz 07 apr 2003
int main(string arg) {
  mixed *history, say;

  history = this_player()->query_say_history();

  if ( sizeof(history) == 0 ) {
    msg("Your say history is empty at the moment.");
    return 1;
  }

  msg("~CTITSay History~CDEF\n------------");

  foreach (say : history) {
    if (say[0][0..2] == "to ")
      msg("(~CCOM"+say[1]+"~CDEF) ~CDRK"+say[0]+"~CDEF: "+say[2],
          strlen(say[0])+13);
    else

      msg("(~CCOM"+say[1]+"~CDEF) ~CACT"+say[0]+"~CDEF: "+say[2],
          strlen(say[0])+13);
  }
  return 1;
}
