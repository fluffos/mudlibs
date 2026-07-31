#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
#include "/quest/menpai/romnpc4.c"


mapping *data=({
(["name":"星宿派叛徒",	"id":"xspt",	"mw":-1,	"tname":"bnpcb1",]),
(["name":"日月教叛徒",	"id":"rypt",	"mw":1,	"tname":"bnpcb2",]),
(["name":"灵蛇岛叛徒	",	"id":"lspt",	"mw":-1,"tname":"bnpcb3",]),
(["name":"丐帮叛徒",	"id":"gbpt",	"mw":1,		"tname":"bnpcb4",]),
(["name":"天下会杀手",	"id":"txss",	"mw":1,	"tname":"bnpcb5",]),
(["name":"嵩山派隐者",	"id":"ssyz",	"mw":-1,	"tname":"bnpcb6",]),
(["name":"御前侍卫长",	"id":"swz",		"mw":1,	"tname":"bnpcb7",]),
(["name":"少林叛徒",	"id":"slpt",	"mw":1,	"tname":"bnpcb8",]),
(["name":"灵鹫宫叛徒",	"id":"ljgpt",	"mw":-1,		"tname":"bnpcb9",]),
(["name":"山大王",		"id":"sdw",	"mw":-1,	"tname":"bnpcb10",]),
(["name":"黑社会老大",	"id":"hld",		"mw":-1,		"tname":"bnpcb11",]),
(["name":"无量山叛徒",	"id":"wlspt",	"mw":1,	"tname":"bnpcb12",]),
(["name":"官府捕快",	"id":"bk",	"mw":-1,	"tname":"bnpcb13",]),
(["name":"百夫长",	"id":"bfz",	"mw":-1,	"tname":"bnpcb14",]),
(["name":"坏车夫",	"id":"cf",	"mw":-1,	"tname":"bnpcb15",]),
(["name":"恶官员",	"id":"gy",	"mw":-1,	"tname":"bnpcb16",]),
(["name":"奸险商人",	"id":"sr",	"mw":-1,	"tname":"bnpcb17",]),
(["name":"红衣细作",	"id":"hxz",	"mw":-1,	"tname":"bnpcb18",]),
(["name":"蓝衣细作",	"id":"rxz",	"mw":-1,	"tname":"bnpcb19",]),
(["name":"红衣儒生",	"id":"hns",	"mw":-1,	"tname":"bnpcb20",]),
(["name":"判乱的侍卫",	"id":"sw",	"mw":-1,	"tname":"bnpcb21",]),
(["name":"侍卫队长",	"id":"swdz",	"mw":-1,	"tname":"bnpcb22",]),
(["name":"落洞女",	"id":"ldn",	"mw":-1,"sex":1,	"tname":"bnpcb23",]),
(["name":"无影贼",	"id":"wyz",	"mw":-1,	"tname":"bnpcb24",]),
(["name":"巫女",	"id":"wn",	"mw":-1,"sex":1,	"tname":"bnpcb25",]),
(["name":"红枪头领",	"id":"hqtl",	"mw":-1,	"tname":"bnpcb26",]),
(["name":"红枪侍卫",	"id":"hqsw",	"mw":-1,	"tname":"bnpcb27",]),
(["name":"狱卒总管",	"id":"yzzg",	"mw":-1,	"tname":"bnpcb28",]),
(["name":"亲兵头领",	"id":"qbtl",	"mw":-1,	"tname":"bnpcb29",]),
(["name":"王府亲兵",	"id":"wfqb",	"mw":-1,	"tname":"bnpcb30",]),
(["name":"恶人护院",	"id":"erhy",	"mw":-1,	"tname":"bnpcb31",]),
(["name":"机关巧匠",	"id":"jgqj",	"mw":-1,	"tname":"bnpcb32",]),
(["name":"淫农妇",	"id":"ynf",	"mw":-1,	"tname":"bnpcb33",]),
(["name":"恶农户",	"id":"enh",	"mw":-1,	"tname":"bnpcb34",]),
(["name":"喽罗",	"id":"ll",	"mw":-1,	"tname":"bnpcb35",]),
(["name":"坏哨兵",	"id":"sb",	"mw":-1,	"tname":"bnpcb36",]),
(["name":"神巫",	"id":"sw",	"mw":-1,	"tname":"bnpcb37",]),
(["name":"勇士",	"id":"ys",	"mw":-1,	"tname":"bnpcb38",]),
(["name":"伏牛山叛军",	"id":"fnspj",	"mw":-1,	"tname":"bnpcb39",]),
(["name":"造反的士卒",	"id":"zfsz",	"mw":-1,	"tname":"bnpcb40",]),
(["name":"亡命徒",	"id":"wmt",	"mw":-1,	"tname":"bnpcb41",]),
(["name":"恶民女",	"id":"emn",	"mw":-1,"sex":1,	"tname":"bnpcb42",]),
(["name":"野人猎手",	"id":"yrls",	"mw":-1,	"tname":"bnpcb43",]),
(["name":"暴怒的苦工",	"id":"kg",	"mw":-1,	"tname":"bnpcb44",]),
(["name":"狩猎的义军",	"id":"yj",	"mw":-1,	"tname":"bnpcb45",]),
(["name":"盐帮帮众",	"id":"ybbz",	"mw":-1,	"tname":"bnpcb46",]),
(["name":"铁衣卫",	"id":"tjw",	"mw":-1,	"tname":"bnpcb47",]),
(["name":"钢甲兵",	"id":"gjb",	"mw":-1,	"tname":"bnpcb48",]),
(["name":"疯狂的伙计",	"id":"fkhj",	"mw":-1,	"tname":"bnpcb49",]),
(["name":"看守",	"id":"ks",	"mw":-1,	"tname":"bnpcb50",]),
(["name":"禁军",	"id":"jj",	"mw":-1,	"tname":"bnpcb51",]),
(["name":"神秘人",	"id":"smr",	"mw":-1,	"tname":"bnpcb52",]),
(["name":"巡查军士",	"id":"xcjs",	"mw":-1,	"tname":"bnpcb53",]),
(["name":"披甲刺客",	"id":"pjck",	"mw":-1,	"tname":"bnpcb54",]),
(["name":"发怒的师太",	"id":"nst",	"mw":-1,	"tname":"bnpcb55",]),
(["name":"翠烟门弟子",	"id":"cydz",	"mw":-1,	"tname":"bnpcb56",]),
(["name":"黑衣人",	"id":"hyr",	"mw":-1,	"tname":"bnpcb57",]),
(["name":"小队长",	"id":"xdz",	"mw":-1,	"tname":"bnpcb58",]),
(["name":"剑奴",	"id":"jn",	"mw":-1,	"tname":"bnpcb59",]),
(["name":"羽林校尉",	"id":"ylxw",	"mw":-1,	"tname":"bnpcb60",]),
(["name":"少林弟子",	"id":"sldz",	"mw":-1,	"tname":"bnpcb61",]),
(["name":"金国士兵",	"id":"jgsb",	"mw":-1,	"tname":"bnpcb62",]),
(["name":"铁浮图高手",	"id":"tftgs",	"mw":-1,	"tname":"bnpcb63",]),
(["name":"地堂刀头领",	"id":"tl",	"mw":-1,	"tname":"bnpcb64",]),
(["name":"做恶的养蜂人",	"id":"yfr",	"mw":-1,	"tname":"bnpcb65",]),
(["name":"宋军军需官",	"id":"jxg",	"mw":-1,	"tname":"bnpcb66",]),
(["name":"义军",	"id":"yj",	"mw":-1,	"tname":"bnpcb67",]),
(["name":"鬼主侍卫",	"id":"gwsw",	"mw":-1,	"tname":"bnpcb68",]),
(["name":"流寇首领",	"id":"lksl",	"mw":-1,	"tname":"bnpcb69",]),
(["name":"神智不清的赌客",	"id":"dk",	"mw":-1,	"tname":"bnpcb70",]),
(["name":"一品堂武士",	"id":"ybtws",	"mw":-1,	"tname":"bnpcb71",]),
(["name":"天忍细作",	"id":"tlxz",	"mw":-1,	"tname":"bnpcb72",]),
(["name":"刺客花魁",	"id":"ckhw",	"mw":-1,	"tname":"bnpcb73",]),
(["name":"迷魂手",	"id":"mhs",	"mw":-1,	"tname":"bnpcb74",]),
(["name":"狩魂居士",	"id":"shjs",	"mw":-1,	"tname":"bnpcb75",]),
(["name":"梵咒僧",	"id":"fzs",	"mw":-1,	"tname":"bnpcb76",]),
(["name":"羽灵祭祀",	"id":"yljs",	"mw":-1,	"tname":"bnpcb77",]),
(["name":"浪刀客",	"id":"ldk",	"mw":-1,	"tname":"bnpcb78",]),
(["name":"铁角蛮兵",	"id":"tjmb",	"mw":-1,	"tname":"bnpcb79",]),
(["name":"叛军矛手",	"id":"pjms",	"mw":-1,	"tname":"bnpcb80",]),
(["name":"铁首刀客",	"id":"tsdk",	"mw":-1,	"tname":"bnpcb81",]),
(["name":"绝顶高手 ",	"id":"jdgs",	"mw":-1,	"tname":"bnpcb82",]),
(["name":"暴动的家丁",	"id":"bdjd",	"mw":-1,	"tname":"bnpcb83",]),
(["name":"暴动的监工",	"id":"bdjg",	"mw":-1,	"tname":"bnpcb84",]),
(["name":"暴动的船夫",	"id":"bdcf",	"mw":-1,	"tname":"bnpcb85",]),
(["name":"采花贼 ",	"id":"chz",	"mw":-1,	"tname":"bnpcb86",]),
(["name":"红枪护卫",	"id":"hqhw",	"mw":-1,	"tname":"bnpcb87",]),
(["name":"敲诈的舵手",	"id":"qzds",	"mw":-1,	"tname":"bnpcb88",]),
(["name":"红枪侍女 ",	"id":"hqsn",	"mw":-1,"sex":1,	"tname":"bnpcb89",]),
(["name":"蒙古将领",	"id":"mgjl",	"mw":-1,	"tname":"bnpcb90",]),
(["name":"金国将领",	"id":"jgjl",	"mw":-1,	"tname":"bnpcb91",]),
(["name":"宋国将领",	"id":"sgjl",	"mw":-1,	"tname":"bnpcb92",]),
(["name":"西域妖术士",	"id":"yss",	"mw":-1,	"tname":"bnpcb93",]),
(["name":"神武军士",	"id":"swjs",	"mw":-1,	"tname":"bnpcb94",]),
(["name":"里乞部守卫",	"id":"sw",	"mw":-1,	"tname":"bnpcb95",]),
(["name":"无影义士",	"id":"wyys",	"mw":-1,	"tname":"bnpcb96",]),
(["name":"朝廷侍卫",	"id":"ctsw",	"mw":-1,	"tname":"bnpcb97",]),
(["name":"黑风寨精英",	"id":"hfjy",	"mw":-1,	"tname":"bnpcb98",]),
(["name":"盗墓蛮贼",	"id":"dmmz",	"mw":-1,	"tname":"bnpcb99",]),
(["name":"黑苗猎手",	"id":"hmls",	"mw":-1,	"tname":"bnpcb100",]),
(["name":"蛮女祭司",	"id":"mnjs",	"mw":-1,"sex":1,	"tname":"bnpcb101",]),
(["name":"白苗猎手",	"id":"blls",	"mw":-1,	"tname":"bnpcb102",]),
(["name":"苗岭守军",	"id":"mlsj",	"mw":-1,	"tname":"bnpcb103",]),
(["name":"长歌门仕子",	"id":"cgmsz",	"mw":-1,	"tname":"bnpcb104",]),
(["name":"江洋大盗",	"id":"jydd",	"mw":-1,	"tname":"bnpcb105",]),
(["name":"山西土匪",	"id":"jxtf",	"mw":-1,	"tname":"bnpcb106",]),
(["name":"江湖郎中",	"id":"jhlz",	"mw":-1,	"tname":"bnpcb107",]),
(["name":"鞑靼人使者",	"id":"ttrsz",	"mw":-1,	"tname":"bnpcb108",]),
(["name":"鞑靼人护卫",	"id":"ttrhw",	"mw":-1,	"tname":"bnpcb109",]),
(["name":"铁浮屠骑兵",	"id":"tftqb",	"mw":-1,	"tname":"bnpcb110",]),
(["name":"西夏军士",	"id":"xxjs",	"mw":-1,	"tname":"bnpcb111",]),
(["name":"西夏马贩",	"id":"xxmf",	"mw":-1,	"tname":"bnpcb112",]),
(["name":"蛮兵",	"id":"mb",	"mw":-1,	"tname":"bnpcb113",]),
(["name":"锦衣卫",	"id":"jyw",	"mw":-1,	"tname":"bnpcb114",]),
(["name":"拖雷部骑兵",	"id":"tlbqb",	"mw":-1,	"tname":"bnpcb115",]),
(["name":"大漠刀客",	"id":"dmdk",	"mw":-1,	"tname":"bnpcb116",]),
(["name":"走私的商队",	"id":"zssd",	"mw":-1,	"tname":"bnpcb117",]),
(["name":"东厂百户",	"id":"dcbh",	"mw":-1,	"tname":"bnpcb118",]),
(["name":"东厂千户",	"id":"dcqh",	"mw":-1,	"tname":"bnpcb119",]),
(["name":"黑水云骑兵",	"id":"hsyqb",	"mw":-1,	"tname":"bnpcb120",]),
(["name":"巨鲸帮帮众",	"id":"jjbbz",	"mw":-1,	"tname":"bnpcb121",]),
(["name":"清风寨强匪",	"id":"qfzqf",	"mw":-1,	"tname":"bnpcb122",]),
(["name":"清风寨强匪",	"id":"qfzqf",	"mw":-1,	"tname":"bnpcb123",]),
(["name":"护关铁骑兵 ",	"id":"hgtqb",	"mw":-1,	"tname":"bnpcb124",]),
(["name":"大内密探",	"id":"ddmt",	"mw":-1,	"tname":"bnpcb125",]),
(["name":"假武僧 ",	"id":"jws",	"mw":-1,	"tname":"bnpcb126",]),
(["name":"黑风寨喽罗 ",	"id":"hfzll",	"mw":-1,	"tname":"bnpcb127",]),
(["name":"巡院队长",	"id":"xydz",	"mw":-1,	"tname":"bnpcb128",]),
(["name":"窃贼",	"id":"qz",	"mw":-1,	"tname":"bnpcb129",]),
(["name":"襄阳官兵",	"id":"xxgb",	"mw":-1,	"tname":"bnpcb130",]),
(["name":"大宋禁军",	"id":"dsjj",	"mw":-1,	"tname":"bnpcb131",]),
(["name":"骗人的庙祝",	"id":"brmz",	"mw":-1,	"tname":"bnpcb132",]),
(["name":"落魄的杀手",	"id":"lpss",	"mw":-1,	"tname":"bnpcb133",]),
(["name":"流放的刀客",	"id":"lfdk",	"mw":-1,	"tname":"bnpcb134",]),
(["name":"流放的巫女",	"id":"lfwn",	"mw":-1,"sex":1,	"tname":"bnpcb135",]),
(["name":"落魄的武士",	"id":"lpws",	"mw":-1,	"tname":"bnpcb136",]),
(["name":"矿工工头",	"id":"kggt",	"mw":-1,	"tname":"bnpcb137",]),
(["name":"土山酋长",	"id":"tsqz",	"mw":-1,	"tname":"bnpcb138",]),
(["name":"小毛贼",	"id":"xmz",	"mw":-1,	"tname":"bnpcb139",]),
(["name":"带刀武士",	"id":"ddws",	"mw":-1,	"tname":"bnpcb140",]),
(["name":"弄蛇人",	"id":"nsr",	"mw":-1,	"tname":"bnpcb141",]),
(["name":"夷人刀客",	"id":"yrdk",	"mw":-1,	"tname":"bnpcb142",]),
(["name":"黑水刀客",	"id":"hsdk",	"mw":-1,	"tname":"bnpcb143",]),
(["name":"黑水剑士",	"id":"hsjs",	"mw":-1,	"tname":"bnpcb144",]),
(["name":"天字牢囚犯",	"id":"tzql",	"mw":-1,	"tname":"bnpcb145",]),
(["name":"地字牢狱卒",	"id":"dzyz",	"mw":-1,	"tname":"bnpcb146",]),
(["name":"金国将佐",	"id":"jgjz",	"mw":-1,	"tname":"bnpcb147",]),
(["name":"穴居男野人",	"id":"yr",	"mw":-1,	"tname":"bnpcb148",]),
(["name":"穴居女野人",	"id":"nyr",	"mw":-1,"sex":1,	"tname":"bnpcb149",]),
(["name":"骑马武士",	"id":"qmws",	"mw":-1,	"tname":"bnpcb150",]),
(["name":"巫术士",	"id":"wss",	"mw":-1,	"tname":"bnpcb151",]),
(["name":"红衣人",	"id":"hyr",	"mw":-1,	"tname":"bnpcb152",]),
(["name":"小偷",	"id":"xt",	"mw":-1,	"tname":"bnpcb153",]),
(["name":"假冒僧人",	"id":"jmsr",	"mw":-1,	"tname":"bnpcb154",]),
(["name":"潜逃僧人",	"id":"qtsl",	"mw":-1,	"tname":"bnpcb155",]),
(["name":"山南暴民",	"id":"snbm",	"mw":-1,	"tname":"bnpcb156",]),
(["name":"乌衣剑士",	"id":"wyjs",	"mw":-1,	"tname":"bnpcb157",]),
(["name":"行凶者头目",	"id":"xxztm",	"mw":-1,	"tname":"bnpcb158",]),
(["name":"南夷勇士",	"id":"nyys",	"mw":-1,	"tname":"bnpcb159",]),
(["name":"南夷祭司",	"id":"nyjs",	"mw":-1,	"tname":"bnpcb160",]),
(["name":"土著巫女",	"id":"tzwn",	"mw":-1,"sex":1,	"tname":"bnpcb161",]),
(["name":"暴动的饥民",	"id":"bdjm",	"mw":-1,	"tname":"bnpcb162",]),
(["name":"云游侠客",	"id":"yyxk",	"mw":-1,	"tname":"bnpcb163",]),
(["name":"杀人的猎户",	"id":"srlh",	"mw":-1,	"tname":"bnpcb164",]),
(["name":"行凶者",	"id":"xxz",	"mw":-1,	"tname":"bnpcb165",]),
(["name":"精锐剑士",	"id":"jrjs",	"mw":-1,	"tname":"bnpcb166",]),
(["name":"山北盗匪",	"id":"sbdf",	"mw":-1,	"tname":"bnpcb167",]),
(["name":"阴剑士",	"id":"yjs",	"mw":-1,	"tname":"bnpcb168",]),
(["name":"螳螂拳师",	"id":"trqs",	"mw":-1,	"tname":"bnpcb169",]),
(["name":"阳剑士",	"id":"yjs",	"mw":-1,	"tname":"bnpcb170",]),
(["name":"游军刀兵",	"id":"yjdb",	"mw":-1,	"tname":"bnpcb171",]),
(["name":"唐家毒使",	"id":"tjds",	"mw":-1,	"tname":"bnpcb172",]),
(["name":"唐家弩手 ",	"id":"tjns",	"mw":-1,	"tname":"bnpcb173",]),
(["name":"霹雳火雷家门人",	"id":"plmr",	"mw":-1,	"tname":"bnpcb174",]),
(["name":"护陵枪兵",	"id":"hlqb",	"mw":-1,	"tname":"bnpcb175",]),
(["name":"护陵弩手",	"id":"hlns",	"mw":-1,	"tname":"bnpcb176",]),
(["name":"锐捷营辎兵",	"id":"rjyzb",	"mw":-1,	"tname":"bnpcb177",]),
(["name":"锐捷营精锐 ",	"id":"rjyjr",	"mw":-1,	"tname":"bnpcb178",]),
(["name":"行脚商人",	"id":"xjsr",	"mw":-1,	"tname":"bnpcb179",]),
(["name":"南蛮刀客",	"id":"nmdk",	"mw":-1,	"tname":"bnpcb180",]),
(["name":"南蛮巫女",	"id":"nmwn",	"mw":-1,"sex":1,	"tname":"bnpcb181",]),
(["name":"神秘商人",	"id":"smsr",	"mw":-1,	"tname":"bnpcb182",]),
(["name":"大内高手",	"id":"dngs",	"mw":-1,	"tname":"bnpcb183",]),
(["name":"大内总管",	"id":"dnzg",	"mw":-1,	"tname":"bnpcb184",]),
(["name":"水匪渔夫",	"id":"sfyf",	"mw":-1,	"tname":"bnpcb185",]),
(["name":"吴家军刀斧手 ",	"id":"wjfs",	"mw":-1,	"tname":"bnpcb186",]),
(["name":"吴家军步枪手 ",	"id":"wjqs",	"mw":-1,	"tname":"bnpcb187",]),
(["name":"钱氏匪兵",	"id":"qsfb",	"mw":-1,	"tname":"bnpcb188",]),
(["name":"蒙古大夫",	"id":"mgdf",	"mw":-1,	"tname":"bnpcb189",]),
(["name":"大力士",	"id":"dls",	"mw":-1,	"tname":"bnpcb190",]),
(["name":"麻衣神相",	"id":"mysx",	"mw":-1,	"tname":"bnpcb191",]),
(["name":"强贼头目",	"id":"qxtm",	"mw":-1,	"tname":"bnpcb192",]),
(["name":"马贼",	"id":"mz",	"mw":-1,	"tname":"bnpcb193",]),
(["name":"叛乱的衙役",	"id":"plya",	"mw":-1,	"tname":"bnpcb194",]),
(["name":"云游僧人",	"id":"yysr",	"mw":-1,	"tname":"bnpcb195",]),
(["name":"刑部捕头",	"id":"xbbt",	"mw":-1,	"tname":"bnpcb196",]),
(["name":"闹事的菜贩",	"id":"nscf",	"mw":-1,	"tname":"bnpcb197",]),
(["name":"官府捕快",	"id":"gfbk",	"mw":-1,	"tname":"bnpcb198",]),
(["name":"白虎堂护卫",	"id":"bhthw",	"mw":-1,	"tname":"bnpcb199",]),
(["name":"船帮帮众",	"id":"cbbz",	"mw":-1,	"tname":"bnpcb200",]),
});




 


