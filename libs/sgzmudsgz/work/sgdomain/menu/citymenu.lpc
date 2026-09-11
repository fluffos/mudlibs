//char menu for managering character database
//created by flee@lima on 3 Aug 1998

#include <menu.h>
#include <mudlib.h>
#include <daemons.h>
#include <edit.h>
#include <ansi.h>

#define AREA_SERVER load_object("/a/area_server")
#define BUILDCITY_D "/daemons/buildcity_d"


inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;

MENU toplevel;
MENU roomedit;

MENU_ITEM quit_item;
MENU_ITEM seperator;

mixed * dirs=({"east","west","south","north","southeast","southwest","northeast",
"northwest","up","down","enter","out",});

mixed opdirs=(["east":"west", "south":"north", "north":"south",
"west":"east","southeast":"northwest","southwest":"northeast","up":"down",
"enter":"out","northeast":"southwest","northwest":"southeast","down":"up",
"out":"enter",]);

string p_id,p_name,p_zhou,p_sht; //城市ID,城市名,所属洲名,城市简称(所有城市的房间ID都以简称_开头)
int level; //城市级别
string m_id,c_id; //房间ID

void do_create(string str);
void do_open(string str);
void do_return();
void do_move(string str);
void do_del(string str);
void do_edit();
void do_add(string str);


mixed can_i_do()
{
c_id=this_body()->query_primary_id();
p_id=CHAR_D->get_char(c_id,"buildcity");
//m_id=explode(file_name(me->query_room()),"/")[2];
if (!p_id&&!wizardp(this_body())) 
   return "%^RED%^你没有被天神赋予修建新城市的权力，还是先通过统一全国来展示自己的实力吧!%^RESET%^\n";
if (p_id)
{
p_name = BUILDCITY_D->get_city_build_info(p_id,"name");
p_zhou = BUILDCITY_D->get_city_build_info(p_id,"zhou");
p_sht  = BUILDCITY_D->get_city_build_info(p_id,"short"); 
p_sht  = BUILDCITY_D->get_city_build_info(p_id,"short"); 
level  = BUILDCITY_D->get_city_build_info(p_id,"level"); 
}
if (!wizardp(this_body()))
{if (!p_id)  return "%^CYAN%^天神赋予你修建这个城市的信息有误，请于天神联系!%^RESET%^\n";
if (!p_name) return "%^CYAN%^天神赋予你修建这个城市的信息有误，请于天神联系!%^RESET%^\n";
if (!p_zhou) return "%^CYAN%^天神赋予你修建这个城市的信息有误，请于天神联系!%^RESET%^\n";
if (!p_sht)  return "%^CYAN%^天神赋予你修建这个城市的信息有误，请于天神联系!%^RESET%^\n";
if (!level) return "%^CYAN%^天神赋予你修建这个城市的信息有误，请于天神联系!%^RESET%^\n";}
return 1;
 
}

int can_i_make_room()
{string p_area=this_body()->query_room()->get_area();
 if ((p_area!=p_id)&&(!wizardp(this_body())))
    {
    write("%^RED%^你无权在此地进行房间改造!%^RESET%^\n");
    return 0;
    } 
m_id=explode(file_name(this_body()->query_room()),"/")[2];
return 1;
}


void create_empty_room(string r_id) {
    AREA_SERVER->add_room(r_id);
    AREA_SERVER->set_room(r_id,"b","%^YELLOW%^空房间("+r_id+")%^RESET%^");
    AREA_SERVER->set_room(r_id,"l","");
    AREA_SERVER->set_room(r_id,"e",([]));
    AREA_SERVER->set_room(r_id,"t",0);
    AREA_SERVER->set_room(r_id,"o",([]));
  }



