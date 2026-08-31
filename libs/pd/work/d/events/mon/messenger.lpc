//  Whit

#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("messenger");
    set_short("a messenger");
    set_long("The messenger is dressed in a dark cloak.  Only his "
      "green eyes can be seen from under it.  He holds a staff in "
      "his hand.\n");
    set_id(({ "messenger", "a messenger" }));
}

void init() {
    ::init();
    if(wizardp(this_player())) add_action("fstart", "start");
}

int fstart() {
    write("Starting event.\n");
    call_out("a", 2);
    return 1;
}

void a() {
    this_object()->force_me("say Listen everyone,  what i have to say is of "
      "great importance.");
    call_out("b", 4);
}

void b() {
    this_object()->force_me("say Time is of the very essence now.  The "
      "world that you know of it now will no longer exist unless "
      "something is done.  Not even the demons are safe.");
    call_out("c", 12);
}

void c() {
    this_object()->force_me("say Centuries ago an anti-paladin, known "
      "only as Desmos, went crazy and took over most of the "
      "continent with his army of skeletons and corpses.");
    call_out("d", 14);
}

void d() {
    this_object()->force_me("say The battle went on for some time.  "
      "Finally Desmos's army subsided and left.  A few months later "
      "by chance Desmos himself was captured.  Since he contained "
      "much dark power we could only contain him inside of a cursed "
      "object.  The object now has become known as \"The book of Shadows\"");
    call_out("e", 20);
}

void e() {
    this_object()->force_me("say It was thought that the book would be "
      "well protected in the city of Lodos.  It was well hidden inside "
      "the temple.  After awhile even the priests forgot where it was.");
    call_out("f", 10);
}

void f() {
    this_object()->force_me("say However,  not so long ago a small adventurer "
      "uncovered the book.  He vanished without a trace.");
    call_out("g", 6);
}

void g() {
    this_object()->force_me("say It is my fear that the adventurer might "
      "find a way to open the book and unleash Desmos.  If that happens "
      "he will again try to take over the world.");
    call_out("h", 20);
}

void h() {
    this_object()->force_me("say Please,  i beg of all of you,  find the "
      "adventurer before the darkness finds him!");
    call_out("i", 5);
}

void i() {
    this_object()->force_me("say I must leave now,  but i will be "
      "watching from the skies.");
    message("", "The messenger starts to levitate "
      "and shoots off into the sky.", environment(this_object()));
    this_object()->move("/wizards/whit/workroom");
    this_object()->force_me("say I am finished telling my story Whit.");
}

void start_corpse() {
    message("a", "The messenger falls from the skies and lands next to you.",
      environment(this_object()));
    call_out("2a", 5);
}

void a2() {
    this_object()->force_me("say Just as i feared.  Some of Desmos's "
      "followers must have reached the adventurer before you did.");
    call_out("2b", 6);
}

void b2() {
    this_object()->force_me("say You must hunt down the person that holds "
      "the book.  Most likely,  they would have taken it to the hidden "
      "rooms that lie deep underneath the Citrin Forest.  There is only "
      "one known entrance and that is through a portal.");
    call_out("2c", 10);
}

void c2() {
    this_object()->force_me("say In order to open the portal the four "
      "orbs of power must be gathered and brought into the same room "
      "as each other and the portal will open.");
    call_out("2d", 15);
}

void d2() {
    this_object()->force_me("say I will meet back with you when you discover "
      "the entrance to the Tunnels Beneath Citrin.");
    message("", "The messenger rockets back up into the sky.", 
      environment(this_object()));
    this_object()->move("/wizards/whit/workroom");
    this_object()->force_me("say I am done with the corpse part.");
}

