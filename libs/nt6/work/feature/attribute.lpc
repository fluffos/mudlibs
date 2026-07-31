// This program is a part of NT MudLIB
// attribute.c
// Rewritten by Lonely@nitan.org

#include <skill.h>

int query_str()
{
        mapping sk;
        int str;
        int ability = 0;
        int lx = 0;

        str = query("str");
        str += query("ability1/str");
        if( query("jingmai/finish") )
        str += ZHOUTIAN_D->query_jingmai_effect("str");
        str += query("jingmai/str");
        str += query_temp("apply/str");
        if( !mapp(sk = query_skills()) )
                return str;
        ability = (int)sk["unarmed"];
        if( ability < (int) sk["cuff"] ) ability = sk["cuff"];
        if( ability < (int) sk["finger"] ) ability = sk["finger"];
        if( ability < (int) sk["strike"] ) ability = sk["strike"];
        if( ability < (int) sk["hand"] ) ability = sk["hand"];
        if( ability < (int) sk["claw"] ) ability = sk["claw"];
        lx = (int)sk["longxiang-gong"] / 30;
        if( lx >= 13 ) lx = 15;
        return str + (ability / 10) + lx;
}

int query_int()
{
        mapping sk;
        int str;
        int ability = 0;

        str = query("int");
        str += query("ability1/int");
        if( query("jingmai/finish") )
        str += ZHOUTIAN_D->query_jingmai_effect("int");
        str += query("jingmai/int");
        str += query_temp("apply/int");
        if( !mapp(sk = query_skills()) )
                return str;
        ability = (int)sk["literate"];
        return str + (ability / 10);
}

int query_con()
{
        mapping sk;
        int str;
        int ability = 0;

        str = query("con");
        str += query("ability1/con");
        if( query("jingmai/finish") )
        str += ZHOUTIAN_D->query_jingmai_effect("con");
        str += query("jingmai/con");
        str += query_temp("apply/con");
        if( !mapp(sk = query_skills()) )
                return str;
        ability = (int)sk["force"];
        return str + (ability / 10);
}

int query_dex()
{
        mapping sk;
        int str, scale;
        int ability = 0;

        //scale = (this_object()->query_encumbrance()*100)/this_object()->query_max_encumbrance();
        str = query("dex");
        str += query("ability1/dex");
        if( query("jingmai/finish") )
        str += ZHOUTIAN_D->query_jingmai_effect("dex");
        str += query("jingmai/dex");
        str += query_temp("apply/dex")/* - (scale > 50 ? (scale-30)/10 : 0)*/;
        if( !mapp(sk = query_skills()) )
                return str;
        ability = (int)sk["dodge"];
        return str + (ability / 10);
}

int query_kar()
{
        int buff;

        if( query("jingmai/finish") ) buff = ZHOUTIAN_D->query_jingmai_effect("kar");
        else buff = query("jingmai/kar");
        return (int)query("kar") + query("ability1/kar") + buff + query_temp("apply/kar");
}

int query_per()
{
        int per;
        int age;
        int ac;

        per = (int)query("per") + query_temp("apply/per");
        if (query("special_skill/youth"))
                return per;

        age = query("age");

        ac = query_skill("art-cognize", 1);
        if (ac < 100)
        {
                if (age > 70) per -= 6; else
                if (age > 60) per -= 5; else
                if (age > 50) per -= 4; else
                if (age > 40) per -= 3; else
                if (age > 30) per -= 2;
        }

        per += ac / 20;
        return per;
}
