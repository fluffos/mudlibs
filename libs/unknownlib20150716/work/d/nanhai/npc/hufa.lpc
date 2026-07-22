// heaven_soldier.c
#include <ansi.h>
inherit HUFA;

mapping Name = ([
	"士乌刍君荼鸯俱尸" : ({"密迹金刚","忿怒面，赤肉色，左手插腰，右手持三钴杵，身着甲胄。\n"}),
	"赏迦罗" : ({"八部力士","面极忿怒，赤肉色，左手安腰，右手掌向外，腰着青衣。\n"}),
	"摩醯那罗延" : ({"二十八部","头着金刚甲，左手当胸掌向外，右手舒肘向前，取大刀刺地。\n",}),
	"迦毗罗" : ({"金刚陀罗","面及身色同前，左手安腰，右手向胸掣大刀，身着甲胄。\n",}),
	"婆馺娑楼罗" : ({"二十八部","面白黄色，忿怒形，头着金甲，左手举于胸前，掌向外，指端垂下，右手握大刀，着甲胄。\n"}),
	"满善车钵真陀罗" : ({"二十八部","面作微笑形，左手握拳安腰，右手当胸取莲华，着青色袈裟。\n",}),
	"萨遮摩和罗" : ({"二十八部","面呈微笑且稍带怒，头着天冠，微举左臂，仰掌舒五指，右手当胸持斧钺，庄严如天女。\n"}),
	"鸠兰单咤半只罗" : ({"二十八部","面带微笑，青色，左手当胸，覆掌舒五指，右臂垂下持大刀，身着甲胄。\n"}),
	"毕婆伽罗王" : ({"二十八部","面现微笑又带怒，白赤色，头有金甲，左手握拳安脐，右手持三戟，着金胄。\n"}),
	"应德毗多萨和罗" : ({"二十八部","轻微忿怒面，头有玉冠，左右手各持独钴杵。\n"}),
	"梵摩三钵罗" : ({"二十八部","面如天女，头戴天冠，左手安脐边，右手当胸持白拂，璎珞庄严如天人。\n"}),
	"炎摩罗" : ({"二十八部","忿怒面，仰视上空，青绿色，左手当胸，右手舒臂覆掌，五指散开安腰下。\n"}),
	"释王" : ({"二十八部","左手握拳安腰，右手持独钴杵，着草鞋。\n"}),
	"娑怛那" : ({"大辩功德","如吉祥天女，左手举臂，持赤莲华，右手当胸，掌向外，捻大指、头指。\n"}),
	"提头赖咤王" : ({"二十八部","忿怒面，左手安腰，右臂上举持三钴杵，身着甲胄。\n"}),
	"神母女" : ({"大力众","仰左掌于胸前，右掌向外捻大指、头指。\n"}),
	"毗楼勒叉" : ({"二十八部","左臂上举持三戟，右手安腰持大刀，身着甲胄。\n"}),
	"毗楼东博叉毗沙门" : ({"二十八部","左手持塔，右手持三钴戟。\n"}),
	"金色孔雀王" : ({"二十八部","雀头人身，左右手各持孔雀足一只以为杖。\n"}),
	"大仙众" : ({"二十八部","仙人形，左臂上举持经卷，右手当胸持杖。\n"}),
	"摩尼跋陀罗" : ({"二十八部","面如天人貌，赤发，以花严饰，二手合掌。\n"}),
	"弗罗婆" : ({"散支大将","微笑忿怒面，白色，头戴天冠，左手当胸，以大指捻头中二指，右手持大刀。\n"}),
	"难陀跋难陀" : ({"二十八部","面极忿怒，青绿色，头上有龙，左手上举于胸前，掌心向外垂五指，右手安腰执三戟，身着甲胄。\n"}),
	"伊钵罗" : ({"娑伽罗龙","忿怒面，青黑色，以二手持大刀刺地。\n"}),
	"乾闼婆" : ({"修罗","三面六臂，各面有三目，白色，左右第一手当胸合掌，左第二手持莲华，右第二手持轮，第三手左右臂共举持日轮。\n"}),
	"迦楼紧那摩侯罗" : ({"二十八部","面极忿怒，白赤色，头上戴白马头，左手插腰，右手高举于头，横持大刀，着甲胄。\n"}),
	"水雷电神" : ({"二十八部","面极忿怒，赤黑色，左手覆掌于胸前，右手舒臂散五指，作压地状，立于黑浪中。\n"}),
	"水雷电神" : ({"二十八部","面如恶鬼形，青色，二手胸前内缚，舒二中指，屈头指相拄，立于波浪中。\n"}),
	"毗舍阇" : ({"鸠槃荼王","鸠槃荼王系黑色长鼻嗔怒形，左持战具，右执索；毗舍阇系黑赤色大目嗔怒形。左手持火玉。\n"}),
]);

varargs void setskills(int i)
{
	string *names,name,long,title;
	int k;
	names = keys(Name);
	k = random(sizeof(names));
	name = names[k];
	title = Name[name][0];
	long = Name[name][1];
	set_name(name,({"ershiba buzhong","hufa",}));
	set("look_msg",long);
	create_family("南海普陀山", 3, "红");	
	set("title",title);
	set("gender","男性");
	set("receive_damage",1);
	set("receive_wound",1);
	set_skill("literate", i);
	set_skill("spells", i);
	set_skill("buddhism", i);
	set_skill("unarmed", i);
	set_skill("jienan-zhi", i);
	set_skill("dodge", i);
	set_skill("lotusmove", i);
	set_skill("parry", i);
	set_skill("force", i);
	set_skill("lotusforce", i);
	set_skill("staff", i);
	set_skill("blade", i);	
	set_skill("cibeidao", i);	
	set_skill("lunhui-zhang", i);
	map_skill("spells", "buddhism");
	map_skill("blade", "cibeidao");	
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");	
	set("max_force",query_skill("force")*10);
	set("max_mana",query_skill("spells")*10);
	if( this_object()->query_level()<70 )
	{
		add_temp("apply/max_kee",500);
		add_temp("apply/max_sen",500);
	}
	else if( this_object()->query_level()<90 )
	{
		add_temp("apply/max_kee",800);
		add_temp("apply/max_sen",800);
	}
	else
	{
		add_temp("apply/max_kee",1000);
		add_temp("apply/max_sen",1000);
	}
}

string query_hufa_msg()
{
	return HIY"金光一闪，"+this_object()->name()+HIY"已挡在了$N"HIY"身前，替$P抵挡了$n"HIY"的部分攻击。\n"NOR;
}