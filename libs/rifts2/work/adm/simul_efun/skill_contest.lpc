//	This function is used to resolve contests and quick contests
//	of skills between characters.  Arg 1 is the first char.'s
//	skill, arg 2 is the second char.'s skill, and if the third
//	arg is set to 1, the contest is a quick contest, i.e., one
//	roll only, and may result in a tie.
//	Return values: 0 = tie, 1 = player 1 wins, 2 = player 2 wins
//	Note that only quick contests may tie.
//	    ^ unless it goes for 1000 cycles with no winner.
//	      (infinite loop protection)
//
//	for DarkeLIB 0.1
//	Diewarzau 7/18/95

varargs int skill_contest(int skill_1, int skill_2, int flag) {
int roll_1, roll_2, count, win_1, win_2;

    if(!intp(skill_1)) skill_1 = 0;
    if(!intp(skill_2)) skill_2 = 0;
    if(flag) {
	roll_1 = random(100);
	roll_2 = random(100);
	if(roll_1 + skill_1 > roll_2 + skill_2 ||
	  (roll_1 < 2 && roll_2 >= 2) || (roll_2 >= 98 && roll_1 < 98)) return 1;
	else if(roll_2 + skill_2 > roll_1 + skill_1 ||
	  (roll_2 < 2 && roll_1 >= 2) || (roll_1 >= 98 && roll_2 < 98)) return 2;
	else return 0;
    }
    count = 0;
     while(count < 100) {
      roll_1 = random(100);
      roll_2 = random(100);
	win_1 = roll_1 < skill_1;
	win_2 = roll_2 < skill_2;
	if(win_1 && !win_2 || (roll_1 < 2 && roll_2 >= 2) ||
	  (roll_2 >= 98 && roll_1 < 98)) return 1;
	if(win_2 && !win_1 || (roll_2 < 2 && roll_1 >= 2) ||
	  (roll_1 >= 98 && roll_2 < 98)) return 2;
	count++;
    }
    return 0;
}

