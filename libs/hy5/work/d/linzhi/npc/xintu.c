#include <ansi.h>
inherit NPC;

mapping *data=({
(["name":"达玛",	"id":"xizang man",	"mw":1,	]),
(["name":"金珠",	"id":"xizang man",	"mw":1,	]),
(["name":"德吉梅朵",	"id":"xizang man",	"mw":1,	]),
(["name":"谐本齐美",	"id":"xizang man",	"mw":1,	]),
(["name":"达娃",	"id":"xizang man",	"mw":1,	]),
(["name":"梅朵",	"id":"xizang man",	"mw":1,	]),				
(["name":"白玛达娃",	"id":"xizang man",	"mw":1,	]),				
(["name":"卓玛",	"id":"xizang man",	"mw":1,	]),				
(["name":"拉姆",	"id":"xizang man",	"mw":1,	]),					
(["name":"贡嘎宁布",	"id":"xizang man",	"mw":-1,	]),					
(["name":"索朗孜摩",	"id":"xizang man",	"mw":-1,	]),					
(["name":"扎巴坚增",	"id":"xizang man",	"mw":-1,	]),					
(["name":"去丹贡布",	"id":"xizang man",	"mw":-1,	]),					
(["name":"丹增班觉",	"id":"xizang man",	"mw":-1,	]),					
(["name":"次仁旺杰",	"id":"xizang man",	"mw":-1,	]),										
(["name":"次仁旺堆",	"id":"xizang man",	"mw":-1,	]),					
(["name":"格桑旺堆",	"id":"xizang man",	"mw":-1,	]),					
(["name":"丹巴",	"id":"xizang man",	"mw":-1,	]),					
(["name":"达杰",	"id":"xizang man",	"mw":-1,	]),					
(["name":"江央",	"id":"xizang man",	"mw":-1,	]),					
(["name":"多吉",	"id":"xizang man",	"mw":-1,	]),										
(["name":"格列",	"id":"xizang man",	"mw":-1,	]),					
(["name":"群佩",	"id":"xizang man",	"mw":-1,	]),					
(["name":"丹增",	"id":"xizang man",	"mw":-1,	]),					
(["name":"朗嘎",	"id":"xizang man",	"mw":-1,	]),					
(["name":"次松",	"id":"xizang man",	"mw":-1,	]),					
(["name":"次吉",	"id":"xizang man",	"mw":-1,	]),										
(["name":"米玛",	"id":"xizang man",	"mw":-1,	]),										
(["name":"普布",	"id":"xizang man",	"mw":-1,	]),										
(["name":"拉巴",	"id":"xizang man",	"mw":-1,	]),										
(["name":"措姆",	"id":"xizang man",	"mw":-1,	]),													
(["name":"玛琼",	"id":"xizang man",	"mw":-1,	]),										
(["name":"那森",	"id":"xizang man",	"mw":-1,	]),											
(["name":"白巴",	"id":"xizang man",	"mw":-1,	]),											
(["name":"格桑索却",	"id":"xizang man",	"mw":-1,	]),											
(["name":"扎西巴杂",	"id":"xizang man",	"mw":-1,	]),													
(["name":"丹巴国钦",	"id":"xizang man",	"mw":-1,	]),											
(["name":"多吉辖过",	"id":"xizang man",	"mw":-1,	]),											
(["name":"巴桑甲马",	"id":"xizang man",	"mw":-1,	]),													
(["name":"旺钦跌布",	"id":"xizang man",	"mw":-1,	]),											
(["name":"次丹堆古",	"id":"xizang man",	"mw":-1,	]),											
(["name":"玛钦次旦",	"id":"xizang man",	"mw":-1,	]),													
(["name":"兴索强巴",	"id":"xizang man",	"mw":-1,	]),											
(["name":"安姆吉格桑",	"id":"xizang man",	"mw":-1,	]),													
(["name":"贡布",	"id":"xizang man",	"mw":-1,	]),											
(["name":"帕卓",	"id":"xizang man",	"mw":-1,	]),											
(["name":"顿珠",	"id":"xizang man",	"mw":-1,	]),													
(["name":"珠杰晋美",	"id":"xizang man",	"mw":-1,	]),											
});
void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ "xintu" }));
//        set_name("去丹贡布", ({ "xintu"}) );
        set("gender", "男性" );
        set("age", 55);
        set("str", 10);
        set("long", @LONG
一个装束华丽但已很破旧的藏人，达赖活佛的虔诚信徒。
LONG
);
        set("attitude", "peaceful");
        set("title", "朝圣信徒");
        set("combat_exp", 10000);
        set_skill("unarmed", 70);
set("gender", "男性");
if (npc["mw"]==1) set("gender", "女性");
else set("gender", "男性");
        set_skill("force", 50);

    set_skill("iron-cloth", random(50)+100);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
 "\n"+query("name")+"面向寺庙，三步一拜，五步一叩，执着而神圣地往前跪行着。\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/hada")->wear();
 
}  
