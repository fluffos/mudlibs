//    /adm/daemon/news_d.c
//      from the Nightmare mudlib
//      a news daemon for logging in
//      created by Descartes of Borg 13 february 1993
//      check added by Pallando, 29 january 1994

#include <news.h>
#include <daemons.h>

void read_news();
void class_news();
void race_news();
void high_mortal_news();
void guild_news();
void immortal_news();
void arch_news();
void end_news();
string path, path2;

void create() { seteuid(getuid()); }

void read_news() {
    if (!this_player()) return;
    if (in_input(this_player())) return;
    tell_object(this_player(), "\nGeneral news:\n");
    message("info", read_file(NEWS), this_player());
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
    message("info", read_file(NEWS_DIR+cl), this_player());
    tell_object(this_player(), "Press <return> to continue: ");
    input_to("high_mortal_news");
}

void race_news() {
    string r;

    r = (string)this_player()->query_race();
    if(!r) r = "unborn";
    if(file_size(NEWS_DIR+r) == (int)this_player()->query_news("race")) {
	high_mortal_news();
	return;
    }
    this_player()->set_news("race", file_size(NEWS_DIR+r));
    if(r == "unborn") tell_object(this_player(), "New player news:\n");
    else tell_object(this_player(), "\n"+capitalize(r)+" news:\n");
    message("info", read_file(NEWS_DIR+r), this_player());
    tell_object(this_player(), "Press <return> to continue: ");
    input_to("high_mortal_news");
}


void high_mortal_news() {
    if(!high_mortalp(this_player()) ||
      file_size(HIGH_MORTAL_NEWS) == (int)this_player()->query_news("high mortal")) {
	guild_news();
	return;
    }
    this_player()->set_news("high mortal", file_size(HIGH_MORTAL_NEWS));
    tell_object(this_player(), "\nHigh mortal news:\n");
    message("info", read_file(HIGH_MORTAL_NEWS), this_player());
    input_to("guild_news");
}

void guild_news() {
    path = "/d/guilds/data/news/"+this_player()->query_guild();
    path2 = "/d/guilds/data/progress/"+this_player()->query_original_guild();
    if(this_player()->query_guild() &&
      file_size(path2) != (int)this_player()->query_news("guild_progress")) {
	tell_object(this_player(), "\nThere have been changes to your guild roster.\n");
	this_player()->set_news("guild_progress", file_size(path2));
    }
    if(!this_player()->query_guild() || file_size(path) == -1 ||
      file_size(path) == (int)this_player()->query_news("guild")) {
	immortal_news();
	return;
    }
    this_player()->set_news("guild", file_size(path));
    tell_object(this_player(), "\nGuild news:\n");
    message("info", read_file(path), this_player());
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
    message("info", read_file(IMMORTAL_NEWS), this_player());
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
    tell_object(this_player(), "\\Arch news:\n");
    message("info", read_file(ARCH_NEWS), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("end_news");
}

void end_news() {
   if(!BANISH_D->query_banished_ip(query_ip_number(this_player()))) { this_object()->finish_news(); return; }
   write("
\n\n%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]%^BLUE%^---------------------------%^BOLD%^( %^RED%^Warning %^BLUE%^}---------------------------%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]%^RESET%^
 You are connecting from a banished ip.  This doesnt mean you have 
 done something wrong, just that someone from the same range of ips 
   have.  If you are seeing this message you cannot create new 
  characters without express permission from the administrators 
  of Primal Darkness. If you have any questions, please contact
                        us through webmail.  

 You must also keep a valid email address in your system information.
%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]%^BLUE%^-----------------------------------------------------------------%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]
");
   input_to("finish_news");
}

void finish_news() { this_player()->describe_current_room(1); }

