inherit ROOM;
#include <ansi.h>

int do_move();

int do_vote(string arg);
void create()
{
        set("short", "^@_@~");
        set("long", @LONG
LONG);

        set("item_desc", ([
        ]));
        set("exits", ([
                "down" : "/d/city/guangchang",
        ]));
        set("objects", ([
"/d/city/npc/tian": 1,
"/kungfu/class/huashan/yueling": 1,
"/d/dali/npc/duanyu": 1,
"/kungfu/class/xingxiu/li": 1,
"/kungfu/class/wudang/zhang": 1,
"/kungfu/class/shaolin/damo": 1,
"/kungfu/class/huashan/linghu": 1,
"/kungfu/class/huashan/yue": 1,
"/kungfu/class/huashan/ning": 1,
"/kungfu/class/mingjiao/zhang": 1,
"/kungfu/class/gumu/yang": 1,
"/d/pker/npc/langhuitou": 1,
"/d/pingxiwangfu/npc/wusangui": 1,
"/kungfu/class/gaibang/hong": 1,
"/d/quanzhou/npc/limochou": 1,
"/kungfu/class/taohua/huang": 1,
"/d/taohuadao/npc/gu": 1,
"/d/taohuadao/npc/fu": 1,
"/kungfu/class/gumu/longer": 1,
"/d/dali/yideng/npc/yu": 1,
"/d/dali/yideng/npc/qiu": 1,
"/d/guiyunzhuang/npc/chairen": 1,
"/d/city/npc/zhu": 1,
"/d/riyuejiao/npc/nongfu": 1,
"/d/dali/yideng/npc/yinggu": 1,
"/kungfu/class/shaolin/tuoboseng": 1,
"/d/city/npc/linpingzhi": 1,
"/kungfu/class/lingjiu/xuzhu": 1,
"/kungfu/class/murong/murongfu": 1,
"/d/emei/houshan/npc/miejue": 1,
"/kungfu/class/riyuejiao/xiang": 1,
"/kungfu/class/btshan/ouyangke": 1,
"/kungfu/class/quanzhen/wang": 1,
"/kungfu/class/shenlong/lu": 1,
"/kungfu/class/dalunsi/jiumozhi": 1,
"/d/xiangyang/npc/guojing": 1,
        ]));

        setup();
}
void init()
{
        add_action("do_move", "move");
        add_action("do_vote", "vote");
}
int do_move()
{
        object *ob;
        int i, skill, damage;
        object me=this_player();    
        if ((string)me->query("id")!="whuan")
        	return 0;

       message_vision(
       HIY "无欢披发仗剑，手指苍天，只听雷声大作，一阵黑风卷过！”\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
    tell_object(ob[i], "你觉得眼前一黑，仿佛看到一片金星……\n");
    ob[i]->move("/d/city/rbz");
        }


        return 1;
}

int do_vote(string arg)
{
        object *ob;
        int i, skill, damage;
        object me=this_player();    
        if ((string)me->query("id")!="whuan")
                return 0;

       message_vision(
       HIY "无欢大喝一声，天灵灵，地灵灵！\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
             if( !living(ob[i]) || ob[i]==me ) continue;
//             ob[i]->command_function("vote chblk "+arg);
             ob[i]->command("hi");
        }
        return 1;
}
