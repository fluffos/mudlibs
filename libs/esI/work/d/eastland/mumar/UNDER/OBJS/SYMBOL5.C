#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "plast_symbol", "plast" );
}
 
void create()
{
        set_name( "gold symbol", "锋锐金符" );
        add( "id", ({ "gold","symbol" }) );
        set_short( "锋锐金符" );
        set_long( @C_LONG
这是一张黄色的符纸，上面画著许多你看不懂的符号。唯一你看得懂的字是最下面
的一个『金』字。
C_LONG
                );
        set("unit","张");
        set("weight", 1);
        set("value",({ 1, "silver"}) );
        set("no_sale", 1 );
}
 
int plast_symbol(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="库房大门" ) {
        tell_object(this_player(),
                "你拿著令牌，守卫对你一幅必恭必敬的样子。\n" );
        this_player()->set_temp("army_mark",1);
        } else
    if ((string)environment(this_player())->query("short")=="密道岗哨" ) {
        tell_object(this_player(),
                "你拿著令牌，守卫对你一幅必恭必敬的样子。\n" );
        this_player()->set_temp("army_mark",1);
        } else
        tell_object(this_player(),
                "你拿著令牌像笨蛋一样晃呀晃呀地，可是没人理你。\n" );
        return 1;
}
