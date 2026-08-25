
//***********************************************************************
// set_gift.c  by fire on Dec 20 1997
// the new name is m_setgift located on PMODULES
#include <menu.h>
#include <sanguo.h>
inherit MENUS;
inherit M_ACCESS;

MENU toplevel;


MENU_ITEM quit_item;
MENU_ITEM goto_main_menu_item;
MENU_ITEM main_seperator;
MENU_ITEM blank_seperator;
MENU_ITEM help_item;

int p_wuli,p_zhimou,p_meili;

void accept_gift()
{
	this_body()->init_sg_gifts(p_wuli,p_zhimou,p_meili);
	quit_menu_application();
}

void view_dir(int i)
{
  MENU m;
  MENU_ITEM item;
  string p_lx;
  string p_disp="dfasfda";
  int p_pointleft,p_ran;
  switch(i)
  {
	case 1:
		p_lx="英勇善战型。";
		p_wuli=20;
		p_zhimou=10;
		p_meili=10;
		break;
	case 2:
	       	p_lx="足智多谋型。";
		p_wuli=10;
		p_zhimou=20;
		p_meili=10;
		break;
	case 3:
		p_lx="识人善用型。";
		p_wuli=10;
		p_zhimou=10;
		p_meili=20;
		break;
	case 4:
		p_lx="智勇全才型。";
		p_wuli=14;
		p_zhimou=14;
		p_meili=12;		
		break;
   }
   m= new_menu("武将选型:"+p_lx);
   p_pointleft=60-p_wuli-p_zhimou-p_meili;
   while(p_pointleft)
   {
	p_ran=random(3);
	switch(p_ran)
	{
		case 0:
			if(p_wuli<30)
			{
				p_wuli++;
				p_pointleft--;
			}
			break;
		case 1:
			if(p_zhimou<30)
			{
				p_zhimou++;
				p_pointleft--;
			}
			break;
	
		case 2:
			if(p_meili<30)
			{
				p_meili++;
				p_pointleft--;
			}
			break;
	}
    }
  p_disp=sprintf("                武力：%d     智谋：%d      魅力：%d",p_wuli,p_zhimou,p_meili);

	

  item=new_menu_item("接受此天赋。",(: accept_gift() :),"r");

  add_menu_item(m, main_seperator);
//  add_menu_item(m, blank_seperator);
  add_menu_item(m, new_seperator("以下天赋值满意吗："));
  add_menu_item(m, new_seperator(p_disp));
  add_menu_item(m, item);
  add_menu_item(m, blank_seperator);
  add_menu_item(m, main_seperator);
  add_menu_item(m, blank_seperator);
  add_menu_item(m, help_item);  
  add_menu_item(m, goto_main_menu_item);
  add_menu_item(m, quit_item);
  add_menu_item(m, blank_seperator);
//  add_menu_item (toplevel, main_seperator);
  allow_empty_selection(m);
//  set_no_match_function(m,(:quit_if_cr:));
  set_menu_prompt (m, "r键接受此天赋，h键帮助，m键返回上级选单，q键退出。 ");
  previous_menu = current_menu;
  current_menu = m;
}
void gift_set_help()
{
        write(read_file(PHELP+"gift"));
	return;
}
void create()
{

  toplevel      = new_menu("《三国演义》玩家天赋设置"); 


  quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
  goto_main_menu_item =new_menu_item("回主选单", toplevel, "m");
  help_item = new_menu_item("帮助", (: gift_set_help() :),  "h");

  main_seperator = 
    new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
                  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  blank_seperator = new_seperator("");


  // Add items to the toplevel (main) menu.  
  add_menu_item (toplevel, new_seperator("请选择角色类型："));
  add_menu_item (toplevel, main_seperator);

  add_menu_item(toplevel,new_menu_item("英勇善战型。",(: view_dir(1) :)));
  add_menu_item(toplevel,new_menu_item("足智多谋型。",(: view_dir(2) :)));
  add_menu_item(toplevel,new_menu_item("识人善用型。",(: view_dir(3) :)));
  add_menu_item(toplevel,new_menu_item("智勇全才型。",(: view_dir(4) :)));

  add_menu_item(toplevel,blank_seperator);
  add_menu_item (toplevel, main_seperator);
  add_menu_item (toplevel, help_item);
  add_menu_item (toplevel, quit_item);
  add_menu_item (toplevel, blank_seperator);
  add_menu_item (toplevel, main_seperator);
  set_menu_prompt (toplevel, "按数字键将以相应的模板选择天赋，h键帮助，q键退出。 ");
  allow_empty_selection(toplevel);
//  set_no_match_function(toplevel,(:quit_if_cr:));
  }

void start_menu()
{
  init_menu_application(toplevel);
}


