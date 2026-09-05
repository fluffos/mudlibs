#ifndef __CONDITION_H__
#define __CONDITION_H__

#define CND_CONTINUE		1
#define CND_NO_HEAL_UP		2

//存放三种类型的条件解释：poison-毒，disease-疾病，injure-创伤
protected mapping cond_def=
(["anran_poison":
	(["name":"情毒",//in use
		"type":"poison"]),
  "bee_poison":
	(["name":"蜂毒",
		"type":"poison"]),
  "bing_poison":
	(["name":"冰魄银针毒",
		"type":"poison"]),
  "bleeding":
	(["name":"流血",
		"type":"injure"]),
  "bt_poison"://in use
	(["name":"白驼蛇毒",
		"type":"poison"]),
  "btgs_poison"://in use
	(["name":"西域怪蛇毒",
		"type":"poison"]),
  "cake_drug":
	(["name":"腹泻",
		"type":"disease"]),
  "cannt_eq":
	(["name":"刺腕",
		"type":"injure"]),
  "chanchu_poison"://in use
	(["name":"蟾蜍毒",
		"type":"poison"]),
  "chuanxin"://in use
	(["name":"穿心钉",
		"type":"injure"]),
  "crazy":
	(["name":"发疯",
		"type":"disease"]),
  "drunk":
	(["name":"醉酒",
		"type":"disease"]),
  "dsy_poison"://in use
	(["name":"密宗大手印毒",
		"type":"poison"]),
  "emerald_poison":
	(["name":"玄冰毒",
		"type":"poison"]),
  "fs_poison":
	(["name":"腐尸毒",//in use
		"type":"poison"]),
  "heat":
	(["name":"燥热",
		"type":"disease"]),
  "hyd_condition"://in use
	(["name":"火焰刀焚伤",
		"type":"injure"]),
  "ill_fashao":
	(["name":"发烧",
		"type":"disease"]),
  "ill_kesou":
	(["name":"咳嗽",
		"type":"disease"]),
  "ill_shanghan":
	(["name":"伤寒",
		"type":"disease"]),
  "ill_zhongshu":
	(["name":"中暑",
		"type":"disease"]),
  "insect_poison":
	(["name":"蜂毒",
		"type":"poison"]),
  "jiaofei-fire":
	(["name":"烈火烧伤",
		"type":"injure"]),
  "kuangre":
	(["name":"狂热",
		"type":"disease"]),
  "nx_zhua"://in use
	(["name":"凝血神爪毒",
		"type":"poison"]),
  "ningxue"://in use
	(["name":"凝血毒",
		"type":"poison"]),
  "qianzhu"://in sue
	(["name":"千蛛万毒",
		"type":"poison"]),
  "qishang":
	(["name":"七伤拳伤心脉",
		"type":"poison"]),
  "rose_poison":
	(["name":"火玫瑰毒",
		"type":"poison"]),
  "s-poison":
	(["name":"断肠散毒",
		"type":"poison"]),
  "san_poison":
	(["name":"断肠散毒",
		"type":"poison"]),
  "sanxiao_poison":
	(["name":"三笑逍遥散",//in use
		"type":"poison"]),
  "scorpion_poison":
	(["name":"蝎毒",
		"type":"poison"]),
  "sha_poison":
	(["name":"铁砂掌毒",
		"type":"poison"]),
  "shuoxin"://in use
	(["name":"烁心弹焚伤",
		"type":"injure"]),
  "slumber_drug"://in use
	(["name":"蒙汗药",
		"type":"poison"]),
  "snake_poison"://in use
	(["name":"蛇毒",
		"type":"poison"]),
  "ss_poison"://in use
	(["name":"生死符",
		"type":"poison"]),
  "tangshang":
	(["name":"烫伤",
		"type":"injure"]),
  "unchblk" :
  (["name":"禁言",
		"type":"disease"]),
  "wannianzui":
	(["name":"万年醉",
		"type":"disease"]),
  "wenyi":
	(["name":"瘟疫",
		"type":"disease"]),
  "wudu_poison"://in use
	(["name":"五毒神掌毒",
		"type":"poison"]),
  "wugong_poison"://in use
	(["name":"蜈蚣毒",
		"type":"poison"]),
  "x_shihui":
	(["name":"石灰眼瞎",
		"type":"injure"]),	
  "xx_poison"://in use
	(["name":"星宿毒掌毒",
		"type":"poison"]),
  "xx_poison2"://in use
	(["name":"星宿毒掌毒",
		"type":"poison"]),
  "xxfog-poison"://in use
	(["name":"星宿毒雾",
		"type":"poison"]),
  "xx-poison-palsy":
	(["name":"星宿麻痹",
		"type":"poison"]),
  "xx-poison-palsy2":
	(["name":"星宿麻痹",
		"type":"poison"]),
  "xx_disorder":
	(["name":"星宿碧磷毒",
		"type":"poison"]),
  "xxx_poison"://in use
	(["name":"冰魄寒毒",
		"type":"poison"]),
  "yf_condition"://in use
	(["name":"玉蜂针毒",
		"type":"poison"])]);

#endif
