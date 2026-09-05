//choujiang     抽奖处
// By icer

#include <ansi.h>
inherit ROOM;

void init()
{
        add_action("stop","yun");
        add_action("stop","exert");
        add_action("stop","perform");
        add_action("stop","yong");
        add_action("stop","hit");
        add_action("stop","hitall");
        add_action("stop","fight");
        add_action("do_cj","choujiang");
}
void create()
{
        set("short", "劳动节大抽奖");
        set("long", @LONG
这里是游乐场里抽奖(choujiang)的地方，15岁以上（包括15岁）的人
都可以参加，每人限抽一次，奖品多多，不想试试？
LONG
        );

        set("exits", ([
                  "south" : __DIR__"duchang",
        ]));

        setup();
}

int stop()
{
        write("来这里是为了庆祝五一，干吗动武呀？\n");
         return 1;
}
int do_cj()
{
        object me;
        
        me = this_player();
         if (me->query("age")<15)
             return notify_fail("你年纪还小，不要抽了。\n");
        if (me->query("gift/200851") == 1)
                return notify_fail("抽过就不要再抽了。\n");
        switch (random(80))
        {
                case 0:
                  write(HIR + "恭喜你！抽中了大奖－最大精力300点！\n" + NOR);
                  CHANNEL_D->do_channel(this_object(),"rumor","听说" + me->query("name") + "抽中了大奖－最大精力300点！\n");
                  me->add("max_jingli",300);
                  break;
                case 1:
                  write(HIR + "恭喜你！抽中了大奖－最大内力300点！\n" + NOR);
                  CHANNEL_D->do_channel(this_object(),"rumor","听说" + me->query("name") + "抽中了大奖－最大内力300点！\n");
                  me->add("max_neili",300);
                  break;
                case 2:
                  write(HIR + "恭喜你！抽中了大奖－经验50000点！\n" + NOR);
                  CHANNEL_D->do_channel(this_object(),"rumor","听说" + me->query("name") + "抽中了大奖－经验50000点！\n");
                  me->add("combat_exp",50000);
                  break;
                case 3:
                  write(HIR + "恭喜你！抽中了大奖－年龄减两岁！猪你越活越年轻！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－年龄减两岁！\n"+ NOR);
                  me->add("mud_age",-172800);
                  break;
                case 4:
                  write(HIR + "恭喜你！抽中了大奖－膂力加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－膂力加5点！\n"+ NOR);
                  me->add("xiantian/str/200651",5);
                  me->add("str",5);
                  break;
                default:
                  write(HIG + "恭喜你！你的最大内力和最大精力各增加了100点！\n" + NOR);
                  CHANNEL_D->do_channel(this_object(),"rumor","听说" + me->query("name") + "抽中了大奖－最大内力和最大精力各增加了100点！\n");
                  me->add("max_jingli",100);
                  me->add("max_neili",100);
        }
        me->set("gift/200851",1);
        write(HIR + BNK + "注意：这里的抽奖与隔壁的彩票没有关系，彩票中奖号码将在节后公布，到时候带着彩票去彩票屋打duijiang会自动兑奖！\n"NOR);
        return 1;
}
        


