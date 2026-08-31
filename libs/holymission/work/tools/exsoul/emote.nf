emo(str) {
object list,player;
int i;
        ghost();
        if (!str) return 0;
        list=users();
	if (this_player()->query_level() > 19) {
        for (i=0; i<sizeof(list); i++) {
                player=list[i];
                if (player && living(player) && !player->query_npc() &&
                        present(player, environment(this_player()))) {
                        tell_object(player, cap_name+ " " +str+"\n");
                }
        }
        return 1;
	} else {
	for (i=0; i<sizeof(list); i++) {
                player=list[i];
                if (player && living(player) && !player->query_npc() &&
                        present(player, environment(this_player()))) {
                        tell_object(player, "_"+cap_name+ " " +str+"_\n");
                }
        }
        return 1;
	}
}
