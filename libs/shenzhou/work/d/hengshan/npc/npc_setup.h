//Cracked by Roath
#ifndef _NPC_SETUP_H_
#define _NPC_SETUP_H_

nosave string *menpai_list = ({
    "huashan", "shaolin", "wudang", "emei", "gaibang",
    "baituo", "hengshan","songshan","taohua","xueshan", "xingxiu" });


// sets full status (qi, jing, neili, jingli) according to level
void set_hp(int level,object ob);

// random menpai if parameter "menpai" given is 0
// return the menpai this npc has been assigned to
// sets "default_weapon" attribute
string set_skills(string menpai, int exp, int skill_rate,object ob);
#endif
