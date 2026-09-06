/*
 * /bin/daemons/drunkd.c
 *
 * Lots of neat effects to drunk people
 *
 * Copyright 1994 StickMUD RY.
 * All Rights Reserved
 *
 */

#include <conditions.h>
#include <macros.h>

#define NAME ((string)ob->query_name())
#define TH env->tell_here
#define TM ob->tell_me

void
drunk_effect(object ob)
{
    object env;

    if (!ob || !living(ob)) return;
    if (!(env = environment(ob))) return;

    switch (random(5))
    {
    case 0:
	TH(NAME + " hiccups.\n", ob, 1);
	TM("You hiccup.\n");
	break;
    case 1:
	TH(NAME + " seems to fall, but takes a step and recovers.\n", ob, 1);
	TM("You stumble.\n");
	break;
    case 3:
	TM("You feel " + (ob->query_condition(C_HALLUCINATING) ?
	    "so cosmic!" : "drunk.") + " \n");
	TH(NAME + " looks drunk.\n", ob, 1);
	break;
    case 4:
	TH(NAME + " burps.\n", ob, 1);
	TM("You burp.\n");
	break;
    default:
	if ((string)ob->query_race() == "elf")
	{
	    TH(NAME + " doubles over and pukes.\n", ob, 1);
	    TM("You puke on your shoes.\n");
	}
	break;
    }
}
