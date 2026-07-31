#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
set_name(HIG"复活戒指"NOR, ({ "fuhuo jie", "jiezhi", "ring" }));
set("weight", 800);
if (clonep())
        set_default_object(__FILE__);
  else {
        set("unit", "枚");
        set("value", 9000);
        set("no_drop",1);
        set("no_give",1);
        set("no_put",1);
        set("material", "gold");
        set("armor_prop/armor", 5);
        set("armor_prop/personality", 3);
        set("armor_prop/no_die",1);
        }
setup();
}       

int no_die(object who)
{
int num;
string str;
        
if ( !who || !present(this_object(),who) )
        return 0;
str = read_file(__DIR__"复活戒指.txt");
num = atoi(str);
if ( wizardp(who) )
        tell_object(who,"num="+num+"\n");
if ( time()<num+86400 )
        return 0;
message_vision(name()+"上闪了几闪，$N顿时变得活力十足！\n",who);
num = time();
write_file(__DIR__"复活戒指.txt",""+num+"",1);
return 1;
}               

