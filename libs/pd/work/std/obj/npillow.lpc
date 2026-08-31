#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("nightmare");
   set_short("a pillow of thorns and nails");
   set_long("The pillow is covered in thorns and nails.");
   set_weight(0);
   set_value(0);
}

int action(string str) {
   write("The horrible nightmare holds you down!");
   return 1;
}

void knight(object ob) {
   message("info", "%^CYAN%^Your body dissolves into nothingness!", ob);
   message("info", "%^BOLD%^%^RED%^You die.", ob);
   message("info", "The nightmage ends.. You awaken in a cold sweat.", ob);
   say(ob->query_cap_name()+" awakens in a cold sweat, screaming!", ob);
   this_object()->remove();
}

void jnight(object ob) {
   message("info", "%^BOLD%^%^BLACK%^In your mind you see the shadow point at you and beckon.", ob);
   message("info", "%^YELLOW%^As you walk foward, thorns rip forth from your skin!", ob);
   ob->damage(10);
   call_out("knight", 4, ob);
}

void fnight(object ob) {
   message("info", "You bones begin to break and snap like twigs.", ob);
   message("info", "Your skin melts over your eyes, preventing all sight.", ob);
   ob->damage(10);
   call_out("jnight", 4, ob);
}

void dnight(object ob) {
   message("info", "%^BOLD%^%^WHITE%^The air becomes hard to breathe..", ob);
   ob->damage(15);
   message("info", "%^ORANGE%^Flames wrap around your body.", ob);
   message("info", "You scream as your skin melts!", ob);
   ob->damage(20);
   call_out("fnight", 4, ob);
}

void snight(object ob) {
   message("info", "%^RED%^Your skin begins to split and bleed.", ob);
   ob->damage(14);
   call_out("dnight", 4, ob);
}

void anight(object ob) {
   message("info", "From the shadow, a cloaked figure steps forth..", ob);
   message("info", "Beneath a shadowy hood, you see two gleaming red eyes.", ob);
   call_out("snight", 4, ob);
}

void night(object ob) {
   message("info", "%^BOLD%^%^CYAN%^A chill runs down your spine.", ob);
   ob->damage(20);
   call_out("anight", 4, ob);
}

void start_nightmare() {
   object tp;
   tp = environment(this_object());
   message("info", "%^BOLD%^%^BLACK%^In your dream, a shadow comes to you.", tp);
   call_out("night", 4, tp);
}

void init() {
 ::init();
   if(!archp(this_player()))
   add_action("action", "");
   write("You fall fast asleep");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " falls fast asleep.", ({ this_player() }));
   if (present("pillow", this_player()))
     present("pillow", this_player())->remove();
   call_out("start_nightmare", 3, this_player());
}
