// Define the attack messages of this type of troop
// and give the basic damage it caused
// $G refers to the general in charge of the troop
// $g refers to the general in charge of the enermy
// $N refers to itself and $n refers to enermy troop
#include <ansi.h>
private mapping *do_attack = ({
	(["msg":HIB"新兵队散乱的组成一道人墙，向敌人涌去。"NOR,
	  "damage": 3,]),
        (["msg":HIY"新兵队呐喊着向敌军勇猛的冲了过去。"NOR,
          "damage": 4,]),
        (["msg":HIG"新兵队胆怯的聚集成群，朝敌军涌去。"NOR,
          "damage": 2,]),
});
mixed query_attack(string environment)
{ 
        return do_attack;
}
string query_id()
{
	return "footman";
}
string query_name()
{
	return "新兵";
}
string query_type()
{
	return "footman";
}
// Attack bonus, when attack some troop
// it is a percentage value and can be positive or negative
mapping query_special_attack()
{
	return ([
	]);
}
// Defence bonus when attacked by some troop
mapping query_special_defence()
{
	return ([
	]);
}
// Defence ablility of arrow attack
int query_arrow_defence(string environment, int zhenfa)
{
	return 0;
}
// Get the some basic data for combat, now it includes
// energy recover, energy lost, basic attck ability and
// basic defence ability. all the items are affect by
// three factors, enrionment, weeather and zhenfa
int query_energy_recover(string environment, int weather, int zhenfa)
{
        int cost;

        if( environment == "∧" ) cost = 5;
        else if ( environment == "～" ) cost = 3;
        else if ( environment == "．" ) cost = 5;
        else if ( environment == "＊" ) cost = 5;
        else cost = 5;

        if( weather == 0 ) cost = cost + 1;
        else if( weather == 7 ) cost = cost + 2;
        else if( weather == 8 ) cost = cost + 3;
        else cost = cost + 1;

        if( zhenfa = 0 ) cost = cost - 2;
        else cost = cost - 1;
	if (cost<1) cost=1;
        return cost;
}
int query_energy_cost(string environment, int weather, int zhenfa)
{
	int cost;

	if( environment == "∧" ) cost =20;
	else if ( environment == "～" ) cost = 22;
	else if ( environment == "．" ) cost = 20;
	else if ( environment == "＊" ) cost = 20;
	else cost = 20;

	if( weather == 0 ) cost = cost - 2;
	else if( weather == 2 ) cost = cost + 1;
	else if( weather == 3 ) cost = cost + 2;
	else cost = cost;

	if( zhenfa = 0 ) cost = cost - 2;
	else cost = cost - 1;
	
	return cost;
}
int query_basic_defence(string environment, int weather, int zhenfa)
{
}
int query_basic_attack(string environment, int weather, int zhenfa)
{
}
// Give types of environments where this type of troop
// can not enter
string *query_forbiden()
{
	return ({"※", });
}
// Special abilily of the troop such as bowman can use
// bow and arrow to attack
void powerup()
{
}
// Can it be upgrated and what are the requirements ?
mapping do_upgrade()
{
	return ([
		"infantry": (["train":60, "weapon":({"tie jia",}),]),
		"cavalry": (["train":90, "weapon":({"horse",}),]),
		"bowman": (["train":80, "weapon":({"bow",}),]),
		"seaman": (["train":70, "weapon":({"water suit",}),]),
		"thief": (["train":70, "weapon":({"dagger",}),]),
	]);
}
// Troops consume money and food, more powerful
// troop needs more
mapping query_cost()
{
	return ([
		"gold": 0.2,
		"food": 1,
	]);
}
// Some type of troops can only be recruited in
// particular cities, NONE means all cities can
string *get_city()
{
	return ({ });
}
// Recruitment cost
mapping query_recruit()
{
	return ([
		"gold": 0.2,
	]);
}

