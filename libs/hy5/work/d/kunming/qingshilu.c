// /d/kunming/qingshilu
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "青石路" );
        set("long", @LONG
出了石林，就到了昆明的官道，青石铺成，平坦宽阔，西去不远
就是昆明了。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"qingshilu1", 
                "east" :  "/d/wudujiao/xiao3", 	
                "northeast"  :__DIR__"shilin2",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
