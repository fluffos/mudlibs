
#include <conditions.h>

status cook_cmd(object cooker,object what,object where,int part)
{
    if (!present(cooker,where))
    {
	cooker->tell_me("Ack you left your meat unattended and it \
burnt to a useless crisp!");
	destruct(what);
	(cooker->query_guild_object())->end_cook();
	return 0;
    }
    if (!what)
    {   
	cooker->tell_me("Oops, the meat is gone!");
	(cooker->query_guild_object())->end_cook();
	return 0;
    }
    if (cooker->is_fighting())
    {
	cooker->tell_me("You can't cook and fight at the same time!");
	(cooker->query_guild_object())->end_cook();
	return 0;
    }
    if (present(what,cooker))
    {
	cooker->tell_me("ACK! That corpse was HOT!");
	cooker->add_hp(-(random(10)));
	move_object(what,environment(cooker));
    }

    switch(part)
    {
    case 0:
	cooker->tell_me("You start a small cooking fire.");
	environment(cooker)->tell_here(cooker->query_name() +
	  " starts a small fire.",cooker);
	part += 1;
	break;
    case 1:
	cooker->tell_me("You place the corpse over the fire.  \
YUM! YUM! YUM! You can't wait!");
	environment(cooker)->tell_here(cooker->query_name() + 
	  " places a corpse over the fire.",cooker);
	part += 1;
	break;
    case 2:
	environment(cooker)->tell_here("The corpse crackles and \
pops in the fire, slowly turning darker and darker.");
	part += 1; 
	break;
    case 3:
	cooker->tell_me("The aroma kicks your demonic hunger into overdrive and \
you remove the corpse from the fire.");
	environment(cooker)->tell_here(cooker->query_name() + 
	  " removes the corpse from the fire.",cooker);
	part += 1;
	break;
    }
    if (part < 4)
	call_out("cook_cmd",1,cooker,what,where,part);
    else
	call_out("final_cook",1,cooker,what);
    return 1;
}
status final_cook(object cooker,object what)
{
    string c_race;
    int corpse_lev;
    object item;

    (cooker->query_guild_object())->end_cook();
    if (!what) return 0;
    cooker->tell_me("You can't wait another second!  You \
savagely devour the cooked meat!");
    environment(cooker)->tell_here(cooker->query_name() + 
      " devours the cooked meat!",cooker);
    c_race = (string)cooker->query_race();
    // Necros - very slight upgrade from divided by 10 to divided by 8
    corpse_lev = (int)what->query_orig_level() / 8;
    if (corpse_lev < 1)
	corpse_lev = 1;
    while(item = first_inventory(what))
	move_object(item, environment(what));
    destruct(what);
    if (!cooker->eat_food(corpse_lev*7))
    {
	cooker->tell_me("You are too full to eat anymore!");
	(cooker->query_guild_object())->end_cook();
	return 0;
    }
    if (c_race != "hobbit")
    {
	if (!random(250))
	{
	    cooker->tell_me("Ack! You undercooked it!");
	    cooker->add_hp(-(5 + random(10)));
	    cooker->set_condition(C_POISONED,random(10));
	    (cooker->query_guild_object())->end_cook();
	    return 1;
	}
	else
	{
	    if (!random(750))
	    {
		cooker->tell_me("WOW! You cooked that just right!");
		cooker->add_hp(corpse_lev * 2 * (20+random(5)));
		cooker->add_fp(corpse_lev * 2 * (20+random(5)));
		cooker->add_sp(corpse_lev *2 * (10 + random(5)));
		(cooker->query_guild_object())->end_cook();
		return 1;
	    }
	}
    }
    else
    {
	if (!random(400))
	{
	    cooker->tell_me("Ack! You undercooked it!");
	    cooker->add_hp(-(5 + random(5)));
	    cooker->set_condition(C_POISONED,random(5));
	    (cooker->query_guild_object())->end_cook();
	    return 1;
	}
	else
	{
	    if (!random(500))
	    {
		cooker->tell_me("WOW! That was cooked just right!");
		cooker->add_hp(corpse_lev * 2 * (20 + random(10)));
		cooker->add_fp(corpse_lev * 2 * (20 + random(10)));
		cooker->add_sp(corpse_lev * 2 * (10 + random(3)));
		(cooker->query_guild_object())->end_cook();
		return 1;
	    }
	}
    }
    cooker->tell_me("Yum!!");
    if (c_race != "hobbit")
    {
	cooker->add_hp(corpse_lev * (10 + random(10)));
	cooker->add_fp(corpse_lev * (10 + random(5)));
	cooker->add_sp(corpse_lev * (3 + random(4)));
    }
    else
    {
	cooker->add_hp(corpse_lev * (12 + random(10)));
	cooker->add_fp(corpse_lev * (10 + random(10)));
	cooker->add_sp(corpse_lev * (5 + random(6)));
    }
    (cooker->query_guild_object())->end_cook();
    return 1;
}
