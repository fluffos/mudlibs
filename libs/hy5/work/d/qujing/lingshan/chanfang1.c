//crack by stey

inherit ROOM;

void check_zuochan(object me);
void finish(object me);

string chinese_time(int timep);

string *str=({
                "你慢慢物我两忘。\n",
                "你觉得一切胜负荣辱都是过眼云烟。\n",
                "你觉得自己进入了一个前所未有的境界。\n",
                "你的心境渐渐清明。\n"
                "你慢慢地领悟到佛的精髓。\n",
                "你的思绪慢慢宁静下来。\n"
             });

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG
这里空荡荡的，只在靠近墙壁的地方整整齐齐地放着一些蒲团。
房里光线很暗，墙壁不知道是什么材料做的，会发出淡淡的黄
光。这里是坐禅(zuochan)参悟的好地方。你要是实在定不下心
也可以出去走走再回来(halt)。

LONG);

  set("exits", ([
          "south"   : __DIR__"baoge1",
      ]));

  set("no_fight", 1);
  set("no_time",1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("do_zuochan", "zuochan");
    add_action("do_halt", "halt");
}

int do_zuochan()
{       int zuochan_time;

        object me = this_player();

        if (me->query("rulaitask/get"))
             {tell_object(me,"你有任务在身，定不下神来参悟。\n");
              return 1;
             }

        if (me->query_temp("zuochan"))
             {tell_object(me,"你正在坐禅参悟。\n");
              return 1;
             }

        message_vision("$N盘膝坐在一个蒲团上，潜思入定，开始参悟自己的所作所为。\n",me);
        me->set_temp("no_move", 1);
        me->set_temp("zuochan", 1);
        if ( !me->query("rulaitask") )  finish(me);
        else {
                if (me->query("rulaitask/fail"))
                zuochan_time = 30+random(16);
                else zuochan_time = 10+random(16);
                me->set_temp("zuochan_time",zuochan_time);

                check_zuochan(me);
              }

        return 1;
}


void check_zuochan(object me)
{
        int zuochan_time = me->query_temp("zuochan_time");

           if (!me->query_temp("zuochan")) return;

        if ( zuochan_time <= 0 ) finish(me);

        else {
                if ( zuochan_time%6 == 0 )
                      tell_object(me,str[random(sizeof(str))]);
                me->add_temp("zuochan_time", -1);
             me->add_busy(1);
                call_out("check_zuochan",1,me);
              }
}


void finish(object me)
{
        tell_object(me,"你只觉灵台一片清明，似乎禅意已尽。\n");
        message_vision("$N深深地吸了口气，站了起来。\n",me);
        me->delete_temp("no_move");
        me->delete_temp("zuochan");
        me->delete("rulaitask");
        me->set("rulaitaskjob/done",1);
}



int do_halt()
{
        object me = this_player();

          me->add_busy(3);
        if(me->query_temp("last_halt_time") && !wizardp(me) && (me->query_temp("last_halt_time")+20)>time())
        {
                tell_object(me,"等等......\n");
                return 1;
        }
        me->add("jing",-10);
        me->set_temp("last_halt_time",time());
        if (me->query_temp("zuochan"))
        {
//274                  remove_call_out("check_zuochan");
                me->delete_temp("zuochan_time");
                message_vision("$N深深地吸了口气，站了起来。\n",me);
                me->delete_temp("no_move");
                me->delete_temp("zuochan");
                return 1;
        }
        else return 0;
}



string chinese_time(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        return time;
}


