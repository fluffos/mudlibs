//  xingxiu.h
//  Ffox 98-9-18 13:40
//  计划：

#define __XX__ "/d/menpai/xingxiu/"
#define __XOBJ__ "/d/menpai/xingxiu/obj/"
#define __XNPC__ "/d/menpai/xingxiu/npc/"


/*
\在这个头文件里面，将有以下功能函数：\
\现在还没有\
\返回星宿弟子: is_xingxiu(ob) \
*/
#include "ansi.h"
int is_xingxiu(object ob)
{
    if( ob->query( "family/family_name" )=="星宿派" ) return 1;
    return 0;
}
