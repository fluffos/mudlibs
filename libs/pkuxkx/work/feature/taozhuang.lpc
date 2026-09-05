// taozhuang.c by becool 07/2009
// taozhuang.c 更新北侠套装 by westernd 05/2015
// taozhuang.c 更新秦公望套装 by westernd 07/2015
// taozhuang.c 更新织女套装 by westernd 07/2015

#include <ansi.h>
string taozhuang_name, taozhuang_part;
int update_taozhuang_wear(object me, object ob);
int update_taozhuang_remove(object me, object ob);

int check_taozhuang_wear(object me, object ob)
{
if (!ob) return 1;
if (!ob->query("taozhuang")) return 1;
taozhuang_name = ob->query("taozhuang");
taozhuang_part = ob->query("id");
me->set_temp("taozhuang/"+taozhuang_name+"/"+taozhuang_part, 1);
update_taozhuang_wear(me, ob);
return 1;
}

int check_taozhuang_remove(object me, object ob)
{
if (!ob) return 1;
if (!ob->query("taozhuang")) return 1;
taozhuang_name = ob->query("taozhuang");
taozhuang_part = ob->query("id");
me->delete_temp("taozhuang/"+taozhuang_name+"/"+taozhuang_part);
update_taozhuang_remove(me, ob);
return 1;
}

int update_taozhuang_wear(object me, object ob)
{
// if (me->query_temp("taozhuang_on")) return 1;

// 龙套装 --- 增加掉宝率 by becool
if (!me->query_temp("taozhuang_on/long")) {
if (me->query_temp("taozhuang/long/long ya") && me->query_temp("taozhuang/long/long lin") && me->query_temp("taozhuang/long/long xin"))
  {
  	object *inv;
  	string obj_name;
  	int i;
  	me->add_temp("apply/magic", 100);
  	if (me->query_temp("apply/magic") > 3000) 
  		{
  			me->set_temp("apply/magic",3000);
  			write_file("/log/bug_report", me->query("id")+"用龙套装时掉宝率超过3000了     " + ctime(time())+ "。\n");
  		}
  	me->set_temp("taozhuang_on/long",1);
  	inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) 
		{
			if( !inv[i]->query("equipped")) continue;
			if(inv[i]->query("taozhuang") == "long") 
				{
					obj_name = inv[i]->query("name");
				  obj_name = replace_string(obj_name,HIY,HIR);
				  obj_name = replace_string(obj_name,"龙 ","龍之");
					inv[i]->set("name", obj_name);
				}
		}
  	message_vision(HIR"$N的龙牙、龙鳞和龙心竟然同时变成了血红色，很是恐怖。\n"NOR, me);
  }
}
 
//北侠套装效果 --- 增加掉宝率 by westernd
if (!me->query_temp("taozhuang_on/nx")) {
if (sizeof(me->query_temp("taozhuang/nx"))==2)
  {
	object *inv;
  	string obj_name;
  	int i;
  	me->add_temp("apply/magic", 150);
  	me->set_temp("taozhuang_on/nx",1);
  	inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if( !inv[i]->query("equipped")) continue;
			if(inv[i]->query("taozhuang") == "nx") 
				{
				  obj_name = inv[i]->query("name");
				  obj_name = replace_string(obj_name,HIY,HIR);
				  inv[i]->set("name", obj_name);
				}
		}
  	message_vision(HIR"$N的北侠兵器竟然同时变成了血红色，很是恐怖。\n"NOR, me);
  }
}

//满月套装效果 --- 增加掉宝率 by westernd
if (!me->query_temp("taozhuang_on/manyue")) {
if (me->query_temp("taozhuang/manyue/mi jie") && me->query_temp("taozhuang/manyue/yue jie"))
  {
  	object *inv;
  	string obj_name;
  	int i;
  	me->add_temp("apply/magic", 150);
	me->add_temp("apply/intelligence", 20);
  	me->set_temp("taozhuang_on/manyue",1);
  	inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if( !inv[i]->query("equipped")) continue;
			if(inv[i]->query("taozhuang") == "manyue") 
				{
				  obj_name = inv[i]->query("name");
				  obj_name = replace_string(obj_name,HIY,HIR);
				  inv[i]->set("name", obj_name);
				}
		}
  	message_vision(HIR"$N的弥月之喜竟然同时变成了血红色，很是恐怖。\n"NOR, me);
  }
}

