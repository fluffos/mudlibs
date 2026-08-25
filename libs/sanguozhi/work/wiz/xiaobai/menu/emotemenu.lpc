//created by flee@lima on 27 July 1998
//modified by flee@lima on 29 July 1998, adding feelings...cmds 

#include <ansi.h>
#include <menu.h>
#include <mudlib.h>

inherit MENUS;
inherit M_ACCESS;
inherit M_GLOB;
inherit M_GRAMMAR;

MENU toplevel;

MENU_ITEM quit_item;
MENU_ITEM seperator;

void do_list(string str);
void do_find(string which);
void do_del(string str);
void do_edit(string str);
void do_help();

void create()
{
	set_privilege(2);

	toplevel = new_menu("\n" + mud_name() + "情感动词编辑器");

	quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
	seperator = new_seperator("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

	add_menu_item(toplevel, seperator);
	add_menu_item(toplevel, new_menu_item("列出情感动词(List)",
			(: get_input_then_call, (: do_list :),
			"以哪个字母开头？(enter 代表所有的): ":), "l"));
	add_menu_item(toplevel, new_menu_item("寻找一个情感动词(Find)",
			(: get_input_then_call, (: do_find :),
			"输入要查询的单词 :" :), "f"));
	add_menu_item(toplevel, new_menu_item("删除一个情感动词(Delete)",
			(: get_input_then_call, (: do_del :),
                        "输入要删除的单词 :" :), "d"));
	add_menu_item(toplevel, new_menu_item("修改一个情感动词(Edit)",
			(: get_input_then_call, (: do_edit :),
			"输入要修改的单词 :" :), "e") );
	add_menu_item(toplevel, new_menu_item("显示帮助文件(Help)",
			(: do_help :), "h") );
	add_menu_item(toplevel, quit_item);
	add_menu_item(toplevel, seperator);
	set_menu_prompt (toplevel, "输入指令[defhlq]: ");
}
void start_menu()
{
	init_menu_application( toplevel );
}
//feelings commands, it will find and list semotes from Soul.o 
//dir /cmds/player/semote.c
private void do_list(string arg)
{
	string *list;
	string *long;
	string str;
	int count, i;

	str = "";
	i = 0;

	list = sort_array(SOUL_D->list_emotes(), 1);
	count = sizeof(list);
	
	if ( !arg || arg == "" )arg = "*";
	else if ( !has_magic(arg) )arg = arg + "*";

	arg = "^"+translate(arg)+"$";
	list = regexp(list, arg);
    
	if ( !list ){
        	printf("没有与 '%s' 对应的情感词汇。\n", arg);
        	return;
    	}

	for(count = 0; count < sizeof(list); count++){
		i++;
		str = str + sprintf("%-15s", list[count]);
		if( i == 4 ){
			i = 0;
			str = str + "\n";
		}
	};
	printf(str + "\n");

	prompt_then_return();	
}
//command semote.c, which can give the details of a semote
//dir is /cmd/player/semote.c
private void do_find(string which)
{
	mapping data;
	mixed * info;

	if( !which ){
	        printf("你要指定一个情感动词。\n");
        	return;
	}

	data = SOUL_D->query_emote(which);
    	if( !data ){
        	printf("没有这个情感动词。\n");
        	return;
	}
	
	if ( data[""] ){
        	info = SOUL_D->get_soul(which, "", ({ }));
        	printf("%s :\n你会看到：%s他人会看到：%s\n",
               		which, info[1][0], info[1][1]);
	}
	if ( data["LIV"] ){
        	info = SOUL_D->get_soul(which, "LIV", ({ this_object() }));
        	printf("%s somebody:\n你会看到：%s目标会看到：%s他人会看到：%s\n",
               		which, info[1][0], info[1][1], info[1][2]);
    	}
	if ( data["STR"] ){
        	info = SOUL_D->get_soul(which, "STR", ({ "slowly" }));
        	printf("%s slowly :\n你会看到：%s他人会看到：%s\n",
               		which, info[1][0], info[1][1]);
    	}
    	if ( data["LIV STR"] ){
	        info = SOUL_D->get_soul(which, "LIV STR", ({ this_object(), "slowly" }));
        	printf("%s somebody slowly :\n你会看到：%s目标会看到：%s他人会看到：%s\n",
               		which, info[1][0], info[1][1], info[1][2]);
    	}

	prompt_then_return();
}
//rmemote command, use to delete a emote from soul.o
//dir /cmds/wiz/rmemote.c
private void do_del(string str)
{
	string rule;
	if( !wizardp( this_body()->query_userid() ) ){
		printf("先申请做巫师再来帮忙吧。\n");
		return;
	};
	if( !str ){
		printf("你要删除那一个emote？\n");
		return;
	};

	sscanf(str, "%s %s", str, rule);
	if (SOUL_D->remove_emote(str, rule))printf("删除成功。\n");
	else printf("删除失败。\n");

	prompt_then_return();
}
void do_help()
{
	printf("\n%10s情感动词编辑器\n", mud_name());
	printf("\n\n请参照主菜单使用。\n");
	if( wizardp( this_body()->query_userid() ) ){
		printf("\n情感动词替代变量说明\n");
		printf("	1)$N  自己的一般称呼。\n");
		printf("	2)$T  目标的一般称呼。\n");
		printf("	3)$n  自己的代称。\n");
		printf("	4)$M  自己的名字。\n");
		printf("	5)$s  自己的谦称。\n");
		printf("	6)$S  自己的自称。\n");
		printf("	7)$R  目标的敬称。\n");
		printf("	8)$r  目标的蔑称。\n");
	};
	prompt_then_return();
}
void do_edit(string str)
{
	int i;
	mapping data;
	string verb, rule, content;

	if( !wizardp( this_body()->query_userid() ) ){
                printf("先申请做巫师再来帮忙吧。\n");
                return;
        };

	printf("格式：动词,内容,对象\n");
	sscanf(str, "%s,%s,%s", verb, content, rule);
	if( !verb || !content ){
		printf("非法的格式。\n");
		return;
	};

	if( !rule )rule = "";
	if( rule != "" && rule != "LIV" && rule != "STR" && rule != "LIV STR"){
		printf("非法的对象，合法的对象为 \"\", LIV, STR, LIV STR\n");
		return;
	}
	
	if(SOUL_D->add_emote(verb, rule, content))printf("修改成功。\n");
	else printf("修改失败。\n");
	
	prompt_then_return();
}
