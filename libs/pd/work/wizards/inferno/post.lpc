#include <std.h>
#include <post.h>
#include <objects.h>

inherit ROOM;

void init() {
    object ob;

    ::init();
/*
    if(!living(this_player()) || !interactive(this_player())) 
      this_player()->move_player(ROOMS"spordel1", "west");
*/
    add_action("mail", "mail");
}

void create() {
  ::create();
    set("short", "Inferno's Post Office");
    set("long",
        "Welcome to Inferno's post office! Type <mail> to access "
        "your mailbox, or <mail name> to send mail to player name. "
        "The Sindarii post office runs on the intermud system, meaning "
        "that you can send mails to players on any other mud on the system. "
        "Type <mudlist> to find out who is on the system.  The groups available "
        "can be accessed by typing <g> at the & prompt.");
    set_property("light", 2);
    set_property("indoors", 1);
    set_items(
        (["list" :  "A list of commands you may use at the post office."]) );
    set_exits( (["south" : "/wizards/inferno/bank"]) );
    set_pre_exit_functions( ({ "south" }), ({ "more" }));
    set_property("no attack", 1);
    set_property("no steal", 1);
}

int mail(string str) {
    object ob;
/*
    if((string)this_player()->query_name() == "guest") {
        notify_fail("Guest may not use the mailer.\n");
        return 0;
    }
*/
    ob = new(OB_POSTAL);
    ob->move(this_player());
    ob->start_mail(str);
    return 1;
}

int more(string str) {
    object ob;

    if(!(ob = present(POSTAL_ID, this_player()))) return 1;
    ob->remove();
    return 1;
}
