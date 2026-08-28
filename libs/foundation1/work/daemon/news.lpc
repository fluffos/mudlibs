/*    /daemon/news.c
 *    from Nightmare 3.3
 *    for IdeaExchange
 *    created by Descartes of Borg 941001
 */

#include <std.h>
#include <news.h>

inherit DAEMON;

void end_news();

void read_news() {
    if(file_size(NEWS) == (int)this_player()->query_news("general")) {
        end_news();
	return;
    }
    this_player()->set_news("general", file_size(NEWS));
    message("news", "\n%^RED%^General news:", this_player());
    message("news", read_file(NEWS), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("end_news");
}

void end_news() {
    this_player()->describe_current_room(1);
    message("loggedin", "", this_player());
}
