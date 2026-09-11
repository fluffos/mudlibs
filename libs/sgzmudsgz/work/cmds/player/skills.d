// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** skills.c -- print out the player's skills
**
** 960522, Deathblade: Created.
*/

#include <mudlib.h>
#include <config.h>
#include <classes.h>

inherit CMD;
inherit CLASS_SKILL;

private void main(string arg)
{
#ifndef USE_SKILLS
    out(mud_name() + "目前没有技能系统，对不起。\n");
#else

    class skill * skills = this_body()->get_skills();
    string name;
    class skill skill;

    if ( sizeof(skills) == 0 )
    {
        out("你不会任何技能。\n");
        return;
    }

    out("你学过的技能有：\n");
    foreach ( name, skill in skills )
    {
        outf("%20s: %5d  %5d\n",
             name, skill->skill_points, skill->training_points);
    }

#endif /* USE_SKILLS */
}
