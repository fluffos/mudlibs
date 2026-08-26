
#include <mudlib.h>
#include <uid.h>

private mixed *auto_load;
inherit ARMOR ;

void create() 
{
    seteuid(getuid());
    set ("id", ({ "ring", "wedding ring" }) ) ;
    set ("short", "a special ring") ;
    set ("long",@EndText
This ring is made by the hands of your beautiful wife and made especially with you in mind.
The band is made out of the purest of silver, with an inscription inside, 
'With thee love thou shall love thee well and forever.'
You feel your heart swell whenever you wear it and read the inscription. 
EndText
 );
    set ("mass", 1) ;
    set_armor_type("ring") ;
    set("size", -1); 
    set("value", 0);
    set("prevent_drop", 1);
    set ("prevent_insert", 1);
    set ("prevevt_move", 1);
    set ("prevent_clean", 1);
}
int query_auto_load() {
	return 1;
}

