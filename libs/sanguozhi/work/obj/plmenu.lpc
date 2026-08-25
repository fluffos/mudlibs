// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*      
**      Player menu by John Viega (rust@virginia.edu) 5-Jul-95
**      For the Lima mudlib.
**
**      Still want to have:
**      o channel menu
**     o more reporter commands
**      o what's new or something like that.
**      o take args at line, ie, b yes for biff or somesuch
**     o disable newbie options
*/

#include <menu.h>
#include <mudlib.h>
#include <playerflags.h>
#include <commands.h>
//### for now
#include <security.h>

inherit MENUS;
//### for now
inherit M_ACCESS;

MENU toplevel;
// submenus of the toplevel (main) menu
MENU soulmenu;
MENU reportmenu;
MENU remotemenu;
MENU personalmenu;
// submenus of personalmenu
MENU biffmenu;  
MENU snoopablemenu; 
// Wizard stuff
MENU wizmenu;
MENU testmenu;


MENU_ITEM quit_item;    
MENU_ITEM goto_main_menu_item;
MENU_ITEM main_seperator;

// right now, we're just going to call the help command.
//private MENU helpmenu;


private mapping dispatch = ([ "n" : "news", "w" : "who", 
                              "b" : "bug", "t" : "typo", "i" : "idea",
                              "?" : "help", "l" : "mudlist" ]);


private nomask void simple_cmd(string cmd)
{
    call_other(CMD_DIR_PLAYER "/" + dispatch[cmd], "player_menu_entry");
}


void
start_mail()
{
    this_body()->query_mailer()->begin_mail();
}

void handle_finger(string person)
{
    CMD_OB_FINGER->player_menu_entry(person);
    prompt_then_return();
}

void test_soul(string s)
{
    CMD_OB_SEMOTE->player_menu_entry(s);
    prompt_then_return();
}

void find_soul(string s)
{
    if(!s) {
        write("Invalid.\n");    
        return;
    }

    CMD_OB_EMOTEAPROPOS->player_menu_entry(s);
}

void show_souls(string s)
{
    CMD_OB_FEELINGS->player_menu_entry(s);
}

 
void show_adverbs(string s)
{
/*  write(
"Remember: You can get any of these adverbs by typing part of the adverb \n"
"then *, if the part you type is unique.  Eg, kick rust ene* would give you:\n"
"kick rust energetically, but kick rust en* won't because it also\n"
"matches endearingly and enthusiastically.\n");
*/
  write(
  "记住：你可以用简写法拼写一个副词，输入它的前部分紧跟着输入一个 * 、\n"
  "前提是它要能唯一确定一个副词。比如：kick rust ene* 会变成：\n"
  "kick rust energetically，但 kick rust en* 不会，因为 en* 同时还对应\n"
  "着 endearingly 和 enthusiastically。\n");
  CMD_OB_ADVERBS->player_menu_entry(s);
}


void change_email(string s)
{
  this_user()->set_email(s);
  //write("Email info changed.\n");
    write("电子邮件信息更改了。\n");
}

void change_url(string s)
{
  this_user()->set_url(s);
  //write("Home page address changed.\n");
    write("网络家页信息更改了。\n");
}

void
change_title(string s)
{

//  if(strsrch(s,"$N") == -1)
//    s = "$N " + s;
  this_body()->set_title(s);
  
  //write("Title changed.\n");
  write("称号更改了。\n");
}
 
void
query_personal_info()
{
  printf(
/*         "Your title is: %s\n"
         "Your provided e-mail address is: %s\n"
         "Your provided WWW home page is: %s\n"
         "You %sget notified when new mail arrives.\n" 
         "Wizards %s snoop you.\n",
*/
         "你的称号是：%s\n"
         "你提供的电子邮件(e-mail)地址是：%s\n"
         "你提供的网络家页(homepage)是：%s\n"
         "%s会在有新邮件时提醒你。\n"
         "巫师%s监听你。\n",
         this_body()->query_title(),
         this_user()->query_email(),
         this_user()->query_url(),
         this_body()->test_flag(F_BIFF) ? "" : "不",
         this_body()->test_flag(F_SNOOPABLE) ? "能够" : "不能够"
         );

  prompt_then_return();
}

void
prompt_change_title()
{
  get_input_then_call ((: change_title :), //"Change title to what? "
                                           "改个什么称号呢？" );
}

void
prompt_change_email()
{
  get_input_then_call ((: change_email :), //"Change e-mail to what? "
                                           "把电子邮件地址(e-mail)改成什么？");
}

void 
prompt_change_url()
{
  get_input_then_call ((: change_url :), //"Change your WWW homepage address to what? "
                                         "把网络家页地址(homepage)改成什么？");
}


