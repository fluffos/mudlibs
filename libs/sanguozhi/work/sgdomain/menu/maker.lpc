// maker.c
// this is the menu to 
#include <menu.h>
#include <commands.h>
#include <security.h>   /* ### for now */
#include <edit.h>

inherit M_GLOB;
inherit MENUS;
inherit M_ACCESS;       /* ### for now */

MENU toplevel;

// submenus of the toplevel (build) menu

// sub menus of the roommenu
MENU editmenu;
MENU objmenu;
MENU actmenu;

MENU_ITEM N_QUIT;
MENU_ITEM main_seperator;

private string p_id,p_name,p_long;
private string p_room;
private mixed * p_act,p_obj;
private int p_gender,p_age;
private int is_new; // 1 is a new maker, 0 is a old maker
void do_new( string str) {
    string p_surname,p_givenname;
    int p_namepart;
    int p_tmp;
	if(!str) str="";
	if(CHAR_D->char_exist(str)){
		write ("该角色已经存在。\n");
        prompt_then_return();
		return;
	}
    p_namepart=sscanf(str,"%s %s",p_surname,p_givenname);

    if(p_namepart!=2){
		write ("ID必须由两部分构成。\n");
        prompt_then_return();
		return;

	}
	p_id=str;
	p_room=file_name(environment(this_body()));
	p_act=({});
	p_obj=({});
	p_name="新工匠";
	p_gender=1;
	p_age=random(40)+15;
	p_long=0;
	is_new=1;
	goto_menu(editmenu);
}
void do_edit(string str) {
	if(!str) str="";
	if(!CHAR_D->get_char(str,"is_maker")){
		write ("不存在该工匠。\n");
        prompt_then_return();
		return;
	}
	else{
		p_id=str;
		p_room=CHAR_D->get_char(p_id,"shd_room");
		p_act=CHAR_D->get_char(p_id,"m_act");
		p_name=CHAR_D->get_char(p_id,"name");
		p_long=CHAR_D->get_char(p_id,"long");
		p_gender=CHAR_D->get_char(p_id,"gender");
		p_obj=CHAR_D->get_char(p_id,"goods");
		p_age=CHAR_D->get_char(p_id,"age");
		is_new=0;
		goto_menu(editmenu);
	}
}
void add_name(string str){
	if((!str)||(str=="")) return;
	p_name=str;
	write("名字："+str+"\n");
}
void add_gender(string str){
	if((!str)||(str=="")) return;
	p_gender=to_int(str);
	if(p_gender!=2) p_gender=1;
	write("性别："+((p_gender==1)? "男" : "女")+"\n");
}
void add_age(string str){
	if((!str)||(str=="")) return;
	p_age=to_int(str);
	write("年龄："+p_age+"\n");
}
void add_long(string str){
	if((!str)||(str=="")) return;
	p_long=str;
	write("外貌："+str+"\n");
}

void add_room(string str){
	object o;
	if((!str)||(str=="")) return;
	if(str=="here") str=file_name(environment(this_body()));
	o=load_object(str);
	if(!objectp(o)) {
		write ("不存在该房间。\n");
        prompt_then_return();
		return;
	}
	p_room=str;
	write("房间："+str+"\n");
}

void add_save(string str){
	mixed tmp;
	if((!str)||(str=="")) str="y";
	if((str[0]!='y')) {
		return;
	}
	if(is_new) {
		tmp=CHAR_D->add_char(p_id);
		tell_user("fire",p_id);
		write(tmp);
	}
	CHAR_D->set_char(p_id,"name",p_name);
	CHAR_D->set_char(p_id,"age",p_age);
	CHAR_D->set_char(p_id,"long",p_long);
	CHAR_D->set_char(p_id,"m_act",p_act);
	CHAR_D->set_char(p_id,"goods",p_obj);
	CHAR_D->set_char(p_id,"gender",p_gender);
	CHAR_D->set_char(p_id,"shd_room",p_room);
	CHAR_D->set_char(p_id,"room",p_room);
	CHAR_D->set_char(p_id,"is_maker",1);
	CHAR_D->set_char(p_id,"is_tmp",1);
	CHAR_D->set_char(p_id,"body","maker");
	write("工匠存贮完毕。\n");
	goto_menu(toplevel);
}

