//add by tangfeng
//2005.3
mapping get_poison(string poison);
void destruct_poison(object me);
mapping *poi_list = ({
	(["id":	 "snake_poison", // 所中毒的E文名称
	  "name":       "蛇毒", // 所中毒的中文名称
	  "col":	""BLU"", // 中毒发作的颜色
	  "con":	"湛蓝之气",]), // 中毒发作的状态
	(["id":	 "xx_poison",
	  "name":       "星宿掌毒",
	  "col":	""BLU"",
	  "con":	"湛蓝之气",]),
	(["id":	 "xuanmin_poison",
	  "name":       "玄冥掌毒",
	  "col":	""HIW"",
	  "con":	"霜白之气",]),
	(["id":	 "dsy_poison",
	  "name":       "密宗大手印掌毒",
	  "col":	""CYN"",
	  "con":	"青气",]),
	(["id":	 "fs_poison",
	  "name":       "腐尸毒",
	  "col":	""HIG"",
	  "con":	"绿气",]),
	(["id":	 "huagu_poison",
	  "name":       "化骨绵掌剧毒",
	  "col":	""BLU"",
	  "con":	"湛蓝之气",]),
	(["id":	 "man_poison",
	  "name":       "蔓陀萝花毒",
	  "col":	""HIB"",
	  "con":	"黑气",]),
	(["id":	 "qinghua_poison",
	  "name":       "情花毒",
	  "col":	""MAG"",
	  "con":	"紫气",]),
	(["id":	 "qishang_poison",
	  "name":       "七伤拳毒",
	  "col":	""HIR"",
	  "con":	"潮红之气",]),
	(["id":	 "qzhu_poison",
	  "name":       "千蛛万毒手毒",
	  "col":	""HIR"",
	  "con":	"潮红之气",]),
	(["id":	 "sl_poison",
	  "name":       "神龙毒",
	  "col":	""BLU"",
	  "con":	"湛蓝之气",]),
	(["id":	 "sy_poison",
	  "name":       "大手印掌毒",
	  "col":	""HIR"",
	  "con":	"潮红之气",]),
	(["id":	 "warm_poison",
	  "name":       "热毒",
	  "col":	""RED"",
	  "con":	"殷红之气",]),
	(["id":	 "hot_poison",
	  "name":       "火毒",
	  "col":	""HIR"",
	  "con":	"潮红之气",]),
	(["id":	 "cold_poison",
	  "name":       "寒毒",
	  "col":	""HIC"",
	  "con":	"绿青之气",]),
	(["id":	 "bing_poison",
	  "name":       "冰魄银针毒",
	  "col":	""HIB"",
	  "con":	"湛蓝之气",]),
	(["id":	 "bt_poison",
	  "name":       "怪蛇毒",
	  "col":	""YEL"",
	  "con":	"泛黄之气",]),
	(["id":	 "hb_poison",
	  "name":       "寒冰绵掌毒",
	  "col":	""HIB"",
	  "con":	"湛蓝之气",]),
});
mapping get_poison(string poison)
{
	int i;
	for(i=0;i<sizeof(poi_list);i++)
	{
	      if(poi_list[i]["id"]==poison)
	      		return poi_list[i];
	}
	return (["id":	 poison,
	  	"name":       "剧毒",
	  	"col":	""GRN"",
	  	"con":	"绿气",]);
}
void destruct_poison(object me)
{
	mapping conditions,my_poison;
 	string *names,name;
 	int lvl=0;
	int i;
	if(mapp(conditions = me->query_conditions_by_type("poison")))
	{
		names = keys(conditions);
		for(i=0;i<sizeof(conditions);i++)
		{
			if(conditions[names[i]]>lvl)
				lvl = conditions[names[i]];
			name  = names[i];
			my_poison = get_poison(name);
			my_poison["lvl"] = lvl;
			if(random(2)) message_vision(HIW"\n突然一道神光笼罩着$N，$N身受之"NOR+my_poison["col"]+my_poison["name"]+HIW"竟然完全消失了！\n"NOR, me);
			else message_vision(HIW"\n$N面色有些"+my_poison["con"]+"，似乎身受"NOR+my_poison["col"]+my_poison["name"]+HIW"！一道神光笼罩，$N全部恢复了！\n"NOR, me);
			me->apply_condition(my_poison["id"], -1);
		}
	}
	me->clear_condition();//其实这个就全部去掉du了
}
