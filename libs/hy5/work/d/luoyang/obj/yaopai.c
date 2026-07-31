// yaopai.c

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name("腰牌", ({ "yao pai", "yaopai" }));
	set("long", "这是一块帮会的腰牌。\n"+
"    凭此腰牌，可以提升(tisheng) 和降黜(jiangchu)本帮会内所有
下属人众，甚至将其驱逐(quzhu) 出帮会。被驱逐者损失一定存款和
阅历。如果对本帮会十分失望，可以自行退出(tuichu)所属帮会，代
价一定的存款和阅历。
     帮(门、教)主无法退会。但可以让位(rangwei) 给本帮会众，
功成身退。对于违命背叛的下属，可以限时派出本帮会刑堂的执法弟
子前往惩处(chengchu)。
    如果想提升一位非本帮会人员成为本帮一般人众，被提升者为表
示忠诚之决心，必须先割一个脑袋瓜来作为加盟投名状。
    所有入会人等均能获得一块腰牌，并按自己的权限凭腰牌行使上
述权力。
      教(帮、门)主    提升 降黜 惩处 驱逐 任命 创立 让位
      副教(帮、门)主  提升 降黜 惩处 驱逐 退出
      长老            提升 降黜 惩处 退出
      香主            提升 降黜 退出
      旗主            退出
      一般人众        退出
其中第三、四、五阶层人等可以任命(renming)专名。如传功长老、
红旗香主、风云旗主等等。任何人等均可用party命令查阅本帮会名
单。
    如果不幸丢失本腰牌，可以到关林对着关夫子像猛磕头(ketou)，
好好思过。
\n");
	set("weight", 300);
	set("no_get", 1);
	set("no_get_from", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 1);
		set("material", "玉");
	}
	setup();
	init_dagger(555);
}

