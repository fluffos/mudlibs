#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIW"仙鹤"NOR, ({ "xian he", "he" }) );
        set("race", "野兽");
        set("age", 100);
        set("long", "一只年过百岁的仙鹤，你可以试着骑(qi)上去.\n");
        set("attitude", "peaceful");
        set("spi",100);
        set("int",100);
        set("per",100);
        set("con",100);
        set("limbs", ({ "头部", "身体", "翅膀" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 110);
        set_temp("apply/armor", 110);
        set_temp("apply/defence",90);

        setup();
}
void die()
{
        object ob,me;
me = this_player();
        message_vision("$N嘶哑的叫了几声，倒在地上死了。。。\n 一道白光闪过，一撮美丽的羽毛飘落在$N的身上。。\n\n", this_object(),me);
        ob = new("/d/hainan/obj/yumao");
        ob->move(me);
        destruct(this_object());
}
void init()
{
        add_action("do_xia","xia");
        add_action("do_qi","qi");

}
int do_qi(string arg)
{
        object me;
        int extra;
        me = this_player();
        if (arg = "仙鹤" && arg = "xian he" && arg = "he")
        {
                extra = me->query_skill("dodge",1);
                if (extra < 100) return notify_fail("你的轻功还不够熟练。\n");
                if (me->query_temp("mark/qi1")) return notify_fail("你还要骑到仙鹤脑袋上去？\n");
                message_vision(HIW"只见$N轻轻跃上了仙鹤的后背，仙鹤载着$N飞上了天空。。。\n\n\n"NOR,me);
                set("long","一只年过百岁的仙鹤，有个人正坐在它背上.\n");
                me->set_temp("mark/qi1",1);
                me->set_temp("mark/tiankong",1);
                me->move("/d/hainan/kongzhong");
                this_object()->move("/d/hainan/kongzhong");
                return 1;
        }
}

int do_xia(string arg)
{
        object me;
        me = this_player();
        if (arg != "仙鹤" && arg != "xian he" && arg != "he") 
                return notify_fail("你要下哪去？\n");
        if (!me->query_temp("mark/qi1")) return notify_fail("你要下哪？地狱？\n");
        if (me->query_temp("mark/tiankong"))
        {
                message_vision(HIR"$N跳下了仙鹤，翻滚着从空中掉了下去。.....\n\n\n"NOR,me);
                me->die();
                message("channel:rumor",YEL"【谣言】某人：发生空难，死亡一人！\n"NOR,users());
                destruct(this_object());
        }
        else
        {
                message_vision("只见$N轻轻一跃，跳下了仙鹤。\n",me);
                set("long","一只年过百岁的仙鹤，你可以试着骑(qi)上去.\n");
                me->delete_temp("mark/qi1",);
        }
        return 1;
}
