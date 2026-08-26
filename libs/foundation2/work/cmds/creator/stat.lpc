/*    /cmds/creator/stat.c
 *    from the Foundation II LPC Library
 *    a command to view something's stats
 *    created by Descartes of Borg 950409
 */

#include <lib.h>

inherit LIB_DAEMON;
 
mixed cmd(string args) {
    string *lines, *arr, *limbs;
    object ob;
    string tmp1, tmp2;
    int i, x, y, cols;

    if( args == "" || !args ) return 0;
    if( !(ob = find_player(convert_name(args))) &&
       !(ob = find_living(lower_case(args))) )
      return capitalize(args) + " is nowhere to be found.";
    if( creatorp(ob) ) return "You cannot get stat information on a creator.";
    cols = ((int *)this_player()->GetScreen())[0];
    tmp1 = (string)ob->GetCapName() + " aka " + (string)ob->GetShort() +
      ", level " + (int)ob->GetLevel() + " " + (string)ob->GetGender();
    if( !(tmp2 = (string)ob->GetRace()) ) tmp2 = "blob";
    tmp1 += " " + tmp2;
    if( !(tmp2 = (string)ob->GetClass()) ) tmp2 = "drifter";
    tmp1 += " " + capitalize(tmp2);
    if( tmp2 = (string)ob->GetSpouse() ) 
      tmp1 += " (spouse: " + tmp2 + ")";
    lines = ({ center(tmp1, cols) , "" });
    lines += ({ center("Health: " +(int)ob->GetHealthPoints() + "/"+
		       (int)ob->GetMaxHealthPoints() + "   Magic: " +
		       (int)ob->GetMagicPoints() + "/" +
		       (int)ob->GetMaxMagicPoints() + "   Stamina: " +
		       (int)ob->GetStaminaPoints() + "/" +
		       (int)ob->GetMaxStaminaPoints() + "   Carry: " +
		       (int)ob->GetCarriedMass() + "/" +
		       (int)ob->GetMaxCarry(), cols) });
    lines += ({ "", "Limbs:" });
    limbs = (string *)ob->GetWieldingLimbs();
    arr = map((string *)ob->GetLimbs(),
	      (: sprintf("%:-14s%s (%d) %d/%d", $1,
			 ((member_array($1, $(limbs)) == -1) ? " " : "*"),
			 (int)($(ob))->GetLimbClass($1),
			 (int)($(ob))->GetHealthPoints($1),
			 (int)($(ob))->GetMaxHealthPoints($1)) :));
    i = sizeof(arr);
    while(i--) if( (y = strlen(arr[i])) > x ) x = y;
    x = cols/(x+2);
    lines += explode(format_page(arr, x), "\n") + ({ "", "Skills:" });
    arr = map((string *)ob->GetSkills(), 
	      (: sprintf("%:-18s (%d) %d/%d", $1, 
			 (int)($(ob))->GetSkillClass($1),
			 (int)($(ob))->GetSkillLevel($1), 
			 (int)($(ob))->GetBaseSkillLevel($1)) :));
    i = sizeof(arr);
    while(i--) if( (y = strlen(arr[i])) > x ) x = y;
    x = cols/(x+2);
    lines += explode(format_page(arr, x), "\n") + ({ "", "Stats:" });
    arr = map((string *)ob->GetStats(),
	      (: sprintf("%:-12s (%d) %d/%d", $1, 
			 (int)($(ob))->GetStatClass($1),
			 (int)($(ob))->GetStatLevel($1),
			 (int)($(ob))->GetBaseStatLevel($1)) :));
    i = sizeof(arr);
    x = 0;
    while(i--) if( (y = strlen(arr[i])) > x ) x = y;
    x =cols/(x+2);
    lines += explode(format_page(arr, x), "\n");
    this_player()->more(lines, "system");
    return 1;
}
