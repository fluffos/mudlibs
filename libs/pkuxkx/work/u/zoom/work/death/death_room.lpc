// Death judge room
// By freecv
// 2007-4-19

#include <ansi.h>
inherit ROOM;

int do_quit(); 
int do_choose(string);
int do_food();
int do_shout();
int do_fine();
int get_answer(string);

void create()
{
        set("short", "xx山xx洞xx刑堂");
        set("long", @LONG
LONG
        );
        set("no_die", 1);
        set("no_sleep", 1);     
        setup();
}

void init()
{       
        object me = this_player();
        string msg = "\n慢慢的你醒了过来，发现自己身被绑在铜柱上。昏沉的灯光下，你什么都看不清.\n这时候，忽然一个人走上前来。\n";
        message_vision(msg, me);
        
        msg = "\n小子，这次你载了倒是服也不服? 本打算一刀砍了你，不过算你命大，居然被我们\n头看见了。";
        msg += "特地差我来问你，你是认打啊还是认罚，再不成爷爷心情好顺手给你个\n痛快也可以。(choose)\n";

//        if( !me || environment(me) != environment() || !userp(me)) return;
        message_vision(msg, me);
        me->set_temp("death/choose",1);

        if (!wizardp(this_player())){ 
                me->set("startroom", "/u/zoom/work/death/death_room");
                add_action("do_none",({"lian","study","xue","learn","dazuo","tuna","exercise","apprentice","du","research","dz","read","practice",}));
                add_action("do_choose","choose");
                add_action("do_food", "food");
                add_action("do_shout", "shout");
                add_action("get_answer", "answer");
                add_action("do_quit", "quit");           
        }
}

int do_quit()
{
        this_player()->force_me("quit");
        return 1;
}

void greeting(object me)
{
}

int do_none()
{
        write("你被绑在柱子上，什么都干不了。\n");
        return 1;       
}

int do_choose(string arg)
{
        object me = this_player();
        string answer;
        
        if (me->query_temp("death/choose") != 1)
        {
                write("什么？\n");
                return 1;
        }

        if (arg!="fine" && arg!="punish" && arg!="death")
        {
                write("小子，你耍我呢? \n");
                write("到底是认打（choose punish)认罚(choose fine)还是想死(choose death) ? \n");
                return 1;
        }
        
        me->delete_temp("death");
        
        if (arg == "fine")
        {
                int ticket = 5000;
                string msg = "Fine ? Fine ! 小子不错，有前途， 有钱能使磨推鬼，更别提人了。恩，什么时候凑够钱了,\n";
                msg += "让你家属给你帐上转个上"+ticket+"两金子来给我们花差花差吧.\n\n";
                msg += "银子到前亏不了你，好吃好喝招待着，不过如果你敢晃点我们。哼哼哼哼。。。。。。\n";
                msg += "如此这样你可愿意？(yes/no)\n";
                message_vision(msg, me);
                me->set_temp("death/fine", ticket);
        }
        else if (arg == "punish")   
        {
                write("认打的话，打傻，打笨， 打残废了你可不要抱怨。要知道这鞭子一轮，什么下场就可以说不准了。\n");
                write("你可愿意赌赌运气，看看你能不能让我家老板打的开心放了你？(yes/no)\n");
                me->set_temp("death/punish", 1);
        }            
        else if (arg == "death")
        {
                write("你有种。待我上报老板，挑个良辰吉日送你上路。\n");
                write("骨头挺硬。。。倒让我有些犹豫，再问你次。\n");
                write("你当真宁死不屈？(yes/no)\n");
                me->set_temp("death/death", 1);
        }
        
        input_to( (:get_answer:) );
        return 1;
}

int get_answer(string arg)
{
        string msg;
        object dest_room;
        
        if (arg == "yes")
        {
                if (this_player()->query_temp("death/fine") > 0)
                        call_out("do_fine", 1, this_player());
                else if (this_player()->query_temp("death/punish") > 0)
                {
                        dest_room = new(__DIR__"punish");
                        this_player()->move(dest_room);
                }
                else
                {
                        dest_room = new(__DIR__"death");
                        this_player()->move(dest_room);
                }
        }
        else if (arg == "no")
        {
                this_player()->set_temp("death/choose", 1);
                do_choose("haha");
        }
        else
        {
                write("yes ? no ? 你可愿意？\n");
                input_to( (:get_answer:) );
        }
        return 1;
}

int do_food()
{
        object me = this_player();
        
        if ( !me->query_temp("death/fine") )
        {
                write("什么?\n");
                return 1;
        }
        
        if (me->is_busy())
                notify_fail("你刚吃完东西，消化消化再吃吧。");
                
        write("你大喊一声\"快把好吃好喝的给我"+RANK_D->query_respect(me)+"摆上来。\"\n");
        write("顿时无数珍馐佳肴摆在了你面前，你开始胡吃海塞......\n");
        write("一会时间，你吃饱喝足了。\n");
        
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        me->start_busy(5 + random(10));
        return 1;
}

int do_shout()
{
        object me = this_player();
        int money = me->query("balance");
        int factor = random(3);
        string msg = "看来不给你些厉害你是不知道马王爷有几只眼了。罚金加上" + factor + "倍.\n";

        factor++;
        if ( !me->query_temp("death/fine") )
        {
                write("什么？\n");
                return 1;
        }
        
        write("你大喊一声\"快放人啦，有没有信誉啊，我这钱已经到帐了，密码是*******,快放我出去!!\"\n");
        
        if (money >= me->query("death/fine")*10000)
        {
                write("一个丫头立刻走上来对你一个万福，然后立马给你解开了绳子松了绑.\n");
                me->set("balance", money - me->query("death/fine")*10000);
                me->delete("death/fine");
                me->set("start_room", "/d/city/kedian");
                me->move("/d/city/kedian");
                me->delete_temp("death");
                write("你刚问这个丫头的姓名，年龄，却被她一脚踢飞，脚踏实地时居然已到扬州客栈。\n");
        }
        else
        {
                write("只见一个蒙面大汉眼露凶光的看着你，叫鬼叫啊，居然晃点我，让老子觉都睡不好。、\n");
                write(msg);
                me->set("balance", money * factor);
        }
        
        return 1;       
}

int do_fine()
{

        write("对了，差点忘了告诉你，钱到帐了就shout.我们听见声看见钱对了转完帐就放走你。老老\n");
        write("实实的，别耍花样。之前你就在这转悠吧，除了不能松绑，想吃想喝了就想想food。说了不亏着你...\n");

        return 1;       
}
