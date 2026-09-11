#include <mudlib.h>
#include <daemons.h>
inherit CMD;

void main()
{
	//AREA_D->set_area("wuguan","troop",([]));
	//printf("hello world\n");
	
	string * char_list;
	string * area_list_all;
	string rdm_area;
	
	char_list = sort_array(CHAR_D->list_chars(), 1);
	area_list_all = sort_array(AREA_D->list_areas_all(), 1);
	foreach(string onechar in char_list)
	{
		if(!stringp(CHAR_D->get_char(onechar,"area")))
		{
			printf("%s   ",onechar);
			rdm_area = area_list_all[random(sizeof(area_list_all))];
			CHAR_D->set_char(onechar,"area",rdm_area);
			printf("地区设置为%s\n",rdm_area);
		}
		/*if(mapp(AREA_D->get_area(temp,"troop")))
		{
			printf("%s:  %O\n",temp,AREA_D->get_area(temp,"troop"));
			//printf("%s\n",temp);
			//printf("%s\n",AREA_D->set_area(temp,"troop",([])));
		}*/
		/*printf("%s    ",temp);
		AREA_D->set_area(temp,"open",0);*/
	}

	
}


