/*  skill.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <ansi.h>
inherit F_CLEAN_UP;

void setup()
{
    seteuid(getuid());
}

string type()
{
    return "martial";
}


string report_status(object ob)
{
    int ratio;

    if( !ob->query_stat_maximum("hp") ) return "\n";

    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");

    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]"NOR;

}


