//char menu for managering character database
//created by flee@lima on 3 Aug 1998

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
    add_menu_item(toplevel, new_menu_item("列出帮助主题(List)",
      (: get_input_then_call, (: do_list :),
           "以哪个字母开头？(enter 代表所有的): ":), "l"));
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
void do_list(string str)
{
    mixed top=SGHELP_D->query_topics();
    string *list;
    int count, i;
    string out;
        
    i = 0;
    out = "";
    list = sort_array(keys(top), 1);
    if ( !str || str == "" )str = "*";
    else if ( !has_magic(str) )str = str + "*";
    str = "^"+translate(str)+"$";
    list = regexp(list, str);
    if( !list ){
         printf("没有与 '%s' 对应的帮助主题。\n", str);
         return;
    };
    count=sizeof(list);
    out="主题ID         主题标题            类  类数 相关主题数\n";
    for(i=0; i<count; ++i)
    {
       out = out + 
       sprintf("%-15s%-20s%2s    %d      %d\n", list[i],
          top[list[i]]["t"],((top[list[i]]["is_parent"]==1 ) ? "是" : "否"),
          sizeof(top[list[i]]["parent"]),sizeof(top[list[i]]["related"]));
    }
    out = out + sprintf("\n共查到：%d个帮助主题。\n", count);
        more(out + "\n");
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
