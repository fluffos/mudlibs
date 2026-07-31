
string getwhere(object ob)
{
       object tmpobj,where, *ob_list,me,obtwo,obthree,tob;

        object item,room;

        string output,outputt,dis,alt,dir,local,tlocal,ck,playout;
        
        int i;

        int x,y,z,x0,y0,z0;

        int realdis;
	 mixed map,mapt;

        int tmp;
        string *dir1;
        string *dir2;

	string str="";
output="未知区域";

dir2=explode(base_name(ob),"/");

if (dir2[1]=="baituo")  

output="白驼山";

else if (dir2[1]=="binghuodao")  

	output="冰火岛";

else if (dir2[1]=="city")  

	output="扬州";

else if (dir2[1]=="city2" || dir2[1]=="beijing"  || dir2[1]=="huanggon"  || dir2[1]=="huanggong" || dir2[1]=="beihai")  

	output="北京城";

else if (dir2[1]=="city4" || dir2[1]=="changan")   

	output="长安城";

else if (dir2[1]=="dali")  

	output="大理";

else if (dir2[1]=="emei")  

	output="娥眉山";

else if (dir2[1]=="foshan")  

	output="佛山";

else if (dir2[1]=="gaibang")  

	output="丐帮";

else if (dir2[1]=="gaochang")  

	output="高昌迷宫";

else if (dir2[1]=="guanwai")  

	output="关外";

else if (dir2[1]=="guiyun")  

	output="归云庄";

else if (dir2[1]=="gumu")  

	output="古墓派";

else if (dir2[1]=="hangzhou")  

	output="杭州";

else if (dir2[1]=="heimuya")  

	output="黑木崖";

else if (dir2[1]=="hengshan")  

	output="恒山";

else if (dir2[1]=="henshan")  

	output="衡山";

else if (dir2[1]=="huanghe")  

	output="黄河九曲";

else if (dir2[1]=="huashan")  

	output="华山";

else if (dir2[1]=="jinshe")  

	output="金蛇山洞";

else if (dir2[1]=="lingjiu")  

	output="灵鹫宫";

else if (dir2[1]=="lingzhou")  

	output="灵州";

else if (dir2[1]=="meizhuang")  

	output="梅庄";

else if (dir2[1]=="mingjiao")  

	output="明教";

else if (dir2[1]=="qingcheng")  

	output="青城山";

else if (dir2[1]=="quanzhen")  

	output="全真派";

else if (dir2[1]=="quanzhou")  

	output="泉州";

else if (dir2[1]=="shaolin")  

	output="少林寺";

else if (dir2[1]=="shenlong")  

	output="神龙岛";

else if (dir2[1]=="songshan")  

	output="嵩山";

else if (dir2[1]=="suzhou")  

	output="苏州";

else if (dir2[1]=="taishan")  

	output="泰山";

else if (dir2[1]=="taohua")  

	output="桃花岛";

else if (dir2[1]=="tianlongsi")  

	output="天龙寺";

else if (dir2[1]=="wanjiegu")  

	output="万劫谷";

else if (dir2[1]=="wudang")  

	output="武当山";

else if (dir2[1]=="xiakedao")  

	output="侠客岛";

else if (dir2[1]=="xiangyang")  

	output="襄阳城";

else if (dir2[1]=="xiaoyao")  

	output="逍遥林";

else if (dir2[1]=="xingxiu")  

	output="星宿海";

else if (dir2[1]=="xueshan")  

	output="雪山寺";

else if (dir2[1]=="xuedao")  

	output="大雪山";

else if (dir2[1]=="mr")  

	output="慕容世家";

else if (dir2[1]=="kunlun")  

	output="昆仑山";

else if (dir2[1]=="tiezhang")  

	output="铁掌门";

else if (dir2[1]=="huizhu")  

	output="回族部落";

else if (dir2[1]=="yinju")  

	output="一灯大师居";

else if (dir2[1]=="menggu")  

	output="蒙古草原";

else if (dir2[1]=="qianjin")  

	output="北京千金楼";

else if (dir2[1]=="lingshedao")  

	output="灵蛇岛";

else if (dir2[1]=="ruzhou")  

	output="汝州城";

else if (dir2[1]=="kunming")  

	output="昆明";

else if (dir2[1]=="jingzhou")  

	output="荆州";

else if (dir2[1]=="yanjing")  

	output="燕京";

else if (dir2[1]=="lanzhou" || dir2[1]=="lanzhouchen")  

	output="兰州";

else if (dir2[1]=="jyguan")  

	output="北嘉峪关";

else if (dir2[1]=="changcheng")  

	output="北长城";

else if (dir2[1]=="fairyland")  

	output="红梅山庄";

else if (dir2[1]=="sdxl")  

	output="剑魔独孤求败墓";

else if (dir2[1]=="jqg")  

	output="绝情谷";

else if (dir2[1]=="nio")  

	output="牛家村";

else if (dir2[1]=="feihu")  

	output="闯王宝藏";

else if (dir2[1]=="wuguan")  

	output="襄阳武馆";

else if (dir2[1]=="village")  

	output="华山村";

else if (dir2[1]=="taohuacun")  

	output="桃花村";

else if (dir2[1]=="pingan")  

	output="平安城";

else if (dir2[1]=="lingxiao")  

	output="凌霄城";

else if (dir2[1]=="wudujiao")  

	output="五毒教";

else if (dir2[1]=="hj")  

	output="天山附近草原";
else if (dir2[1]=="dali/yuxu")  

	output="大理玉虚观";
else if (dir2[1]=="dali/wuliang")  

	output="大理无量山";
else if (dir2[1]=="huanghe/yyd")  

	output="黄河萧府";
else if (dir2[1]=="kaifeng")  

	output="开封城";
else if (dir2[1]=="feitian")  

	output="飞天御剑流";
else if (dir2[1]=="japan")  

	output="日本神户";
else if (dir2[1]=="tangmen")  

	output="唐门";
else if (dir2[1]=="luoyang")  

	output="洛阳城";

else if (dir2[1]=="chengdu" || dir2[1]=="city3")  

	output="成都";

else if (dir2[1]=="baihuagu")  

	output="百花谷";

else if (dir2[1]=="heizhao")  

	output="黑沼";

else if (dir2[1]=="jiaxing")  

	output="嘉兴";

else if (dir2[1]=="shiliang")  

	output="温家庄";

else if (dir2[1]=="wuyi")  

	output="武夷山区";

else if (dir2[1]=="yanping")  

	output="延平城";
	

if (dir2[1]=="jiangling")  
{
	output="江陵城";
}

if (dir2[1]=="yueyang")  
{
	output="岳阳城";	
}

if (dir2[1]=="qilian")  
{
	output="祁连山";	
}

if (dir2[1]=="shouxihu")  
{
	output="瘦西湖";	
}

if (dir2[1]=="wuxi")  
{
	output="无锡城";	
}

if (dir2[1]=="yixing")  
{
	output="宜兴城";	
}
if (dir2[1]=="taiwan")  
{
	output="台湾地区";	
}
if (dir2[1]=="nanyang")  
{
	output="南阳地区";	
}
if (dir2[1]=="nanshaolin")  
{
	output="南少林地区";	
}

if (dir2[1]=="cangzhou")  
{
	output="沧州地区";	
}

if (dir2[1]=="tanggu")  
{
	output="塘沽城地区";	
}

if (dir2[1]=="yunhe")  
{
	output="京杭大运河";	
}

if (dir2[1]=="hainan")  
{
	output="海南岛";	
}

if (dir2[1]=="jindezheng")  
{
	output="景德镇";	
}

if (dir2[1]=="yandang")  
{
	output="雁荡山";	
}

if (dir2[1]=="jinling")  
{
	output="金陵城";	
}

if (dir2[1]=="sandboy")  
{
	output="江南农村";	
}

if (dir2[1]=="huangshan")  
{
	output="黄山";	
}

if (dir2[1]=="yubifeng")  
{
	output="玉笔峰";	
}

if (dir2[1]=="quanzhouchen")  
{
	output="泉州城内";	
}

if (dir2[1]=="qingzh")  
{
	output="青藏高原";	
}

if (dir2[1]=="changbaishan" || dir2[1]=="gaoli")  
{
	output="高丽 长白山";	
}

if (dir2[1]=="annan")  
{
	output="安南";	
}

if (dir2[1]=="taiyuan")  
{
	output="太原";	
}

if (dir2[1]=="hefei")  
{
	output="合肥";	
}

if (dir2[1]=="jiujiang")  
{
	output="九江";	
}

if (dir2[1]=="baling")  
{
	output="巴陵";	
}

if (dir2[1]=="xinjiang")  
{
	output="新疆";	
}
if (dir2[1]=="dingxiang")  
{
	output="定襄";	
}
if (dir2[1]=="suiye")  
{
	output="碎叶";	
}


if (dir2[1]=="mayi")  
{
	output="马邑边疆";	
}
if (dir2[1]=="xuzhou")  
{
	output="徐州城";	
}
if (dir2[1]=="jinan")  
{
	output="济南城";	
}
if (dir2[1]=="guizhou")  
{
	output="贵阳城";	
}

if (dir2[1]=="nanchang")  
{
	output="南昌城";	
}


if (dir2[1]=="changsha")  
{
	output="长沙城";	
}


if (dir2[1]=="zhongzhou")  
{
	output="中州城";	
}

if (dir2[1]=="xizang" || dir2[1]=="zangbei")  
{
	output="西藏或藏北";	
}

if (dir2[1]=="cloud" )  
{
	output="东北绮云镇";	
}

if (dir2[1]=="xueting" )  
{
	output="东北雪亭镇";	
}

if (dir2[1]=="ny" )  
{
	output="东北宁远城";	
}

if (dir2[1]=="fengtian" )  
{
	output="东北盛京城";	
}

if (dir2[1]=="yanmen" )  
{
	output="雁门关";	
}

if (dir2[1]=="linzhi" )  
{
	output="西藏林芝地区";	
}

if (dir2[1]=="datong" )  
{
	output="大同府";	
}

if (dir2[1]=="tianshui" )  
{
	output="天水镇";	
}

if (dir2[1]=="heifeng" )  
{
	output="黑风寨";	
}

if (dir2[1]=="paiyun" )  
{
	output="排云寨";	
}


if (dir2[1]=="yeyangzai" )  
{
	output="野羊寨";	
}


if (dir2[1]=="jinghai" )  
{
	output="靖海派";	
}

if (dir2[1]=="zuojiacun" )  
{
	output="华亭镇";	
}


if (dir2[1]=="houjizhen" )  
{
	output="侯集镇";	
}

if (dir2[1]=="huayin" )  
{
	output="铜山村";	
}

if (dir2[1]=="lumaji" )  
{
	output="鹿马集";	
}


if (dir2[1]=="xiyu/gaochang" || dir2[1]=="xiyu/hami" || dir2[1]=="xiyu")  
{
	output="西域边疆";	
}

if (dir2[1]=="xibei/desert" || dir2[1]=="xibei/kongdong" || dir2[1]=="xibei/liangzhou" || dir2[1]=="xibei/xingqing" || dir2[1]=="xibei")  
{
	output="西北边疆";	
}

if (dir2[1]=="zhongyuan/chuzhou" || dir2[1]=="zhongyuan" )  
{
	output="中原关中";	
}

if (dir2[1]=="xinan/after_qingcheng" || dir2[1]=="xinan/cunzi" || dir2[1]=="xinan")  
{
	output="西南四川";	
}

if (dir2[1]=="loulan" )  
{
	output="楼兰";	
}

if (dir2[1]=="biancheng" )  
{
	output="边城";	
}

if (dir2[1]=="quicksand" )  
{
	output="大沙漠";	
}

if (dir2[1]=="tieflag/qianfo" || dir2[1]=="tieflag" || dir2[1]=="tieflag/palace" || dir2[1]=="tieflag/bat" || dir2[1]=="tieflag/chuenyu")  
{
	output="东海区域";	
}

if (dir2[1]=="taiping" )  
{
	output="太平镇";	
}

if (dir2[1]=="eren/eren2" || dir2[1]=="eren" )  
{
	output="恶人谷";	
}
return output;
}