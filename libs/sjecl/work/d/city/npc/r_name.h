// named.c
// By snowman@SJ 10/06/2000
//modified by campsun 2003/09/25
//修改内容，修改函数get_random_name,现在可以指定获得名字的字符数量了。
//可以指定取出名字是1-4个中文字，但是请不要超过4个以上

mapping get_random_name(int, int);
mapping random_name(int, int);

string *f_name = ({
  "爱", "安",
  "柏", "鲍", "贝", "卞", "卜",
  "曹", "岑", "昌", "常", "陈", "成",
  "呆", "戴", "邓", "狄", "第", "董", "窦",
  "耳",
  "樊", "范", "方", "费", "冯", "凤", "伏", "福", "付",
  "葛", "缑", "顾", "关", "管",
  "哈", "韩", "郝", "和", "何", "贺", "候", "后", "胡", "花", "华", "华", "黄", "霍",
  "计", "纪", "姜", "蒋", "金", "昝",
  "康", "亢", "柯", "孔", "蒯", "况",
  "郎", "雷", "李", "廉", "梁", "林", "凌", "柳", "卢", "鲁", "吕", "罗",
  "马", "茅", "毛", "米", "苗", "明", "墨", "牟", "穆",
  "倪", "年",
  "潘", "庞", "彭", "皮", "平",
  "戚", "齐", "祁", "钱", "谯", "秦", "琴", "仇", "屈",
  "任",
  "傻", "商", "邵", "佘", "沈", "施", "石", "时", "史", "舒", "帅", "水", "宋", "苏", "孙",
  "谈", "汤", "唐", "陶", "藤", "佟",
  "万", "汪", "王", "韦", "魏", "卫", "吴", "五", "伍", "邬",
  "奚", "项", "肖", "谢", "熊", "徐", "许", "薛",
  "严", "言", "杨", "阳", "姚", "益", "殷", "尹", "英", "盈", "尤", "有", "虞", "余", "禹", "喻", "元", "袁", "岳", "乐", "云",
  "藏", "湛", "章", "张", "赵", "郑", "支", "钟", "周", "朱", "祝", "宗", "邹", "褚", "祖",

  "百里", "佰赏",
  "楚晋", "淳于", "单于",
  "东方", "东郭", "东门", "端木", "段千",
  "公良", "公孙", "公西", "公羊", "公冶", "谷梁", "归海",
  "赫连", "呼延", "皇甫",
  "夹谷",
  "梁丘", "令狐",
  "慕容",
  "南宫", "南郭",
  "欧阳",
  "濮阳",
  "漆雕",
  "汝鄢",
  "上官", "申屠", "师空", "司马", "司徒",
  "太叔", "澹台", "涂钦", "拓趾",
  "微生", "闻人", "巫马",
  "西门", "夏候", "骧驷", "轩辕",
  "阎法", "羊舌", "尉迟", "宇文", "乐正",
  "宰父", "长孙", "钟离", "仲孙", "诸葛", "颛孔", "宗政", "左丘",
});

