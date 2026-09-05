inherit NPC;
#include <ansi.h>

string *msg = ({
"北大侠客行可能是教育网里开放时间最长的Mud了，从1997年起开始稳定开放。\n",
"新手多多help，如help path/help faq/help list/help task/help maps等等！\n",
"经验30M之前可以到发呆室找爱爱领取免费的兵器，相关命令为list和draw。\n",
"当铺可以用buy <中文名>来购买东西，比如“buy 玄铁剑”，记住哦，很有用的！\n",
"新手不熟悉地图可以多多help maps，同时牢记localmaps这个命令。\n",
"北侠主页http://pkuxkx.net(教育网直连)，http://telweb.pkuxkx.net(电信)，http://cncweb.pkuxkx.net(网通)。\n",
"新人遇到困难的时候可以询问在线的老玩家，不过建议多看看论坛，找不到了再问。\n",
"新人有很多的书可以读，几乎所有的基本工夫都有相关的书籍。\n",
"北侠是一个友好的mud，请老玩家们在练功之余多多帮助新手。希望大家在mud内外都能成为朋友。\n",
"请大家挖泥之余去各大BBS和论坛宣传北大侠客行，宣传内容详见\nhttp://pkuxkx.net/forum/viewthread.php?tid=2805&extra=page%3D1&frombbs=1\n如果宣传较多，可以在玩家乐园版单独开一个帖子列出自己发布的宣传贴的url，由巫师确认后予以相应的奖励。\n",
"请大家挖泥之余去各大BBS和论坛宣传北大侠客行，宣传内容详见\nhttp://pkuxkx.net/forum/viewthread.php?tid=2805&extra=page%3D1&frombbs=1\n如果宣传较多，可以在玩家乐园版单独开一个帖子列出自己发布的宣传贴的url，由巫师确认后予以相应的奖励。\n",
"出差在外还想来聊天？关机后还想知道北侠新闻？\n使用主页右上方web连线功能并申请发呆不退出帐号，\n随时随地可以来聊天、监控机器人，关机后的信息可以在两天内随时查看！\n",
"使用北侠主页上方“网速监视”功能可以及时查看北侠服务器到电信和网通转发服务器8081端口的连接速度，使用转发连接方式的玩家可参考其中信息选择适当的地址进行连接。\n",
"“我们不能玩一辈子的mud，但是可以做一辈子的朋友。”\n",
"北侠主页http://www.pkuxkx.net(直连)。\n",
"北侠主页有北侠npc和物品列表，可供玩家下载。\n",
"新人可以在扬州荣昌交易行(中央广场;e;e;e;n)向曲清要挖宝任务，这是一个危险很小的任务。\n",
"中央广场可以climb tree把基本轻功练到50级，新手好好利用。\n",
"新手可以钓鱼的地方有：姑苏慕容钓鱼台，神龙岛海滩，扬州汉水南岸，泉州港。\n",
"新人可以在注册后前往北大侠客行接待室找天赋调整巫师调整天赋。\n",
"为减少解谜的困难，玩家可以ask <npc> about all，老玩家需要支付一定的费用。\n",
"新手可以到发呆室找满不懂，ask budong about all来获取帮助。\n",
"请留意北大侠客行的登录界面，选择适合自己的连接方式。\n",
"今年是北侠的第十个年头，请大家多多宣传北大侠客行。\n",
"北大侠客行的QQ群是43515624（一群）和1029195(二群)，欢迎访问！\n",
"使用news命令来查看北大侠客行的最新变化！\n",
"风水大师预测的宝藏很准，找对了地方用digmoney命令慢慢挖，不需要任何工具。\n",
"名人堂的冰冰帮玩家存储潜能，相关命令是deposit/cun，withdraw/qu，check/chaxun。\n",
"可以使用help change命令查看最新的改动！\n",
"查看北大侠客行最新连接方式请help pkuxkx"
"经验在1M以上的玩家可以使用setmail命令申请空间高达6G的@pkuxkx.net邮箱，请输入setmail命令查看帮助。\n"
"新手可以help start，也可以去论坛看一下相关的文章。\n",
"新手可以help start，也可以去论坛看一下相关的文章。\n",
"新手可以在扬州名人堂ask hongdou about 开心辞典答题，潜能的奖励不菲哦。\n",
"门忠任务无法完成的时候可以ask npc about cancelquest来取消。\n",
"北侠提供了很多有趣的东东，比如说你可以去扬州名人堂ask hongdou about gre，红豆会考你GRE单词哦。\n",
"闲暇无聊的时候，不妨去扬州的书院，ask zhu about question，跟朱熹玩猜数字的游戏。\n",
"北侠提供了改名字的服务，可以去扬州知府，向知府本人打听「改名换姓」，\n到东厅找帐房先生交钱，再打听「改名换姓」即可。\n",
"在扬州书院的朱熹处，可以更改自己的称谓，在扬州书院朱熹面前输入apply可以知道用法。\n",
"杀人名医平一指推出变性服务，需要花费8888gold的存款。\n",
"发呆室的vast提供寻找task物品的服务，每次收费3 gold，直接从银行扣款，\n相关命令：在vast前输入“findtask 令狐冲的佩剑”。\n",
"百度贴吧有北侠的宣传信息，大家没事去顶啊：http://post.baidu.com/f?kz=286553212\n",
"北侠传奇巫师Jason开发了一个免费的手机软件，www.poporz.com，大家有兴趣的可以去支持下。\n",
"查看最新改动请help change\n",
"请用paihang/top/who等指令来查询目前在线玩家的数据。\n",
"水木社区mud版是北侠分舵，大家可以去灌水聊天，地址是：http://Mud.board.newsmth.net/。\n",
"请用cmd skill/cmd std/cmd usr指令来查询可以用的命令列表。\n",
"熟练cmd命令，掌握mud中所有的命令。\n",
"由于网络不是很稳定，请大家掌握好穿梭的技巧，目前可以从thu，yjrg，newytht和zixia进行穿梭。\n",
"不会穿梭的玩家可以去论坛参考《北侠穿梭全攻略》。\n",
"没事就去bbs.thu.cn/bbs.zixia.net/bbs.yjrg.net注册一个帐号，有备无患！\n",
"注册thu/zixia/yjrg的帐号之后别忘了用telnet进去看看，填写注册单哦。\n",
"穿梭请help shuttle，或参考论坛置顶《PKUXKX穿梭全攻略》。\n",
"速度很慢的玩家建议使用netpas的网络加速服务，参见http://www.netpas.com.cn，包月15元，\n速度很不错，注册时推荐人ID请填写heavenice，为北侠做一点贡献。\n",
"连不上服务器的时候，参考论坛北侠网站公告中icer的大作《PKUXKX当前连接方法总结》。\n",
"请用femote命令来查找适合的聊天表情，用vemote来查看聊天表情，用cemote来自定义聊天内容。\n",
"中央广场附近的发呆室能够用fadai命令恢复气血、精神等，请新手好好利用。\n",
"经验10w之前可以免费问朱熹学习读书写字。\n",
"经验10w以内，内力和精力在1000以下可以在发呆室使用fadai命令恢复精神气血。\n",
"大家记得随时保存和备份自已的档案，相关指令是save/backup。\n",
"系统不太稳定，建议大家用backup命令一个小时备份一次。\n",
"维护良好的氛围，谢绝pk和恶意捣乱，请老玩家们在练功之余多多帮助新手，请大家爱护北侠。\n",
"有任何心得、意见和建议，请去北大侠客行论坛发贴灌水。\n",
"新手可以做钓鱼，唱戏，送信，挖宝等任务，多多看帮助，多多看论坛。\n",
"新手在14岁的时候死亡没有损失，请珍惜自己的童年。\n",
"新增了一个recitewords命令，随时帮玩家背GRE单词。\n",
"新增特技系统，请查看help kungfu-special\n",
"新增出师系统，清查看help mimi-chushi\n",
"注意，各门派有一些NPC发放生活补贴，具体请help silver\n",
"新手有生活上的问题可以help userlife\n",
});

void create()
{
        set_name(HIW"北大侠客行"NOR, ({"PKUXKX"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", "北侠新闻发言人");
     set("env/invisibility",1);
        set("long", "一个可爱的小童，每天负责在这里迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_qi", 1500000);
        set("qi",1500000);
        set("jing",1500000);
        set("max_jing", 1500000);
        setup();
        remove_call_out("pkumsg");
        call_out("pkumsg",1);
}

void pkumsg()
{
	if (environment(this_object()))
	{
        message("channel:chat",HBBLU+HIY+"【北侠公告】"+NOR+HBRED+msg[random(sizeof(msg))]+NOR,users());
        remove_call_out("pkumsg");
        call_out("pkumsg",300);
    }
}
