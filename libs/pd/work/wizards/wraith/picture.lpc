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
    

    message("info", "%^BOLD%^%^BLACK%^                                _,.-----.,_                            \n"
" %^BOLD%^%^BLACK%^                            ,-~           ~-.                         \n"
"%^BOLD%^%^BLACK%^                           ,^___           ___^.                       \n"
"%^BOLD%^%^BLACK%^                         ,'~'   ~'   .   '~   '~'.                     \n"
"%^BOLD%^%^BLACK%^                         Y %^BOLD%^%^RED%^ ,--._    %^BOLD%^%^BLACK%^I   %^BOLD%^%^RED%^ _.--.  %^BOLD%^%^BLACK%^Y                     \n"
"%^BOLD%^%^BLACK%^                         | %^BOLD%^%^RED%^Y   ,'~-. %^BOLD%^%^BLACK%^| %^BOLD%^%^RED%^,-~',   Y %^BOLD%^%^BLACK%^|                     \n"
"%^BOLD%^%^BLACK%^                         | %^BOLD%^%^RED%^|  |     }%^BOLD%^%^BLACK%^:%^BOLD%^%^RED%^{     |  | %^BOLD%^%^BLACK%^|                    \n"
"%^BOLD%^%^BLACK%^                         j %^BOLD%^%^RED%^l  (    ,'%^BOLD%^%^BLACK%^| %^BOLD%^%^RED%^',   )  ! %^BOLD%^%^BLACK%^l                    \n"
"%^BOLD%^%^BLACK%^                      .-~  %^BOLD%^%^RED%^(__,.--' %^BOLD%^%^BLACK%^.^. %^BOLD%^%^RED%^'--.,__) %^BOLD%^%^BLACK%^ ~-.                  \n"
"%^BOLD%^%^BLACK%^                     (           ,','| ',',          )                 \n"
"%^BOLD%^%^BLACK%^                     ',.____,   ~   '''   ~   .____.,'                 \n"
"%^BOLD%^%^BLACK%^                       ^.____                 ____.^                   \n"
"%^BOLD%^%^BLACK%^                         |  |T ~', !   ! ,'~ T|  |                     \n"
"%^BOLD%^%^BLACK%^                         |  |l   _ _ _ _ _   !|  |                     \n"
"%^BOLD%^%^BLACK%^                         |  l','V V V V V V','j  |                     \n"
"%^BOLD%^%^BLACK%^                         l  | ',|_|_|_|_|_|,' |  !                     \n"
"%^BOLD%^%^BLACK%^                          ', ',[T T T T T TI,'  ,'                     \n"
"%^BOLD%^%^BLACK%^                           ',  `^-^-^-^-^-^'  ,'                       \n"
"%^BOLD%^%^BLACK%^                            ',               ,'                        \n"
"%^BOLD%^%^BLACK%^                              ',           ,,'                         \n"
"%^BOLD%^%^BLACK%^                                '^-.___,-^'                            \n"
"\n"
"%^BOLD%^%^BLACK%^Welcome to %^BOLD%^%^RED%^Hell!%^RESET%^", this_player());

   return 1;
}
int get() { return 0; }
