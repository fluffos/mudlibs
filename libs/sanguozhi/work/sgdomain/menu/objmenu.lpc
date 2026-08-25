// to manage D_OBJ system
//by fire on March 22, 1999

#include <menu.h>
#include <mudlib.h>
inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;

void do_list(string str);
void do_find(string str);
void do_del(string str);
void do_edit(string str);
void do_add(string str);

void done_delete(string arg, string str);
void done_edit(string char, string input);


int comfirm_char(string *list, string arg)
{
        int i;
        for(i = 0; i < sizeof( list ); i++){
                if( list[i] == arg )return 1;
        };
        return 0;
}
void done_title(string str,string title)
{
    mixed ret;
    ret=SGHELP_D->set_topic(str,"t",title);
    if(ret) write("成功。\n");
     else write("失败。\n");
}
void do_title(string str)
{
    get_input_then_call
     ((: done_title, str:), "输入标题。");

}
void do_class(string str)
{
    mixed ret;
    ret=SGHELP_D->set_topic(str,"is_parent",1);
    if(ret) write("成功。\n");
     else write("失败。\n");
}
void do_unclass(string str)
{
    mixed ret;
    ret=SGHELP_D->set_topic(str,"is_parent",0);
     write("成功。\n");
}

void done_subclass(string str,string par)
{
    mixed ret;
    ret=SGHELP_D->sub_parent(str,par);
    write(ret);
}
void do_subclass(string str)
{
    get_input_then_call
     ((: done_subclass, str:), "从哪一类中删除。");
}

void done_addclass(string str,string par)
{
    mixed ret;
    ret=SGHELP_D->add_parent(str,par);
    write(ret);
}
void do_addclass(string str)
{
    get_input_then_call
     ((: done_addclass, str:), "加入哪一类。");
}
void do_check()
{
   mixed ret;
   ret=SGHELP_D->find_wrong();
   write(ret);
   prompt_then_return();
}
void create()
{
    set_privilege(1);
    toplevel = new_menu("\n" + mud_name() + "帮助系统管理菜单");
    quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("物品列表(List)",
      (: get_input_then_call, (: do_list :),
           "物品类或子类？(enter 代表所有的): ":), "l"));
        add_menu_item(toplevel, new_menu_item("寻找一个帮助主题(Find)",
           (: get_input_then_call, (: do_find :),
           "输入要查询的帮助主题名 :" :), "f"));
        add_menu_item(toplevel, new_menu_item("修改主题标题(Title)",
           (: get_input_then_call, (: do_title :),
             "输入要修改标题的主题 :" :), "t"));
        add_menu_item(toplevel, new_menu_item("设一主题为类(Class)",
            (: get_input_then_call, (: do_class :),
             "输入要成为类的主题 :" :), "c"));
        add_menu_item(toplevel, new_menu_item("取消一类(UnClass)",
            (: get_input_then_call, (: do_unclass :),
             "输入要取消类的主题 :" :), "u"));

        add_menu_item(toplevel, new_menu_item("把一主题加入一类(AddClass)",
            (: get_input_then_call, (: do_addclass :),
             "输入要调整的主题 :" :), "a"));
        add_menu_item(toplevel, new_menu_item("把一主题从一类中取消(SubClass)",
            (: get_input_then_call, (: do_subclass :),
             "输入要调整的主题 :" :), "s"));

        add_menu_item(toplevel, new_menu_item("查找不完整主题(cHeck)",
             (: do_check :), "h"));

        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "输入指令[lftcuasq]: ");
}
void start_menu()
{
        init_menu_application( toplevel );
}

void doreal_list(string *ids,string str){
	string *dis; 
	string tmp;
	mixed ob;
	ob=OBJ_D->get_obj();
	dis=explode(str,",");
	if(!sizeof(dis))
		dis=({"name"});

	foreach(string id in ids)
	{
		tmp=sprintf("%-12s ",id);
		foreach(string d in dis){
			if(!ob[id][d])
				tmp+="       0 ";
			else{
				if(intp(ob[id][d]))
					tmp+=sprintf("%8d ",ob[id][d]);
				else
					tmp+=sprintf("%-10s",ob[id][d]);
			}
			if(tmp[<1]==10)
				tmp=tmp[0..<2];
		}
		printf("%s\n",tmp);
	}
}
		


void do_list(string str)
{
	string *ids;
	string dis;
	if((!str)||(str==""))
		ids=OBJ_D->get_obj("list");
	else
	{
		ids=OBJ_D->check_obj("type",str);
		if(!sizeof(ids))
			ids=OBJ_D->check_obj("sub_type",str);
	}
	if(!sizeof(ids)) {
         printf("没有该类物品。\n", str);
         prompt_then_return();
         return;
    }

    get_input_then_call
     ((: doreal_list, ids:), "显示哪些信息。");
}

void do_find(string str)
{
    mapping temp;
    string dis;
    temp = SGHELP_D->get_topic(str);
    if( !temp ){
         printf("没有关于 '%s' 的帮助主题。\n", str);
         prompt_then_return();
         return;
    }
    dis=sprintf("主题: %s : 标题 :%O\n",str,temp["t"]);
    dis+=sprintf("位置： %O\n",temp["p"]);
    dis+=sprintf("是否类: %O \n",temp["is_parent"]);
    dis+=sprintf("所属类：%O \n",temp["parent"]);
    dis+=sprintf("相关主题：%O \n",temp["related"]);
    write(dis);
}
