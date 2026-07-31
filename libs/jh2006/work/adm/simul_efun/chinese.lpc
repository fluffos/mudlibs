string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
	if (strlen(str) < 2) return 0;
	if (str[0] < 176 || str[0] > 247) return 0;
	if (str[1] < 161 || str[1] > 254) return 0;
	if (str[0] == 215 && str[1] > 249) return 0;
	return 1;
}
