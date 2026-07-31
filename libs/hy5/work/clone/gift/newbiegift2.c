#include <ansi.h>
inherit ITEM;
string *w_object=({
"/clone/box/new/ar1",
"/clone/box/new/ar10",
"/clone/box/new/ar11",
"/clone/box/new/ar12",
"/clone/box/new/ar13",
"/clone/box/new/ar14",
"/clone/box/new/ar15",
"/clone/box/new/ar16",
"/clone/box/new/ar17",
"/clone/box/new/ar18",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/bt1",
"/clone/box/new/bt10",
"/clone/box/new/bt11",
"/clone/box/new/bt12",
"/clone/box/new/bt13",
"/clone/box/new/bt14",
"/clone/box/new/bt15",
"/clone/box/new/bt16",
"/clone/box/new/bt17",
"/clone/box/new/bt18",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/h1",
"/clone/box/new/h10",
"/clone/box/new/h11",
"/clone/box/new/h12",
"/clone/box/new/h13",
"/clone/box/new/h14",
"/clone/box/new/h15",
"/clone/box/new/h16",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/hd1",
"/clone/box/new/hd10",
"/clone/box/new/hd11",
"/clone/box/new/hd12",
"/clone/box/new/hd13",
"/clone/box/new/hd14",
"/clone/box/new/hd15",
"/clone/box/new/hd16",
"/clone/box/new/hd17",
"/clone/box/new/hd18",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/nk1",
"/clone/box/new/nk10",
"/clone/box/new/nk11",
"/clone/box/new/nk12",
"/clone/box/new/nk13",
"/clone/box/new/nk14",
"/clone/box/new/nk15",
"/clone/box/new/nk16",
"/clone/box/new/nk17",
"/clone/box/new/nk18",
"/clone/box/new/nk2",
"/clone/box/new/nk3",
"/clone/box/new/nk4",
"/clone/box/new/nk5",
"/clone/box/new/nk6",
"/clone/box/new/nk7",
"/clone/box/new/nk8",
"/clone/box/new/nk9",
"/clone/box/new/sc1",
"/clone/box/new/sc10",
"/clone/box/new/sc11",
"/clone/box/new/sc12",
"/clone/box/new/sc13",
"/clone/box/new/sc14",
"/clone/box/new/sc15",
"/clone/box/new/sc16",
"/clone/box/new/sc17",
"/clone/box/new/sc18",
"/clone/box/new/sc2",
"/clone/box/new/sc3",
"/clone/box/new/sc4",
"/clone/box/new/sc5",
"/clone/box/new/sc6",
"/clone/box/new/sc7",
"/clone/box/new/sc8",
"/clone/box/new/sc9",
"/clone/box/new/sd1",
"/clone/box/new/sd10",
"/clone/box/new/sd11",
"/clone/box/new/sd12",
"/clone/box/new/sd13",
"/clone/box/new/sd14",
"/clone/box/new/sd15",
"/clone/box/new/sd16",
"/clone/box/new/sd17",
"/clone/box/new/sd18",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/wi1",
"/clone/box/new/wi10",
"/clone/box/new/wi11",
"/clone/box/new/wi12",
"/clone/box/new/wi13",
"/clone/box/new/wi14",
"/clone/box/new/wi15",
"/clone/box/new/wi16",
"/clone/box/new/wi17",
"/clone/box/new/wi18",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wt1",
"/clone/box/new/wt10",
"/clone/box/new/wt11",
"/clone/box/new/wt12",
"/clone/box/new/wt13",
"/clone/box/new/wt14",
"/clone/box/new/wt15",
"/clone/box/new/wt16",
"/clone/box/new/wt17",
"/clone/box/new/wt18",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
});

void setup()
{}

void init()
{
	add_action("do_eat", "openbeg");
}

void create()
{
	set_name(GRN"新手装备包"NOR, ({"newbie beg", "newbiebeg"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个新手装备包。似乎可以打开(openbeg)。\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
set("liwu",1);
    set("no_steal", 1);
    set("no_get", 1);
    set("no_give","每个人只有一个，你都这么大方！\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
set("no_pawn",1);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要打开什么？\n");



 	if (me->query("ishyover"))
{
	return notify_fail("你已经领过了!\n");
//destruct(this_object());
}

message_vision(HIY "$N打开了新手装备包!获得了很多宝贝!\n" NOR, me);

//me->set("ishyover",1);




corpse=new("/clone/money/gold");
corpse->set_amount(1000);
corpse->move(me);
tell_object(me,HIY"你找到了一些黄金!\n"+NOR);




/*corpse=new("/p/newweapon/weaponobj/buliao1");
corpse->move(me);
corpse=new("/p/newweapon/weaponobj/kuangshi1");
corpse->move(me);
corpse=new("/p/newweapon/weaponobj/material7");
corpse->move(me);

tell_object(me,HIY"你找到了一些打造防具的材料!\n"+NOR);
*/
corpse=new("/p/newweapon/weaponobj/kuangshi1");
corpse->move(me);
corpse=new("/p/newweapon/weaponobj/kuangshi1");
corpse->move(me);
corpse=new("/p/newweapon/weaponobj/material1");
corpse->move(me);


tell_object(me,HIY"你找到了一些打造武器的材料!\n"+NOR);

	
	destruct(this_object());
	return 1;
}