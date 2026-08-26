//	/adm/daemon/news_d.c
//	from the Nightmare mudlib
//	a news daemon for logging in
//	created by Descartes of Borg 13 february 1993
//      check added by Pallando, 29 january 1994

#include <lib.h>
#include <news.h>

inherit LIB_DAEMON;

void read_news();
void arch_news();
void end_news();

void read_news() {
    int x;

    x = get_dir(NEWS, -1)[0][2];
    if( x == (int)this_player()->GetNews("general") ) {
	arch_news();
	return;
    }
    this_player()->SetNews("general", x);
    message("news", "\n%^RED%^General news:", this_player());
    message("news", read_file(NEWS), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to((: arch_news :));
}

void arch_news() {
    int x;

    if( !archp(this_player()) || (file_size(ARCH_NEWS) == -1) ||
      (x = get_dir(ARCH_NEWS, -1)[0][2]) == (int)this_player()->GetNews("arch")) {
        end_news();
	return;
    }
    this_player()->SetNews("arch", x);
    message("news", "\n%^RED%^Arch news:", this_player());
    message("news", read_file(ARCH_NEWS), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to((: end_news :));
}

void end_news() {
    this_player()->eventDescribeEnvironment(0);
    if( (string)this_player()->GetClient() )
      message("loggedin", "", this_player());
}