//小宝套装效果 --- 增加减伤 by westernd
if (ob->query("taozhuang")=="xb") {
	if (sizeof(me->query_temp("taozhuang/xb"))>=2)
	  {
		object *inv;
		string obj_name;
		int i;
		int add_xb;
		
		if (sizeof(me->query_temp("taozhuang/xb"))==2)
		{
			if (me->query("level")<50)
			{
				add_xb=50;
			}
			else
			{
				add_xb=me->query("level");
			}
			if (add_xb>100)
			{
				add_xb=100;
			}
			me->add_temp("apply/dodge", add_xb);
			me->add_temp("apply/damage", add_xb);
		}
		if (sizeof(me->query_temp("taozhuang/xb"))==3) {
			me->add_temp("apply/kf_def_wound",7); }

		me->set_temp("taozhuang_on/xb",1);

		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if( !inv[i]->query("equipped")) continue;
				if(inv[i]->query("taozhuang") == "xb") 
					{
					  obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIY,HIR);
					  inv[i]->set("name", obj_name);
					}
			}
		message_vision(HIR"$N的小宝的护身三宝竟然同时变成了血红色，很是恐怖。\n"NOR, me);
	  }
}
 
//秦公望套装效果 --- 增加伤害 by westernd
if (ob->query("taozhuang")=="qgw") {
	if (sizeof(me->query_temp("taozhuang/qgw"))>=2)
	  {
		object *inv;
		string obj_name;
		int i;
		int add_qgw;
		
		if (sizeof(me->query_temp("taozhuang/qgw"))==2) {
			add_qgw=me->query("level")*2/5;	
		}
		else 
		{
			add_qgw=me->query("level")/5;
		}
		
//		if query_temp("taozhuang_on") != "xb")
//		{	me->add_temp("apply/damage", add_qgw);
//		}

		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if( !inv[i]->query("equipped")) continue;
				if(inv[i]->query("taozhuang") == "qgw") 
					{
					  obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIY,HIR);
					  inv[i]->set("name", obj_name);
					}
			}
		message_vision(HIR"$N的秦公望的遗憾竟然同时变成了血红色，很是恐怖。\n"NOR, me);
	  }
}

//织女套装效果 --- 增加容貌 by westernd
if (ob->query("taozhuang")=="zn") {
	if (sizeof(me->query_temp("taozhuang/zn"))>=2)
	  {
		object *inv;
		string obj_name;
		int i;

		if (sizeof(me->query_temp("taozhuang/zn"))==2) 
		{ 
			me->add_temp("apply/personality", 8);
		}
		else 
		{
			me->add_temp("apply/personality", 4);
		}

		if (sizeof(me->query_temp("taozhuang/zn"))==2) me->add_temp("apply/dexerity", me->query("level"));

		if (sizeof(me->query_temp("taozhuang/zn"))==3) me->add_temp("apply/intelligence", me->query("level")/2);

		if (sizeof(me->query_temp("taozhuang/zn"))==4) 
		{
        	me->add_temp("apply/qi_recover", 100);
        	me->add_temp("apply/jing_recover", 100);
		}

		if (sizeof(me->query_temp("taozhuang/zn"))==5) 
		{
        	me->add_temp("apply/qi_cure", 50);
        	me->add_temp("apply/jing_cure", 50);
		}
		
		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if( !inv[i]->query("equipped")) continue;
				if(inv[i]->query("taozhuang") == "zn") 
					{
					  obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIY,HIR);
					  inv[i]->set("name", obj_name);
					}
			}
		message_vision(HIR"$N的织女套装竟然同时变成了血红色，很是妖艳。\n"NOR, me);
	  }
}

return 1;
}

int update_taozhuang_remove(object me, object ob)
{
if (!me->query_temp("taozhuang_on")) return 1;
// 龙套装 --- 增加掉宝率 by becool
if (me->query_temp("taozhuang_on/long") == 1)
  {
  	object *inv;
  	string obj_name;
  	int i;
  	me->add_temp("apply/magic", -100);
  	me->delete_temp("taozhuang_on/long");
  	inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) 
		{
			if(inv[i]->query("taozhuang") == "long") 
				{
					obj_name = inv[i]->query("name");
				  obj_name = replace_string(obj_name,HIR,HIY);
				  obj_name = replace_string(obj_name,"龍之","龙 ");
					inv[i]->set("name", obj_name);
				}
		}
  	message_vision(HIY"$N的龙牙、龙鳞和龙心渐渐变回了金黄色。\n"NOR, me);
  }

