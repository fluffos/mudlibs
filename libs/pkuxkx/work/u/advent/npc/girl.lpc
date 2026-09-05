#include <ansi.h>

#include "translate.h"    
inherit NPC;
void create()
{
        int i,amun;
        string *name= ({"清风", "明月", "彩云",});
        set_name( name[random(3)] , ({ "pretty girl", "girl" }) );
        set("long", "这是行云家的陪读小丫鬟。\n");
        set("attitude", "friendly");
        set("max_qi", 500);
        set("max_jing", 500);
        set("age", 18);
        set("gender", "女性" );
        set("chat_chance", 10);
        set("chat_msg", ({
                "小丫鬟窃窃道：听说主人去了燕子坞，也不知道是真是假．\n",
                "小丫鬟叹了口气：主人好久没有回来了．\n",
        }) );
        set("per", 100);
        set("combat_exp", 200000);
        setup();
}
string SetPassword()
{
        string *llt = ({
        "1","2","3","4","5","6",
        "7","8","9","0","a","b",
        "c","d","e","f","g","h",
        "i","j","k","l","m","n",
        "o","p","q","r","s","t",
        "u","v","w","x","y","z",
        });
        string output = "";
        int i,j;
        for (i=0;i<4+random(3);i++)
        {
                j=random(36);
                output=output + llt[j];
        }
        return output;
}
int SizeOfStr()
{
return sizeof("abcd");
}
