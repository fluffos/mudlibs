// wuxian_mic.c

#include <ansi.h>;
#include <command.h>;
#define 001 = "《楚歌-玛莉亚-花花公子-死不了》";

inherit ITEM;

string *sing_001 = ({
        HIW "白无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
        HIW "白无常用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,
        HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
        HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
        HIW "白无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});


void create()
{
        set_name("无线麦", ({"wuxian mic", "mic"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",@LONG
这是一把高级无线麦克风，它可以给你开个“失恋发泄演唱会”(chang)
但是你必须有超人迷人的魅力，不然......嘿嘿！！
LONG
);
        set("value", 0);
        set_weight(10);
        }
        setup();
}
void init()
{
        add_action("do_chang", "chang");
        add_action("do_list","list");
}
int do_chang(string arg,string num,int i)
{
        object me = this_player();
        num = "楚歌-玛莉亚-花花公子-死不了";
        if( me->query("qi") < 20 ) return notify_fail("别再唱了，不然就看不到明天的太阳了！\n");
        if(!num) return notify_fail("你要唱什么歌？请先用（list）查看歌曲列表！\n");
        if( me->query("per") < (25 + random(5))){
        message("channel:chat",HIW"【走火入魔】："+ me->name() +"疯狂的唱着歌曲，无奈声音沙哑！谁知......\n",users());
        message("channel:chat",HIW"【走火入魔】：隔壁的小强破口大骂：半夜三更练什么玉女神经，学什么猫叫春？想吵死人啊？！...\n",users());
        message("channel:chat",HIW"【走火入魔】："+ me->name() +"不由自主的疯狂起舞，样子无可救药\n",users());
        me->unconcious();
        return 1;
}       else {
        message("channel:chat",HIC"【失恋发泄演唱会】"+ me->name() +"带起一把无线MIC伤心的说：请让我为大家献上几首失恋情歌
                 《"+ num +"》，谢谢！\n"NOR,users());
        remove_call_out("sing");
        call_out("sing",3,me);
        return 1;
        }

}
int do_list(string arg)
{
        object me;
        me = this_player();
        me->set("title",HIR +"自做"+ HIY +"多情"+ HIW +"死不了"NOR);
        
        tell_object(me,"\n
目前演唱的歌曲有：\n
(001)   ————  《楚歌-玛莉亚-花花公子》\n\n
请挑选您说喜欢的歌曲，输入：chang <歌曲编号>
\n");
        return 1;
}

void sing(int num,object ob)
{
        message("channel:chat",HIG"【楚歌】：淡淡野花香 烟雾盖似梦乡 别后故乡千里外 那世事变模样\n",users());
        message("channel:chat",HIG"【楚歌】：我却在他乡 千里关山 风雨他乡 乡音 我愿听 家里酒 我愿能尝\n",users());
        message("channel:chat",HIG"【楚歌】：莫道隔千山 朝夕里也梦想 但望有朝身花蝶 对抗着风与霜 我在踏家乡\n",users());
        call_out("sing1_02",5,ob);
        return;
}
void sing1_02(object ob)
{
        message("channel:chat",HIM"【玛莉亚】：让那长长秀法发 象云落下 柔弱柔弱如轻纱 徐徐落下\n",users());
        message("channel:chat",HIM"【玛莉亚】：让那长长秀法发 摇落下 红脸红脸何悲伤 莹莹泪下\n",users());
        message("channel:chat",HIM"【玛莉亚】：明媚眸子里 仍残留心碎 盈类满腔 心里似是有说话\n",users());
        message("channel:chat",HIM"【玛莉亚】：静静的落泪 迷糊说话 又像是受尽 无言责骂\n",users());
        message("channel:chat",HIM"【玛莉亚】：SMILE AGAIN 莫让旧日爱的死结绑着你\n",users());
        message("channel:chat",HIM"【玛莉亚】：SMILE AGAIN 那恶梦忘了吧\n",users());
        message("channel:chat",HIM"【玛莉亚】：SMILE AGAIN 就让就让我心深切爱着你\n",users());
        message("channel:chat",HIM"【玛莉亚】：忘了吧 不要想他 SMILE AGAIN\n",users());
        remove_call_out("sing1_03");
        call_out("sing1_03",5,ob);
        return;
}
void sing1_03(object ob)
{
        message("channel:chat",HIY"【花花公子】：他穿梭这里 他穿梭那里 天天多派对 他没有空虚\n",users());
        message("channel:chat",HIY"【花花公子】：连到潇洒的语句 高级的兴趣 恰好的应对 他备有一堆\n",users());
        message("channel:chat",HIY"【花花公子】：长期东奔与西跑 就像从未累 孩童一般贪心多心\n",users());
        message("channel:chat",HIY"【花花公子】：日夜寻玩具 寻乐趣 花花公子 情人多多多\n",users());
        message("channel:chat",HIY"【花花公子】：然而开不开心 他都不是太清楚 花花公子 寻求多多多\n",users());
        message("channel:chat",HIY"【花花公子】：然而追追赶赶 他都不是太清楚 寻什么?\n",users());
        remove_call_out("sing1_04");
        call_out("sing1_04",5,ob);
        return;
}
void sing1_04(object ob)
{
        message("channel:chat",HIR"【死不了】：剖开胸膛 我让心在烈日底下烧 烧成记号 记你的好永远别忘掉\n",users());
        message("channel:chat",HIR"【死不了】：头破血流 也要护你到天涯海角 爱一个字 我敢用一辈子回报\n",users());
        message("channel:chat",HIR"【死不了】：狂风吹 大海啸 真心的人死不了 地多大 天多高 一生只换一声好\n",users());
        message("channel:chat",HIR"【死不了】：痛快哭 痛快死 痛快的痛死不了 这一生 这一秒 我只要求你知道\n",users());
        message("channel:chat",HIR"【死不了】：冰天雪地 我把冰水全往头上浇 浇熄思念 最后一处温暖的怀抱\n",users());
        message("channel:chat",HIR"【死不了】：你为了谁 宁愿让心变成了孤鸟敞开双手 不依不靠从此随风飘\n",users());
        message("channel:chat",HIR"【死不了】：离别的酒容易醉 男人流血不流泪干一杯 痛痛快快说再会\n",users());
        return;
}
