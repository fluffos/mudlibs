// edit by Zjb@HLXY /2003/08/06/

#include <ansi.h>
#include <login.h>

inherit NPC;
void create()
{

           set_name("转世僧人", ({ "zhuanshi sengren", "sengren" }) );
           set("age", 50);
           set("long",@STORY
这个是星空(zjb)写的转世僧人,你可以使用zhuanshi指令来转世
具体请help zhuanshi
STORY
              );
        set("chat_chance", 8);
        set("title",HIC"转世者"NOR);
        exert_function(10);
        set("chat_msg", ({
        "转世僧人偷偷的在你耳边说道：“您可以使用zhuanshi指令来转世重生!”\n",
                }));

        set("gender","男性");
        set("combat_exp",10000);
        set("max_force", 1500);
        set("force",9999999);

        set_skill("hunyuan-yiqi", 999);
        set_skill("force",999);
        map_skill("force", "hunyuan-yiqi");


        setup();
}

void init()
{
        add_action("do_zs", "zhuanshi");
}

int do_zs(object me)
{ 
    int exp, dx,zs, wx, dx2, add;        
    me  = this_player(); 
    exp = me->query("combat_exp"); 
    dx  = me->query("daoxing");
    zs  = me->query("zs");

// add by Zjb@HLXY 以下是判断转世条件
    if ( zs < 1 ) {
            if ( exp < (wx = 500000000) || dx < (dx2 = 400000000) )
            return notify_fail("转一世需要五亿点武学值和四十万年道行，您好象"
                               "还不够!\n");
    } else {
    if ( zs < 11 ) {
            if ( (wx=((zs+5)*100000000)) > exp || (dx2=((zs+4)*100000000)) > dx )
            return notify_fail(""+chinese_number((zs+1))+"转需要"+wx+"武学"
                               "值和"+((zs+4)*100000000)/1000+"年道行\n");
                    } else
    if ( (wx = 1500000000) > exp || (dx2 = 1400000000) > dx )
    return notify_fail(""+chinese_number((zs+1))+"转需要十五亿武学值和一百四十万"
                       "年道行\n"); 
            }

// add by Zjb@HLXY 转世所用的武学和道行
    me->add("combat_exp", -wx);
    me->add("daoxing", -dx2);
 
// add by Zjb@HLXY 以下是转世增加的属性
    add = wx/30000;
    me->add("max_force", add);
    add = dx2/30000;
    me->add("max_mana", add);
    add = 20;
    me->add("shuxing",add);

// add by Zjb@HLXY 以下是转世后的描述
    write("您成功的进行了"+chinese_number((zs+1))+"转了!\n"NOR);
    write("描述自己写...\n");
    command("chat 描述自己写");

// add by Zjb@HLXY 给物件增加转世变量
    me->add("zs",1);

    return 1;
}

