#include <std.h>
#include <tirun.h>
#define MASTER ROOMS"times/master"
inherit ROOM;

mapping tmp;

int new_article();
int remove_article();
int show_articles();

void create() {
 ::create();
    set_short("Tirun Times News Room");
    set_long("Welcome to the Tirun Times News Room.  Many desks sit sprawled across the room belonging to the many "
	"reporters that work here.  All of the desks have papers thrown about on top of them.  Here, reporters "
	"may use the <ttns> to submit articles.  They may also <claim presspass> to get a presspass.");
    set_exits( 
              (["north" : ROOMS"times/editor",
                "south" : ROOMS"times/entrance",
		"east"  : ROOMS"times/pressroom",
]) );

    set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
	"indoors"     : 1,
        "no steal"    : 1 ]) );
    set_items(
        ([
	"carpet":"Its nice and new.  Very bouncy!",
	"desk":"The desk is a made from oak.  Its varnished in an antique red giving it a sense of class.  It is neat and "
		"clean.",
	"portaits":"The portaits are of scholars.",
]) );
    tmp = ([]);
}

void init() {
	::init();
	add_action("claim", "claim");
	add_action("ttns", "ttns");
}

int claim() {
	object o;
	if(!MASTER->is_member(this_player()->query_name())) return notify_fail("Only members of the press may get a pass.\n");
	if(present("presspass", this_player())) return notify_fail("You already have a presspass.");
	write("You grab a presspass from the shelf.");
	o=new(ROOMS"times/presspass");
	o->set_owner(this_player()->query_name());
	o->move(this_player());
	say(this_player()->query_cap_name()+" gets a presspass.");
	return 1;
}

int ttns() {
        if(!MASTER->is_member(this_player()->query_name())) return notify_fail("Only members of the press may use this feature.\n");
	write("Main Menu");
	write("
          1) Submit an Article
          2) Remove an Article
          3) View a list of your current articles
          4) Quit

>");
	input_to("menu");
	return 1;
}

int menu(string s) {
	if(!s) s == "asldkasdlk";
	switch(s) {
		case "1":
			new_article();
			break;
		case "2":
			remove_article();
			break;
		case "3":
			show_articles();
			break;
		case "4":
		case "q":
			write("Qutting out.");
			return 1;
			break;
		default:
			write("Unknown command.  Please try again> ");
			input_to("menu");
			break;
	}
	return 1;
}

int remove_article() {
	mapping art;
	string *k;
	write("Type the name of the article you wish to %^RED%^%^BOLD%^remove%^RESET%^.  This action cannot be "
		"undone.  Please (*) to return to main menu.");
	k=MASTER->get_user_articles(this_player()->query_name());
	write(format_page(k, 3));
	input_to("remove_article_2");
	return 1;
}

int remove_article_2(string s) {
	int i;
	i=MASTER->remove_article(this_player()->query_name(), s);
	if(!i) write("The article could not be found and was not removed."); else
	write("Article removed.");
	ttns();
	return 1;
}

int show_articles() {
	string *k;
	write("The following is your articles: ");
	k=MASTER->get_user_articles(this_player()->query_name());
	write(format_page(k, 3));
	write("Enter the title of the article you would like to view?  Or press * to return to the menu.");
	input_to("view_article");
	return 1;
}

int view_article(string s) {
	mapping art;
	if(s == "q") return ttns();
	if(s == "*") return ttns();
	art = MASTER->get_article(this_player()->query_name(), s);
	if(!art) {
		write("Article not found.  Remember to use the same formatting and this is case sensitive.");
		input_to("view_article");
		return 1;
	}
	write("Title: "+art["title"]);
	write("Time: "+ctime(art["time"]));
	write("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
	write(art["contents"]+"");
	write("\nPress any key to return to the article viewer.");
	input_to("show_articles");
	return 1;
}

int new_article(string s) {
	write("Please enter a title for this article.  Titles cannot be more than 40 characters long. >");
	input_to("new_article_2");
	return 1;
}

int new_article_2(string s) {
	if(strlen(s) > 40 || strlen(s) < 2) {
		write("Your title is too long.  Please try again. >");
		input_to("new_article");
		return 1;
	}
	tmp[this_player()] = ([]);
	tmp[this_player()]["title"] = s;
	this_player()->edit("/tmp/"+this_player()->query_name()+".art", "confirm_finish_article", this_object());
	return 1;
}

int confirm_finish_article() {
	write("
		Are you sure you wish to submit this article?
				Yes [y] No [n]
	");
	input_to("finish_article");
}

int finish_article(string s) {
	if(!s || (s != "y" && s != "yes")) {
		write("Submission canceled.");
		ttns();
		return 1;
	}
	MASTER->add_article(this_player()->query_name(), tmp[this_player()]["title"], read_file("tmp/"+this_player()->query_name()+".art"));
	rm("tmp/"+this_player()->query_name()+".art");
	write("Article added for submission.");
	ttns();
	return 1;
}

int abort() {
	write("Your submission was aborted.  Returning to main menu.");
	ttns();
	return 1;
}
