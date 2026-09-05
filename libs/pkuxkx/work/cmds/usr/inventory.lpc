//inventory.c
//
#include <weapon.h>
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_MORE;

string inventory_desc(object *inv);
int inventory_item(string);
string a_item(object);
string w_item(object);
string p_item(object);


int main(object me, string arg)
{
        int i, def, dam1, dam2;
        object *inv, ob, eq, wp;
    		string wp1=HIK"--"NOR, wp1_c=HIK"--"NOR, wp2=HIK"--"NOR, wp2_c=HIK"--"NOR;
    		string eq1="", eq1_c="", eq2="", eq2_c="";
    		string str1, str2, str3, str4;
    		string line, tmp,skin_color,skin_b,bra,lip;

        if( arg ) 
		{
			if (1==inventory_item(arg))
			{
				return 1;
			}
		}
		
        if( wizardp(me) && arg ) 
		{
			ob = find_player(arg);
			if( !ob ) ob = find_living(arg);
			if( !ob ) ob = present(arg, environment(me));
        }

        if( !ob ) ob = me;

        inv = all_inventory(ob);
        if( !sizeof(inv) ) {
                write((ob==me)? "目前你身上没有任何东西。\n"
                        : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }
	if (ob->query("gender")=="男性") 
	{
		skin_color=YEL;
		skin_b=BYEL;
		bra="█";
		lip="﹀";
	}
	else 
	{
		skin_color=WHT;
		skin_b=HBWHT;
		bra=RED+"▂";
		lip="一";
	}
    line = sprintf(NOR+"╭────────────────────────────────────────────╮\n");
    line = sprintf("%s│%10s身上带著下列这些东西(负重 %2d%%)：                                              │\n",line, (ob==me)? "你": ob->name(), (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());
    line = sprintf("%s├────────────────────────────────────────────┤\n",line);
    
    str1 = str2 = str3 = str4 = "";
    
	if(objectp(wp = ob->query_temp("weapon")))
	{
		inv -= ({wp});
		dam1 = wp->query("weapon_prop/damage");
		if ( wp->query_amount()>1 )
		  wp1 = wp1_c = wp->name()+"〖"+wp->query_amount()+wp->query("base_unit")+"〗";
		else
		  wp1 = wp1_c = wp->name();
		str1 = "(" + "+" + dam1 + ")";
	}
	if(objectp(wp = ob->query_temp("secondary_weapon")))
	{
		inv -= ({wp});
		dam2 = wp->query("weapon_prop/damage");
		if ( wp->query_amount()>1 )
		  wp2 = wp2_c = wp->name()+"〖"+wp->query_amount()+wp->query("base_unit")+"〗";
		else
		  wp2 = wp2_c = wp->name();
		str2 = "(" + "+" + dam2 + ")";
	}
    
    if( objectp(eq = ob->query_temp("armor/head")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq1 = eq1_c = eq->name();
    		str3 = "(" + "+" + (string)def + ")";
    	}
    else eq1 = eq1_c = HIK"--"NOR;
//    eq1 = uncolor(eq1);
//    wp1 = uncolor(wp1);
		eq1 = COLOR_D->uncolor(eq1);
		wp2 = COLOR_D->uncolor(wp2);
		
		str3 = eq1 + str3;
		str2 = wp2 + str2;
		
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
    tmp = sprintf("│%29s "HIK"[头部]__"NOR+skin_color+"   ███"+"   "HIK"__[左手]"NOR+" %-29s│\n", str3, str2);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq1, eq1_c);
    tmp = replace_string(tmp, wp2, wp2_c);
    line += tmp;
		
		str3 = str4 = "";
		
    if( objectp(eq = ob->query_temp("armor/neck")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq1 = eq1_c = eq->name();
    		str3 = "(" + "+" + (string)def + ")";
    	}
    else eq1 = eq1_c = HIK"--"NOR;
    if( objectp(eq = ob->query_temp("armor/wrists")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq2 = eq2_c = eq->name();
    		str4 = "(" + "+" + (string)def + ")";
    	}
    else eq2 = eq2_c = HIK"--"NOR;
		eq1 = COLOR_D->uncolor(eq1);
		eq2 = COLOR_D->uncolor(eq2);  

		str3 = eq1 + str3;
		str4 = eq2 + str4;
				
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
//    tmp = sprintf("│%29s "HIK"[脸部]__"NOR+BLU"   ███   "HIK"__[手腕]"NOR" %-29s│\n", eq1, eq2);
    tmp = sprintf("│%29s "HIK+"[颈部]__"NOR+skin_color+"   "NOR+skin_b+BLK+" o"+skin_color+"█"NOR+skin_b+BLK+"o "NOR+"   "HIK"__[手腕]"NOR+" %-29s│\n", str3, str4);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq1, eq1_c);
    tmp = replace_string(tmp, eq2, eq2_c);
    line += tmp;
		
		str3 = str4 = "";
		
    if( objectp(eq = ob->query_temp("armor/surcoat")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq1 = eq1_c = eq->name();
    		str3 = "(" + "+" + (string)def + ")";
    	}
    else eq1 = eq1_c = HIK"--"NOR;
    if( objectp(eq = ob->query_temp("armor/hands")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq2 = eq2_c = eq->name();
    		str4 = "(" + "+" + (string)def + ")";
    	}
    else eq2 = eq2_c = HIK"--"NOR;
		eq1 = COLOR_D->uncolor(eq1);
		eq2 = COLOR_D->uncolor(eq2);   

		str3 = eq1 + str3;
		str4 = eq2 + str4;
				
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
    tmp = sprintf("│%29s "HIK+"[外套]__"NOR+skin_color+"   "BLK+skin_b+"▂"+BLK+lip+BLK+"▂"NOR+skin_color+" ▌"HIK+"__[手部]"NOR+" %-29s│\n", str3, str4);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq1, eq1_c);
    tmp = replace_string(tmp, eq2, eq2_c);
    line += tmp;
		
		str3 = str4 = "";
		
    if( objectp(eq = ob->query_temp("armor/cloth")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq1 = eq1_c = eq->name();
    		str3 = "(" + "+" + (string)def + ")";
    	}
    else eq1 = eq1_c = HIK"--"NOR;
    if( objectp(eq = ob->query_temp("armor/armor")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq2 = eq2_c = eq->name();
    		str4 = "(" + "+" + (string)def + ")";
    	}
    else eq2 = eq2_c = HIK"--"NOR;
		eq1 = COLOR_D->uncolor(eq1);
		eq2 = COLOR_D->uncolor(eq2);  

		str3 = eq1 + str3;
		str4 = eq2 + str4;
				  
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
    tmp = sprintf("│%29s "HIK"[衣服]__"NOR+skin_color+" ▅█"+skin_b+bra+skin_color+"█"BLK+skin_b+"▂"NOR+HIK" __[铠甲]"NOR+" %-29s│\n", str3, str4);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq1, eq1_c);
    tmp = replace_string(tmp, eq2, eq2_c);
    line += tmp;
		
		str3 = str4 = "";
		
    if( objectp(eq = ob->query_temp("armor/finger")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq1 = eq1_c = eq->name();
    		str3 = "(" + "+" + (string)def + ")";
    	}
    else eq1 = eq1_c = HIK"--"NOR;
    if( objectp(eq = ob->query_temp("armor/waist")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq2 = eq2_c = eq->name();
    		str4 = "(" + "+" + (string)def + ")";
    	}
    else eq2 = eq2_c = HIK"--"NOR;
		eq1 = COLOR_D->uncolor(eq1);
		eq2 = COLOR_D->uncolor(eq2);   
		
		str3 = eq1 + str3;
		str4 = eq2 + str4;		
		
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
    tmp = sprintf("│%29s "HIK"[戒指]__"NOR+skin_color+" ▌  █     "HIK"__[腰部]"NOR+" %-29s│\n", str3, str4);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq1, eq1_c);
    tmp = replace_string(tmp, eq2, eq2_c);
    line += tmp;
		
		str3 = str4 = "";

    if( objectp(eq = ob->query_temp("armor/secondary_finger")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq1 = eq1_c = eq->name();
    		str3 = "(" + "+" + (string)def + ")";
    	}
    else eq1 = eq1_c = HIK"--"NOR;
    if( objectp(eq = ob->query_temp("armor/shield")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq2 = eq2_c = eq->name();
    		str4 = "(" + "+" + (string)def + ")";
    	}
    else eq2 = eq2_c = HIK"--"NOR;
    	
		eq2 = COLOR_D->uncolor(eq2);
		eq1 = COLOR_D->uncolor(eq1);  
		
		str3 = eq1 + str3;
		str4 = eq2 + str4;
						
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
    tmp = sprintf("│%29s "HIK"[戒指]__"NOR+"   "BLK+skin_b+"▌"+RED+BRED"█"NOR+skin_color+"▌   "HIK+"__[盾牌]"NOR+" %-29s│\n", str3, str4);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq2, eq2_c);
    tmp = replace_string(tmp, eq1, eq1_c);
    line += tmp;
		
		str3 = str4 = "";
		
    if( objectp(eq = ob->query_temp("armor/boots")) ) 
    	{
    		inv -= ({eq});
    		def = eq->query("armor_prop/armor");
    		eq2 = eq2_c = eq->name();
    		str4 = "(" + "+" + (string)def + ")";
    	}
    else eq2 = eq2_c = HIK"--"NOR;
		wp1 = COLOR_D->uncolor(wp1);
		eq2 = COLOR_D->uncolor(eq2);  
		
		str1 = wp1 + str1;
		str4 = eq2 + str4;	
				
    // 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
    tmp = sprintf("│%29s "HIK+"[右手]__"NOR+skin_color+" ▄█  █▄ "HIK+"__[足部]"NOR+" %-29s│\n", str1, str4);
    // 将无颜色的置换成有颜色的
    tmp = replace_string(tmp, eq2, eq2_c);
    tmp = replace_string(tmp, wp1, wp1_c);
    
    line += tmp;

    line = sprintf("%s├────────────────────────────────────────────┤\n",line);
    line = sprintf("%s%s",line, inventory_desc(inv));
    
    line = sprintf("%s╰────────────────────────────────────────────╯\n",line);
    
    write(line);
/*    
        printf("%s身上带著下列这些东西(负重 %d%%)：\n%s\n",
                (ob==me)? "你": ob->name(),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),

                inventory_desc(ob) );
*/
        return 1;
}

string inventory_desc(object *inv)
{
	int i,j,n;
	string str,keyname,name,name_uncolor,id;
	string key,string_short,string_uncolor;
	int line_legth=88;    /* 每一行的字符数 */
	int line_tab=2;		  /* 每一行的栏位数 */
	int tab_space;        /* 每栏字符数 */
	int str_start=0;
	int max_length=42;   /* 每个物件的short最大长度 */
	int gb_count=0;
	int index=0;    /* 含颜色字符的索引 */
	
	object* inv_count = ({});
	mapping count_stat = ([]);
	str ="";

	if (22 < sizeof(inv)) line_tab = 4;
	
	for (i = 0; i < sizeof(inv); i++) 
	{
		keyname = base_name(inv[i])+inv[i]->short();
		if(undefinedp(count_stat[keyname]))
		{
			count_stat[keyname] = 1;
			inv_count += ({inv[i]});
		}
		else
		{
			count_stat[keyname] = count_stat[keyname] + 1;
		}                
	}


	tab_space=line_legth/line_tab;
	for(i=0; i<sizeof(inv_count); i++) 
	{
		if (str_start==line_tab) str_start=0;
		
		key = base_name(inv_count[i])+inv_count[i]->short();
		name = inv_count[i]->query("name");
		name_uncolor = COLOR_D->uncolor(name);
		id = inv_count[i]->query("id");
		if(count_stat[key] ==1)
		{
			if( sizeof(name_uncolor)+2+sizeof(id) <= max_length )
			{
				string_short = inv_count[i]->short();
			}
			else
			{
				/* gb2312中文对齐检查 */
				for (j=0;j < max_length-3-sizeof(id);j++)
				{
					if ((int)name_uncolor[j] > 160) gb_count++;
				}
				
				index=0;
				for (j=0;j<sizeof(name);j++)
				{
					if (sizeof(COLOR_D->uncolor(name[0..j])) == max_length-3-sizeof(id))
					{
						index=j;
						break;
					}
				}

				if (gb_count%2==0)
				{
					string_short = name[0..index] +NOR+ "~" + "(" + capitalize(id) + ")";
				}
				else
				{
					string_short = name[0..index-1] +NOR+ "~" + "(" + capitalize(id) + ")";
				}
			}
		}
		else
		{
			if( sizeof(name_uncolor)+2+sizeof(id)+sizeof(chinese_number(count_stat[key]))+sizeof(inv_count[i]->query("unit")) <= max_length )
			{
				string_short = chinese_number(count_stat[key])+inv_count[i]->query("unit")+inv_count[i]->short();
			}
			else
			{
				/* gb2312中文对齐检查 */
				for (j=0;j < max_length-3-sizeof(id)-sizeof(chinese_number(count_stat[key]))-sizeof(inv_count[i]->query("unit"));j++)
				{
					if ((int)name_uncolor[j] > 160) gb_count++;
				}

				index=0;
				for (j=0;j<sizeof(name);j++)
				{
					if (sizeof(COLOR_D->uncolor(name[0..j])) == max_length-3-sizeof(id)-sizeof(chinese_number(count_stat[key]))-sizeof(inv_count[i]->query("unit")))
					{
						index=j;
						break;
					}
				}

				if (gb_count%2==0)
				{
					string_short = chinese_number(count_stat[key])+inv_count[i]->query("unit")+name[0..index]+NOR+"~"+"("+capitalize(id)+")";
				}
				else
				{
					string_short = chinese_number(count_stat[key])+inv_count[i]->query("unit")+name[0..index-1]+NOR+"~"+"("+capitalize(id)+")";
				}
			}
		}
		
		if (stringp(string_short)) string_uncolor = COLOR_D->uncolor(string_short);
		
		n=(strwidth(string_uncolor))/tab_space+1;
		if (str_start==0) str += "│";
		if (n<=line_tab-str_start) 
		{
			str += sprintf("%-"+n*tab_space+"s", string_uncolor);

			if(str_start+n == line_tab)
			{
				str += "│\n";
			}
			str_start += n;
		}
		else
		{
			str += sprintf("%-"+(line_tab-str_start)*tab_space+"s│\n"," ");
			str_start=0;
			i-=1;
		}
		
		str = replace_string(str, string_uncolor, string_short);
	}
	if ((line_tab-str_start)>0) str += sprintf("%-"+(line_tab-str_start)*tab_space+"s│\n"," ");

	return str;  
}

int inventory_item(string arg)
{
	object me, *inv, obi, ob;
	int i, j, index;
	string str,*idlist,id;
	
	me = this_player();
	inv = all_inventory(me);
	str=NOR+"你身上id为"+HIW+arg+NOR+"的东西有下面这些：\n";
	index=0;
	
	for (i=0;i<sizeof(inv);i++)
	{
		obi=inv[i];
		idlist=obi->parse_command_id_list();
		for (j=0;j<sizeof(idlist);j++)
		{
			id=idlist[j];
			if (id==arg) break;
		}
		// if (idi!=arg)
		// {
			// switch(arg)
			// {
				// case obi->query("skill_type"):
				// case obi->query("armor_type"):
			// }
		// }
		if (arg==id)
		{
			index+=1;
			str += sprintf("%s%s%s%s%s\n", HIW+"("+sprintf("%2d",index)+")  "+NOR, HIR+a_item(obi)+NOR, HIC+w_item(obi)+NOR, obi->short(), p_item(obi));
		}
	}
	if (index>0)
	{
		write(str);
		return 1;
	}
	
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if( !ob ) ob = present(arg, environment(me));
	if( ob ) return 0;

	write("你身上没有id为"+HIW+arg+NOR+"的东西。\n");
	return 1;
   
}

string a_item(object obi)
{
	if(obi->query("gem_ob_autoloaded"))
	{
		return "(绑) ";
	}
	else
	{
		return "";
	}
}

string w_item(object obi)
{
	if(obi->query("equipped"))
	{
		return "(装) ";
	}
	else
	{
		return "";
	}
}

string p_item(object obi)
{
	string prop="";
	
	if (2==obi->query("identified"))
	{
		if(obi->query("weapon_prop"))
		{
			prop="  可塑性:"+HIC+obi->query("forge/max")+"("+obi->query("forge/capacity")+")"+NOR+"  伤害力:"+HIC+obi->query("weapon_prop/damage")+NOR;
		}
		else if(obi->query("armor_prop"))
		{
			prop="  可塑性:"+HIC+obi->query("forge/max")+"("+obi->query("forge/capacity")+")"+NOR+"  防御力:"+HIC+obi->query("armor_prop/armor")+NOR;
		}
	}
	return prop;
}

int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你(你)目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}

