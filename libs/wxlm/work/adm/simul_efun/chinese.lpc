/**
 * @file chinese.c
 * @author Lu dexiang
 * @brief 中文处理相关的模拟外部函数
 */

/**
 * @brief 将数字转换为中文表示
 * @param int i 要转换的数字
 * @return string 转换后的中文数字字符串
 */
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

/**
 * @brief 将字符串转换为中文
 * @param string str 要转换的字符串
 * @return string 转换后的中文字符串
 */
string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

/**
 * @brief 判断字符串是否全为中文字符
 * @param string str 要检查的字符串
 * @return int 1:全为中文 0:不全为中文或空字符串
 */
int is_chinese(string str)
{
	if (!str)
		return 0;

	return pcre_match(str, "^\\p{Han}+$");
}


