// /system/std/char/include/master.h for F_MASTER
// Amber 97-12 将master.c一些变量、定义转到这里来。

string *quest_reward_msg = ({
	"看了看你，笑道：“不错不错！”\n",
});

string *quest_fail_msg = ({
    "看了看你，然后又失望地摇了摇头，什么也不说。\n",
    "看起来很是生气，但似乎又发作不出来，只是轻轻哼了一声。\n",
    "惊奇地问：“什么，连这个都没做好？？！！！”\n"
    "沮丧地望着你，并不说话，但明显很失望。\n",
    "叹了口气：“本来对你期望甚高，怎知你却如此辜负于我的苦心……”\n",
    "摇了摇头：“我本不应该让你去的……”\n",
    "冷哼一声：“怎的你竟是如此不中用？！！”\n",
    "拍拍你的肩膀：“不要灰心，我知道你尽力了。”\n",
    "对着你摇了摇头，说：“连这点事都做不好……下去吧。”\n",
    "看上去很不高兴，皱了皱眉头对你说：“下去歇着吧。”，嘴\n"
    "里嘟囔着：“真是没用……”\n",
    "疑惑地看着你：“怎么回事？怎么你……”\n",
    "失望地看看你，慢慢地转过头去，跟其他弟子说话去了。\n",
});
string *quest_delay_msg = ({
    "似乎有些不满：“怎么现在才办好这件事？，你……”\n",
    "很不高兴地看了你两眼，一言不发，又把身子转了过去……\n",
    "瞪了你一眼：“真是误事，现在才回来……”\n",
    "很是圭怒，气呼呼地说：“你怎么现在才回来？！！”\n",
    "和蔼地笑了笑：“你应该早点回来呀……算了吧……”\n",
    "很是失望，叹了口气说：“你做事怎么如此磨蹭？！”\n",
});

string *quest_refuse_msg = ({
    "$N对$n说：“现在没什么事做，你先下去练功吧。”\n",
    "$N向$n摇了摇头：“你还是应当多练练功为上。”\n",
});

string get_family_id( string family_name )
{
    switch( family_name )
    {
        case "无量剑派东宗" :   return "east";      break;
        case "无量剑派西宗" :   return "west";      break;
        case "伏牛派"       :   return "funiu";     break;
        case "崆峒派"       :   return "kongdong";  break;
        case "少林派"       :   return "shaolin";   break;
        case "镇南王府"     :   return "duanshi";   break;
        case "蓬莱派"       :   return "penglai";   break;
        case "凤翔镖局"     :   return "biaoju";    break;
        case "神农帮"       :   return "shennong";  break;
        
        default:                return "common";    break;
    }
}
