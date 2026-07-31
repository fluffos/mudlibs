// SN:dAj1`C6Y0k7QMFe`
// judge_robot.c
// Create by Cenzzz@ELL.RV
// 判断机器人（简单回答）
#include <ansi.h>;
#include "charcode.h";
// 外部方法
mixed do_ask();
// 内部方法
mixed do_ask_digital();
// 提问
mixed do_ask()
{
        return do_ask_digital();
}
// 提问数字的问题
mixed do_ask_digital()
{
        object me = this_player();
        string message = "";
        int i, j, k, m;
        string *str_keys = keys(str_char_map);
        int *int_char_array;
        string *str_char_answer;
        int *int_rnd_row = ({random(3), random(3)});  // 随机行
        int *int_rnd_col = ({random(3), random(3)});  // 随机列

        str_char_answer[0] = str_keys[random(sizeof(str_keys))];  // 答案
        str_char_answer[1] = str_keys[random(sizeof(str_keys))];  // 答案
        
        tell_object(me, "int_rnd_row[0] = " + int_rnd_row[0] + "\n");
        message = HIC "";
        for (i = 0; i < 16 + 2; i++)  // 字符 16 行，随机行 2 行
        {
                for (m = 0; m < 2; m++)
                {
                        for (j = 0; j < 2; j++)
                        {
                                for (k = 0; k < 8; k++)
                                {
                                        int_char_array = str_char_map[str_char_answer[m]];  
                                        if (i - int_rnd_row[0] > 0 &&
                                            i - int_rnd_row[0] < 15 &&
                                            (int_char_array[(i-int_rnd_row[0])*2+j] >> (7-k)) & 0x1)
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

        return 1;
}