void add_unsave(string str){
	if((!str)||(str=="")) str="N";
	if((str[0]=='y')) {
		goto_menu(toplevel);
		return;
	}
	return;
}

void add_obj(string str) {
	mixed name;
	if(!str) str="";
	name=OBJ_D->get_obj(str,"name");
	if(!name) {
		write ("该物品不存在。\n");
        prompt_then_return();
		return;
	}
	if(!p_obj) p_obj=({});
	p_obj-=({str});
	p_obj+=({str});
	write("新增物品："+name+"\n");
}

void del_obj(string str) {
	mixed name;
	if(!str) str="";
	name=OBJ_D->get_obj(str,"name");
	if(!name) {
		write ("该物品不存在。\n");
        prompt_then_return();
		return;
	}
	if(!p_obj) p_obj=({});
	p_obj-=({str});
	write("去掉物品："+name+"\n");
}

void list_obj() {
	if(!p_obj) p_obj=({});
	if(!sizeof(p_obj)) {
		write ("还没有任何物品。\n");
        prompt_then_return();
		return;
	}
	write("已有以下物品：\n");
	foreach(string p in p_obj){
		write(OBJ_D->get_obj(p,"name"));
		write("("+p+")\n");

	}
    prompt_then_return();
	return;
}
void list_act() {
	int i,s;
	if(!p_act) p_act=({});
	if(!sizeof(p_act)) {
		write ("还没有任何言行。\n");
        prompt_then_return();
		return;
	}
	write("已有以下言行：\n");
	s=sizeof(p_act);
	for(i=0;i<s;++i) {
		printf("[%2d] %s\n",i+1,p_act[i]);
	}
    prompt_then_return();
	return;
}

void del_act(string str) {
	int i,sum;
	string s;
	i=to_int(str);
	if(!p_act) p_act=({});
	sum=sizeof(p_act);
	if((i<1)||(i>sum)) {
		write ("还没此项言行。\n");
        prompt_then_return();
		return;
	}
	s=p_act[i-1];
	p_act-=({s});
	write("去掉言行："+s+"\n");
}

void add_act(string str) {
	if(!str) str="";
	if(sizeof(str)<8) {
		write ("此言行太短。\n");
        prompt_then_return();
		return;
	}
	if(!p_act) p_act=({});
	p_act-=({str});
	p_act+=({str});
	write("新增言行："+str+"\n");
}
void init_actionmenu() {
	add_menu_item(actmenu,main_seperator);
	add_menu_item(actmenu,new_menu_item("增加言行(a)",
		(: get_input_then_call, (: add_act :),
		"输入新加入的言行 : " :),  "a"));
	add_menu_item(actmenu,new_menu_item("删除言行(d)",
		(: get_input_then_call, (: del_act :),
		"删除第几条言行 : " :),  "d"));
	add_menu_item(actmenu,new_menu_item("列出言行(l)",
		(: list_act :),"l"));
	add_menu_item(actmenu, new_menu_item("返回上级(r)",
		editmenu,"r"));
	add_menu_item(objmenu,main_seperator);
}
void init_objmenu() {
	add_menu_item(objmenu,main_seperator);
	add_menu_item(objmenu,new_menu_item("增加物品(a)",
		(: get_input_then_call, (: add_obj :),
		"输入新加入物品ID  : " :),  "a"));
	add_menu_item(objmenu,new_menu_item("删除物品(d)",
		(: get_input_then_call, (: del_obj :),
		"输入新去掉物品ID  : " :),  "d"));
	add_menu_item(objmenu,new_menu_item("列出物品(l)",
		(: list_obj :),"l"));
	add_menu_item(objmenu, new_menu_item("返回上级(r)",
		editmenu,"r"));
	add_menu_item(objmenu,main_seperator);

}

