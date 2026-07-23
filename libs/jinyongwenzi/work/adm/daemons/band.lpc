// ban.c
// Created by Xiang@XKX

// #include <net/telnet.h>

#define BANNED_SITES "/log/banned_sites"

void load_sites();
void add(string pattern);
void del(string pattern);
int  is_banned(string site);
void print();

string *Sites;

void create()
{
	seteuid(getuid());
	load_sites();
}

void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });
}

int is_banned(string site)
{
	string *line;
	int i;

	line = ({});
	line += ({site});

	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1)
			return 1;
	return 0;
}	

void print()
{
	int i;
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
}

void add(string site)
{
	if (member_array(site, Sites) >= 0) {
		write(site + " 已经被 ban 了。\n");
		return;
	}
	Sites += ({site});
	write(site + " 被 ban 了。\n");
	write_file(BANNED_SITES, Sites[<1] + "\n");
}

void del(string site)
{
        string file;
        string *file_info;
        int i, tt = 0;

        if (file_size(BANNED_SITES) < 0) {
                write(BANNED_SITES+"不存在,目前没有站点被禁止.\n");
                return;
        }
        file = read_file(BANNED_SITES);
        file_info = explode(file,"\n");
        if (sizeof(file_info) < 1) {
                write(BANNED_SITES+"不存在,目前没有站点被禁止.\n");
                return;
        }
        for (i=0;i<sizeof(file_info);i++) {
                if (file_info[i] == site) {
                        tt = 1;
                        file_info = file_info[0..i-1] + file_info[i+1..sizeof(file_info)];
                        break;
                }
        }
        if (tt == 0) {
                write(site + "并没有被禁止。\n");
                return;
        }
	Sites -= ({ site });
        rm(BANNED_SITES);
        for(i=0;i<sizeof(file_info);i++)
                write_file(BANNED_SITES,file_info[i]+"\n");
        write("站点 "+site+" 已经解禁。\n");
        return;
}
