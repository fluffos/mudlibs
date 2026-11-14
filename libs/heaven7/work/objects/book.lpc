int current_page;

reset() {
  current_page = 0;
}

short() { return "A golden bound book"; }

long(str) {
  write("This book, bound in soft black leather and fitted with golden \n"+
        "fastens sits proudly atop a stand or white marble.            \n");
  write("It's title is:  'ADVENTURING' \n");
}

init() {
    add_action("open", "open");
    add_action("close", "close");
    add_action("read_book", "read");
}

id(str) { return str == "book" || str == "chain"; }

open(str) {
    if (!id(str))
	return 0;
    if (current_page > 0) {
	write("The book is already open at page " + current_page + ".\n");
	return 1;
    }
    current_page = 1;
    write("You open the book...\n");
    say(call_other(this_player(), "query_name", 0) +
	" opens the book.\n");
    return 1;
}

close(str)
{
    if (!id(str))
	return 0;
    if (current_page == 0) {
	write("It is already closed.\n");
	return 1;
    }
    current_page = 0;
    write("The book closes with a THUD!\n");
    say(call_other(this_player(), "query_name", 0) +
	" closed the book.\n");
    return 1;
}

read_book(string str) {
    if (!id(str) && str != "page")
	return 0;
    if (current_page == 0) {
	write("It is closed.\n");
	return 1;
    }
    if (current_page == 1)
	cat("/objects/book_page1");
    return 1;
}

get(str) {
    if (str == "book") {
	write("The book is attached to the marble stand that it sits on.\n");
	return 0;
    }
    return 0;
}
