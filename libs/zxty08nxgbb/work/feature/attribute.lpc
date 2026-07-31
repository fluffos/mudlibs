// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Updated by zjb@TY (2/2/03)

#include <dbase.h>
#include <skill.h>
int query_exp()
{
    object me = this_object();
    int exp, dj = me->query("zjb_dj/dj");

    switch(dj) {
            case 2:
            exp=((int)me->query("combat_exp")/100)+100000;
            break;
            case 3:
            exp=((int)me->query("combat_exp")/100)+300000; 
            break;
            case 4:
            exp=((int)me->query("combat_exp")/100)+600000; 
            break;
            case 5:
            exp=((int)me->query("combat_exp")/100)+1000000; 
            break;
            case 6:
            exp=((int)me->query("combat_exp")/100)+1500000; 
            break;
            case 7:
            exp=((int)me->query("combat_exp")/100)+2100000; 
            break;
            case 8:
            exp=((int)me->query("combat_exp")/100)+2800000;
            break;
            case 9:
            exp=((int)me->query("combat_exp")/100)+3600000;
            break;
            case 10:
            exp=((int)me->query("combat_exp")/100)+4500000;
            break;
            default: 
            break;
    }
    if ( dj > 10 ) 
        exp=((int)me->query("combat_exp")/100)+(4500000+((dj-10)*1000000));
    if ( dj < 2 )
        exp = ((int)me->query("combat_exp")/100);
    return exp;
}
int query_str()
{
    int improve = query_skill("unarmed", 1) / 10;
    return (int)query("str") + (int)query("jiali") +improve
        +query_temp("apply/strength");
}
int query_int()
{
  
return (int)query("int") + query_temp("apply/intelligence") +  (int)query_skill("literate", 1) / 10;

}
int query_con()
{
    return (int)query("con") + query_temp("apply/constitution") +
        (int)query_skill("force", 1) / 10;
}
int query_dex()
{
    int i;
    i=(this_object()->query_encumbrance()*100)/this_object()->query_max_encumbrance();
    if (i>50)
        return (int)query("dex") + query_temp("apply/dexerity") +(int)query_skill("dodge", 1) / 10-(i-30)/10;
    else
        return (int)query("dex") + query_temp("apply/dexerity") +
        (int)query_skill("dodge", 1) / 10;
}
int query_kar()
{
    return (int)query("kar")+ query_temp("apply/karma");
}
int query_per()
{
    return (int)query("per") + query_temp("apply/personality");
}

