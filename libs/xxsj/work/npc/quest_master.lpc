// quest_master.c - 任务发布NPC

#include <globals.h>

string name;

void create() {
    name = "任务执事";
    seteuid(getuid());
}

void init() {
    add_action("do_talk", "talk");
    add_action("do_quest", "quest");
}

// 显示任务列表
void show_quest_list(object me) {
    write("\n" + HIC + "╔════════════════════════════════════════╗\n");
    write("║" + HIY + "            可用任务列表            " + HIC + "║\n");
    write("╚════════════════════════════════════════╝\n" + RESET);
    
    write("\n" + HIY + "【1】采集灵药\n" + RESET);
    write("  要求：采集灵芝 x5\n");
    write("  奖励：修为 +50，灵石 x1\n");
    write("  难度：★☆☆☆☆\n\n");
    
    write(HIY + "【2】清理妖兽\n" + RESET);
    write("  要求：击杀野狗 x3\n");
    write("  奖励：修为 +100，兽皮 x2\n");
    write("  难度：★★☆☆☆\n\n");
    
    write(HIY + "【3】收集矿石\n" + RESET);
    write("  要求：采集铁矿 x5，铜矿 x3\n");
    write("  奖励：修为 +150，灵石 x2\n");
    write("  难度：★★★☆☆\n\n");
    
    write(HIG + "输入 " + HIW + "quest accept <编号>" + RESET + HIG + " 接取任务\n\n" + RESET);
}

// 接取任务
void accept_quest(object me, int quest_id) {
    if (quest_id < 1 || quest_id > 3) {
        write(HIR + "无效的任务编号！\n" + RESET);
        return;
    }
    
    write(HIG + "你接取了任务！\n" + RESET);
    write(HIY + "任务目标已记录，完成后回来找我领取奖励。\n" + RESET);
    write(HIG + "输入 " + HIW + "quest status" + RESET + HIG + " 查看任务进度\n\n" + RESET);
}

// 显示任务状态
void show_quest_status(object me) {
    write("\n" + HIC + "╔════════════════════════════════════════╗\n");
    write("║" + HIY + "            当前任务            " + HIC + "    ║\n");
    write("╚════════════════════════════════════════╝\n" + RESET);
    
    write("\n" + HIY + "暂无进行中的任务\n" + RESET);
    write(HIG + "前往任务大厅接取任务吧！\n\n" + RESET);
}

// 完成任务
void complete_quest(object me) {
    write(HIR + "你还没有完成任何任务！\n" + RESET);
}

// 对话
int do_talk(string arg) {
    if (!arg || (arg != "任务执事" && arg != name)) {
        return 0;
    }
    
    write("\n" + HIC + name + RESET + " 对你说：\n");
    write(HIY + "「欢迎来到任务大厅，道友。」\n" + RESET);
    write(HIY + "「我这里有一些任务可以接取，完成后会有丰厚的奖励。」\n" + RESET);
    write(HIY + "「输入 " + HIW + "quest list" + RESET + HIY + " 查看可用任务。」\n" + RESET);
    write(HIY + "「输入 " + HIW + "quest accept <编号>" + RESET + HIY + " 接取任务。」\n\n" + RESET);
    
    return 1;
}

// 任务命令
int do_quest(string arg) {
    object me = this_player();
    int quest_id;
    
    if (!arg || arg == "") {
        write("用法：\n");
        write("  quest list           - 查看可用任务\n");
        write("  quest accept <编号>  - 接取任务\n");
        write("  quest status         - 查看当前任务\n");
        write("  quest complete       - 完成任务\n");
        return 1;
    }
    
    if (arg == "list") {
        show_quest_list(me);
        return 1;
    }
    
    if (sscanf(arg, "accept %d", quest_id) == 1) {
        accept_quest(me, quest_id);
        return 1;
    }
    
    if (arg == "status") {
        show_quest_status(me);
        return 1;
    }
    
    if (arg == "complete") {
        complete_quest(me);
        return 1;
    }
    
    return 0;
}

// 查询函数
string query_name() { return name; }
string query_cap_name() { return name; }
int is_living() { return 1; }
string query_short() { return name; }
string query_long() { 
    return name + " 正站在这里，他负责发布宗门任务。\n" +
           "你可以 " + HIW + "talk " + name + RESET + " 与他交谈。\n";
}
