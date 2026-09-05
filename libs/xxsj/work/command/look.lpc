// look.c - 查看命令

int main(object me, string arg) {
    object ob, room;
    object *obs;
    int i;
    
    room = environment(me);
    if (!room) {
        write("你在虚空中，什么也看不到。\n");
        return 1;
    }
    
    // 如果没有参数，查看房间
    if (!arg || arg == "" || arg == "here") {
        write(room->query_long());
        return 1;
    }
    
    arg = lower_case(arg);
    
    // 查看自己
    if (arg == "me" || arg == "self") {
        write(me->query_long());
        return 1;
    }
    
    // 查找目标对象
    obs = all_inventory(room);
    for (i = 0; i < sizeof(obs); i++) {
        string target_name = obs[i]->query_name();
        if (target_name && lower_case(target_name) == arg) {
            write(obs[i]->query_long());
            return 1;
        }
    }
    
    write("这里没有这个东西。\n");
    return 1;
}
