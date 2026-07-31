 // Room: darklane1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "暗巷"); 
        set("long", @LONG
小巷又窄又暗，一阵阵又湿又冷的风似鬼魂般时有时无，你不禁
打了个寒战。血腥之气弥漫在空气之中，一种莫名的恐怖，强烈的恐
怖，梦魇般压住了你的心头。血，遍地的血；尸骸，残缺的尸骸……
LONG); 
        set("type","street");
        set("exits",([
        "south":__DIR__"stoneroad2",
        "north":__DIR__"darklane2",
        ]) );
        
                set("objects", ([
        "/d/huizhu/npc/qingbing": 2,
        ]) );
        
        set("indoors", "libie");
        set("coor/x",40);
        set("coor/y",210);
        set("coor/z",0);  
        setup();
} 
void init()
{
        add_action("do_look","look"); 
} 
int do_look(string arg)
{
    object corpse;
    
    if (!arg) return "cmds/std/look"->main(this_player(),"");
    else if (arg != "尸骸"&&arg!="corpses") return 0; 
    if (this_player()->query_skill("dodge",1)<50) {
        write ("你隐隐约约好象看见地上有些尸体,但又看不真切.\n");
        return 1;           
    }
    write("你发现地上躺着几具尸体，好象死了还不到一个时辰。\n");
    corpse=present("bloody corpse",this_object());
     if( !objectp(corpse)) 
     {
    corpse = new(__DIR__"obj/corpse");
    corpse->set("no_get",1);
    corpse->move(this_object());
    corpse = new(__DIR__"obj/corpse");
    corpse->set("no_get",1);
    corpse->move(this_object());
    corpse = new(__DIR__"obj/corpse");
    corpse->set("no_get",1);
    corpse->move(this_object());
    }
    if(!this_player()->query_temp("libie/离别钩_发现尸体"))
        this_player()->set_temp("libie/离别钩_发现尸体",1);
    return 1;
}    
int valid_leave(object me, string dir)
{
	if ( objectp(present("qing bing", environment(me))) && 
		dir == "north")
		return notify_fail("清兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

