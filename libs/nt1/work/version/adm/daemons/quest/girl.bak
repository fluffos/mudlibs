// 玩家任务守护进程：girl.c

#include <ansi.h>

void startup();

// 任务对象创建
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
        object env;             // 接收物品的NPC所在的环境
        object npc;             // 接收物品的NPC对象
        object *obs;            // 目前所有的SUPPLY任务
        string *env_room;       // 新任务能够在的地点
        string room;            // NPC所在的环境文件名字
        string sob_file;        // 接收的物品对应的文件

        object qob;             // 任务对象

        // 选择一个新的地点(目前没有SUPPLY任务的)
        env_room = keys(rcv_npcs);
        obs = children("/clone/quest/supply");
        if (arrayp(obs) && sizeof(obs) > 0)
                env_room -= obs->query("quest_position");

        if (sizeof(env_room) < 1)
                // 无法找到这样的地点
                return;

        room = env_room[random(sizeof(env_room))];
        env = get_object(room);

        // 选择改地点中的人
        if (! objectp(npc = present(rcv_npcs[room], env)) ||
            npc->query("startroom") != base_name(env))
                // 无法找到该地点中合适的NPC来接收
                return;


        // 选择一种兵器
        sob_file = supply_objs[random(sizeof(supply_objs))];

        // 初始化任务的一些信息（启动地点）
        qob = new("/clone/quest/supply");
        qob->set("quest_position", room);

        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "进程(SUPPLY)在" + env->short(1) +
                              HIR "地点利用" + npc->name() +
                              HIR "创建了一个任务。");

        // 交由任务自己进行初始化
        qob->init_quest(npc, sob_file);
}

private void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // 如果可以，每次心跳产生一个QUEST
        start_quest();
}

// 任务守护进程唤醒这个进程
void startup()
{
        // 启动
        if (! find_object(QUEST_D))
                return;

        if (! query_heart_beat())
                CHANNEL_D->do_channel(find_object(QUEST_D),
                                      "sys", "进程(SUPPLY)启动了。");

        // 平均每四分钟产生一个任务
        set_heart_beat(110 + random(20));
}

// 停止这个任务进程
void stop()
{
        set_heart_beat(0);
}