void do_change_room_id(string id)
{mapping r_info;
 int index = sizeof(p_sht);
 if (id=="q") return;
 if (!can_i_make_room()) return;
 if (id[0..index]!=(p_sht+"_"))
    {
    write("%^RED%^房间ID的前缀必须为 "+p_sht+"_"+"。%^RESET%^\n");
    get_input_then_call((: do_change_room_id :),"重新输入要修改的房间ID :" );
    return;
    }
 if (BUILDCITY_D->is_room_exist(id))
    {
    write("%^RED%^修改的房间ID的已经存在。%^RESET%^\n");
    get_input_then_call((: do_change_room_id :),"重新输入要修改的房间ID :" );
    return;
    }
 BUILDCITY_D->add_room(p_id,id);
 BUILDCITY_D->trans_room(p_id,m_id,p_id,id);
 this_body()->move("/a/"+p_id+"/"+id);
 r_info=BUILDCITY_D->get_room(p_id,m_id,"e");
 BUILDCITY_D->del_room(p_id,m_id);
 foreach(string dir in keys(r_info))
  {mapping exits;
   exits=BUILDCITY_D->get_room(p_id,r_info[dir],"e");
   exits[opdirs[dir]]=id;
   BUILDCITY_D->set_room(p_id,r_info[dir],"e",exits);
   }
}

void do_change_room_name(string name)
{
if (!can_i_make_room()) return;
BUILDCITY_D->set_room(p_id,m_id,"b","%^YELLOW%^"+name+"%^RESET%^");
this_body()->force_look();
}


private nomask void receive_room_long(string* text)
{int lines;
 string desc="\n";
 if ( !sizeof(text) )
    { write("放弃撰写描述。\n");
      return;
    }
 lines = sizeof(text);
 for (int i=0;i<lines;i++)
     desc+=text[i];
 desc = wrap(desc, 60);
 desc += "\n";
 BUILDCITY_D->set_room(p_id,m_id,"l",desc);
 write("撰写描述结束。\n");
 this_body()->force_look();
 return;
}

void do_change_room_long()
{
 if (!can_i_make_room()) return;
 write("%^CYAN%^请输入房间的描述:%^RESET%^\n");
 new(EDIT_OB, EDIT_TEXT, 0, (: receive_room_long:));
}

void do_del_connection(string dir,string str)
{string r_id;
 mapping r_exit,m_exit;
if (str!="y"&&str!="Y") return;
m_exit=BUILDCITY_D->get_room(p_id,m_id,"e");
r_id = m_exit[dir];
r_exit=BUILDCITY_D->get_room(p_id,r_id,"e");
map_delete(r_exit,opdirs[dir]);
map_delete(m_exit,dir);
//目标房间只有opdirs[dir]这一个出口时，为了防止成为遗漏的孤岛房间，我们
//不允许直接删除这个出口。绕过这个限制的办法是先把孤岛房间连接到别处，然
//后再删除这个出口。
/*if (!sizeof(r_exit)) 
{
write("%^RED%^删除出口"+dir+"后，出口房间"+r_id+"将成为没有入口的孤岛房间，所以该删除出口操作被禁止!%^RESET%^\n");
return;
}
if (!sizeof(m_exit)) 
{
write("%^RED%^删除出口"+dir+"后，当前房间"+m_id+"将成为没有入口的孤岛房间，所以该删除出口操作被禁止!%^RESET%^\n");
return;
}*/
BUILDCITY_D->set_room(p_id,m_id,"e",m_exit);
BUILDCITY_D->set_room(p_id,r_id,"e",r_exit);
}