string *f_id = ({
  "ai", "an",
  "bo", "bao", "bei", "bian", "bo",
  "cao", "cen", "chang", "chang", "chen", "cheng",
  "dai", "dai", "deng", "di", "di", "dong", "dou",
  "er",
  "fan", "fan", "fang", "fei", "feng", "feng", "fu", "fu", "fu",
  "ge", "gou", "gu", "guan", "guan",
  "ha", "han", "hao", "he", "he", "he", "hou", "hou", "hu", "hua", "hua", "hua", "huang", "huo",
  "ji", "ji", "jiang", "jiang", "jin", "jiu",
  "kang", "kang", "ke", "kong", "kuai", "kuang",
  "lang", "lei", "li", "lian", "liang", "lin", "ling", "liu", "lu", "lu", "lv", "luo",
  "ma", "mao", "mao", "mi", "miao", "ming", "mo", "mou", "mu",
  "ni", "nian",
  "pan", "pang", "peng", "pi", "ping",
  "qi", "qi", "qi", "qian", "qiao", "qin", "qin", "qiu", "qu",
  "ren",
  "sha", "shang", "shao", "she", "shen", "shi", "shi", "shi", "shi", "shu", "shuai", "shui", "song", "su", "sun",
  "tan", "tang", "tang", "tao", "teng", "tong",
  "wan", "wang", "wang", "wei", "wei", "wei", "wu", "wu", "wu", "wu",
  "xi", "xiang", "xiao", "xie", "xiong", "xu", "xu", "xue",
  "yan", "yan", "yang", "yang", "yao", "yi", "yin", "yin", "ying", "ying", "you", "you", "yu", "yu", "yu", "yu", "yuan", "yuan", "yue", "yue", "yun",
  "zang", "zhan", "zhang", "zhang", "zhao", "zheng", "zhi", "zhong", "zhou", "zhu", "zhu", "zong", "zhou", "zhu", "zu",

  "baili", "baishang",
  "chujin", "chunyu", "chanyu",
  "dongfang", "dongguo", "dongmen", "duanmu", "duanqian",
  "gongliang", "gongsun", "gongxi", "gongyang", "gongye", "guliang", "guihai",
  "helian", "huyan", "huangpu",
  "jiagu",
  "liangqiu", "linghu",
  "murong",
  "nangong", "nanguo",
  "ouyang",
  "puyang",
  "qidiao",
  "ruyan",
  "shangguan", "shentu", "shikong", "sima", "situ",
  "taishu", "tantai", "tuqin", "tuozhi",
  "weisheng", "wenren", "wuma",
  "ximen", "xiahou", "xiangsi", "xuanyuan",
  "yanfa", "yangshe", "yuchi", "yuwen", "yuezheng",
  "zaifu", "zhangsun", "zhongli", "zhongsun", "zhuge", "zhuankong", "zongzheng", "zuoqiu",
});

string *name_m = ({
  "安",
  "霸", "白", "班", "碧", "斌", "宾", "波",
  "才", "财", "昌", "长", "超", "诚", "川",
  "大", "德华", "鼎", "定", "栋", "斗", "多",
  "发", "法", "飞", "锋", "风", "夫", "福", "福", "富",
  "钢", "罡", "高", "公", "贯", "光", "国",
  "海", "浩", "赫", "宏", "虎", "华", "辉",
  "济", "戟", "坚", "键", "健", "剑", "江", "杰", "金", "金", "进", "靖", "峻", "俊",
  "康", "可", "克", "匡",
  "琅", "礼", "良", "良", "麟", "令", "龙", "隆", "禄",
  "满", "民", "明", "鸣",
  "宁",
  "培", "沛",
  "奇", "启", "强", "庆",
  "仁", "人", "荣", "若",
  "山", "盛", "胜", "时", "世", "寿", "叔", "顺",
  "泰", "涛", "添", "铁", "挺", "同",
  "万", "为", "伟", "文", "武",
  "熙", "羲", "宪", "祥", "祥", "晓", "小", "孝", "雄", "雄", "旭", "学友",
  "杨", "亿", "毅", "义", "益", "永", "勇", "友", "宇", "羽", "瑜", "岳",
  "振", "峥", "之", "志", "智", "忠", "舟", "宙", "子", "自",
});

string *id_m = ({
  "an",
  "ba", "bai", "ban", "bi", "bin", "bin", "bo",
  "cai", "cai", "chang", "chang", "chao", "cheng", "chuan",
  "da", "dehua", "ding", "ding", "dong", "dou", "duo",
  "fa", "fa", "fei", "feng", "feng", "fu", "fu", "fu", "fu",
  "gang", "gang", "gao", "gong", "guan", "guang", "guo",
  "hai", "hao", "he", "hong", "hu", "hua", "hui",
  "ji", "ji", "jian", "jian", "jian", "jian", "jiang", "jie", "jin", "jin", "jin", "jing", "jun", "jun",
  "kang", "ke", "ke", "kuang",
  "lang", "li", "liang", "liang", "lin", "ling", "long", "long", "lu",
  "man", "min", "ming", "ming",
  "ning",
  "pei", "pei",
  "qi", "qi", "qiang", "qing",
  "ren", "ren", "rong", "ruo",
  "shan", "sheng", "sheng", "shi", "shi", "shou", "shu", "shun",
  "tai", "tao", "tian", "tie", "ting", "tong",
  "wan", "wei", "wei", "wen", "wu",
  "xi", "xi", "xian", "xiang", "xiang", "xiao", "xiao", "xiao", "xiong", "xiong", "xu", "xueyou",
  "yang", "yi", "yi", "yi", "yi", "yong", "yong", "you", "yu", "yu", "yu", "yue",
  "zhen", "zheng", "zhi", "zhi", "zhi", "zhong", "zhou", "zhou", "zi", "zi",
});

