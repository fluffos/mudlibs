#define MAX_FILE 1000

mapping *local;
int i;
setup()
{
	l_n(1,6,2,"/d/city/guangchang");
//	... ...
}
l_n(int x, int y, int z, string name1)
{
	if (i<MAX_FILE) {
		local[i]["x"] = x ;
		local[i]["y"] = y ;
		local[i]["z"] = z ;
		strcpy(local[i]["name"], name1);
		i++ ;
	}
}
int get_x(int x)
{
	int low, high, mid;
	low=0 ; high = MAX_FILE;
	while(low<=high) {
		mid = (low + high)/2 ;
		if(x<local[mid]["x"]) high=mid-1;
		else if(x>local[mid]["x"]) high=mid+1;
		else return mid;
	}
}
int get_y(int y, int start_y, int end_y)
{
	int low, high, mid;
	low = start_y ; high = end_y ;
	while(low<=high) {
		mid = (low+high)/2 ;
		if(y<local[mid]["y"]) high = mid -1;
		else if(y>local[mid]["y"]) high = mid +1;
		else return mid;
	}
}
string get_z(int z, int start_z, int end_z)
{
	for (int j=start_z; j<end_z ; j++) {
		if(z==local[j]["z"]) return local[j]["name"];
	}
	return "no this file.";
}
object get_name(int x, int y, int z)
{
	int start_y, start_z, end_y, end_z;
	start_y = get_x(x-1);
	end_y = get_x(x+1);
	start_z = get_y(y-1, start_y, end_y);
	end_z = get_y(y+1, start_y, end_y);
	return (object)get_z(z, start_z, end_z);
}


