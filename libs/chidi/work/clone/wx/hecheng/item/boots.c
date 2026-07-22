
#include <ansi.h>
#include <armor.h>
#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit CLOTH;
//inherit EQUIP;
#endif

int check_name(string str,object me);
//int do_hui(object weapon);
//int do_rename(string arg);
int do_qie(string arg);
//int do_xiang(object me,object obj);
void init()
{
   if (!mapp(this_player()->query("hcboots"))){
     this_object()->owner_is_killed();
     return;
   }
    if (this_player()!=environment()) return;
    //add_action("do_hui","duan");
    add_action("do_rename","gainame");
    //add_action("do_qie","xiangqie");
}
void create()
{   
    object me;
    string w_name,w_id;
    int w_armor;
    me = this_player();
    if (me){
    w_name=me->query("hcboots/name");
    w_id = me->query("hcboots/id");
    w_armor = me->query("hcboots/armor");
   //w_lb = me->query("hcloth/lb");
    set("armor_type", "boots");
    set("armor_prop/armor", w_armor);
    if ( me->query("hcboots/int") ) 
    set("armor_prop/intelligence",me->query("hcboots/int"));
    if ( me->query("hcloth/dex") ) 
    set("armor_prop/dexerity",me->query("hcboots/dex"));
    if ( me->query("hcboots/con") ) 
    set("armor_prop/constitution",me->query("hcboots/con"));
    if ( me->query("hcboots/str") ) 
    set("armor_prop/strength",me->query("hcboots/str"));
    set_weight(5000);
    
    set_name(w_name, ({w_id,"hecheng","boots"}));
  //  set("flag", 1 | EDGED);
    set("unit", "双");   
    set("no_get",1);
 //   set("no_give",1);
    set("no_sell",1);
    set("nopaimai",1);
    set("no_drop",1);
 
     if ( me->query("env/hcboots1"))
set("wear_msg", ""HIG+me->name()+"穿上一双合成鞋子!  "NOR+me->query("env/hcboots1")+"\n"NOR);
    if ( me->query("env/hcboots2"))
set("unwear_msg", ""HIM+me->name()+"脱掉一双合成鞋子!  "NOR+me->query("env/hcboots2")+"\n"NOR);
 
    }
    setup();
}

int check_name(string name,object me)
{
        int i;

        i = strlen(name);

      if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
              tell_object(me,"合成鞋子名字请定在50个位数。\n");
                return 0;
        }
        while(i--) {
              if( name[i]<=' ' ) {
                  tell_object(me,"对不起，你的合成鞋子名字中不能用控制字符。\n");
                        return 0;
                }
        }
        return 1;
}
