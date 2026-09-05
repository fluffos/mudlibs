//定义兑奖相关的服务列表

//定义各种服务的基本属性
//服务分为以下几类：
//第一类是直接提升属性类，设定goods_type属性为attribute，设定attribute属性为具体要提升的属性，
//通过price和value来计算价格和要提升的幅度，通过limit_max和limit_min来限制提升该属性玩家其他
//属性的最高值和最低值。
//第二类是获得某类杂物，设定goods_type属性为item，设定item属性为到库房兑换实际物品的收据文件，
//fitem属性为实际兑换物品，limit_min和limit_max来限制兑换该物品所需要的属性最高值和最低值
//第三类是获得士兵装备，设定goods_type属性为equip，设定item属性为到库房兑换实际物品的收据文件，
//fitem为实际兑换物品列表(这里兑换物品列表中元素可以为array，如果为array，则第一个元素是文件名，
//第二个元素是调用的函数名，后面的元素是调用的函数入口参数），limit_min和limit_max来限制兑换
//该物品所需要的属性最高值和最低值
//第四类是租借士兵装备，设定goods_type属性为rent，其他同equip
mapping service_lists=
(["L001":
  (["name":"提升声望", 
    "desc":"通过朝廷的宣传手段在一定范围内提升你的武林声望。（不高于20年\n功力和50万声望）\n", 
    "price_desc": "3000点声望/10点积分", 
    "price": 10, "value": 3000, 
    "goods_type": "attribute", 
    "attribute" : "repute", 
    "limit_max" : (["combat_exp":600000, "repute":500000])]), 
  "L002":
  (["name":CYN"提升武功"HIW"（初级）"NOR,
    "desc":"朝廷的库房中存放着从各地武林高手哪里收集过来的武林秘籍，阅读\n武林秘籍可以大幅提升你的武学潜能。（至少需要10年功力）\n",
    "price_desc":"1本秘籍/500点积分",
    "price": 500,
    "goods_type": "item",
    "item" : "/d/changan/title/item/receipt-1",
    "fitem" : "/d/changan/title/item/book1",
    "limit_min" : (["combat_exp":100000]) ]),
  "L003":
  (["name":YEL"普通士兵装备"NOR,
    "desc":"一套普通士兵用的装备，包括陌刀、明光甲〖头部〗、明光甲〖身体〗\n、明光甲〖脚部〗。（至少需要１年功力）\n",
    "price_desc":"1套/240点积分",
    "price": 240,
    "goods_type": "equip",
    "item" : "/d/changan/title/item/receipt-2",
    "fitem" : ({"/d/changan/title/weapon/modao",({"/d/changan/title/armor/dtang_armor","set_dtang_armor","lv1_head"}),
      ({"/d/changan/title/armor/dtang_armor","set_dtang_armor","lv1_armor"}),
      ({"/d/changan/title/armor/dtang_armor","set_dtang_armor","lv1_boots"})}),
    "limit_min" : (["combat_exp":10000]) ]),
  "L004":
  (["name":"租借普通士兵装备",
    "desc":"从库房临时租借一套普通士兵用的装备，包括陌刀、明光甲〖头部〗、\n明光甲〖身体〗、明光甲〖脚部〗。（至少需要１年功力）\n",
    "price_desc":"1套/80点积分/天",
    "price": 80,
    "goods_type": "rent",
    "item" : "/d/changan/title/item/receipt-2",
    "fitem" : ({"/d/changan/title/weapon/modao",({"/d/changan/title/armor/dtang_armor","set_dtang_armor","lv1_head"}),
      ({"/d/changan/title/armor/dtang_armor","set_dtang_armor","lv1_armor"}),
      ({"/d/changan/title/armor/dtang_armor","set_dtang_armor","lv1_boots"})}),
    "limit_min" : (["combat_exp":10000]) ]),
]);

//爵位兑换服务清单
mapping title_slist=
(["LV1":({"L001", "L002", "L004", "L003"})
]);
