// attribute.c

#include <dbase.h>
inherit F_SKILL;
int query_str()
{
	return (int)query("str") + (int)query("force_factor")
		+ (int)query_skill("unarmed",1)/10
		+ query_temp("apply/strength");
}

int query_cor()
{
	return (int)query("cor") + (int)query("bellicosity") / 50
		+ query_temp("apply/courage");
}

int query_int()
{
	return (int)query("int")
		+ (int)query_skill("literate",1)/10
		+ query_temp("apply/intelligence");
}

int query_spi()
{
	return (int)query("spi")
		+ query_temp("apply/spirituality");
}

int query_cps()
{
	return (int)query("cps") + (int)query("force_factor") / 2
		+ query_temp("apply/composure");
}

int query_per()
{
	return (int)query("per")
		+ (int)query("balance")/1000000
		+ query_temp("apply/personality");
}

int query_con()
{
	return (int)query("con")
		+ (int)query_skill("force",1)/10
		+ query_temp("apply/constitution");
}

int query_kar()
{
	return (int)query("kar")
		+ query_temp("apply/karma");
}