void init_editmenu(){
   add_menu_item(editmenu, main_seperator);
   add_menu_item(editmenu, new_menu_item("编辑工匠名称(m)",
		(: get_input_then_call, (: add_name :),
           "输入工匠名称 : " :),  "m"));
   add_menu_item(editmenu, new_menu_item("编辑工匠性别(g)",
		(: get_input_then_call, (: add_gender :),
           "输入工匠性别(男:1 | 女:2) : " :),  "g"));
   add_menu_item(editmenu, new_menu_item("编辑工匠年龄(a)",
		(: get_input_then_call, (: add_age :),
           "输入工匠年龄 : " :),  "a"));
   add_menu_item(editmenu, new_menu_item("编辑工匠外貌(l)",
		(: get_input_then_call, (: add_long :),
           "输入工匠外貌 : " :),  "l"));
   add_menu_item(editmenu, new_menu_item("编辑工匠房间(r)",
		(: get_input_then_call, (: add_room :),
           "输入工匠房间 : " :),  "r"));
   add_menu_item(editmenu, new_menu_item("编辑工匠物品(o)",
		objmenu,  "o"));
   add_menu_item(editmenu, new_menu_item("编辑工匠言行(w)",
		actmenu,  "w"));
   add_menu_item(editmenu, new_menu_item("存盘返回(s)",
		(: get_input_then_call, (: add_save :),
           "确认存盘吗？(y/n) : " :),  "s"));
   add_menu_item(editmenu, new_menu_item("不存盘返回(u)",
		(: get_input_then_call, (: add_unsave :),
           "确认返回吗？(y/n) : " :),  "u"));
   add_menu_item(editmenu, main_seperator);
   return;
}
void do_list(string str){
     string *list;
     string dis="";
     object o_room;
     string p_rom,ara,*objs;
     list=CHAR_D->check_char("is_maker",1);
    if ( !str || str == "" )
        str = "*";
    else 
        str = str + "*";
    str = "^"+translate(str)+"$";
    list = regexp(list, str);    
    
     if(!sizeof(list)) {
         write("没有这样的工匠。\n");
         prompt_then_return();
         return;
     }
     foreach(string ls in list) {
        p_rom=CHAR_D->get_char(ls,"shd_room");
        o_room=load_object(p_rom);
        if(objectp(o_room)) {
           p_rom=o_room->short();
           ara=o_room->get_area();
           ara=AREA_D->get_area(ara,"name");
        }
        else {
           p_rom="----";
           ara="----";
        }
        if(!stringp(p_rom)) p_rom="----";
        if(!stringp(ara)) ara="----";
        dis+=sprintf("工匠ID: %s 工匠姓名：%s 可定: %s 所在地区: %s 所在房间: %s ",
           ls,CHAR_D->get_char(ls,"name"),
            (CHAR_D->get_char(ls,"just_sell")==1 ? "否" : "是"),
            ara,p_rom);
        objs=CHAR_D->get_char(ls,"goods");
        if(sizeof(objs)) {
           dis+="\n可制做：";
           foreach(string ob in objs) {
              dis+=sprintf("%s(%s)等级：%d同人：%d\n",
                 OBJ_D->get_obj(ob,"name"),ob,
                 OBJ_D->get_obj(ob,"level"),
                 sizeof(OBJ_D->get_obj_maker(ob)));
           }
        }
        dis+="\n";
    }
    more(dis);
    prompt_then_return();
    return;
}
void do_delete(string str) {
	write("not finish\n");
}
void create() {
    set_privilege(1);
    toplevel = new_menu(mud_name()+"工匠编辑器");
    editmenu = new_menu("编辑工匠信息");
    objmenu = new_menu("编辑工匠所能制做的物品");
    actmenu =  new_menu("编辑工匠的言行");

    N_QUIT = new_menu_item("Quit",(:quit_menu_application:),"q");
    main_seperator =  new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

    add_menu_item(toplevel, main_seperator);
    add_menu_item(toplevel, new_menu_item("产生一个新工匠(n)", 
		(: get_input_then_call, (: do_new :),
           "输入要产生的工匠ID :" :), "n"));
    add_menu_item(toplevel, new_menu_item("编辑一个已有工匠(e)",  
		(: get_input_then_call, (: do_edit :),
           "输入要编辑的工匠ID :" :),  "e"));
    add_menu_item(toplevel, new_menu_item("删除一个工匠(d)", 
		(: get_input_then_call, (: do_delete :),
           "输入要删除的工匠ID :" :), "n"));
    add_menu_item(toplevel, new_menu_item("列表工匠(l)", 
		(: get_input_then_call, (: do_list :),
           "输入要列表的工匠ID首字母 :" :), "l"));

    add_menu_item(toplevel, N_QUIT);
    add_menu_item(toplevel, main_seperator);
	init_editmenu();
	init_actionmenu();
	init_objmenu();
    // Add menu items to the roommenu item
}

void start_menu() {
    init_menu_application(toplevel);
}

