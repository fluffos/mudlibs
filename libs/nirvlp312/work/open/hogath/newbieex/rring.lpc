/****************************************************
creator:  Hogath                                    *
Started:  5/15/04                                   *
Type:  ring                                         *
For:  Rabbit King                                   *
                                                    *                                                                                                 *
                                                    *
*****************************************************/


#include <ansi.h>
#include "/players/hogath/tools/def.h";
inherit "obj/armor";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_name(WHT+"Rabbit Ring"+NORM);
    set_alias("ring");
    set_short(WHT+"Rabbit Ring"+NORM); 
    set_type("ring");
    set_ac(1);
    set_long("A slightly tarnished band of white gold.  It has\n"+
             "the figure of a rabbit with a crown etched on it.\n");
    set_weight(0);
    set_value(200+random(600));
}
do_special(owner)
{
    int i;
    if (tp->query_level()< 10){
    i=random(12);
    if (i >9)
    {
     tell_object(owner, "You feel the power of the "+WHT+"BUNNY"+NORM+" inside!\n");
/* incorrect format- is causing hb-killing errors
     tell_room(owner,(owner->query_name()+" is over come by "+HIW+"BUNNY"+NORM+" power\n",owner));
*/
if(environment(owner)) tell_room(environment(owner),owner->query_name()+" is over come by "+HIW+"BUNNY"+NORM+" power\n",({owner}));
     return (random(2));
    }
}
}
