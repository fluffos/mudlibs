//  remind me
inherit "/std/object";
int i;
void create() {
    ::create();
    set_name("reminder");
    set_long("This is a reminder.  This will tell you every five minutes "
      "how long untill reboot.");
    set_short("a reminder");
    set_id(({"reminder"}));
    call_out("remind", 300);
    i=2700;
}
void remind() {
    i=i-300;
    message("", "Reboot occurs in "+i+" seconds.  "+(i/60)+" minutes.",
      environment(this_object()));
    call_out("remind", 300);
}
