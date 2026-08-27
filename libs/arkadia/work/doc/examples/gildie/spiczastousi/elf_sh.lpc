/* Przykladowy shadow gildii 'Spiczastouchych' */

inherit "/std/guild/guild_race_sh";

#include "defs.h"

query_guild_tax_race() 
{ 
    return TAX; 
}

string 
query_guild_title_family_name()
{ 
    return "";
}

string
query_guild_title_race()
{
    return "Spiczastouch" + shadow_who->koncowka("y", "a");
}

int
query_guild_not_allow_join_race(object gracz, string typ, string styl, 
    string nazwa)
{
    if (::query_guild_not_allow_join_race(gracz, typ, styl, nazwa))
	return 1;

    return 0;
}

string 
query_guild_name_race()
{
   return GUILD_NAME;
}

string
query_guild_style_race()
{
    return GUILD_STYLE;
}

query_guild_keep_player(object gracz)
{
    string rasa;
    
    rasa = gracz->query_race_name();
    if ( (rasa != "elf") && (rasa != "elfka"))
    {
	write("Jako, ze juz nie jestes juz elf" + gracz->koncowka("em", "ka") +
	   ", bedziesz musial" + gracz->koncowka("", "a") + " opuscic "+
	   "nasze stowarzyszenie...\n");
	   
	set_alarm(2.0, 0.0, "wyrzuc_drania", gracz);
	   
	return 0;
    }
    
    set_alarm(1.0, 0.0, "daj_mu_soula", gracz);    

    return 1;
}

void
daj_mu_soula(object delikwent)
{
    delikwent->add_cmdsoul(SOUL);
    delikwent->update_hooks();
}

void
wyrzuc_drania(object gracz)
{
    gracz->remove_guild_race();
    gracz->remove_cmdsoul(SOUL);
    gracz->update_hooks();
}


