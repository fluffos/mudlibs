#pragma save_binary

/*
   /d/Genesis/std/special_stuff.c

   This 

*/

#define WIZ_PATH "/d/Standard/doc/infowiz/"

start_special(qroom)
{
    call_other(qroom, "query_mail");
}

finger_special()
{
    string file, nam;

    nam = this_object()->query_real_name(); 
    file = WIZ_PATH + nam; 
    if (file_size(file) >= 0)
    {
	write("--------- Special mud info on: " + capitalize(nam) + "\n");
	cat(file);
    }
}
 
