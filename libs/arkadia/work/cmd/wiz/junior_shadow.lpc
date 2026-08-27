/*
 * /cmd/wiz/junior_shadow.c
 *
 * This shadow redefines the function do_die() in a junior player to a
 * wizard. It prevents them from death if they so choose.
 *
 * There is some protection in the shadow for we do not want ordinary
 * mortal players to get this protection. I bet they would want to have it!
 *
 * /Mercade, 6 February 1994
 */

#pragma no_inherit
#pragma strict_types
#pragma save_binary

inherit "/std/shadow";

#include <macros.h>
#include <std.h>

/*
 * Function name: remove_death_protection
 * Description  : Remove this shadow from a player.
 * Returns      : 1 - always
 */
nomask public int
remove_death_protection()
{
    tell_object(query_shadow_who(), "Juz nie jestes chronion" +
        query_shadow_who()->koncowka("y", "a") + " przed smiercia. " +
        "Powodzenia! Zycie to ciezki kawalek chleba..\n");

    destruct();
    return 1;
}

/*
 * Function name: illegal_shadow_use
 * Description  : If you are not allowed to use this shadow, this function
 *                will take care of it.
 */
nomask private void
illegal_shadow_use(object player)
{
    SECURITY->log_syslog("ILLEGAL_JUNIOR_SHADOW",
        ctime(time()) + ", " + player->query_real_name() + 
        "<-\tshadow: uid[" + getuid() + "], euid[" + geteuid() + "].\n");
}

/*
 * Function name: do_die
 * Description  : This function is called whenever someone suspects that
 *                we have died.
 * Arguments    : killer - the object that killed us.
 */
public void
do_die(object killer)
{
    string  name;
    object *enemies;

    if ((query_shadow_who()->query_hp() > 0) ||
	(query_shadow_who()->query_ghost()))
    {
	return;
    }

    if (!objectp(killer))
    {
	killer = previous_object();
    }

    if (sscanf((string)query_shadow_who()->query_real_name(),
	"%sjr", name) != 1)
    {
	illegal_shadow_use(query_shadow_who());
	set_alarm(0.1, 0.0, "remove_death_protection");
	query_shadow_who()->do_die(killer);
	return;
    }

    if (SECURITY->query_wiz_rank(name) <= WIZ_RETIRED)
    {
	illegal_shadow_use(query_shadow_who());
	set_alarm(0.1, 0.0, "remove_death_protection");
	query_shadow_who()->do_die(killer);
	return;
    }

    enemies = (object *)query_shadow_who()->query_enemy(-1) - ({ 0 });

    if (sizeof(enemies))
    {
	query_shadow_who()->stop_fight(enemies);
	enemies->stop_fight(query_shadow_who());
    }

    /* Give him/her at least one hitpoint so this function won't be called
     * over and over again.
     */
    query_shadow_who()->set_hp(1);

    tell_roombb(environment(query_shadow_who()),
	"\n" + QCIMIE(query_shadow_who(), PL_MIA) + " umiera ....\n" +
	" .... zaraz ...  " + query_shadow_who()->query_zaimek(PL_MIA) +
	" caly czas zyje!\n" +
	"Pomimo, iz nie ma juz w " + query_shadow_who()->query_zaimek(PL_MIE) +
	" sil zyciowych, Bogowie nie chca przyjac " +
	query_shadow_who()->query_zaimek(PL_DOP, 1) + " duszy do siebie.\n",
	({query_shadow_who()}), query_shadow_who());
    tell_object(killer, "Zabil" + killer->koncowka("es", "as") + " " +
	query_shadow_who()->query_imie(killer, PL_BIE) + ".\n");
    tell_object(query_shadow_who(), "\nUMARL" + 
        query_shadow_who()->koncowka("ES", "AS") + " !!!\n\n" +
	"Junior tool jednakze ochronil cie przed smiercia.\n" +
	"Przestajesz walczyc ze wszystkimi dotychczasowymi " + 
	"przeciwnikami.\n\n");
}

/*
 * Function name: query_death_protection
 * Description  : This function will return whether the player is protected
 *                from Death.
 * Returns      : 1 (always)
 */
nomask public int
query_death_protection()
{
    return 1;
}

/*
 * Function name: shadow_me
 * Description  : This function is called to make this shadow shadow the
 *                player. It add the autoloading feature to the player.
 * Arguments    : player - the player
 * Returns      : 1 - everything went right
 *                0 - no player or player already shadowed
 */
nomask public int
shadow_me(object player)
{
    string name;

    if (sscanf((string)player->query_real_name(), "%sjr", name) != 1)
    {
	tell_object(player,
	    "ACK! Nigdy nie powinienes byl" + player->koncowka("", "a") +
	        " dostac tego shadowa!\n");
	
	illegal_shadow_use(player);
	return 0;
    }

    if (SECURITY->query_wiz_rank(name) <= WIZ_RETIRED)
    {
	tell_object(player,
	    "ACK! Nigdy nie powinienes byl" + player->koncowka("", "a") +
	        " dostac tego shadowa!\n");
	illegal_shadow_use(player);
	return 0;
    }

    if (!::shadow_me(player))
    {
	tell_object(player,
	    "Cos jest bardzo zle z junior shadowem. Nie chce " + 
	        "zashadowowac...\n");
	return 0;
    }

    tell_object(player, "Od teraz jestes chronion" + 
        player->koncowka("y", "a") + " przed Smierca!\n");
    return 1;
}
