/*
** File: certificate.c
** Author: Lady Nsd
** Purpose: To goof off with shya for a bit
*/

inherit OBJECT ;
void create() {
    set("author", "nsd");
    set ("short", "Certificate of property");
    set("long", @EndText
This is a certificate of property printed in bond paper with
a watermark of this mud. Also has the stamps of authenticity.
It's a legal document and you can 'read' it.
EndText);
    set ("id", ({ "certificate"}) );
    set("mass", 0);
    set("prevent_clean", 1);
}
void init() {
    add_action("read_certificate", "read");
}
int read_certificate (string str) {
    if (str != "certificate") return 0;
    say(TPN+" reads the Certificate of Property.\n");
    write(@EndText
@*=-~-~-~-~-~-~-~-~-~-=@^@=-~-~-~-~-~-~-~-~-~-*@
*                                              *
|         CERTIFICATE  OF  PROPERTY:           |
|                                              |
|      This certificate grants SHYA legal      |
|      rights over the sex slave SHALLAR.      |
|                                              |
|      The present document gives SHYA         |
|      total and absolute control over         |
|      the possession of the slave named       |
*      above.                                  *
@                                              @
<             Given to SHYA on:                >
@                                              @
*          Tuesday, August 1, 2000             *
|                                              |
|                    At:                       |
|                                              |
|            Mortal Remains Mud                |
|                                              |
|                        Signed by ex-owner:   |
|                                              |
|                         -Lady Nsd            |
|                                              |
*                                              *
@*=-~-~-~-~-~-~-~-~-~-=@v@=-~-~-~-~-~-~-~-~-~-*@
EndText);
    return 1;
}
int query_auto_load() {return 1;}
/* End of file */