void 
set_biff(string s)
{
  if(s == "y")
    {
      this_body()->set_flag(F_BIFF);    
      //write("Mail notification is now on.\n");
      write("邮件提示现在打开。\n");

    }
  else
    {
      this_body()->clear_flag(F_BIFF);  
      //write("Mail notification is now off.\n");
      write("邮件提示现在关闭。\n");
    }
  goto_previous_menu();
} 

 
void
set_ansi(string s)
{
  if(s && s=="on")
  {
  this_body()->query_shell_ob()->set_variable( "ansi" , 1);
  //write("Ansi is now on.\n");
    write("色彩开启。\n");
  } else {
  this_body()->query_shell_ob()->unset_variable( "ansi");
  //write("Ansi is off.\n");
  write("色彩关闭。\n");
}
}
      
   
void
set_snoopable(string s)
{
  if(s == "n")
    {
      this_body()->clear_flag(F_SNOOPABLE);
      write(//"You now can not be snooped (except by admins)\n"
            "现在开始，除开大神没有人可以监听你。\n");
    }
  else
    {
      this_body()->set_flag(F_SNOOPABLE);
      write(//"Any wizard can now snoop you.\n"
            "现在开始，任何巫师都可以监听你。\n");
    }
  goto_previous_menu();
}

void finish_who(string mudname)
{
    CMD_OB_FINGER->player_menu_entry("@" + mudname);
    printf(//"%s queried.  It's up to that mud to reply to you.\n",
           "向 %s 的询问已经送出，看它会不会给你回答。\n", mudname);
    prompt_then_return();
}

void
remote_who()
{
  //write("Which mud do you want to query?\n");
  write("你要向哪个 MUD 询问？\n");
  complete_choice(0, IMUD_D->query_mudnames(), (: finish_who :));
}

#if 0 /* mudinfo is a wiz command */
void finish_mudinfo(string mudname)
{
    do_cmd( "mudinfo " + mudname );

    printf("%s queried.  It's up to that mud to reply to you.\n"
           "向 %s 的询问已经送出，看它会不会给你回答。\n", mudname);
}
 
void remote_muds()
{
    do_cmd( "mudlist" );
}
void remote_mudinfo()
{
   //write("Which mud do you want to query?\n");
   write("你要向哪个 MUD 询问？\n");
   complete_choice(0, IMUD_D->query_mudnames(), (: finish_mudinfo :));
}
#endif /* 0 */

