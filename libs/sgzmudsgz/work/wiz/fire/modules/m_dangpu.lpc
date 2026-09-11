//*******************************************************************
// m_dangpu.c  by fire on Dec 16, 1997
// 当铺模块
#include <mudlib.h>
#include <move.h>
#include <sanguo.h>
inherit ROOM;
inherit CHINESE_DA;
private object p_dpck;
private string *stored_items = ({}); // state name cost ids name ? enough?
private string *items_available = ({});
void reset()
{
	return;
}
void create_cangku()
{
	p_dpck=new(FOBJPATH+"dangpu_cangku");
}
void clear_cangku()
{
	stored_items=({});
}
void init_dpck()
{
    p_dpck=find_object(FOBJPATH+"dangpu_cangku");
}
void query_items()
{
        int i,j;
	int p_diffitem;
        string *stored_items_ids;
	string p_itemid;
	string *p_tmp;
	int *pi_tmp;
	int p_rep;
	items_available = ({});
        
	i = sizeof(stored_items);
        if(!i)
        {
                return ;
        }
        else
        {
		p_diffitem=0;  // different items
                while(i--)
                {
			p_tmp=({ stored_items[i][0]});
			p_itemid=p_tmp[0];
			p_tmp=({ stored_items[i][1]});
			p_itemid=p_itemid+p_tmp[0];
			p_tmp=({stored_items[i][3]});
			p_itemid=p_itemid+p_tmp[0];
			p_rep=0;
			for(j=0;j<p_diffitem;++j)
			{	p_tmp=({ items_available[j][0] });
				if (p_itemid==p_tmp[0])
				{	pi_tmp=({ items_available[j][1] });
					pi_tmp[0]++;
					(int*)items_available[j][1]= pi_tmp[0];
					p_rep=1;
					break;
				}
			}
			
			if(!p_rep)
			{
				items_available += ({ ({ p_itemid })+
					({ 1 })+ 
					({ stored_items[i][2] })+
					({ stored_items[i][0] })+
					({ stored_items[i][1] })+
					({ stored_items[i][3] }) }); // id num ids name value unit
				p_diffitem++;
			}
                }
	}
	return;
}
void add_object(object ob) 
{
    string item_name;
    string item_unit;
    string *object_ids;
    int object_value;
    int ob_value;            
        object_value = ob->query_absolutevalue();
        ob_value=ob->query_chinesevalue();
        item_name = ob->short();
        object_ids = ob->query_id();
        object_ids += ({ ob->short() });
	item_unit=ob->query_unit();
        stored_items += ({ ({ item_name }) + 
        ({object_value }) + ({object_ids }) + ({item_unit}) + ({ob}) });
	query_items();
}
void list_item()
{
	int j,m;
	int *p_tmp;
	string * p_ttt;
	int *p_val;
	int ppp;
        j = sizeof(items_available);
	if(j == 0)
	{
		write("本当铺目前尚无任何存货\n");
		return;
	}
	else
	{
		write("本当铺现有下列存货： \n
-----------------------------------------------------------------\n");
printf("          货物名称            存货数量         单价\n");
                for( m=0; m < j; m++)
                {
                	p_tmp=({ items_available[m][1] });
			p_ttt=({ items_available[m][5] });
			p_val=({ items_available[m][4] });
			ppp=p_val[0];
			ppp = ppp * SALERATE;
		        printf("%20s          %s    %s",items_available[m][3],
					 "还剩"+chinese_number(p_tmp[0])+p_ttt[0] ,
			 chinese_value(ppp) );
                }
                printf(
"-----------------------------------------------------------------\n看看你是买点什么还是卖点什么？\n");
        }
}
void buy_sthing(string p_fullid)
{
	int i;
	string *p_tmp;
	int p_itemnum;
        int p_buyersmoney, p_itemvalue;
	object *obs,ob;
	string p_itemid;
	p_itemnum=sizeof(stored_items);
        p_buyersmoney=this_body()->query_all_con_money();
	for(i=0 ; i<p_itemnum ; ++i)
	{
		p_tmp=({ stored_items[i][0] });
		p_itemid=p_tmp[0];
		p_tmp=({ stored_items[i][1]});
		p_itemid=p_itemid+p_tmp[0];
		p_tmp=({stored_items[i][3]});
		p_itemid=p_itemid+p_tmp[0];
		if (p_itemid==p_fullid)
		{	obs=({ stored_items[i][4] });
			ob=obs[0];
			break;
		}
	}
	p_itemvalue=ob->query_absolutevalue();
	p_itemvalue = p_itemvalue *  SALERATE;
	if (p_itemvalue > p_buyersmoney)
	{
		write("你的钱好象没带够呀。\n");
		return;
	}
        if((ob->move(this_body())) == MOVE_OK)
        {		
  		this_body()->simple_action("$N在此铺买下了一"+
                ob->query_unit()+ob->short()+"。\n"); 
		this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
                stored_items -= ({ stored_items[i] });
		query_items();
                return;
        }
        else
	{
		write("好象拿不了了。\n");
		return;
    }
	
}
void buy_sth(string item, int number)
{
    int p_items,i;
    int p_objfind=0;
    string *for_sale_ids;
    string *p_tmp;
    string p_fullid;
    int j=0;
    p_items = sizeof(items_available);
    if (!number)
    {
        number = 1;
    }
    if(!p_items)
    {
    	write("目前本铺没有存货可卖。\n");
	return;
    }
    
    for(i=0 ; i<p_items ; ++i)
    {
        for_sale_ids = ({ items_available[i][2] });
        if(member_array(item, for_sale_ids[0]) != -1)
        {
             j += 1;
             if (j == number)
             {
		    p_tmp=({ items_available[i][0] });
		    p_fullid=p_tmp[0];    
		    p_objfind=1;
		    break;
	     }	
	}
    }
    if(!p_objfind)
    {
	write("你要得东西这儿好象没有呀。\n");
	return;
    }
    buy_sthing(p_fullid);
    return;
}
void sell_sth( string item, int number)
{
	mixed contents;
	mixed ss;
	object ob;
	int p_itemnum;	
	int i,j;
	int p_findobj=0;
	int p_value;
        int p_buyersmoney;
        p_buyersmoney=this_body()->query_all_con_money();
	contents = all_inventory(this_body());
	p_itemnum = sizeof(contents);
	if(!p_itemnum)
	{
		write("别逗了，你可是一无所有呀。\n");
	}
	j=0;
	for(i=0;i<p_itemnum;++i)
	{
		ob=contents[i];
		ss=ob->query_id();
            	if(member_array(item, ss) != -1)
		{
			j++;
			if(j==number)
			{
				p_findobj=1;
				break;
			}
		}
	}
	if(!p_findobj)
	{
		write("你到底要卖什么，想清楚点。\n");
		return;
	}
	p_value=ob->query_absolutevalue();
	if(!p_value)
	{
		write("这种东西此铺不收。\n");
		return;
	}
	p_value = p_value *  BUYRATE;
	
        if((ob->move(p_dpck)) != MOVE_OK)
	{
		write("当铺好象已经没地方在收新货物了。\n");
		return;
	}
	add_object(ob) ;
	this_body()->set_all_con_money(p_buyersmoney + p_value);
	this_body()->simple_action("$N在此铺卖了一"+
                ob->query_unit()+ob->short()+"，\n得了"+
		chinese_value(p_value)); 
	return;
}
mixed buy(string item, int number)
{
	buy_sth(item,number);
	return 1;
}	
mixed sell(string item, int number)
{
	sell_sth(item, number);
	return 1;
}
mixed list()
{
        list_item();
        return 1;
}
