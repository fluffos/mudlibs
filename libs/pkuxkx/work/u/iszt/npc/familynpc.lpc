// File         : xiaoer2.c
// Created By   : iszt@pkuxkx, 2007-03-22

inherit NPC;
#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("测试用NPC", "test npc");
        set_name("店小二", ({ "xiao er", "xiao", "er", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ({
                __DIR__"obj/food_meixue",
                __DIR__"obj/food_sanxian",
                __DIR__"obj/food_hanmo",
                "/clone/food/mifan",
                "/clone/food/mantou",
                "/clone/food/baozi",
        }));
        add("inquiry", ([
                "name" : "不敢不敢，您就叫我小二吧。\n",
                "here" : "冰雪楼的名号在凌霄城可是响当当的，客官您不来点啥？\n",
                "rumors" : "莫谈国事，莫谈国事。\n",
                "武功" : "大侠您可千万别搞错了，小的不会武功。\n",
                "剑法" : "大侠您可千万别搞错了，小的不会武功。\n",
                "雪山剑法" : "大侠您可千万别搞错了，小的不会武功。\n",
                "雪山三鲜" : "这是凌霄城独有的美食，"YEL"野狼肉、"CYN"山鸡骨、"RED"獐子血"NOR"煮到一起，鲜味扑鼻，嚼起来更是美味！\n",
                "梅雪飘香" : "梅雪飘香本是一套轻功身法，用于它倒也恰如其分：雪山融水炖梅子，此梅虽非彼梅，尝起却甚是美味。\n",
                "寒蘑肉片" : "寒蘑肉片中的"HIG"寒蘑"NOR"，取自凌霄城外二十余里的雪地中，甚是珍贵，味道自然也绝佳。\n",
        ]));
        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_set", "setnpc");
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id"))
        {
                tell_object(who, "小二一哈腰，说道：「多谢您老赏钱，欢迎下次再来。」\n");
                return 1;
        }

        return 0;
}

int do_set(string arg)
{
        if(!arg)
                arg = "random";
        "/u/whuan/familyd"->family_skill(this_object(), arg, 400, 1);
        return 1;
}
