/*
  cooldowns.c
  
  Shows your current cooldowns and time left.
  
  -- Tlaloc --
*/

#include <std.h>
#include <ansi.h>
#include <daemons.h>

//#define LINE sprintf("%s[ Cooldowns ]%s\n", "*=*=*=*=*=*", "*=*=*=*=*=*")
#define LINE "%^BOLD%^BLUE%^-------------------=%^CYAN%^< %^WHITE%^Cooldowns %^CYAN%^>%^BLUE%^=--------------------%^RESET%^"
#define LINE2 "%^BOLD%^BLUE%^------------------------------------------------------%^RESET%^"
#define LINE3 "%^BOLD%^BLACK%^------------------------------------------------------%^RESET%^"

inherit DAEMON;

mixed cmd_cooldowns(string args)
{
    object who = this_player();
    mapping cooldowns;
    string *keys;
    string time_output;
    int width, minutes, seconds, hours;
    
    cooldowns = who->query_cooldowns();
    keys = keys(cooldowns);
    
    write("\n");
    write(LINE);
    write(LINE3);
    
    if(sizeof(keys))
    {
        foreach(string str in keys)
        {
            seconds = cooldowns[str] - time();
            hours = seconds / 3600;
            minutes = (seconds % 3600) / 60;
            seconds = seconds % 60;
            if(hours)
                time_output = sprintf("%2dh %2dm %2ds", hours, minutes, seconds);
            else if(minutes)
                time_output = sprintf("%2dm %2ds", minutes, seconds);
            else
                time_output = sprintf("%2ds", seconds);      
            
            //time_output = sprintf("%s%s%s", hours ? hours + "h " : "", minutes ? minutes + "m " : "", seconds + "s");
            tell_object(who, sprintf("  %s%-19s%s - %s%s%s", HIY, capitalize(str), NOR, HIN, time_output, NOR));
            //tell_object(who, sprintf("   %s%-13s%s : %s%6d%s sec\n",YEL,capitalize(str),NOR,HIN,(cooldowns[str] - time()),NOR));
        }
    }
    //else
    //    write("                %^BOLD%^None%^RESET%^\n");
    
    write(LINE2);
    //write("%^BLACK%^BOLD%^Type 'dispell' to see what spells you maintain.%^RESET%^");
    //write("%^BLACK%^BOLD%^Type 'bonuses' to see what bonuses you are receiving.%^RESET%^");
    return 1;
}
    
    
    