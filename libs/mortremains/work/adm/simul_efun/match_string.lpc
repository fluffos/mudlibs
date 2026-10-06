//
//	match_string
//
// simul_efun to do simple * and ? wildcarding. Written as a stopgap
// by Zak 930221, for any mudlib which needs it until a driver with
// the match_string() efun() interface to the function in file.c of
// the same name is running.
//
// Based on the version in MudOS 0.9.15's file.c, except that it
// had to be rewritten to not use `goto's'.


nosave string *match, *src;
nosave int	mlen, slen;

protected int
m_str2(int mp, int sp)
{
    int i;

    while (1)
    {
	if (mp >= mlen)
	    return (sp >= slen);

	switch ( match[ mp ] )
	{
	    case "?":
		if (sp >= slen)
		    return 0;
		sp++;
		mp++;
		break;
	    case "*":
		mp++;
		if (mp >= mlen)
		    return 1;
		for ( i = sp; i < slen; i++ )
		    if ( m_str2( mp, i ) )
			return 1;
		return 0;
	    case "\\":
		mp++;
		if (mp >= mlen)
		    return 0;
		// fall thru
	    default:
		if (sp >= slen)
	            return 0;	// new check
		if (match[mp] != src[sp])
		    return 0;
		mp++;
		sp++;
	} // switch
    } // while
} // m_str2

int
match_string(string pattern, string source)
{
    if (!pattern || !source)
	return 0;
    match = explode(pattern, "");
    mlen = sizeof(match);
    src = explode(source, "");
    slen = sizeof(src);
    return m_str2(0, 0);
} // match_string
