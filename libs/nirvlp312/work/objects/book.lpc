int current_page;

void reset(status arg) {
  if (arg) return;
  current_page = 0;
}

string short() { return "A golden bound book"; }

void long(string str) {
  write("This book, bound in soft black leather and fitted with golden \n" +
        "fastens sits proudly atop a stand of white marble.            \n");
  write("It's title is:  'ADVENTURING' \n");
}

void init() {
  add_action("open", "open");
  add_action("close", "close");
  add_action("read_book", "read");
}

status id(string str) {
  return str == "book" ||
         str == "chain";
}

status open(string str) {
  if (!id(str)) return 0;
  if (current_page > 0) {
    write("The book is already open at page " + current_page + ".\n");
    return 1;
  }
  current_page = 1;
  write("You open the book...\n");
  say(this_player()->query_name() + " opens the book.\n");
  return 1;
}

status close(string str) {
  if (!id(str)) return 0;
  if (!current_page) {
    write("It is already closed.\n");
    return 1;
  }
  current_page = 0;
  write("The book closes with a THUD!\n");
  say(this_player()->query_name() + " closed the book.\n");
  return 1;
}

status read_book(string str) {
  if (!id(str) && str != "page") return 0;
  if (!current_page) {
    write("It is closed.\n");
    return 1;
  }
  if (current_page == 1)
    cat("/objects/book_page1");
  return 1;
}

status get(string str) {
  if (id(str)) {
    write("The book is attached to the marble stand that it sits on.\n");
    return 0;
  }
  return 0;
}

