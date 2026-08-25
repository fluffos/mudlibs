inherit OUTDOOR_ROOM;
void setup(){
    string st1,st2,st3;
    set_light(50);
    set_brief(mud_name()+"博物馆");
    set_long(read_file("/sgdomain/museum/yard.pic"));
    set_exits( ([
        "out" :  "/a/huayin/vhall",
	"enter" : "/sgdomain/museum/control/"+MUSEUM_D->get_enter_room(),
            ]) );

    set_area("museum");
}                

