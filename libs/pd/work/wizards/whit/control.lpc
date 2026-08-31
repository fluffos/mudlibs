#include <std.h>
#include <daemons.h>
#ifndef QUEST_D
#define QUEST_D "/d/events/daemon"
#endif
#define WEATHER "/d/events/weather"
inherit OBJECT;
void create() {
    ::create();
    set_name("control");
    set_long("This ring belongs to Whit.");
    set_short("a ring");
    set_id(({ "control","ring" }));
}
void init() {
    ::init();
    add_action("start", "start");
}
void start() {
    //   if(QUEST_D->query_start("Citrin")) return notify_fail("Event "
    //     "has already started.");
    //   QUEST_D->start_quest("Citrin", 1);
    write("Starting.\n");
    call_out("a", 2);
}
void force(string action) {
    environment(this_object())->force_me(action);
}
void a() {
    force("say I would like to welcome you all to the second "
      "event of Primal Darkness.  For a little more then a "
      "year, Primal Darkness has grown and strived into what "
      "it is now.  With well over 10 players on at almost "
      "all times, we have become very popular.  Several rule "
      "changes have also taken place, such as the "
      "Multiplaying rules, and the PK rules.");
    call_out("b", 4);
}
void b() {
    force("echoall The sky starts to cloud up.");
    call_out("c", 4);
}
void c() {
    force("echoall Thunder sounds through the air.  It starts to "
      "rain.");
    call_out("d", 7);
}
void d() {
    force("say Depite all of these changes in the rules, and "
      "the retirements of our staff, many players still come "
      "here and enjoy what we have to offer.  ");
    call_out("e", 3);
}
void e() {
    force("echoall The rain starts coming down really hard now.");
    call_out("f", 4);
}
void f() {
    force("say But, that is not why we are gathered here today.  "
      "Something has happened.  In the world all things must "
      "maintain a certain balance.  My being here desecrates "
      "that balance.  Before I am allowed to return, this "
      "balance must be restored.  ");
    call_out("g", 2);
}
void g() {
    force("echo %^BOLD%^%^BLACK%^The shadows start to move "
      "around.  The shadows start to envelope Whit, dragging "
      "him into The Realm of Light.");
    //   WEATHER->start();
}
