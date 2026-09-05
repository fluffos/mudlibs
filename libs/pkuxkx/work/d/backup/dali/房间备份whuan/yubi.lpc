// by paladin

inherit ROOM;

void create()
{
set("short","无量玉璧");
        set("long", @LONG
石壁平整异常，宛然似一面铜镜. 当年无量剑东宗、西宗的掌门人，
常在月明之夕见到玉壁(yubi)上有舞剑的仙人影子. 
LONG
        );
        set("outdoors", "dali");

        set("no_fight", 1);
        set("item_desc", ([ /* sizeof() == 2 */

  "yubi" : "你突然之间全身一震，只见对面玉壁上赫然有个人影。\n",

]));




        set("exits", ([
           "south" : __DIR__"yubi2",
	   "west" : __DIR__"yubi3",
        ]));


        setup();

}

void init()
{
        add_action("do_watch","watch");
}

int do_watch(string arg)
{ object me;

me = this_player();
message_vision("$N正专心观看玉壁。\n", me);

// if (arg != "yubi" ) return 0;

if( (int)me->query("max_jingli",)<150)
        {
            write("你精力不够，无法领悟玉壁\n");
                return 1;
        }
if( (int)me->query("jing",)<50)
        {
           write("你太累了，歇歇再读吧。\n");
           return 1;
         }  
if( (int)me->query_skill("sword",1)>150)
        {
        write("你看了半天，发现玉壁上的剑法对你太浅了。\n");
                return 1;
        }


else    {
 //me->sleep();
  message_vision("$N对着玉壁研究了一会,似乎有些心得。\n", me);
  me->add("jing",-30);
      me->improve_skill("sword",(int)(me->query_skill("literate")/4+1));

 return 1;      }

}


