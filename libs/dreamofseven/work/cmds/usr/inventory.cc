//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;
string inventory_desc(object ob);
int main(object me, string arg)
{
	int i,j;
	object *inv, ob;
	string str;
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	// inv = all_inventory(ob);
	inv = F_QUANTITY->sortinv(ob);	// add by luky/add by shengsan for sort env
	if( !sizeof(inv) ) {
		write((ob==me)? "目前你身上沒有任何東西。\n"
			: ob->name() + "身上沒有攜帶任何東西。\n");
		return 1;
	}
	str=""; j=1;
	for(i=0; i<sizeof(inv); i++)
        {
	  if( i+1 < sizeof(inv) )
	  {
		if( base_name(inv[i])==base_name(inv[i+1]) && !inv[i+1]->query("equipped"))
		{
		  if(inv[i]->query("equipped")) 
		  {
		  	str += inventory_desc(inv[i])+"\n";
		  }	
		  else j++;
		}
		else
		{
			if(j>1)		//luky 兩個以上再顯示數量
			{		//luky
			str += chinese_number(j);
			str += inv[i]->query("unit")  ? inv[i]->query("unit"):"個";
			}		//luky
			str += inventory_desc(inv[i]);
			str += wizardp(me)? "\t"+base_name(inv[i])+"\n" : "\n" ;
			j = 1;
		}
	  }
	  else
	  {
		if(j>1)		//luky 兩個以上再顯示數量試試
		{		//luky
		str += chinese_number(j);
		str += inv[i]->query("unit")  ? inv[i]->query("unit"):"個";
		}		//luky
		str += inventory_desc(inv[i]);
		str += wizardp(me)? "\t"+base_name(inv[i])+"\n" : "\n" ;
	  }
	}


	printf("%s身上帶著下列這些東西﹕         ("HIY"負重%d%%"NOR")\n"+
		"==============================[%d/%d]====\n",
		(ob==me)? "你": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		(int)ob->query_encumbrance(),
		(int)ob->query_max_encumbrance()
		 );
	str += "\n";
	me->start_more(str);
	return 1;
}

string inventory_desc(object ob)
{
	return sprintf("%s%s%s",
		ob->short(),
		ob->query("equipped")? HIG "(已裝備)" NOR:"",
		ob->query("security")? HIC "(保存)" NOR:"",
	);
}

int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你(妳)目前身上所攜帶的所有物品。
 
註 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}
