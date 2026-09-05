//忘忧亭
//by male
// Modified by iszt@pkuxkx, 2007-03-26

#include <ansi.h>

inherit ROOM;

void sing1(object me);
void sing2(object me);
void meet(object me);
void give_shui(object me);

void create()
{
        set("short", HIW"忘忧亭"NOR);
        set("long", @LONG
忘忧亭相传是西汉年间一高人所修，现在由于年代久远已经破败不堪。传说
福缘高和有恒心的人在此亭还会偶尔遇到那位高人，不过此话也不足为信，都只
是一笑置之罢了。在亭边有一副对联(duilian)，需要仔细辨认(read)才能看清。
LONG);
        set("exits", ([
                "north" : __DIR__"xiaodao5",
        ]));
        set("shui",1);
        setup();
}

void init()
{
        add_action("do_read","read");
}

int do_read(string arg)
{
        object me = this_player();
        if(!arg || arg!="duilian")
        {
                write(HIY"你要看什么?\n");
                return 1;
        }
        write(MAG"上面写着：「世间本无事 庸人自扰之」\n"NOR);
        if(!this_object()->query("shui"))
                return 1;
        if(me->query("shen")<10)
                return 1;
        if(!me->query_temp("havemet")) 
        {
                me->set_temp("havemet",1);
                me->set_temp("meettime",0);
        }
        me->add_temp("meettime",1);
        if((me->query("kar")>30 && me->query("shaqi")>10)
                || (me->query("shaqi")>10 && me->query_temp("meettime")>10+random(10)))
        {
                me->start_busy(100);
                add("shui", -1);
                message_vision(HIY"$N正看的时候，突然听见有歌声传来：
问世间情是何物，只教人生死相许
天南地北双飞客，老翅几回寒暑......\n"NOR,me);
                call_out("sing1",6,me);
                return 1;
        }
        return 1;
}

void sing1(object me)
{
        message_vision(HIY"\n\n\n欢乐趣，离别苦，就中更有痴儿女......\n"NOR,me);
        call_out("sing2", 6, me);
        return;
}

void sing2(object me)
{
        message_vision(HIY"\n\n\n君应有语，藐万里尘云，千山暮雪，只影向谁去？......\n"NOR,me);
        call_out("meet",6,me);
        return;
}

void meet(object me)
{
        message_vision(HIY"\n\n\n$N正在奇怪，突然发现身边已多了一位身穿白色素装的女子，歌声正是由她发出来的。\n"NOR,me);
        message_vision(HIY"\n\n这名女子虽然身着素妆，但是亦是美艳不可方物，$N不禁看得痴了......\n"NOR,me);
        call_out("give_shui",6,me);
        return;
}

void give_shui(object me)
{
        object shui;
        message_vision(HIY"\n\n这名女子本在眉宇之间有一丝忧郁之气，"
                "但见$N看那她痴痴入神的神情不禁嫣然一笑。\n"NOR,me);
        message_vision(HIB"\n\n白衣女子停下歌来，对$N说道：「你我今日一见也算有缘，"
                "看你脸上有股杀气，这瓶"+HIW"忘忧水"+HIB"会对你有所帮助。」\n"NOR,me);
        message_vision(HIB"\n话音刚落，$N还没来得及说话，白衣女子已飘然而去了。\n"
                "这时$N才发现自己手中已多了一个小瓷瓶，还微微带着白衣女子的体温。\n"NOR,me);
        me->set_temp("meettime",0);
        shui=load_object(__DIR__"obj/wangyoushui");
        shui->move(me);
        me->start_busy(1);
        return;
}
