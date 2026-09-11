// post as a menu
#include <mudlib.h>
#include <setbit.h>
#include <classes.h>
#include <edit.h>
inherit M_INPUT;
inherit M_COMPLETE;
inherit M_GRAMMAR;
inherit CLASS_NEWSMSG;
inherit CMD;
string ngroup;
nomask void wrap_post(string * text)
{
    int i = sizeof(text);
    while ( i-- )
    {
        /* only wrap really long lines */
        if ( sizeof(text[i]) > 78 )
        {
            /* wrap to different widths, based on the text */
            int width=78;
            if ( sizeof(text[i]) > width )
                text[i] = wrap(text[i], width);
        }
    }
}
private nomask void receive_post_text(string subject, string * text)
{
    int id;
    if ( !text )
    {
        write("放弃留言。\n");
	destruct(this_object());
        return;
    }
    wrap_post(text);
    id = NEWS_D->post(ngroup, subject, implode(text, "\n") + "\n");
    write("留言结束。\n");
    destruct(this_object());
}
private void receive_post_subject(string subject)
{
    if(subject==".")
    {   write("放弃留言。\n");
	destruct(this_object());
	return;
    }
    if(!subject)
	subject="";
    if ( subject == "" )
    {
	subject="无主题。";
    }
    new(EDIT_OB, EDIT_TEXT, 0, (: receive_post_text, subject :));
}
mixed can_i_post() {
      if(wizardp(this_body())) return 1; // wizard can post anywhere
//      ngroup=(this_body()->query_room())->query_board();
      if(ngroup=="caolu") return 1; // any one can post in there
      if(ngroup=="newbie") return 
          "这是新手帮助板，只有巫师才可以在此留言。\n";
      if(ngroup=="war") return 
          "这是战争留言板，只有战神才可以在此留言。\n";
      if(ngroup=="marriage") return 
          "这是婚姻留言板，只有爱神才可以在此留言。\n";
      if(ngroup=="ranks") return 
          "这是排名留言板，只有统计者才可以在此留言。\n";
      if(ngroup=="progress") return 
          "这是巫师留言板，只有巫师才可以在此留言。\n";
      if(ngroup[0..6]=="nation.") {
	 string p_id,p_nation;
         p_id=this_body()->query_id()[0];
         p_nation=ngroup[7..<1];
         if(p_nation!=CHAR_D->get_char(p_id,"nation"))
             return "只有本国官员才能在此留言。\n";
      }
      return 1;
          
}
void do_post()
{
        mixed ret;
	object o;
	o=present("news board",this_body()->query_room());
	if (!objectp(o))
        {
              printf("这儿没地方可以留言呀。\n");
	      destruct(this_object());
              return;
        }
	ngroup=o->query_group();
        ret=can_i_post();
        if(stringp(ret)) {
            write(ret);
 	   destruct(this_object());
            return;
        }
        write("请输入留言主题， . 表示放弃。\n");
	write("留言主题：");
        modal_simple((: receive_post_subject :));
}
int clean_up() {
	destruct(this_object());
}
