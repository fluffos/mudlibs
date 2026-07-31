#include <ansi.h>
inherit NPC; 
void create()
{
 set_name("李红袖", ({ "li hongxiu","li" }) );
 set("gender", "女性" );
 set("title", "博学才女" );
 set("age", 22);
 set("str",20);
 set("max_qi",100);
 set("long",
"这是一个美丽的少女，她穿件宽大而舒服的鲜红衣裳，秀发松松地挽起，露出
双晶莹、修长的玉腿，赤纤秀的、完美无疵的双足。\n" );
 set("combat_exp", 50000);
 set("chat_chance", 1);
 set("chat_msg", ({
 "李红袖咬着嘴唇，道：
我偏不坐下来，偏不讲故事，我也不要晒太阳……这见鬼的太阳，
晒得人头晕，我真不懂你为什麽喜欢太阳？\n",
"李红袖笑声渐渐停止又道：
但你也真该起来做做事了，自从京城回来後，你就连动都不想动，
再这样懒下去，你就要变成流氓了。\n",
"李红袖撇嘴道：楚大少爷的轻功天下无双，江湖中人谁不知道……
但楚大少爷，你的牛已吹完了麽？\n",
        }) );
 set("attitude", "friendly");
 setup();
 carry_object("/clone/misc/cloth")->wear();
} 
