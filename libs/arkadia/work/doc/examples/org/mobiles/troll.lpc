/*
    /doc/examples/mobiles/troll.c

    JnA 920115

    A sample monster

    Monsters are humanoid creatures that get humanoid attacks and
    hitlocations predefined. We need not bother to set these if we
    do not want to, it will be managed for us.

    This troll gives an example of how to use the sequence actions in
    combination with VBFC. It is used to wield and wear.

*/
inherit "/std/monster";

#include "/sys/ss_types.h"
#include "/sys/macros.h"

#define WEP "/doc/examples/weapons/knife"
#define ARM "/doc/examples/armours/jacket"

create_monster()
{
    /* We ignore the master object 
     */
    if (!IS_CLONE) 
	return;

    set_name("ugluk");
    set_race_name("troll"); 
    set_adj("nasty");
    set_long("It is a very ugly and nasty lookin' troll.\n");

    /* Average stat: 5 
     */
    default_config_npc(5);          

    /* But we want it to have more hitpoints
     */
    set_base_stat(SS_CON, 20);
    set_hp(1000);

    seq_new("do_things");
    seq_addfirst("do_things",({"@@arm_me","say Ok, come on you bastards!"}));
}

arm_me()
{
    object wep, arm;

    /* In VBFC's euid == 0, must fix cause we want to clone things
    */
    seteuid(getuid(this_object()));

    wep = clone_object(WEP);
    wep->move(this_object());
    command("wield knife");

    arm = clone_object(ARM);
    arm->move(this_object());
    command("wear jacket");
}

/* The rest here is to get this mobile to be a nice buddy and if he is in a
 * team and he or a members gets attacked he will join the fight.
 */
/*
 * Function name: attacked_by
 * Description:   This function is called when somebody attacks this object
 * Arguments:     ob - The attacker
 */
void
attacked_by(object ob)
{
    object *arr;
    int i;

    ::attacked_by(ob);

    arr = (object *)query_team_others();
    for (i = 0; i < sizeof(arr); i++)
        arr[i]->notify_ob_attacked_me(this_object(), ob);
}

/*
 * Function name: notify_ob_attacked_me
 * Description:   This is called when someone attacks a team member of mine
 * Arguments:     friend - My team mate
 *                attacker - The attacker
 */
void
notify_ob_attacked_me(object friend, object attacker)
{
    if (query_attack())
        return;

    if (random(10))
        call_out("help_friend", 1, attacker);
}

/*
 * Function name: help_friend
 * Description:   Help my friends by attacking their attacker
 * Arguments:     attacker - The person who attacked my friend
 */
void
help_friend(object ob)
{
    if (ob && !query_attack() && present(ob, environment()))
    {
        command("say You scum, stop fighting my friend!");
        command("kill " + lower_case(ob->query_real_name()));
    }
}

