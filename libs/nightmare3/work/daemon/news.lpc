//	/adm/daemon/news_d.c
//	from the Nightmare mudlib
//	a news daemon for logging in
//	created by Descartes of Borg 13 february 1993
//      check added by Pallando, 29 january 1994

#include <std.h>
#include <news.h>

inherit DAEMON;

void read_news();
void class_news();
void high_mortal_news();
void immortal_news();
void arch_news();
void end_news();

void read_news() {
    if(file_size(NEWS) == (int)this_player()->query_news("general")) {
	class_news();
	return;
    }
    this_player()->set_news("general", file_size(NEWS));
    message("news", "\n%^RED%^General news:", this_player());
    message("news", (read_file(NEWS)||""), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("class_news");
}

void class_news() {
    string cl;

    cl = (string)this_player()->query_class();
    if(!cl) cl = "child";
    if(file_size(NEWS_DIR+cl) == (int)this_player()->query_news("class")) {
	high_mortal_news();
	return;
    }
    this_player()->set_news("class", file_size(NEWS_DIR+cl));
    if(cl == "child")
      message("news", "\n%^RED%^New player news:", this_player());
    else message("news", "\n%^RED%^"+capitalize(cl)+" news:", this_player());
    message("news", read_file(NEWS_DIR+cl), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("high_mortal_news");
}

void high_mortal_news() {
    if(!high_mortalp(this_player()) ||
      file_size(HIGH_MORTAL_NEWS) == (int)this_player()->query_news("high mortal")) {
	immortal_news();
	return;
    }
    this_player()->set_news("high mortal", file_size(HIGH_MORTAL_NEWS));
    message("news", "\n%^RED%^High mortal news:", this_player());
    message("news", read_file(HIGH_MORTAL_NEWS), this_player());
    input_to("immortal_news");
}

void immortal_news() {
    if(!creatorp(this_player()) ||
      file_size(IMMORTAL_NEWS) == (int)this_player()->query_news("immortal")) {
	    arch_news();
	    return;
    }
    this_player()->set_news("immortal", file_size(IMMORTAL_NEWS));
    message("news", "\n%^RED%^Immortal news:", this_player());
    message("news", read_file(IMMORTAL_NEWS), this_player());
    message("prompt", "\nPress <return> to continue: ", this_player());
    input_to("arch_news");
}

void arch_news() {
    if(!archp(this_player()) || (file_size(ARCH_NEWS) == -1) ||
      file_size(ARCH_NEWS) == (int)this_player()->query_news("arch")) {
        end_news();
	return;
    }
    this_player()->set_news("arch", file_size(ARCH_NEWS));
    message("news", "\n%^RED%^Arch news:", this_player());
    message("news", read_file(ARCH_NEWS), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("end_news");
}

void end_news() {
    this_player()->describe_current_room(1);
    message("loggedin", "", this_player());
}
