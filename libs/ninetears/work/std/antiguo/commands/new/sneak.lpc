// #define SAFE_SNEAK
// uncomment if rooms break
/**** Original code by Unknown ****/
/**** First mod for new FR by Baldrick ****/
/**** Modified by Ilmryn to be realistic ****/
/**** The return 1's are DELIBERATE, thsi was getting into
      recursive loops
      Taniwha 1996
*/       	
#include "tweaks.h"
#include "room.h"
#define SNEAK_SKILL 20
#define COST SNEAK_COST

int sneak(string str, object mee)
{
    int i;
    object me;
    object tmp;
    mixed *dest_dir;
    mixed *dest_other;

    me = mee ? mee : this_player();

    str = me->expand_nickname(str);

    if (!str)  
    {
	write("Sintaxi: sigilar <direccion>\n");
	return 1;
    }

    if ((int)me->query_gp() < COST) 
    {
	write("No tienes suficientes puntos de guild para sigilar.\n");
	return 1;
    }
    if(me->query_guild_name() == "ranger" && !environment(me)->query_outside())
    {
	write("Perdon, aqui no.\n");
	return 1;
    }

    if(me->query_light() > 20) {
	tell_object(me, "Viste nunca sigilar una antorcha? Pues es lo que "
	  "pareces ahora mismo.\n");
	return 1;
    }

    dest_dir = (mixed *)environment(me)->query_dest_dir();
    dest_other = (mixed *)environment(me)->query_dest_other();
    if (!pointerp(dest_dir)) 
    {
	write("Porfavor contacta con alguien. Esta habitacion esta MAL!\n");
	return 1;
    }

    if ((i = member_array(str, dest_dir)) == -1 || i%2) 
    {
	write("Estaria bien si la habitacion existiese.\n");
	return 1;
    }
#ifdef SAFE_SNEAK
    tmp = find_object(dest_other[i+1][ROOM_DEST]);
    if(!tmp)
    {
	notify_fail("Fallas al sigilar a "+dest_dir[i]+" vuelve a probarlo ?.\n");
	load_object(dest_other[i+1][ROOM_DEST]);
	return 0;
    }
#endif

    me->adjust_gp(-COST);

    if ((int)me->query_level() > random(SNEAK_SKILL))
    {
	if (me->query_hide_shadow())
	    i = (int)environment(me)->do_exit_command(0, 
	      ({ dest_dir[i], "none"}), me, me );
	else
	    i = (int)environment(me)->do_exit_command(0,
	      ({ dest_dir[i], "none"}) );
    }
    else
	i = (int)environment(me)->do_exit_command(0, dest_dir[i]);

    if (!i)
    {
	write("Fallas al sigilar a "+dest_dir[i]+".\n");
	return 1;
    }  

    environment(me)->renew_exits();
    write("Sigilas al "+str+".\n");
    return 1;
}

string help() 
{
    return 
    "Sintaxi: sigilar <direccion>\n\n"
    "Te permite sigilar en una direccion. Esto permite que los otros "
    "no vean mensajes de entrada y salida tuyos. Sigilar depende de tu nivel  "
    "Ejemplo: \n"
    "> sigilar oeste\n"
    "Sigilas al oeste\n";
    
}