string *name_g = ({     //女性专用
"爱",
  "宝钗", "碧",
  "春", "翠",
  "黛", "黛玉", "丹",
  "芳", "芬", "凤", "芙",
  "姑",
  "虹", "红", "花", "惠", "慧",
  "娇", "晶", "静", "菊", "娟",
  "珂",
  "兰", "岚", "莉", "丽", "莲", "琳", "玲",
  "美", "敏",
  "萍",
  "倩", "琴", "芹", "青", "箐",
  "蓉",
  "姗", "淑",
  "婷",
  "婉",
  "霞", "贤", "香", "湘云",
  "嫣然", "艳", "燕", "英", "瑛", "荧", "盈", "颖", "玉", "媛",
  "真", "珍", "珠",
});

string *id_g = ({
  "ai",
  "baochai", "bi",
  "chun", "cui",
  "dai", "daiyu", "dan",
  "fang", "fen", "feng", "fu",
  "gu",
  "hong", "hong", "hua", "hui", "hui",
  "jiao", "jing", "jing", "ju", "juan",
  "ke",
  "lan", "lan", "li", "li", "lian", "lin", "ling",
  "mei", "min",
  "ping",
  "qian", "qin", "qin", "qing", "qing",
  "rong",
  "shan", "shu",
  "ting",
  "wan",
  "xia", "xian", "xiang", "xiangyun",
  "yanran", "yan", "yan", "ying", "ying", "ying", "ying", "ying", "yu", "yuan",
  "zhen", "zhen", "zhu",
});

mapping random_name(int gender, int num) {
  string *ids, *f_id1, *f_id2;
  mapping name;
  string f_n1, f_n2;
  int i;
  string *group_name, *group_id;
  if (gender)                     //判定男或女名字
  {
    group_name = f_name;
    group_id = f_id;
  } else {
    group_name = name_g;
    group_id = id_g;
  }
  f_n2 = "";
  f_id2 = ({});
  i = random(sizeof(group_name));
  f_n1 = group_name[i];
  f_id1 = ({ group_id[i] });
  while (strlen(f_n1) > num)                  //如果获得的字符数大于需要的，则再寻找
  {
    name = random_name(gender, num);

    f_n1 = name["name"];
    f_id1 = name["id"];
  }
  if (strlen(f_n1) < num)                  //如果字符数不满，则进行递归寻找
  {
    name = random_name(gender, num - strlen(f_n1));
    f_n2 = name["name"];
    f_id2 = name["id"];
  }
  f_n1 = f_n1 + f_n2;
  f_id1 = f_id1 + f_id2;
  ids = f_id1;


  return ([
    "name": f_n1,
    "id": ids,
  ]);
}

mapping get_random_name(int gender, int num)                //对名字的id进行排序
{
  mapping name;
  string *ids;
  int char_num = num * 2;
  name = random_name(gender, char_num);                 //调用random_name获得随机名字
  ids = name["id"];

  switch (sizeof(ids)) {

    case 4:
      ids = ({ ids[0] + ids[1] + " " + ids[2] + ids[3] }) + ({ ids[0] + ids[1] }) + ({ ids[2] + ids[3] });     //对4个字的名字的id进行重新排序
      break;
    case 3:
      ids = ({ ids[0] + " " + ids[1] + ids[2] }) + ({ ids[0] }) + ({ ids[1] + ids[2] });         //对3个字的名字的id排序
      break;
    case 2:
      ids = ({ ids[0] + " " + ids[1] }) + ({ ids[0] }) + ({ ids[1] });            //两个字的名字的id排序
      break;


  }

  return ([
    "name": name["name"],
    "id": ids,
  ]);



}
