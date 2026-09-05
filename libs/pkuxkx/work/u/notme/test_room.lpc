// only for wizard room test

#include <ansi.h>
inherit ROOM;
int do_test(string);
int do_edem(string);
int do_edem2(string);

string *index= ({
    "myself","others","myself_self","others_self",
    "myself_target","target","others_target"
    }); 
string *explain= ({
       "不指定对象，自己看到：",
       "不指定对象，他人看到：",
       "对自己使用，自己看到：",
       "对自己使用，他人看到：",
       "对别人使用，自己看到：",
       "对别人使用，对象看到：",
       "对别人使用，他人看到："
    });

void create()
{
    set("short", "测试室");
    set("long",@LONG
测试专用    
───────────────────────────────────
LONG
       );
    set("exits", ([
                "east":"/u/notme/wizard_room_notme",
                ]));
                set("no_clean_up", 0);
                setup();
    set("objects",([
                "/clone/weapon/dart":3,
                "/clone/weapon/jian":1,
                "/clone/weapon/gangdao":1,
                "/clone/food/baozi":1,
                "/clone/food/jiudai":1,
                "/clone/misc/checker":1,
                ]));
    setup();
}
void init()
{
    add_action("do_test","test");
    add_action("do_edem","edem");
    add_action("do_edem2","edem2");
}

int do_test(string arg)
{
    string action, target;
    if(!arg) return 0; 
	sscanf(arg, "%s %s", action, target);
    printf("arg %s\naction %s\ntarget %s\n", arg, action, target);
    return 1;
       
}
    
int do_edem2(string arg)
{
    string *line;
    string lines, file_name;
    mapping emote = ([ ]);
    
    if(!arg) return notify_fail("你想要测试什么？\n");
    file_name = sprintf("/u/%s/%s", this_player()->query("id"),arg);
    lines = read_file(file_name);

    if( !(lines) )
        return notify_fail("文件不存在。\n");
    line = explode(lines,"$$$"+"\n");
    printf("lines\n%s",lines);
    for(int i=0;i<sizeof(line);i++)
    {
        printf("%d %s %s\n%s\n",i,index[i],explain[i],line[i]);
        emote[index[i]] = line[i];
    }
    emote["updated"] = this_player()->query("id");
    EMOTE_D->set_emote(arg, emote);
    return 1;
}

int do_edem(string arg)
{
    string *line;
    string lines, file_name;
    mapping emote = ([ ]);
    
    if(!arg)
    {
        printf("命令格式 edem filename
$N : 自己的名字.
$n : 目标的名字.
$P : 自己的人称代名词.
$p : 目标的人称代名词.
$S : 对自己的称呼。
$s : 对自己的粗鲁称呼。
$C : 别人对自己的尊称。
$c : 别人对自己的粗鲁称呼。
$R : 对别人的尊称。
$r : 对别人的粗鲁称呼。\n");
        return notify_fail("你想要编辑什么 emote？\n");
    }
    file_name = sprintf("/u/%s/%s", this_player()->query("id"),arg);
    lines = read_file(file_name);

    if( !(lines) )
        return notify_fail("文件不存在。\n");
    line = explode(lines,"\n");
    for(int i=0;i<sizeof(line);i++)
    {
        printf("%d %s %s\n%s\n",i,index[i],explain[i],line[i]);
        emote[index[i]] = line[i];
    }
    emote["updated"] = this_player()->query("id");
    EMOTE_D->set_emote(arg, emote);
    rm(file_name);
    return 1;
}
