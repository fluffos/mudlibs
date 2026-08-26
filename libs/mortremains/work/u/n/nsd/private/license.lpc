/*
** File: license.c
** Author: Lady Nsd
** Purpose: To goof off with shya for a bit
*/

inherit OBJECT ;
void create() {
    set("author", "nsd");
    set ("short", "License of Use");
    set("long", @EndText
This is a license that will make legal any possession
of the person that carries it. In case this licence
is stolen or lost, please notify the authorities so
we can create a new one and dismiss the old one. You
can 'read' it.
EndText);
    set ("id", ({ "license" }) );
    set("mass", 0);
    set("prevent_clean", 1);
}
void init() {
    add_action("read_license", "read");
}
int read_license (string str) {
    if (str != "license") return 0;
    say(TPN+" reads the License of Use.\n");
    write(@EndText
}>=-~-~-~-~-~-~-~-~-~-~-~-={&&}=-~-~-~-~-~-~-~-~-~-~-~-<{
v                                                       v
"                                                       "
|                  LICENSE  OF  USE:                    |
|                                                       |
|     The following document will grant SHYA total      |
|     and absolute permission to use and abuse the      |
|     sex slave SHALLAR at will.                        |
|                                                       |
|     SHYA will be able to behave freely with him       |
+     and claim him as her property. SHYA must          +
<     carry this document always as evidence of         >
+     legal possession.                                 +
|                                                       |
|     Date of expedition:   Tuesday, August 1, 2000     |
|                                                       |
|     Date of expiration:                               |
|             The day he runs away with another owner   |
|                                                       |
|                  Granter's Signature:                 |
|                      -Lady Nsd                        |
"                                                       "
^                                                       ^
}>=-~-~-~-~-~-~-~-~-~-~-~-={&&}=-~-~-~-~-~-~-~-~-~-~-~-<{
EndText);
    return 1;
}
int query_auto_load() {return 1;}
/* End of file */
