#include <std.h>
inherit OBJECT;
void create() {
    :: create();
    set_name("old map");
    set_short("old map");
    set_long("An old map\n\n"
      "type 'view' to view it");
    set_id(({"map", "old map", "an old map"}));
    set_mass(0);
    set_value(0);
}
void init()
{
    ::init();
    add_action("cmd_view", "view");
}
int cmd_view(string str)
{
    if (!str || str=="") return 0;
    if (str!="map") return 0;
    write( @EndText
%^GREEN%^            --------  --------
            |      |  |      |
            --------  --------
          /              |
--------              --------
|      | ------------ |      |
--------              --------
                         |
                      --------
                      |      |
                      --------
                         |
                      --------   --------
                      |      |   |      |
                      --------   --------
                         |          |
                      --------   --------
                      |      | - |      |
                      --------   --------
                                    |
                                 --------
                                 |      |
                                 --------
EndText );
    return 1;
}
int query_auto_load() { return 1; }
