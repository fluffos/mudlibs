#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "大海");
	set("outdoors","海上");
        set("long", "一望无际的大海，但见夕阳即将没入波心，照得水面上万道金蛇，闪烁不定。一个浪头
伴着汹涌澎湃的浪涛声扑将上来，这巨浪犹似一堵结实的水墙，砰的一声大响，只打得
船木横飞，险些翻转过去！\n");
        set("no_clean_up", 1);
	setup();
}

void init()
{
   string dest;
   if(this_player()->is_character()) {
        tell_object(this_player(), HIR"\n一个巨浪打来，将你抛上了天。。。！\n"NOR);
        this_player()->unconcious();
        dest = ({ "/d/mingjiao/xikou", "/d/mingjiao/lsd/anbian"})[random(2)];
        this_player()->move(dest);
        message("vision", "突然一阵大风刮过，将一个"+this_player()->name()+"从海里吹上岸来！\n",environment(this_player()), ({this_player()}));
        }   
}

int clean_up() { return 0; }
