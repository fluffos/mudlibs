// gems - by xbd
// modified by Vast@pkuxkx
// all comments added by Vast.

#include <ansi.h>

inherit ITEM;
inherit F_GEMS;

void set_level(int min, int number, string gem);
void generate_newweapon(object ob, string material, int lev);
void generate_newarmor(object ob, string material, int lev);
void generate_newring(object ob, string material, int lev);

int is_gem() {return 1;}// /feature/gems.c閲岄潰鏄痠s_gems()


void create()
{
	int lev, i;
	string gem, s;
	object me = this_player();

	//绉嶇被涓嶅お閲嶈锛岀洿鎺ヨ瀹?
	i = random(19);
	if (i < 3) gem = "ruby";
	else if (i < 6) gem = "topaz";
	else if (i < 9) gem = "sapphire";
	else if (i < 12) gem = "emerald";
	else if (i < 15) gem = "amethyst";
	else if (i < 18) gem = "diamond";
	else gem = "skull";//skull鐨勫嚭鐜板嚑鐜囦负鍏朵綑瀹濈煶鐨?/3

	//绛夌骇姣旇緝閲嶈锛屽彲浠ヤ汉涓鸿瀹氫笂锛屼笅闄?
	set_level(0, 10000, gem);

	setup();
}
void set_level(int min, int number, string gem)
{
	int lev, i;

	if (min > number) return;
	if (min < 0) return;
	if (number > 10000) return;

	i = min + random(number - min + 1);
	//鏄剧劧濡傛灉min == number鍒欏彲浠ョ簿纭‘瀹氬疂鐭崇殑绛夌骇

	if (i < 5000) lev = 1;		//浜屽垎涔嬩竴
	else if (i < 8335) lev = 2;	//涓夊垎涔嬩竴
	else if (i < 9445) lev = 3;	//涓囧垎涔嬩竴鍗冧竴鐧句竴鍗?11.1%)
	else if (i < 9815) lev = 4;	//涓囧垎涔嬩笁鐧句竷鍗?3.7%)
	else if (i < 9940) lev = 5;	//涓囧垎涔嬩竴鐧句簩鍗佷簲(1.25%)
	else if (i < 9980) lev = 6;	//涓囧垎涔嬪洓鍗?0.4%)
	else if (i < 9995) lev = 7;	//涓囧垎涔嬪崄浜?0.15%)
	else lev = 8;			//涓囧垎涔嬩簲(0.05%)
	//璇蜂笉瑕侀殢鎰忔敼鍔ㄤ互涓婃暟鎹?

	set_name(query_gem_name(gem, lev), ({query_gem_id(gem, lev), "gem"}));
	set_weight( 100 * lev * lev);
	set("long", query_all_effect(gem, this_object()));
	set("unit", "棰?);
	//鍙兘鍦ㄤ笓闂ㄧ殑鍦版柟杩涜涔板崠
	set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
	set("value", 2000 * lev * lev * lev);//浠峰€间笉鑿?
	set("material", gem);
	set("level", lev);
}