#include <mudlib.h>
inherit CMD;
#define MARRY_GATE "/sgdomain/area/marriage/marry_gate"
void main()
{	object who,rom;
	string p_area;

	who = CHAR_D->find_char("group");
	p_area = "xiangping";

        rom=load_object("/a/"+p_area+"/"+AREA_D->get_area(p_area,"meeting"));
        rom->add_exit("litang" , MARRY_GATE);
        rom=load_object(MARRY_GATE);
        rom->add_exit("out","/a/"+p_area+"/"+AREA_D->get_area(p_area,"meeting"));

        CHAR_D->add_char("li guan");
        CHAR_D->set_char("li guan","body","marriage/lg");
        CHAR_D->set_char("li guan","is_tmp",1);
        CHAR_D->appear("li guan",p_area,"meeting","$N兴致勃勃地走了过来。\n");
        CHAR_D->find_char("li guan")->set_boygirl("group","zhou feng");
        CHAR_D->remove_char_d("li guan");

        CHAR_D->add_char("si yi");
        CHAR_D->set_char("si yi","body","marriage/sy");
        CHAR_D->set_char("si yi","is_tmp",1);
	 CHAR_D->put_char("si yi","/sgdomain/area/marriage/marry_tang");
        CHAR_D->find_char("si yi")->set_boygirl("group","zhou feng");
        CHAR_D->remove_char_d("si yi");
}	
