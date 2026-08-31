#include <std.h>

inherit OBJECT;
void init() {
    ::init();
    add_action("look_picture", "look");
}
void create() {
    set_name("Picture");
    set("id", ({ "picture" }) );
    set_short("A Picture");
    set("long", "This is a visage of what most of the people who step into this office get to see.");
    set_prevent_get("");
}
int look_picture(string str) {
    if(!str) {
        notify_fail("look at what?\n");
        return 0;

    }
    if(str != "picture") {
        notify_fail("You can't look at that!\n");
        return 0;
    }
    

    write(@ENDTEXT
%^BOLD%^%^WHITE%^88888888888888888888888888888888888888888888888888888888888888888888888%^RESET%^\n"
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..%^BOLD%^%^WHITE%^88%^RESET%^\n"
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  %^BOLD%^%^WHITE%^88%^RESET%^\n"
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^      | `-!._  |  `;!  ;.%^RESET%^ _______________ %^RESET%^%^RED%^,'| .-' |%^RESET%^%^RED%^   _!.i'     |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^..__  |     |`-!._ | `.| %^RESET%^|_______________||%^RESET%^%^RED%^."'|  _!.;'   |     _|..%^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^   |``"..__ |    |`";.| i%^RESET%^|_|%^BOLD%^%^BLACK%^MMMMMMMMMMM%^RESET%^|_|%^RESET%^%^RED%^'| _!-|   |   _|..-|'    %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^   |      |``--..|_ | `;!%^RESET%^|l|%^BOLD%^%^BLACK%^MMoMMMMoMMM%^RESET%^|1|%^RESET%^%^RED%^.'j   |_..!-'|     |     %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^   |      |    |   |`-,!_%^RESET%^|_|%^BOLD%^%^BLACK%^MMMMP'YMMMM%^RESET%^|_|%^RESET%^%^RED%^|.!-;'  |    |     |     %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^___|______|____!.,.!,.!,!%^RESET%^|d|%^BOLD%^%^BLACK%^MMMo %^BOLD%^%^YELLOW%^*%^BOLD%^%^BLACK%^ loMM%^RESET%^|p|%^RESET%^%^RED%^,!,.!.,.!..__|_____|_____%^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^      |     |    |  |  | %^RESET%^|_|%^BOLD%^%^BLACK%^MMMMb,dMMMM%^RESET%^|_|%^RESET%^%^RED%^| |   |   |    |      |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^      |     |    |..!-;'i%^RESET%^|r|%^BOLD%^%^BLACK%^MPYMoMMMMoM%^RESET%^|r|%^RESET%^%^RED%^ |`-..|   |    |      |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^      |    _!.-j'  | _!,"%^RESET%^|_|%^BOLD%^%^BLACK%^M)(MMMMoMMM%^RESET%^|_|%^RESET%^%^RED%^|!._|  `i-!.._ |      |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^     _!.-'|    | _."|  !;%^RESET%^|1|%^BOLD%^%^BLACK%^MbdMMoMMMMM%^RESET%^|l|%^RESET%^%^RED%^`.| `-._|    |``-.._  |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^..-i'     |  _.''|  !-| !%^RESET%^|_|%^BOLD%^%^BLACK%^MMMoMMMMoMM%^RESET%^|_|%^RESET%^%^RED%^.|`-. | ``._ |     |``"..%^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^   |      |.|    |.|  !| %^RESET%^|u|%^BOLD%^%^BLACK%^MoMMMMoMMMM%^RESET%^|n|%^RESET%^%^RED%^|`. |`!   | `".    |     %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^   |  _.-'  |  .'  |.' |/%^RESET%^|_|%^BOLD%^%^BLACK%^MMMMoMMMMoM%^RESET%^|_|%^RESET%^%^RED%^! |`!  `,.|    |-._|     %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^  _!"'|     !.'|  .'| .'|%^RESET%^[@]%^BOLD%^%^BLACK%^MMMMMMMMMMM%^RESET%^[@]%^RESET%^%^RED%^ \|  `. | `._  |   `-._  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^-'    |   .'   |.|  |/| /                 \|`.  |`!    |.|      |`-%^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^      |_.'|   .' | .' |/                   \  \ |  `.  | `._    |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^     .'   | .'   |/|  /                     \ |`!   |`.|    `.  |  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88%^RESET%^%^RED%^  _.'     !'|   .' | /                       \|  `  |  `.    |`.|  %^BOLD%^%^WHITE%^88%^RESET%^
%^BOLD%^%^WHITE%^88 %^RED%^Step into my office!%^BOLD%^%^WHITE%^ 88888888888888888888888888888888888888888888888%^RESET%^

%^BOLD%^%^BLACK%^Welcome to %^BOLD%^%^RED%^Hell!%^RESET%^
ENDTEXT);
   return 1;
}
int get() { return 0; }
