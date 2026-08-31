// coded by Ace
#include <std.h>
inherit OBJECT;

#define MAX_BET 500
void init() {
    ::init();
    add_action("play", "play");
}
void create() {
    ::create();
    set_id(({"slot machine", "slot", "slotmachine", "machine"}));
    set_name("slot machine");
    set_short("a slot machine");
    set_long( "A slot machine, maybe you should play.  Lucky "          "%^ORANGE%^s%^WHITE%^E%^ORANGE%^v%^WHITE%^E%^ORANGE%^n%^WHITE%^!  "
      "To play just %^CYAN%^play slot <amount of gold>%^RESET%^.  It is so much fun!  The "
      "numbers must total up to 7.");
    set_mass(9000);
    set_prevent_get("You can't take the slot machine!!");
    set_value(2);
}
int play(string str) {
    int x;
    int y;
    int z;
    int a;
    int b;
    int c;
    if (!str || sscanf(str, "slot %d", x) != 1) return 0;
    if(x<= 0) return notify_fail("You can not play with that amount "
	  "of gold.\n");
    if(x > MAX_BET) return notify_fail("You cannot bet that much.\n");
    if(x > this_player()->query_money("gold")) return notify_fail("You do not "
	  "have that much gold.\n");
    this_player()->add_money("gold", -x);
    b=x*5;
    write("You put "+x+" gold in the slot machine.");
    say(this_player()->query_cap_name()+" puts money in the slot machine.");
    write("You pull the lever.\n");
    say(this_player()->query_cap_name()+" pulls the lever.");
    y=(random(4));
    z=(random(4));
    a=(random(4));
    c=(random(4));
    write("%^CYAN%^~(:=-|  "
      "%^RESET%^L%^ORANGE%^u%^WHITE%^c%^ORANGE%^k%^WHITE%^y %^ORANGE%^s%^WHITE%^E%^ORANGE%^v%^WHITE%^E%^ORANGE%^n%^WHITE%^! %^CYAN%^|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    write("%^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7");
    write("%^CYAN%^!%^GREEN%^7       %^MAGENTA%^"+y+"%^RESET%^       %^CYAN%^!%^GREEN%^7       %^BLUE%^"+z+"%^RESET%^       %^CYAN%^!%^GREEN%^7       %^ORANGE%^"+c+"%^RESET%^       %^CYAN%^!%^GREEN%^7       %^RED%^"+a+"%^RESET%^       %^CYAN%^!%^GREEN%^7");
    write("%^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7               %^CYAN%^!%^GREEN%^7");
    write("%^CYAN%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=:)~");
    if(y+z+a+c!=7) return 1;
    if(y+z+a+c=7) write("%^YELLOW%^JACKPOT!!!%^RESET%^");
    write("You %^MAGENTA%^w%^CYAN%^i%^GREEN%^n "
      "%^ORANGE%^"+b+" %^YELLOW%^gold%^RESET%^ coins!!!");
    say("D%^ORANGE%^i%^RESET%^n%^ORANGE%^g%^RESET%^, "                      "D%^ORANGE%^i%^RESET%^n%^ORANGE%^g%^RESET%^, "
      "D%^ORANGE%^i%^RESET%^n%^ORANGE%^g%^RESET%^!%^ORANGE%^!%^RESET%^! "
      "%^ORANGE%^A %^WHITE%^w%^CYAN%^i%^GREEN%^n%^ORANGE%^n%^WHITE%^e%^CYAN%^r %^ORANGE%^!%^WHITE%^!%^CYAN%^!%^RESET%^");
    this_player()->add_money("gold", b);
    return 1;
}

