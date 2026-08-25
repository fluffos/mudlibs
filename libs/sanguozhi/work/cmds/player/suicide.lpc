// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** suicide.c
**
*/

inherit CMD;

nomask void main(string arg) {
    string my_id=this_user()->query_userid();
    if(CHAR_D->get_char(my_id,"ranknation")==R_KING)
    {
         write("身为一国之君怎能随便轻身？\n");
         return;
    }
    if(MUSEUM_D->char_exist(my_id))
    {
         write("已经进了典藏馆，怎么好意思在自杀？\n");
         return;
    }
    if(AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"leader")==my_id)
    {
         write("身为首领，怎能随便轻身？\n");
         return;
    }

    if(wizardp(this_user()))
    {
        write("身为巫师，怎能随便轻身？\n");
        return;
    }
    USER_D->suicide();    
}

