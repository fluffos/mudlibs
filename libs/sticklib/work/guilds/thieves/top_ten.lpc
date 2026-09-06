/* Keep top ten lists - used by guild hall */

#include "dirs.h"
#include "ranks.h"

#define SAVEFILE GDIR + "TOP_TEN"

/* How many on each list? */
/* Was 20, but too long evaluation strikes with that... */
#define NTOP 12

mixed top_ten;

/* Prototypes */
void sort_top_ten();
void reset_top_ten();

void
create()
{
    restore_object(SAVEFILE);
    if (!pointerp(top_ten)) reset_top_ten();
}

void
reset_top_ten()
{
    int i, j;

    top_ten = ({ ({}), ({}), ({}), ({}), ({}),
      ({}), ({}), ({}), ({}), ({}), ({}),({}), });

    for (i=0;i<12;i++)
	for (j = 0; j < NTOP; j++)
	    top_ten[i] += ({ "Nobody", 0 });

    save_object(SAVEFILE);
}

nomask void save_me() { save_object(SAVEFILE); }

/* Called from guild */
void
check_top_ten(object playerob)
{
    object tm;
    string plrn;
    int i, j, k, jep, jepulis, nimion, joo, *skills;

    if (!playerob ||
      !living(playerob) ||
      playerob->query_npc() ||
      !(tm = present("tmark", playerob))) return;

    if (playerob->query_testplayer() ||
      (int)playerob->query_coder_level() != 0) return;

    // 28-Apr-98 / Graah: Demons won't show on these lists.
    if ((int)tm->query_guildmaster() >= TR_DEMON) return;

    skills = ({ });

    for (i = 0; i < 9; i++)
	skills += ({ tm->query_skills(i) });

    if (!skills || sizeof(skills) < 9) return;

    joo = jepulis = 0;

    if (!top_ten) reset_top_ten();

    plrn = (string)playerob->query_real_name();

    for (i=0;i < 9; i++) {
	jep = -1; nimion = 0;

	for (j = 0; j < NTOP; j++) {
	    if (top_ten[i][j * 2] == plrn) {
		nimion++; joo++;
		if (top_ten[i][j * 2 + 1] < skills[i])
		{
		    top_ten[i][j * 2 + 1] = skills[i];
		    jepulis = 1;
		}
		break;
	    }
	}

	if (!nimion)
	{
	    for (j = (NTOP - 1); j >= 0; j--)
	    {
		if (top_ten[i][j * 2 + 1] < skills[i]) jep = j;
	    }

	    if (jep != -1)
	    {
		joo++;

		/* Move 'em down? */
		if (jep < (NTOP - 1))
		{
		    for (k = (NTOP - 1); k > jep; k--)
		    {
			top_ten[i][k * 2] = top_ten[i][k * 2 - 2];
			top_ten[i][k * 2 + 1] = top_ten[i][k * 2 - 1];
		    }
		}

		top_ten[i][jep * 2] = (string)playerob->query_real_name();
		top_ten[i][jep * 2 + 1] = skills[i];
	    }
	}
    }

    remove_call_out("sortimentti");
    call_out("sortimentti", 4);
}

/*
 * x = 0 = stab
 * x = 1 = tth
 */
void
check_top_damage(int x, int dmg, object playerob)
{
    object tm;
    string plrn;
    int i, j, k, jep, jepulis, nimion, joo;

    if (!playerob ||
      !living(playerob) ||
      playerob->query_npc() ||
      x < 0 || x > 2 || dmg < 1 ||
      !(tm = present("tmark", playerob))) return;

    if (playerob->query_testplayer() ||
      (int)playerob->query_coder_level() != 0) return;

    joo = jepulis = 0;

    if (!top_ten) reset_top_ten();

    plrn = (string)playerob->query_real_name();

    i = 9 + x;
    jep = -1; nimion = 0;

    for (j = 0; j < NTOP; j++) {
	if (top_ten[i][j * 2] == plrn) {
	    nimion++; joo++;
	    if (top_ten[i][j * 2 + 1] < dmg)
	    {
		top_ten[i][j * 2 + 1] = dmg;
		jepulis = 1;
	    }
	    break;
	}
    }

    if (!nimion)
    {
	for (j = (NTOP - 1); j >= 0; j--)
	{
	    if (top_ten[i][j * 2 + 1] < dmg) jep = j;
	}

	if (jep != -1)
	{
	    joo++;

	    /* Move 'em down? */
	    if (jep < (NTOP - 1))
	    {
		for (k = (NTOP - 1); k > jep; k--)
		{
		    top_ten[i][k * 2] = top_ten[i][k * 2 - 2];
		    top_ten[i][k * 2 + 1] = top_ten[i][k * 2 - 1];
		}
	    }

	    top_ten[i][jep * 2] = (string)playerob->query_real_name();
	    top_ten[i][jep * 2 + 1] = dmg;
	}
    }

    remove_call_out("sortimentti");
    call_out("sortimentti", 4);
}

void
sortimentti()
{
    sort_top_ten();
    save_object(SAVEFILE);
}

void
list_top_ten(int x)
{
    int i;

    if (x < 0 || x > 11) return;

    if (!pointerp(top_ten)) reset_top_ten();

    write("Top " + NTOP + " " +
      ({ "Backstabbers", "Sneak/Hiders",
	"Throwers", "Lockpickers", "Stealers", "Appraisers",
	"Poisons", "Tumblers", "Thieves (Average Skills)",
	"Best Stabs", "Best Throws", "Best Steals" })[x] + ":\n");
    write("-------------=======================================-------------\n");

    for (i = 0; i < NTOP; i++)
	if (x < 9)
	    write(sprintf("%2d. %-25s: %s\n",
		i + 1,
		capitalize(top_ten[x][i * 2]),
		(string)call_other(GDIR + "thief_mark_new",
		  "EV", top_ten[x][i * 2 + 1])));
	else
	    write(sprintf("%2d. %-25s: %5d\n",
		i + 1,
		capitalize(top_ten[x][i * 2]),
		top_ten[x][i * 2 + 1]));
}

void
sort_top_ten()
{
    int t, i, j, s;
    mixed tt;
    string n;

    tt = top_ten;

    for (t=0;t<12;t++)
    {
	for (i = 0; i < NTOP; i++)
	{
	    for (j = 0; j < i; j++)
	    {
		if (tt[t][i * 2 + 1] > tt[t][j * 2 + 1])
		{
		    s = tt[t][i * 2 + 1];
		    n = tt[t][i * 2];

		    tt[t][i * 2 + 1] = tt[t][j * 2 + 1];
		    tt[t][i * 2] = tt[t][j * 2];

		    tt[t][j * 2 + 1] = s;
		    tt[t][j * 2] = n;
		}
	    }
	}
    }
}
