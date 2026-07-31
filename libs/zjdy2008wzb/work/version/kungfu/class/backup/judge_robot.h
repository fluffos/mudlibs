// SN:_QYFoI\T4QEZK]@0
// judge_robot.c
// Create by Chenzzz@HELL.RV
// 判断机器人（简单回答）
#include <ansi.h>;
#include <npc/chinese.lpc>
#include "charcode.h";  // 字符编码文件
// 外部方法
mixed do_ask();
mixed do_cancel();
mixed do_answer(string arg);
// 内部方法
mixed do_ask_char();
// 提问
mixed do_ask()
{
        object me = this_player();

        if (me->is_busy())
                return "你正忙着呢！";

        if (! undefinedp(me->query_temp("robot_judge/answer")))
        {
                me->start_busy(2);
                return "你已经收到问题了，请尽早回答。";
        }

        return do_ask_char();
}
// 回答
mixed do_answer(string arg)
{
        object me = this_player();
        string str_answer = me->query_temp("robot_judge/answer");

        if (!arg)
        {
                tell_object(me, "你要回答什么？\n");
                return 1;
        }
        if (me->is_busy())
        {
                tell_object(me, "你正忙着呢！\n");
                return 1;
        }
        if (undefinedp(me->query_temp("robot_judge/answer")))
        {
                tell_object(me, "没有人向你提问啊。\n");
                return 1;
        }
        if (me->query_temp("robot_judge/time") < time())
        {
                tell_object(me, "已经超过三分钟的回答时间了，下次你要快一点回答。\n");
                return 1;
        }
        if (arg == str_answer)
        {
                message_vision("$N点了点头，说道：嗯，不错，$n答对了。\n",
                       this_object(), me);
                me->delete_temp("robot_judge/answer");
                me->set_temp("robot_judge/ok", 1);
                return 1;
        }
        else
        {
                message_vision("$N叹了口气，对$n道：这么简单都答不对？\n",
                                this_object(), me);
                me->start_busy(1 + random(3));
                return 1;
        }
        return 1;
}
// 取消
mixed do_cancel()
{
        object me = this_player();

        if (me->is_busy())
                return "你正忙着呢！";

        if (undefinedp(me->query_temp("robot_judge/answer")))
                return "没有人向你提问啊。";

        me->delete_temp("robot_judge/answer");
        message_vision("$N叹了口气，对$n道：回答不上就算了，你休息一会吧。\n",
                       this_object(), me);
        me->start_busy(10 + random(60));

        return 1;
}
// 提问字符的问题
mixed do_ask_char()
{
        object me = this_player();
        string message = "";
        int i, j, k, m;
        string *str_keys = keys(str_char_map);
        int *int_char_array;
        string *str_char_answer = ({"", ""});
        int *int_rnd_row = ({random(2), random(2)});  // 随机行
        int *int_rnd_col = ({random(2), random(2)});  // 随机列

        str_char_answer[0] = str_keys[random(sizeof(str_keys))];  // 答案 1
        str_char_answer[1] = str_keys[random(sizeof(str_keys))];  // 答案 2
        
        message = HIC "";
        for (i = 0; i < 18; i++)  // 字符 16 行
        {
                for (m = 0; m < 2; m++)  // 第几个字符
                {
                        for (j = 0; j < int_rnd_col[m]; j++)
                                message += "  ";

                        for (j = 0; j < 2; j++)  // 字符中的高八位和低八位
                        {
                                for (k = 0; k < 8; k++)  // 位移
                                {
                                        int_char_array = str_char_map[str_char_answer[m]];  
                                        if (i - int_rnd_row[m] >= 0 &&
                                            i - int_rnd_row[m] <= 15 &&
                                            (int_char_array[(i-int_rnd_row[m])*2+j] >> (7-k)) & 0x1)
                                                message += "■";
                                        else
                                                message += "  ";
                                }
                        }
                }
                message += "\n";
        }
        message += "" NOR;
        tell_object(me, "大宗师对着你说道：\n" + message + "请回答（answer）这组字符是什么：\n");
//        me->set_temp("robot_judge/answer", str_char_answer[0] + str_char_answer[1]);
        me->set_temp("robot_judge/time", time() + 1800);
        me->delete_temp("robot_judge/ok", 1);

        return 1;
}
