
#include <ansi.h>
#include <login.h>
#include <command.h>

inherit ROOM;

int is_chat_room() { return 1; }

int do_wash(string arg);
int do_washto(string arg);
int do_born(string arg);
int do_pianshu(string arg);

mapping born = ([
	"关外人氏" : "/d/guanwai/kedian",
	"燕赵人氏" : "/d/beijing/kedian",
	"齐鲁人氏" : "/d/taishan/kedian",
	"秦晋人氏" : "/d/changan/kezhan",
	"中原人氏" : "/d/shaolin/kedian1",
	"西域人氏" : "/d/xingxiu/kedian",
	"荆州人氏" : "/d/xiangyang/kedian",
	"扬州人氏" : "/d/city/kedian",
	"苏州人氏" : "/d/suzhou/kedian",
	"杭州人氏" : "/d/hangzhou/kedian",
	"福建人氏" : "/d/fuzhou/kedian",
	"巴蜀人氏" : "/d/city3/kedian",
	"云南人氏" : "/d/dali/kedian",
	"两广人氏" : "/d/foshan/beidimiao",
	"欧阳世家" : ([ "born"      : "西域人氏",
			"surname"   : "欧阳",
			"startroom" : "/d/baituo/dating",
		     ]),
	"关外胡家" : ([ "born"      : "关外人氏",
			"surname"   : "胡",
			"startroom" : "/d/guanwai/xiaowu",
		     ]),
	"段氏皇族" : ([ "born"      : "大理人氏",
			"surname"   : "段",
			"startroom" : "/d/dali/wangfugate",
		     ]),
	"慕容世家" : ([ "born"      : "江南人氏",
			"surname"   : "慕容",
			"startroom" : "/d/yanziwu/cuixia",
		     ]),
]);

void create()
{
	int i, k;
	string desc;
	string *position;

	set("short", HIR "阎罗殿" NOR);
	set("long", @LONG
这里阴深恐怖，让人感觉到一阵阵的寒意，两旁列着牛头马面，冥
府狱卒，各个威严肃穆。十殿阎罗，尽皆在此，地藏王坐在大堂之上，
不怒自威，你的腿脚不禁都有些软了。
    大殿角落有一个石头砌成的池子，其中水清澈却不见底，不知道它
究竟有多深。
    旁边有几个牌子，你也许应该仔细看看。
LONG );
	set("no_fight", 1);

	set("objects", ([
		__DIR__"npc/dizangwang" : 1,
	]));

	set("no_say", "阎罗殿内阴森恐怖，你哪里敢乱说话？\n");


	setup();
}

