/* this function starts a monster or a group of monsters in a random
 * place in an area based on what parameters are passed.
 * /global/move_around.doc explains how to use the function and 
 * /global/move_around_ex.c is an example of how to use the function
 * Raskolnikov Nov 96
 */

void create() {
    seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
}

/* params passed:
 * monsie: path to monster
 * num_in_group: number of monsie in each group
 * groups: total number of groups
 * rooms: rooms to choose from
 * env: path(s) of the jump room(s)
 */

void move_around(string monsie, int num_in_group, int groups,
  string *rooms, string *env) {

    int i, j, tot_num, counter, num_to_clone, groups_to_clone, left_over;
    string room, *exp_path, imp_path;
    mixed monsie_env;
    object *monsies;

    counter = 0;
    /** get all the monsies currently loaded **/
    monsies = children(monsie);
    /** if there are children of the monsie file see if they are in **/
    /** the same path as the "jump room" **/
    if(sizeof(monsies) > 1) {
	for(i=0;i<sizeof(monsies);i++) {
	    monsie_env = environment(monsies[i]);
	    if(monsie_env) {
		monsie_env = file_name(environment(monsies[i]));
		exp_path = explode(monsie_env, "/");
		exp_path -= ({ exp_path[sizeof(exp_path) - 1] });
		imp_path = implode(exp_path, "/");
		/** if the path that the monsie is in is the **/
		/** same as the path passed then add to the total **/
		/** currently cloned in the path in question **/
		if(member_array(imp_path, env) != -1)
		    counter += 1;
	    }
	}
    }
    /** see how many could be cloned **/
    tot_num = num_in_group * groups;
    /** see how many need to be cloned **/
    num_to_clone = tot_num - counter;
    /** split that up into groups and left overs (ie not enough **/
    /** to make a whole group) **/
    groups_to_clone = num_to_clone / num_in_group;
    left_over = num_to_clone % num_in_group;
    /** clone em **/
    for(i=0;i<groups_to_clone;i++) {
	room = rooms[random(sizeof(rooms))];
	/** dont stick more than one group in each room **/
	rooms -= ({ rooms[member_array(room, rooms)] });
	for(j=0;j<num_in_group;j++) {
	    load_object(room);
	    clone_object(monsie)->move(room);
	}
    }
    /** clone the left overs **/
    room = rooms[random(sizeof(rooms))];
    for(i=0;i<left_over;i++) {
	load_object(room);
	clone_object(monsie)->move(room);
    }
}
