#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY "大清国宝藏图" NOR, ({ "daqing baotu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
set("no_get",1);
set("no_drop",1);            
set("value",0);            
            set("material", "paper");
            set("long", HIY"一张你根据四十二章经画的宝藏图，你可以查看（chakan）．\n"NOR);
          }

    setup();
}
void init()
{
	if(environment(this_object())==this_player())
	add_action("do_read","chakan");
	add_action("do_go","go");
}

int do_read(string arg)
{
object me;
mapping exits;
string *dirs;
string thisdir;
me=this_player();
if(arg != "daqing baotu" && arg != "大清国宝藏图") return 0;

if(this_object()->query("bid")!=me->query("id"))
{
tell_object(me,"突然出现一个黑衣人，把你的藏宝图抢走了!\n");
destruct(this_object());
}

if(!environment(me))
{
tell_object(me,"你现在无法看宝图！\n");
 return 1;
}
if(!environment(me)->query("exits"))
{
tell_object(me,"宝图显示这里和宝藏无关！\n");
 return 1;
}
if(this_object()->query("lastck") ==environment(me)->query("short"))
{
tell_object(me,"宝图不是刚刚告诉过你该向哪里去吗?\n");
 return 1;
}

if(environment(me)->query("short")!="龙门峰"
&& !this_object()->query("lmf"))
{
tell_object(me,"宝图告诉你宝藏在关外龙门峰附近！你先去那里吧!\n");
 return 1;
}
if(environment(me)->query("short")=="龙门峰"
&& environment(me)->query("already")
&& !this_object()->query("lmf"))
{
tell_object(me,"你来晚了，看来别人已经把宝物拿走了!\n");
return 1;
}


if(find_call_out("markit")== -1)
//call_out("markit",3,me);
call_out("markit",random(60)+20,me);
if( !mapp(exits = environment(me)->query("exits")) ) 
{
tell_object(me,"大清国宝藏应该就在这附近！\n");
return 1;
}
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
	set("thisdir",thisdir);
	tell_object(me,HIY"图上显示大清国宝藏应该在"+thisdir+"的方向！\n"NOR);
if (environment(me)->query("short")=="龙门峰")
{
this_object()->set("lmf",1);
environment(me)->set("already",1);
}
this_object()->set("lastck",environment(me)->query("short"));
	return 1;
}

int do_go(string arg)
{
	if(arg==query("thisdir"))
	this_player()->add_temp("going",1);
	return 0;
}
int markit(object me)
{
      object gold;
      int i;
       object ob,  corpse,who;
        ob = this_object();

who=me;
//if(me->query_temp("going") <= 3 || environment()!=me) return 1;
if(me->query_temp("going") <= 20 || environment()!=me) return 1;
if(!query("already"))
{
tell_object(me,HIY"\n\n你双眼一亮，从『大清国宝藏图』所指示的地方挖出大量的黄金，和若干个宝箱！\n"NOR);
gold = new("/clone/money/gold");
i=random(1201)+600;
gold->set_amount(i);
gold->move(me);
me->delete("huanggong");
me->delete_temp("going");
set("already",1);
message("channel:chat", HIC"【江湖传闻】"GRN + me->query("name")+"发现"+HIY"大清国宝藏:计黄金" + chinese_number(i)+HIY"两！\n"NOR,users() );



if(who->query("jinyong/book7")==7 ) 
{

		i = 1900+random(2000);
		who->set("jinyong/book7",8);
		who->add("combat_exp",i+20000);
		who->add("potential",i*28);
		who->add("mpgx",20);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+20000)+"点经验"+
		           chinese_number(i*28)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");
message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了鹿鼎记的所有任务!"NOR"\n", users());

		who->save();
        }

destruct(this_object());
}
return 1;
}

