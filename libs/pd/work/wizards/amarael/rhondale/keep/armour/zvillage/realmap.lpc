#include <std.h>
#include <aziraphale.h>
inherit OBJECT;

void create() {
   ::create();
     set_id(({"map", "mapxzor"}));
     set_name("Rhondale Fountain");
     set_long("This is a map of the forest just outside Rhondale. It shows a path that can supposedly lead you to the village of the
Kra'toans. Read it, if you want.");
     set_short("a map");
     set_weight(0);
     set_value(0);
}

void init() {
   ::init();
        add_action("readin", "read");
        }

int readin(string str) {
        if(str != "map") return 0;
        write( @EndText

%^BOLD%^WHITE%^+-----------------------------------------------------------------------+
|%^RESET%^GREEN%^                                                [ ]-[ ]-[ ]            %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^                                                 |         \           %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^                                                [ ]         [ ]        %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^                                                   \           \       %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^                [ ]                                 [ ]         [ ]-[ ]%^BOLD%^WHITE%^|
|%^RESET%^GREEN%^               /   \                                 |             /   %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^            [ ]     [ ]                             [ ]         [ ]    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^             |         \                             |           |     %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^            [ ]         [ ]-[ ]-[ ]                 [ ]         [ ]    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^           /                     |                     \           \   %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ]                     [ ]                     [ ]         [ ]%^BOLD%^WHITE%^|
|%^RESET%^GREEN%^           \                   /                       /             | %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^            [ ]             [ ]                     [ ]             [%^YELLOW%^X%^RESET%^GREEN%^]%^BOLD%^WHITE%^|
|%^RESET%^GREEN%^             |                 \                   /                   %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^            [ ]                 [ ]         [ ]-[ ]                    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^               \                   \         |                         %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^    [ ]-[ ]     [ ]                 [ ]-[ ]-[ ]                        %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^       \   \       \                                                   %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ] [ ]     [ ]                                                %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^         |     \   /                                                   %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ]     [ ]                                                    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^         |                                                             %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ]                                                            %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^       /                                                               %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^    [ ]                 %^RESET%^At the X does lie Kra'Toa'Kathor,              %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^   /                         %^RESET%^home of the Kra'toan people.              %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^[ ]                                                                    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^ |                                                                     %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^[ ]                                                                    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^ |                                                                     %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^[ ]                                                                    %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^   \                                                                   %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^    [ ]                                                                %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^       \                                                               %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ]                                                            %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^         |                                                             %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ]                                                            %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^         |                                                             %^BOLD%^WHITE%^|
|%^RESET%^GREEN%^        [ ]                                                            %^BOLD%^WHITE%^|
+-----------------------------------------------------------------------+%^RESET%^
EndText );
return 1;
}