void do_add_room_exit(string dir,string str)
{
 mapping r_exit,m_exit;
 if (str[0..sizeof(p_sht)]!=(p_sht+"_"))
    {
    write("%^RED%^连接的房间ID的前缀必须为 "+p_sht+"_"+"。%^RESET%^\n");
    get_input_then_call((: do_add_room_exit :),"重新输入要连接的房间ID :" );
    return;
    }
 if (!BUILDCITY_D->is_room_exist(p_id,str))
    {
    write("%^RED%^连接的房间ID的不存在。%^RESET%^\n");
    get_input_then_call((: do_add_room_exit :),"重新输入要连接的房间ID :" );
    return;
    }
if (member_array(opdirs[dir],keys(BUILDCITY_D->get_room(p_id,str,"e")))!=-1)
   {
     write("目标房间的对应方向已经存在连接。\n");
     return;
   }
m_exit=BUILDCITY_D->get_room(p_id,m_id,"e");
if (!m_exit) m_exit=([]);
m_exit[dir] = str;
r_exit=BUILDCITY_D->get_room(p_id,str,"e");
if (!r_exit) r_exit=([]); 
r_exit[opdirs[dir]] = m_id;
BUILDCITY_D->set_room(p_id,m_id,"e",m_exit);
BUILDCITY_D->set_room(p_id,str,"e",r_exit);

}

void do_change_room_exit(string dir)
{
 if (!can_i_make_room()) return;
 if (dir=="q") return;
 if (member_array(dir,dirs)==-1)
   {
     write("错误的方向。\n");
     get_input_then_call((: do_change_room_exit :),"重新输入你想修改的出口：" );
     return;
   }
 if (member_array(dir,keys(BUILDCITY_D->get_room(p_id,m_id,"e")))!=-1)//出口已经存在
   {
     get_input_then_call((: do_del_connection,dir :),"你确信要删除这个出口吗？<y/n>：" );
     return;
   }
 else
   {
     get_input_then_call((: do_add_room_exit,dir:),"你想连接的房间ID：" );
     return;
   }
}

void do_change_room_object()
{
}

void done_change_room_type(string type)
{
if (type=="q") return;
switch(type)
{
case "1" :
     BUILDCITY_D->set_room(p_id,m_id,"t",1);break;
case "2" :
     if (level<5) {write(RED"只有五级城才能建当铺!\n"NOR);return;}
     BUILDCITY_D->trans_room("jianye","jy_dangpu",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"dangpu",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "的新城"+p_name+"("+p_id+")"+"的当铺完工了。"+NOR+"\n");

     break;
case "3" :
     if (level<4) {write(RED"只有四、五级城才能建钱庄!\n"NOR);return;}
     BUILDCITY_D->trans_room("jianye","jy_bank",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"bank",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "的新城"+p_name+"("+p_id+")"+"的钱庄完工了。"+NOR+"\n");

     break;
case "4" :
     BUILDCITY_D->trans_room("jianye","jy_yst",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"meeting",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "的新城"+p_name+"("+p_id+")"+"的县衙完工了。"+NOR+"\n");

     break;
case "5" :
     BUILDCITY_D->trans_room("jianye","jy_djt",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"fly",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                    "的新城"+p_name+"("+p_id+")"+"的校场完工了。"+NOR+"\n");

     break;
case "6" :
     BUILDCITY_D->trans_room("jianye","jy_westgate",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"go",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "的新城"+p_name+"("+p_id+")"+"的城门完工了。"+NOR+"\n");

     break;
case "7" :
     BUILDCITY_D->trans_room("jianye","jy_jianyu",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"prison",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "的新城"+p_name+"("+p_id+")"+"的监狱完工了。"+NOR+"\n");

     break;
case "8" :
     BUILDCITY_D->trans_room("jianye","jy_yz",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"yizhan",m_id);
     tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "的新城"+p_name+"("+p_id+")"+"的驿站完工了。"+NOR+"\n");

default  :
     BUILDCITY_D->set_room(p_id,m_id,"t",0);break;
}
this_body()->force_look();
}

void do_change_room_type()
{
if (!can_i_make_room()) return;
write("%^CYAN%^1--室外房间  2--当铺  3--钱庄  4--议事厅  5--点将台  6--城门　7--监狱　8--驿站  其他--室内房间%^RESET%^\n");
get_input_then_call((: done_change_room_type :),"输入想更改的房间类型:" );
}

