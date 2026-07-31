#include <ansi.h>

string* names = ({
        "chengguan luohan",
        "chengzhi luohan",
        "chengming luohan",
        "chengjing luohan",
        "chengjian luohan",
        "chengxing luohan",
        "chengji luohan",
        "chengmie luohan",
        "chenghe luohan",
        "chengxin luohan",
        "chengyi luohan",
        "chengsi luohan",
        "chengshi luohan",
        "chengzhi luohan",
        "chengxin luohan",
        "chengling luohan",
        "chengyu luohan",
        "chengshang luohan",
});

string ask_me()
{
        mapping fam, my_fam;
        object power, me, room, monk, ling;
        int j;

        power = this_player();
        me = this_object();
        my_fam  = me->query("family");

        if ( mapp(fam = power->query("family")) 
        && fam["family_name"] == "少林派"
        && (int)fam["generation"] < 37)
                return RANK_D->query_respect(power) + 
                "你还不够资格带领十八罗汉去攻打雪山寺。";

        if ( (int)power->query("guilty") > 0 )
                return RANK_D->query_respect(power) + 
                "你累犯数戒，身带重罪，我如何能准许你去攻打雪山寺！";

        say("\n清乐说道：好吧，我来召集罗汉堂长老和般若堂长老们于本寺广场，我稍候在广厂等你。\n");

        power->set("assigned_power", 1);
        for(j=1; j<10; j++) 
        {
                if(!( room = find_object("/d/shaolin/luohan" + j)) )
                room = load_object("/d/shaolin/luohan" + j);
                
                if( !objectp(monk = present(names[j-1], room) ))
                {
                        me->move("/d/shaolin/fzlou1");
                        message_vision("\n清乐比丘走了过来。\n\n", power);
                        return "真是不巧，罗汉堂中有人不在，无法凑齐人数。\n";    
                }
                monk->add_skill("move", 1000);
                monk->map_skill("move", "shaolin-shenfa");
                monk->move("/d/shaolin/fzlou1");
                monk->set_leader(power);
                monk->move("/d/xueshan/shenghu");
        }
        
        me->move("/d/shaolin/guangchang1");
        power->move("/d/shaolin/guangchang1");
        message_vision("\n清乐比丘走了过来。说道：这是令符，好好保留。\n",power);
        ling=new(__DIR__"obj/lingfu");
        ling->set("time",power->query("time"));
        ling->move(power);
        message_vision("\n清乐比丘：祝大师旗开得胜，马到功成。\n", power);
        me->move("/d/shaolin/fzlou1");
            power->move("/d/xueshan/shenghu");

        return "好！大家都出来了。\n";
}
