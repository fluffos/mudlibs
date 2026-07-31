//Cracked by puma 12/14/2002
// dealer_d.c
// by puma@XKM

#define ITEMS_DEALER	"/data/items_dealer"

inherit F_SAVE;

string *items_dealer_file;

void sell_items_dealer(object item);
void buy_items_dealer(object item,int num);
string *query_items_dealer_file();

string query_save_file()
{
	return ITEMS_DEALER;
}

void create()
{
	seteuid(getuid());
	if (file_size(ITEMS_DEALER)<=0)
	{
		items_dealer_file=({});
		save();
	}
	restore();
}

void buy_items_dealer(object item,int num)
{
	int mounts,i;
	
	for (i=0,mounts=0;i<sizeof(items_dealer_file);i++)
	{
		if(items_dealer_file[i]==base_name(item))
	        mounts++;
	}
	mounts-=num;
	
	items_dealer_file=items_dealer_file-({base_name(item)});
	
	for (;mounts>0;mounts--)
	{
		items_dealer_file=items_dealer_file+({base_name(item)});
	}
	
	save();
	restore();
}

void sell_items_dealer(object item)
{
	items_dealer_file=items_dealer_file+({base_name(item)});
	save();
	restore();
}

string *query_items_dealer_file()
{
	return items_dealer_file;
}