/*
 * 3/30/97 First version by Chopin
 * 
 * (int) pex = priest experienxe points.
 * This object converts pexes to skill promilles and vice versa.
 * "skill" is handled as "float" in this object and internally in
 * gen_skill_object.c, but elsewhere type "int" should be used instead.
 */


#include "../priest.h"
#include "../skills.h"


/*
 * PEX2SKILL
 * The argument is the number of skill's priest experience points
 * and the result is a value defining how good the skill is. (0..1000)
 */

float pex2skill(int pex)
{
    return 1000.0*pex/(AVERAGE_COST + pex);
}


/*
 * SKILL2PEX
 */

int skill2pex(mixed skill)
{
    int t;
    t = to_int(AVERAGE_COST*skill/(1000-skill));

    // not really needed, unless AVERAGE_COST is _really_ high
    if(t>K_MAX_PEX/1000)
	t = K_MAX_PEX/1000;
    return t;
}


/*
 * GET_SKILL_RANK
 * Calculates a skill rank (0..23 !!) directly from a pex value
 */

int
get_skill_rank(int pex) {
    int n,t;
    float tmp;

    tmp = pex/BASE_COST;
    t = to_int(tmp*tmp);
    while(t>0) {
	t>>=1; n++;
    }
    // very unlikely to happen:
    if(n>=sizeof(SKILL_RANKS)) n = sizeof(SKILL_RANKS)-1;
    return n;
}


int
rank2pex(int rank) {
    return to_int(sqrt(BASE_COST * BASE_COST * (1 << (rank-1))));

}


/*
 * PEX2STR (again a better name could be invited)
 */

string pex2str(int pex)
{
    int rank, p;

    rank = get_skill_rank(pex);
    p = rank2pex(rank);
    p = 100 * (pex - p) / (rank2pex(rank+1) - p);
    return sprintf("%s (%d%%)",SKILL_RANKS[rank], p);
}
