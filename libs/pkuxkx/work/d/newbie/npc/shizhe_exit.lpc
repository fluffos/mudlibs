//shizhe_exit.c 新手学堂指引使
//by zoom
//2004.4.3

#include <ansi.h>
inherit NPC;

string* guider_id = ({"mudadm","hongdou","xigua"});
string* guider_name = ({"管理","红豆","西瓜"});

void greeting(object);
void create()
{
        int n=random(sizeof(guider_name));
        set_name(guider_name[n], ({ guider_id[n] }));
	set("long", "他是北大侠客行历任管理员之一，现在已经另某高就。\n");
	set("title","[指引使]");
	set("gender", "男性");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("race", "人类");	
	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 800);
	set("eff_jing", 800);
	set("jing", 800);
	set("max_neili", 800);
	set("eff_neili", 800);
	set("neili", 800);
	set("max_jingli", 800);
	set("eff_jingli", 800);
	set("jingli", 800);
	set("combat_exp", 10000);
	set("score", 1000);
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me = this_player();        

        ::init();
        add_action("do_decide", "decide");
        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	object room;
	if(mapp( this_player()->query("family") ))
	{
		return;
	}
	if (query_temp(this_player()->query("id")) == 0 )
		{	command("hi " + me->query("id"));
        tell_object(me,HIG+this_object()->query("name")+"告诉你：  
          欢迎来到这里，我是新手学堂的指引使，可以帮助你去拜师，请你选择一个门派。
现在请你选择一个门派，选好了告诉我"HIR+"(decide)"HIG+"。请help menpai查询门派帮助。"WHT+"
如果不想拜师，要自成一家，请参考任务系统"HIR+"(help tasks)"HIW+"，公共武功"HIR+"(help kungfu-public)"HIW+"。
如果不需要我的帮助，请直接输入leave指令，我会把你送到扬州的客店。\n"NOR);
	}
	else
		command("tell " + me->query("id")+" " +HIG"  
          欢迎再次来到这里。"NOR);
return;
}

int do_decide()
{
	object me = this_player();
	if(mapp( me->query("family") ))
	{
	        tell_object( me, "你已经拜师了，不需要弟子的帮助了。\n");
		return 1;
	}
	if ( query_temp(me->query("id")) )
	{	command("? " + me->query("id"));
		command("tell " + me->query("id")+" " +HIG"  
          弟子刚刚领你去拜师了吧，你怎么又回来了呢？"NOR);
		return 1;
	}
	write("           *@*@*@*@*@*@*@*@*@*你可以拜的门派如下：*@*@*@*@*@*@*@*@*@*

              ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
              ＊＊ 白驼山(bt)	     朝廷(ct)         大理(dl)    ＊＊
              ＊＊ 峨嵋(em)          丐帮(gb)         古墓(gm)    ＊＊     
              ＊＊ 华山(hs)          灵鹫(lj)         明教(mj)    ＊＊
              ＊＊ 姑苏慕容(mr)      全真(qz)         日月(ry)    ＊＊
              ＊＊ 少林(sl)          天地会(tdh)      桃花岛(thd) ＊＊
              ＊＊ 武当(wd)          星宿(xx)         雪山派(xs)  ＊＊
              ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n"NOR);
	command("say 想好了么？请输入门派名称:");
	input_to("get_menpai");

   return 1;
}

void get_menpai(string arg)
{
	  int n;
          object* inv;
          string destin, destna, destch, destma, destmg, destpo, desthelp, tosay;
          object pla,target;
          int i;
          object me = this_player();

	if (arg=="雪山派" || arg == "xs")
		{
                destin = "/d/lingxiao/chengmen";
		destna = "凌霄城";
                destch = "凌霄城";
		destma = "耿万钟";
                destmg = "雪山派在凌霄城内，在极高极险之地。";
                destpo = "去凌霄城的话可以从扬州城中心出发
走以下路径：enter shudong;andao;d;9;sw;s;sw;sw;nw;out;n;w;nu;nu;n;w;w;yell bridge;n;sheng bridge";
		desthelp = "menpai-lingxiao,map-lingxiao";			
		}
     if(arg=="白驼山" || arg == "bt")
        {
                destin = "/d/city/qianzhuang";
		destna = "白驼";
                destch = "白驼山开的钱庄";
		destma = "钱眼开";
                destmg = "去白驼山的路上有一片大沙漠很危险，可以向钱眼开或者欧阳克要骆驼。
钱眼开是白驼山派来扬州的卧底，想拜他为师，要揭穿他的身份，试试ask qian about 白驼山。
成为白驼弟子之后也可以问他，给他一点钱就能直接来回于扬州和白驼，很方便。";
		destpo = "白驼山位于中原西去大漠之中，如果骑骆驼去的话，路径如下：
“#6 w;nu;nd;w;w;nw;w;w;w;w;w;e;n;w;w;e;w;w;w”，注意多带水，沙漠中行走速度慢，要适当休息";
		desthelp = "menpai-baituo,map-baituo";
        }
    else if(arg=="朝廷" || arg == "ct")
        {
                destin = "/d/beijing/shiweiying";
		destna = "朝廷";
                destch = "北京城，朝廷的所在地";
		destma = "多隆";
                destmg = "朝廷是不能叛师的，一定要想好哦。想好了话就ask jiaotou about 投军，
然后就可以进去拜师了。如果出现拜了没反应的时候就走开再回来一下。
北京城晚上要关城门，要进城可要赶白天啊，不过如果你官做大了也能随便出入。";
		destpo = "朝廷就在北京城，从扬州出发，路径如下：
“enter shudong;say 天堂有路你不走呀;d;3;ne;ne;u;sw;e;sd;e;e;ne;ne;ne;do 6 n”";
		desthelp = "menpai-chaoting,map-beijing";
        }
    else if(arg=="大理" || arg == "dl")
        {
                destin = "/d/dalicheng/dadian";
		destna = "天龙";
                destch = "天龙寺";
		destma = "本因方丈";
                destmg = "这里就是天龙寺了。据说大理王子段誉在琅缳福地，不知道是个什么地方。";
		destpo = "大理位于西南边陲，从扬州出发，路径如下：
“#9 s;sw;w;w;nw;#5 sw;wu;nu;n”";
		desthelp = "menpai-dali,map-dali";
        }
    else if(arg=="峨嵋" || arg == "em")
        {
                destin = "/d/emei/shanmen";
		destna = "峨嵋";
                destch = "峨嵋";
		destma = "文虚师太";
                destmg = "入门要拜文虚师太，愿意出家可(ask 文虚about 出家)。当然只有出家才能学到上乘武功。";
destpo = "峨嵋山位于四川眉县城西南十五里，雄踞四川盆地西南缘，从扬州出发，路径如下：
“#9 s;sw;#2 w;nw;w;w;sw;w;nw;n;#2 nu;n;e;eu;#2 nu;eu;n;#3 nu;wu;nu;#2 n”";
		desthelp = "menpai-emei,map-emei";
        }
    else if(arg=="丐帮" || arg == "gb")
        {
                destin = "/d/gaibang/inhole";
		destna = "丐帮";
                destch = "丐帮树洞";
		destma = "裘万家或空空儿";
                destmg = "新手加入丐帮应该算是成长最快的了，升袋会有很多经验奖励，而且丐帮弟子可以随地睡觉，真是爽啊！";
		destpo = "丐帮总舵就设在扬州东门的青竹林中，也可走丐帮的暗道。在扬州中央广场：
“enter shudong;say 天堂有路你不走呀;d”即可走暗道了，暗道四通八达，非常方便。";
		desthelp = "menpai-gaibang,map-gaibang";
        }
    else if(arg=="古墓" || arg == "gm")
        {
                destin = "/d/gumu/caodi";
		destna = "古墓";
                destch = "古墓";
		destma = "小虹，小玲";
                destmg = "这里就是杨过与小龙女双宿双栖的古墓了，要拜师的话，你去向杨女打听“进墓”吧。";
		destpo = "古墓位于终南山脚下，从扬州出发，路径如下：
“#5 n;nw;#6 n;#2 nw;w;#2 nw;n;nw;#2 nu;n;nu;#2 n;#5 n;#6 n;nd;wd;ed;ask yang about 进墓”";
		desthelp = "menpai-gumu,map-gumu";
        }
    else if(arg=="华山" || arg == "hs")
        {
                destin = "/d/huashan/buwei1";
		destna = "华山";
                destch = "华山";
		destma = "陆大有(男玩家)，岳灵珊(女玩家)";
                destmg = "华山自来是学武之人向往之地，如能在华山论剑中获胜就可扬名天下了。";
		destpo = "华山位于扬州西北，从扬州出发，路径如下：
“#5 n;nw;#6 n;#5 e;se;su;eu;su;eu;#2 su;sd;su;#2 s;s;w;w”";
		desthelp = "menpai-huashan,map-huashan";
        }
    else if(arg=="灵鹫" || arg == "lj")
        {
                destin = "/d/lingjiu/jian";
		destna = "灵鹫";
                destch = "灵鹫宫";
		destma = "钧天部副首领 程青霜";
                destmg = "要上山必须余婆婆带你去了，向她打听一下“上山”的消息吧，不过灵鹫宫只收女弟子哦。";
		destpo = "灵鹫宫位于天山上，从扬州出发，路径如下：
“enter shudong;say 天堂有路你不走呀;d;4;#3 w;#2 nw;nu;#2 n;#2 nu”";
		desthelp = "menpai-lingjiu,map-lingjiu";
        }
    else if(arg=="明教" || arg == "mj")
        {
                destin = "/d/mingjiao/damen";
		destna = "明教";
                destch = "明教";
		destma = "颜垣、闻苍松、庄铮、辛然";
                destmg = "明教源出波斯，教中不乏武林高手，历代教主更是武林霸主人物。";
		destpo = "明教位于西域沙漠之中，从扬州出发，路径如下：
“#6 w;nu;nd;#2 w;nw;w;nw;#2 wu;nw;#7 w;#3 n;#3 w;nw;n;nw;#4 nu;n”";
		desthelp = "menpai-mingjiao,map-mingjiao";
        }
    else if(arg=="姑苏慕容" || arg == "mr")
        {
                destin = "/d/murong/qinyun";
		destna = "慕容";
                destch = "慕容山庄的琴韵小居";
		destma = "阿碧、阿朱";
                destmg = "姑苏慕容在太湖之上，必须要坐船才能到达。本门弟子可以在湖边自行找船往返(find boat)。";
		destpo = "慕容山庄位于苏州城西大湖之中，从扬州出发到湖边，路径如下：
“#6 e;se;s;e;#5 n;nw;#5 w;s”。ask girl about 拜庄;enter boat即可去慕容山庄";
		desthelp = "menpai-murong,map-murong,map-suzhou";
        }
    else if(arg=="全真" || arg == "qz")
        {
                destin = "/d/quanzhen/gongmen";
		destna = "全真";
                destch = "全真";
		destma = "男玩家：尹志平，女玩家：程遥伽";
                destmg = "全真派可是个不错的门牌，有很多好东西，如果男弟子要拜尹志平需要发誓‘忠于全真’(swear 忠于全真)。";
		destpo = "全真教位于终南山上，从扬州出发，路径如下：
“#5 n;nw;#6 n;#2 nw;w;#2 nw;n;nw;#2 nu;n;nu;#2 n”";
		desthelp = "menpai-quanzhen,map-quanzhen";
        }
    else if(arg=="日月" || arg == "ry")
        {
                destin = "/d/riyuejiao/rukou";
		destna = "日月";
                destch = "日月教";
		destma = "童百熊或鲍大楚";
                destmg = "日月教有很多秘密，如果自己实在摸索不出，也可以问问高手。";
		destpo = "日月教位于扬州西门外，从扬州出发，路径如下：
“#5 w;#2 n;ne;#2 nu”";
		desthelp = "menpai-riyuejiao,map-riyuejiao";
        }

     else if(arg=="少林" || arg == "sl")
        {
                destin = "/d/shaolin/guangchang1";
		destna = "少林";
                destch = "少林寺";
		destma = "清法比丘";
                destmg = "少林只收男弟子，并且要出家才能随意出入少林寺。(ask biqiu about 剃度)";
		destpo = "少林寺坐落于河南省嵩山，从扬州出发，路径如下：
“enter shudong;say 天堂有路你不走呀;d;3;#2 ne;u;sw;e;sd;e;#2 nu;wu;#3 nu;e;eu;#3 nu;n;”";
		desthelp = "menpai-shaolin,map-shaolin";
        }
     else if(arg=="天地会" || arg == "tdh")
        {
                destin = "/d/beijing/chaguan";
		destna = "天地会";
                destch = "天地会的接头地点";
		destma = "关安基或徐天川";
		destmg = "天地会在北京设了不少暗道来确保安全。要进入暗道需要知道暗号，多问问天地会人物会有发现的。";
                destpo = "天地会总舵设在北京城中杨柳胡同,从扬州出发去北京，路径如下：
“enter shudong;say 天堂有路你不走呀;d;3;ne;ne;u;sw;e;sd;e;e;ne;ne;ne;do 6 n”";
		desthelp = "menpai-tiandihui,map-tiandihui,map-beijing";
        }
    else if(arg=="桃花岛" || arg == "thd")
        {
                destin = "/d/guiyunzhuang/guiyunting";
		destna = "桃花";
                destch = "归云庄";
		destma = "陆冠英";
                destmg = "拜桃花岛需要先入归云庄，要注意桃花岛的弟子不要随意pk同时要注意自己的道德哦，否则会被师傅开除的。";
		destpo = "桃花岛位于东海之中，去岛上要乘船，从扬州出发，路径如下：
“#6 e;se;s;e;e;nd;e;e;e;e;n;enter;enter boat”";
		desthelp="menpai-taohuadao,map-taohuadao,map-guiyunzhuan,map-jiaxing";
        }
     else if(arg=="武当" || arg == "wd")
        {
                destin = "/d/wudang/sanqing";
		destna = "武当";
                destch = "武当";
		destma = "谷虚道长";
                destmg = "此处就是武当的三清殿，不是武当弟子到这就进不去了，武当弟子要下山需要向宋远桥打听“下山”的消息。";
		destpo = "武当山位于扬州西南，从扬州出发，路径如下：
“#5 s;#4 s;sw;w;w;nw;#3 w;wu;#3 nu;w;#2 nu;#2 eu;#2 nu;n;n”";
		desthelp = "menpai-wudang,map-wudang";
        }
    else if(arg=="星宿" || arg == "xx")
        {
                destin = "/d/xingxiu/xxroad4";
		destna = "星宿";
                destch = "星宿海";
		destma = "阿紫";
                destmg = "这星宿海人烟稀少，附近倒是有个维吾尔族小镇。";
		destpo = "星宿位于西部边陲，沙漠边缘，毗邻天山，从扬州出发，路径如下：
“enter shudong;say 天堂有路你不走呀;d;4;w;w;w;#wa 1000;nw;wu;n;”";
		desthelp = "menpai-xingxiu,map-xingxiu";
        }
    else
	{
        write("什么乱七八糟的，先想清楚吧。\n");
	return;
	}
//生成npc,跟随玩家去想要拜的门派，完成任务后销毁
    tosay = query("name")+"说道：“我这就派弟子跟你去，他会在路上帮助你。”\n";
    tell_object(me, tosay);
    target = new("/d/newbie/npc/guider");
    target->move(environment(me));
    target->set("name",destna+"弟子");
    target->set_leader(me);
    message_vision(query("name")+"对$N说道：这位新手就由你负责帮助拜师，早些回来！\n",target);
    message_vision("$N说道：是！\n",target);

    if( !objectp(pla = find_object(destin)) )
        pla = load_object(destin);
    if (me->move(pla)&&target->move(pla))
     {
        message_vision(HIW"弟子领着$N来到这里，周围的人都投来羡慕的眼光。\n", me);
        tell_object(me, "弟子告诉你：“到啦，这里就是" + destch + "。”\n");
	tell_object(me, "本派入门可拜" +destma+"。用bai <id>来拜他为师，可以用id here来获得当前房间生物或物品的id。\n");
        tell_object(me, CYN "弟子又说道：“" + destmg + "”\n");
        tell_object(me, "弟子又说道：“" + destpo + "”\n");
        tell_object(me, HIY "关于本派的帮助请看：help " + desthelp + "。\n" NOR);
     }
    me->set("startroom","/d/city/kedian");
    me->set("xuetang",1);
    set_temp(this_player()->query("id"),1);
    return;
}
void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}