void create()
{
	mapping npc;
	string weapon,tname;
	npc=data[124+random(2)];
	//weapon=npc["weapon"];

	set_name(order[random(13)] +npc["name"]+NOR,({ npc["id"] }));
	tname=npc["tname"];
	set("tname",tname);
	set("age",20+random(30));
	set("gender", "男性");
	if (npc["sex"]) set("gender", "女性");
set("str",25+random(5));
set("dex",25+random(5));
set("con",25+random(5));
set("int",25+random(5));
set("per",25+random(5));
set("kar",25+random(5));
	set("combat_exp",371694959);

	set("max_jing",500);
	set("max_qi",500);
	set("max_neili",1000);
	set_skill("sword",30);
	set_skill("blade",30);
	set_skill("unarmed",30);
	set_skill("sword",30);
	set_skill("club",30);
	set_skill("whip",30);
	set_skill("throwing",30);
	set_skill("parry",30);
	set("mgnpc",1);
	set_skill("dodge",30);
	//set("shen_type",npc["mw"]);

	setup();
	//carry_object("/clone/misc/cloth")->wear();
	initlvl(658,62+random(2));
	this_object()->delete("nickname");
	//if( weapon)
	//	carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",18+random(20));
}
       
void unconcious()
{
    die();
}

void die()
{
	string msg;
int i,pot,exp,shen;
	object killer;
	exp= random(188)+188+(187*2);
	pot= exp*2/3+1;
	if( objectp(killer = query_temp("last_damage_from")))
{
	if (userp(killer))
{
	killer->add_temp(this_object()->query("tname"),1);
if (killer->query("shen",1)>=0) shen=random(50)+10;
if (killer->query("shen",1)<0) shen=-random(60);
                msg =  "你获得了:";
        if (exp > 0) msg += chinese_number(exp) + "点经验 ";
        if (pot > 0) msg += chinese_number(pot) + "点潜能 ";
        if (shen > 0) msg += chinese_number(shen) + "点正神 ";
        if (shen < 0) msg += chinese_number(-shen) + "点负神 ";
        killer->add("combat_exp", exp);
        killer->add("potential", pot);
        killer->add("shen", shen);
 tell_object(killer, msg);
}
}
	::die();

return ;
}

void setn(int rw)
{
	mapping npc;
        object ob = this_object();
	npc=data[rw];
		ob->set_name(order[random(13)] +npc["name"]+NOR,({ npc["id"] }));
}

void init()
{
        remove_call_out("leave");
        call_out("leave",66);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}