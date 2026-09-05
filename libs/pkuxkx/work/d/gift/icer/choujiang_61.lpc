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
        set("short", "儿童节大抽奖");
        set("long", @LONG
这里是游乐场里抽奖(choujiang)的地方，mudage在5个小时以上，
都可以参加，每人限抽一次，奖品多多，不想试试？
LONG
        );

        set("exits", ([
                  "northwest" : "/d/city/guangchang",
        ]));

        setup();
}

int stop()
{
        write("来这里是为了庆祝六一，干吗动武呀？\n");
         return 1;
}
int do_cj()
{
        object me;
        
        me = this_player();
/*
         if (me->query("age")>100)
             return notify_fail("拜托！是儿童节好不好？\n");
*/
         if (me->query("mud_age")<21600)
             return notify_fail("你这个儿童也太小了吧，过几天再来吧？\n");
        if (me->query("gift/200761") == 1)
                return notify_fail("抽过就不要再抽了。\n");
        switch (random(200))
        {
                case 0:
                  write(HIR + "恭喜你！抽中了大奖－最大精力300点！\n" + NOR);
                  me->add("max_jingli",300);
                  break;
                case 1:
                  write(HIR + "恭喜你！抽中了大奖－最大内力300点！\n" + NOR);
                  me->add("max_neili",300);
                  break;
                case 2:
                  write(HIR + "恭喜你！抽中了大奖－经验50000点！\n" + NOR);
                  me->add("combat_exp",250000);
                  break;
                case 3:
                  write(HIR + "恭喜你！抽中了大奖－年龄减两岁！猪你越活越年轻！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－年龄减两岁！\n"+ NOR);
                  me->add("mud_age",-172800);
                  break;
                case 4:
                  write(HIR + "恭喜你！抽中了大奖－膂力加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－膂力加5点！\n"+ NOR);
                  me->add("xiantian/str/200761",5);
                  me->add("str",5);
                  break;
                case 5:
                  write(HIR + "恭喜你！抽中了大奖－悟性加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－悟性加5点！\n"+ NOR);
                  me->add("xiantian/int/200761",5);
                  me->add("int",5);
                  break;
                 case 6:
                  write(HIR + "恭喜你！抽中了大奖－根骨加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－根骨加5点！\n"+ NOR);
                  me->add("xiantian/con/200761",5);
                  me->add("int",5);  
                  break;
                 case 7:
                  write(HIR + "恭喜你！抽中了大奖－身法加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－身法加5点！\n"+ NOR);
                  me->add("xiantian/con/200761",5);
                  me->add("dex",5); 
                  break; 
                 case 7:
                  write(HIR + "恭喜你！抽中了大奖－灵性加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－灵性加5点！\n"+ NOR);
                  me->add("xiantian/spi/200761",5);
                  me->add("spi",5); 
                  break;
                 case 8:
                  write(HIR + "恭喜你！抽中了大奖－容貌加10点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－容貌加10点！\n"+ NOR);
                  me->add("xiantian/per/200761",10);
                  me->add("per",10);                    
                  break;
                 case 9:
                  write(HIR + "恭喜你！抽中了大奖－福缘加5点！\n" + NOR);
                  shout(HIR + me->query("name") + "抽中了大奖－福缘加5点！\n"+ NOR);
                  me->add("xiantian/kar/200761",5);
                  me->add("kar",5); 
                  break; 
                default:
                  write(HIG + "恭喜你！你的最大内力和最大精力各增加了100点！\n" + NOR);
                  me->add("max_jingli",100);
                  me->add("max_neili",100);
        }
        me->set("gift/200761",1);
        return 1;
}
  
