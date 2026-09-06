#ifndef _SKILLS_H_
#define _SKILLS_H_

// Skills not included in this mapping have a base difficulty of 10
// Don't forget slashes when adding lines!
#define SKILL_DIFFICULTY ([ /*** Magic Skills ***/ \
                            "spellcraft":11, "concentration":11, \
                            "faith":10, "necromancy":15, \
                            "thunder":14, "wind":14, "earth":14, \
                            "fire":14, "water":14, \
                            /*** Knowledge Skills ***/ \
                            "alchemy":16, "literacy":11, \
                            "technology":17, "religion":10, \
                            /*** Weapon Skills ***/ \
                            "dagger":7, "sword":8, "axe":10, \
                            "staff":8, "mace":9, \
                            "hammer":9, "bow":11, "gun":12, \
                            "knife":6, "polearm":10, \
                            "whip":10, "flail":11, \
                            /*** Combat Skills ***/ \
                            "dodge":8, "shield":7, "parry":11, \
                            "riposte":14, "find weakness":12, \
                            "dual wield":12, "two-handed":11, \
                            "unarmed":10, "armour":13, \
                            "critical hit":15, \
                            /*** Misc Skills ***/ \
                            "pick lock":10, "prowl":10, \
                            "tumbling":11, "special":0 ])


#define SKILL_NAMES ([ /*** Magic Skills ***/ \
                       "spellcraft":"in ~CACTspellcraft", \
                       "concentration":"at ~CACTcontroling your thoughts", \
                       "faith":"at calling on your ~CACTfaith", \
                       "necromancy":"at ~CACTnecromantic magic", \
                       "thunder":"at ~CACTthunder magic", \
                       "wind":"at ~CACTwind magic", \
                       "earth":"at ~CACTearth magic", \
                       "fire":"at ~CACTfire magic", \
                       "water":"at ~CACTwater magic", \
                       /*** Knowledge Skills ***/ \
                       "alchemy":"in ~CACTalchemy", \
                       "literacy":"in your ~CACTknowledge of the world", \
                       "technology":"in ~CACTthe use of machines", \
                       "religion":"in ~CACTreligious knowledge", \
                       /*** Weapon Skills ***/ \
                       "dagger":"at wielding ~CACTdaggers", \
                       "knife":"at wielding ~CACTknives", \
                       "sword":"at wielding ~CACTswords", \
                       "axe":"at wielding ~CACTaxes", \
                       "polearm":"at wielding ~CACTspears and pole-arms", \
                       "staff":"at wielding ~CACTstaves", \
                       "mace":"at wielding ~CACTclubs and maces", \
                       "hammer":"at wielding ~CACThammers and flails", \
                       "bow":"in ~CACTarchery", \
                       "gun":"in ~CACTgun marksmanship", \
                       "whip":"at wielding ~CACTwhips", \
                       "flail":"at wielding ~CACTflails", \
                       /*** Combat Skills ***/ \
                       "dodge":"at ~CACTdodging blows", \
                       "shield":"at ~CACTblocking attacks with a shield", \
                       "parry":"at ~CACTparrying blows with your weapon", \
                       "riposte":"at ~CACTcountering parried attacks", \
                       "find weakness":"at ~CACTfinding weaknesses in your enemies", \
                       "dual wield":"at ~CACTwielding two weapons at a time", \
                       "two-handed":"at ~CACTwielding a weapon with both hands", \
                       "unarmed":"at ~CACTunarmed combat", \
                       "armour":"at ~CACTmoving in heavy armour", \
                       "critical hit":"at ~CACTdelivering critical blows", \
                       /*** Misc Skills ***/ \
                       "pick lock":"at ~CACTpicking locks", \
                       "prowl":"in ~CACTprowling and backstabbing", \
                       "tumbling":"in ~CACTtumbling and acrobatics" ])

#endif
