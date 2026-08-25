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

string *okid = ({ "stefan", "fire", "yue", "group", "yuner", "flee" });

int check_id(string str)
{
	int i;
	for(i = 0; i < sizeof( okid ); i++)if( str == okid[i] )return 1;
	return 0;
}

mixed check_ok( mixed str)
{
	if( !str || str == "" || str == 0)return "未知";
	else return str;
}

int comfirm_char(string *list, string arg)
{
	int i;
	for(i = 0; i < sizeof( list ); i++){
		if( list[i] == arg )return 1;
	};
	return 0;
}

void create()
{
	set_privilege(1);
	
	toplevel = new_menu("\n" + mud_name() + "角色管理菜单");
	quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
	seperator = new_seperator("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

	add_menu_item(toplevel, seperator);
	add_menu_item(toplevel, new_menu_item("列出角色(List)",
                        (: get_input_then_call, (: do_list :),
                        "以哪个字母开头？(enter 代表所有的): ":), "l"));
        add_menu_item(toplevel, new_menu_item("寻找一个角色(Find)",
                        (: get_input_then_call, (: do_find :),
                        "输入要查询的角色名 :" :), "f"));
	add_menu_item(toplevel, new_menu_item("增加一个角色(Add)",
			(: get_input_then_call, (: do_add :),
                        "输入要增加的角色名 :" :), "a"));
        add_menu_item(toplevel, new_menu_item("删除一个角色(Delete)",
                        (: get_input_then_call, (: do_del :),
                        "输入要删除的角色名 :" :), "d"));
        add_menu_item(toplevel, new_menu_item("修改一个角色(Edit)",
                        (: get_input_then_call, (: do_edit :),
                        "输入要修改的角色名 :" :), "e") );
        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "输入指令[adeflq]: ");
}
void start_menu()
{
        init_menu_application( toplevel );
}
void do_list(string str)
{
	int count, i;
	string out;
	string *list;
	
	i = 0;
	out = "";
	list = sort_array(CHAR_D->list_chars(), 1);

	if ( !str || str == "" )str = "*";
        else if ( !has_magic(str) )str = str + "*";
        str = "^"+translate(str)+"$";
        list = regexp(list, str);

	if( !list ){
		printf("没有与 '%s' 对应的角色。\n", str);
		prompt_then_return();
	};
        for(count = 0; count < sizeof(list); count++){
                i++;
                out = out + sprintf("%-15s", list[count]);
                if( i == 4 ){
                        i = 0;
                        out = out + "\n";
                }
        };
	out = out + sprintf("\n共查到：%d个角色。\n", count);
        printf(out + "\n");

        prompt_then_return();
}
void do_find(string str)
{
	string *list;
	mapping temp;
	int per;

	list = sort_array(CHAR_D->list_chars(), 1);        

	if( !str ){
                printf("你要查找那个角色？\n");
		return;
        };
	if( !comfirm_char(list, str) ){
		printf("%s这个角色并不存在。\n", str);
		return;
	};
	
	temp = CHAR_D->get_char(str, "gift");
	per = temp["rongmao"];
	temp = CHAR_D->get_char(str, "skills");

	printf("\n\n");
	printf("角色代号: %-10s, 名称: %-10s, 字: %s \n", 
		str, 
		check_ok( CHAR_D->get_char(str, "name")), 
		check_ok( CHAR_D->get_char(str, "zi")));
	printf("性别:     %-10s, 年龄: %d\n", 
		(CHAR_D->get_char(str, "gender")==1 ? "男" :"女"),
		CHAR_D->get_char(str, "age"));
	printf("武力:     %-10d, 智谋: %-10d, 魅力: %-10d, 容貌: %d\n",
		temp["sk_wuli"],
		temp["sk_zhimou"],
		temp["sk_meili"],
		per );
	printf("声望:     %-10s \n", 
		CHAR_D->get_char(str, "reputationstr") );
	printf("所在地:   %-10s, 所属国: %s\n", 
		check_ok( AREA_D->get_area(CHAR_D->get_char(str, "area"), "name")),
		check_ok( COUNTRY_D->get_country(CHAR_D->get_char(str, "nation"), "name")));
	printf("朝廷官职: %-10s, 地方官: %s\n", 
		check_ok( OFFICER_D->query_rank_name(CHAR_D->get_char(str, "ranknation"))),
		check_ok( OFFICER_D->query_rank_name(CHAR_D->get_char(str, "ranklocal"))));
	printf("忠诚:     %-10d, 俸禄: %d\n", 
		CHAR_D->get_char(str,"loyalty"),		
		CHAR_D->get_char(str,"salary"),);	
	printf("\n");

	prompt_then_return();
}
void do_add(string str)
{
	string str1, str2;
	string *list;

	if( !str ){
		printf("请输入要添加的角色英文名。\n");
		return;
	};
	if( !wizardp( this_body()->query_userid() ) ){
                printf("先申请做巫师再来帮忙吧。\n");
                return;
	};
	if( !check_id( this_body()->query_userid() ) ){
		printf("please ask Fire or Stefan for this permission.\n");
		return;
	};
	if( sscanf(str, "%s %s", str1, str2 ) != 2){
		printf("姓与名之间要有空格．\n");
		return;
	};
	
        list = sort_array(CHAR_D->list_chars(), 1);
	if( comfirm_char(list, str) ){
		printf("%s已经存在！\n", str);
		printf("要删除此角色请用( d )选项，要编辑此角色请用( e )选项。\n");
		return;
	};

	if( CHAR_D->add_char( str ) )printf("%s添加成功.\n", str);
	else printf("%s添加失败.\n", str);

	prompt_then_return();
}
void do_del(string str)
{
	string *list;


        if( !str ){
                printf("请输入要删除的角色英文名。\n");
                prompt_then_return();
        };
        if( !wizardp( this_body()->query_userid() ) ){
                printf("先申请做巫师再来帮忙吧。\n");
                prompt_then_return();
        };
        if( !check_id( this_body()->query_userid() ) ){
                printf("please ask Fire or Stefan for this permission.\n");
                prompt_then_return();
        };

        list = sort_array(CHAR_D->list_chars(), 1);
	if( !comfirm_char(list, str) ){
                printf("%s并不存在！\n", str);
                return;
        };

	do_find( str );

	get_input_then_call( (: done_delete , str :), "你确定吗？(yes or no)>" ); 
	return;
}
void done_delete(string arg, string str)
{

	if( str == "yes" || str == "YES"){
		if( CHAR_D->remove_char( arg ) )printf("%s删除成功! \n", str);
		else printf("%s删除失败!\n", str);
		return;
	} else if( str == "no" || str == "NO" ){
		printf("canceled\n");
	} else printf("invalid choice, prossess terminated.\n");

}
void do_edit(string str)
{
        string *list;


        if( !str ){
                printf("请输入要删除的角色英文名。\n");
                prompt_then_return();
        };
        if( !wizardp( this_body()->query_userid() ) ){
                printf("先申请做巫师再来帮忙吧。\n");
                prompt_then_return();
        };
        if( !check_id( this_body()->query_userid() ) ){
                printf("please ask Fire or Stefan for this permission.\n");
                prompt_then_return();
        };

        list = sort_array(CHAR_D->list_chars(), 1);
        if( !comfirm_char(list, str) ){
                printf("%s并不存在！\n", str);
                return;
        };

	do_find( str );
	printf("名称: name          , 字: zi,\n"); 
	printf("性别: gender(1 为男,0 为女), 年龄: age\n");
	printf("武力: wuli          , 智谋: zhimou    , 魅力: meili     , 容貌: rongmao\n");
	printf("声望: reputationstr\n");
	printf("所在地: area        , 所属国: nation\n");
	printf("朝廷官职: ranknation, 地方官: ranklocal\n");
	printf("忠诚: loyalty       , 俸禄: salary\n"); 

	get_input_then_call( (: done_edit , str :), "输入要编辑的项目和它的值>"); 
}
void done_edit(string char, string input)
{
	string parameter;
	mixed value;
	if( sscanf( input, "%s %s", parameter, value) != 2 ){
		printf("格式：项目  项目的值\n");
		return;
	};
	if( restore_variable( value ) != 0 )value = restore_variable( value );
        if( value == "0" )value = 0;
	if( CHAR_D->set_char(char, parameter , value) )printf("改变成功！\n");
	else printf("改变失败！\n");
}	

