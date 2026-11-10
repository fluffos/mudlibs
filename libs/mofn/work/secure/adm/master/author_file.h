string author_file(string file) {
  int i;

  if(!file || file == "")
    return "NONAME";

  // given /w/... then /w/l/luggage, for example
  // or /u/l/luggage.o and /u/l/luggage :)
  if(sizeof(file) > sizeof(WIZ_DIR)+3 &&
       file[0..sizeof(WIZ_DIR)] == WIZ_DIR "/") {
    i = strsrch(file[sizeof(WIZ_DIR)+3..], '/');
    if(i < 0)
      return "NONAME";
    return file[sizeof(WIZ_DIR)+3..i+4];
  }

  // probably want to do some magic for projects

  return "NONAME";
}
