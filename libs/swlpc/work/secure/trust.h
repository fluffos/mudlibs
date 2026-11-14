nosave fix_trust()
{
if (k_tmstmp < 10)
    {
    if (k_tmstmp == 1 || (k_tmstmp == 0 && untrustworthy))
	dont_trust();
    else
	do_trust();
    }
    if (!wiz_level) do_trust();
}


nosave dont_trust()
{
    k_tmstmp = (random(50000) & 65503) | 32;
}


nosave do_trust()
{
    k_tmstmp = random(50000) & 65503;
}

/* if this returns 0 then player is to be logged. */
nosave trusted()
{
    return (!(k_tmstmp & 32));
}


/* NOTE: Do not call this in code - only for gods to set trust values */
god_set_trust(y)
{
if (query_su_level(caller()) < 10000) return 0;

if (y)
    do_trust();
else
    dont_trust();
}

int allow(string str) 
{
    array allow_who;

	allow_who = ({ "gandalf", "dredd", "rhys", "whiplash",
	"germaine", "llati", "pandora", "gods" });

	if (index(allow_who, str) >= 0)
	    return 1;

	return 0;
}	
