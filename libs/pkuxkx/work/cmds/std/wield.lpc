// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);
int non_query_func(object me,int para)
{
	switch (para)
	{
	case 0:
	return me->query_str();
	case 1:
	return me->query_con();
	case 2:
	return me->query_dex();
	case 3:
	return me->query_int();
	}
}
int legal_wield(object me,object ob)
{
	mapping restricts;
	mixed *attributes;
	string *legal_non_query_type=({"query_str","query_con","query_dex","query_int"});
	if (objectp(me->query_temp("weapon"))&&me->query_temp("weapon")->query("wield_restrict/double_hand"))
	{
		tell_object(me,"你正装备着"+me->query_temp("weapon")->query("name")+"，腾不出手来拿其他武器了。\n");
		return -1;
	}
	if (objectp(me->query_temp("secondary_weapon"))&&me->query_temp("secondary_weapon")->query("wield_restrict/double_hand"))
	{
		tell_object(me,"你正装备着"+me->query_temp("secondary_weapon")->query("name")+"，腾不出手来拿其他武器了。\n");
		return -1;
	}
	if (!mapp(ob->query("wield_restrict")))
	return 1;
	restricts=ob->query("wield_restrict");
	attributes=keys(restricts);
	for (int i=0;i<sizeof(attributes);i++)
	{
		if (attributes[i]=="double_hand")//双手武器
		{
			if (me->query_temp("weapon")||me->query_temp("secondary_weapon"))
			{
				tell_object(me,ob->query("name")+"必须腾出双手才能装备起来。\n");
				return -1;
			}
			continue;
		}
		if (member_array(attributes[i],legal_non_query_type)!=-1)
		{
			if (non_query_func(me,member_array(attributes[i],legal_non_query_type))<restricts[attributes[i]][1])
			{
				tell_object(me,"由于你的"+restricts[attributes[i]][0]+"小于"+restricts[attributes[i]][1]+"，所以暂时不能装备"+ob->query("name")+"。\n");
				return -1;
			}
			if (non_query_func(me,member_array(attributes[i],legal_non_query_type))>restricts[attributes[i]][2]&&restricts[attributes[i]][2]!=-1)
			{
				tell_object(me,"由于你的"+restricts[attributes[i]][0]+"高于"+restricts[attributes[i]][2]+"，所以暂时不能装备"+ob->query("name")+"。\n");
				return -1;
			}
			continue;
		}
		if (me->query(attributes[i])<restricts[attributes[i]][1])
		{
			tell_object(me,"由于你的"+restricts[attributes[i]][0]+"小于"+restricts[attributes[i]][1]+"，所以暂时不能装备"+ob->query("name")+"。\n");
			return -1;
		}
		if (me->query(attributes[i])>restricts[attributes[i]][2]&&restricts[attributes[i]][2]!=-1)
		{
			tell_object(me,"由于你的"+restricts[attributes[i]][0]+"大于"+restricts[attributes[i]][2]+"，所以暂时不能装备"+ob->query("name")+"。\n");
			return -1;
		}
	}
	return 1;
}
int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要装备什么武器？\n");
	if(me->query_condition("cannt_eq")>0)
		return notify_fail("你手上的伤还没有好，不能拿兵器。\n");
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
            if( inv[i]->is_draft() ) continue;
			if (legal_wield(me,inv[i])==-1) continue;
			if (inv[i]->query("id") == "long ya" && me->query_temp("taozhuang/long/long ya")) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if (legal_wield(me,ob)==-1)
		return notify_fail("");
    if (ob->is_draft())
        return notify_fail("这不是一件武器。\n");
	if (ob->npc_only())
        return notify_fail("你装备不了"+ob->query("name")+"。\n");
	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");
  if (ob->query("id") == "long ya" && me->query_temp("taozhuang/long/long ya")) return notify_fail("你无法同时装备两把龙牙，神仙也不行。\n");
	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str, *type, *key;
	string *weapon;
	int lp1, lp2;

	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
		message_vision(str, me, ob,"wield");
		if ( mapp(me->query("recent_weapon")) )
			me->delete("recent_weapon");
		weapon=me->query("recent_weapon");
		if ( !arrayp(weapon) )
			weapon=({});
		if ( member_array(ob->query("skill_type"), weapon)<0 )
			weapon=weapon+({ob->query("skill_type")});
		if ( sizeof(weapon) > 4 )
			weapon=weapon[1..];
		me->set("recent_weapon", weapon);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wield <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
    );
    return 1;
}
