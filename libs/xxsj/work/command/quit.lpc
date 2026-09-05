// quit.c - 退出命令

int main(object me, string arg) {
    write("\n你确定要退出游戏吗？(yes/no): ");
    input_to("confirm_quit", me);
    return 1;
}

void confirm_quit(string str, object me) {
    if (!str) str = "";
    str = lower_case(trim(str));
    
    if (str == "yes" || str == "y" || str == "是") {
        me->quit();
    } else {
        write("取消退出。\n");
        write("> ");
    }
}
