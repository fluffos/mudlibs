// sz:shenzhen.c
// 97.10.1   by Aug

inherit ROOM;

void create()
{
      set("short", "神针世家");
	set("long", @LONG
这里是神针世家叶家世代居住的祖宅。屋中的陈设虽简朴但不失其世
家风范，屋中桌椅虽然有些陈旧，但看起来都很结实；铺地的石板也有了
磨损的痕迹。总之一切都显示着叶家悠久的历史。而这屋子里最显眼的东
西就是门梁上的那块金字大匾(bian)－－据传这还是苏东坡的手迹呢，和
那副古色古香的药架(yaojia)－－这才是叶家世代受人尊重的根源所在。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/shenyi" :  1,
	]));

	set("item_desc", ([ /* sizeof() == 1 */
		"yaojia" : "药架上摆满了药瓶，药罐，一个玉盒里还有几枚闪闪发光的银针。\n",
		"bian" : "匾上书写着四个金光闪闪的大字－－「神针世家」。\n",
	]));

	set("no_fight",1);
	set("no_magic",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

      set("exits", ([ /* sizeof() == 1 */
	    "north" : "/d/pingan/west2",
	]));
      
	setup();
	replace_program(ROOM);
}

