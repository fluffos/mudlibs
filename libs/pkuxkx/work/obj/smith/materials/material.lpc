inherit ITEM;
#include <ansi.h>
string *names=({"坤地","艮山","坎水","巽風","震雷","離火","兌澤","乾天"});
string *all_colors = ({NOR, RED, BLU, GRN, YEL, CYN, MAG, HIW});
string *ids=({"kundi","genshan","kanshui","xunfeng","zhenlei","lihuo","duize","qiantian"});
string *types=({"short","medium","long","entire"});
string *units=({"块","条","根","副"});
string *allows=({"匕、盔","刀、剑、鞭","杖、斧、枪、锤、戟","铠甲、盾"});
void init_material(int level,int type)
{
	if (level<0||level>7) level=random(8);
	if (type<0||type>3) type=random(4);
	set_name(all_colors[level]+names[level]+"之材"+NOR,({ids[level]+" zhicai",ids[level],"cai"}));
	set("unit",units[type]);
	set("level",1+level);
	set("long","这是一"+units[type]+query("name")+"，可以用来打造"+allows[type]+"类。\n");
	set("type",types[type]);
	set("true_value",(level+5)*10);
}
void refine()
{
	set("advanced",1);
	set_name(all_colors[query("level")-1]+names[query("level")-1]+"精材"+NOR,({ids[query("level")-1]+" jingcai",ids[query("level")-1],"cai"}));
}
void create()
{
        set_name("材料", ({"cai"}));
        set("material", "iron");
		set("value",0);
		set("unit","件");
		set("is_castmaterial",1);
		set("type","medium");
		set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
		set("no_sell_in_playershop",1);
        setup();
		init_material(0,0);
}