void create()
{       
	set_privilege(1);
	toplevel = new_menu("\n" + mud_name() + "城市建设管理菜单");
        roomedit = new_menu("\n房间修改选单");

	quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
	seperator = new_seperator("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

	add_menu_item(toplevel, seperator);
	add_menu_item(toplevel, new_menu_item("创建新城市(Create)",
                        (: get_input_then_call, (: do_create :),
                        "输入你要创建的城市ID: ":), "c"));
        add_menu_item(toplevel, new_menu_item("开放新城市(Open)",
                        (: get_input_then_call, (: do_open :),
                        "输入要开放的城市名 :" :), "o"));
	add_menu_item(toplevel, new_menu_item("移动到新城市(Move)",
                        (: get_input_then_call, (: do_move :),
                        "输入你要去的新建城市ID: ":), "m"));
        add_menu_item(toplevel, new_menu_item("从新城市返回(Return)",
                        (: do_return :), "r"));
	add_menu_item(toplevel, new_menu_item("增加新的房间(Add)",
			(: get_input_then_call, (: do_add :),
                        "输入要增加的房间ID :" :), "a"));
        add_menu_item(toplevel, new_menu_item("删除当前房间(Delete)",
                        (: get_input_then_call, (: do_del :),
                        "你确认要删除当前房间吗?<y/n> :" :), "d"));
        add_menu_item(toplevel, new_menu_item("修改当前房间(Edit)",roomedit, "e"));
        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "输入指令[comradeq]: ");

        add_menu_item(roomedit, seperator);
        add_menu_item(roomedit,new_menu_item("修改房间ID(Id)",
                        (: get_input_then_call, (: do_change_room_id :),
                        "输入新的的房间ID :" :), "i"));
        add_menu_item(roomedit,new_menu_item("修改房间名称(Name)",
                        (: get_input_then_call, (: do_change_room_name :),
                        "输入新的的房间名称 :" :), "n"));
        add_menu_item(roomedit,new_menu_item("修改房间描述(Long)",
                        (: do_change_room_long :),"l"));
        add_menu_item(roomedit,new_menu_item("修改房间出口(Exit)",
                        (: get_input_then_call,(:do_change_room_exit :),
                         "输入你想修改的出口：" :),"e"));
        add_menu_item(roomedit,new_menu_item("修改房间物件(Object)",
                        (: do_change_room_object :),"o"));
        add_menu_item(roomedit,new_menu_item("修改房间类型(Type)",
                        (: do_change_room_type :),"t"));
        add_menu_item(roomedit, quit_item);
        add_menu_item(roomedit, new_menu_item("回到主选单",toplevel, "m"));
        add_menu_item(roomedit, seperator);
        set_menu_prompt (roomedit, "输入指令[inleotqm]: ");

}

void start_menu()
{
 mixed tmp;
 if (stringp(tmp=can_i_do()))
   {
   write(tmp);
   this_object()->remove();
   return;
   }
 init_menu_application( toplevel );
}

void do_create(string str)
{
string creator = BUILDCITY_D->get_city_build_info(str,"creator");
if (!creator) 
    {write("%^RED%^没有该城市的构造信息，无法操作!%^RESET%^\n");return;}
if (!wizardp(this_body())&&(creator!=c_id))
    {write("%^RED%^你不是该城市的创建者，无法操作!%^RESET%^\n");return;}
p_id = str;
p_name = BUILDCITY_D->get_city_build_info(str,"name");
p_zhou = BUILDCITY_D->get_city_build_info(str,"zhou");
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
level  = BUILDCITY_D->get_city_build_info(str,"level"); 
BUILDCITY_D->create_first_room_of_city(p_id,p_sht);
}

