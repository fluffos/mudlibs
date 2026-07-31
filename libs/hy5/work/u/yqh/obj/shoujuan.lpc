#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(HIM "手绢" NOR, ({ "kerchief", "shou juan", "juan" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
               set("long", "这是一条丝制手绢，散发着淡淡的香气，角上绣着三个字“妖怪”。\n");
                set("value", 100000);
                set("armor_prop/armor", 100);
                set("armor_prop/personality", 3);

        }

}


void init()
{
        add_action("quit", "q1");
        add_action("do_bian", "bian");
}

int quit()
{
message("shout",HIR"【翩翩公子】妖怪清声唱道：爱你，忘了苏醒，我情愿闭上眼睛。任凭此生长睡不醒，你就是我的来生。\n"NOR,users());
return 1;
}

int do_bian(string arg)
{
        object who;
        if (!arg)

               return notify_fail("你想变什么？\n");
       if (arg == "human" || arg == "ren") {
if (!this_player()->query_temp("fox")) return notify_fail("你早就化成人形了！\n");
                this_player()->delete_temp("apply/name");
                this_player()->delete_temp("apply/long");
this_player()->delete_temp("fox");
message_vision(HIY"一阵烟雾过后，$N身上的绒毛尽退，变成了一个身材清瘦，眉目间有些微愁的书生。\n"NOR, this_player());
   
                return 1;
        }
       if (arg == "fox" || arg == "huli")
{if (this_player()->query_temp("fox")) return notify_fail("你原本就是狐狸呀！\n");
        message_vision(HIR"$N似乎有些不对劲儿，原来脸颊上、手背上竟长出一绒毛，身形渐渐变小，竟成了一只狐狸。\n"NOR, this_player());
            this_player()->set_temp("apply/name", ({"九尾妖狐"}));
            this_player()->set_temp("apply/long", ({"一只有九条尾巴的狐狸。\n"}));
this_player()->set_temp("fox",1);
        return 1;
}
}
int query_autoload() { return 1; }
