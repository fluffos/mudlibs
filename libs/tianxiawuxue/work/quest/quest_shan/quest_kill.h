mapping area=([
 "扬州城" : ({"/d/city/","beidajie1","beidajie2","beimen","bingyin",
            "bingyindamen","caizhu","guangchang","houyuan",
            "lichunyuan","lichunyuan2","meigui",
            "nandajie1","nandajie2","nanmen","pomiao",
            "shuyuan","xidajie1","xidajie2","ximen",
            "yamen","yaopu",
            "zahuopu","zuixianlou","zuixianlou2"
            }),
 "北京城" : ({"/d/city2/","alley1","alley2","alley3","anding","aobai1",
            "bingyin1","bingyin2","bridge","bridge2","bridge3","ceting",
            "chaguan","chaoyan1","chaoyan2","chaoyang","dangpu","datiepu",
            "dating","di_an1","di_an2","di_an3","di_an4","di_anmen",
            "dongcha1","dongcha2","dongchangdamen","dongmen","duchang",
            "duchang2","fotang","guancai2","haigang","hbridge","huayuan",
            "road2","road3","road4","road5","road6","road7","road8",
            "road9","tian_anm","tuzai","wangfu1","wangfu2","wangfu3",
            "xichang1","xichang2","xichangdamen","xidan","xidan1",
            "ximen","ximenwai","xisi","xisi2","yihongyu","yongding",
            "zahuopu","zhengmen"
            }),
 "白驼山" : ({"/d/baituo/","bridge","cao1","cao2","caomeide","caoping",
            "cave","cave1","cedong","chaifang","changlang","chufang",
            "damen","datiepu","dating","dongjie","dongkou","dongnei",
            "fang","fende","gebi","guangchang","houmen","houyuan",
            "huayuan","jiudian","liangong","menlang","midao","mumen",
            "neishi","nongshe","restroom","room1","room2","room3",
            "shanlu","shanlu1","shijie","shulin","shulin1","storeroom",
            "tuyuan","wuqiku","xiaolu1","xiaolu2","xiaolu3","xiaolu4",
            "xijie","ximen","yaofang","yuanzi","zhailuo","zhulin",
            "zhuyuan",
            }),
"灵鹫宫" : ({"/d/lingjiu/","changl1","changl10","changl11",
            "changl12","changl13","changl14","changl15","changl2",
            "changl3","changl4","changl5","changl6","changl7","changl8",
            "changl9","chufang","daban","dadao1","dadao2","damen",
            "dating","huayuan","jian","liangong","men1","men2","men3",
            "shanjiao","shufang","wuqiku","xianchou","xiaodao1",
            "xiaodao2",   
             }),
 "泉州城" : ({"/d/quanzhou/","beimen","haigang","houyuan",
            "jiaxing","jxnanmen","laozhai","liang","midao","mishi",
            "nanhu","nanhu1","nanmen","qzroad1","qzroad2","qzroad3",
            "qzroad4","qzroad5","tieqiang","well","xijie","yanyu",
            "zahuopu","zhongxin",
            }),
         ]);

string *city=({"扬州城","北京城","白驼山","灵鹫宫","泉州城"});

int place_room(object me,object ob)
{
  string *location, site_file, site_name;
  int size;

  site_name=city[random(sizeof(city))];
  location=area[site_name];
  size=sizeof(location);

  site_file=location[0]+location[random(size-1)+1];
  ob->set("area",site_name);
  ob->set("place_name",site_file);
  ob->set("killer",me->query("id"));
  ob->move(site_file);

  return 1;
}

