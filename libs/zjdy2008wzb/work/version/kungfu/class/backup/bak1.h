// SN:Kc6HYLMFg@R42X1T
// judge_robot.c
// Create by Cenzzz@ELL.RV
// 判断机器人（简单回答）
#include <ansi.h>;
#include "charcode.h" 
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
        string str_char;
        int i, j, k;
        int rnd_size;
        string *str_keys = keys(str_char_map);
        int *int_char_array;

        rnd_size = random(sizeof(str_keys));
        str_char = str_keys[rnd_size];  // 答案
        int_char_array = str_char_map[str_char];
        
        message = HIC "";
        for (i = 0; i < 16; i++)
        {
                for (j = 0; j < 2; j++)
                {
                        for (k = 0; k < 8; k++)
                        {
                                if ((int_char_array[i*2+j] >> (7-k)) & 0x1)
                                        message += "■";
                                else
                                        message += "  ";
                        }
                }
                message += "\n";
        }
        message += "" NOR;
        tell_object(me, "大宗师对着你说道：\n\n" + message + "请回答（answer）这组数字是多少：\n");

        return 1;
}

