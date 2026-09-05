// monksk.h 技能设定头文件

//少林武器技能设定
mapping weapon_sk=
(["damo-jian":
	(["base":"sword",
		"special":"damo-jian",
	  "weapon":"/clone/weapon/changjian",
	  "perform": ({(: perform_action, "sword.sanjue" :)}),
	  "class": 10]),
  "xiuluo-dao":
  (["base":"blade",
  	"special":"xiuluo-dao",
  	"weapon":"/clone/weapon/gangdao",
  	"class": 10]),
  "riyue-bian":
  (["base":"whip",
  	"special":"riyue-bian",
    "weapon":"/clone/weapon/changbian",
    "perform": ({(: perform_action, "whip.chan" :),
    	           (: perform_action, "whip.fumoquan" :)}),
    "class": 100]),
  "cibei-dao":
  (["base":"blade",
  	"special":"cibei-dao",
  	"weapon":"/clone/weapon/gangdao",
  	"class": 10]),
  "fumo-jian":
  (["base":"sword",
  	"special":"fumo-jian",
  	"weapon":"/clone/weapon/changjian",
  	"class": 10]),
  "pudu-zhang":
  (["base":"staff",
  	"special":"pudu-zhang",
  	"weapon":"/clone/weapon/gangzhang",
  	"class": 10]),
  "wuchang-zhang":
  (["base":"staff",
  	"special":"wuchang-zhang",
  	"weapon":"/clone/weapon/gangzhang",
  	"class": 10]),
  "weituo-gun":
  (["base":"club",
  	"special":"weituo-gun",
  	"weapon":"/clone/weapon/qimeigun",
  	"class": 10]),
  "zui-gun":
  (["base":"club",
  	"special":"zui-gun",
  	"weapon":"/clone/weapon/qimeigun",
	  "perform": ({(: perform_action, "club.zuida" :)}),
  	"class": 50]),
  "ranmu-daofa":
  (["base":"blade",
  	"special":"ranmu-daofa",
  	"weapon":"/d/shaolin/obj/mudao",
  	"perform": ({(: perform_action, "blade.fentian" :), 
  		           (: perform_action, "blade.fenwo" :),
  		           (: perform_action, "blade.fenxin" :)}),
  	"class": 100]),
  "daweituo-chu":
  (["base":"staff",
  	"special":"daweituo-chu",
  	"weapon":"/clone/weapon/gangzhang",
  	"perform": ({(: perform_action, "staff.rulai" :), 
  		           (: perform_action, "staff.wuxiang" :)}),
  	"class": 100])]);
//少林拳脚技能设定
mapping unarmed_sk=
(["longzhua-gong":
	(["base": "claw",
		"special":"longzhua-gong",
		"class": 10]), 
  "yingzhua-gong":
  (["base": "claw",
  	"special":"yingzhua-gong",
  	"class": 10]),
  "luohan-quan":
  (["base": "cuff",
  	"special":"luohan-quan",
  	"perform": ({(: perform_action, "cuff.luohan" :)}),
  	"class": 100]),
  "jingang-quan":
  (["base": "cuff",
  	"special":"jingang-quan",
  	"perform": ({(: perform_action, "cuff.jingang" :)}),
  	"class": 10]),
  "qianye-shou":
  (["base": "hand",
  	"special":"qianye-shou",
  	"perform": ({(: perform_action, "hand.qianshou" :)}),
  	"class": 10]),
  "fengyun-shou":
  (["base": "hand",
  	"special":"fengyun-shou",
  	"perform": ({(: perform_action, "hand.foguang" :)}),
  	"class": 10]),
  "nianhua-zhi":
  (["base": "finger",
  	"special":"nianhua-zhi",
  	"perform": ({(: perform_action, "finger.fuxue" :)}),
  	"class": 100]),
  "yizhi-chan":
  (["base": "finger",
  	"special":"yizhi-chan",
  	"perform": ({(: perform_action, "finger.jingmo" :)}),
  	"class": 100]),
  "banruo-zhang":
  (["base": "strike",
  	"special":"banruo-zhang",
  	"perform": ({(: perform_action, "strike.san" :)}),
  	"class": 10]),
  "sanhua-zhang":
  (["base": "strike",
  	"special":"sanhua-zhang",
  	"perform": ({(: perform_action, "strike.sanhua" :)}),
  	"class": 10])]);