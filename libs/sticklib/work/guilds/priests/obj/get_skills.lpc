#include "../priest.h"

string name;
int base_skill;
int heal_min_skill;
int heal_maj_skill;
int les_res_skill;
int gre_res_skill;
int invis_skill;
int invuln_skill;

int*
get_skills(string asker) {
    int *temp;
    if(!restore_object(PRIEST_SAVE_DIR "old_alc_skills/"+asker))
	return 0;

    temp = ({ base_skill, heal_min_skill, heal_maj_skill, les_res_skill,
      gre_res_skill, invis_skill, invuln_skill });
    return temp;
}