void
create()
{
    set_privilege(1);

  toplevel      = new_menu(mud_name()+"泥潭游戏选单");
  soulmenu      = new_menu("灵魂选单");
  reportmenu    = new_menu("报告选单");
  personalmenu  = new_menu("个人选单");
  biffmenu      = new_menu("收到邮件时是否提示你？");
  snoopablemenu = new_menu("让巫师可以监听你吗？");
  remotemenu    = new_menu("其他泥潭(MUD)");
  wizmenu       = new_menu("巫师选单");

  // Since we'll use these things more than once, we can just
  // call new_menu_item once, and insert them wherever we want
  // to use them.
  quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
  goto_main_menu_item =new_menu_item("回到主选单", 
                                         toplevel, "m");


  main_seperator = new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");


  // Add items to the toplevel (main) menu.  
  add_menu_item (toplevel, main_seperator);
  add_menu_item (toplevel, new_menu_item("阅读新闻 (news)", 
                                         (: simple_cmd :), "n"));
  add_menu_item (toplevel, new_menu_item("收发邮件 (mail)",
                                         (: start_mail :), "m"));
  // The 1 at the end of this next one creates a prompt:
  // "[Hit enter to return to menu] "
  // You can also do this by calling prompt_then_return() from your
  // function.
  add_menu_item (toplevel, new_menu_item("看看都有谁在连线中？ (who)", 
                                            (: simple_cmd :), "w", 1));
  add_menu_item (toplevel, new_menu_item("查询某人档案 (finger)", 
                                            (: get_input_then_call, 
                                              (: handle_finger :),
                                             "查询谁的档案 ? ":), "f"));
  add_menu_item (toplevel, new_menu_item("灵魂/感情 选单", soulmenu, "s"));
  add_menu_item (toplevel, new_menu_item("汇报程序、拼写错误或提意见", 
                                         reportmenu, "r"));
  add_menu_item (toplevel, new_menu_item("更改或显示个人小档案",
                                         personalmenu, "i"));
  add_menu_item (toplevel, new_menu_item("关于其他泥潭(mud)的信息",
                                         remotemenu, "o"));
  add_menu_item (toplevel, new_menu_item("巫师的东东", wizmenu, "*", 0, 
                                         (: wizardp(this_user()) :)));
  add_menu_item (toplevel, quit_item);
  add_menu_item (toplevel, new_menu_item("帮助", (: simple_cmd :), "?"));

  // Add items to the soul menu.
  add_menu_item (soulmenu, main_seperator);
  add_menu_item (soulmenu, 
                 new_menu_item("列出灵魂词汇", (: get_input_then_call,
                                              (: show_souls :),
                                              "以哪个字母开头？"
                                              "(enter 代表所有的): ":),
                               "s"));
  add_menu_item (soulmenu, 
                 new_menu_item("列出副词词汇", (: get_input_then_call,
                                              (: show_adverbs :),
                                              "以哪个字母开头？"
                                              "(enter 代表所有的): ":),
                               "a"));
  add_menu_item (soulmenu, 
                 new_menu_item("查找灵魂", (: get_input_then_call,
                                              (: find_soul :),
                                              "查找的灵魂要包括的字：" :),
                               "f"));

  add_menu_item (soulmenu, 
                 new_menu_item("测试灵魂", (: get_input_then_call,
                                      (: test_soul :),
                                      "测试灵魂: ":),
                       "t"));

  add_menu_item (soulmenu, quit_item);
  
  add_menu_item (soulmenu, goto_main_menu_item);
                                         
  add_menu_item (reportmenu, main_seperator);
  add_menu_item (reportmenu, new_menu_item("汇报编程错误", (: simple_cmd :),
                                           "b"));
  add_menu_item (reportmenu, new_menu_item("汇报拼写错误", (: simple_cmd :),
                                           "t"));
  add_menu_item (reportmenu, new_menu_item("提出意见想法", (: simple_cmd :),
                                           "i"));
  add_menu_item (reportmenu, quit_item);
  add_menu_item (reportmenu, goto_main_menu_item);

  add_menu_item (personalmenu, main_seperator);
  add_menu_item (personalmenu, new_menu_item("查阅个人小档案",
                                             (: query_personal_info :), "v"));
  add_menu_item (personalmenu, new_menu_item("改变称号", 
                                             (: prompt_change_title :), "t"));
  add_menu_item (personalmenu, new_menu_item("改变电子邮件(e-mail)地址",
                                             (: prompt_change_email :), "e"));
  add_menu_item (personalmenu, new_menu_item("改变网络家页(homepage)地址",
                                             (: prompt_change_url :), "w"));
  add_menu_item (personalmenu, new_menu_item("设定或取消邮件提示",
                                             biffmenu, "n"));
  add_menu_item (personalmenu, new_menu_item("设定是否被监听", snoopablemenu, "s"));
  //  add_menu_item (personalmenu, new_menu_item("Change your supplied real name",
  //                                         (: prompt_change_real_name :), "n"));
add_menu_item(personalmenu, new_menu_item("开关色彩", (: get_input_then_call, (: set_ansi :), "Ansi 'on' or 'off' ? (default off): ":), "a"));
 
  add_menu_item (personalmenu, quit_item);
  add_menu_item (personalmenu, goto_main_menu_item);

  add_menu_item (biffmenu, main_seperator);
  add_menu_item (biffmenu, new_menu_item("Yes", (: set_biff :), "y"));
  add_menu_item (biffmenu, new_menu_item("No", (: set_biff :), "n"));
  add_menu_item (biffmenu, quit_item);
  add_menu_item (biffmenu, goto_main_menu_item);

  add_menu_item (snoopablemenu, main_seperator);
  add_menu_item (snoopablemenu, new_menu_item("Yes", 
                                              (: set_snoopable :), "y"));
  add_menu_item (snoopablemenu, new_menu_item("No", 
                                              (: set_snoopable :), "n"));
  add_menu_item (snoopablemenu, quit_item);
  add_menu_item (snoopablemenu, goto_main_menu_item);

  add_menu_item (remotemenu, main_seperator);
  add_menu_item (remotemenu, new_menu_item("列出" + mud_name() + 
                                           "所知的泥潭(mud)", 
                (: simple_cmd :), "l", 1 ));
  add_menu_item (remotemenu, new_menu_item("看看都有谁在其它泥潭(mud)中",
                                           (:remote_who:), "w"));
  add_menu_item (remotemenu, quit_item);
  add_menu_item (remotemenu, goto_main_menu_item);
  add_menu_item (wizmenu, main_seperator);
//  add_menu_item (wizmenu, new_menu_item("Info on another mud",
//                                      (: remote_mudinfo :), "i"));
  add_menu_item (wizmenu, quit_item);
  add_menu_item (wizmenu, goto_main_menu_item);

}


void
start_menu()
{
  init_menu_application(toplevel);
}
