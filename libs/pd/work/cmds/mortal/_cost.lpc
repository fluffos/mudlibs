// cost -- seeker
// major fixes by Whit for driver change

// altered by Nesoo to changed Improve to
// show number of improvements possible.

#include <daemons.h>
#include <std.h>
#include <str_fmt.h>
inherit DAEMON;
int remove_dec(mixed i) {
    int a, b;
    if(!stringp(i)) i = ""+i+"";
    if(sscanf(i, "%d.%d", a, b)) return a;
    else return i;
}

int cmd_cost(string str)
{
    string msg_level, seeker, FGHR, *stats;
    int exp, lev_exp, lev_perc, i, tmp, max;
    stats = ({ "strength", "constitution", "dexterity", "charisma", "intelligence", "wisdom" });
    if (!(string)this_player()->query_class())
    {
        write("Your body is still in the process of forming.");
        return 1;
    }
    if ((string)this_player()->query_class()!="child")
        FGHR = "/d/nopk/tirun/"+(string)this_player()->query_class()+"_hall";
    else
        FGHR = "/d/nopk/tirun/adv_hall";
    /*
        if ((string)this_player()->query_class() == "wanderer")
            FGHR = "/cmds/skills/_improve";
    */
    exp = (int)this_player()->query_exp();
    lev_exp = (int)ADVANCE_D->get_exp((int)this_player()->query_level()+1);
    lev_perc = percent(exp,lev_exp);
    if (lev_perc >= 100)
        msg_level = "You have enough to advance to the next level.";
    if (lev_perc <= 99)
        msg_level = "You ALMOST have enough to advance.";
    if (lev_perc <= 75)
        msg_level = "You are three quarters of the way to the next level.";
    if (lev_perc <= 60)
        msg_level = "You are over half way to the next level.";
    if (lev_perc <= 50)
        msg_level = "You are half way to the next level.";
    if (lev_perc <= 25)
        msg_level = "You are a quarter of the way to the next level.";
    if (lev_perc <= 10)
        msg_level = "You have a ways to go before the next level.";
    if (lev_perc <= 5)
        msg_level = "You have just begun to the next level.";
    message("no_wrap", "%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Cost %^BLUE%^)%^RESET%^"
            "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
            "+=\n%^RESET%^", this_player());
    write("%^BOLD%^          Stat           Improve #     Cost to Improve"
            "%^RESET%^");
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~%^RESET%^");
    max = sizeof(stats);
    i = 0;
    while(i < max) {
        int count;
        int expTmp;
        count = 0;
        expTmp = this_player()->query_exp();
        seeker = "     "+arrange_string("%^BOLD%^%^MAGENTA%^"+capitalize(stats[i]), 13);
        seeker += arrange_string("%^RESET%^: "+this_player()->query_stats(stats[i]), 9);
        
        while( expTmp > ADVANCE_D->get_stat_cost(1,
                this_player()->query_base_stats(stats[i]) + 1 + count, stats[i]))
        {
            expTmp -= ADVANCE_D->get_stat_cost(1,
                this_player()->query_base_stats(stats[i]) + 1 + count, stats[i]);
            count++;
        }
        
        if( count > 0 )
            seeker += arrange_string("%^BOLD%^%^CYAN%^" + sprintf("[%|3d]", count) + "%^RESET%^", 15);
        else
            seeker += arrange_string("%^CYAN%^" + sprintf("[%|3d]", count) + "%^RESET%^", 15);
        
        if (ADVANCE_D->get_stat_cost(1,this_player()->query_base_stats(stats[i])+1, stats[i]) <= this_player()->query_exp())
            seeker += "%^BOLD%^%^WHITE%^";
        
        tmp = remove_dec(ADVANCE_D->get_stat_cost(1, this_player()->query_base_stats(stats[i])+1, stats[i]));
        seeker += add_commas(tmp);
        seeker += "%^RESET%^";
        write(seeker);
        i++;
    }
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~%^RESET%^");
    write(""+ msg_level +"\n%^CYAN%^You have "+ add_commas(exp) +" experience "
            "to spend.%^RESET%^");
    write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
            "+=+=+=+=+=+=+=+=+=\n");
    return 1;
}
int help()
{
    write( @EndText
Syntax: cost
Effect: shows you if you are close to leveling or if stats can be improved.
See also: score
EndText
    );
    return 1;
}

