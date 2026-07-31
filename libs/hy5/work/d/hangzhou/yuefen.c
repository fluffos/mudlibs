// yuefen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "岳坟");
        set("long", @LONG
墓道两旁有石虎，石羊，石马和三对翁仲。正中古柏交柯，便是岳飞的坟墓。
墓碑刻着“宋岳鄂王墓”。 岳王墓的左面，便是岳飞之子岳云的墓，墓碑上
刻着“宋继忠侯岳云之墓”.  在岳坟前面两边四个铁像(statue)。东首墙上
有四个大字(word)。
LONG);
        set("exits", ([
            "south"     : __DIR__"yuelang",
        ]));
        set("item_desc" , ([
            "statue" :
"北边两个是秦烩和他的妻子王氏；南边两个是同谋杀害岳飞的奸臣，
张俊和万俟屑。四个铁像都反翦着手，向岳墓跪着。遭受万人的唾骂(tuo)。\n",
            "word"   :
"墙上有“精忠报国”四个大字。这是岳母当年训子时在岳飞背上刻的字。\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
//        replace_program(ROOM);
}
void init()
{
   add_action("do_spit","spit");
   add_action("do_spit","tuo");
   add_action("do_spit","唾");
}
int do_spit(string arg)
{
   if( !arg || arg=="" ) 
{
message_vision("$N要唾什么啊?”\n", this_player());
   return 1;
}
   if( arg=="statue" )
   {   switch (random(4)) {
   	 case 0:
		message_vision("$N向秦烩像唾了一口，骂道：“死奸臣 *&#$%。”\n", this_player());
		break;
	 case 1:
		message_vision("$N向王氏像唾了一口，骂道：“死贱妇，世世为娼，永不翻身。”\n", this_player());
		break;
	 case 2:
		message_vision("$N向张俊像唾了一口，骂道：“为虎作娼，陷害忠良。”\n", this_player());
		break;
	 case 3:
		message_vision("$N向万俟屑像唾了一口，骂道：“为虎作娼，陷害忠良。”\n", this_player());
		break;
   }
   return 1;
}
}