void do_open(string str)
{
 if (!wizardp(this_body())) {write(RED"只有巫师才能开放新城市!\n"NOR);return;}
 if (p_id==str)
 {  
    BUILDCITY_D->init_city_info(p_id,p_name,p_zhou,p_sht,level);
    //CHAR_D->set_char(this_body()->query_primary_id(),"buildcity",0);
 }
 else
 {
    write(RED"城市不匹配，开放城市失败!\n"NOR);
 }

//added city neighbor below. 

 return;
}

void do_move(string str)
{
string creator = BUILDCITY_D->get_city_build_info(str,"creator");
if (!creator) 
    {write("%^RED%^没有该城市的构造信息，无法操作!%^RESET%^\n");return;}
if (!wizardp(this_body())&&(creator!=c_id))
    {write("%^RED%^你不是该城市的创建者，无法操作!%^RESET%^\n");return;}
p_id = str;
p_name = BUILDCITY_D->get_city_build_info(str,"name");
p_zhou = BUILDCITY_D->get_city_build_info(str,"zhou");
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
level  = BUILDCITY_D->get_city_build_info(str,"level"); 
this_body()->move("/a/"+str+"/"+p_sht+"_lsjlg");
this_body()->force_look();
tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "召集数万民夫，开始在"+p_zhou+"一带建造新城"+p_name+"("+p_id+")"+NOR+"\n");
return;
}


void do_return()
{
   if(this_body()->query_room()->get_area()!=p_id)
      {
      write("%^RED%^你不在修建中的城市中,无法执行该功能。%^RESET%^\n");
      return;
      }
   this_body()->move("/a/huayin/vroad1");
   this_body()->force_look();
}

void do_add_connection(string str,string dir)
{  if (dir=="q") return;
   if (member_array(dir,dirs)==-1)
   {
     write("错误的方向。\n");
     get_input_then_call((: do_add_connection,str :),"重新输入目标新房间的延伸方向:" );
     return;
   }
   if (member_array(dir,keys(BUILDCITY_D->get_room(p_id,m_id,"e")))!=-1)
   {
     write("该方向已经有房间连接。\n");
     get_input_then_call((: do_add_connection,str :),"重新输入目标新房间的延伸方向:" );
     return;
   }
   BUILDCITY_D->add_room(p_id,str);
   BUILDCITY_D->insert_connection(p_id,m_id,dir,str);
   BUILDCITY_D->insert_connection(p_id,str,opdirs[dir],m_id);
   BUILDCITY_D->update_room(p_id,str);
   this_body()->move(load_object("/a/"+p_id+"/"+str));//移动到新房间
   this_body()->force_look();
   BUILDCITY_D->update_room(p_id,m_id);
   tell(bodies(),YEL+"【系统】"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "带领民夫大兴土木建设新的建筑。"+NOR+"\n");

}

void do_add(string str)
{int index = sizeof(p_sht);
 if (!can_i_make_room()) return;
 if (str=="q") return;
 if (str[0..index]!=(p_sht+"_"))
    {
    write("%^RED%^修建的房间ID的前缀必须为 "+p_sht+"_"+"。%^RESET%^\n");
    get_input_then_call((: do_add :),"重新输入要新建的房间ID :" );
    return;
    }
 if (BUILDCITY_D->is_room_exist(p_id,str))
    {
    write("%^RED%^修建的房间ID的已经存在。%^RESET%^\n");
    get_input_then_call((: do_add :),"重新输入要新建的房间ID :" );
    return;
    }
 get_input_then_call((: do_add_connection,str :),"输入目标新房间的延伸方向:" );

}
void do_del(string str)
{mapping r_info;
 if ((str=="n")||(str=="N")) return;
 if (!can_i_make_room()) return;
 if (str!="y"&&str!="Y") m_id= str;
 BUILDCITY_D->del_room(p_id,m_id);
}

void do_edit()
{
if (!can_i_make_room()) return;
write("%^CYAN%^现在房间的ID为"+m_id+"%^RESET%^\n");
init_menu_application(roomedit);
}

