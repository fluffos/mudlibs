#include <lord.h>
#include <curse.h>

int curse_cmd(string str)
{
    object target;
    string tmp;
    int curse_level, curse_max, curse_bonus, cost;

    if ((int)TP->query_level() < 36)
	return 0;

    if(!str)
    {
	notify_fail("Usage: curse <weapon/armour>.\n");
	return 0;
    }

    tmp=lower_case(str);
    target=present(tmp,TP);
    tmp=capitalize(str);

    if(!target)
    {
	notify_fail("You don't have "+str+".\n");
	return 0;
    }

    if(!target->is_weapon() && !target->is_armour())
    {
	notify_fail(str+" is not a weapon or an armour.\n");
	return 0;
    }

    cost = target->is_weapon() ? CO_CURSE_WEP : CO_CURSE_ARM;

    if(SP < cost)
    {
	notify_fail(SP_MES);
	return 0;
    }

    if (target->query_curse_level())
    {
	notify_fail(tmp+" is already cursed.\n");
	return 0;
    }

    if (target->query_unique(0))
    {
	notify_fail(tmp+" can't be cursed.\n");
	return 0;
    }

    // (At least) Tron's cloak:
    if(!sscanf(object_name(target),"%!s#%~d"))
	return notify_fail(tmp+" can't be cursed.\n"),0;

    if(target->is_weapon())
    {
	curse_bonus = ((int)TP->query_level() - 36) / 10;
	if(curse_bonus > 5) curse_bonus = 5;
	curse_max   = (int)target->query_wc() / 5;
	curse_level = (random(curse_max + curse_bonus));
	target->set_curse(-curse_level,CT_CURSED);
    }
    else
    {
	curse_max   = (int)target->query_ac()/2;
	if(!curse_max) curse_max = 1;
	curse_level = (random(curse_max));
	target->set_curse(-curse_level,CT_CURSED);
    }

    TP->add_sp(-cost);
    TM("Ok. You mumble an incatation and "+str+" is cursed now.\n");
    return 1;
}
