#include <std.h>
#include <ether.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("<3");
    set_id(({ "heart","<3" }));
    set_short("%^RED%^<3%^RESET%^");
    set_long(
      "%^RESET%^This heart symbolizes the love of %^RED%^Evolution%^RESET%^ & %^RED%^Kumi%^RESET%^."
    );
    set_ac(0);
    set_limbs( ({ "left hand", "right hand" }) );
    set_weight(5);
    set_type("ring");
}


void welcome()
{
    call_out("wear", 3, "heart");
}
int query_auto_load() {
    if(this_player()->query_name() == "kumi" || this_player()->query_name() == "evolution") return 1;
    return 0;

}
void init_arg(mixed *arg) {
    welcome();
}
string extra_look() {
    return (checkowner()+" is in love.\n");
}





