/* 
 * SKILL SAVER
 * This daemon logs players' skills and reports, if something odd
 * happens (player's skills have become lower than they were).
 * Can be used to restore player's skills in such case using the
 * coder command "restore_skills".
 */


#include "../priest.h"

#define SAVE_FILE PRIEST_SAVE_DIR "skill_backup"

// ["name" : coef; save_str]
// where coef is sum of all pexes
mapping data;


void
create() {
    if(!restore_object(SAVE_FILE))
	data = ([]);
}

// decreases player's skills by p%
string
decrease_skills(string save_str, int p) {
    int i, t;
    string *skills, *d;

    d = explode(save_str, "&");
    skills = explode(d[3], "#");
    t = 100 - p;
    for(i=sizeof(skills);--i>=0;)
	skills[i] = to_string(t*to_int(skills[i])/100);
    d[3]= implode(skills, "#") + "#";
    return implode(d, "&");
}

varargs status
save_my_skills(object who, object sym, status resigning) {
    int *pexes, new_coef, old_coef, i;
    string save_str, name;

    name = who->query_real_name();
    save_str = sym->query_guild_save();
    if(resigning) {
	save_str = decrease_skills(save_str, 50); // 50% off
	new_coef = -time();
    }
    else new_coef = sym->query_coef();

    if(!member(data, name)) {
	data += ([name : new_coef; save_str]);
	save_object(SAVE_FILE);
	return 1; // everything is ok.
    }

    if(data[name,0] < 0) return 1;
    // let's not do anything, because we are rejoining the guild

    if(new_coef<data[name, 0] && !resigning) {
	if(who->query_coder_level()) return 0; // no error messages for coders
	// something is wrong, since skills can't be lowered by normal
	// means. Probably player has lost his guild object for a while.
	PRIEST_ERROR(who,sprintf("Skill save string is corrupted. \
new string: %s, old string: %s\n", save_str, data[name,1]));
	who->tell_me("** There's something wrong with your skills. \
If your skills have become lower or cleared, you should report this to a \
guild coder. **\n");
	// hmm... should we automatically restore player's skills
	// using the old save string, if this happens??
	return 0;
    }

    // Everything should be ok...
    data[name, 0] = new_coef;
    data[name, 1] = save_str;
    save_object(SAVE_FILE);
    return 1;
}

varargs status
restore_my_skills(object who, object sym, status joining) {
    string name, save_str;
    int d;

    name = who->query_real_name();
    if(!member(data, name)) {
	if(!joining)
	    notify_fail("That player doesn't have any saved data.\n");
	return 0;
    }
    if(joining) {
	d = time() + data[name, 0];
	d /= 86400; // how many days since resign?
	if(d>50) d = 50; // max 50% off
	data[name,0] = 0;
	save_str = decrease_skills(data[name, 1], d);
    }
    else save_str = data[name, 1];
    sym->restore_skills(save_str);
    return 1;
}

void
remove_player(string name) {
    data -= ([name]);
    save_object(SAVE_FILE);
}

mapping
query_data() { return data; }

string
query_my_data(string name) { return data[name,1]; }

string*
query_priests() { return m_indices(data); }

status
make_skills_valid(string name) {
    object pl;

    if(!member(data,name)) return 0;
    if(pl = find_player(name))
	data[name,0] = pl->query_guild_object()->query_coef();
    else data[name,0] = 0;
    save_object(SAVE_FILE);
    return 1;
}

int
query_coef(string name) { return data[name, 0]; }


void
debug() {
    printf("%O", data);
}
