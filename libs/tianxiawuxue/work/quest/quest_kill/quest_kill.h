mapping area=([
 "扬州城" : ({"/d/city/","beidajie1","beidajie2","beimen","bingyin",
            "bingyindamen","guangchang",
            "nandajie1","nandajie2","nanmen","xidajie1","xidajie2","ximen",
            }),
 "北京城" : ({"/d/city2/","alley1","alley2","alley3","anding","aobai1",
            "bridge","bridge2","bridge3","ceting",
            "road2","road3","road4","road5","road6","road7","road8",
            "road9","tian_anm","tuzai","wangfu1","wangfu2","wangfu3",
            }),
 "白驼山" : ({"/d/baituo/","bridge","cao1","cao2","caomeide","caoping",
            "cave","cave1","cedong","chaifang","changlang","chufang",
            "damen","datiepu","dating","dongjie","fang","fende",
            }),
 "灵鹫宫" : ({"/d/lingjiu/","biguan","changl1","changl10","changl11",
             }),
 "泉州城" : ({"/d/quanzhou/","beimen","haigang","houyuan",
            "jiaxing","jxnanmen","laozhai","liang","midao","mishi",
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

