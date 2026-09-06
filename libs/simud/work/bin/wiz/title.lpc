main(string title) {
  if (title) {
    if (title == "0" || title == "clear" || title == "none") {
      this_player()->set_title("");
      write("Title cleared\n");
    } else {
      this_player()->set_title(title);
      write("Title set to "+title+"\n");
    }
  } else
    write("Your title is currently "+this_player()->query_title()+"\n");
  return 1;
}
