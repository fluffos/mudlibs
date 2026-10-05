//Cracked by Kafei
//wzfeng@xkx 2000 6
//job_system 的一些附加函数
//判断一个string数否在一个group中
int is_attribute(string element,string *group)
{
	int i;
	if(!pointerp(group))
		return 0;
	for(i=0;i<sizeof(group);i++)
	{
		if(element==group[i])
			return 1;
	}
	return 0;
}
//在一个字串阵列中添加一个字串
mixed *add_string(mixed element,mixed *group)
{
	if( !pointerp(group) )
       {
         group = ({ element });
        }
	else group += ({ element });
	return group;
}
/*
mixed add_mapping(mixed keys,mixed mapping,mapping map)
{
	string *map_keys;
	if(!sizeof(map))
		return 0;
	
	return map;
}
*/
//在一个字串阵列中减去一个字串
mixed *decrease_string(mixed element,mixed *group)
{
	if( !pointerp(group) )
       {
        return group;
        }
	else group -= ({ element });
	return group;
}


//判断一个string数否在一个*map的一个标记tag中
int is_attr_mapping(string element,string tag,mapping *map)
{
	int i;
	string *tag_temp;
	if(!pointerp(map))
		return 0;
	for(i=0;i<sizeof(map);i++)
	{
		if(!tag_temp=keys(map[i]))
			return 0;
		if(element==map[i][tag])
			
		return 1;
	}
	return 0;
}
//返回一个*mapping中的一个指定mapping,这个mapping中的tag中包含有固定的字串str
mixed get_mapping(mixed element,mixed tag,mapping *map)
{
	int i;
	string *tag_temp;

	if(!pointerp(map))
		return 0;
	for(i=0;i<sizeof(map);i++)
	{
		if(!tag_temp=keys(map[i]))
			return 0;
		if(element==map[i][tag])
		return map[i];
	}
	return 0;

}


//获取一个*mapping中指定mapping中tag标记的内容
mixed get_msg_map(string tag1,string tag1_str,string tag2,mapping *map)
{
	int i;
	string *tag_temp;
	if(!pointerp(map))
		return 0;
	for(i=0;i<sizeof(map);i++)
	{
		if(!tag_temp=keys(map[i]))
			return 0;
		if(tag1_str==map[i][tag1])
			return map[i][tag2];
			//printf("%s\t%s\n",element,map[i][tag]);
	}
	return 0;
}

//获得一个*mapping中某种成员的所有数值的阵列
mixed *get_array_map(string tag1,mapping *map)
{
	int i;
	mixed *str;
	string *keys;
	if(!pointerp(map))
		return 0;
	for(i=0;i<sizeof(map);i++)
	{
		keys=keys(map[i]);

		if(is_attribute(tag1,keys))
		str=add_string(map[i][tag1],str);
	}
	return str;

}
//判断一个key是否在map中
int judge_map_element(string element,mapping map)
{
	string *keys;
	int i;
	if(!sizeof(map))
		return 0;
	keys=keys(map);
	for(i=0;i<sizeof(keys);i++)
	{
		if(keys[i]==element)
			return 1;
	}

	return 0;
}
//change the maps member.
mapping *change_map(mapping map,mapping *maps,string fag,mixed element)
{
	int i;
	if( !pointerp(maps) )
        {
         maps = ({});
		 maps=add_string(map,maps);
		 return maps;
        }

	for(i=0;i<sizeof(maps);i++)
		if(maps[i][fag]==element)
		{
			maps[i]=map;
			return maps;
		}
		 maps=add_string(map,maps);
		 return maps;

}

//get map message
string p_map(mapping map)
{
	string *keys,msg;
	int i;
	msg="";
	
	if(!sizeof(map))
	{
		return ("map为空\n");

	}
		
	keys=keys(map);
	if(!sizeof(keys))
	{
		return ("keys为空\n");

	}
	for(i=0;i<sizeof(keys);i++)
	{

		msg+=("["+keys[i]+"]=="+map[keys[i]]+"\n");
	}

	return msg;


}
//change a map in maps
mapping *modify_map(string element,string fag,mapping map,mapping *maps)
{
	int i;
	if( !pointerp(maps) )
        {
         maps = ({});
		 return maps;
        }
	for(i=0;i<sizeof(maps);i++)
	{
		if(maps[i][fag]==element)
		{
		maps[i] = map; 
		return maps;
		}
	}
	return 0;

}
//获取一个map中的最大数的成员，如果有相等的。返回一个数列
string *get_maxnum_inmap(mapping map)
{
	int i,map_num,temp_num;
	string *keys,*member,temp_key;
	if(!(map_num=sizeof(map)))
		return member;
	keys=keys(map);
	if(map_num==1)
	{
		//write("只有一个成员");
		return keys;
	}
	temp_num=map[keys[0]];
	temp_key=keys[0];
	
	for(i=0;i<(map_num-1);i++)
	{
		if(map[keys[i+1]]>temp_num)
		{
			//write(map[keys[i+1]]+">"+temp_num+"\n");
			temp_num=map[keys[i+1]];
			temp_key=keys[i+1];
			
		}
		
	}
	
   //member=add_string(temp_key,member);

	for(i=0;i<(map_num);i++)
		if(map[keys[i]]==temp_num)
			member=add_string(keys[i],member);
		return member;
	
}

string *get_minnum_inmap(mapping map)
{
	int i,map_num,temp_num;
	string *keys,*member,temp_key;
	if(!(map_num=sizeof(map)))
		return member;
	keys=keys(map);
	if(map_num==1)
	{
		write("只有一个成员");
		return keys;
	}
	temp_num=map[keys[0]];
	temp_key=keys[0];
	
	for(i=0;i<(map_num-1);i++)
	{
		if(map[keys[i+1]]<temp_num)
		{
			//write(map[keys[i+1]]+"<"+temp_num+"\n");
			temp_num=map[keys[i+1]];
			temp_key=keys[i+1];
			
		}
		
	}
	
   //member=add_string(temp_key,member);

	for(i=0;i<(map_num);i++)
		if(map[keys[i]]==temp_num&&map[keys[i]]<0)
			member=add_string(keys[i],member);
		return member;
	
}

