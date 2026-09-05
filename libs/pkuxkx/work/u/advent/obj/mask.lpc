
#include <armor.h>
inherit HEAD;

int do_wear(string arg);
int do_remove(string arg);
void create()
{
        set_name("面罩", ({ "mianzhao", "mask" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是个神龙教特有的黑布头套，能把整个脑袋套起来，只露出两个眼睛。\n你每次为神龙教办案后，务必在尸体上写下(sign)“逆神龙教者杀！”。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 10);
                set("no_get", "这样东西不能离开那儿。\n");
                set("no_drop", "这样东西不能离开你。\n");
        }
        setup();
}

void init()
{
        add_action("do_wear", "wear");
        add_action("do_remove", "remove");
}

int do_wear(string arg)
{
        if (!arg || (arg != "mianzhao" && arg != "mask") ) return 0;

        this_player()->set_temp("apply/name",  ({"蒙面人"}));
        this_player()->set_temp("apply/short", ({"蒙面人(Mengmian ren)"}));
        this_player()->set_temp("apply/id", ({"Mengmian ren"}));
        this_player()->set_temp("apply/long",  ({"一个黑布蒙面，神秘兮兮的家伙。\n"}));

        return 0;
}

int do_remove(string arg)
{
        if (!arg || (arg != "mianzhao" && arg != "mask") ) return 0;

        this_player()->delete_temp("apply/name");
        this_player()->delete_temp("apply/short");
        this_player()->delete_temp("apply/long");
        this_player()->delete_temp("apply/id");

        return 0;
}
