main(string title) {
  if (title) {
    if (title == "0" || title == "clear" || title == "none") {
      this_player()->set_pretitle("");
      write("Pretitle cleared\n");
      return 1;
    }
    if (strlen(title) <= 10) {
      this_player()->set_pretitle(title);
      write("Pretitle set to "+title+"\n");
    } else
      write("Pretitle must be 10 characters or less.\n");
  } else
    write("Your pretitle is currently "+this_player()->query_pretitle()+"\n");
  return 1;
}
