#include <std.h>

inherit DAEMON;

int get_Pdamage(object tp, object ob, int rank, string *skills, string *stats, string *mstats) 
{
    int ret, i, tmp;
    if(!mstats)
        mstats = ({});
   //fighter ranks 1-2, 1 is for low level attacks
    if(rank == 1) {
        ret = 0;
        tmp = 0;
        i = sizeof(stats);
        while(i--)
            tmp += tp->query_stats(stats[i]);
        tmp = tmp / sizeof(stats);
        tmp = tmp * 2.5;
        ret += (int)(tmp);
        tmp = 0;
        i = sizeof(skills);
        while(i--)
            tmp += tp->query_skill(skills[i]);
        tmp = tmp / sizeof(skills);
        ret += (int)(tmp);
        ret += random(tp->query_level());
    }//rank 2 is for higher level attacks, relying more on stats than skills.
    else if(rank == 2) {
        ret = 0;
        tmp = 0;
        //----------------------------
        i = sizeof(stats);
        while(i--)
            tmp += tp->query_stats(stats[i]);
        tmp = tmp / sizeof(stats);
        tmp = tmp;
        ret += tmp*1.5;
        tmp = 0;
        //----------------------------
        i = sizeof(skills);
        while(i--)
            tmp += tp->query_skill(skills[i]);
        tmp = tmp / sizeof(skills);
        ret += (int)(tmp);
        tmp = 0;
        //----------------------------
        i = sizeof(mstats);
        while(i--)
            tmp += tp->query_stats(mstats[i]);
        if(sizeof(mstats) > 0)
            tmp = tmp / sizeof(mstats);
        tmp = 2*tmp/3;
        ret += tmp;
        tmp = 0;
        ret += random(tp->query_level());
    } 
    else {
        message("info", "This ability/spell has an invalid rank "+rank+
          " Please inform an admin or use the <bug> command to report it.",
          tp);
        return 0; // yes, that means it will do 0 damage.
    }
   
    ret -= ob->query_skill("defense")/3;
    ret -= ob->query_stats("dexterity")/2;
    ret -= ob->query_stats("constitution")/10;
    ret -= ob->query_stats("strength")/10;
    
    ret = (int)(3*ret/2);
         
    if(wizardp(tp))
    {
        message("info", "Rank = "+(rank)+", Dmg = "+ret+"\n", tp);
    }
    return (ret);

}

int get_Mdamage(object tp, object ob, int rank, string *skills, string *stats, string *mskills)
{
    int ret, i, tmp;
    if(!mskills)
        mskills = ({});

    if(rank == 1) {
        ret = 0;
        tmp = 0;
        i = sizeof(stats);
        while(i--)
            tmp += tp->query_stats(stats[i]);
        tmp = tmp / sizeof(stats);
        tmp = (int)(tmp);
        ret += tmp;
        tmp = 0;
        i = sizeof(skills);
        while(i--)
            tmp += tp->query_skill(skills[i]);
        tmp = tmp / sizeof(skills);
        ret += (int)(3*tmp/2);
        ret += random(tp->query_level());
    }
    else if(rank == 2) {
        ret = 0;
        tmp = 0;
        //---------------------------
        i = sizeof(stats);
        while(i--)
            tmp += tp->query_stats(stats[i]);
        tmp = tmp / sizeof(stats);
        tmp = tmp;
        ret += tmp;
        tmp = 0;
        //----------------------------
        i = sizeof(skills);
        while(i--)
            tmp += tp->query_skill(skills[i]);
        tmp = tmp / sizeof(skills);
        ret += tmp;
        tmp = 0;
        //----------------------------
        i = sizeof(mskills);
        while(i--)
            tmp += tp->query_skill(mskills[i]);
        if(sizeof(mskills) > 0)
            tmp = tmp / sizeof(mskills);
        tmp = tmp/3;
        ret += tmp;
        tmp = 0;
        ret += random(tp->query_level());
    }
    else {
        message("info", "This ability/spell has an invalid rank "+rank+
          " Please inform an admin or use the <bug> command to report it.",
          tp);
        return 0; // yes, that means it will do 0 damage.
    }
    
    ret -= ob->query_skill("magic defense")/4;
    ret -= (int)(3*(ob->query_stats("wisdom"))/2);
    ret -= ob->query_stats("intelligence")/5;
    
    /*
    ret -= ob->query_skill("magic defense")/2;
    ret -= ob->query_stats("wisdom")/3;
    ret -= ob->query_stats("intelligence")/8;
    */
    ret = (int)(3*ret/2);
         
    if(wizardp(tp))
    {
        message("info", "Rank = "+(rank)+", Dmg = "+ret+"\n", tp);
    }
    return (ret);
    
}
