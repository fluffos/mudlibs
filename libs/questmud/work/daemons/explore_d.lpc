// Explore system v1, May 2004. - Nalle.

/**********************************************************************/

int query_hash(string path)
{
 int i, a, b, z;

 if(!path) return 0;

 a = 0; b = 0;

 for(i = 0; i < strlen(path); i++)
    {
     z = (int) path[i];

     if(i%2)
       {
	a ^= z;
	b  = (b + z) % 127;
       }
	 else
       {
	b ^= z;
	a  = (a + z) % 127;
       }
    }

 return a + b * 127 + 1;
}

/**********************************************************************/

int format_change(int hash)
{
 return (int) (to_float(hash) / 1.37);
}

/**********************************************************************/

// historical
int add_room(object player) { return 1; }

/**********************************************************************/

