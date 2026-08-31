#include <std.h>

inherit DAEMON;

#define TIMEMAX 250000

/* Taken from Dead Souls lib. */
string RateScore(int i)
{
    string ret;

    if (!i) ret = "No score available.";
    else if (i < 51) ret = "Spectacular.";
    else if (i < 101) ret = "Excellent.";
    else if (i < 201) ret = "Very good.";
    else if (i < 301) ret = "Good.";
    else if (i < 401) ret = "Fair.";
    else if (i < 501) ret = "Poor.";
    else if (i < 601) ret = "Very poor.";
    else if (i < 701) ret = "Bad.";
    else ret = "Execrable.";

    return ret;
}

int cmd_timetest(string args)
{
#ifdef __HAS_RUSAGE__
    mapping before, after;
#endif
    float r;
    int l, a, t;

    /* Start time_expression { } test. */
    l = 1;
    t = 0;

    while (t < TIMEMAX)
    {
	a = l;

	t = time_expression
	{
	    while (l--) { }
	};

	if (t < TIMEMAX)
	    l = a * 2;
    }

    r = to_float(t) / to_float(a);

    printf("*** START TEST ***\n");
    printf("time_expression {} test...\n");
    printf("loops done = %i\n" ,a);
    printf("time taken = %i us\n", t);
    printf("ratio = %.3f (time taken / loops done)\n", r);
    printf("Rating: %s\n", RateScore(to_int(r * 1000)));

#ifdef __HAS_RUSAGE__
    /* Start rusage() test. */
    l = 1;
    t = 0;

    while (t < TIMEMAX)
    {
	a = l;
	before = rusage();

	while (l--) { }

	after = rusage();
	t = (after["utime"] - before["utime"]) * 1000;

	if (t < TIMEMAX)
	    l = a * 2;
    }

    r = to_float(t) / to_float(a);

    printf("*** START TEST ***\n");
    printf("rusage() test...\n");
    printf("loops done = %i\n" ,a);
    printf("time taken = %i us\n", t);
    printf("ratio = %.3f (time taken / loops done)\n", r);
    printf("Rating: %s\n", RateScore(to_int(r * 1000)));
#endif

    return 1;
}
