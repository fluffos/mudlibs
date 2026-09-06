// Tumble, tth and stab all now ask critical from this module.
// There are critical levels 0, 1, 2 and 3.
// 25-Sep-97 / Graah
// 26-Sep-97 / Graah: Upgrading
// 01-Feb-98 / Chaotic: Re-write

// Originaly based on a 0-20 out of 100 system now 0-200 out of 1000
// Skill differences are more meaningful with this system
// 2.5% (1-25)   Is based on skill between 0 and 5000
// 7.5% (26-100) Is based on skill between 5001 and ult
//  20% (101-300)Is based on ultimate skill, current assumed max 11800
// Critical column:	the same as under old
// Critical-2:		odds improved about 1/4
// Critical-3:		very best players will at most see 1 or two a day
// Rates:
// Skill	Critical	Critical-2	Critical-3
// 4000		 1/50		1/3750		1/506250
// 8000		 1/14		1/300		1/11571
// 10000	 1/10		1/150		1/4050
// 10500	 1/7.8		1/91		1/1919
// 11000	 1/6.4		1/62		1/1079
// 11500	 1/5.4		1/44		1/653
// 11800	 1/5		1/37		1/506

#ifndef _THIEF_H
#include "../thief.h"
#endif

varargs int critical(int skill, int gm, int adv, int pk) {
    int chance,high;

    chance=high=0;

    if(skill > 10000) {
	high  = skill - 10000;
	chance += high / 10;
	skill = 10000;
    }

    if(skill > 5000) {
	high  = skill - 5000;
	chance += high / 66;
	skill = 5000;
    }

    chance += skill / 200;

    // Racial bonus or penalty. This is from -3 to 4.
    // Much more resonable in a base 100 system.  Now level 1
    // hobbits don't have a 5% chance with no skills
    chance += adv;

    // Demon or enforcer status gives an extra 5%
    if(gm) chance += 50;

    // Make sure people aren't exceeding the 35% absolute rate
    if(chance < 1) chance = 1;
    else if(chance > 350) chance = 350;

    // Check to see that there was a critical at all
    if(random(1001) >= chance) return 0;

    // Check to see if it was an extra special critical
    if(random(1501) < chance) {
	// Criticals of 3rd level are even more scarce.
	if(random(2701) < chance) {
	    return 3;
	} else  {
	    return 2;
	}
    }

    return 1;
}
