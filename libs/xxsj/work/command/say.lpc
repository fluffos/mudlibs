// say.c - 说话命令

int main(object me, string arg) {
    object room;
    string name;
    object *obs;
    int i;
    
    if (!arg || arg == "") {
        write("你想说什么？\n");
        return 1;
    }
    
    room = environment(me);
    if (!room) {
        write("你在虚空中，没有人能听到你说话。\n");
        return 1;
    }
    
    name = me->query_cap_name();
    
    // 向自己显示
    write("你说：" + arg + "\n");
    
    // 向房间内其他人显示
    obs = all_inventory(room);
    for (i = 0; i < sizeof(obs); i++) {
        if (obs[i] != me && obs[i]->is_living()) {
            tell_object(obs[i], name + " 说：" + arg + "\n");
        }
    }
    
    return 1;
}
