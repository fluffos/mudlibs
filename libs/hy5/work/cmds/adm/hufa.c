
int main(object me, string arg)
{
string* names = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫",
"蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻",
"柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳",
"邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付",
"皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍",
"虞","万","支","柯","昝","管","卢","英","仇","候","岳","帅",
"司马","上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫",
"尉迟","公羊","澹台","公治","宗政","濮阳","淳于","单于","太叔",
"申屠","公孙","仲孙","辕轩","令狐","钟离","宇文","长孙","幕容",
"司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷",
"公良","拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦",
"段千","百里","东郭","南郭","呼延","归海","羊舌","微生","梁丘",
"左丘","东门","西门","佰赏","南官",
"缑","亢","况","后","有","琴","商","牟","佘","耳","墨","哈",
"谯","年","爱","阳","佟","第","五","言","福","蒯","钟","宗",
"林","石",
});

string* ids = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});
//----以下欢迎添加，nm2需要一定的空字，以便产生出单名--------------
string* nm2 = ({
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
});

mixed npcs = ({
        ({
        "/kungfu/class/wudang/zhang",
        "/kungfu/class/shaolin/da-mo",
"/quest/menpaijob/emei/miejue",
"/kungfu/class/huashan/feng",
"/kungfu/class/lingjiu/tonglao",
"/kungfu/class/lingjiu/li",
"/kungfu/class/taohua/huang",
"/quest/menpaijob/xingxiu/ding",
"/kungfu/class/btshan/ouyangfeng",
"/quest/menpaijob/shenlong/hong",
"/kungfu/class/xueshan/fawang",
"/kungfu/class/xueshan/jiumozhi",
"/kungfu/class/xueshan/xuedao",
"/quest/menpaijob/yunlong/chen",
"/quest/menpaijob/mingjiao/zhangwuji",
"/quest/menpaijob/gumu/zf/longnv",
"/quest/menpaijob/gumu/yangguo",
"/kungfu/class/gaibang/hong",
"/d/quanzhen/npc/wang",
"/kungfu/class/dali/duanzc",
"/d/yinju/npc/yideng",
"/d/tianlongsi/npc/kurong",
"/d/xiaoyao/npc/xiaoyaozi",
"/d/nanshaolin/nanshaolin/tianhong",
"/d/nanshaolin/nanshaolin/tianjing",
"/d/tiezhang/npc/qqren",
"/d/tiezhang/npc/sgjn",
"/d/mr/npc/murong-bo",
"/d/mr/npc/murong-fu",
"/kungfu/class/kunlun/hezudao",
"/d/heimuya/npc/dongfang",
"/d/heimuya/npc/renwoxing",
"/d/lingxiao/npc/bai-wanjian",
"/d/lingxiao/npc/bai",
"/d/wudujiao/npc/hetieshou",
"/d/wudujiao/npc/hehongyao",
"/d/tangmen/npc/tang",
"/d/feitian/npc/biguqing",
"/d/feitian/npc/tianfeng",
"/kungfu/class/honghua/chen-jialuo",
"/kungfu/class/qingcheng/yu",
"/kungfu/class/taishan/tianmen",
"/kungfu/class/songshan/zuo",
"/kungfu/class/henshan/moda",
"/kungfu/class/hengshan/xian",
"/kungfu/class/hu/hufei",
"/kungfu/class/miao/miao",
"/d/meizhuang/npc/huangzhong-gong",
"/d/meizhuang/npc/danqing-sheng",
"/d/meizhuang/npc/tubi-weng",
"/d/jinghai/npc/master1",
"/d/jinghai/npc/master2",
"/d/hainan/npc/master",
"/d/xiakedao/npc/mu",
"/d/xiakedao/npc/long",
"/d/xibei/kongdong/npc/mu",
        }),
        });

   string HUFA_FILE = npcs[0][random(sizeof(npcs[0]))];
   object hufa;
   int i;

object *enemy;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
int k,a,b,c,d,e,f,temp;
   seteuid(getuid());
        

		if( environment(me)->query("no_fight") )
		return notify_fail("这里没有人打斗！\n");
   //last 0 means do not show position.

   if (me->query("jing")<100) 
	return notify_fail("你精不够!!\n");


//   me->save();


   message_vision("只听$N大喝一声：护法何在！！！！\n", me);
   hufa = new(HUFA_FILE);
   hufa->move(environment(me));
   	 //hufa->set_name(me->query("name")+"的护法",({"dizi"}));
   
    i = random(sizeof(names));
  hufa->set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
   hufa->set("combat_exp",me->query("combat_exp")/2);
   hufa->set("possessed", me);
     hufa->set("combat_exp", (me->query("combat_exp")));
	hufa->set("max_qi",  me->query("max_qi")); 
	hufa->set("max_jing",  me->query("max_jing")); 
        hufa->set("eff_jingli", me->query("eff_jingli")); 
        hufa->set("max_neili",  me->query("max_neili")); 
hufa->set("str",  me->query("str")); 
hufa->set("dex",  me->query("dex")); 
hufa->set("con",  me->query("con")); 
hufa->set("int",  me->query("int")); 
 hufa->set("jiali", random(300)+1);     
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = hufa->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = hufa->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
hufa->set_skill(sname[i],e);//删除自己所有功夫
}

   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       hufa->set_temp("apply/defense", 200);
        hufa->set_temp("apply/armor", 500);
        hufa->set_temp("apply/damage", 200);
        hufa->set_temp("apply/attack", 200);		
	}	



      hufa->set("owner_id", (string)me->query("id")); 
   hufa->set_leader(me);



   hufa->show(me);
    me->add("jing",-100); 
	   	if(me->is_fighting()) {
  enemy = me->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			hufa->kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(hufa);
			else enemy[i]->kill_ob(hufa);
		}
	}
//me->remove_all_killer();
	}
      return 1;
}
 


int help(object me)
{
    write(@HELP
指令格式: alert 
 
身为武林正邪两派的盟主，可以用召唤两名护法来保护自己。
可用whisper对自己的护法下命令。例如，如果你的护法叫aaa-zuo，用
whisper aaa-zuo kill xiao er即可命令他杀店小二。

HELP
    );
   return 1;
}
 
