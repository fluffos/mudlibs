#ifndef __NAME_H__
#define __NAME_H__

//北侠地图分六大块
#define ZHONGYUAN 1        //中原区域 
#define CHANGJIANGNAN 2    //长江以南
#define HUANGHEBEI 3       //黄河以北 
#define XIYU 4             //西域
#define XINAN 5            //西南
#define XIANGYANGNAN 6     //中原地区的襄阳南部
#define QUESTREG 0         //任务区域，实际上指的是未知区域

//玩家划分为4个等级，越高等级，地图越大。第一等级集中在很小的区域内
//第零等级就在扬州
#define USER_LEVEL0 0
#define USER_LEVEL1 1
#define USER_LEVEL2 2
#define USER_LEVEL3 3
#define USER_LEVEL4 4
//暂时不对玩家开放5
#define USER_LEVEL5 5

protected nosave mapping ok_dir=([
//中原区域    
"/d/huashan/":({"华山",ZHONGYUAN,USER_LEVEL2}),
"/d/village/":({"小山村",ZHONGYUAN,USER_LEVEL1}),
"/d/wudang/":({"武当山",ZHONGYUAN,USER_LEVEL1}),
"/d/shaolin/":({"少林寺",ZHONGYUAN,USER_LEVEL3}),
"/d/gumu/":({"古墓",ZHONGYUAN,USER_LEVEL3}),
"/d/xinyang/":({"信阳",ZHONGYUAN,USER_LEVEL1}),
"/d/changan/":({"长安",ZHONGYUAN,USER_LEVEL5}),
"/d/luoyang/":({"洛阳",ZHONGYUAN,USER_LEVEL1}),
"/d/pker/":({"杀手帮",ZHONGYUAN,USER_LEVEL3}),
"/d/taishan/":({"泰山",ZHONGYUAN,USER_LEVEL1}),
"/d/qufu/":({"曲阜",ZHONGYUAN,USER_LEVEL1}),
"/d/qilincun/":({"麒麟村",ZHONGYUAN,USER_LEVEL4}), 
"/d/xiangyang/":({"襄阳",ZHONGYUAN,USER_LEVEL1}),
"/d/lingzhou/":({"灵州",ZHONGYUAN,USER_LEVEL2}),
"/d/xingxiu/":({"星宿",ZHONGYUAN,USER_LEVEL3}),
"/d/quanzhen/":({"全真",ZHONGYUAN,USER_LEVEL1}),
"/d/gaibang/":({"丐帮",ZHONGYUAN,USER_LEVEL2}),
"/d/city/":({"扬州",ZHONGYUAN,USER_LEVEL0}),
"/d/lingjiu/":({"灵鹫",ZHONGYUAN,USER_LEVEL2}),
"/d/xiangyangnan/":({"荆州",ZHONGYUAN,USER_LEVEL1}),
"/d/zhongyuan/":({"中原",ZHONGYUAN,USER_LEVEL1}),
"/d/changjiangnorth/":({"长江北岸",ZHONGYUAN,USER_LEVEL1}),
"/d/huanghe/":({"黄河南岸",ZHONGYUAN,USER_LEVEL1}),
//江南
"/d/yuewangmu/":({"岳王墓",CHANGJIANGNAN,USER_LEVEL3}),
"/d/yashan/":({"牙山",CHANGJIANGNAN,USER_LEVEL2}),
"/d/yideng/yideng/":({"桃源",CHANGJIANGNAN,USER_LEVEL2}),
"/d/quanzhou/":({"嘉兴",CHANGJIANGNAN,USER_LEVEL2}),
"/d/quanzhou2/":({"泉州",CHANGJIANGNAN,USER_LEVEL2}),
"/d/fuzhou/":({"福州",CHANGJIANGNAN,USER_LEVEL2}),
"/d/taohuadao/":({"桃花岛",CHANGJIANGNAN,USER_LEVEL2}),
"/d/guiyunzhuang/":({"归云庄",CHANGJIANGNAN,USER_LEVEL2}),
"/d/suzhou/":({"苏州",CHANGJIANGNAN,USER_LEVEL1}),
"/d/murong/":({"姑苏慕容",CHANGJIANGNAN,USER_LEVEL3}),
"/d/hangzhou/":({"临安府",CHANGJIANGNAN,USER_LEVEL2}),
"/d/hangzhou/xihu/":({"西湖",CHANGJIANGNAN,USER_LEVEL2}),
"/d/hangzhou/tidufu/":({"杭州提督府",CHANGJIANGNAN,USER_LEVEL3}),
"/d/hangzhou/palace/":({"临安府皇宫",CHANGJIANGNAN,USER_LEVEL5}),
"/d/riyuejiao/meizhuang/":({"西湖梅庄",CHANGJIANGNAN,USER_LEVEL4}),
"/d/changjiang/":({"长江",CHANGJIANGNAN,USER_LEVEL2}),
"/d/zhenjiang/":({"镇江",CHANGJIANGNAN,USER_LEVEL2}),
"/d/yingtiannorth/":({"建康府北城",CHANGJIANGNAN,USER_LEVEL2}),
"/d/yingtiansouth/":({"建康府南城",CHANGJIANGNAN,USER_LEVEL3}),
"/d/yingtiansouth/dufu/":({"建康府诸军统制府",CHANGJIANGNAN,USER_LEVEL5}),
"/d/jiangzhou/":({"江州",CHANGJIANGNAN,USER_LEVEL2}),
"/d/nanchang/":({"南昌",CHANGJIANGNAN,USER_LEVEL2}),
"/d/yueyang/":({"岳阳",CHANGJIANGNAN,USER_LEVEL2}),
"/d/southmountain/dongtianmu/":({"东天目山",CHANGJIANGNAN,USER_LEVEL5}),
"/d/southmountain/xitianmu/":({"西天目山",CHANGJIANGNAN,USER_LEVEL5}),
"/d/southmountain/dashigu/":({"大石谷",CHANGJIANGNAN,USER_LEVEL5}),
"/d/southmountain/shezhai/":({"畲寨",CHANGJIANGNAN,USER_LEVEL5}),
"/d/southmountain/qingliangfeng/":({"清凉峰",CHANGJIANGNAN,USER_LEVEL5}),
//黄河以北       
"/d/beijing/":({"北京",HUANGHEBEI,USER_LEVEL2}),
"/d/beijing/kangqin/":({"康亲王府",HUANGHEBEI,USER_LEVEL4}),
"/d/beijing/zijin/":({"紫禁城",HUANGHEBEI,USER_LEVEL4}),
"/d/beijing/tiantan/":({"天坛",HUANGHEBEI,USER_LEVEL4}),
"/d/shenlongdao/":({"神龙岛",HUANGHEBEI,USER_LEVEL3}),
"/d/riyuejiao/":({"日月神教",HUANGHEBEI,USER_LEVEL2}),
"/d/jinyang/":({"晋阳",HUANGHEBEI,USER_LEVEL2}),
"/d/saiwai/":({"张家口",HUANGHEBEI,USER_LEVEL2}),
"/d/huanghenorth/":({"黄河北岸",HUANGHEBEI,USER_LEVEL2}),
"/d/northmountain/heishan/":({"黑山",HUANGHEBEI,USER_LEVEL5}),
//西域 

"/d/baituo/":({"白驼山",XIYU,USER_LEVEL2}),
"/d/mingjiao/":({"明教",XIYU,USER_LEVEL3}),  
"/d/silk/":({"丝绸之路",XIYU,USER_LEVEL3}),                       

//西南
"/d/chengdu/":({"成都",XINAN,USER_LEVEL3}),
"/d/kunming/":({"昆明",XINAN,USER_LEVEL3}),
"/d/miaojiang/":({"苗疆",XINAN,USER_LEVEL5}),
"/d/tianlong/":({"天龙寺",XINAN,USER_LEVEL2}),
"/d/pingxiwangfu/":({"平西王府",XINAN,USER_LEVEL3}),
"/d/emei/":({"峨嵋",XINAN,USER_LEVEL3}),
"/d/emei/houshan/":({"峨眉后山",XINAN,USER_LEVEL4}),
"/d/wuliang/":({"无量山",XINAN,USER_LEVEL4}),
"/d/lingxiao/":({"凌霄城",XINAN,USER_LEVEL4}),
"/d/dalunsi/":({"大轮寺",XINAN,USER_LEVEL3}),
"/d/dalicheng/":({"大理城中",XINAN,USER_LEVEL2}),    
]);

/* 地区归属补充 */
protected nosave mapping local_belong = 
([
"/d/jwhz/" : "/d/yashan/", /* 甲午海战地区 归属 牙山 */
"/d/xiangyangnan/" : "/d/xiangyang/", /* 保卫中荆门在S1位置 */
]);


#endif
