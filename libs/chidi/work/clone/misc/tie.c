// tie.c   change by zhm
inherit ITEM;
mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"tam":"/d/city2/tian_anm",
"wd":"/d/wudang/chaotian",
"xy":"/d/xiaoyao/qingcaop",
"qz":"/d/quanzhou/zhongxin",
]);
void init(){
add_action("do_goto","goto");
}
void create(){
set_name("时空传送帖",({"tie"}));
set("no_get",1);
set_weight(100); set_max_encumbrance(8000);
        if( clonep() )                set_default_object(__FILE__);
 else {     set("long",              "一张时空传送帖，以它的魔力现在所能传送(goto)的地方如下。\n
\t中央广场(gc)    少林寺(sl)    天安门(tam)   \n  
\t武当山(wd)      逍遥派(xy)    泉州(qz)  \n");
set("value", 50000);
set("unit","张");
}
}
int do_goto(string arg){
        object me,obj;string msg,str;str=where_map[arg];
        if( !arg||!stringp(str)) return notify_fail("你要去哪里？\n");
me=this_player();
             if (! environment(me)->query("outdoors"))
 return notify_fail("在这房间里无法使用魔法传送。\n");
 if (me->is_fighting())
return notify_fail("战斗中无法使用魔法传送！");
str+=".c";
        if(file_size(str)<0) 
return notify_fail("没有这个地方。\n");
    if( stringp(msg = me->query("env/msg_mout")) )       {if (msg!="") message_vision(msg+"\n", me);} 
       else                message_vision("只见一阵烟雾过後，$N的身影已经不见了。\n", me);
me->move(str);
if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else                message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);        return 1;}
