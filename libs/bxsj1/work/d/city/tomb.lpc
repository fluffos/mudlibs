// tomb.c 扬州坟墓
// Lklv modify 2001.9.27

#include <ansi.h>
inherit ROOM;

string look_shibei();
int do_pull(string arg);
void close_door();

void create()
{
	set("short","坟墓");
	set("long", @LONG
这是一个建在岗上最高处的一个大坟，地上插了几柱香，还在燃着。看来
有人经常来这。坟上立了一个大石碑(shibei)，旁边还有一个铁环(huan)。这
里风很大，除了隐隐从远处传来阵阵狗吠声，你什么也听不到。
LONG
	);
	set("outdoors","扬州");

	set("item_desc",([
		"shibei" : (: look_shibei :),
		"huan" : "这是一个铁环，看上去十分光滑。\n",
	]));

	set("exits",([
		"south" : __DIR__"shangang"
	]));
	setup();
}

void init()
{
	add_action("do_pull", "pull");
}

string look_shibei()
{
	return
	"\n"
	"   ※※※※※※※※※※※※※※※   \n"
	"   ※※※                  ※※※   \n"
	"   ※※※     驱逐靼虏     ※※※   \n"
	"   ※※※     还我河山     ※※※   \n"
	"   ※※※                  ※※※   \n"
        "   ※※※※※※※※※※※※※※※   \n";
}

int do_pull(string arg)
{
        object room;

	if( !arg || arg!="huan" ) return 0;
	message("vision","墓碑忽然发出轧轧的声音，向一侧缓缓移开，"
	                "向下露出一个黑洞洞的入口。\n", this_object() );
	set("exits/down", __DIR__"fenduo2");
	if( room = load_object(__DIR__"fenduo2") ) {
 		 room->set("exits/up", __FILE__);
		 message("vision", "头顶上的墓碑忽然发出轧轧的声音，露出一个光亮亮的洞口。\n",room );
	}
	remove_call_out("close_door");
	call_out("close_door", 3);
        return 1;
}

void close_door()
{
	object room;

        if( !query("exits/down") ) return;
        message("vision","墓碑忽然发出轧轧的声音，缓缓地移回原处，"
                "将向下的洞口盖住了。\n", this_object() );
        if( room = load_object(__DIR__"fenduo2") ) {
                room->delete("exits/up");
                message("vision", "头顶上的墓碑忽然发出轧轧的声音，"
                        "墙上的石块又缓缓地收了回去，阶梯消失了。\n",
			room );
        }
        delete("exits/down");
}