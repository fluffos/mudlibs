class coordinate { int x; int y; }
void test()
{
mixed *newpath = ({});
class coordinate temp, temp1;
object me = this_player();

temp = new(class coordinate);
temp->x = 2;
temp->y = 2;
newpath += ({ temp });
temp = new(class coordinate);
temp->x = 5;
temp->y = 5;
newpath += ({ temp });
        tell_object(me, sprintf("newpath is  %O\n", newpath)); 
   for(int i=0;i<sizeof(newpath);i++)
	if( newpath[i]->x == 2 && newpath[i]->y ==2 )
	        newpath[i] = 0;
newpath -= ({ 0 });
temp1 = new(class coordinate);
temp1->x = 2;
temp1->y = 2;
newpath -= ({ temp1 });

/*
if( member_array(temp, newpath) != -1)
        tell_object(me, sprintf("temp is in member\n"));
temp = newpath[random(sizeof(newpath))];
        tell_object(me, sprintf("%O\n", temp));
*/
        tell_object(me, sprintf("newpath is  %O\n", newpath)); 
}
