//	/adm/daemon/news_d.c
//	from the Nightmare mudlib
//	a news daemon for logging in
//	created by Descartes of Borg 13 february 1993
//      check added by Pallando, 29 january 1994

#include <news.h>

void read_news();
void class_news();
void high_mortal_news();
void immortal_news();
void arch_news();
void end_news();

void create() { seteuid(getuid()); }

void read_news() {
    if(file_size(NEWS) == (int)this_player()->query_news("general")) {
	class_news();
	return;
    }
    this_player()->set_news("general", file_size(NEWS));
    tell_object(this_player(), "\nGeneral news:\n");
    this_player()->more(NEWS);
    tell_object(this_player(), "Press <return> to continue: ");
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
    if(cl == "child") tell_object(this_player(), "New player news:\n");
    else tell_object(this_player(), "\n"+capitalize(cl)+" news:\n");
    this_player()->more(NEWS_DIR + cl);
    tell_object(this_player(), "Press <return> to continue: ");
    input_to("high_mortal_news");
}

void high_mortal_news() {
    if(!high_mortalp(this_player()) ||
      file_size(HIGH_MORTAL_NEWS) == (int)this_player()->query_news("high mortal")) {
	immortal_news();
	return;
    }
    this_player()->set_news("high mortal", file_size(HIGH_MORTAL_NEWS));
    tell_object(this_player(), "\nHigh mortal news:\n");
    this_player()->more(HIGH_MORTAL_NEWS);
    input_to("immortal_news");
}

void immortal_news() {
    if(!wizardp(this_player()) ||
      file_size(IMMORTAL_NEWS) == (int)this_player()->query_news("immortal")) {
	    arch_news();
	    return;
    }
    this_player()->set_news("immortal", file_size(IMMORTAL_NEWS));
    tell_object(this_player(), "\nImmortal news:\n");
    this_player()->more(IMMORTAL_NEWS);
    tell_object(this_player(), "Press <return> to continue: ");
    input_to("arch_news");
}

void arch_news() {
    if(!archp(this_player()) || (file_size(ARCH_NEWS) == -1) ||
      file_size(ARCH_NEWS) == (int)this_player()->query_news("arch")) {
        end_news();
	return;
    }
    this_player()->set_news("arch", file_size(ARCH_NEWS));
    tell_object(this_player(), "\nArch news:\n");
    this_player()->more(ARCH_NEWS);
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("end_news");
}

void end_news() { this_player()->describe_current_room(1); }
