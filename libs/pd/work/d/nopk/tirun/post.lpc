#include <std.h>
#include <tirun.h>
#include <post.h>
#include <objects.h>
inherit ROOM;
void init() {
//    object ob;
    ::init();
    add_action("mail", "mail");
}
void create() {
    ::create();
    set_short("Tirun Post Office");
    set_long(
      "%^GREEN%^The Tirun Post Office%^RESET%^\n"
      "The post office is always open, day or night, "
      "mostly because it is run by the Tirunian government.  People "
      "come here to read and send mail.  Type <mail> to access your "
      "individual mailbox, or <mail name> to send mail to a player.");
    set_property("light", 1);
    set_property("indoors", 1);
    set_items(
      (["list" :  "A list of commands you may use at the post office."]) );
    set_exits( (["out" : ROOMS"square6"]) );
    set_pre_exit_functions( ({ "north" }), ({ "more" }));
    set_property("no attack", 1);
    set_property("no steal", 1);
}
int mail(string str) {
    object ob;
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
