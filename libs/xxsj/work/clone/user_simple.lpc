// user_simple.c - 简化的玩家对象用于测试

string name;

void create() {
    seteuid(getuid());
}

void logon() {
    write("=== 简化测试版本 ===\n");
    write("请输入你的名字: ");
    input_to("get_name");
}

void get_name(string str) {
    if (!str || str == "") {
        write("名字不能为空！\n");
        write("请输入你的名字: ");
        input_to("get_name");
        return;
    }
    
    name = str;
    write("欢迎，" + name + "！\n");
    write("输入任何内容测试...\n");
    write("> ");
}

void receive(string str) {
    write("*** 收到输入: [" + str + "] ***\n");
    write("输入长度: " + strlen(str) + "\n");
    
    if (str == "quit") {
        write("再见！\n");
        destruct(this_object());
        return;
    }
    
    write("你输入了: " + str + "\n");
    write("> ");
}

// FluffOS 使用 process_input 而不是 receive
void process_input(string str) {
    receive(str);
}

string query_name() {
    return name;
}

int is_living() {
    return 1;
}