// 北侠套装 --- 增加掉宝率 by westernd
if (ob->query("taozhuang")=="nx") {
	if (me->query_temp("taozhuang_on/nx"))
	  {
		object *inv;
		string obj_name;
		int i;
		me->add_temp("apply/magic", -150);
		me->delete_temp("taozhuang_on/nx");
		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++) 
			{
				if(inv[i]->query("taozhuang") == "nx") 
					{
						obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIR,HIY);
	//				  obj_name = replace_string(obj_name,"俠之","侠 ");
						inv[i]->set("name", obj_name);
					}
			}
		message_vision(HIY"$N的北侠兵器渐渐变回了金黄色。\n"NOR, me);
	  }
}

// 满月套装 --- 增加掉宝率 by westernd
if (ob->query("taozhuang")=="manyue") {
	if (me->query_temp("taozhuang_on/manyue"))
	  {
		object *inv;
		string obj_name;
		int i;
		me->add_temp("apply/magic", -150);
		me->add_temp("apply/intelligence", -20);
		me->delete_temp("taozhuang_on/manyue");
		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++) 
			{
				if(inv[i]->query("taozhuang") == "manyue") 
					{
						obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIR,HIY);
	//				  obj_name = replace_string(obj_name,"俠之","侠 ");
						inv[i]->set("name", obj_name);
					}
			}
		message_vision(HIY"$N的弥月之喜渐渐变回了金黄色。\n"NOR, me);
	  }
	}

//小宝套装效果 --- 增加减伤 by westernd
if (ob->query("taozhuang")=="xb") {
	if (sizeof(me->query_temp("taozhuang/xb"))>=1)
	  {
		object *inv;
		string obj_name;
		int i;
		int add_xb;

		if (me->query("level")<50)
			{
				add_xb=50;
			}
			else
			{
				add_xb=me->query("level");
			}
		if (add_xb>100)
			{
				add_xb=100;
			}

		if (sizeof(me->query_temp("taozhuang/xb"))==2) {
			me->add_temp("apply/kf_def_wound",-7);
			ob->set("name",replace_string(ob->query("name"),HIR,HIY));
		}
		if (sizeof(me->query_temp("taozhuang/xb"))==1) {
		me->add_temp("apply/dodge", -add_xb);
		me->add_temp("apply/damage", -add_xb);
		
		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if(inv[i]->query("taozhuang") == "xb") 
					{
					  obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIR,HIY);
					  inv[i]->set("name", obj_name);
					}
			}
		message_vision(HIR"$N的小宝的护身三宝渐渐变回了金黄色。\n"NOR, me);
		
		}
	  }
	else
	{
		me->delete_temp("taozhuang/xb");
	}
}

//秦公望套装效果 --- 增加伤害 by westernd
if (ob->query("taozhuang")=="qgw") {
	if (sizeof(me->query_temp("taozhuang/qgw"))>1)
	  {
		object *inv;
		string obj_name;
		int i;

		me->add_temp("apply/damage", -me->query("level")/5);
		
		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if(inv[i]->query("taozhuang") == "qgw") 
					{
					  obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIR,HIY);
					  inv[i]->set("name", obj_name);
					}
			}
		}
	else {
		message_vision(HIR"$N的秦公望的遗憾渐渐变回了金黄色。\n"NOR, me);
		me->add_temp("apply/damage", -me->query("level")*2/5);
		me->delete_temp("taozhuang/qgw");
	}
}

//织女套装效果 --- 增加容貌 by westernd
if (ob->query("taozhuang")=="zn") {
	if (sizeof(me->query_temp("taozhuang/zn"))>1)
	  {
		object *inv;
		string obj_name;
		int i;

		me->add_temp("apply/personality", -4);

		if (sizeof(me->query_temp("taozhuang/zn"))==2) 
		{
			me->add_temp("apply/intelligence", -me->query("level")/2);
		}
		if (sizeof(me->query_temp("taozhuang/zn"))==3) 
		{
        	me->add_temp("apply/qi_recover", -100);
        	me->add_temp("apply/jing_recover", -100);
		}

		if (sizeof(me->query_temp("taozhuang/zn"))==4) 
		{
        	me->add_temp("apply/qi_cure", -50);
        	me->add_temp("apply/jing_cure", -50);
		}
		
		inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if(inv[i]->query("taozhuang") == "zn") 
					{
					  obj_name = inv[i]->query("name");
					  obj_name = replace_string(obj_name,HIR,HIY);
					  inv[i]->set("name", obj_name);
					}
			}
		}
	else {
		me->add_temp("apply/dexerity", -me->query("level"));
		message_vision(HIR"$N的织女套装渐渐变回了金黄色。\n"NOR, me);
		me->add_temp("apply/personality", -4);
		me->delete_temp("taozhuang/zn");
	}
}


return 1;
}
