// who.c - 在线玩家列表

int main(object me, string arg) {
    object *user_list;
    int i, count;
    string output;
    
    user_list = users();
    count = sizeof(user_list);
    
    output = "\n========================================\n";
    output += "  在线玩家列表 (" + count + " 人)\n";
    output += "========================================\n\n";
    
    if (count == 0) {
        output += "  目前没有玩家在线。\n";
    } else {
        for (i = 0; i < count; i++) {
            string player_name = user_list[i]->query_cap_name();
            if (player_name) {
                output += "  " + player_name;
                if (user_list[i] == me) {
                    output += " (你)";
                }
                output += "\n";
            }
        }
    }
    
    output += "\n========================================\n";
    write(output);
    
    return 1;
}
