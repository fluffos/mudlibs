// story:linghu
// storied by zgbl@pkuxkx

#include <ansi.h>

int give_gift();

protected mixed *story = ({
"闻令狐冲伤重，五毒教蓝凤凰特送上五宝花蜜酒一壶，",
"此酒乃如何如何酿成，分五天服用。                ",
"第一天                                        ",  
"令狐冲喝了一口，把酒放窗口睡了。                ",
"第二天                                        ",  
"酒少了                                        ",  
"令狐冲在酒壶上贴上“禁止偷喝”字样。            ",
"第三天                                        ",  
"酒又少了                                      ",  
"令狐冲在壶上贴上“偷喝者断子绝孙”字样。        ",
"第四天                                        ",  
"酒又少了                                      ",  
"任盈盈说，何不贴上“夜壶”字样 。               ",
"令狐冲一琢磨，照做了。                          ",
"第五天                                        ",  
"壶满了...                                     ",  
"令狐冲：...                                   ",  
"任盈盈：这酒没法喝了，扔了吧。                  ",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
	      if(!random(3))
        STORY_D->give_gift("/d/jiaofei/npc/obj/wuxianjiu", 1,
                           HIM "\n天上掉下五宝花蜜酒一壶，“咚”的一声掉到你面前。\n\n" NOR);
        else
        STORY_D->give_gift("/clone/story/obj/niaohu", 1,
                           HIM "\n天上掉下五宝花蜜酒一壶，“咚”的一声掉到你面前。\n\n" NOR);                           
        return 1;
}
