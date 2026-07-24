// math.c
// mudring

#if 0
// random
int random(int i)
{    
    if (i > 10000000)
        return efun::random(i / 100000) * 100000;
    if (i > 100000) 
        return efun::random(i / 1000) * 1000;

    return efun::random(i);
}
#endif

nomask mixed abs(mixed n)
{
	if (!floatp(n) && !intp(n))
		return 0;

	return (n<0)? -n : n;
}

// get_level
int get_level(int combat_exp)
{
    int level;

    if (combat_exp < 1000) combat_exp = 1000;

    level = sqrt(combat_exp / 1000) - 1;

    return level;
}

// Reduce the data
int valid_data(int i)
{
    if (i < 20000000)
        return i;

    i -= 20000000;
    if (i < 10000000)
        return 20000000 + i / 10;

    i -= 10000000;
    return 20000000 + (10000000 / 10) + (i / 20);
}
