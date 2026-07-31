#include <armor.h>
#include <ansi.h>
inherit ITEM;
void create()
{        set_name("龙元", ({ "dragon soul" }) );
        set_weight(1);
        if( clonep() )
set_default_object(__FILE__);
        else {
                set("long","这是龙的内丹，鸡蛋大小，如火焰般赤红。\n");
                set("unit", "颗");
                set("value", 50000);
                //set("no_drop",1);
				}
setup();}

void init(){
  if(this_player()==environment())
add_action("boost_skill","eat");
}

int boost_skill(){
	int force_limit, neili_limit, force_skill, add_skill, improve;
	object ob, *list, couple_ob;
	string theskill;
	int thelevel = 0;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
	int i, marry_flag;
	ob = this_player();
    skl = ob->query_skills();
    force_limit = ob->query_skill("force")*10;
	neili_limit = ob->query("max_neili");
    force_skill = ob->query_skill("force", 1);

	if(ob->query("baoji") <= 2000)
	{
		improve = 10+random(10);
		ob->add("baoji", improve);
		write( "你的武学镜界得到了提升，会心一击率提高"+improve+"点。\n");
	}else
	{
		write( "龙元的帮助已到上限。\n");
	}

	if(!sizeof(skl))
	{
		write( "你目前并没有学会任何技能。\n");
        return 1;
	}

	sname  = sort_array( keys(skl), (: strcmp :) );
	map = ob->query_skill_map();
	if( mapp(map) )
		mapped = values(map);
	if( !mapped )
		mapped = ({});
        lrn = ob->query_learned();
	if( !mapp(lrn) )
		lrn = ([]);

	for(i=0; i<sizeof(skl); i++)
	{
		if(random(skl[sname[i]]) > random(thelevel))
		{
			theskill = sname[i];
			thelevel = skl[sname[i]];
		}
	}
	ob->set_skill(theskill, (int)thelevel+1);

	message_vision("$N的"+to_chinese(theskill)+"增强了。\n", this_player());
	destruct(this_object());
	return 1;

}