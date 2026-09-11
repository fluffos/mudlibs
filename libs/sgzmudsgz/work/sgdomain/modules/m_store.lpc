// m_store.c  by fire on Dec 12 1997  
#include <mudlib.h>
#include <move.h>
private mapping stored_item = ([]); // state name cost ids name ? enough?
void add_objecta(string ob_name,int sg_obj);
int colour_strlen(string s);

void add_object(string ob_name)
{
	add_objecta(ob_name,0);
}
void add_sg_object(string id)
{
	add_objecta(id,1);
}
void add_objecta(string ob_name,int sg_obj) 
{
    object ob;
	string m_id;
	mixed par;
	if(!sg_obj)
	{
		ob=new(ob_name);
		if(!objectp(ob)) return;
		m_id=ob->query_id()[0];

		stored_item[m_id]=([]);
		stored_item[m_id]["name"]=ob->short();
		stored_item[m_id]["file_name"]=ob_name;
		stored_item[m_id]["value"]=ob->query_absolutevalue();
		destruct(ob);
	}
	else
	{
		par=OBJ_D->get_obj(ob_name);
		if(!par) return;
//		ob=OBJ_D->clone_obj(ob_name);
//		if(!objectp(ob)) return;

		stored_item[ob_name]=([]);
		stored_item[ob_name]["name"]=par["name"]+"("+ob_name+")";
//		stored_item[m_id]["name"]=ob->short();

		stored_item[ob_name]["value"]=par["value"];
		stored_item[ob_name]["sg_obj"]=1;
//		destruct(ob);
	}
}
mixed show_all()
{
	return stored_item;
}
mixed query_items()
{
	int i,sum;
	string *ids;
	string bar="                                 ",tmp;
	int len;

	ids=keys(stored_item);
	sum = sizeof(ids);
    if(!sum)
    {
		return "这儿的货还没进呢。\n";
    }
    printf("货物名称                       价钱\n"+
	"--------------------------------------------------------\n");
	for(i=0;i<sum;++i){
		len=colour_strlen(stored_item[ids[i]]["name"]);
		tmp=" ";
		if( len <30)
			tmp=bar[0..(30-len)];
		printf("%s%s%s\n",stored_item[ids[i]]["name"],tmp,
		  CHINESE_D->chinese_value(stored_item[ids[i]]["value"]));
	}
    return 
	"--------------------------------------------------------\n看看你需要点什么\n";
}
mixed list()
{
        string retstr;
        retstr= query_items();
		write(retstr);
        return 1;
}
void buy_sth(string item, int number)
{
    int p_buyersmoney;
    int p_itemvalue;
    object ob;
    string ob_filename;

    p_buyersmoney=this_body()->query_all_con_money();

	if(!stored_item[item]){
		write("你要的东西这儿没有。\n");
		return;
	}
	p_itemvalue=stored_item[item]["value"];
	if(p_itemvalue>p_buyersmoney) {
					write("钱没带够呀。\n");
					return;
	}
	if(stored_item[item]["sg_obj"])
		ob=OBJ_D->clone_obj(item);
	else
		ob=new(stored_item[item]["file_name"]);
	if(!objectp(ob)) {
		write("东西买不到，有BUG，请报告巫师。\n");
		return;
	}

    if((ob->move(this_body())) == MOVE_OK)
    {		
   		this_body()->simple_action("$N在此买下了一"+
            ob->query_unit()+ob->short()+"。\n"); 
    	this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
        return;
     }
    else
    {
		write("好象没法拿不了了。\n");
	        destruct(ob);
		return;
    }
}
mixed buy(string item, int number)
{
	buy_sth(item,number);
	return 1;
}	
